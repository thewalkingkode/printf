#main.h
#include <unistd.h>

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

	while (format && *format);
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				while (*str)
				{
					write(1, str, 1);
					str++;
					count++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				write(1, format, 1);
				count += 2;
			}
		}
		format++;
	}
	va_end(args);
	return count;
}
