/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurnToAngle.h"
#include "subsystems/MainDrive.h"
#include "subsystems/NavX.h"
#include "Robot.h"

TurnToAngle::TurnToAngle(float Angle, float Steering, float Speed) {

  // Use Requires() here to declare subsystem dependencies
  Requires (&Robot::m_MainDrive);

  // distance drive command is interruptable
  SetInterruptible(false);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);

  // set the parameters: Angle, Steering, Speed
  m_AngleToTurn = Angle;
  m_Steering = Steering;
  m_Speed = Speed;

}

// Called just before this Command runs the first time
void TurnToAngle::Initialize() {

  //zero the gyro
  Robot::m_NavX.ZeroYaw();

}

// Called repeatedly when this Command is scheduled to run
void TurnToAngle::Execute() {

  // get the current yaw
  float CurrentYaw = Robot::m_NavX.GetYaw();

    // if the angle is positive, drive forward, otherwise drive backward at given speed
    if (m_AngleToTurn >=0)
      Robot::m_MainDrive.ArcadeDrive(m_Steering,m_Speed);

    if (m_AngleToTurn < 0)
      Robot::m_MainDrive.ArcadeDrive(m_Steering, -m_Speed);
}

// Make this return true when this Command no longer needs to run execute()
bool TurnToAngle::IsFinished() { 

  // compare current angle to the desired angle
  if ((Robot::m_NavX.GetYaw())>= m_AngleToTurn)
    return true; 
  else
    return false;
}

// Called once after isFinished returns true
void TurnToAngle::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnToAngle::Interrupted() {}
