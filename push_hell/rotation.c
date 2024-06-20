/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:34:58 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/20 14:58:28 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	rotate(t_Node **list)
{
	t_Node	*first;
	t_Node	*last;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	first = *list;
	last = lastnode(*list);
	*list = first -> next;
	first -> next = NULL;
	last -> next = first;
}

void	double_rotate(t_Node **listA, t_Node **listB)
{
	if (*listA == NULL || (*listA)->next == NULL)
		rotate(listB);
	else if (*listB == NULL || (*listB)->next == NULL)
		rotate(listA);
	else
	{
		rotate(listA);
		rotate(listB);
	}
}

void	reverse_rotate(t_Node **list)
{
	t_Node	*tmp;
	t_Node	*last;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	last = lastnode(*list);
	while (tmp->next->next != NULL)
		tmp = tmp -> next;
	tmp -> next = NULL;
	last -> next = *list;
	*list = last;
}

void	double_reverse_rotate(t_Node **listA, t_Node **listB)
{
	if (*listA == NULL || (*listA)->next == NULL)
		reverse_rotate(listB);
	else if (*listB == NULL || (*listB)->next == NULL)
		reverse_rotate(listA);
	else
	{
		reverse_rotate(listA);
		reverse_rotate(listB);
	}
}
