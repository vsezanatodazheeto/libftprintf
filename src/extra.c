#include "ft_printf.h"

t_basic	*basic_struct_get(void)
{
	static t_basic	basic;

	return (&basic);
}

void	basic_struct_init(t_basic *basic, int fd)
{
	bzero(basic, sizeof(t_basic));
	basic->format->base = BASE_DECIMAL;
	basic->output->fd = fd;
}
