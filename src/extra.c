#include "ft_printf.h"

t_basic	*basic_struct_get(void)
{
	static t_basic	basic;

	return (&basic);
}

void	basic_struct_init(t_basic *basic, int fd)
{
	ft_printf_memset(basic, 0, sizeof(t_basic));
	basic->format->base = BASE_DECIMAL;
	basic->output->fd = fd;
}

void	*ft_printf_memset(void *s, int c, size_t len)
{
	size_t	i;
	char	*temp;

	temp = (char *)s;
	i = 0;
	while (i < len)
	{
		temp[i] = c;
		i++;
	}
	return (s);
}
