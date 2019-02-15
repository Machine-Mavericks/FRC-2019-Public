/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "subsystems/Elevator.h"
#include "RobotMap.h"
#include "commands/ElevatorManualControl.h"


// Elevator constructor - this is run when elevator subysstem is first created
Elevator::Elevator() : Subsystem("Elevator") {

  // create individual motor control objects - assign unique CAN address to motor drive - defined in RobotMap.h
  m_Motor = new WPI_TalonSRX(ELEVATOR_MOTOR_CANID);

  // set factory default settings
  m_Motor->ConfigFactoryDefault();

  // select quadrature encoder (first parameter) as primary feedback sensor (second parameter=0)
  // Third parameter kTimeoutMs is timeout to wait for Talon to confirm update - set to 0 for no checking
  m_Motor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

  // sets direction of the encoder - set to true to invert phase (to change encoder direction)
  m_Motor->SetSensorPhase(true);

  // set nominal and peak outputs of drive 
  // nominal = 0, peak is +1 or -1 depending on direction
  // second parameter is timeout (use 0)
  m_Motor->ConfigNominalOutputForward(0, 0);
  m_Motor->ConfigNominalOutputReverse(0, 0);
  m_Motor->ConfigPeakOutputForward (ELEVATOR_DRIVE_FULL_VLTG_FWD, 0);
  m_Motor->ConfigPeakOutputReverse (-ELEVATOR_DRIVE_FULL_VLTG_REV, 0);

  // Set elevator motor maximum current level to 20A (total for two motors)
  m_Motor->ConfigContinuousCurrentLimit(ELEVATOR_CURRENT_LIMIT);
  m_Motor->EnableCurrentLimit(true);

  // setup motor drive hardware limit switches
  // by default, TalonSRX is configured to use Normally Open (NO) switches
  // when either limit switch is activated, motor is automatically disabled
  // this way, out-of-box Talon will still work w/o limit switches connected

  // set up forward direction soft (software) limit - set to maximum allowed encoder pulse counts at elevator top
  m_Motor->ConfigForwardSoftLimitEnable(true,0);
  m_Motor->ConfigForwardSoftLimitThreshold(ELEVATOR_SOFT_LIMIT_MAX);
  
  // set up reverse direction soft limit - assumes encoder pulse at bottom is 0
  m_Motor->ConfigReverseSoftLimitEnable(true, 0);
  m_Motor->ConfigReverseSoftLimitThreshold(ELEVATOR_SOFT_LIMIT_MIN);

  // set motor ramp rate (from neutral to full) to 50ms
  // used to avoid sudden changes in speed
  m_Motor-> ConfigClosedloopRamp(ELEVATOR_DRIVE_MAXRAMP, 0);

  // Set position feedback control error gains
  // First parameter slotID - motor drive can support 4 different sets of PID values - we only need slot 0
  // Second parameter is PGain/IGain/DGain as applicable
  // Third parameter is timeout value - set to 0 for no checking
  // Note: Full-scale error output is 1023. I believe inputs to PID loop are encoder pulse counts.
  m_Motor->Config_kP(0, ELEVATOR_PGAIN, 0);
  m_Motor->Config_kI(0, ELEVATOR_IGAIN, 0);
  m_Motor->Config_kD(0, ELEVATOR_DGAIN, 0);

  // set integration maximum accumulator value
  m_Motor->ConfigMaxIntegralAccumulator(0, ELEVATOR_MAX_INTEGRAL_ACCUMULATOR, 0);
  
  // Set maximum allowed posotion controller closed loop error
  // within this error, no control action is performed (i.e control deadband)
  m_Motor->ConfigAllowableClosedloopError(0, ELEVATOR_ALLOWABLE_CLOSEDLOOP_ERROR, 0);

  // reset encoder
  ResetEncoderPosition();
}

// default command to run with the subsystem
void Elevator::InitDefaultCommand() {
  SetDefaultCommand(new ElevatorManualControl());
}



// ------------- Elevator Functions -------------


// Function to command elevator to move to a fixed position
// Input: position number. If not valid position, do nothing
void Elevator::SetElevatorPresetPosition(int pos)
{
  // depending on position given to us, tell motor to turn to desired position (in # of pulse counts)
  switch (pos) {
    case 0:
      m_Motor->Set(ControlMode::Position, ELEVATOR_POSITION0);
      break;

    case 1:
      m_Motor->Set(ControlMode::Position, ELEVATOR_POSITION1);
      break;

    case 2:
      m_Motor->Set(ControlMode::Position, ELEVATOR_POSITION2);
      break;

    case 3:
      m_Motor->Set(ControlMode::Position, ELEVATOR_POSITION3);
      break;

    case 4:
      m_Motor->Set(ControlMode::Position, ELEVATOR_POSITION4);
      break;

    // otherwise do nothing - default case not req'd
  }
}


