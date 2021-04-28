////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       main.cpp
//*FILE DESC:       Header file for FreqReader library.
//*FILE VERSION:    0.3.1
//*FILE AUTHOR:     Chimaroke Okwara
//*LAST MODIFIED:   Wednesday, 28 April 2021 12:46
//*LICENSE:         Academic Free License
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef FREQ_READER
#define FREQ_READER

#define DEFAULT_PERIOD 1u


#include <Arduino.h>
#include <stdint.h>

struct pinInfo
{
  uint8_t  Bit { }, Port{ }, Timer { };
  volatile uint8_t *Reg { }, *Out { };
};


class FreqReader
{
public:
  FreqReader(const uint8_t &inPutSignalPin) :_signalPin{inPutSignalPin}
  {

  }

  FreqReader() = default;

  inline void init()   //Sets pin as input pin.
  {
    _inputPin.Bit = digitalPinToBitMask(_signalPin);
    _inputPin.Port = digitalPinToPort(_signalPin);
    if (_inputPin.Port == NOT_A_PIN) return;

    _inputPin.Reg = portModeRegister(_inputPin.Port);
    _inputPin.Out = portOutputRegister(_inputPin.Port);

    uint8_t oldSREG = SREG;
    cli();
    *(_inputPin.Reg) &= ~(_inputPin.Bit);
    *(_inputPin.Out) &= ~(_inputPin.Bit);
    SREG = oldSREG;
    _init = 1;
  }

  unsigned long getHz(const uint8_t &period);
  unsigned long getKHz(const uint8_t &period) { return (getHz(period)/1000); }
  unsigned long getMhz(const uint8_t &period) { return (getHz(period)/1000000); }

  unsigned long getHz(void) { return(getHz(DEFAULT_PERIOD)); }
  unsigned long getKHz(void) { return (getHz()/1000); }
  unsigned long getMHz(void) { return (getHz()/1000); }

private:
  pinInfo _inputPin;
  uint8_t _signalPin { };
  bool _init { 0 };
};


#endif
