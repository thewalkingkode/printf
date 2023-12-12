#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - custom printf function
 * @format: Format String
 *
   * Return: Number of chars printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			switch (*++format)
			{
			case 'c':
				count += putchar(va_arg(args, int));
				break;
			case 's':
				count += fputs(va_arg(args, char *), stdout);
				break;
			case '%':
				count += putchar('%');
				break;
			default:
				break;
			}
		}
		else
		{
			count += putchar(*format);
		}
		++format;		
	}
	va_end(args);
	return count;
}

int main(void)
{
	int number_of_chars_printed = _printf("This is a test string.\n");
	printf("Number of characters printed: %d\n", number_of_chars_printed);
	return (0);
}
