/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:17:05 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/22 18:10:42 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_detected(t_piles *pile)
{
	if (pile->a)
		free(pile->a);
	if (pile->b)
		free(pile->b);
	if (pile->split_av)
		free_split(pile->split_av);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	push_swap(char **av, t_piles *pile)
{
	int	size;
	int	i;

	i = -1;
	size = push_swap_strlen(av);
	pile->a = malloc(size * sizeof(int));
	if (!pile->a)
		return ;
	pile->b = malloc(size * sizeof(int));
	if (!pile->b)
	{
		free(pile->a);
		return ;
	}
	pile->size_a = size;
	pile->size_b = 0;
	while (++i < size)
		pile->a[i] = push_swap_atoi(av[i], pile);
	check_doubles(pile);
	sort(pile, size);
	free(pile->a);
	free(pile->b);
}

int	main(int ac, char **av)
{
	t_piles	pile;

	memset(&pile, 0, sizeof(t_piles));
	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			if (av[0][0] == '\0')
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			pile.split_av = ft_split(*av, ' ');
			if (!pile.split_av)
				return (1);
			av = pile.split_av;
		}
		push_swap(av, &pile);
		if (ac == 2)
			free_split(pile.split_av);
		return (0);
	}
	return (0);
}
