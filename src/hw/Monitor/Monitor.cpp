#include "Monitor.h"

Monitor::Monitor()
{

}

Monitor::~Monitor()
{

}

void Monitor::print(uint8_t *data, int size)
{
    for(int i = 0;i<size;i++)
    {
        printf("%x ", data[i]);
    }
    printf("\n");
}