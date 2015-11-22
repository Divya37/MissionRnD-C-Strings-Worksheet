/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>
#include<conio.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2)
{
	int *spaces1, *spaces2, size1 = 1, size2 = 1, count1 = 0, count2 = 0,flag=0, check_val = 0, str1_counter = 0, str2_counter = 0, x = 0, y = 0, k, l;
	char **common;
		
	if (!str1 || !str2)
		return NULL;

	spaces1 = (int *)malloc(sizeof(int) * 20);
	spaces2 = (int *)malloc(sizeof(int) * 20);

	spaces1[0] = -1;	
	for (x = 0; str1[x] != '\0'; x++)
		if (str1[x] == ' ')
			spaces1[size1++] = x;
	spaces1[size1] = x;	

	spaces2[0] = -1;
	for (x = 0; str2[x] != '\0'; x++)
		if (str2[x] == ' ')
			spaces2[size2++] = x;
	spaces2[size2] = x;	

	//main logic
	common = (char **)malloc(sizeof(char *) * 10);
	for (x = 0; x < size1; x++)
	{
		for (y = 0; y < size2; y++)
		{
			if (str1[spaces1[x] + 1] == str2[spaces2[y] + 1])
			{
				if ((spaces1[x + 1] - spaces1[x]) == (spaces2[y + 1] - spaces2[y]))
				{					
					check_val = 0;
					
					for (k = spaces1[x] + 1, l = spaces2[y] + 1; k < spaces1[x + 1] && l<spaces2[y + 1]; k++, l++)
					{
						if (str1[k] == str2[l])
							check_val++;
						else
							break;
					}
					check_val = check_val + 1;

					if (check_val == (spaces1[x + 1] - spaces1[x]))
					{
						flag = 1;
						common[count1] = (char *)malloc(sizeof(char) * 31);
						count2 = 0;

						for (k = spaces1[x] + 1; k < spaces1[x + 1]; k++)
							common[count1][count2++] = str1[k];	

						common[count1][count2] = '\0';
						count1++;
					}
					
				}
			}
		}
	}
	if (count1 == count2 == 0 || flag==0)
		return NULL;
	return common;
}