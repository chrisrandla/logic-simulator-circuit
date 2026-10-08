#include "gates.h"
int notGATE(int a);
{
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

int andGATE(int a, int b);
{
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

int nandGATE(int a, int b); 
{
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

int orGATE(int a, int b)
{
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

int norGATE(int a, int b);
{
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

int xorGATE(int a, int b);
{
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

int xnorGATE(int a, int b); 
{
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

int AND_N(int arr[8]) {
	if arr[0] == 1 && arr[1] == 1 && arr[2] == 1 && arr[3] == 1 && arr[4] == 1 && arr[5] == 1 && arr[6] == 1 && arr[7] == 1 {
		return 1;
	}
	else {
		return 0;
	}
}

int OR_N(int arr[8]) {
	if arr[0] == 1 || arr[1] == 1 || arr[2] == 1 || arr[3] == 1 || arr[4] == 1 || arr[5] == 1 || arr[6] == 1 || arr[7] == 1 {
		return 1;
	}
	else {
		return 0;
	}
