/*************************************************************************
Implementation File : aliquotcycles.c
Author - Date       : Efstathios Siatras - 08/11/2016
Purpose             : Finds aliquot cycles
**************************************************************************/
#include <stdio.h>

#define MAXCYC 28													    /* Max length of a cycle */
#define MAXNUM 10000000													    /* Max number in a cycle */

long s(long n) {      /* Function to calculate the aliquot sum of n ; The aliquot sum of a positive integer n is the sum of all proper divisors of n */

	long divisor, result, ndiv;
	result = 1;										 	      /* Every number is always divided by 1 */

	for (divisor = 2 ; divisor*divisor <= n ; divisor++) {	/* Optimization on loops ; 'divisor * divisor <= n' is equal to 'divisor <= sqrt(n)' */
		if (n % divisor == 0) {									  /* Check if current divisor is factor of n */
			result += divisor; 										 /* Add up factor to the sum */

			ndiv = n / divisor;

			if (divisor != ndiv) {									  /* Do not add up same number twice */
				result += ndiv; 								       /* Find divisors over sqrt(n) */
			}
		}
	}

	return result; 												 /* Return the sum of proper factors */
}

int main(void) {
	long n, result, numprint;
	int cyc, i, counter = 0, perfect = 0, amicable = 0;

	for (n = 2 ; n <= MAXNUM ; n++) {
		cyc = 1;
		result = s(n);													 /* Cache the result */
		numprint = result; 								  	     /* Save the result to be used in printf */

		while ((result > n)) { 			  /* Every number calculated must be greater than the specific n ; Avoid finding same cycles */
			if (result > MAXNUM) { 					     /* Every number calculated must be less than or equal to MAXNUM */
				break;
			}
			else if (result <=  1) {		        /* Every number used in s() function must be greater than 1 ; Domain of s(n) */
				break;
			}
			else if (cyc > MAXCYC) {				      /* Every cycle should have length less than or equal to MAXCYC */
				break;
			}
			result = s(result); 										    /* Calculate next number */
			cyc++; 												  /* Counter of cycle length */
		}

		if (result == n) { 										      /* Check if cycle is completed */
			switch(cyc) {
				case 1: 							  /* Perfect numbers have length of cycle equal to 1 */
					perfect++; 							   /* Counter of cycles with perfect numbers */
					break;
				case 2: 							 /* Amicable numbers have length of cycle equal to 2 */
					amicable++; 							  /* Counter of cycles with amicable numbers */
					break;
			}

			counter++; 								  			    /* Counter of all cycles */

			printf("Cycle of length %d: %ld ", cyc, n);				  /* Print cycle of length and first number of cycle */

			for (i=0 ; i<cyc ; i++) {   							    /* Loop to print numbers of found cycles */
				printf("%ld ", numprint); 						  			     /* Print number */
				numprint = s(numprint);							  /* Calculate the next number in each cycle */
			}

			printf("\n"); 									  	     /* Change line after each cycle */

		}
	}

	printf("\nFound %d cycles including\n%d cycles with perfect numbers and\n%d cycles with amicable numbers\n", counter, perfect, amicable);
									 		 /* Final print after all cycles are printed ; Show counters */
	getchar();

	return 0;
}
