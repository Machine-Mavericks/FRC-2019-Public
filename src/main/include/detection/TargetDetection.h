// Target detection and estimation functions
// These functions may use various robot systems as required 

#pragma once

#include "robot.h"

// minimum ball detection area (# square pixels)
// 1000 sq pixels corresponds to ~8 ft
#define MIN_BALL_DETECTION_AREA     1000.0

struct BALL_TARGET {
    bool Detected;          // true if ball has been detected
    float Area;             // area of detected ball (in # sq pixels)
    float XAngle;           // angle (deg) of target relative to center-line of camera
    float Distance;         // estimated distance (in) of ball from camera
    BALL_TARGET()           // defaults
    { Detected = false; }
};


// ---------- Ball Detection Routines ----------

// returns ball target data
BALL_TARGET GetBallTargetEstimation(void);


// ---------- Chevron Detection Routines */
    

