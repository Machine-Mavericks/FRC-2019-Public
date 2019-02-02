/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// ManualElevatorControl command allows elevator to be driven by jostick
// This is the default command for elevator

#include "commands/ElevatorManualControl.h"
#include "Robot.h"
#include "RobotMap.h"

ElevatorManualControl::ElevatorManualControl() {
  // Use Requires() here to declare subsystem dependencies
  Requires (&Robot::m_Elevator);

  // tank drive command is interruptable
  SetInterruptible(true);

  // command is not to run when robot is disabled
  SetRunWhenDisabled(false);

  
}

// Called just before this Command runs the first time
void ElevatorManualControl::Initialize() {
    //Robot::m_Elevator.ResetEncoderPosition();
}

// Called repeatedly when this Command is scheduled to run
void ElevatorManualControl::Execute() {
  
    // get controller position
    //float y = 0.5 * (1.0 + -Robot::m_MechanismOI.MechanismJoystick->GetRawAxis(5));
    //Robot::m_Elevator.SetElevatorTargetAnalog(y);
   //Robot::m_Elevator.SetElevatorTargetAnalog(Robot::m_MechanismOI.MechanismJoystick->GetRawAxis(5));
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorManualControl::IsFinished() {
  // since this is default mode, always return false - command never ends
  return false;
}

// Called once after isFinished returns true
void ElevatorManualControl::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorManualControl::Interrupted() {}