#include <unistd.h>
#include <limits.h>

void ft_putnbr_fd(int n, int fd)
{
    if (n < 0)
	{
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar_fd(n + '0', fd);
}