#include "main.h"
#include "base.h"
#include "pragma.h"
using namespace pros;
//test
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() 
{
	std::cout << "START VEX PROGRAM" << std::endl;

	//skills
	/*flywheelred(true);
	shoot(2);
	flywheelred(false);
	turnBase(-25, 127);
	pros::delay(100);
	moveBase(-110,127);
	roller(-200);
	pros::delay(200);
	turnBase(-150,127);
	piston3.set_value(true);
	pros::delay(10000);
	piston3.set_value(false);*/

	//FAR ROLLER SHOOTING FOR 2 points
	/*moveBase(-420, 100);
	turnBase(-230, 127);
	moveBase(-220,127);
	roller(-150);
	pros::delay(500);
	moveBase(60,127);
	turnBase(320,127);
	moveBase(100,127);*/
	/*flywheel(true, 58);
	shoot(2);
	flywheel(false, 0);*/

	//FAR ROLLER SHOOTING FOR 10 points
	/*moveBase(-320, 127);
	turnBase(-300, 127);
	moveBase(-170,127);
	roller(-150);
	pros::delay(500);
	moveBase(30,127);
	turnBase(-65,127);
	flywheelblue(true);
	shoot(2);
	flywheelblue(false);*/

	//REDSIDE ROLLER AND 10
	flywheelred(true);
	shoot(2);
	flywheelred(false);
	/*turnBase(-25, 127);
	pros::delay(100);
	moveBase(-110,127);
	roller(-200);
	pros::delay(200);*/

	std::cout << "END VEX PROGRAM" << std::endl;
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	leftBase1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	leftBase2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	rightBase1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	rightBase2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor right_mtr(2);

	std::cout << "START VEX PROGRAM" << std::endl;

	while (true) {
		runLeftBase(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
		runRightBase(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
		
		bool state = LOW;
    
	//state != state;

    piston1.set_value(true);
	piston2.set_value(true);
	piston3.set_value(false);
    pros::delay(10); // toggle the sensor value every 50ms
  

		pros::delay(20);

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
		{
			flywheel1.move(59);
			flywheel2.move(-57);
		}
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X))
		{
			flywheel1.move(70);
			flywheel2.move(0);
		}
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
		{
			flywheel1.move(70);
			flywheel2.move(-70);
		}
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
		{
			flywheel1.move(50);
			flywheel2.move(-50);
		}
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			flywheel1.move(0);
			flywheel2.move(0);
		}
		
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			intake1.move(130);
			intake2.move(130);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			intake1.move(-130);
			intake2.move(-130);
		}
		else
		{
			intake1.move(0);
			intake2.move(0);
		}

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
		{
			piston1.set_value(false);
			piston2.set_value(false);
			pros::delay(150);
			piston1.set_value(true);
			piston2.set_value(true);
		}

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) && master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			piston3.set_value(true);
			pros::delay(10000);
			piston3.set_value(false);
		}
}
}	