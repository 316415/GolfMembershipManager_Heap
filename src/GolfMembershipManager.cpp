#include "GolfMembershipManager.h"

GolfMembershipManager::GolfMembershipManager()
    : listener(new Listener())
    //mfrc522 *rfid = new mfrc522(new SPI(10,3000000))
{
}

GolfMembershipManager::~GolfMembershipManager()
{

}

void GolfMembershipManager::run()
{
    while(1)
    {
        listener->checkEvent();
        delay(10);
    }
}