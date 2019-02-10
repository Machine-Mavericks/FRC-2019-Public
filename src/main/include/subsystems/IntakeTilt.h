/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

class IntakeTilt : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  //define drive motors - assign each to specific PWN channel
  WPI_TalonSRX *m_Motor;

 public:
  IntakeTilt();
  void InitDefaultCommand() override;

// ------------- IntakeTilt Functions -------------

  // These are functions we added ourselves that provide useful(and simplified) control of the IntakeTilt

  // Function to command IntakeTilt to move to a fixed position
  void SetIntakeTiltTargetPosition(int pos);

  // Function to return IntakeTilt position
  int GetIntakeTiltTargetPosition(void);

  // Function returns true if IntakeTilt at, or near, its target position
  bool IsIntakeTiltAtTarget(void);

  // Function to command IntakeTilt to move to a fixed position
  void SetIntakeTiltTargetAnalog(int pos);
    
  // Function to get current IntakeTilt target position
  int GetIntakeTiltTargetAnalog(void);

  // initialize position control - to be called when subsystem has been re-homed
  void InitPositionControl();

  // initialize position control - to be called when subsystem has been re-homed
  void InitForHoming(void);
    
  // ------------- Low-level IntakeTilt Functions -------------


  // Resets IntakeTilt encoder position value
  // USE ONLY WHEN IntakeTilt AT HOME POSITION (BOTTOM?)
  void ResetEncoderPosition(void);

  // Returns IntakeTilt encoder position value (in raw sensor units)
  int GetEncoderPosition(void);

  //directly set motor speed to be used for homing 
  // to be in between -1 and 1
  void SetTiltMotorSpeed(float speed);

  // check if limit switch is closed
  bool IsFwdLimitSwitchClosed(void);

  // Check if limit switch is closed
  bool IsRevLimitSwitchClosed(void);



};
                  