/* Project Euler Problem 20
 * Factorial digit sum
 * 2016, Kenneth Jensen <kenneth@jensen.cf>
 * ---
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 
 * 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 * Find the sum of the digits in the number 100!
 */

#include <stdio.h>
#include <gmp.h>

void main(void) {
	int i;
	mpz_t prod, x;
	mpz_init_set_si(prod, 1);

	for (i = 2; i <= 100; ++i) {
		mpz_mul_si(prod, prod, i);
	}
	i = 0;
	mpz_init(x);
	while (mpz_cmp_ui(prod, 0)) {
		i += mpz_mod_ui(x, prod, 10);
		mpz_init_set_ui(x, 10);
		mpz_tdiv_q(prod, prod, x);
	}
	printf("%d\n", i);
}
