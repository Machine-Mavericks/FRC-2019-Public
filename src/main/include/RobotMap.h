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
#define LINEAR_WEIGHT                   1.0                     // value between 0 and 1
#define CUBIC_WEIGHT                    (1.0 - LINEAR_WEIGHT)   // automatically calculated to ensure equivalence to 1

// Robot wheel diameter (in inches) - used to determine travel distance
#define WHEEL_DIAMETER                  6.0      

// Robot encocer resolution (pulse counts per revolution)
#define ENCODER_PULSE_PER_REVOLUTION    360.0

// Other constants
constexpr double kPi = 3.14159265358979;

// ------------- Elevator Constants -------------


// Motor Drive CANbus node IDs
#define ELEVATOR_MOTOR_CANID            6

// Joystick Axis IDs
#define JOYSTICK_ELEVATOR_AXIS_ID       5

// Motor encoder counts per revolution
// TalonSRX uses 4x count mode - encocer normally has 1024 pulses per revolution
#define ELEVATOR_ENCODER_PULSE_PER_REVOLUTION   4096

// Maximum ramp rate of drive - time(s) from zero to full appplied voltage
#define ELEVATOR_DRIVE_MAXRAMP          0.15

// Maximum applied motor voltage in forward and reverse direction (can be used to limit speed)
// Value betwen 0.0 and 1.0
#define ELEVATOR_DRIVE_FULL_VLTG_FWD    1.0
#define ELEVATOR_DRIVE_FULL_VLTG_REV    1.0

// claw current limit
#define ELEVATOR_CURRENT_LIMIT          20

// Elevator position control error gains
#define ELEVATOR_PGAIN                 0.5
#define ELEVATOR_IGAIN                 0.004   
#define ELEVATOR_DGAIN                 20.0        
#define ELEVATOR_MAX_INTEGRAL_ACCUMULATOR   40000.0     // in encoder units x ms

// Maximum closed loop error - within this error no control action is performed (in sensor units)
#define ELEVATOR_ALLOWABLE_CLOSEDLOOP_ERROR 1

// Elevator soft (software) limits - in # of encoder pulses
// MiN would normally be 0 for elevator, corresponding to lowest position (home position)
#define ELEVATOR_SOFT_LIMIT_MIN         0  
#define ELEVATOR_SOFT_LIMIT_MAX         50000
         
// Elevator defined positions - in # of encoder pulses
#define ELEVATOR_POSITION0              0
#define ELEVATOR_POSITION1              10000
#define ELEVATOR_POSITION2              20000
#define ELEVATOR_POSITION3              30000
#define ELEVATOR_POSITION4              40000

// Elevator positional tolerance. Elevator reports in position if within +/- tolerance of target position
#define ELEVATOR_POSITION_TOLERANCE     200


// ------------- Claw Constants -------------


// Motor Drive CANbus node IDs
#define CLAW_MOTOR_CANID         9

// Motor encoder counts per revolution
// TalonSRX uses 4x count mode - encocer normally has 1024 pulses per revolution
#define CLAW_ENCODER_PULSE_PER_REVOLUTION   4096

// claw current limit
#define CLAW_CURRENT_LIMIT          1


// Elevator soft (software) limits - in # of encoder pulses
// MiN would normally be 0 for elevator, corresponding to lowest position (home position)
#define CLAW_SOFT_LIMIT_MIN         0  
#define CLAW_SOFT_LIMIT_MAX         1023
         
// Elevator defined positions - in # of encoder pulses
#define CLAW_BALL_POSITION              1023
#define CLAW_OPEN_POSITION              0 // 4000
#define CLAW_HATCH_POSITION             515 //8000 

// Elevator position control error gains
#define CLAW_PGAIN                  8.0 // 4.0 // 0.8 // 0.2
#define CLAW_IGAIN                  0.001 // 05 // 0.0002     // Note: I gain should be used very sparingly. 
#define CLAW_DGAIN                  0.01         

// Maximum closed loop error (in sensor units)
#define CLAW_ALLOWABLE_CLOSEDLOOP_ERROR 10

#define CLAW_POSITION_TOLERANCE 100

// ------------- IntakeTilt Constants -------------


// Motor Drive CANbus node IDs
#define TILT_MOTOR_CANID         8


// Motor encoder counts per revolution
// TalonSRX uses 4x count mode - encocer normally has 1024 pulses per revolution
#define TILT_ENCODER_PULSE_PER_REVOLUTION   4096


// Elevator soft (software) limits - in # of encoder pulses
// MiN would normally be 0 for elevator, corresponding to lowest position (home position)
#define TILT_SOFT_LIMIT_MIN         0  
#define TILT_SOFT_LIMIT_MAX         1023
         
// Elevator defined positions - in # of encoder pulses
#define TILT_UP_POSITION              0
#define TILT_MID_POSITION              515// 4000
#define TILT_DOWN_POSITION             1300 //8000 

// Elevator position control error gains
#define TILT_PGAIN                 0.5// 0.8 //  0.8 // 0.2
#define TILT_IGAIN                  0.00015 //0.0005 // 0.0002  // Note: I gain should be used very sparingly. 
#define TILT_DGAIN                  80 // 0.01         

// Maximum closed loop error (in sensor units)
#define TILT_ALLOWABLE_CLOSEDLOOP_ERROR 1

#define TILT_POSITION_TOLERANCE 100

// --------- LobClaw constants ---------------------------------------------------------

#define LC_OPEN_CHANNEL 1
#define LC_CLOSE_CHANNEL 2

#define PI 3.14159265358979323846264338327