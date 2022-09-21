#include "ManageButton.h"

ManageButton::ManageButton(int pin, std::string name)
: Button(pin) //부모클래스의 생성자에 넣어주면 됨
{
    buttonData.devName = name;
}

ManageButton::~ManageButton()
{

}

bool ManageButton::checkButton()
{
    if(getState() == RELEASE_ACTIVE)
    {
        return true;
    }
    return false;
}

DeviceData ManageButton::getButtonData()
{
    // buttonData.devName = "modeButton";
    buttonData.devData.clear();
    buttonData.devData.push_back(1);
    return buttonData;
}