// Function to return elevator position
// Returns 0 if elevator at bottom, 1 if in middle, 2 if at top
// Returns -1 if not in defined position 
int Elevator::GetElevatorTargetPresetPosition(void)
{  
  // by default, return -1 (elevator not at a specific position)
  int pos=-1;

  // get current elevator target
  int target = m_Motor->GetClosedLoopTarget(0);

   // depending on position given to us, tell motor to turn to desired position (in # of pulse counts)
  switch (target) {
  
    case ELEVATOR_POSITION0:
      pos = 0;
      break;

    case ELEVATOR_POSITION1:
      pos = 1;
      break;

    case ELEVATOR_POSITION2:
      pos = 2;
      break;

    case ELEVATOR_POSITION3:
      pos = 3;
      break;

    case ELEVATOR_POSITION4:
      pos = 4;
      break;
  }

  return (pos);
} 

// Function to return elevator's next preset position (next higher position)
int Elevator::GetElevatorNextHigherPresetPosition(void) {

  // get current elevator position
  int position = m_Motor->GetSelectedSensorPosition(0);

  // next position
  int next = 0;

  if (position >= (ELEVATOR_POSITION0-ELEVATOR_POSITION_TOLERANCE))
    next = 1;
  if (position >= (ELEVATOR_POSITION1-ELEVATOR_POSITION_TOLERANCE))
    next = 2;
  if (position >= (ELEVATOR_POSITION2-ELEVATOR_POSITION_TOLERANCE))
    next = 3;
  if (position >= (ELEVATOR_POSITION3-ELEVATOR_POSITION_TOLERANCE))
    next = 4;
  
  // return next elevator position
  return next;
  }

// Function to return elevator's next preset position (next higher position)
int Elevator::GetElevatorNextLowerPresetPosition(void) {

  // get current elevator position
  int position = m_Motor->GetSelectedSensorPosition(0);

  // next position
  int next = 0;

  if (position <= (ELEVATOR_POSITION4+ELEVATOR_POSITION_TOLERANCE))
    next = 3;
  if (position <= (ELEVATOR_POSITION3+ELEVATOR_POSITION_TOLERANCE))
    next = 2;
  if (position <= (ELEVATOR_POSITION2+ELEVATOR_POSITION_TOLERANCE))
    next = 1;
  if (position <= (ELEVATOR_POSITION1+ELEVATOR_POSITION_TOLERANCE))
    next = 0;
  
  // return next elevator position
  return next;
  }



// Function returns true if elevator at, or near, its target position
bool Elevator::IsElevatorAtTarget(void)
{
  if (abs(m_Motor->GetClosedLoopError()) <= ELEVATOR_POSITION_TOLERANCE )
    return true;
  else
    return false;
}


// Function to command elevator to move to a fixed position
// Input: Target position (in sensor units)
void Elevator::SetElevatorTargetAnalog(int pos){

  // ensure position in valid range of drive
  if (pos<ELEVATOR_SOFT_LIMIT_MIN )
      pos=ELEVATOR_SOFT_LIMIT_MIN;
  if (pos>ELEVATOR_SOFT_LIMIT_MAX)
      pos=ELEVATOR_SOFT_LIMIT_MAX;

  // set motor target position
  m_Motor->Set(ControlMode::Position, pos);
}

// Function to get current elevator target position
// Output: Target position (in sensor units)
int Elevator::GetElevatorTargetAnalog(void){
  return m_Motor->GetClosedLoopTarget(0);
}

// ------------- Low-level Elevator Functions -------------


// Resets elevator encoder position value
// USE ONLY WHEN ELEVATOR AT HOME POSITION (BOTTOM?)
void Elevator::ResetEncoderPosition(void)
{
  // first parameter - encoder position, second parameter PID loop ID (use 0), third is timeout (use 0)
  m_Motor->SetSelectedSensorPosition(0, 0, 0);
}

// Returns elevator encoder position value (in raw sensor units)
int Elevator::GetEncoderPosition(void)
{  
  // return position of primary feedback sensor for PID loop ID (use 0)
  return m_Motor->GetSelectedSensorPosition(0);
}

// Returns elevator encoder speed value (in raw sensor units per 100ms)
int Elevator::GetEncoderSpeed(void)
{
  // return speed of primary feedback sensor for PID loop ID (use 0)
  return m_Motor->GetSelectedSensorVelocity(0);
}

// ------------- Motor Drive Functions -------------

// Returns motor drive current (amps)
float Elevator::GetMotorCurrent(void)
{ 
  // return motor drive current
  return m_Motor->GetOutputCurrent();
}
