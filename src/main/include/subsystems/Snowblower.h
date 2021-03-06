/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// This subsystem controls the snowblower subsytstem

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

class Snowblower : public frc::Subsystem {
  private:

  // define drive motors
  WPI_TalonSRX *m_Motor;

  public:
  
  // constructor - used to initialize specific hardware
  Snowblower();
  
  // default command to run with the subsystem
  void InitDefaultCommand() override;
    

  // ------------- Snowblower Functions -------------

  // Set motor speed 
  void SetMotorSpeed(float speed);

  // Set max motor current (A)
  void SetMaxMotorCurrent(float current);

  // Returns motor drive current (amps)
  float GetMotorCurrent(void);
};