#include "substring.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * find_substring - Finds all possible substrings containing a list of words
 *
 * @s: The string to scan
 * @words: Array of words all substrings must be a concatenation
 * @nb_words: Number of elements in the array words
 * @n: Holds the address at which to store the number
 *
 * Return: An allocated array storing each index in s
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, j, k, pos, s_len = strlen(s), word_len = strlen(words[0]);
	int *indices, *matched_word = /
	malloc(nb_words * sizeof(int)), temp[50], count = 0;

	if (!s || !words || !*words || !n || !matched_word)
		return (NULL);

	for (i = 0; i < s_len; i++)
	{
		memset(matched_word, 0, nb_words * sizeof(int));
		pos = i;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (!matched_word[k] && strncmp(words[k], s + pos, word_len) == 0)
				{
					matched_word[k] = 1;
					pos += word_len;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			temp[count++] = i;
	}
	free(matched_word);
	*n = count;
	indices = malloc(count * sizeof(int));
	if (!indices)
		return (NULL);
	for (i = 0; i < count; i++)
		indices[i] = temp[i];
	return (indices);
}
