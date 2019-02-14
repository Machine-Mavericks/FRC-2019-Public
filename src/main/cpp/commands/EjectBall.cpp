/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/EjectBall.h"
#include "Robot.h"
#include "RobotMap.h"


EjectBall::EjectBall() {
  // Use Requires() here to declare subsystem dependencies
  Requires (&Robot::m_Claw);

  // tank drive command is interruptable
  SetInterruptible(true);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);
}

// Called just before this Command runs the first time
void EjectBall::Initialize() {
    timer = 0;
    Robot::m_Claw.SetClawMotorSpeed(-0.5);
}

// Called repEjectedly when this Command is scheduled to run
void EjectBall::Execute() {
    timer = timer + 0.02;
}

// Make this return true when this Command no longer needs to run execute()
bool EjectBall::IsFinished() {
    if (timer >= 5.0)
        return true;
    else
        return false;
 }

// Called once after isFinished returns true
void EjectBall::End() {
    Robot::m_Claw.SetClawMotorSpeed(0.2);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EjectBall::Interrupted() {}
