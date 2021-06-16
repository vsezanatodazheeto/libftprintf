#include "ft_printf.h"

void	buf_print(t_output *output)
{
	if (!output || !output->buf_i || !output->amount)
		return ;
	write(output->fd, output->buf, output->buf_i);
	ft_memset(output->buf, 0, BUF_SIZE);
	output->buf_i = 0;
}

void	buf_copy(char *dest, const char *src, unsigned int *dest_i, int *amount)
{
	*dest = *src;
	(*dest_i)++;
	(*amount)++;
}

void	buf_fill(t_basic *basic, const char *line)
{
	int	i;

	i = 0;
	while (line[i] && basic->output->buf_i < BUF_SIZE)
	{
		buf_copy(&basic->output->buf[basic->output->buf_i], &line[i], \
					&basic->output->buf_i, &basic->output->amount);
		i++;
		if (basic->output->buf[basic->output->buf_i - 1] == '\n')
			break ;
	}
	buf_print(basic->output);
	if (line[i])
		buf_fill(basic, line + i);
}

void	buf_fill_main(t_basic *basic, const char *line)
{
	int	i;

	i = 0;
	while (line[i] && basic->output->buf_i < BUF_SIZE)
	{
		if (line[i] == '%')
		{
			parse_main(basic, line, &i);
			continue ;
		}
		buf_copy(&basic->output->buf[basic->output->buf_i], &line[i], \
					&basic->output->buf_i, &basic->output->amount);
		i++;
		if (basic->output->buf[basic->output->buf_i - 1] == '\n')
			break ;
	}
	buf_print(basic->output);
	if (line[i])
		buf_fill_main(basic, line + i);
}
