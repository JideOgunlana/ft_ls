/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:56:23 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/02 19:02:36 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Function name			ft_lstsize

Prototype 				int ft_lstsize(t_list *lst);

Parameters 				lst: The beginning of the list.

Return value 			The length of the list

External functs. 		None

Description 			Counts the number of nodes in a list */
#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		node_count;

	current = lst;
	node_count = 0;
	while (current)
	{
		current = current->next;
		node_count++;
	}
	return (node_count);
}