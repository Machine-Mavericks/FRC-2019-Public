/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/WPILib.h>
#include "DashboardOI.h"
#include "Robot.h"

// class constructor - executed upon creation of DashboardOI object
DashboardOI::DashboardOI() { }

// Update dashboard
void DashboardOI::UpdateDashBoard(void)
{
    // Show left/right encoder distances 
    frc::SmartDashboard::PutNumber("Left Encoder", Robot::m_MainDrive.GetLeftEncoderDistance());
    frc::SmartDashboard::PutNumber("Right Encoder", Robot::m_MainDrive.GetRightEncoderDistance());
  
    // Show robot NavX gyro data
    frc::SmartDashboard::PutNumber("Yaw", Robot::m_NavX.GetYaw());
    frc::SmartDashboard::PutNumber("Roll", Robot::m_NavX.GetRoll());
    frc::SmartDashboard::PutNumber("Pitch", Robot::m_NavX.GetPitch());
  
    // Show limelight table values
    frc::SmartDashboard::PutNumber("Target Present?", Robot::m_Limelight.IsTargetPresent());
    frc::SmartDashboard::PutNumber("Horizontal Target Offset Angle", Robot::m_Limelight.GetHorizontalTargetOffsetAngle());
  frc::SmartDashboard::PutNumber("Vertical Target Offset Angle", Robot::m_Limelight.GetVerticalTargetOffsetAngle());
  frc::SmartDashboard::PutNumber("Target Area", Robot::m_Limelight.GetTargetArea());
  frc::SmartDashboard::PutNumber("Target Skew", Robot::m_Limelight.GetTargetSkew());

  frc::SmartDashboard::PutNumber("Latency", Robot::m_Limelight.GetLatencyContribution());
  frc::SmartDashboard::PutNumber("Shortest Side", Robot::m_Limelight.GetShortestSide());
  frc::SmartDashboard::PutNumber("Longest Side", Robot::m_Limelight.GetLongestSide());
  frc::SmartDashboard::PutNumber("Horizontal Side", Robot::m_Limelight.GetHorizontalSideLength());
  frc::SmartDashboard::PutNumber("Vertical Side", Robot::m_Limelight.GetVerticalSideLength());
  frc::SmartDashboard::PutNumber("Pipeline", Robot::m_Limelight.GetPipeline());

 }
