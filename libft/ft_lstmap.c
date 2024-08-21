/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:18:21 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/04 02:23:45 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*Function name				ft_lstmap

Prototype					t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *));

Parameters 					lst: The address of a pointer to a node. 
							f: The address of the function used to iterate on the list.
							del: The address of the function used to delete the content of a node if needed.
							
Return value 				The new list. NULL if the allocation fails.

External 					functs. malloc, free

Description 				Iterates the list ’lst’ and applies the function ’f’ on the content of each node. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of a node if needed. 
*/

#include "../includes/libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list *new;
	t_list	*ptr;
	t_list	*head;

	ptr = lst;
	if (!lst)
		return NULL;
	new = ft_lstnew(f(lst->content));
	head = new;
	while (ptr->next)
	{
		ptr = ptr->next;
		new->next = ft_lstnew(f(ptr->content));
		if (!new->next)
		{
			lst = NULL;
			del(NULL);
			// ft_lstclear(&lst, del);
			// return NULL;
		}
		new = new->next;
	}
	return (head);
}
