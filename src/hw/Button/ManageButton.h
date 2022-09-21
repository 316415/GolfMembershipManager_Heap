#ifndef MANAGEBUTTON_H
#define MANAGEBUTTON_H

#pragma once
#include <string>
#include "Button.h"
#include "DeviceData.h"

class ManageButton : public Button
{
public:
    ManageButton(int pin, std::string name);
    virtual ~ManageButton();
    bool checkButton();
    DeviceData getButtonData();

private:
    DeviceData buttonData;
};

#endif