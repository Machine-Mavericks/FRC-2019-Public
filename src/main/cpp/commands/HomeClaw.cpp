/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HomeClaw.h"
#include "Robot.h"
#include "subsystems/Claw.h"

HomeClaw::HomeClaw() {
    // Use Requires() here to declare subsystem dependencies
  Requires (&Robot::m_Claw);

  // tank drive command is interruptable
  SetInterruptible(false);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);
  
}

// Called just before this Command runs the first time
void HomeClaw::Initialize() {
  // initialize homing
  Robot::m_Claw.InitForHoming();
  // turn on motor
  Robot::m_Claw.SetClawMotorSpeed(-0.3);

}

// Called repeatedly when this Command is scheduled to run
void HomeClaw::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool HomeClaw::IsFinished() {   
  return Robot::m_Claw.IsRevLimitSwitchClosed(); 
}

// Called once after isFinished returns true
void HomeClaw::End() {

  // stop motor
  Robot::m_Claw.SetClawMotorSpeed(0);

  //reset encoder
  Robot::m_Claw.InitPositionControl();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HomeClaw::Interrupted() {}
