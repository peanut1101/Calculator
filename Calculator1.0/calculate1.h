#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define DefaultSize 100
typedef struct Stack
{
	char data[DefaultSize];
	int cursor;
}CulStack, StrStack;

typedef struct lfStack
{
	double data[DefaultSize];
	int cursor;
}StStack;
StrStack* Trans(char str[], int length1);
double Calcul(StrStack* opStack);
extern double calculate(char in[]);
