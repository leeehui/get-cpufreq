#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>

static inline uint64_t get_cycles(void)
{
    uint32_t lo, hi;
    asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

static inline uint64_t get_cycles_a(void)
{
    uint64_t t;
    asm volatile("rdtsc" : "=A"(t));
    return t;
}

int main(void)
{
    struct timespec ts_start, ts_end;
    uint64_t cycle_start, cycle_end;
    uint64_t cycle_start_a, cycle_end_a;
    
    clock_gettime(CLOCK_REALTIME, &ts_start);
    cycle_start = get_cycles();
    cycle_start_a = get_cycles_a();
    
    //do something
    //double a = 1;
    //for (int i = 0; i < INT_MAX; i++)
    //{
    //   a += 1.0; 
    //}
    //printf("a: %f\n", a);
    sleep(1);
    
    clock_gettime(CLOCK_REALTIME, &ts_end);
    cycle_end = get_cycles();
    cycle_end_a = get_cycles_a();
    
    int64_t sec = ts_end.tv_sec - ts_start.tv_sec;
    int64_t nsec = ts_end.tv_nsec - ts_start.tv_nsec;
    
    double cycles= (double)(cycle_end - cycle_start); 
    double cycles_a= (double)(cycle_end_a - cycle_start_a); 
    double secs = (double)(sec + (double)(nsec) / 1000000000.0);
    printf("cycle_start : %ld\n", cycle_start);
    printf("cycle_end : %ld\n", cycle_end);
    
    printf("secs : %f\n", secs);
    printf("cycles : %f\n", cycles);
    printf("cycles_a : %f\n", cycles_a);
    printf("frequency : %f\n", cycles/secs);
    
    return 0;
}
