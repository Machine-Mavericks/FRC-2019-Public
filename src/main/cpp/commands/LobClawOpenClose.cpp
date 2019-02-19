/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LobClawOpenClose.h"
#include "subsystems/LobClaw.h"
#include "robot.h"

//open/close the claw
//1=open, 0=close
LobClawOpenClose::LobClawOpenClose(int pos) {
   
   // Use Requires() here to declare subsystem dependencies
  Requires (&Robot::m_LobClaw);
  
  position = pos;
}

// Called once when the command executes
void LobClawOpenClose::Initialize() {
  Robot::m_LobClaw.SetLobClawTargetPosition(position);
}
