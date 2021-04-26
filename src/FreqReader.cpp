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

unsigned long FreqReaderDigital::getHz(const uint8_t &period) //TODO: Reimplement using timer/counter
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


unsigned long FreqReaderAnalogue::getHz(const uint8_t &period)
{
  PulseCount = 0;
  int pulseHigh = pulseIn(SignalPin, HIGH, period*1000000L);
  int pulseLow = pulseIn(SignalPin, LOW, period*1000000L);
  return (2000000L/(pulseHigh+pulseLow));
}
