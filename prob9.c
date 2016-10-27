/* Project Euler Problem 9
 * Special Pythagorean triplet
 * 2016 Kenneth Jensen <kenneth@jensen.cf>
 * ---
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for 
 * which,
 * a^2 + b^2 = c^2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product a*b*c.
 */

#include <stdio.h>
#include <math.h>

void main(void) {
	int a, b, c;
	for (a = 1; a < 500; ++a) {
		for (b = 1; b < 500; ++b) {
			double temp = sqrt(a*a+b*b);
			c = (int)temp;
			if (c != temp) continue;
			else if (a + b + c == 1000)
				goto out; // goto considered useful
		}
	}
out:
	printf("%d * %d * %d = %d\n", a, b, c, a*b*c);
}
