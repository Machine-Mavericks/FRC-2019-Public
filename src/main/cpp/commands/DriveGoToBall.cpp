/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveGoToBall.h"
#include "Robot.h"
#include "detection/TargetDetection.h"

// Constructor - approach ball at specified speed
// input 0 to 1 - 0=stop, 1=full speed
DriveGoToBall::DriveGoToBall(float Speed) {
  
  // This command requires use of robot drive
  Requires (&Robot::m_MainDrive);

  // distance drive command is not interruptable
  SetInterruptible(false);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);

  // record speed to drive robot at
  m_Speed = Speed;
}

// Called just before this Command runs the first time
void DriveGoToBall::Initialize() {
  // initially assume we are not yet arrived at target
  m_AtTarget = false;
}

// Called repeatedly when this Command is scheduled to run
void DriveGoToBall::Execute() {

  // get ball target information
  BALL_TARGET target = GetBallTargetEstimation();

  // have we detected a ball?
  if (target.Detected == true)
  {
    // ball has been detected

    // get angle to target
    float TargetAngle = target.XAngle;

    // do we need to turn to angle?
    if (TargetAngle >=2.0 || TargetAngle <=-2.0)
      // drive towards ball
      Robot::m_MainDrive.SetArcadeDrive(m_Speed, 0.025*TargetAngle, false);
    else
      // ball is ahead of us, drive straight
      Robot::m_MainDrive.SetArcadeDrive(m_Speed, 0.0, false);
  }
  else
  {
    // ball has not been detected - stop robot
    Robot::m_MainDrive.SetArcadeDrive(0.0,0.0,false);
  }

}

// Return true when this Command is finished
bool DriveGoToBall::IsFinished() { 
  return false;
}

// Called once after isFinished returns true
void DriveGoToBall::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveGoToBall::Interrupted() {
  
}