/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/WPILib.h>
#include "MechanismOI.h"
#include "RobotMap.h"
#include "commands/ElevatorUpDownPosition.h"
#include "commands/TiltUp.h"
#include "commands/TiltDown.h"
#include "commands/TiltMid.h"
#include "commands/LobClawOpenClose.h"
#include "commands/EjectBall.h"
#include "commands/EatBall.h"

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
    MechanismJoystickButton9 = new JoystickButton(MechanismJoystick,9);
    MechanismJoystickButton10 = new JoystickButton(MechanismJoystick,10);


    // move elevator up or down one position
    MechanismJoystickButton1->WhenPressed(new ElevatorUpDownPosition(false));
    MechanismJoystickButton4->WhenPressed(new ElevatorUpDownPosition(true));
    
    // open and close claw
   // MechanismJoystickButton3->WhenPressed(new GrabBall());
    //MechanismJoystickButton2->WhenPressed(new Open());
    //MechanismJoystickButton6->WhenPressed(new GrabHatch());

    // tilt claw
    MechanismJoystickButton5->WhenPressed(new TiltMid());
    MechanismJoystickButton7->WhenPressed(new TiltDown());
    MechanismJoystickButton8->WhenPressed(new TiltUp());

    // turn intake wheels

    MechanismJoystickButton9->WhenPressed(new EatBall());
    MechanismJoystickButton10->WhenPressed(new EjectBall());


    // open/close LobClaw
 
    MechanismJoystickButton3->WhenPressed(new LobClawOpenClose(1));
    MechanismJoystickButton2->WhenPressed(new LobClawOpenClose(0));
 

}
  