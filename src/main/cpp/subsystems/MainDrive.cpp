/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "subsystems/MainDrive.h"
#include "RobotMap.h"


constexpr double kPi = 3.14159265358979;

MainDrive::MainDrive() : Subsystem("MainDrive") {

  // create individual motor control objects - assign unique CAN address to each motor drive
  m_MotorFrontLeft = new WPI_VictorSPX(FRONT_LEFT_MOTOR_CANID);
  m_MotorRearLeft = new WPI_VictorSPX(REAR_LEFT_MOTOR_CANID);
  m_MotorFrontRight = new WPI_VictorSPX(FRONT_RIGHT_MOTOR_CANID);
  m_MotorRearRight = new WPI_VictorSPX(REAR_RIGHT_MOTOR_CANID);
  
  // configure motor drives with factory default settings
  m_MotorFrontLeft->ConfigFactoryDefault();
  m_MotorRearLeft->ConfigFactoryDefault();
  m_MotorFrontRight->ConfigFactoryDefault();
  m_MotorRearRight->ConfigFactoryDefault();

  // set rear drives to follow front ones
  m_MotorRearLeft->Follow(*m_MotorFrontLeft);
  m_MotorRearRight->Follow(*m_MotorFrontRight);

  // create differential drive
  m_Drive = new DifferentialDrive(*m_MotorFrontLeft, *m_MotorFrontRight);

  // create encoder objects
  m_EncoderRight = new Encoder(2,3);
  m_EncoderLeft = new Encoder(0,1);

  // Use SetDistancePerPulse to set the multiplier for GetDistance
  // This is set up assuming a 6 inch wheel with a 360 CPR encoder.
  m_EncoderRight->SetDistancePerPulse((kPi * 6) / 360.0);
  m_EncoderLeft->SetDistancePerPulse((kPi * 6) / 360.0);

  // reset encoders
  ResetLeftEncoder();
  ResetRightEncoder();
}

  // default command to run with the subsystem
void MainDrive::InitDefaultCommand() {
  // For drive there is no default command
}


// Drive in Tank Drive - where left and right motors are driven independently
// Inputs: LeftSpeed, RightSpeed - -1 <=speed <= +1.
// -1: full reverse
// 0: full stop 
// +1: full forward
// Left motor is inverted
void MainDrive::TankDrive(float LeftSpeed, float RightSpeed) {

  // make a local copy of left and right, so we can check each for range & invert left motor
  float left = -LeftSpeed;
  float right = RightSpeed;

  // ensure speeds given to us are between -1.0 and 1.0
  if (left > 1.0)
    left = 1.0;
  if (left < -1.0)
    left = -1.0;

  if (right > 1.0)
    right = 1.0;
  if (right < -1.0)
    right = -1.0;

  // command drive to tankdrive at specified speeds
  //m_MotorFrontLeft->Set(ControlMode::PercentOutput, left);
  //m_MotorFrontRight->Set(ControlMode::PercentOutput, right);
  m_Drive->TankDrive(left, right);
  m_MotorFrontRight->GetSelectedSensorPosition();
  m_MotorFrontLeft->GetSelectedSensorPosition();


}

void MainDrive::ArcadeDrive(float XSpeed, float ZRotation) {

  // make a local copy of left and right, so we can check each for range & invert left motor
  float speed = XSpeed;
  float rotation = ZRotation;

  // ensure speeds given to us are between -1.0 and 1.0
  if (speed > 1.0)
    speed = 1.0;
  if (speed < -1.0)
    speed = -1.0;

  if (rotation > 1.0)
    rotation = 1.0;
  if (rotation < -1.0)
    rotation = -1.0;

  m_Drive->ArcadeDrive(speed, rotation);



}


  float MainDrive::GetLeftEncoderDistance(void){
    // get left encoder distance since last reset
    return m_EncoderLeft->GetDistance();
  }

  float MainDrive::GetRightEncoderDistance(void){
    // get right encoder distance since last reset
    return m_EncoderRight->GetDistance();
  }

  void MainDrive::ResetLeftEncoder(void){
   //reset the left encoder to 0 distance
    m_EncoderLeft->Reset();
  }

  void MainDrive::ResetRightEncoder(void){
    // reset the right encoder to 0 value
    m_EncoderRight->Reset();

  }