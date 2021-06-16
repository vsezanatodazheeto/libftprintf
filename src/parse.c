#include "ft_printf.h"

unsigned long long	cast_types_dipux(t_basic *basic)
{
	int					val;
	unsigned long long	unval;

	if (basic->format->type == 'd' || basic->format->type == 'i')
	{
		val = va_arg(basic->vl, int);
		if (val < 0)
		{
			unval = (unsigned int)(val * -1);
			basic->format->val_neg = 1;
		}
		else
			unval = val;
	}
	else if (basic->format->type == 'x' || basic->format->type == 'u')
		unval = (unsigned long long)va_arg(basic->vl, unsigned int);
	else
		unval = va_arg(basic->vl, unsigned long long);
	if (!unval)
		basic->format->val_zero = 1;
	return (unval);
}

char	*cast_types_csper(t_basic *basic)
{
	static char	cper[CPER_SIZE];

	if (basic->format->type == 'c' || basic->format->type == '%')
	{
		ft_printf_memset(cper, 0, CPER_SIZE);
		if (basic->format->type == 'c')
			*cper = (char)va_arg(basic->vl, int);
		else
			*cper = '%';
		return (cper);
	}
	else
		return (va_arg(basic->vl, char *));
}

static int	parse_specifiers(t_basic *basic, const char *line, int *i)
{
	int	i_type;

	i_type = 0;
	while (PRINTF_TYPES[i_type])
	{
		if (line[*i] == PRINTF_TYPES[i_type])
		{
			if (line[*i] == 'x' || line[*i] == 'X' || line[*i] == 'p')
				basic->format->base = BASE_HEXICAL;
			basic->format->type = line[*i];
			(*i)++;
			return (1);
		}
		i_type++;
	}
	return (0);
}

void	parse_main(t_basic *basic, const char *line, int *i)
{
	char				*str;
	unsigned long long	unval;

	(*i)++;
	if (!(parse_specifiers(basic, line, i)))
		return ;
	if (basic->format->type == 's' || basic->format->type == 'c' || \
		basic->format->type == '%')
	{
		str = cast_types_csper(basic);
		if (!str)
			str = NULL_STR;
		buf_fill(basic, str);
	}
	else
	{
		unval = cast_types_dipux(basic);
		buf_fill_num(basic, unval);
	}
}
