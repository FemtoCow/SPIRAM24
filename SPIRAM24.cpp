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


#include <SPI.h>
#include <SPIRAM24.h>


SPIRAM24::SPIRAM24(byte csPin) : _csPin(csPin)
{
  pinMode(csPin, OUTPUT);
  SPI.begin();
  this->disable();
  SPI.setClockDivider(SPI_CLOCK_DIV2);
}

void SPIRAM24::enable()
{
  digitalWrite(this->_csPin, LOW);
}


void SPIRAM24::disable()
{
  digitalWrite(this->_csPin, HIGH);
}

char SPIRAM24::getCS() {
  return this->_csPin;
}

char SPIRAM24::readByte(long address)
{
  char read_byte;
  this->enable();
  SPI.transfer(RAM_READ);
  SPI.transfer((char)(address >> 16));
  SPI.transfer((char)(address >> 8));
  SPI.transfer((char)address);
  read_byte = SPI.transfer(0xFF);
  this->disable();
  return read_byte;
}


char SPIRAM24::writeByte(long address, char data_byte)
{
  this->enable();
  SPI.transfer(RAM_WRITE);
  SPI.transfer((char)(address >> 16));
  SPI.transfer((char)(address >> 8));
  SPI.transfer((char)address);
  SPI.transfer(data_byte);
  this->disable();
  return data_byte;
}

