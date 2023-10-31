#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2147483648", 10);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
}

int	ft_printf(const char	*ptr, ...)
{
	va_list	args;
	va_start(args, ptr);
	char	*str;
	int		i;

	i = 0;
	//printf("%s", ptr);
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			if (ptr[++i] == 'd')
				ft_putnbr((int)va_arg(args, int));
			if (ptr[i] == 'c')
				ft_putchar((char)(va_arg(args, int)));
			if (ptr[i] == 'f')
				ft_putnbr((float)va_arg(args, int));
			if (ptr[i] == 's')
			{
				str = ft_strdup(va_arg(args, char *));
				write(1, str, ft_strlen(str));
			}
			if (ptr[i] == 'p')
			{
				//str = ft_strdup(va_arg(args, char *));
				printf("%s", ft_itoa(va_arg(args, int)));
				//write(1, str, ft_strlen(str));
			}
		}
		else
			write(1, &ptr[i], 1);
		i++;
	}
	va_end(args);
}

int	main(void)
{
	char *str = "semih";
	char a = 48;

	printf("semih %dekmekci %d %c %s %p\n", 4, 10, 'a', str, &a);
	ft_printf("semih %dekmekci %d %c %s %p", 4, 10, 'a', str, &a);
}