/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorUpDownPosition.h"
#include "Robot.h"
#include "RobotMap.h"

// Move elevator up or down one position
// Inputs: true is up, false is down
ElevatorUpDownPosition::ElevatorUpDownPosition(bool dir) {
  // This command requires both elevator and intake tilt
  // Intake tilt is adjusted based on elevator target position
  Requires (&Robot::m_Elevator);
  Requires (&Robot::m_IntakeTilt);

  // tank drive command is interruptable
  SetInterruptible(false);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);

  // set direction
  direction = dir;
}

// Called just before this Command runs the first time
void ElevatorUpDownPosition::Initialize() {
   
  // Assume elevator is not being moded to bottom position
  // Inform intake tilt accoringly, so it holds horizontal
  Robot::m_IntakeTilt.AdjustforBottomPosition(false);
  
  if (direction==true)
     Robot::m_Elevator.SetElevatorPresetPosition(Robot::m_Elevator.GetElevatorNextHigherPresetPosition());
 
  else
  {
    // get next elevator lower position
    int NextPos = Robot::m_Elevator.GetElevatorNextLowerPresetPosition();
    
    // set elevator target
    Robot::m_Elevator.SetElevatorPresetPosition(NextPos);

    // if elevator moving to bottom level, adjust intake tilt position so it is pointing downwards somewhat
    if (NextPos==0)
      Robot::m_IntakeTilt.AdjustforBottomPosition(true);

  }
}

// Called repeatedly when this Command is scheduled to run
void ElevatorUpDownPosition::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorUpDownPosition::IsFinished() { 
  // return true when elevator has arrived at its target
  return true; //Robot::m_Elevator.IsElevatorAtTarget();
 }

// Called once after isFinished returns true
void ElevatorUpDownPosition::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorUpDownPosition::Interrupted() {}
