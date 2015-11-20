#include<stdio.h>

int length(char *string)
{
	int i;
	for (i = 0; string[i] != '\0'; i++);
	return i;
}
char KthIndexFromEnd(char *str, int K)
{
	int i;
	if (str == NULL || K<0 || length(str)<K)
		return '\0';
	else
	{
		if (length(str) == K)
			return str[0];
		else if (K == 0)
			return str[length(str) - 1];
		else
		{
			return str[length(str) - K - 1];
		}
	}
}