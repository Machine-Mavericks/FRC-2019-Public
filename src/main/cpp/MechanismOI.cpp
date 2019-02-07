/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/WPILib.h>
#include "MechanismOI.h"
#include "RobotMap.h"
#include "commands/ElevatorChangePosition.h"
#include "commands/Open.h"
#include "commands/GrabHatch.h"
#include "commands/GrabBall.h"


// class constructor - executed upon creation of MechanismOI object
// creates joystick operator interfaces
MechanismOI::MechanismOI() {

    // create operator joystick objects
    MechanismJoystick = new Joystick(MECHANISM_CONTROLLER_PORT);

    // create robot operator button objects and associate with operator joystick and button #
    MechanismJoystickButton1 = new JoystickButton(MechanismJoystick,1);
    MechanismJoystickButton2 = new JoystickButton(MechanismJoystick,2);
    MechanismJoystickButton3 = new JoystickButton(MechanismJoystick,3);
    MechanismJoystickButton4 = new JoystickButton(MechanismJoystick,4);
    MechanismJoystickButton5 = new JoystickButton(MechanismJoystick,5);
    MechanismJoystickButton6 = new JoystickButton(MechanismJoystick,6);
    MechanismJoystickButton7 = new JoystickButton(MechanismJoystick,7);
    MechanismJoystickButton8 = new JoystickButton(MechanismJoystick,8);
    
    // associate operator joystick buttons with commands
    // TBD


    // move elevator to target position
    MechanismJoystickButton1->WhenPressed(new ElevatorChangePosition(false));
    MechanismJoystickButton4->WhenPressed(new ElevatorChangePosition(true));

    // move claw to target position
    MechanismJoystickButton3->WhenPressed(new GrabBall());
    MechanismJoystickButton2->WhenPressed(new Open());
    MechanismJoystickButton6->WhenPressed(new GrabHatch());


}
  