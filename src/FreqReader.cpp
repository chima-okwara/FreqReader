////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       main.cpp
//*FILE DESC:       Source file for FreqReader library.
//*FILE VERSION:    0.3.1
//*FILE AUTHOR:     Chimaroke Okwara
//*LAST MODIFIED:   Wednesday, 28 April 2021 12:46
//*LICENSE:         Academic Free License
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <FreqReader.hpp>



unsigned long FreqReader::getHz(const uint8_t &period) //TODO: Reimplement using timer/counter
{
  if (!_init)
    this->init();
  uint8_t Check = HIGH;
  uint8_t PulseCount = 0;
  auto tempo {millis()+(period*1000)};
  while(millis()<tempo)
  {
    if(*portInputRegister(_inputPin.Port) & _inputPin.Bit)
    {
      if(Check == HIGH)
        ++PulseCount;
      Check = LOW;
    }
    else
      Check = HIGH;
  }

  return (PulseCount/period);
}
