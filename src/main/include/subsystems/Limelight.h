/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Limight subsytem contains all functions needed to access camera

#pragma once

#include <frc/commands/Subsystem.h>
#include <networkTables/networkTable.h>
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

class Limelight : public frc::Subsystem {
    public:
  
    // constructor - used to initialize specific hardware
    Limelight();

    // default command to run with the subsystem
    void InitDefaultCommand() override;
  

    // ---------- Camera Control Functions

    // set/get Limelight camera's current pipeline
    void SetPipeline(unsigned int num);
    unsigned int GetPipeline(void);

    // ---------- Camera Data Functions
    
    // get angles to center of target
    float GetHorizontalTargetOffsetAngle();
    float GetVerticalTargetOffsetAngle();
    float GetTargetSkew();
 
    // get target detection time latency
    float GetLatencyContribution();

    // get whether target is currently detected or not
    bool IsTargetPresent();

    // get target atributes
    float GetTargetArea();
    int GetShortestSide();
    int GetLongestSide();
    int GetHorizontalSideLength();
    int GetVerticalSideLength();
 
    private:

    // create pointer to Limelight object
    std::shared_ptr<NetworkTable> table;

};


