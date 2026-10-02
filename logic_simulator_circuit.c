#include<stdio.h>
#include "gates.h"
#include "gates.c"


int main() {
	//user enters two variables 
	int a, b, circuit_a, circuit_b;
	printf("Enter two binary inputs (0 orgit  1): ");
	scanf("%d %d", &a, &b);
// Circuit A
	int atemp1= andGATE(a, b);
	int nota = notGATE(a);
	int notb = notGATE(b);
	int atemp2 = andGATE(nota, notb);
	circuit_a = orGATE(atemp1, atemp2);
// Circuit B
	int btemp1 = andGATE(nota, b);
	int btemp2= andGATE(a, notb);
	circuit_b = orGATE(btemp1, btemp2);

	// Output the results
	printf("Output of circuit a is: %d\n", circuit_a);
	printf("Output of circuit b is: %d\n", circuit_b);
}