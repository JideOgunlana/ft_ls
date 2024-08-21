/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:09:39 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/03 16:17:34 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 				ft_lstiter

Prototype 					void ft_lstiter(t_list *lst, void (*f)(void *));

Parameters 					lst: The address of a pointer to a node.
							f: The address of the function used to iterate on the list.
							
Return value 				None

External functs. 			None

Description Iterates the list ’lst’ and applies the function ’f’ on the content of each node.
*/

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return;
	while(lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}