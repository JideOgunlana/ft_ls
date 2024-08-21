/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:05:08 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/03 15:47:35 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name			ft_lstdelone

Prototype				void ft_lstdelone(t_list *lst, void (*del)(void*));

Parameters 				lst: The node to free 
						del: The address of the function used to delete the content.
						
Return value 			None

External functs. 		free

Description 			Takes as a parameter a node and frees the memory of the node’s content using the function ’del’ given as a parameter and free the node. The memory of ’next’ must not be freed. 
*/

#include "../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}