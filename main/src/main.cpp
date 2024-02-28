/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    6, 7, 10, 13, 9 
// Controller1          controller                    
// Intake               motor         5               
// Flywheel             motor         3               
// Wings                digital_out   B               
// BarrierHang          digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;


// define your global instances of motors and other devices here

motor_group left_motors = motor_group(leftMotorA, leftMotorB, leftMotorC);
motor_group right_motors = motor_group(rightMotorA, rightMotorB, rightMotorC);
motor_group full_drive = motor_group(leftMotorA, leftMotorB, leftMotorC, rightMotorA, rightMotorB, rightMotorC);
bool wing_tog = true;
bool hang_tog = false;
bool flywheel_tog = false;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  /*Wings.set(true);

  Drivetrain.setDriveVelocity(30, percent);

  Drivetrain.driveFor(reverse, 29, inches);*/
  

  

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

void change_wing(){
  wing_tog = !wing_tog;
  Wings.set(wing_tog);

}

void activate_hang(){
  hang_tog = !hang_tog;
  BarrierHang.set(hang_tog);
}

void toggle_flywheel(){
  flywheel_tog = !flywheel_tog;

  if (flywheel_tog == true) {
    Flywheel.spin(reverse);
  }
  else {
    Flywheel.stop();
  }
}

void auton_test() {
  Wings.set(true);
  full_drive.setVelocity(30, percent);
  full_drive.spinFor(reverse, 5.6, rev);
  vex::task::sleep(200);
  full_drive.setVelocity(30, percent);
  full_drive.spinFor(forward, 4.5, rev);
  vex::task::sleep(500);
  Drivetrain.setTurnVelocity(30, percent);
  Drivetrain.turnToHeading(45, deg);
  vex::task::sleep(500);
  full_drive.spinFor(3, rev);
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  Controller1.ButtonRight.pressed(auton_test);

  Intake.setVelocity(100, percent);
  Flywheel.setVelocity(100, percent);

  Controller1.ButtonL1.pressed(change_wing);

  Controller1.ButtonY.pressed(activate_hang);

  Controller1.ButtonB.pressed(toggle_flywheel);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
