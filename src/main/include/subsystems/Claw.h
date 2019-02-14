

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

class Claw : public frc::Subsystem {
  private:

  //define drive motors - assign each to specific PWN channel
  WPI_TalonSRX *m_Motor;

  public:
  
  // constructor - used to initialize specific hardware
  Claw();
  
  // default command to run with the subsystem
  void InitDefaultCommand() override;
    
  // ------------- Low-level claw Functions -------------

  //directly set motor speed to be used for homing 
  // to be in between -1 and 1
  void SetClawMotorSpeed(float speed);

  // Returns motor drive current (amps)
  float GetMotorCurrent(void);
};
                  