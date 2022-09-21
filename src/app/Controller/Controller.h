#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once
#include "DeviceData.h"
#include "Monitor.h"
#include "MembersManageService.h"

class Controller
{
public:
    Controller();
    virtual ~Controller();
    void updateEvent(DeviceData data);

private:
    Monitor *monitor;
    MembersManageService *membersManageService;
};

#endif