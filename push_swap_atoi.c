/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:21:58 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/22 16:32:43 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit_or_valid_range(char c, long *num, int sign, t_piles *pile)
{
	if (c < '0' || c > '9')
		return (0);
	*num = *num * 10 + (c - '0');
	if ((sign == 1 && *num > INT_MAX)
		|| (sign == -1 && *num > (long)INT_MAX + 1))
		error_detected(pile);
	return (1);
}

int	push_swap_atoi(char *str, t_piles *pile)
{
	int		i;
	int		sign;
	long	num;

	num = 0;
	i = parse_sign_and_skip_spaces(str, &sign);
	num = parse_and_validate_number(str + i, sign, pile);
	return (num * sign);
}

int	parse_sign_and_skip_spaces(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

long	parse_and_validate_number(char *str, int sign, t_piles *pile)
{
	int		i;
	long	num;
	int		has_digit;

	i = 0;
	num = 0;
	has_digit = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			if (str[i] != '\0')
				error_detected(pile);
			break ;
		}
		if (!is_digit_or_valid_range(str[i], &num, sign, pile))
			error_detected(pile);
		has_digit = 1;
		i++;
	}
	if (!has_digit)
		error_detected(pile);
	return (num);
}
