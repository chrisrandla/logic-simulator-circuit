#include "gates.h"
#include"gates.c"
#include <stdlib.h>
#include <stdio.h>

int main() {
	int a[8], b[8], circuit_a, circuit_b, choice;
printf("Enter 1 for manual input or 2 for random input: ");
scanf("%d", &choice);
if choice == 2 {
	for (int i = 0; i < 8; i++) {
		a[i] = randbetween(0, 1);
		b[i] = randbetween(0, 1);
	}
}
else if choice == 1 {

	for (int i = 0; i < 8; i++) {
		printf("Enter the value of a[%d] (0 or 1): ", i);
		scanf("%d", &a[i]);
		if (a[i] != 0 && a[i] != 1) {
			printf("Invalid input. Please enter 0 or 1.\n");
			i--;
		}
	}
	for (int i = 0; i < 8; i++) {
		printf("Enter the value of b[%d] (0 or 1): ", i);
		scanf("%d", &b[i]);
		if (a[i] != 0 && a[i] != 1) {
			printf("Invalid input. Please enter 0 or 1.\n");
			i--;
		}
	}
}
else {
	printf("Invalid choice. Please enter 1 or 2.\n");
	return 1;
}
// calculate circuits 
circuit_a = notGate(xorGATE(AND_N(a), OR_N(b)));
circuit_b= orGate(AND_N(a), OR_N(b)), andGATE(OR_N(a), AND_N(b)));

		printf("The output of circuit 1 is: %d\n", circuit_a);
		printf("The output of circuit 2 is: %d\n", circuit_b);

}