/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:59:16 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/04 14:15:14 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description				The C library function void *calloc(size_t nitems, size_t size) allocates the requested memory and returns a pointer to it. The difference in malloc and calloc is that malloc does not set the memory to zero where as calloc sets allocated memory to zero.

	Prototype:				void *calloc(size_t nitems, size_t size)

	Parameters				nitems − This is the number of elements to be allocated.
							size − This is the size of elements.

	Return Value			This function returns a pointer to the allocated memory, or NULL if the request fails.
	
 */

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size > __SIZE_MAX__ / count)			// check to protect memory usage (memory leaks, segmentation fault ....), checks the size needed is not more than the available size to be shared 
		return (NULL);
	p = malloc (count * size);
	if (!p)
		return (NULL);
	if (p)
		ft_bzero(p, count * size);
	return (p);
}
