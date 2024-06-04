#include "holberton.h"


/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0
*/
int main(int argc, char *argv[])
{
	check_arguments(argc, argv);
	check_digits(argv[1]);
	check_digits(argv[2]);
	multiply_and_print_result(argv[1], argv[2]);
	return (0);
}

/**
 * check_arguments - checks if the number of arguments is correct
 * @argc: number of arguments
 * @argv: arguments
*/
void check_arguments(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "Error\n");
	exit(98);
	}
}

/**
 * check_digits - checks if the string contains only digits
 * @str: string to check
*/
void check_digits(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			fprintf(stderr, "Error\n");
			exit(98);
		}
	}
}

/**
 * multiply_and_print_result - multiplies two strings and prints the result
 * @num1: first number
 * @num2: second number
*/
void multiply_and_print_result(char *num1, char *num2)
{
	char command[256];

	snprintf(command, sizeof(command), "echo \"%s * %s\" | bc", num1, num2);
	system(command);
}
