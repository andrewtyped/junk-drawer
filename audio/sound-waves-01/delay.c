#define N 800 //Produce a 0.1s delay (800 / 8000Hz sampling rate)
int main() {
    int delay[N] = {0};
    for(int t=0;; t++) {
        int output = ((t*(42&t>>10))&0xff)/2; //More bytebeat
        delay[t%N] = output; //put current sample into delay line;
        putchar(output + delay[(t+1)%N]); //mix current sample with the oldest sample from the delay line.
    }
}