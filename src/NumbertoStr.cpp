#include<stdio.h>

long power(int num, int pow)
{
	long result = 1, i;
	for (i = 0; i < pow; i++)
		result = result*num;
	return result;
}
void number_to_str(float number, char *str, int afterdecimal)
{
	long temp, temp_num;
	int rem, i, len, j;
	char var;
	temp = number*power(10, afterdecimal);
	temp_num = temp;

	if (temp < 0)
		temp_num = -1 * temp_num;

	for (i = 0; temp_num > 0; i++)
		temp_num = temp_num / 10;
	len = i;
	
	if (temp > 0)
	{
		i = 0;
		temp_num = temp;
	}
	else
	{
		i = 1;
		str[0] = '-';
		afterdecimal++;
		temp_num = -1 * temp;
	}
	
	for (i = i; temp_num > 0; i++)
	{
		if (i < afterdecimal)
		{
			rem = temp_num % 10;
			str[i] = rem + 48;
			temp_num = temp_num / 10;
		}

		else if (i > afterdecimal)
		{
			rem = temp_num % 10;
			str[i] = rem + 48;
			temp_num = temp_num / 10;
		}
		else
			str[i] = '.';
	}
	
	len = i;
	if (temp > 0)
		i = 0;
	else
	{
		i = 1;
		str[0] = '-';
	}
	for (i = i, j = len - 1; i <= j; i++, j--)
	{
		var = str[i];
		str[i] = str[j];
		str[j] = var;
	}
}
