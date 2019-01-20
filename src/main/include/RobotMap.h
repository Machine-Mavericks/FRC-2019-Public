/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// Motor Drive CANbus node IDs
#define FRONT_LEFT_MOTOR_CANID    2
#define FRONT_RIGHT_MOTOR_CANID  3
#define REAR_LEFT_MOTOR_CANID    5
#define REAR_RIGHT_MOTOR_CANID  4

// Joystick port Ids
#define RIGHT_JOYSTICK_PORT 1
#define LEFT_JOYSTICK_PORT 0
#define MECHANISM_CONTROLLER_PORT 2

// Wrist PID gains
#define WRIST_P_GAIN 1.0
#define WRIST_I_GAIN 0.0
#define WRIST_D_Gain 0.0

// Throttle Curve Coefficients
#define LINEAR_WEIGHT 0.5           // value between 0 and 1
#define CUBIC_WEIGHT (1.0 - LINEAR_WEIGHT) // automatically calculated to ensure equivalence to 1

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
