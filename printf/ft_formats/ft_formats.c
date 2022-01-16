#include "ft_formats.h"

void	width_handle(const char *format, long long *start, t_format
			*format_param, t_current_state *state);
void	precition_handle(const char *format, long long *start, t_format
			*format_param, t_current_state *state);

t_boolean	is_format_char(char c)
{
	if ((c < '0' || c > '9') && c != '.' && c != '*' && c != ' ')
		return (false);
	return (true);
}

void	set_default_format(t_format *format_param)
{
	format_param->precition = -1;
	format_param->width = -1;
	format_param->format_type_length = 0;
	format_param->print_space = false;
	format_param->padding_with_zeros = false;
	format_param->alignment = right_alignment;
	format_param->format_type_param = type_empty;
}

int	check_first_param_symbol(char format, t_format *format_param)
{
	int	status;

	status = 0;
	if (format == '-')
	{
		format_param->alignment = left_alignment;
		status = 1;
	}
	else if (format == '0')
	{
		format_param->padding_with_zeros = true;
		status = 1;
	}
	else if (format == ' ')
	{
		format_param->print_space = true;
		status = 1;
	}
	return (status);
}

void	ft_digit_handler(const char *format, t_current_state *state,
t_format *format_param, long long *i)
{
	if (*state == width_handling)
		width_handle(format, i, format_param, state);
	else if (*state == precition_handling)
		precition_handle(format, i, format_param, state);
}

void	ft_minus_handler(t_current_state *state, t_format *format_param)
{
	format_param->padding_with_zeros = false;
	format_param->alignment = left_alignment;
	*state = width_handling;
}
