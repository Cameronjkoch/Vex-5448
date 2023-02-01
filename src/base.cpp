#include "main.h"
#include "pragma.h"
#include "base.h"
void runLeftBase(double input)
{
    if (input < 0)
    {
        input = -input * input / 130;
        //if (input < -127) input = -127;
    }
    else
    {
        input = input * input / 130;
        //if (input > 127) input = 127;
    }
    leftBase1.move(-input);
    leftBase2.move(-input);
    std::cout << "left " << input << std::endl;
}

void runRightBase(double input)
{
    if (input < 0)
    {
        input = -input * input / 130;
        //if (input < -127) input = -127;
    }
    else
    {
        input = input * input / 130;
        //if (input > 127) input = 127;
    }
    rightBase1.move(-input);
    rightBase2.move(-input);
    std::cout << "right " << input << std::endl;
}

void moveBase(double input, double speed)
{
    leftBase1.tare_position(); 
    leftBase2.tare_position(); 
    rightBase1.tare_position();
    rightBase2.tare_position();
 
    leftBase1.move_relative(input, speed);
    leftBase2.move_relative(input, speed);
    rightBase1.move_relative(input, speed);
    rightBase2.move_relative(input, speed);
    while (!((leftBase2.get_position() < input + 5) && (leftBase2.get_position() > input - 5)))
    {
        pros::delay(2);
    }
}
void turnBase(double input, double speed)
{
    std::cout << "works" << std::endl;
    leftBase1.tare_position(); 
    leftBase2.tare_position(); 
    rightBase1.tare_position();
    rightBase2.tare_position();


    leftBase1.move_relative(input, speed);
    leftBase2.move_relative(input, speed);
    rightBase1.move_relative(-input, speed);
    rightBase2.move_relative(-input, speed);
   
    input=abs(input);

    
    int iLastRightPosition = 0;
    int iLastLeftPosition = 0;   
    checkMoving(input);
}
void shoot(int input)
	{	
        for(int i=0;i<input;i++)
		{
            piston1.set_value(false);
		    piston2.set_value(false);
		    pros::delay(150);
		    piston1.set_value(true);
		    piston2.set_value(true);
            pros::delay(1000);
        }
	}

    void shootblue(int input)
	{	
        for(int i=0;i<input;i++)
		{
            piston1.set_value(false);
		    piston2.set_value(false);
		    pros::delay(150);
		    piston1.set_value(true);
		    piston2.set_value(true);
            pros::delay(2000);
        }
	}

void flywheel(bool bOn, double speed)
    {
        if (bOn)
        {
            piston1.set_value(true);
		    piston2.set_value(true);
            pros::delay(100);
            flywheel1.move(speed);
            flywheel2.move(-speed);
            pros::delay(3250);
        }
        else {
            flywheel1.move(0);
            flywheel2.move(0);   
        }
    }


    void flywheelred(bool bOn)
    {
        if (bOn)
        {
            piston1.set_value(true);
		    piston2.set_value(true);
            pros::delay(100);
            flywheel1.move(70);
            flywheel2.move(-80);
            pros::delay(3250);
        }
        else {
            flywheel1.move(0);
            flywheel2.move(0);   
        }
    }

    void flywheelblue(bool bOn)
    {
        if (bOn)
        {
            piston1.set_value(true);
		    piston2.set_value(true);
            pros::delay(100);
            flywheel1.move(70);
            flywheel2.move(-80);
            pros::delay(3250);
        }
        else {
            flywheel1.move(0);
            flywheel2.move(0);   
        }
    }

    void roller(double input)
{
    intake1.tare_position(); 
    intake2.tare_position(); 
 
    intake1.move_relative(input, 127);
    intake2.move_relative(input, 127);
    while (!((intake2.get_position() < input + 5) && (intake2.get_position() > input - 5)))
    {
        pros::delay(2);
    }
}
void checkMoving(double input)
{
    leftBase1.tare_position(); 
    leftBase2.tare_position(); 
    //std:: cout << "checkMoving " << input << std::endl;
    double avgPos = (abs(leftBase1.get_position()) + abs(leftBase2.get_position()))/2.0;
    while (!(avgPos <= input + 5 && avgPos >= input - 5))
    {
        avgPos = (+abs(leftBase1.get_position()) + abs(leftBase2.get_position()))/2.0;
    }
}
