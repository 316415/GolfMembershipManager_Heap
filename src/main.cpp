#include <iostream>
#include <wiringPi.h>
#include "GolfMembershipManager.h"
#include "MembersEntity.h"

int main()
{
    GolfMembershipManager golf_membership_manager;
    golf_membership_manager.run();
/*
    // MemberInfo member = {100000, "HongGilDong", "100Dong-100Ho", "010-1234-1234", {0x33,0x44,0x55,0x55,0x05}};
    MembersEntity membersentity;
    // MemberInfo member;
    // member.id = 10000;
    // strcpy(member.name, "HongGilDong");
    // strcpy(member.address, "100Dong-100Ho");
    // strcpy(member.phoneNumber, "010-1234-1234");
    uint8_t num[5] = {0x33,0x44,0x55,0x55,0x05};
    // memcpy(member.cardNum, num, sizeof(num));
    // membersentity.addMemberInfo(member);
    membersentity.printMemberInfo(10000);
    
    membersentity.printMemberInfo(3000);
    /*membersentity.printMemberInfo("kivqyeuhq");
    if(membersentity.findMemberInfo("dhkjlwf"))
    {
        printf("1found the name\n");
        membersentity.printMemberInfo("dhkjlwf");
    }
    else printf("1not found the name\n");

    if(membersentity.findMemberInfo("kivqyeuhq"))
    {
        printf("2found the name\n");
        membersentity.printMemberInfo("kivqyeuhq");
    }
    else printf("2not found the name\n");

    uint8_t cardNum[5] = {0xa3,0x8c,0xab,0x75,0xba};

    if(membersentity.findMemberInfo(cardNum))
    {
        printf("3found the card number\n");
        membersentity.printMemberInfo(cardNum);
    }
    else printf("3not found the card number\n");

    uint8_t cardNum2[5] = {0x33,0x44,0x55,0x55,0x05};
    if(membersentity.findMemberInfo(cardNum2))
    {
        printf("4found the card number\n");
        membersentity.printMemberInfo(cardNum2);
    }
    else printf("4not found the card number\n");
    
    if(membersentity.findMemberInfo("HongGilDong"))
    {
        printf("5found the name\n");
        membersentity.printMemberInfo("HongGilDong");
    }
    else printf("5not found the name\n");

    // membersentity.deleteMemberInfo(num);

    if(membersentity.findMemberInfo(num))
    {
        printf("6found the card number\n");
        membersentity.printMemberInfo(num);
    }
    else
    {
        printf("6not found the card number\n");
    }

    // membersentity.memoryToDB();


    // mfrc522 rfid(new SPI(10, 3000000));
    // Listener *listener = new Listener(&rfid);
    // while(1)
    // {
    //     listener->checkEvent();
    //     delay(1000);
    //     printf("hihi\n");

    // }
    */
    return 0;
}