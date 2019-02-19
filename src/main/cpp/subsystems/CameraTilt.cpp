/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/CameraTilt.h"
#include "RobotMap.h"


CameraTilt::CameraTilt() : Subsystem("CameraTilt")
{

    // create PWM object on RoboRIO channel 0
    m_Servo = new Servo(0);

    // default angle
    SetTilt(45.0);
}

// default command to run with the subsystem
void CameraTilt::InitDefaultCommand()
{
}


// sets camera tilt to desired angle
// Angle between 0 and 1
void CameraTilt::SetTilt(float value)
{
    // PWM 50Hz
    // 1ms = 0deg
    // 1.5ms = 90deg
    // 2ms = 180deg
    
    // set tilt value
    m_Servo->SetAngle(value);
}

