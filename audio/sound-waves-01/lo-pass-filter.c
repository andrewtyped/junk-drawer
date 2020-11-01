#include <stdio.h>

int main() {
    int prev = 0;
    for (int t = 0;; t++) {
        int output = t*(t+(t>>9|t>>13))%40&120; // this is the 'bytebeat' music sample from earlier in the article.
        //This basically uses the previous signal to approximate the current signal.
        prev = prev * 0.6 + output * 0.4; //as the coefficient to "prev" gets larger, sound becomes more muffled and less high-pitched.
        putchar(prev);
    }
}