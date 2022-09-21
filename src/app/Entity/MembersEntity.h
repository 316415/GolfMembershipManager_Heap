#ifndef MEMBERSENTITY_H
#define MEMBERSENTITY_H

#pragma once
#include <vector>
#include <iostream>
#include <string.h> //#include <cstring>과 똑같음
#include "MemberInfo.h"

class MembersEntity
{
public:
    MembersEntity();
    virtual ~MembersEntity();
    void loadMembersData();
    void addMemberInfo(MemberInfo member);
    bool deleteMemberInfo(int *cardNum);
    bool deleteMemberInfo(std::string name);
    void make_DB_members_info();
    void printMemberInfo(int index);
    void printMemberInfo(std::string name);
    void printMemberInfo(int *cardNum);
    bool findMemberInfo(int *cardNum);
    bool findMemberInfo(std::string name);
    void memoryToDB();

private:
    std::vector<MemberInfo> vecMembersList;
    MemberInfo memberInfo;
    FILE *fpDB;
};

#endif