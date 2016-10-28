/* Project Euler Problem 5
 * Smallest multiple
 * 2016, Kenneth Jensen <kenneth@jensen.cf>
 * ---
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 */

#include <stdio.h>
#include <limits.h>

void main(void) {
	int i, j;
	/* this could be done a lot better with prime factorization, though it
	 * is something difficult both to compute and implement
	 * simply finding the unique prime factors from 1 to 20 would be enough;
	 * by hand this is 1 * 2^4 * 3^2 * 5 * 7 * 11 * 13 * 17 * 19, which
	 * yields the same result as this program (232792560)
	 */
	for (i = 2520; i < INT_MAX; ++i) {
		for (j = 1; j < 21; ++j) {
			if (i % j != 0) break;
			if (j == 20) {
				printf("%d\n", i);
				return;
			}
		}
	}
}
