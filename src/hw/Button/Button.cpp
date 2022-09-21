#include "Button.h"
#include "wiringPi.h"
 
Button::Button(int pin)
    : pinNumber(pin), prevState(RELEASED)
{
    wiringPiSetup();
    pinMode(pinNumber, INPUT);
}

Button::~Button()
{
}

int Button::readPin()
{
    return digitalRead(pinNumber);
}

int Button::getState()
{
    int curState = readPin();
    if (curState == PUSHED && prevState == RELEASED) {
        prevState = PUSHED;
        return PUSH_ACTIVE;
    }
    else if (curState == RELEASED && prevState == PUSHED) {
        prevState = RELEASED;
        return RELEASE_ACTIVE;
    }
    return NO_ACTIVE;
}
