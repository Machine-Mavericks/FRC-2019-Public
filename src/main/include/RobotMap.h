/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// Motor Drive CANbus node IDs
#define FRONT_LEFT_MOTOR_CANID          2
#define FRONT_RIGHT_MOTOR_CANID         3
#define REAR_LEFT_MOTOR_CANID           5
#define REAR_RIGHT_MOTOR_CANID          4

// Joystick port Ids
#define LEFT_JOYSTICK_PORT              0
#define RIGHT_JOYSTICK_PORT             1
#define MECHANISM_CONTROLLER_PORT       2

// Joystick Axis IDs
#define JOYSTICK_X_AXIS_ID              0
#define JOYSTICK_Y_AXIS_ID              1
#define JOYSTICK_THROTTLE_AXIS_ID       3

// Encoder Channel IDs - defines RoboRio I/O # for each encoder channel 
#define RIGHT_ENCODER_CHANNELA_ID       2       
#define RIGHT_ENCODER_CHANNELB_ID       3
#define LEFT_ENCODER_CHANNELA_ID        0
#define LEFT_ENCODER_CHANNELB_ID        1

// Throttle Curve Coefficients - used for tank and arcade drive modes
#define LINEAR_WEIGHT                   0.5                     // value between 0 and 1
#define CUBIC_WEIGHT                    (1.0 - LINEAR_WEIGHT)   // automatically calculated to ensure equivalence to 1

// Robot wheel diameter (in inches) - used to determine travel distance
#define WHEEL_DIAMETER                  6.0      

// Robot encocer resolution (pulse counts per revolution)
#define ENCODER_PULSE_PER_REVOLUTION    360.0



// Other constants
constexpr double kPi = 3.14159265358979;



