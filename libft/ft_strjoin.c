/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:23:28 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:52:20 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
Function name 				ft_strjoin

Prototype 					char *ft_strjoin(char const *s1, char const *s2);

Parameters 					s1: The prefix string.
							s2: The suffix string.

Return value 				The new string.	NULL if the allocation fails.

External functs.: 			malloc

Description 				Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	newstr = (char *) malloc(sizeof(*s1) * (ft_strlen(s1)+ ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
	{
		newstr[i] = s1[i];
	}
	j = -1;
	while (s2[++j] != '\0')
	{
		newstr[i++] = s2[j];
	}
	newstr[i] = '\0';
	return (newstr);
}

/* int main()
{
	printf(":%s:", ft_strjoin("g", "ege"));
    return (0);
} */