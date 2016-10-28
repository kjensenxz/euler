/* Project Euler Problem 4
 * Largest palindrome product
 * 2016, Kenneth Jensen <kenneth@jensen.cf>
 * ---
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>

void main(void) {
	int i, j, n = 0, p = 0;
	for (i = 100; i <= 999; ++i ) {
		for (j = 100; j <= 999; ++j) {
			int r = 0;
			n = j * i;
			while (n > 0) {
				r = (r * 10) + (n % 10);
				n /= 10;
				if (r == n && p < i * j) p = i * j;
			}
		}
	}
	printf("%d\n", p);
}
