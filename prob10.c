/* Project Euler Problem 10
 * Summation of primes
 * 2016, Kenneth Jensen <kenneth@jensen.cf>
 * ---
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
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
