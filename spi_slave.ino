#include <SPI.h>
char p [50];
int a=0;
boolean s;

void setup () {
   Serial.begin (9600);
   Serial3.begin (9600);
   pinMode(MISO, OUTPUT); // have to send on master so it is  set as output
   SPCR |= _BV(SPE); // turn on SPI in slave mode
   s = false;
   SPI.attachInterrupt(); // turn on interrupt
}
ISR (SPI_STC_vect) // SPI interrupt routine 
{ 
   int c = SPDR; // read byte from SPI Data Register
   if (a < sizeof p) {
      p [a++] = c; // save data in the next index in the array buff
      if (c == '\r') //check for the end of the word
      s = true;
   }
}

void loop () {
   if (s) {
      s = false; //reset the process
      Serial.println (p); //print the array on serial monitor
      a= 0; //reset button to zero
   }
}
