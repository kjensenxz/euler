/* Project Euler Problem 14
 * Longest Collatz sequence
 * 2016, Kenneth Jensen <kenneth@jensen.cf>
 * ---
 * The following iterative sequence is defined for the set of positive 
 * integers:
 * n -> n/2 (n is even)
 * n -> 3n + 1 (n is odd)
 * Using the rule above and starting with 13, we generate the following 
 * sequence:
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 * It can be seen that this sequence (starting at 13 and finishing at 1) 
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it
 * is thought that all starting numbers finish at 1.
 * Which starting number, under one million, produces the longest chain?
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 * --
 * Note that compiling this with anything higher than -O0 results in greater
 * error as optimization levels increase.
 */

#include <stdio.h>

void main(void) {
	unsigned int i;
	unsigned long int current, highest;
	unsigned short steps, moststeps;

	for (i = 1; i < 1000000; ++i) {
		current = i;
		steps = 0;
		while (current > 1 && ++steps) {
			current = (current & 1) ? 3 * current + 1 : current / 2;
		}
		if (steps > moststeps) {
			highest = i;
			moststeps = steps;
		}
	}
	printf("%d: %d\n", highest, moststeps);
}
