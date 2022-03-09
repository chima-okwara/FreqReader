////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       main.cpp
//*FILE DESC:       Source file for FreqReader library.
//*FILE VERSION:    0.4.0
//*FILE AUTHOR:     Chimaroke Okwara
//*LAST MODIFIED:   Saturday, 15 May 2021 09:41
//*LICENSE:         Academic Free License
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <FreqReader.hpp>

uint32_t FreqReader::getHz(const uint32_t &period) //TODO: Reimplement using timer/counter
{
  tempo = millis()+(period*1000);
  while(millis() <= tempo)
  {
    *PulseCount += checkPulse();
  }

  return ((*PulseCount)/(period));
}

ISR(TIMER1_OVF_vect)
{
}
