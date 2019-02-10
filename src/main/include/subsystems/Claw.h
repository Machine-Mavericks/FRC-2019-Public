

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
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  //define drive motors - assign each to specific PWN channel
  WPI_TalonSRX *m_Motor;

 public:
  Claw();
  void InitDefaultCommand() override;

// ------------- claw Functions -------------

  // These are functions we added ourselves that provide useful(and simplified) control of the claw

  // Function to command claw to move to a fixed position
  void SetClawTargetPosition(int pos);

  // Function to return claw position
  int GetClawTargetPosition(void);

  // Function returns true if claw at, or near, its target position
  bool IsClawAtTarget(void);

  // Function to command claw to move to a fixed position
  void SetClawTargetAnalog(int pos);
    
  // Function to get current claw target position
  int GetClawTargetAnalog(void);
  
  // initialize position control - to be called when subsystem has been re-homed
  void InitPositionControl();

  // initialize position control - to be called when subsystem has been re-homed
  void InitForHoming(void);
    
  // ------------- Low-level claw Functions -------------


  // Resets claw encoder position value
  // USE ONLY WHEN claw AT HOME POSITION (BOTTOM?)
  void ResetEncoderPosition(void);

  // Returns claw encoder position value (in raw sensor units)
  int GetEncoderPosition(void);

  //directly set motor speed to be used for homing 
  // to be in between -1 and 1
  void SetClawMotorSpeed(float speed);

  // check if limit switch is closed
  bool IsFwdLimitSwitchClosed(void);

  // Check if limit switch is closed
  bool IsRevLimitSwitchClosed(void);

  // Returns motor drive current (amps)
  float GetMotorCurrent(void);
   
};
                  