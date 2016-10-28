/* Project Euler Problem 3
 * Largest prime factor
 * 2016, Kenneth Jensen <kenneth@jensen.cf>
 * ---
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>
#include <math.h>

int isPrime(int n) {
	int mask = n >> 31;
	n = (mask ^ n) - mask;
	if (n < 4) return 1;
	if (!(n & 1)) return 0;

	unsigned short i;
	for (i = 3; i <= sqrt((double)n); i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

void main(void) {
	int i, j;
	for (i = sqrt((double)600851475143); i > 2; --i) {
		if (600851475143 % i == 0 && isPrime(i)) 
			break;
	}
	printf("%d\n", i);
}
