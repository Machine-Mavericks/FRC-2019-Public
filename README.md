# FRC-2019-Build
Public Release of Machine Mavericks robot control system using 2019 FRC libraries

Repository includes source (src) files folder. Copy 'src' folder into main robot project folder and rebuild project
Requires: 2019 FRC Studio and WPI libraries, and Victor SPX libraries installed.fs

Jan 27/2019: Rev 1
Now includes fully functional tank and arcade drive modes - both only available when robot is in teleop mode
Tank mode is default. Press and hold right joystick trigger for arcade drive mode. Releasing trigger returns robot to tank mode.
Right joystick throttle controls thrust throttle for both Tank and Arcade modes.
Subsystems include MainDrive (incl left/right encoders) and NavX for Gyro monitoring (not used in this release)
Commands include TankDrive and ArcadeDrive
Constants now in Robotmap.h
All driver station updates moved to DriverStation.h

Known issues:
1) May require fine-tuning of joystick response characteristics which can be done at later date

For next release:
1) Add functional Limelight camera subsystem
2) TBD


Jan 15/2019: Initial KN
Inlcudes tank drive mode - only when robot is in teleop mode.
Known issues:
1) Need to create file to contain all robot constants, in place of hard-coded numbers
2) Tank drive joystick drive requires dead-zone and adjustment to joystick response characteristics for more precise low-speed driving








