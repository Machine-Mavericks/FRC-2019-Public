

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "frc/DoubleSolenoid.h"

using namespace frc;

class LobClaw : public frc::Subsystem {
 private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
    DoubleSolenoid *m_DoubleSolenoid;

 public:
  LobClaw();
  void InitDefaultCommand() override;

// ------------- LobClaw Functions -------------

  // These are functions we added ourselves that provide useful(and simplified) control of the LobClaw

  // Function to command LobClaw to move to a fixed position
  void SetLobClawTargetPosition(int pos);

  // Function to return LobClaw position
  int GetLobClawTargetPosition(void);

   
};
                  