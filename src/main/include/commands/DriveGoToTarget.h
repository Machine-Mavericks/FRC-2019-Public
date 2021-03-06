/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// This command is used to drive robot towards detected target

#pragma once

#include <frc/commands/Command.h>
#include "commands/DriveTurntoAngle.h"
#include "commands/DriveStraightDistance.h"
#include "commands/DriveSteerTowardsTarget.h"

#define SETBACK  60    // setback distance from target to aim for (inches)

class DriveGoToTarget : public frc::Command {
  public:
  
  // Constructor
  DriveGoToTarget(float Speed);
  
  // Called just before this Command runs the first time
  void Initialize() override;
  
  // Called repeatedly when this Command is scheduled to run
  void Execute() override;
  
  // Return true when this Command no longer needs to run execute()
  bool IsFinished() override;
  
  // Called once after isFinished returns true
  void End() override;
  
  // Called when another command which requires one or more of the same
  // subsystems is scheduled to run
  void Interrupted() override;
  
  struct PATHTOTARGET {
  bool TargetLock;          // true if target locked on
  int TargetType;           // =0 if chevron, =1 if ball
  unsigned int State;  // index of state machine
  float Angle1;       // angle of first turn (deg)
  float Distance1;     // distance to drive (in) after first turn
  float Angle2;         // angle of second turn (deg)
  float Distance2;     // distance to drive to reach target (in)
  float CX;
  float CZ;
  float XA;
  float CA;
  };

  private:

  float m_Speed;

  // create empty path to target
  PATHTOTARGET m_PathToTarget;

  // pointers to commands to get us to target
  DriveTurnToAngle *Turn1;
  DriveStraightDistance *Distance1;
  DriveTurnToAngle *Turn2;
  DriveStraightDistance *Distance2;

  // command used to steer towards ball
  DriveSteerTowardsTarget *Steer;
};