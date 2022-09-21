#ifndef CARDREADER_H
#define CARDREADER_H

#pragma once
#include <iostream>
#include "mfrc522.h"
#include "DeviceData.h"

class CardReader : public mfrc522
{
public:
    CardReader(SPI* spi);
    ~CardReader();
    bool isCard();
    DeviceData get_card_number();

private:
    uint8_t rfidData[16];
    DeviceData cardData;
};

#endif