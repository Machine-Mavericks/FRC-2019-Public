/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/GoToTarget.h"
#include "commands/TurnToAngle.h"
#include "commands/DistanceDrive.h"
#include "Robot.h"
#include "RobotMap.h"

GoToTarget::GoToTarget() {
  /*Limelight::CamTran vector = Robot::m_Limelight.GetCameraTransformation();
  float camtranx = vector.x;
  float camtranz = vector.z;
  float theta = atan(PI/180(camtranz/camtranx));                                
  float Angleb = theta-atan(PI/180(camtranz-44)/camtranx); 
  float distanceA = sqrt(pow(camtranx,2)+pow((camtranz-44),2));
  float tx = Robot::m_Limelight.GetHorizontalTargetOffsetAngle();
  float Anglec = 90-theta-Angleb;
  float Anglea = Anglec-180;

  AddSequential(new TurnToAngle(Angleb,0.25,0.3));
  AddSequential(new DistanceDrive(distanceA));
  AddSequential(new TurnToAngle(Anglea,0.25,0.3));*/

  AddSequential(new DistanceDrive(7));
  AddSequential(new DistanceDrive(-7));


}
