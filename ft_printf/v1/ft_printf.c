
#include <stdarg.h>
#include <unistd.h>

ssize_t	ft_putchr(int c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putstr(char *s)
{
	ssize_t	cnt;

	cnt = 0;
	if (!s)
		s = "(null)";
	while (*s)
		cnt += ft_putchr(*s++);
	return (cnt);
}

ssize_t	put_base(unsigned int n, unsigned int base, const char *d)
{
	ssize_t	cnt;

	cnt = 0;
	if (n >= base)
		cnt += put_base(n / base, base, d);
	cnt += ft_putchr(d[n % base]);
	return (cnt);
}

ssize_t	ft_puthex(unsigned int n)
{
	return (put_base(n, 16, "0123456789abcdef"));
}

ssize_t	ft_putnbr(int n)
{
	ssize_t			cnt;
	unsigned int	un;

	cnt = 0;
	if (n < 0)
	{
		cnt += ft_putchr('-');
		un = -n;
	}
	else
		un = n;
	cnt += put_base(un, 10, "0123456789");
	return (cnt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 's')
				cnt += ft_putstr(va_arg(ap, char *));
			else if (fmt[i] == 'd')
				cnt += ft_putnbr(va_arg(ap, int));
			else if (fmt[i] == 'x')
				cnt += ft_puthex(va_arg(ap, unsigned int));
		}
		else
			cnt += ft_putchr(fmt[i]);
		i++;
	}
	va_end(ap);
	return (cnt);
}

#include <stdio.h>

int	main(void)
{
	int	cnt1;
	int	cnt2;

	cnt1 = printf("hello\n");
	printf("%d\n", cnt1);
	cnt2 = ft_printf("hello\n");
	ft_printf("%d\n", cnt2);
	cnt1 = printf("%s\n", NULL);
	printf("%d\n", cnt1);
	cnt2 = ft_printf("%s\n", NULL);
	ft_printf("%d\n", cnt2);
}
