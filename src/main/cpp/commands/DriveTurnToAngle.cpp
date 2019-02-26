/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveTurnToAngle.h"
#include "subsystems/MainDrive.h"
#include "subsystems/NavX.h"
#include "Robot.h"
#include "RobotMap.h"

// constructor - Turn robot by fixed angle, with speed limit
// Inputs: Angle +/- deg, Speed 0 to 1.0
DriveTurnToAngle::DriveTurnToAngle(float Angle, float Speed) {

  // Use Requires() here to declare subsystem dependencies
  Requires (&Robot::m_MainDrive);

  // distance drive command is interruptable
  SetInterruptible(false);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);

  // set the parameters: Angle, speed
  m_Angle = Angle;
  if (Speed >= 0.0 && Speed <=1.0)
     m_Speed = Speed;
  else
    m_Speed = 0.0;
}

// Called just before this Command runs the first time
void DriveTurnToAngle::Initialize() {

  //zero the gyro
  Robot::m_NavX.ZeroYaw();

  // reset integrated error
  m_IntegratedError = 0.0;
}

// Called repeatedly when this Command is scheduled to run
void DriveTurnToAngle::Execute() {

  // get the current yaw
  float CurrentYaw = Robot::m_NavX.GetYaw();

  // our current error  
  float error = m_Angle - CurrentYaw;

  // integrate error
  m_IntegratedError = m_IntegratedError + 0.02*error;
  
  // do not integrate if error is over 10 deg
  if (fabs(error) >10.0)
    m_IntegratedError = 0;

  // PI output
  float PIOutput = 0.02 * error + 0.001 * m_IntegratedError;

  // apply speed limit
  if (PIOutput > m_Speed)
    PIOutput = m_Speed;
  else if (PIOutput < -m_Speed)
    PIOutput = -m_Speed;

// apply speed limit
  if (fabs(error) < 15.0) {
  if (PIOutput > 0.15)
    PIOutput = 0.15;
  else if (PIOutput < -0.15)
    PIOutput = -0.15;
  }

  // turn robot
  Robot::m_MainDrive.SetArcadeDrive(0.0, PIOutput , false);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurnToAngle::IsFinished() { 

  // compare current angle to the desired angle
  if (fabs(Robot::m_NavX.GetYaw() - m_Angle)<= 2)
    return true; 
  else
    return false;
}

// Called once after isFinished returns true
void DriveTurnToAngle::End() {
    // we are finished - stop robot
    Robot::m_MainDrive.SetArcadeDrive(0.0, 0.0 , false);
}

// Called when another command which requires one or more of the same subsystems is scheduled to run
void DriveTurnToAngle::Interrupted() {}