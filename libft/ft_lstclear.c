/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:48:34 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/03 16:05:11 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name				ft_lstclear

Prototype 					void ft_lstclear(t_list **lst, void (*del)(void*));

Parameters					lst: The address of a pointer to a node.
							del: The address of the function used to delete the content of the node.
							
Return value 				None

External functs. 			free

Description 				Deletes and frees the given node and every successor of that node, using the function ’del’ and free(3). Finally, the pointer to the list must be set to NULL.
*/

#include "../includes/libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst == NULL)
	{
		del((*lst)->content);
		free(*lst);
	}
	else
	{
		while (*lst)
		{
			del((*lst)->content);
			free(*lst);
			(*lst) = (*lst)->next;
		}
	}
}