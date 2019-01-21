/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/StraightDrive.h"
#include "Robot.h"
#include <math.h>
#include "RobotMap.h"


StraightDrive::StraightDrive() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void StraightDrive::Initialize() {
  // Use Requires() here to declare subsystem dependencies
  Requires (&Robot::m_MainDrive);

  // tank drive command is interruptable
  SetInterruptible(true);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);
  }

// Called repeatedly when this Command is scheduled to run
void StraightDrive::Execute() {
  // create variables for left and right joystick y axes
  float raw_right_y, right_y;

  // get joystick y values from joystick
  raw_right_y = Robot::m_DriverOI.RightJoystick->GetRawAxis(1);

  // implement throttle curve
  right_y = raw_right_y; 

  // set main drive tank speeds
  Robot::m_MainDrive.ArcadeDrive (right_y,0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool StraightDrive::IsFinished() { return false; }

// Called once after isFinished returns true
void StraightDrive::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StraightDrive::Interrupted() {}
