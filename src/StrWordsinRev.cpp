/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void str_words_in_rev(char *input, int len)
{
	int i = 0, j = 0, index, space_index = 0, k;
	char temp;
	for (i = 0; i < len; i++)
	{
		if (input[i] == ' ')
			j++;
	}
	if (j > 0)
	{
		for (i = 0, k = len - 1; i <= k; i++, k--)
		{
			temp = input[i];
			input[i] = input[k];
			input[k] = temp;
		}
		for (i = 0; i <= len; i++)
		{
			if (input[i] == ' ' || input[i] == '\0')
			{
				if (i>0)
				{
					if (space_index - i != 1)
					{
						for (j = space_index, index = i - 1; j <= index; j++, index--)
						{
							temp = input[index];
							input[index] = input[j];
							input[j] = temp;
						}

					}
				}
				space_index = i + 1;
			}
		}
	}
	
}
