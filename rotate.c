/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:18:11 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/19 16:37:24 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	i = 0;
	tmp = pile->a[i];
	i++;
	while (i < pile->size_a)
	{
		pile->a[i - 1] = pile->a[i];
		i++;
	}
	pile->a[i - 1] = tmp;
	ft_printf("ra\n");
}

void	rotate_b(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	i = 0;
	tmp = pile->b[i];
	i++;
	while (i < pile->size_b)
	{
		pile->b[i - 1] = pile->b[i];
		i++;
	}
	pile->b[i - 1] = tmp;
	ft_printf("rb\n");
}

void	rotate_r(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1
		|| (pile->size_b == 0 || pile->size_b == 1))
		return ;
	i = 0;
	tmp = pile->a[i];
	while (++i < pile->size_a)
		pile->a[i - 1] = pile->a[i];
	pile->a[i - 1] = tmp;
	i = 0;
	tmp = pile->b[i];
	while (++i < pile->size_b)
		pile->b[i - 1] = pile->b[i];
	pile->b[i - 1] = tmp;
	ft_printf("rr\n");
}
