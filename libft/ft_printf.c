/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:26:49 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/05 16:26:50 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_print_fns(t_specifier *spec, long long data)
{
	char	*str;

	str = spec->tp == 'x' || spec->tp == 'X' ? ft_print_x(spec, data) : 0;
	str = ft_strchr("oO", spec->tp) ? ft_print_o(spec, data) : str;
	str = spec->tp == 's' ? ft_print_s(spec, (char*)data) : str;
	str = spec->tp == 'p' ? ft_print_p(spec, data) : str;
	str = ft_strchr("Uu", spec->tp) ? ft_print_u(spec, data) : str;
	str = ft_strchr("Ddi", spec->tp) ? ft_print_di(spec, data) : str;
	str = spec->tp == 'b' ? ft_print_bin(spec, data) : str;
	str = str ? str : ft_strnew(0);
	return (str);
}

static int	ft_print_type(va_list va, char **format)
{
	int			wrote;
	char		*str;
	t_specifier	specifier;

	wrote = 0;
	initspecifier(&specifier, format, va);
	if (ft_strchr("bspDdioOUuxX", specifier.tp) && specifier.tp)
	{
		ft_putstr((str = ft_print_fns(&specifier, va_arg(va, long long))));
		wrote += ft_strlen(str);
		free(str);
	}
	else if (specifier.tp == 'f')
	{
		ft_putstr((str = ft_print_double(&specifier, specifier.mdr == L ?
		va_arg(va, long double) : (long double)va_arg(va, double))));
		wrote += ft_strlen(str);
		free(str);
	}
	else if (specifier.tp)
		wrote += specifier.tp == 'c' ?
				ft_print_c(&specifier, va_arg(va, long long)) :
				ft_print_c(&specifier, specifier.tp);
	return (wrote);
}

int			ft_fvprintf(va_list va, char *format)
{
	int			wrote;

	wrote = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			wrote++;
		}
		else
		{
			format++;
			wrote += ft_print_type(va, &format);
		}
		format = *format ? ++format : format;
	}
	return (wrote);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		wrote;

	va_start(ap, format);
	wrote = ft_fvprintf(ap, (char*)format);
	va_end(ap);
	return (wrote);
}
