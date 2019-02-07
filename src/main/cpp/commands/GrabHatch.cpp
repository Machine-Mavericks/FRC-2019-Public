/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/GrabHatch.h"
#include "Robot.h"
#include "RobotMap.h"

// default position is open
static int position = CLAW_HATCH_POSITION;

GrabHatch::GrabHatch() {
  // Use Requires() here to declare subsystem dependencies
  Requires (&Robot::m_Claw);

  // tank drive command is interruptable
  SetInterruptible(false);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);
}

// Called just before this Command runs the first time
void GrabHatch::Initialize() {

  // set Claw target position
  Robot::m_Claw.SetClawTargetPosition(2);
  
}

// Called repeatedly when this Command is scheduled to run
void GrabHatch::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool GrabHatch::IsFinished() {
  return Robot::m_Claw.IsClawAtTarget(); }

// Called once after isFinished returns true
void GrabHatch::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabHatch::Interrupted() {}
