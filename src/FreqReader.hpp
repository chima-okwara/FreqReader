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
#define DEFAULT_PERIOD 1
#include <Arduino.h>

class FreqReaderDigital
{
public:
  FreqReaderDigital(const uint8_t &inPutSignalPin)
            :SignalPin{inPutSignalPin}
  { }

  inline void begin()
  {
    pinMode(SignalPin, INPUT);      //Declares the input pin
    digitalWrite(SignalPin, HIGH);  //Enables internal pull-up resistor
    set = true;                     //To verify that begin has been called.
  }

  unsigned long getHz(const uint8_t &period);
  unsigned long getKHz(const uint8_t &period) { return (getHz(period)/1000); }
  unsigned long getMhz(const uint8_t &period) { return (getHz(period)/1000000); }

  unsigned long getHz(void) { return(getHz(DEFAULT_PERIOD)); }
  unsigned long getKHz(void) { return (getHz()/1000); }
  unsigned long getMHz(void) { return (getHz()/1000); }

private:
  bool set { };
  uint8_t SignalPin { }, Check {HIGH};
  uint32_t PulseCount { };
};



class FreqReaderAnalogue    //TODO: Reimplement using ADC
{
public:
  FreqReaderAnalogue(const uint8_t &inPutSignalPin)
                      :SignalPin{inPutSignalPin}
  { }

  inline void begin()
  {
    pinMode(SignalPin, INPUT);
    set = true;
  }

  unsigned long getHz(const uint8_t &period);
  unsigned long getKHz(const uint8_t &period) { return (getHz(period)/1000); }
  unsigned long getMhz(const uint8_t &period) { return (getHz(period)/1000000); }

  unsigned long getHz(void) { return (getHz(DEFAULT_PERIOD)); }
  unsigned long getKHz(void) { return (getHz()/1000); }
  unsigned long getMhz(void) { return (getHz()/1000000); }

private:
  bool set { };
  uint8_t SignalPin { };
  uint32_t PulseCount { };

};
#endif
