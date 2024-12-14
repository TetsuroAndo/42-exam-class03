/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 04:05:29 by teando            #+#    #+#             */
/*   Updated: 2024/12/14 09:40:57 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

ssize_t	ft_putchr(int c)
{
	return ((ssize_t)write(1, &c, 1));
}

ssize_t	ft_putstr(char *s)
{
	ssize_t		cnt;
	const char	*null_str = "(null)";

	cnt = 0;
	if (!s)
		while (*null_str)
			cnt += ft_putchr(*null_str++);
	else
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

int	ft_putnbr_hex(unsigned int n)
{
	return (put_base(n, 16, "0123456789abcdef"));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 's')
				count += ft_putstr(va_arg(ap, char *));
			else if (fmt[i] == 'd')
				count += ft_putnbr(va_arg(ap, int));
			else if (fmt[i] == 'x')
				count += ft_putnbr_hex(va_arg(ap, unsigned int));
			else
				count += ft_putchr(fmt[i]);
		}
		else
			count += ft_putchr(fmt[i]);
		i++;
	}
	va_end(ap);
	return (count);
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
	cnt1 = printf("");
	printf("%d\n", cnt1);
	cnt2 = ft_printf("");
	ft_printf("%d\n", cnt2);
}
