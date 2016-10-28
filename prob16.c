/* Project Euler Problem 16
 * Power digit sum
 * 2016, Kenneth Jensen <kenneth@jensen.cf>
 * --
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 2^1000?
 */

#include <stdio.h>
#include <gmp.h>

int main() {
	unsigned int sum;
	mpz_t n, x;

	mpz_init(n);
	mpz_init_set_ui(x, 2);
	mpz_pow_ui(n, x, 1000);

	while (mpz_cmp_ui(n, 0)) {
		sum += (unsigned int) mpz_mod_ui(x, n, 10);
		mpz_init_set_ui(x, 10);
		mpz_tdiv_q(n, n, x);
	}

	printf("%d\n", sum);
	return 0;
}
