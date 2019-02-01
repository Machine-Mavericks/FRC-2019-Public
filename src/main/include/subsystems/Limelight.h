/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ntcore.h>
#include <networkTables/networkTable.h>
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

class Limelight : public frc::Subsystem {
 private:


  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Limelight();

  void InitDefaultCommand() override;
  double GetHorizontalTargetOffsetAngle();
  double GetVerticalTargetOffsetAngle();
  double GetTargetArea();
  double GetTargetSkew();
  bool IsTargetPresent();
  double GetLatencyContribution();
  int GetShortestSide();
  int GetLongestSide();
  int GetHorizontalSideLength();
  int GetVerticalSideLength();
  int GetPipeline();

  //create pointer to Limelight object
  std::shared_ptr<NetworkTable> table;

};
