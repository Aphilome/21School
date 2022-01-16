#ifndef FT_FORMATS_H
# define FT_FORMATS_H

# include <stdarg.h>
# include "../ft_utils/ft_utils.h"

typedef enum e_format_type
{
	type_empty,
	type_c,
	type_s,
	type_p,
	type_d,
	type_i,
	type_u,
	type_x,
	type_X,
	type_percent,
	type_n
}	t_format_type;

typedef enum e_alignment
{
	left_alignment,
	right_alignment
}	t_alignment;

typedef enum e_current_state
{
	width_handling,
	precition_handling,
	converter_handling,
	end_handling
}	t_current_state;

typedef struct s_format
{
	long long		precition;
	long long		width;
	long long		format_type_length;
	const char		*start_src;
	long long		*current_index;
	t_boolean		print_space;
	t_boolean		padding_with_zeros;
	t_alignment		alignment;
	t_format_type	format_type_param;
}	t_format;

void	ft_parse_format_type(const char *format, t_format *format_param,
			va_list *undef_args);

#endif
