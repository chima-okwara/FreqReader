////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       main.cpp
//*FILE DESC:       Source file for FreqReader library.
//*FILE VERSION:    0.1.1
//*FILE AUTHOR:     Chimaroke Okwara
//*LAST MODIFIED:
//*LICENSE:         Academic Free License
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <FreqReader.hpp>

unsigned long FreqReader::getHz(const uint8_t &period)
{
  PulseCount = 0;
  auto tempo {millis()+(period*1000)};
  while(millis()<tempo)
  {
    if(digitalRead(SignalPin))
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

unsigned long FreqReader::getHzAnalogue(void)
{
  unsigned long frequency { };
  frequency = analogueFreqReader::getHzA();
  return (static_cast<unsigned long>(frequency));
}
