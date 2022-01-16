#include "ft_formats.h"

t_boolean	is_format_char(char c);
void		set_default_format(t_format *format_param);
int			check_first_param_symbol(char format, t_format *format_param);
void		ft_digit_handler(const char *format, t_current_state *state,
				t_format *format_param, long long *i);
void		ft_minus_handler(t_current_state *state, t_format *format_param);

void	width_handle(const char *format, long long *start,
			t_format *format_param, t_current_state *state)
{
	format_param->width = simple_atoi(format, start);
	if (format[*start] != '*')
		*state = precition_handling;
}

void	precition_handle(const char *format, long long *start, t_format
*format_param, t_current_state *state)
{
	format_param->precition = simple_atoi(format, start);
	*state = converter_handling;
}

void	star_handle(va_list *undef_args, t_format *format_param,
				 t_current_state *state)
{
	if (*state == width_handling)
	{
		format_param->width = va_arg(*undef_args, int);
		if (format_param->width < 0)
		{
			format_param->alignment = left_alignment;
			format_param->width = -format_param->width;
			format_param->padding_with_zeros = false;
		}
		*state = precition_handling;
	}
	else if (*state == precition_handling)
	{
		format_param->precition = va_arg(*undef_args, int);
		*state = converter_handling;
	}
}

void	converter_handle(char format, t_format *format_param,
					  t_current_state *state)
{
	if (format == 'c')
		format_param->format_type_param = type_c;
	else if (format == 's')
		format_param->format_type_param = type_s;
	else if (format == 'p')
		format_param->format_type_param = type_p;
	else if (format == 'd')
		format_param->format_type_param = type_d;
	else if (format == 'i')
		format_param->format_type_param = type_i;
	else if (format == 'u')
		format_param->format_type_param = type_u;
	else if (format == 'x')
		format_param->format_type_param = type_x;
	else if (format == 'X')
		format_param->format_type_param = type_X;
	else if (format == '%')
		format_param->format_type_param = type_percent;
	else if (format == 'n')
		format_param->format_type_param = type_n;
	*state = end_handling;
}

void	ft_parse_format_type(const char *format, t_format *format_param,
						  va_list *undef_args)
{
	long long		i;
	t_current_state	state;

	set_default_format(format_param);
	i = check_first_param_symbol(format[0], format_param);
	state = width_handling;
	while (state != end_handling)
	{
		if (ft_isdigit(format[i]) == true)
			ft_digit_handler(format, &state, format_param, &i);
		if (format[i] == '.' || format[i] == ',')
		{
			format_param->precition = 0;
			state = precition_handling;
		}
		else if (format[i] == '*')
			star_handle(undef_args, format_param, &state);
		else if (format[i] == '-')
			ft_minus_handler(&state, format_param);
		else if (is_format_char(format[i]) == false)
			converter_handle(format[i], format_param, &state);
		i++;
	}
	format_param->format_type_length = i;
}
