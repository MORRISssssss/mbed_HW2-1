#include "mbed.h"

PwmOut PWM1(D6);
AnalogOut aout(PA_4);

int main()
{
   float sample[100];

   for (int i = 0; i < 100; i++){
        if (i < 25)
            sample[i] = (float)i / 25;
        else if (i < 50)
            sample[i] = 1.;
        else if (i < 75)
            sample[i] = 1. - (i - 50.) / 25;
        else
            sample[i] = 0;
   }
   PWM1.period_ms(5);
   int cnt = 0;
   while (1)
   {
      PWM1.pulsewidth_us(5000 * sample[cnt]);
      aout = PWM1;
      cnt++;
      if (cnt == 100) cnt = 0;
      ThisThread::sleep_for(10ms);
   }
}