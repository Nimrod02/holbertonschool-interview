#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 */
void menger(int level)
{
	int i, j, size, x, y;
	char c;

	if (level < 0)
		return;

	size = pow(3, level);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			x = i;
			y = j;
			c = '#';
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					c = ' ';
				x = x / 3;
				y = y / 3;
			}
			printf("%c", c);
		}
		printf("\n");
	}
}
