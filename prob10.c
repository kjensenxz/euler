/* Project Euler Problem 10
 * Summation of primes
 * 2016 Kenneth Jensen <kenneth@jensen.cf>
 * ---
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 * --
 * I'm proud of this one; it finishes in less than 0.5s on a 2.5 GHz 
 * 2nd-generation mobile i5 (with -O3)
 * Here's some benchmarks:
 *
 * $ gcc -O0 -lm prob10.c && time ./a.out
 * real	0m1.112s
 *
 * $ gcc -O3 -lm prob10.c && time ./a.out
 * real	0m0.423s
 *
 */

#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>

int isPrime(uint32_t n) {
	uint32_t mask = n >> 31;
	n = (mask ^ n) - mask;

	if (n < 4) return 1 % n;
	if (!(n & 1)) return 0;

	uint32_t i;

	for (i = 3; i <= sqrtl((long double)n) + 1; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

void main(void) {
	uint32_t i;
	uint64_t sum = 0;

	for (i = 1; i < 2000000; ++i) {
		if (isPrime(i)) 
			sum+= i;
	}
	printf("%"PRIu64"\n",sum);
}
