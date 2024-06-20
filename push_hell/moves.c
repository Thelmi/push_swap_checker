/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:55:36 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/20 14:54:48 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	swap(t_Node *list)
{
	int	swp;

	if (list == NULL || list->next == NULL)
		return ;
	swp = list -> data;
	list -> data = list -> next -> data;
	list -> next -> data = swp;
}

void	double_swap(t_Node *listA, t_Node *listB)
{
	if (listA == NULL || listA->next == NULL)
		swap(listB);
	else if (listB == NULL || listB->next == NULL)
		swap(listA);
	else
	{
		swap(listA);
		swap(listB);
	}
}

void	push(t_Node **listA, t_Node **listB)
{
	t_Node	*tmp;

	if (*listA == NULL)
		return ;
	tmp = *listA;
	*listA = (*listA)-> next;
	tmp -> next = *listB;
	*listB = tmp;
}
