#include"ft_printf.h"

void ft_putchar(char c);
void ft_putstr(char *str);

void ft_putnbr(int nb)
{
	if (nb == INT_MIN)
		ft_putstr("-2147483648");
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
	else
		ft_putchar(nb + 48);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	if (str)
	{
		while (*str)
		{
			ft_putchar(*str);
			str++;
		}
	}
	else	
		ft_putstr("(null)");
}

void ft_convertbase(unsigned long n, char *base, int ln)
{
    if (n >= ln)
	{
		ft_convertbase(n / ln, base, ln);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[n % 16]);
}

void ft_check_format(const char specifier, va_list args)
{
	if (specifier == 'p')
	{
		ft_putstr("0x");
		ft_convertbase(va_arg(args, void *), LOWERHEXBASE, 16);
	}
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(args, int));
	else if (specifier == 's')
		ft_putstr(va_arg(args, char *));
	else if (specifier == 'c')
		ft_putchar(va_arg(args, char));
	else if (specifier == 'x')
		ft_convertbase(va_arg(args, unsigned int), LOWERHEXBASE, 16);
	else if (specifier == 'X')
		ft_convertbase(va_arg(args, unsigned int), UPPERHEXBASE, 16);
	else if (specifier == 'u')
		ft_convertbase(va_arg(args, unsigned int), DECIMALBASE, 10);
	else
		ft_putchar(specifier);
}

int ft_()
{

}

int main()
{




	return 0;
}