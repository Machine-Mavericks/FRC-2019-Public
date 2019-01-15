/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/MainDrive.h"

MainDrive::MainDrive() : Subsystem("MainDrive") {

  // create individual motor control objects - assign unique CAN address to each motor drive
  m_MotorFrontLeft = new WPI_VictorSPX(2);
  m_MotorRearLeft = new WPI_VictorSPX(5);
  m_MotorFrontRight = new WPI_VictorSPX(3);
  m_MotorRearRight = new WPI_VictorSPX(4);
  
  // configure motor drives with factory default settings
  m_MotorFrontLeft->ConfigFactoryDefault();
  m_MotorRearLeft->ConfigFactoryDefault();
  m_MotorFrontRight->ConfigFactoryDefault();
  m_MotorRearRight->ConfigFactoryDefault();

  // set rear drives to follow front ones
  m_MotorRearLeft->Follow(*m_MotorFrontLeft);
  m_MotorRearRight->Follow(*m_MotorFrontRight);
}

  // default command to run with the subsystem
void MainDrive::InitDefaultCommand() {
  // For drive there is no default command
}


// Drive in Tank Drive - where left and right motors are driven independently
// Inputs: LeftSpeed, RightSpeed - -1 <=speed <= +1.
// -1: full reverse
// 0: full stop
// +1: full forward
void MainDrive::Drive(float LeftSpeed, float RightSpeed) {

  // make a local copy of left and right, so we can check each for range
  float left = LeftSpeed;
  float right = RightSpeed;

  // ensure speeds given to us are between -1.0 and 1.0
  if (left > 1.0)
    left = 1.0;
  if (left < -1.0)
    left = -1.0;

  if (right > 1.0)
    right = 1.0;
  if (right < -1.0)
    right = -1.0;

  // command drive to tankdrive at specified speeds
  m_MotorFrontLeft->Set(ControlMode::PercentOutput, left);
  m_MotorFrontRight->Set(ControlMode::PercentOutput, right);

}
