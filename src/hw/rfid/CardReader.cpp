#include "CardReader.h"

CardReader::CardReader(SPI* spi)
    : mfrc522(spi)
{

}

CardReader::~CardReader()
{

}

bool CardReader::isCard()
{
    uint8_t byte = mfrc522_request(PICC_REQALL, rfidData);
    if(byte == CARD_FOUND)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

DeviceData CardReader::get_card_number()
{
    mfrc522_get_card_serial(rfidData);
    cardData.devName = "CardReader";
    cardData.devData.clear();
    for(const auto data : rfidData)
    {
        cardData.devData.push_back((int)data);
        // cardData.devData.emplace_back((int)data);
    }
    return cardData;
}
