/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:17:49 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/19 16:38:03 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_piles *pile)
{
	int	i;

	if (pile->size_a)
	{
		pile->size_b++;
		i = pile->size_b;
		while (--i > 0)
			pile->b[i] = pile->b[i - 1];
		pile->b[0] = pile->a[0];
		i = -1;
		pile->size_a--;
		while (++i < pile->size_a)
			pile->a[i] = pile->a[i + 1];
		ft_printf("pb\n");
	}
	else
		return ;
}

void	push_a(t_piles *pile)
{
	int	i;

	if (pile->size_b)
	{
		pile->size_a++;
		i = pile->size_a;
		while (--i > 0)
			pile->a[i] = pile->a[i - 1];
		pile->a[0] = pile->b[0];
		i = -1;
		pile->size_b--;
		while (++i < pile->size_b)
			pile->b[i] = pile->b[i + 1];
		ft_printf("pa\n");
	}
	else
		return ;
}
