// Target detection and estimation functions
// These functions may use various robot systems as required 

#include "detection/TargetDetection.h"


// ---------- Ball Detection Routines ----------


// Test Data from Lab (Feb 3/18 estimates - requires retest for better accuracy)
// Size (typ x and y)            Distance              
// 84                            42" (1.1m)
// 36                            93" (2.4m)  (base case)
// 16                            168" (4.3m)

// returns true if ball is detected
BALL_TARGET GetBallTargetEstimation(void)
{
    BALL_TARGET target;
    
    // determine if camera has acquired a target
    // camera must be set to correct pipeline AND be detecting an object
    bool detected = (Robot::m_Limelight.GetPipeline()==1) && Robot::m_Limelight.IsTargetPresent();
  
    // get target area of ball (in sq pixels)
    float area = Robot::m_Limelight.GetTargetArea();

    // average size of ball - average of x and y lengths
    float avgsize = 0.5*(Robot::m_Limelight.GetVerticalSideLength()+Robot::m_Limelight.GetHorizontalSideLength()) ;

    // do we have a valid target? - also check avg size, so we don't divide by zero!
    // camera must detect target AND ball larger than minimum size
    if ((detected==true) && (area >= MIN_BALL_DETECTION_AREA) && (avgsize!=0.0))
    {
        // we have a valid target - populate target info
        target.Detected = true;
        target.Area = area;
        target.XAngle = Robot::m_Limelight.GetHorizontalTargetOffsetAngle();
        target.Distance = (36.0 / avgsize) * 93.0;
    }
    else
        // we do not have a valid target
        target.Detected = false;

    // return target data
    return target;
}



// ---------- Chevron Detection Routines


