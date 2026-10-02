//Header files including function prototyeps
#include <stdio.h>
#include "gates.h"
#include "gates.c"

int main() {
	int a, b, result;
	int gatechoice;
	printf"Enter two binary inputs(0 or 1) :";
		scanf("%d %d", &a, &b);
	printf("Select the logic gate to perform: \n 1. NOT \n 2. AND \n 3. NAND\n 4. OR\n 5. NOR\n6. XOR\n7. XNOR \n");
	scanf(" %c", &gatechoice);
	switch(gatechoice); {
	case 'NOT':
		result = notGATE(a);
		printf("The result of the NOT gate is: %d\n", result);
		break;
	case 'AND':
		result = andGATE(a, b);
		printf("The result of the AND gate is: %d\n", result);
		break;
	case 'NAND':
		result = nandGATE(a, b);
		printf("The result of the NAND gate is: %d\n", result);
		break;
	case 'OR':
		result = orGATE(a, b);
		printf("The result of the OR gate is: %d\n", result);
		break;
	case 'NOR':
		result = norGATE(a, b);
		printf("The result of the NOR gate is: %d\n", result);
		break;
	case 'XOR':
		result = xorGATE(a, b);
		printf("The result of the XOR gate is: %d\n", result);
		break;
	case 'XNOR':
		result = xnorGATE(a, b);
		break;
		printf("The result of the XNOR gate is: %d\n", result);
	default:
		printf("Invalid gate choice. Please select a valid gate.\n");
		return 1;
		
	}

}
