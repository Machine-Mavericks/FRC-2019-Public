/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Wrist.h"
#include "RobotMap.h"
#include <frc/livewindow/LiveWindow.h>
#include <frc/smartdashboard/SmartDashboard.h>

Wrist::Wrist()
    : PIDSubsystem("Wrist", WRIST_P_GAIN, WRIST_I_GAIN, WRIST_D_Gain) {
  // Use these to get going:
  // SetSetpoint() -  Sets where the PID controller should move the system
  //                  to
  // Enable() - Enables the PID controller.
}

double Wrist::ReturnPIDInput() {
  // Return your input value for the PID loop
  // e.g. a sensor, like a potentiometer:
  // yourPot->SetAverageVoltage() / kYourMaxVoltage;
  return 0;
}

void Wrist::UsePIDOutput(double output) {
  // Use output to drive your system, like a motor
  // e.g. yourMotor->Set(output);
}

void Wrist::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
