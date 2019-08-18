#include<SPI.h>
void setup() {
  Serial.begin(9600);
  digitalWrite(SS, HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop() {
char c;
digitalWrite(SS, LOW);
for(const char *p = "1234"; c=*p; p++) 
{ SPI.transfer(c);
  Serial.print(c);}
digitalWrite(SS,HIGH);
delay(2000);
}
