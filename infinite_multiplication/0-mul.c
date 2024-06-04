#include "holberton.h"

/**
 * init_digit_array - allocates and initializes an array to contain the digits
 *   of a base 10 number.
 *
 * @size: array size
 * Return: pointer to initialized array, or NULL on failure
 */
unsigned int *init_digit_array(size_t size)
{
	unsigned int *arr = malloc(sizeof(unsigned int) * size);
	size_t i;

	if (arr)
	{
		for (i = 0; i < size; i++)
			arr[i] = 0;
	}
	return (arr);
}

/**
 * string_int_multiply - multiplies two base 10 numbers represented as strings
 *                     and stores the result in an array of digits.
 *
 * @prod_digits: array to store digits of the product
 * @n1_digits: string containing multiplicand digits in ASCII
 * @n2_digits: string containing multiplier digits in ASCII
 * @n1_len: length of the multiplicand string
 * @n2_len: length of the multiplier string
 */
void string_int_multiply(unsigned int *prod_digits, char *n1_digits,
			 char *n2_digits, size_t n1_len, size_t n2_len)
{
	int i, j, sum;
	unsigned char digit1, digit2;

	if (!prod_digits || !n1_digits || !n2_digits)
		return;

	for (i = n1_len - 1; i >= 0; i--)
	{
		sum = 0;
		digit1 = n1_digits[i] - '0';

		for (j = n2_len - 1; j >= 0; j--)
		{
			digit2 = n2_digits[j] - '0';
			sum += prod_digits[i + j + 1] + digit1 * digit2;
			prod_digits[i + j + 1] = sum % 10;
			sum /= 10;
		}
		prod_digits[i + j + 1] += sum;
	}
}

/**
 * string_is_pos_int - checks if a string represents a positive integer.
 *
 * @s: string to check
 * Return: 1 if true, 0 if false
 */
int string_is_pos_int(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * error - prints an error message and exits with a given status code.
 *
 * @status: error code to exit with
 */
void error(int status)
{
	const char *msg = "Error\n";
	int i;

	for (i = 0; msg[i]; i++)
		_putchar(msg[i]);
	exit(status);
}

/**
 * main - entry point
 *
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	size_t i, av1_len, av2_len, prod_len;
	unsigned int *prod_digits;

	if (argc != 3 || !string_is_pos_int(argv[1]) ||
	    !string_is_pos_int(argv[2]))
		error(98);

	av1_len = strlen(argv[1]);
	av2_len = strlen(argv[2]);
	prod_len = av1_len + av2_len;

	prod_digits = init_digit_array(prod_len);
	if (!prod_digits)
		error(98);

	string_int_multiply(prod_digits, argv[1], argv[2], av1_len, av2_len);

	for (i = 0; i < prod_len && prod_digits[i] == 0; i++)
		;

	if (i == prod_len)
		_putchar('0');
	else
	{
		for (; i < prod_len; i++)
			_putchar(prod_digits[i] + '0');
	}

	_putchar('\n');
	free(prod_digits);

	return (0);
}
