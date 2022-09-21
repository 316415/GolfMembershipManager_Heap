#include "MembersEntity.h"

MembersEntity::MembersEntity()
{
    loadMembersData();
}

MembersEntity::~MembersEntity()
{

}

void MembersEntity::loadMembersData()
{
    fpDB = fopen("memberLists.bin", "r");
    if(fpDB == NULL)
    {
        fprintf(stderr, "file open error\n");
        return;
    }
    while(fread(&memberInfo, sizeof(MemberInfo), 1, fpDB))
    {
        vecMembersList.push_back(memberInfo);
    }
    fclose(fpDB);
}

void MembersEntity::addMemberInfo(MemberInfo member)
{
    std::cout << "addmemberinfo : " << member.id << " " << member.name << " "
        << member.address << " " <<
        member.phoneNumber << " " <<
        member.cardNum << " " << std::endl;
    vecMembersList.push_back(member);
}

bool MembersEntity::deleteMemberInfo(int *cardNum)
{
    std::vector<MemberInfo>::iterator itrMember; //일종의 포인터 같은 것
    itrMember = vecMembersList.begin(); //begin : vector의 제일 첫 번째 주소
    //iterator는 주소를 가졌으니 포인터변수와 거의 같다.
    for(itrMember; itrMember != vecMembersList.end(); itrMember++) //vector의 마지막주소와 같지 않을 때까지 for문 실행
    {
        if(memcmp(itrMember->cardNum, cardNum, sizeof(itrMember->cardNum)) == 0) //if(itrMember->cardNum == cardNum)
        {
            vecMembersList.erase(itrMember);
            return true;
        }
    }
    return false;
}

bool MembersEntity::deleteMemberInfo(std::string name)
{
    ;
}

void MembersEntity::make_DB_members_info()
{
    ;
}

void MembersEntity::printMemberInfo(int index)
{

    printf("size : %d\n", (int)vecMembersList.size());
    if (index > (int)vecMembersList.size())
    {
        fprintf(stderr, "out of range member count!\n");
        return;
    }
    printf("%06d, %s, %s, %s, %02x-%02x-%02x-%02x-%02x\n",
           vecMembersList[index].id,
           vecMembersList[index].name,
           vecMembersList[index].address,
           vecMembersList[index].phoneNumber,
           vecMembersList[index].cardNum[0],
           vecMembersList[index].cardNum[1],
           vecMembersList[index].cardNum[2],
           vecMembersList[index].cardNum[3],
           vecMembersList[index].cardNum[4]
           );
}

void MembersEntity::printMemberInfo(std::string name)
{
    for(const auto &member : vecMembersList) //reference member
    {
        if(strcmp(member.name, name.c_str()) == 0)
        {
            printMemberInfo(member.id);
            return;
        }
    }
}

void  MembersEntity::printMemberInfo(int *cardNum)
{
    for(const auto &member : vecMembersList) //reference member
    {
        if(memcmp(member.cardNum, cardNum, sizeof(member.cardNum)) == 0)
        {
            printMemberInfo(member.id);
            return;
        }
    }
}

bool MembersEntity::findMemberInfo(int *cardNum)
{
    for(const auto &member : vecMembersList) //reference member
    {
        if(memcmp(member.cardNum, cardNum, sizeof(member.cardNum)) == 0)
        {
            return true;
        }
    }
    return false;
}

bool MembersEntity::findMemberInfo(std::string name)
{
    for(const auto &member : vecMembersList) //reference member
    {
        if(strcmp(member.name, name.c_str()) == 0)
        {
            return true;
        }
    }
    return false;
}

void MembersEntity::memoryToDB()
{
    fpDB = fopen("memberLists.bin", "w"); //덮어씌우기
    if(fpDB == NULL)
    {
        fprintf(stderr, "file open error\n");
        return;
    }
    for(const auto &member : vecMembersList)
    {
        fwrite(&member, sizeof(member), 1, fpDB);
    }
    fclose(fpDB);
    /*file open
    vecMembersList의 배열을 하나씩 읽고
    vecMembersList 값을 file에 vecMembersList 끝까지 write
    file close*/
}