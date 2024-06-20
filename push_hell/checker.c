/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:07:19 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/20 17:49:12 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	goodbye(char *read, t_Node **stack)
{
	write (2, "Error\n", 6);
	freelist (*stack);
	free (read);
	exit (1);
}

static void	applymoves(char *read, t_Node **stacka, t_Node **stackb)
{
	if (!ft_strcmp(read, "sa\n"))
		swap(*stacka);
	else if (!ft_strcmp(read, "sb\n"))
		swap(*stackb);
	else if (!ft_strcmp(read, "ss\n"))
		double_swap(*stacka, *stackb);
	else if (!ft_strcmp(read, "pa\n"))
		push(stackb, stacka);
	else if (!ft_strcmp(read, "pb\n"))
		push(stacka, stackb);
	else if (!ft_strcmp(read, "ra\n"))
		rotate(stacka);
	else if (!ft_strcmp(read, "rb\n"))
		rotate(stackb);
	else if (!ft_strcmp(read, "rr\n"))
		double_rotate(stacka, stackb);
	else if (!ft_strcmp(read, "rra\n"))
		reverse_rotate(stacka);
	else if (!ft_strcmp(read, "rrb\n"))
		reverse_rotate(stackb);
	else if (!ft_strcmp(read, "rrr\n"))
		double_reverse_rotate(stacka, stackb);
	else
		goodbye(read, stacka);
}

static void	moves_checker(t_Node *stacka, t_Node *stackb)
{
	char	*read;

	read = get_next_line(0);
	while (read)
	{
		applymoves(read, &stacka, &stackb);
		free(read);
		read = get_next_line(0);
	}
	free(read);
	if (stacka && isascending(stacka) && stackb == NULL)
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
		freelist(stackb);
	}
	freelist(stacka);
}

int	main(int ac, char **av)
{
	t_Node	*stacka;
	t_Node	*stackb;

	stacka = is_valid(ac, av);
	stackb = NULL;
	moves_checker(stacka, stackb);
}
