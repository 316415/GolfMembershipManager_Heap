#ifndef LISTENER_H
#define LISTENER_H

#pragma once
#include "CardReader.h"
#include "Controller.h"
#include "ManageButton.h"
#include <string.h>

class Listener
{
public:
    Listener();
    ~Listener();
    void checkEvent();
    bool checkRfid();

private:
    CardReader *rfid;
    Controller *controller;
    ManageButton *modeButton;
    uint8_t rfidData[16];
};

#endif