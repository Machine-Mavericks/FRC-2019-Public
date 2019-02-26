/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/IntakeTilt.h"
#include "RobotMap.h"


IntakeTilt::IntakeTilt() : Subsystem("IntakeTilt") {

  // create individual motor control objects- assign unique CAN adress to motor drive-
  m_Motor = new WPI_TalonSRX(TILT_MOTOR_CANID);

  // set factory default settings
  m_Motor->ConfigFactoryDefault();

  // reverse motor direction
  m_Motor->SetInverted(false);

  // select quadrature encoder (first parameter) as primary feedback sensor (second parameter=0)
  // Third parameter kTimeoutMs is timeout to wait for Talon to confirm update - set to 0 for no checking
  m_Motor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

  // sets direction of the encoder - set to true to invert phase (to change encoder direction)
  m_Motor->SetSensorPhase(false);

  // set nominal and peak outputs of drive 
  // nominal = 0, peak is +1 or -1 depending on direction
  // second parameter is timeout (use 0)
  m_Motor->ConfigNominalOutputForward(0, 0);
  m_Motor->ConfigNominalOutputReverse(0, 0);
  m_Motor->ConfigPeakOutputForward (TILT_DRIVE_FULL_VLTG_FWD, 0);
  m_Motor->ConfigPeakOutputReverse (-TILT_DRIVE_FULL_VLTG_REV, 0);

  // Set elevator motor maximum current level
  m_Motor->ConfigContinuousCurrentLimit(TILT_CURRENT_LIMIT);
  m_Motor->ConfigPeakCurrentLimit(TILT_PEAKCURRENT_LIMIT);
  m_Motor->ConfigPeakCurrentDuration(TILT_PEAKCURRENT_TIME);
  m_Motor->EnableCurrentLimit(true);

  // set up forward direction soft (software) limit - set to maximum allowed encoder pulse counts at IntakeTilt top. Disable until subsystem has been rehomed
  m_Motor->ConfigForwardSoftLimitEnable(false,0);
  m_Motor->ConfigForwardSoftLimitThreshold(TILT_SOFT_LIMIT_MAX);

  // set up reverse direction soft limit - assumes encoder pulse at bottom is 0. Disable until subsystem has been rehomed
  m_Motor->ConfigReverseSoftLimitEnable(false, 0);
  m_Motor->ConfigReverseSoftLimitThreshold(TILT_SOFT_LIMIT_MIN); 

  // configure limit switches
	m_Motor->ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,0);

  // set motor ramp rate (from neutral to full) used to avoid sudden changes in speed
  m_Motor-> ConfigClosedloopRamp(ELEVATOR_DRIVE_MAXRAMP, 0);

  // Set position feedback control error gains
  // First parameter slotID - motor drive can support 4 different sets of PID values - we only need slot 0
  // Second parameter is PGain/IGain/DGain as applicable
  // Third parameter is timeout value - set to 0 for no checking
  // Note: Full-scale error output is 1023. I believe inputs to PID loop are encoder pulse counts.
  m_Motor->Config_kP(0, TILT_PGAIN, 0);
  m_Motor->Config_kI(0, TILT_IGAIN, 0);
  m_Motor->Config_kD(0, TILT_DGAIN, 0);

  // set integration maximum accumulator value
  m_Motor->ConfigMaxIntegralAccumulator(0, TILT_MAX_INTEGRAL_ACCUMULATOR, 0);
 
  // Set maximum allowed posotion controller closed loop error 
  m_Motor->ConfigAllowableClosedloopError(0, TILT_ALLOWABLE_CLOSEDLOOP_ERROR, 0);
}

// default command to run with the subsystem
void IntakeTilt::InitDefaultCommand() {}



// ------------- IntakeTilt Functions -------------


void IntakeTilt::SetIntakeTiltTargetPosition(int pos)
{
  // depending on position given to us, tell motor to turn to desired position (in # of pulse counts)
  switch (pos) {
    case 0:
      m_Motor->Set(ControlMode::Position, TILT_UP_POSITION);
      break;

    case 1:
      m_Motor->Set(ControlMode::Position, TILT_MID_POSITION);
      break;

    case 2:
      m_Motor->Set(ControlMode::Position, TILT_DOWN_POSITION);
      break;

    // otherwise do nothing - default case not req'd
  }
}


