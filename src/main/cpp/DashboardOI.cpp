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
    
    // Elevator data
    frc::SmartDashboard::PutNumber("ElevatorTargetPosition", Robot::m_Elevator.GetElevatorTargetPresetPosition());
    frc::SmartDashboard::PutBoolean("ElevatorAtTarget?", Robot::m_Elevator.IsElevatorAtTarget());
    frc::SmartDashboard::PutNumber("Next Elevator Position", Robot::m_Elevator.GetElevatorNextHigherPresetPosition());
    frc::SmartDashboard::PutNumber("Elevator Motor Current", Robot::m_Elevator.GetMotorCurrent());
    frc::SmartDashboard::PutNumber("Elevator Encoder", Robot::m_Elevator.GetEncoderPosition());

    // Show Limelight data
    /*frc::SmartDashboard::PutNumber("Target Present?", Robot::m_Limelight.IsTargetPresent());
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

    // Show limelight raw contours (to see if they are useful)
    frc::SmartDashboard::PutNumber("RawScreenspaceX0", Robot::m_Limelight.GetRawScreenspaceX0());
    frc::SmartDashboard::PutNumber("RawScreenspaceX1", Robot::m_Limelight.GetRawScreenspaceX1());
    frc::SmartDashboard::PutNumber("RawScreenspaceX2", Robot::m_Limelight.GetRawScreenspaceX2());
    frc::SmartDashboard::PutNumber("RawScreenspaceY0", Robot::m_Limelight.GetRawScreenspaceY0());
    frc::SmartDashboard::PutNumber("RawScreenspaceY1", Robot::m_Limelight.GetRawScreenspaceY1());
    frc::SmartDashboard::PutNumber("RawScreenspaceY2", Robot::m_Limelight.GetRawScreenspaceY2());
    frc::SmartDashboard::PutNumber("RawArea0", Robot::m_Limelight.GetRawArea0());
    frc::SmartDashboard::PutNumber("RawArea1", Robot::m_Limelight.GetRawArea1());
    frc::SmartDashboard::PutNumber("RawArea2", Robot::m_Limelight.GetRawArea2());
    frc::SmartDashboard::PutNumber("RawSkew0", Robot::m_Limelight.GetRawSkew0());
    frc::SmartDashboard::PutNumber("RawSkew1", Robot::m_Limelight.GetRawSkew1());
    frc::SmartDashboard::PutNumber("RawSkew2", Robot::m_Limelight.GetRawSkew2());
    */

       // claw
    frc::SmartDashboard::PutNumber("ClawEncoder", Robot::m_Claw.GetEncoderPosition());
    frc::SmartDashboard::PutBoolean("IsFwdSwitchClosedClaw", Robot::m_Claw.IsFwdLimitSwitchClosed());
    frc::SmartDashboard::PutBoolean("IsRevSwitchClosedClaw",Robot::m_Claw.IsRevLimitSwitchClosed());
    frc::SmartDashboard::PutNumber("ClawCurrent", Robot::m_Claw.GetMotorCurrent());


    // intake tilt
    frc::SmartDashboard::PutNumber("TiltEncoder", Robot::m_IntakeTilt.GetEncoderPosition());
    frc::SmartDashboard::PutBoolean("IsFwdSwitchClosed", Robot::m_IntakeTilt.IsFwdLimitSwitchClosed());
    frc::SmartDashboard::PutBoolean("IsRevSwitchClosed",Robot::m_IntakeTilt.IsRevLimitSwitchClosed());
    frc::SmartDashboard::PutNumber("TiltEncoder", Robot::m_IntakeTilt.GetEncoderPosition());
 }
