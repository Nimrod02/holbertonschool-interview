#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int wildcmp(char *s1, char *s2);
int _wildcmp(char *base, char *pattern, bool wildcard);
int globMatch(char *base, char *pattern, int *tested_indices);
int match_question(char *base, char *pattern);
int match_star(char *base, char *pattern);


#endif /* HOLBERTON_H */
