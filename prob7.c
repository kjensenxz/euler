/* Project Euler Problem 7
 * 10001st prime
 * 2016, Kenneth Jensen <kenneth@jensen.cf>
 * ---
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 * What is the 10 001st prime number?
 */

#include <stdio.h>
#include <math.h>

int isPrime(int n) {
	unsigned int mask = n >> 31;
	n = (mask ^ n) - mask;
	if (n < 4) return 1;
	if (!(n & 1)) return 0;

	unsigned int i;
	for (i = 3; i <= sqrtl((long double)n) + 1; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

void main(void) {
	int i, j;
	for (i = 2, j = 1; j <= 10001; ++i) {
		if(isPrime(i)) ++j;
	}
	printf("%d\n", --i);
}
