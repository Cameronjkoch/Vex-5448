#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor leftBase1(9, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftBase2(7, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBase1(19, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBase2(10, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lift(13, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake1(11, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake2(5, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);