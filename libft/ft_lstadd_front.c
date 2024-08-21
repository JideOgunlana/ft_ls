/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:14:21 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/02 18:47:37 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 			ft_lstadd_front

Prototype 				void ft_lstadd_front(t_list **lst, t_list *new);

Parameters 				lst: The address of a pointer to the first link of a list.

						new: The address of a pointer to the node to be added to the list.
						
Return value 			None

External functs. 		None

Description 			Adds the node ’new’ at the beginning of the list. */

#include "../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	ft_lstnew(new);
	new->next = *lst;
	*lst = new;
}