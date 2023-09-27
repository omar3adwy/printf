#include "main.h"

/**
 * int_to_str - Function to help in Identify the d and i as integars
 * @n: parameter to identify int
 * @buf: parameter point to char
 *
 * Return: Will be len
 */

int int_to_str(int n, char *buf)
{
	int len = 0;
	int sign = 1;
	int i;
	char temp;

	if (n == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (1);
	}
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	while (n > 0)
	{
		buf[len] = (n % 10) + '0';
		len++;
		n /= 10;
	}
	if (sign < 0)
	{
		buf[len] = '-';
		len++;
	}
	for (i = 0; i < len / 2; i++)
	{
		temp = buf[i];
		buf[i] = buf[len - i - 1];
		buf[len - i - 1] = temp;
	}
	buf[len] = '\0';
	return (len);
}

