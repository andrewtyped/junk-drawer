#include <stdio.h>
#include <stdlib.h>

int main() {
    //Sawtooth wave at 440hz (A concert)
    for(int t = 0, osc = 0; t < 8000; t++, osc = osc + 14) {
        putchar(osc);
    }

    //Silence
    for(int t = 0, osc = 0; t < 4000; t++, osc = osc + 14) {
        putchar(0);
    }

    //Square wave at 440hz (A concert)
    for(int t = 0, osc = 0; t < 8000; t++, osc = osc + 14) {
        putchar(osc & 0x80);
    }

    //Silence
    for(int t = 0, osc = 0; t < 4000; t++, osc = osc + 14) {
        putchar(0);
    }

    //Sine wave at 440hz (A concert)
    for(int t = 0, osc = 0; t < 8000; t++, osc = osc + 14) {
        putchar(127 * sin(osc / 255.0*2*3.14) + 128);
    }

    //Silence
    for(int t = 0, osc = 0; t < 4000; t++, osc = osc + 14) {
        putchar(0);
    }

    //Simulate strings
    unsigned char a[256];
    for(int i = 0; i < sizeof(a); i++) {
        a[i] = rand();
    }

    for(int t = 0; t < 16000; t++) {
        int i = t % sizeof(a);
        int j = (t + 1) % sizeof(a);
        putchar(a[i] = (a[i] + a[j])/2);
    }
}