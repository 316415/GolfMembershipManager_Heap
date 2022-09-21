#include "MembersManageService.h"

MembersManageService::MembersManageService()
{
    membersEntity = new MembersEntity();
    membersManagerState = CARD_READER;
}

MembersManageService::~MembersManageService()
{

}

void MembersManageService::updateStateEvent(std::string devName)
{
    switch (membersManagerState)
    {
    case CARD_READER:
        if(devName == "modeButton")
        {
            membersManagerState = CARD_REGISTER;
            printf("change to CARD_REGISTER state\n");
        }
        break;
    
    case CARD_REGISTER:
        if(devName == "modeButton")
        {
            if(devName == "modeButton")
            {
                membersManagerState = CARD_READER;
                printf("change to CARD_READER state\n");
            }
        }
        break;
    };
}

void MembersManageService::checkCardNumber(int *cardNum)
{
    std::cout << cardNum << " : cardnumber in service" << std::endl;
    switch (membersManagerState)
    {
    case CARD_READER:
        if(membersEntity->findMemberInfo(cardNum))
        {
            printf("Registered Member!\n");
            membersEntity->printMemberInfo(cardNum);
        }
        else
        {
            printf("Not Registered Member!\n");
        }
        break;
    
    case CARD_REGISTER:
        MemberInfo tempMember;
        tempMember.id = 10000;
        strcpy(tempMember.name,  "LeeSunShin");
        strcpy(tempMember.address, "101Dong 123Ho");
        strcpy(tempMember.phoneNumber, "010-1231-1234");
        memcpy(&(tempMember.cardNum), cardNum, sizeof(tempMember.cardNum));
        membersEntity->addMemberInfo(tempMember);
        std::cout << tempMember.id << " " << tempMember.name << " "
        << tempMember.address << " " <<
        tempMember.phoneNumber << " " <<
        tempMember.cardNum << " " << std::endl;
        printf("Member Registered!\n");
        break;
    };
}