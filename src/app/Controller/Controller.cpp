#include "Controller.h"

Controller::Controller()
{
    monitor = new Monitor();
    membersManageService = new MembersManageService();

}

Controller::~Controller()
{

}

void Controller::updateEvent(DeviceData data)
{
    printf("controller update\n");
    if(data.devName == "CardReader")
    {
        int cardNumber[5];
        for(int i = 0;i<5;i++)
        {
            cardNumber[i] = data.devData[i];
            std::cout << cardNumber[i] << " : cardnumber" << std::endl;
            printf("%d\n", data.devData[i]);
        }
        std::cout << cardNumber << " : cardnumber" << std::endl;
        membersManageService->checkCardNumber(cardNumber);
        // std::cout << data.devName << " : ";
        // for (const auto data : data.devData)
        // {
        //     std::cout << std::hex << data << " ";
        // }
        // std::cout << std::endl;
    }

    if(data.devName == "modeButton")
    {
        membersManageService->updateStateEvent(data.devName);
    }
}