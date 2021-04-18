#include "ft_printf.h"

static void	buf_fill_num_zero(t_basic *basic)
{
	if (basic->output->buf_i == BUF_SIZE)
		buf_print(basic->output);
	buf_copy(&basic->output->buf[basic->output->buf_i], "0", \
				&basic->output->buf_i, &basic->output->amount);
}

static void	buf_fill_num_neg(t_basic *basic)
{
	if (basic->output->buf_i == BUF_SIZE)
		buf_print(basic->output);
	buf_copy(&basic->output->buf[basic->output->buf_i], "-", \
				&basic->output->buf_i, &basic->output->amount);
}

static void	buf_fill_num_base_plus(t_basic *basic, unsigned long long unval)
{
	char	ch;

	if (basic->output->buf_i == BUF_SIZE)
		buf_print(basic->output);
	ch = unval % basic->format->base + 'a' - 10;
	buf_copy(&basic->output->buf[basic->output->buf_i], &ch, \
				&basic->output->buf_i, &basic->output->amount);
}

static void	buf_fill_num_base(t_basic *basic, unsigned long long unval)
{
	char	ch;

	if (basic->output->buf_i == BUF_SIZE)
		buf_print(basic->output);
	ch = unval % basic->format->base + '0';
	buf_copy(&basic->output->buf[basic->output->buf_i], &ch, \
				&basic->output->buf_i, &basic->output->amount);
}

void	buf_fill_num(t_basic *basic, unsigned long long unval)
{
	if (basic->format->val_zero)
		buf_fill_num_zero(basic);
	if (!unval && basic->format->val_neg)
		buf_fill_num_neg(basic);
	if (unval)
	{
		if (unval % basic->format->base >= 10)
		{
			buf_fill_num(basic, unval / basic->format->base);
			buf_fill_num_base_plus(basic, unval);
		}
		else if (unval % basic->format->base < 10)
		{
			buf_fill_num(basic, unval / basic->format->base);
			buf_fill_num_base(basic, unval);
		}
	}
}
