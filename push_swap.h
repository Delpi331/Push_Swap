/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:17:21 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/22 14:14:20 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_piles
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	char	**split_av;
}	t_piles;

char	**ft_split(char const *s, char c);
void	push_swap(char **av, t_piles *pile);
int		push_swap_strlen(char **av);
void	error_detected(t_piles *pile);
int		push_swap_atoi(char *str, t_piles *pile);
void	check_doubles(t_piles *pile);
void	swap_a(t_piles *pile);
void	swap_b(t_piles *pile);
void	swap_s(t_piles *pile);
void	rotate_a(t_piles *pile);
void	rotate_b(t_piles *pile);
void	rotate_r(t_piles *pile);
void	reverse_rotate_a(t_piles *pile);
void	reverse_rotate_b(t_piles *pile);
void	reverse_rotate_r(t_piles *pile);
void	push_b(t_piles *pile);
void	push_a(t_piles *pile);
int		sort(t_piles *pile, int size);
int		check_sorted(int *pile, int size, int order);
void	three_numbers_case_pile_a(t_piles *three);
void	temporary_sort(int *pile_temporaire, int size);
int		quicksort_pile_a(t_piles *pile, int len, int count_r);
int		quicksort_pile_b(t_piles *pile, int len, int count_r);
void	quicksort_three_pile_a_and_b(t_piles *pile, int len);
int		sort_three_b(t_piles *pile, int len);
int		ft_push(t_piles *pile, int len, int pb);
int		mediane_of_numbers(int *pivot, int *pile, int size);
void	read_from_stdin(t_piles *pile);
int		*c_errors(char **av);
void	exec_instruction(t_piles *pile, char *instruction);
void	free_error(t_piles *pile, int choix);
void	free_split(char **split_array);
int		push_swap_atoi(char *str, t_piles *pile);
int		parse_sign_and_skip_spaces(char *str, int *sign);
long	parse_and_validate_number(char *str, int sign, t_piles *pile);
#endif
