/* Project Euler Problem 6
 * Largest palindrome product
 * 2016 Kenneth Jensen <kenneth@jensen.cf>
 * ---
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */

#include <stdio.h>

void main(void) {
	int sum1, sum2, i;
	for (i = 1; i <= 100; ++i) {
		sum1 += i * i;
		sum2 += i;
	}
	sum2 *= sum2;
	printf("%d - %d = %d\n", sum2, sum1, sum2-sum1);
}
