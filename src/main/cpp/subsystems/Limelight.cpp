/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "frc/WPILib.h"
#include "subsystems/Limelight.h"
#include "frc/smartdashboard/Smartdashboard.h"
#include <ntcore.h>
#include <networkTables/networkTable.h>
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"


Limelight::Limelight() : Subsystem("ExampleSubsystem") {}

void Limelight::InitDefaultCommand() {

  table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

}

double Limelight::GetHorizontalTargetOffsetAngle(){

  return table->GetNumber("tx",0.0);

}

double Limelight::GetVerticalTargetOffsetAngle(){

  return table->GetNumber("ty",0.0);

}

double Limelight::GetTargetArea(){

  return table->GetNumber("ta",0.0);

}

double Limelight:: GetTargetSkew(){

  return table->GetNumber("ts",0.0);

}



// Put methods for controlling this subsystem
// here. Call these from Commands 
