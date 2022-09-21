#ifndef MEMBERSMANAGESERVICE_H
#define MEMBERSMANAGESERVICE_H

#pragma once
#include <string>
#include "MembersEntity.h"
#include "MemberInfo.h"

enum {CARD_READER, CARD_REGISTER};

class MembersManageService
{
public:
    MembersManageService();
    virtual ~MembersManageService();
    void updateStateEvent(std::string devName);
    void checkCardNumber(int *cardNum);

private:
    int membersManagerState;
    MembersEntity *membersEntity;
};

#endif