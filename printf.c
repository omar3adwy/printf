#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
        int count = 0;
        va_list args;
        char c;
        char *s;
        char buf[1024];
        int len;
        int n;

        va_start(args, format);

        while (*format)
        {
                if (*format == '%')
                {
                        format++;
                        switch (*format)
                        {
                                case 'c':
                                        c = va_arg(args, int);
                                        write(1, &c, 1);
                                        count++;
                                        break;
                                case 's':
                                        s = va_arg(args, char *);
                                        while (*s)
                                        {
                                                write(1, s, 1);
                                                s++;
                                                count++;
                                        }
                                        break;
                                case '%': 
                                        write(1, "%", 1);
                                        count++;
                                        break;
                                case 'd':
                                case 'n':
                                        n = va_arg(args, int);
                                        len = int_to_str(n, buf);
                                        write(1, buf, len);
                                        count += len;
                                        break;
                                default:
                                        write(1, format, 1);
                                        count++;
                        }
                }
                else
                {
                        write(1, format, 1);
                        count++;
                }
                format++;
        }
        va_end(args);
        return (count); 
}

