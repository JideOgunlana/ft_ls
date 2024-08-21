/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:52:26 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 13:17:22 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Function name:				ft_strtrim
	
	Prototype 					char *ft_strtrim(char const *s1, char const *set);
	
	Parameters 					s1: The string to be trimmed.
								set: The reference set of characters to trim.
								
	Return value 				The trimmed string.NULL if the allocation fails.
	
	External functs. 			malloc
	
	Description 				Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.
 */

static unsigned int	ft_b(char const *s1, char const *set)
{
	unsigned int	temp_begin;
	unsigned int	index;
	int				i;

	i = 0;
	temp_begin = 0;
	while (s1[i] != '\0')
	{
		index = temp_begin;
		if (ft_strchr(set, s1[i++]))
			temp_begin++;
		if (temp_begin == index)
			break ;
	}
	return (temp_begin);
}

static unsigned int	ft_e(char const *s1, char const *set)
{
	unsigned int	temp_end;
	unsigned int	index;
	int				i;

	i = ft_strlen(s1) - 1;
	temp_end = ft_strlen(s1) - 1;
	while ((i >= 0))
	{
		index = temp_end;
		if (ft_strchr(set, s1[i--]))
			temp_end--;
		if (temp_end == index)
			break ;
	}
	return (temp_end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;

	if (!s1)
		return (0);
	str = ft_substr(s1, ft_b(s1, set), ft_e(s1, set) - ft_b(s1, set) + 1);
	if (!str)
		return (NULL);
	return (str);
}

/* int main()
{
	printf(":%s:", ft_strtrim("b   b bddasd    ddasdf", "bf "));
	return (0);
} */