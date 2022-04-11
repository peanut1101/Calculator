#include "pch.h"
#include "calculate1.h"
StrStack* Trans(char str[], int length1) {
	StrStack* sStack = (StrStack*)malloc(sizeof(StrStack));
	sStack->cursor = 0;
	StrStack opStack;
	opStack.cursor = 0;
	int length;
	if (str[0] == '-')
	{
		for (int i = length1; i > -1; i--)
		{
			str[i + 1] = str[i];
		}
		str[0] = '0';
		length = length1 + 1;
	}
	else
	{
		length = length1;
	}
	for (int i = 0; i < length; i++)
	{
		if (str[i] >= '0' && str[i] <= '9' || str[i] == 'e' || str[i] == 'p') {
			sStack->data[sStack->cursor] = str[i];
			sStack->cursor++;
		}
		if (str[i] == '.') {
			sStack->data[sStack->cursor] = str[i];
			sStack->cursor++;
		}
		if (str[i] == '+' || str[i] == '-')
		{
			sStack->data[sStack->cursor] = ' ';
			sStack->cursor++;
			while (opStack.cursor != 0 && opStack.data[opStack.cursor - 1] != '(')
			{
				sStack->data[sStack->cursor] = opStack.data[opStack.cursor - 1];
				sStack->cursor++;
				opStack.cursor--;
			}
			opStack.data[opStack.cursor] = str[i];
			opStack.cursor++;
		}
		if (str[i] == '*' || str[i] == '/')
		{
			sStack->data[sStack->cursor] = ' ';
			sStack->cursor++;
			while (opStack.cursor != 0 && opStack.data[opStack.cursor - 1] != '+' && opStack.data[opStack.cursor - 1] != '-' && opStack.data[opStack.cursor - 1] != '(')
			{
				sStack->data[sStack->cursor] = opStack.data[opStack.cursor - 1];
				sStack->cursor++;
				opStack.cursor--;
			}
			opStack.data[opStack.cursor] = str[i];
			opStack.cursor++;
		}

		if (str[i] == 'l' || str[i] == '^' || str[i] == 'G' || str[i] == 'S' || str[i] == 'C' || str[i] == 'T' || str[i] == '!')
		{
			sStack->data[sStack->cursor] = ' ';
			sStack->cursor++;
			while (opStack.cursor != 0 && opStack.data[opStack.cursor - 1] != '+' && opStack.data[opStack.cursor - 1] != '-' && opStack.data[opStack.cursor - 1] != '(' && opStack.data[opStack.cursor - 1] != '*' && opStack.data[opStack.cursor - 1] != '/')
			{
				sStack->data[sStack->cursor] = opStack.data[opStack.cursor - 1];
				sStack->cursor++;
				opStack.cursor--;
			}
			opStack.data[opStack.cursor] = str[i];
			opStack.cursor++;
		}

		if (str[i] == '(')
		{
			opStack.data[opStack.cursor] = str[i];
			opStack.cursor++;
		}
		if (str[i] == ')')
		{
			while (opStack.cursor != 0 && opStack.data[opStack.cursor - 1] != '(')
			{
				sStack->data[sStack->cursor] = opStack.data[opStack.cursor - 1];
				sStack->cursor++;
				opStack.cursor--;
			}
			opStack.cursor--;
		}
	}
	while (opStack.cursor != 0)
	{
		sStack->data[sStack->cursor] = opStack.data[opStack.cursor - 1];
		sStack->cursor++;
		opStack.cursor--;
	}
	sStack->data[sStack->cursor] = '\0';

	return sStack;
}