// Function returns true if IntakeTilt at, or near, its target position
bool IntakeTilt::IsIntakeTiltAtTarget(void){
  
  if (abs(m_Motor->GetClosedLoopError()) <= TILT_POSITION_TOLERANCE )
    return true;
  else
    return false;
}

// Function to return IntakeTilt position
// Returns 0 if IntakeTilt at bottom, 1 if in middle, 2 if at top
// Returns -1 if not in defined position 
int IntakeTilt::GetIntakeTiltTargetPosition(void)
{  
  // by default, return -1 (IntakeTilt not at a specific position)
  int pos=-1;

  // get current IntakeTilt target
  int target = m_Motor->GetClosedLoopTarget(0);

   // depending on position given to us, tell motor to turn to desired position (in # of pulse counts)
  switch (target) {
  
    case TILT_UP_POSITION:
      pos = 0;
      break;

    case TILT_MID_POSITION:
      pos = 1;
      break;

    case TILT_DOWN_POSITION:
      pos = 2;
      break;
  }

  return (pos);
}


// initialize position control - to be called when subsystem has been re-homed
void IntakeTilt::InitPositionControl(){

  //reset encoder
  ResetEncoderPosition();
  
  //enable forward direction soft limit - set to maximum allowed encoder pulse counts at IntakeTilt top.
  m_Motor->ConfigForwardSoftLimitEnable(true,0);

  //enable reverse direction soft limit - assumes encoder pulse at bottom is 0
  m_Motor->ConfigReverseSoftLimitEnable(true, 0);
}

// initialize position control - to be called when subsystem has been re-homed
void IntakeTilt::InitForHoming(void){
  
  //enable forward direction soft limit - set to maximum allowed encoder pulse counts at Claw top.
  m_Motor->ConfigForwardSoftLimitEnable(false,0);

  //enable reverse direction soft limit - assumes encoder pulse at bottom is 0
  m_Motor->ConfigReverseSoftLimitEnable(false, 0);
}


// ------------- Encoder-Related Functions -------------


// Function to command IntakeTilt to move to a fixed position
// Input: Target position (in sensor units)
void IntakeTilt::SetIntakeTiltTargetAnalog(int pos){

  // ensure position in valid range of drive
  if (pos<TILT_SOFT_LIMIT_MIN )
      pos=TILT_SOFT_LIMIT_MIN;
  if (pos>TILT_SOFT_LIMIT_MAX)
      pos=TILT_SOFT_LIMIT_MAX;

  // set motor target position
  m_Motor->Set(ControlMode::Position, pos);
}

// Function to get current IntakeTilt target position
// Output: Target position (in sensor units)
int IntakeTilt::GetIntakeTiltTargetAnalog(void){
  return m_Motor->GetClosedLoopTarget(0);
}

// Resets IntakeTilt encoder position value
// USE ONLY WHEN IntakeTilt AT HOME POSITION (BOTTOM?)
void IntakeTilt::ResetEncoderPosition(void){
  // first parameter - encoder position,
  m_Motor->SetSelectedSensorPosition(0);
}

// Returns IntakeTilt encoder position value (in raw sensor units)
int IntakeTilt::GetEncoderPosition(void){  
  // return position of primary feedback sensor for PID loop ID (use 0)
  return m_Motor->GetSelectedSensorPosition(0);
}



// ------------- Motor Drive Functions -------------


// Directly set motor speed to be used for homing 
// input: speed between -1 and 1
void IntakeTilt::SetMotorSpeed(float speed){
  m_Motor->Set(ControlMode::PercentOutput, speed);
}

// Returns motor drive current (amps)
float IntakeTilt::GetMotorCurrent(void){ 
  return m_Motor->GetOutputCurrent();
}

// Check if limit switch is closed
bool IntakeTilt::IsFwdLimitSwitchClosed(void){
  return m_Motor->GetSensorCollection().IsFwdLimitSwitchClosed();
}

// Check if limit switch is closed
bool IntakeTilt::IsRevLimitSwitchClosed(void){
  return m_Motor->GetSensorCollection().IsRevLimitSwitchClosed();
}