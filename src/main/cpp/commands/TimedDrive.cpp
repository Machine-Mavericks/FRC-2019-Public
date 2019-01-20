/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TimedDrive.h"
#include "Robot.h"

TimedDrive::TimedDrive() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());

  // Use Requires() here to declare subsystem dependencies
  Requires (&Robot::m_MainDrive);

  // tank drive command is interruptible
  SetInterruptible(true);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);


}

// Called just before this Command runs the first time
void TimedDrive::Initialize() {

  // Set driveTime to 0
  driveTime = 0;

}

// Called repeatedly when this Command is scheduled to run
void TimedDrive::Execute() {

  // increment timer by delta t
  driveTime = driveTime + 0.02;

  // turn on motors
  Robot::m_MainDrive.Drive (0.2, -0.2);

}

// Make this return true when this Command no longer needs to run execute()
bool TimedDrive::IsFinished() { 
  if (driveTime >= 3)
    return true;
  else 
    return false;


}

// Called once after isFinished returns true
void TimedDrive::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimedDrive::Interrupted() {}
