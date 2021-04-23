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
#include <analogueFreqReader.hpp>


class FreqReader : public analogueFreqReader
{
public:
  FreqReader(const uint8_t &inPutSignalPin)
            :SignalPin{inPutSignalPin}
  { }
  FreqReader(const uint8_t &inputSignalPin, const uint32_t sampleRate)
            :SignalPin{inputSignalPin}, SampleRate{sampleRate}
  { }
  inline void begin()
  {
    pinMode(SignalPin, INPUT);
    digitalWrite(SignalPin, HIGH);
    set = true;
  }

  void beginAnalogue()
  {
    analogueFreqReader::begin(SignalPin, SampleRate);
  }

  unsigned long getHz(const uint8_t &period);
  unsigned long getKHz(const uint8_t &period) { return (getHz(period)/1000); }
  unsigned long getMhz(const uint8_t &period) { return (getHz(period)/1000000); }

  unsigned long getHzAnalogue();
  unsigned long getKHzAnalogue(void) { return (getHzAnalogue()/1000); }
  unsigned long getMHzAnalogue(void) { return (getHzAnalogue()/1000000); }


private:
  bool set { };
  uint8_t SignalPin { }, Check {HIGH};
  uint32_t PulseCount { }, SampleRate { };
};
#endif
