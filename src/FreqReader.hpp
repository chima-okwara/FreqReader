////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       main.cpp
//*FILE DESC:       Header file for FreqReader library.
//*FILE VERSION:    0.4.0
//*FILE AUTHOR:     Chimaroke Okwara
//*LAST MODIFIED:   Saturday, 15 May 2021 09:41
//*LICENSE:         Academic Free License
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef FREQ_READER
#define FREQ_READER

#define DEFAULT_PERIOD 1u


#include <Arduino.h>
#include <stdint.h>
#include <pincontrol.hpp>


class FreqReader: protected pin
{
public:
  FreqReader(const uint8_t &inPutSignalPin) :pin::pin{inPutSignalPin, INPUT}
  {

  }

  FreqReader() = default;

  ~FreqReader()
  {
    delete PulseCount;
  }


  inline void init(void)                    //Sets pin as input pin.
  {
    pin::set();
    pin::write(LOW);
    noInterrupts();
  }

  uint_fast32_t checkPulse(void)                  //Returns 1 if input pin is set to high
  {
    return((*portInputRegister(port) & bit) ? (1) : (0));
  }

  uint32_t getHz(const uint32_t &period);
  uint32_t getKHz(const uint32_t &period) { return (getHz(period)/1000); }
  uint32_t getMhz(const uint32_t &period) { return (getHz(period)/1000000); }

  uint32_t getHz(void) { return(getHz(DEFAULT_PERIOD)); }
  uint32_t getKHz(void) { return (getHz()/1000); }
  uint32_t getMHz(void) { return (getHz()/1000); }

private:
  unsigned long tempo;                    //How long for to take reading.
  uint32_t *PulseCount = new uint32_t;    //Input pulse counter.
//  uint32_t *Check = new uint32_t{ };
};
#endif
