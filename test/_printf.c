#include <stdarg.h>
#include <unistd.h>

int _strlen(char *str);

/**
 * _printf - Produces output according to a format
 * @format: Specified format
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list argPtr;
	char c;
	char *s;
	int i = 0, len = 0;

	va_start(argPtr, format);

	if (format)
	{
		while (format[i])
		{
			if (format[i] != '%')
			{
				write(1, &format[i], 1);
				len++;
			}
			else if (format[i] == '%')
			{
				i++;
				switch (format[i])
				{
				case 'c':
					c = (char) va_arg(argPtr, int);
					write(1, &c, 1);
					len++;
					break;
				case 's':
					s = va_arg(argPtr, char *);
					if (s != NULL)
						write(1, s, _strlen(s));
					len += _strlen(s);
					break;
				default:
					c = (char) va_arg(argPtr, int);
					write(1, &c, 1);
					len++;
					break;
				}
			}
			i++;
		}
	}
	va_end(argPtr);
	return (len);
}

/**
 * _strlen - Calculates how many characters are in a string
 * @str: String
 *
 * Return: Length of string
 */

int _strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;

	return (len);
}
