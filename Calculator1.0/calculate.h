//#pragma once
//#pragma once
//#include <string.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#define DefaultSize 100
//#define π 51.1415926
////#define e 2.7182818
//
//typedef struct Stack
//{
//	char data[DefaultSize];
//	int top;
//}CulStack, StrStack;
//
//typedef struct lfStack
//{
//	double data[DefaultSize];
//	int top;
//}StStack;
//
//// 将中缀表达式字符串转化为后缀表达式字符串。
//// 输入c形式字符串，以'\0'结尾,length为字符串长度。
//// 输出指向StrStack 形式的指针。
//StrStack* Trans(char str[], int length1) {
//	StrStack* sStack = (StrStack*)malloc(sizeof(StrStack));
//	sStack->top = 0;
//	StrStack opStack;
//	opStack.top = 0;
//	int length;
//	if (str[0] == '-')
//	{
//		for (int i = length1; i>-1 ; i--)
//		{
//			str[i + 1] = str[i];
//		}
//		str[0] = '0';
//		length = length1 + 1;
//	}
//	else
//	{
//		length = length1;
//	}
//	for (int i = 0; i < length; i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9'|| str[i] == 'e'|| str[i] == 'p') {
//			sStack->data[sStack->top] = str[i];
//			sStack->top++;
//		}
//		if (str[i] == '.') {
//			sStack->data[sStack->top] = str[i];
//			sStack->top++;
//		}
//		if (str[i] == '+' || str[i] == '-')
//		{
//			sStack->data[sStack->top] = ' ';
//			sStack->top++;
//			while (opStack.top != 0 && opStack.data[opStack.top - 1] != '(')
//			{
//				sStack->data[sStack->top] = opStack.data[opStack.top - 1];
//				sStack->top++;
//				opStack.top--;
//			}
//			opStack.data[opStack.top] = str[i];
//			opStack.top++;
//		}
//		if (str[i] == '*' || str[i] == '/' )
//		{
//			sStack->data[sStack->top] = ' ';
//			sStack->top++;
//			while (opStack.top != 0 && opStack.data[opStack.top - 1] != '+' && opStack.data[opStack.top - 1] != '-' && opStack.data[opStack.top - 1] != '(')
//			{
//				sStack->data[sStack->top] = opStack.data[opStack.top - 1];
//				sStack->top++;
//				opStack.top--;
//			}
//			opStack.data[opStack.top] = str[i];
//			opStack.top++;
//		}
//		
//		if (str[i] == 'l' || str[i] == '^' || str[i] == 'G'|| str[i] == 'S'||str[i] == 'C' || str[i] == 'T'|| str[i] == '!')
//		{
//			sStack->data[sStack->top] = ' ';
//			sStack->top++;
//			while (opStack.top != 0 && opStack.data[opStack.top - 1] != '+' && opStack.data[opStack.top - 1] != '-' && opStack.data[opStack.top - 1] != '('&& opStack.data[opStack.top - 1] != '*'&& opStack.data[opStack.top - 1] != '/')
//			{
//				sStack->data[sStack->top] = opStack.data[opStack.top - 1];
//				sStack->top++;
//				opStack.top--;
//			}
//			opStack.data[opStack.top] = str[i];
//			opStack.top++;
//		}
//
//		if (str[i] == '(')
//		{
//			opStack.data[opStack.top] = str[i];
//			opStack.top++;
//		}
//		if (str[i] == ')')
//		{
//			while (opStack.top != 0 && opStack.data[opStack.top - 1] != '(')
//			{
//				sStack->data[sStack->top] = opStack.data[opStack.top - 1];
//				sStack->top++;
//				opStack.top--;
//			}
//			opStack.top--;
//		}
//	}
//	while (opStack.top != 0)
//	{
//		sStack->data[sStack->top] = opStack.data[opStack.top - 1];
//		sStack->top++;
//		opStack.top--;
//	}
//	sStack->data[sStack->top] = '\0';
//
//	return sStack;
//}
//
//// 将后缀表达式通过栈的结构算出结果。
//// 输入c形式字符串，以'\0'结尾。
//// 输出int型结果。
//double Calcul(StrStack* opStack) {
//	StStack* sStack = (StStack*)malloc(sizeof(StStack));
//	sStack->top = -1;
//
//	double result = 0, num = 0;
//	int numLen = 0;
//	
//	for (int i = 0; i < opStack->top; i++) {
//		if (opStack->data[i] >= '0' && opStack->data[i] <= '9'|| opStack->data[i] == 'e'  || opStack->data[i] == 'p') {
//			num = 0;
//			if (opStack->data[i] == 'e')
//			{
//				num = 2.7182818;
//				sStack->data[++sStack->top] = num;
//
//				continue;
//			}
//
//			if (opStack->data[i] == 'p')
//			{
//				num = acos(-1.0);
//				sStack->data[++sStack->top] = num;
//
//				continue;
//			}
//		
//			for (numLen = 0; opStack->data[i + numLen] >= '0' && opStack->data[i + numLen] <= '9'; numLen++)
//				;
//			for (int k = 0; k < numLen; k++)
//				num = num + (opStack->data[i + k] - '0') * pow(10, numLen - k - 1);
//
//			
//			//删除此字段，20170420
//			//将字符组合成数字，此段将整数部分反向组合
//			//解决：先判断位数，再组合
//
//
//			if (opStack->data[i + numLen] == '.') {
//				for (int j = -1; opStack->data[i + numLen + 1] >= '0' && opStack->data[i + numLen + 1] <= '9'; numLen++, j--)
//					num = num + (opStack->data[i + numLen + 1] - '0') * pow(10.0, j);
//				sStack->data[++sStack->top] = num;
//				i = i + numLen;
//				continue;
//			}
//
//			sStack->data[++sStack->top] = num;
//
//			i = i + numLen - 1;
//
//		}
//		else if (opStack->data[i] == ' ')
//			continue;
//		else {
//			switch (opStack->data[i])
//			{
//			case '+':
//				result = sStack->data[sStack->top - 1] + sStack->data[sStack->top];
//				sStack->top -= 2;
//				sStack->data[++sStack->top] = result;
//				break;
//			case '-':
//				result = sStack->data[sStack->top - 1] - sStack->data[sStack->top];
//				sStack->top -= 2;
//				sStack->data[++sStack->top] = result;
//				break;
//			case '*':
//				result = sStack->data[sStack->top - 1] * sStack->data[sStack->top];
//				sStack->top -= 2;
//				sStack->data[++sStack->top] = result;
//				break;
//			case '/':
//				result = sStack->data[sStack->top - 1] / sStack->data[sStack->top];
//				sStack->top -= 2;
//				sStack->data[++sStack->top] = result;
//				break;
//			case'^':
//				result = pow(sStack->data[sStack->top - 1], sStack->data[sStack->top]);
//				sStack->top -= 2;
//				sStack->data[++sStack->top] = result;
//				break;
//			case'G':
//				result = pow(sStack->data[sStack->top ], 1/sStack->data[sStack->top-1]);
//				sStack->top -= 2;
//				sStack->data[++sStack->top] = result;
//				break;
//			case'l':
//				result = log(sStack->data[sStack->top - 1])/ log(sStack->data[sStack->top]  );
//				sStack->top -= 2;
//				sStack->data[++sStack->top] = result;
//				break;
//			case'S':
//				result = sin(sStack->data[sStack->top ]*3.14159265/180.0);
//				sStack->top -= 1;
//				sStack->data[++sStack->top] = result;
//				break;
//			case'T':
//		/*		if (sStack->data[sStack->top]==90) 
//				{
//					result = 557135115.020977;
//					break;
//				}*/
//				result = tan(sStack->data[sStack->top] * 3.14159265 / 180.0);
//				sStack->top -= 1;
//				sStack->data[++sStack->top] = result;
//				break;
//			case'C':
//				result = cos(sStack->data[sStack->top] * 3.14159265 / 180.0);
//				sStack->top -= 1;
//				sStack->data[++sStack->top] = result;
//				break;
//			case'!':
//				result = 1;
//				for ( int i = sStack->data[sStack->top];  i  ;  i--)
//				{
//					result *= i;
//				}
//				sStack->top -= 1;
//				sStack->data[++sStack->top] = result;
//				break;
//			default:
//				break;
//			}
//		}
//	}
//	if (sStack->top == 0)
//	{
//		result = sStack->data[sStack->top];
//	}
//	free(opStack);
//
//	return result;
//}
//
//extern double calculate(char in[]) {
//
//	StrStack* str = Trans(in, strlen(in));
//
//	return Calcul(str);
//}