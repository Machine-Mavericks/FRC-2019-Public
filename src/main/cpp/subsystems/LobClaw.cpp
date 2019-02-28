/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/LobClaw.h"
#include "RobotMap.h"


LobClaw::LobClaw() : Subsystem("LobClaw") {

    // define solenoid object - set channel numbers for open/close
   m_DoubleSolenoid = new DoubleSolenoid(LC_OPEN_CHANNEL,LC_CLOSE_CHANNEL);

   // set initial solenoid position
   SetLobClawTargetPosition(1);
}


void LobClaw::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

// ------------- LobClaw Functions -------------

// Open/Close claw
// Inputs: 1=open, 0=close
void LobClaw::SetLobClawTargetPosition(int pos){
    // depending on desired position, turn on forward or reverse valve
    if (pos == 1)
        m_DoubleSolenoid->Set(DoubleSolenoid::kForward);
    if (pos ==0)
        m_DoubleSolenoid->Set(DoubleSolenoid::kReverse);
}



// Function to return LobClaw position
// Output: 1 if open, 0 if closed, -1 if off (or otherwise) 
int LobClaw::GetLobClawTargetPosition(void){
   int pos = -1;
    if (m_DoubleSolenoid->Get() == DoubleSolenoid::kForward)
        pos = 1;
    if (m_DoubleSolenoid->Get() == DoubleSolenoid::kReverse)
        pos = 0;
}


