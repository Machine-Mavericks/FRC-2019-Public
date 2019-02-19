/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/InstantCommand.h>

class LobClawOpenClose : public frc::InstantCommand {
 public:
  //open/close the claw
  //1=open, 0=close
  LobClawOpenClose(int pos);
  
  void Initialize() override;

  private:
  int position;
};
