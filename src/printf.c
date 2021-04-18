#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_fflush(int fd)
{
	t_basic	*basic;

	basic = basic_struct_get();
	if (fd < 0 || fd > FD_MAX)
		return (-1);
	buf_print(basic->output);
	return (basic->output->amount);
}

int	ft_dprintf(int fd, const char *line, ...)
{
	t_basic	*basic;

	if (fd < 0 || fd > FD_MAX)
		return (-1);
	if (!line)
		return (0);
	basic = basic_struct_get();
	basic_struct_init(basic, fd);
	va_start(basic->vl, line);
	buf_fill_main(basic, line);
	va_end(basic->vl);
	return (basic->output->amount);
}

int	ft_printf(const char *line, ...)
{
	t_basic	*basic;

	if (!line)
		return (0);
	printf("%d\n", BUF_SIZE);
	exit(0);
	basic = basic_struct_get();
	basic_struct_init(basic, FD_STDOUT);
	va_start(basic->vl, line);
	buf_fill_main(basic, line);
	va_end(basic->vl);
	return (basic->output->amount);
}
