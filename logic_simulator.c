//Header files including function prototyeps
#include <stdio.h>
#include "gates.h"
#include "gates.c"

int main() {
	int a, b, result;
	char gatechoice;
	printf"Enter two binary inputs(0 or 1) :";
		scanf("%d %d", &a, &b);
	printf("Select the logic gate to perform: NOT, AND, NAND, OR, NOR, XOR, XNOR \n");
	scanf(" %c", &gatechoice);
	switch(gatechoice); {
	case 'NOT':
		result = notGATE(a);
		printf("The result of the %c gate is: %d\n", gatechoice, result);
		break;
	case 'AND':
		result = andGATE(a, b);
		printf("The result of the %c gate is: %d\n", gatechoice, result);
		break;
	case 'NAND':
		result = nandGATE(a, b);
		printf("The result of the %c gate is: %d\n", gatechoice, result);
		break;
	case 'OR':
		result = orGATE(a, b);
		printf("The result of the %c gate is: %d\n", gatechoice, result);
		break;
	case 'NOR':
		result = norGATE(a, b);
		printf("The result of the %c gate is: %d\n", gatechoice, result);
		break;
	case 'XOR':
		result = xorGATE(a, b);
		printf("The result of the %c gate is: %d\n", gatechoice, result);
		break;
	case 'XNOR':
		result = xnorGATE(a, b);
		break;
		printf("The result of the %c gate is: %d\n", gatechoice, result);
	default:
		printf("Invalid gate choice. Please select a valid gate.\n");
		return 1;
		
	}

}
// Functions of logic gates 
