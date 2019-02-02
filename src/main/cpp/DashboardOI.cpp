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
    frc::SmartDashboard::PutNumber("ElevatorTargetPosition", Robot::m_Elevator.GetElevatorTargetPosition());
    frc::SmartDashboard::PutBoolean("ElevatorAtTarget?", Robot::m_Elevator.IsElevatorAtTarget());
       
 }
