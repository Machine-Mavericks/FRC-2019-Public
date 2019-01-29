/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/WPILib.h>
#include "DashboardOI.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Robot.h"
#include "subsystems/Limelight.h"


// class constructor - executed upon creation of DashboardOI object
DashboardOI::DashboardOI() {

  // Encoders
  frc::SmartDashboard::PutNumber("Left Encoder", Robot::m_MainDrive.GetLeftEncoderDistance());
  frc::SmartDashboard::PutNumber("Right Encoder", Robot::m_MainDrive.GetRightEncoderDistance());

  // NavX
  frc::SmartDashboard::PutNumber("Roll", Robot::m_NavX.GetRoll());
  frc::SmartDashboard::PutNumber("Yaw", Robot::m_NavX.GetYaw());
  frc::SmartDashboard::PutNumber("Pitch", Robot::m_NavX.GetPitch());
  frc::SmartDashboard::PutNumber("CompassHeading", Robot::m_NavX.ahrs->GetCompassHeading());

  // Limelight
  //frc::SmartDashboard::PutNumber("Horizontal Target Offset Angle", Robot::m_Limelight.GetHorizontalTargetOffsetAngle());
  //frc::SmartDashboard::PutNumber("Vertical Target Offset Angle", Robot::m_Limelight.GetVerticalTargetOffsetAngle());
  //frc::SmartDashboard::PutNumber("Target Area", Robot::m_Limelight.GetTargetArea());
  //frc::SmartDashboard::PutNumber("Target Skew", Robot::m_Limelight.GetTargetSkew());

}