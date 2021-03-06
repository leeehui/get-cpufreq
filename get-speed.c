#include <stdio.h>
#include <stdint.h>
#include <time.h>


int main(void)
{
	struct timespec start;
	struct timespec stop;
	uint64_t loops = 10000000;
	uint64_t elapsed;
	double speed = 0.0;

	clock_gettime(CLOCK_MONOTONIC, &start);
	asm volatile (
			"mov x0, %x[R]\n"
			"1:\n"
			"sub x0, x0, #1\n"
			"cbnz x0, 1b\n"
			:
			:[R]"r"(loops)
			:"x0"
		     );
	clock_gettime(CLOCK_MONOTONIC, &stop);

	elapsed = (stop.tv_sec - start.tv_sec) * 1000000000 + (stop.tv_nsec - start.tv_nsec);

	speed = loops / (double)elapsed;
	
	printf("speed: %f\n", speed);
	return 0;
}