// 将后缀表达式通过栈的结构算出结果。
// 输入c形式字符串，以'\0'结尾。
// 输出int型结果。
double Calcul(StrStack* opStack) {
	StStack* sStack = (StStack*)malloc(sizeof(StStack));
	sStack->cursor = -1;

	double result = 0, num = 0;
	int numLen = 0;

	for (int i = 0; i < opStack->cursor; i++) {
		if (opStack->data[i] >= '0' && opStack->data[i] <= '9' || opStack->data[i] == 'e' || opStack->data[i] == 'p') {
			num = 0;
			if (opStack->data[i] == 'e')
			{
				num = 2.7182818;
				sStack->data[++sStack->cursor] = num;

				continue;
			}

			if (opStack->data[i] == 'p')
			{
				num = acos(-1.0);
				sStack->data[++sStack->cursor] = num;

				continue;
			}

			for (numLen = 0; opStack->data[i + numLen] >= '0' && opStack->data[i + numLen] <= '9'; numLen++)
				;
			for (int k = 0; k < numLen; k++)
				num = num + (opStack->data[i + k] - '0') * pow(10, numLen - k - 1);


			//删除此字段，20170420
			//将字符组合成数字，此段将整数部分反向组合
			//解决：先判断位数，再组合


			if (opStack->data[i + numLen] == '.')
			{
				for (int j = -1; opStack->data[i + numLen + 1] >= '0' && opStack->data[i + numLen + 1] <= '9'; numLen++, j--)
					num = num + (opStack->data[i + numLen + 1] - '0') * pow(10.0, j);


				sStack->data[++sStack->cursor] = num;
				i = i + numLen;
				continue;
			}

			sStack->data[++sStack->cursor] = num;

			i = i + numLen - 1;

		}
		else if (opStack->data[i] == ' ')
			continue;
		else {
			switch (opStack->data[i])
			{
			case '+':
				result = sStack->data[sStack->cursor - 1] + sStack->data[sStack->cursor];
				sStack->cursor -= 2;
				sStack->data[++sStack->cursor] = result;
				break;
			case '-':
				result = sStack->data[sStack->cursor - 1] - sStack->data[sStack->cursor];
				sStack->cursor -= 2;
				sStack->data[++sStack->cursor] = result;
				break;
			case '*':
				result = sStack->data[sStack->cursor - 1] * sStack->data[sStack->cursor];
				sStack->cursor -= 2;
				sStack->data[++sStack->cursor] = result;
				break;
			case '/':
				result = sStack->data[sStack->cursor - 1] / sStack->data[sStack->cursor];
				sStack->cursor -= 2;
				sStack->data[++sStack->cursor] = result;
				break;
			case'^':
				result = pow(sStack->data[sStack->cursor - 1], sStack->data[sStack->cursor]);
				sStack->cursor -= 2;
				sStack->data[++sStack->cursor] = result;
				break;
			case'G':
				result = pow(sStack->data[sStack->cursor], 1 / sStack->data[sStack->cursor - 1]);
				sStack->cursor -= 2;
				sStack->data[++sStack->cursor] = result;
				break;
			case'l':
				result = log(sStack->data[sStack->cursor - 1]) / log(sStack->data[sStack->cursor]);
				sStack->cursor -= 2;
				sStack->data[++sStack->cursor] = result;
				break;
			case'S':
				result = sin(sStack->data[sStack->cursor] * 3.14159265 / 180.0);
				sStack->cursor -= 1;
				sStack->data[++sStack->cursor] = result;
				break;
			case'T':
				/*		if (sStack->data[sStack->cursor]==90)
						{
							result = 557135115.020977;
							break;
						}*/
				result = tan(sStack->data[sStack->cursor] * 3.14159265 / 180.0);
				sStack->cursor -= 1;
				sStack->data[++sStack->cursor] = result;
				break;
			case'C':
				result = cos(sStack->data[sStack->cursor] * 3.14159265 / 180.0);
				sStack->cursor -= 1;
				sStack->data[++sStack->cursor] = result;
				break;
			case'!':
				result = 1;
				for (int i = sStack->data[sStack->cursor]; i; i--)
				{
					result *= i;
				}
				sStack->cursor -= 1;
				sStack->data[++sStack->cursor] = result;
				break;
			default:
				break;
			}
		}
	}
	if (sStack->cursor == 0)
	{
		result = sStack->data[sStack->cursor];
	}
	free(opStack);

	return result;
}

extern double calculate(char in[]) {

	StrStack* str = Trans(in, strlen(in));

	return Calcul(str);
}