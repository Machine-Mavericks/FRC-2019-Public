/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Claw.h"
#include "RobotMap.h"

Claw::Claw() : Subsystem("Claw") {

  // create individual motor control objects- assign unique CAN adress to motor drive- defined in RobotMap.h
  m_Motor = new WPI_TalonSRX(CLAW_MOTOR_CANID);

  // configure motor drive with factory default settings
  m_Motor->ConfigFactoryDefault();

}

void Claw::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// ------------- Low-level Claw Functions -------------

//directly set motor speed to be used for homing 
// to be in between -1 and 1
void Claw::SetClawMotorSpeed(float speed){
  m_Motor->Set(ControlMode::PercentOutput, speed);
}

// Returns motor drive current (amps)
float Claw::GetMotorCurrent(void)
{ 
  // return motor drive current
  return m_Motor->GetOutputCurrent();
}