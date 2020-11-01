#include <stdio.h>
#include <stdlib.h>

int main() {
    float f; //note frequency
    char c; // "cdefgab" for notes or "pr" (1) for pause
    int d; //duration
    int o; //octave

    while(scanf("%d%c%d ", &d, &c, &o) > 0) {
        c &= 31; //convert note to lower case
        f = !(c >> 4) * 55; // c >> 4 is 0 for CDEFGAB and 1 for PR. So, for pauses f is 0, for notes, 55.
        c = (c * 8 / 5 + 8) % 12 + o * 12 - 22; //a trick used in Nokia Composer post to convert note letter to index. Note the use of modulus to ensure note is 0-11. Then we add the octave's start index. 

        //Note 'x' frequency is 2^(x/12), or (2^(1/12))^x
        while(c--) {
            f *= 1.0595; //1.0595 is 2^(1/12)
        }

        //Play sawtooth wave for the given duration with given pitch.
        for(d = 16e3 / d; d--; putchar(d * f * 0.032));
    }
}