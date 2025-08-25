/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:18:16 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/19 16:36:59 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_piles *pile)
{
	int	tmp;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	tmp = 0;
	tmp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_piles *pile)
{
	int	tmp;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	tmp = 0;
	tmp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = tmp;
	ft_printf("sb\n");
}

void	swap_s(t_piles *pile)
{
	int	tmp;

	if (pile->size_a == 0 || pile->size_a == 1
		|| (pile->size_b == 0 || pile->size_b == 1))
		return ;
	tmp = 0;
	tmp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = tmp;
	tmp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = tmp;
	ft_printf("ss\n");
}
