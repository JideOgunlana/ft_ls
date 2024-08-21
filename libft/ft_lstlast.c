/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:06:43 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/02 19:18:53 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function				nameft_lstlast

Prototype				t_list *ft_lstlast(t_list *lst);

Parameters				lst: The beginning of the list.

Return value			Last node of the list

External functs			None

Description 			Returns the last node of the list
*/

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst->next);
		lst = lst->next;
	}
	return (lst);
}