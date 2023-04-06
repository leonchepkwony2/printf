#include "main.h"

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	for (const char *p = format; *p != '\0'; ++p)
	{
		if (*p == '%')
		{
			++p;
			switch (*p)
			{
				case 'c':
				{
					int c = va_arg(args, int);
				
					putchar(c);
					++count;
					break;
				}
				case 's':
				{
					const char *s = va_arg(args, const char *);
				
					for (; *s != '\0'; ++s)
					{
						putchar(*s);
						++count;
					}
					break;
				}
				case '%':
				{
					putchar('%');
					++count;
					break;
				}
			}
		}
		else
		{
			putchar(*p);
			++count;
		}
	}

	va_end(args);

	return (count);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: on Success 1
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
