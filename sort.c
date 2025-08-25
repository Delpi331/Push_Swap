/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:18:14 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/19 18:30:47 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	temporary_sort(int *pile_temporaire, int size)
{
	int	i;
	int	j;
	int	temporaire;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (pile_temporaire[i] > pile_temporaire[j])
			{
				temporaire = pile_temporaire[i];
				pile_temporaire[i] = pile_temporaire[j];
				pile_temporaire[j] = temporaire;
			}
			j++;
		}
		i++;
	}
}

void	three_numbers_case_pile_a(t_piles *three)
{
	if (three->a[0] > three->a[1] && three->a[0] < three->a[2]
		&& three->a[1] < three->a[2])
		swap_a(three);
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] > three->a[2])
	{
		swap_a(three);
		reverse_rotate_a(three);
	}
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] < three->a[2])
		rotate_a(three);
	if (three->a[0] < three->a[1] && three->a[0] < three->a[2]
		&& three->a[1] > three->a[2])
	{
		swap_a(three);
		rotate_a(three);
	}
	if (three->a[0] < three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] > three->a[2])
		reverse_rotate_a(three);
}

int	sort(t_piles *pile, int size)
{
	if (check_sorted(pile->a, pile->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(pile);
		else if (size == 3)
			three_numbers_case_pile_a(pile);
		else
			quicksort_pile_a(pile, size, 0);
	}
	return (0);
}

int	ft_push(t_piles *pile, int len, int push)
{
	if (push == 0)
		push_b(pile);
	else
		push_a(pile);
	len--;
	return (len);
}
