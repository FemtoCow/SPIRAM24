/*

Copyright (C) 2015 Michal Canecky
All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/


#ifndef SPIRAM24_h
#define SPIRAM24_h

#include <Arduino.h>
#include <SPI.h>

// SRAM opcodes
#define RAM_READ  3
#define RAM_WRITE 2

#define RAM_RDMR  5
#define RAM_WRMR  1


class SPIRAM24
{
  public:
    SPIRAM24(byte csPin);
    void enable();
    void disable();
    char readByte(long address);
    char writeByte(long address, char data_byte);
    char getCS();
  private:
    byte _csPin;
    void setMode(char mode); 
};


#endif 