#include "mbed.h"

PwmOut PWM1(D6);
int main()
{
   float sample[400];

   for (int i = 0; i < 400; i++){
        if (i < 100)
            sample[i] = (float)i / 100;
        else if (i < 200)
            sample[i] = 1.;
        else if (i < 300)
            sample[i] = 1. - (i - 200.) / 100;
        else
            sample[i] = 0;
   }
   PWM1.period_ms(4);
   int cnt = 0;
   while (1)
   {
      PWM1.pulsewidth_us(4000 * sample[cnt]);
      cnt++;
      if (cnt == 400) cnt = 0;
      ThisThread::sleep_for(10ms);
   }
}