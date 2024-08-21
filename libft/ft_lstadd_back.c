/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:52:01 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/02 21:03:26 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name			ft_lstadd_back

Prototype				void ft_lstadd_back(t_list **lst, t_list *new);

Parameters lst: 		The address of a pointer to the first link of a list.
				
						new: The address of a pointer to the node to be added to the list.

Return value 			None

External functs. 		None

Description 			Adds the node ’new’ at the end of the list.
*/

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if(*lst)
	{
		current = ft_lstlast(*lst);
		current->next = new;
	}
	else
		(* lst) = new;
}