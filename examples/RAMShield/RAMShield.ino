/* 

  Writes random bytes to a random positions in the RAM
  Reads the data back and compares them with expected data

*/


#include <SPI.h>
#include <SPIRAM24.h>

#define BANK0_PIN 10
#define BANK1_PIN 9
#define BANK2_PIN 8
#define BANK3_PIN 7

#define i2addr(i) (i*i*63 + i*15)
#define i2data(i) (i*i*31 + i*7)
#define RAM_SIZE 100


SPIRAM24 ram(BANK0_PIN);

void setup() {
  Serial.begin(9600); 
  delay(100);
  Serial.println("");  
  Serial.println("SPI RAM Test");  

  //write data to RAM
  for (long i = 0; i < RAM_SIZE; i++) {
    long addr = i2addr(i);
    byte data = i2data(i);
    ram.writeByte(addr, data);
  }
  //read and test if data is correct
  for (long i = 0; i < RAM_SIZE; i++) {
    long addr = i2addr(i);
    byte data = i2data(i);
    byte ramData = ram.readByte(addr);
    if (data == ramData) {
      Serial.println("OK");
    } else {
      Serial.println("Fail"); 
    }
  }

 
}


void loop() {
  
}

