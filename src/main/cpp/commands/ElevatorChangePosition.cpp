/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorChangePosition.h"
#include "Robot.h"
#include "RobotMap.h"

// default position is all the way down
static int position = 0;


ElevatorChangePosition::ElevatorChangePosition(bool dir) {
  // Use Requires() here to declare subsystem dependencies
  Requires (&Robot::m_Elevator);

  // tank drive command is interruptable
  SetInterruptible(false);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);

  // set direction
  direction = dir;

}

// Called just before this Command runs the first time
void ElevatorChangePosition::Initialize() {
   if (direction == true){
    if (position < 4)
      position = position + 1;
  }
  else{
    if (position > 0)
      position = position - 1;
  }

   // set elevator target position
  Robot::m_Elevator.SetElevatorTargetPosition(position);
}

// Called repeatedly when this Command is scheduled to run
void ElevatorChangePosition::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorChangePosition::IsFinished() { 
  //return true;
  return Robot::m_Elevator.IsElevatorAtTarget();
 }

// Called once after isFinished returns true
void ElevatorChangePosition::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorChangePosition::Interrupted() {}
