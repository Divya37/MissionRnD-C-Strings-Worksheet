/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>

int _length(char *string)
{
	int i;
	for (i = 0; string[i] != '\0'; i++);
	return i;
}
char removeSpaces(char *str)
{
	int i, j, len;
	
	if (!str)
		 return '\0';
	len = _length(str);
	 for (i = 0; i < len; i++)
		{
			if (str[i] == ' ')
			{
				for (j = i; j < len - 1; j++)
					str[j] = str[j + 1];

				len--;
				i--;
			}
		}
		str[len] = '\0';
		return 'a';
	
}