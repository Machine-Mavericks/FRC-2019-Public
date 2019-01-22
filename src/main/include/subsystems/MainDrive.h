/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// RobotDrive subsystem represents the main robot drive system
// which consists of four drive motors - two for left, and two for right side

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Spark.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <ctre/Phoenix.h>

using namespace frc;

class MainDrive : public frc::Subsystem {
 private:

  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  // define drive motors - assign each to specific PWN channel
  WPI_TalonSRX *m_MotorFrontLeft;
  WPI_VictorSPX *m_MotorRearLeft;
  WPI_TalonSRX *m_MotorFrontRight;
  WPI_VictorSPX *m_MotorRearRight;

  // create overall drive system
  DifferentialDrive *m_Drive;

public:

  // constructor - used to initialize specific hardware
  MainDrive();

  // default command to run with the subsystem
  void InitDefaultCommand() override;

  // Drive in Tank Drive - where left and right motors are driven independently
  // Inputs: LeftSpeed, RightSpeed
  // =-1.0: full reverse
  // =0.0: full stop
  //=+1.0: full forward
  void TankDrive(float LeftSpeed, float RightSpeed);

  void ArcadeDrive(float XSpeed, float ZRotation);

  // add other drive commands
  // TBD

};
