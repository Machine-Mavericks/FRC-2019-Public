/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TiltDown.h"
#include "Robot.h"
#include "RobotMap.h"

// default position is open
static int position = TILT_DOWN_POSITION;

TiltDown::TiltDown() {
  // Use Requires() here to declare subsystem dependencies
  Requires (&Robot::m_IntakeTilt);

  // tank drive command is interruptable
  SetInterruptible(false);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);
}

// Called just before this Command runs the first time
void TiltDown::Initialize() {

  // set IntakeTilt target position
  Robot::m_IntakeTilt.SetIntakeTiltTargetPosition(2); 
  
}

// Called repeatedly when this Command is scheduled to run
void TiltDown::Execute() {

  // move IntakeTilt to position
  Robot::m_IntakeTilt.SetIntakeTiltTargetPosition(2);
}

// Make this return true when this Command no longer needs to run execute()
bool TiltDown::IsFinished() {
  return Robot::m_IntakeTilt.IsIntakeTiltAtTarget(); }

// Called once after isFinished returns true
void TiltDown::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TiltDown::Interrupted() {}
