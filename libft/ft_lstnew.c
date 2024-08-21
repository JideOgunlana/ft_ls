/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:41:42 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/30 21:36:28 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
Function name			ft_lstnew

Prototype				t_list *ft_lstnew(void *content)

Parameters 				content:The content to create the node with.

Return value 			The new node

External functs. 		malloc

Description 			Allocates (with malloc(3)) and returns a new node. The member variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.

*/

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if(!new)
		return 0;
	new->content = content;
	new->next = 0;
	return(new);
}