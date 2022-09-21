#ifndef __BUTTON_H__
#define __BUTTON_H__
 
enum {NO_ACTIVE, PUSH_ACTIVE, RELEASE_ACTIVE};

class Button
{
private:
    const int SET = 1;
    const int RESET = 0;
    const int PUSHED = RESET;
    const int RELEASED = SET;

    int pinNumber;
    int prevState;

    int readPin();

public:
    Button(int pin);
    virtual ~Button();
    int getState();

};


#endif /* __BUTTON_H__ */
