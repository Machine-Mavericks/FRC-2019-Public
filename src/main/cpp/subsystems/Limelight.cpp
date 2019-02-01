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


Limelight::Limelight() : Subsystem("Limelight") {
  table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
}

void Limelight::InitDefaultCommand() {}

double Limelight::GetHorizontalTargetOffsetAngle(){

  return table->GetNumber("tx",0.0);

}

double Limelight::GetVerticalTargetOffsetAngle(){

  return table->GetNumber("ty",0.0);

}

double Limelight::GetTargetArea(){

  return table->GetNumber("ta",0.0);

}

double Limelight::GetTargetSkew(){

  return table->GetNumber("ts",0.0);

}

bool Limelight::IsTargetPresent(){

  return table->GetNumber("tv", 0);
  
}

double Limelight::GetLatencyContribution(){

  return table->GetNumber("tl",0.0);

}

int Limelight::GetShortestSide(){

  return table->GetNumber("tshort",0);

}

int Limelight::GetLongestSide(){

  return table->GetNumber("tlong",0);

}

int Limelight::GetHorizontalSideLength(){

  return table->GetNumber("thor",0);

}

int Limelight::GetVerticalSideLength(){

  return table->GetNumber("tvert",0);

}

int Limelight::GetPipeline(){

  return table->GetNumber("getpipe",0);

}


// Put methods for controlling this subsystem
// here. Call these from Commands 
