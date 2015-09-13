// quadsim.cpp
// BY BRANDON BEANLAND
#include "quadcopter.h"
#define IDLEPOWER 128
#define MAXPOWER 255

// a b
// c d
uint8_t a = IDLEPOWER;
uint8_t b = IDLEPOWER;
uint8_t c = IDLEPOWER;
uint8_t d = IDLEPOWER;

int fixCopter();
void setAllMotors(uint8_t power);
void boostMotor(uint8_t * power);
void slowMotor(uint8_t * power);

int main(int argc, char const *argv[])
{
	while(true)
	{
		// if stable, then set power to middle
		if(!(getPitch()==0 && getRoll()==0))
		{
			setAllMotors(IDLEPOWER);
			continue;
		}
		else
		{
			fixCopter();
		}
	}
	return 0;
}

// boost the side that is lower
void fixCopter()
{
	// handle pitch first
	if(getPitch()>0)
	{
		boostMotor(&a);
		boostMotor(&b);
	}
	else if(getPitch()<0)
	{
		boostMotor(&c);
		boostMotor(&d);
	}

	// handle roll next
	if(getRoll()>0)
	{
		boostMotor(&b);
		boostMotor(&d);
	}
	else if(getRoll()<0)
	{
		boostMotor(&a);
		boostMotor(&c);
	}
}

void setAllMotors(uint8_t power)
{
	a = power;
	b = power;
	c = power;
	d = power;
}

void boostMotor(uint8_t * power)
{
	uint8_t original = *power;
	*power=(original<MAXPOWER)?(original+1):MAXPOWER;
}

void slowMotor(uint8_t * power)
{
	uint8_t original = *power;
	*power=(original>0)?(original-1):0;
}
