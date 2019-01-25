/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/TestSolenoid.h"

TestSolenoid::TestSolenoid() : Subsystem("ExampleSubsystem") {}

void TestSolenoid::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void TestSolenoid::SetSolenoid(void){
    m_doubleSolenoid.Set(frc::DoubleSolenoid::kForward);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
