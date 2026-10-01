//Header files including function prototyeps
#include <stdio.h>
#include <gates.h>

int main() {

}
// Functions of logic gates 
int notGATE(int a, int b); {
	int x; 
	if (a == 1) {
		x = 0;
	}
	else if (a == 0) {
		x = 1;
	}
	else {
		printf("Invalid input for NOT gate. Please enter 0 or 1.\n");
	}
	return x; 
	}

int andGATE(int a, int b); {
	int x; 
	if (a == 1 && b == 1) {
		x = 1;
	}
	else if (a == 0 || b == 0) {
		x = 0;
	}
	else {
		printf("Invalid input for AND gate. Please enter 0 or 1.\n");
	}
	return x;
	}

int nandGATE(int a, int b);{
int x; 
if (a == 1 && b == 1) {
	x = 0;
}
else if (a == 0 || b == 0) {
	x = 1;
}
else {
	printf("Invalid input for NAND gate. Please enter 0 or 1.\n");
}
return x;
}

int orGATE(int a, int b); {
	int x;
	if (a == 0 && b == 0) {
		x = 0;
	}
	else if (a == 1 || b == 1) {
		x = 1;
	}
	else {
		printf("Invalid input for OR gate. Please enter 0 or 1.\n");
	}
	return x;
}

int norGATE(int a, int b); {
	int x;
	if (a == 0 && b == 0) {
		x = 1;
	}
	else if (a == 1 || b == 1) {
		x = 0;
	}
	else {
		printf("Invalid input for NOR gate. Please enter 0 or 1.\n");
	}
	return x;
}

	int xorGATE(int a, int b); {
		int x;
		if (a == 1 && b == 0) {
			x = 1;
		}
		else if (a == 0 && b == 1) {
			x = 1;
		}
		else if (a == 0 && b == 0) {
			x = 0;
		}
		else if (a == 1 && b == 1) {
			x = 0;
		}
		else {
			printf("Invalid input for XOR gate. Please enter 0 or 1.\n");
		}
		return x;
	}

int xnorGATE(int a, int b);{
	int x;
	if (a == 1 && b == 1) {
		x = 1;
	}
	else if (a == 0 && b == 0) {
		x = 1;
	}
	else if (a == 1 && b == 0) {
		x = 0;
	}
	else if (a == 0 && b == 1) {
		x = 0;
	}
	else {
		printf("Invalid input for XNOR gate. Please enter 0 or 1.\n");
	}
	return x;
}
