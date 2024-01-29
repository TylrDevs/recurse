using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern controller Controller1;
extern motor Intake;
extern motor Flywheel;
extern digital_out Wings;
extern digital_out BarrierHang;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor leftMotorC;
extern motor rightMotorA;
extern motor rightMotorB;
extern motor rightMotorC;





/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );