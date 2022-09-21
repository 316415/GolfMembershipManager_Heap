#ifndef GOLFMEMBERSHIPMANAGER_H
#define GOLFMEMBERSHIPMANAGER_H

#pragma once
#include "Listener.h"
#include <wiringPi.h>

class GolfMembershipManager
{
public:
    GolfMembershipManager();
    ~GolfMembershipManager();
    void run();

private:
    Listener *listener;
    
};

#endif