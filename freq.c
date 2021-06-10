#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define WARMUP 100
#define TRIES  1000
#define ITERS  10000

#define CAL_FN add_calibration_x86
extern void add_calibration_x86(uint64_t i);

uint64_t get_nano(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec * 1000000000 + ts.tv_nsec; 
    
}

double get_freq(void)
{
    uint64_t res[TRIES];
    for (int w = 0; w < WARMUP + 1; w++)
    {
        for (int r = 0; r < TRIES; r++)
        {
            uint64_t t0 = get_nano();
            CAL_FN(ITERS);
            uint64_t t1 = get_nano();
            CAL_FN(ITERS * 2);
            uint64_t t2 = get_nano();
            res[r] = (t2 - t1) - (t1 - t0);
        }
    }
    
    uint64_t sum = 0;
    for (int i = 0; i < TRIES; i++)
    {
       sum += res[i];
    }
    
    double ghz = (double)ITERS / (sum / TRIES);
    return ghz;
}

int main(void)
{
    printf("begin.\n");
    
    printf("freq: %f\n", get_freq());
    
    return 0;
}
