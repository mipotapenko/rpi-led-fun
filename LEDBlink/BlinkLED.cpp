// Use wiringpi to blink the LED
// Most code taken from blink example on wiringpi website

#include <iostream>
#include <wiringPi.h>
int main (void)
{
  wiringPiSetup() ;
  pinMode(0, OUTPUT) ;
  for (int i = 0; i < 10; i++)
  {
    digitalWrite (0, HIGH) ; delay (500) ;
    digitalWrite (0,  LOW) ; delay (500) ;
    std::cout << i + 1 << "\n";
  }

  return 0;
}