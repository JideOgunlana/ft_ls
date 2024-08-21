/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:41:08 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 13:19:05 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//Function name ft_substr

//Prototype 	char *ft_substr(char const *s, unsigned int start, size_t len);

// Parameters 	s: The string from which to create the substring.
//				start: The start index of the substring in the string ’s’.
//				len: The maximum length of the substring.

//Return value The substring. NULL if the allocation fails.

//External functs. malloc

//Description Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (len > (size_t)ft_strlen(s))
		len = ft_strlen(s);
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while ((s[i] != '\0') && (j != len))
	{
		while (i == start && j < len)
		{
			substr[j] = s[j + i];
			j++;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

/* 
int	main()
{
	char ans[100];

	printf("%s",ft_substr("We think in generalities, but we live in details.", 3, 5));
	// printf("%s", ans));
	return (0);
}
 */