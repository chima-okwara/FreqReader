////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       main.cpp
//*FILE DESC:       Header file for FreqReader library.
//*FILE VERSION:    0.1.1
//*FILE AUTHOR:     Chimaroke Okwara
//*LAST MODIFIED:
//*LICENSE:         Academic Free License
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef FREQ_READER
#define FREQ_READER

#include <Arduino.h>
#include "analogueFreqReader.hpp"


class FreqReaderDigital
{
public:
  FreqReaderDigital(const uint8_t &inPutSignalPin)
            :SignalPin{inPutSignalPin}
  { }

  inline void begin()
  {
    pinMode(SignalPin, INPUT);
    digitalWrite(SignalPin, HIGH);
    set = true;
  }

  unsigned long getHz(void) { return(getHz(1)); }
  unsigned long getHz(const uint8_t &period);
  unsigned long getKHz(const uint8_t &period) { return (getHz(period)/1000); }
  unsigned long getMhz(const uint8_t &period) { return (getHz(period)/1000000); }

private:
  bool set { };
  uint8_t SignalPin { }, Check {HIGH};
  uint32_t PulseCount { };
};

class FreqReaderAnalogue : public analogueFreqReader
{
public:
  FreqReaderAnalogue(uint8_t &inputSignalPin, uint32_t &sampleRate)
            :SignalPin{&inputSignalPin}, SampleRate{&sampleRate}
  {
    setBandwidth(50, 5000);
  }

  FreqReaderAnalogue(const uint8_t &inPutSignalPin)
  {
    *SignalPin = inPutSignalPin;
    *SampleRate = 45000ul;
    setBandwidth(50, 5000);
  }

  void begin()
  {
    analogueFreqReader::begin(*SignalPin, *SampleRate);
    set = true;
  }

  unsigned long getHz(void);
  unsigned long getKHz(void) { return (getHz()/1000); }
  unsigned long getMhz(void) { return (getHz()/1000000); }

private:
  bool set { };
  uint8_t *SignalPin {&samplePin}, Check {HIGH};
  uint32_t PulseCount { };
  uint32_t *SampleRate {&sampleRate};

};
#endif
