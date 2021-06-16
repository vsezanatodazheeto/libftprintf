#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <strings.h>

#ifndef BUF_SIZE
# define BUF_SIZE 100
#endif

# define LOW_HEX_BASE	'a'
# define UPPER_HEX_BASE	'A'
# define PRINTF_TYPES	"%csdipux"
# define NULL_STR		"(null)"

# define CPER_SIZE		2

# define FD_STDOUT		1
# define FD_MAX			1024

# define BASE_DECIMAL	10
# define BASE_HEXICAL	16

typedef struct s_format
{
	char			type;

	int				base;
	int				val_neg;
	int				val_zero;
}					t_format;

typedef struct s_output
{
	char			buf[BUF_SIZE + 1];
	unsigned int	buf_i;
	int				fd;
	int				amount;
}					t_output;

typedef struct s_basic
{
	va_list			vl;
	t_format		format[1];
	t_output		output[1];
}					t_basic;

/* general */
int		ft_printf(const char *line, ...);
int		ft_dprintf(int fd, const char *line, ...);

/* buffer */
void	buf_copy(char *dest, const char *src, \
					unsigned int *dest_i, int *amount);
void	buf_print(t_output *output);

void	buf_fill_main(t_basic *basic, const char *line);
void	buf_fill_num(t_basic *basic, unsigned long long unval);
void	buf_fill(t_basic *basic, const char *line);

/* logic */
void	parse_main(t_basic *basic, const char *line, int *i);

/* extra */
void	basic_struct_init(t_basic *basic, int fd);
t_basic	*basic_struct_get(void);
void	*ft_printf_memset(void *s, int c, size_t len);

#endif
