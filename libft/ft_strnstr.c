/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:23:13 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 13:12:33 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description:			The strnstr function locates the first occurrence of the null-terminated string \c little in the string \c big, where not more than \c len characters are searched

	The strnstr() function locates the first occurrence of the null-terminated string needle in the string haystack, where not more than len characters are searched.  Characters that appear after a `\0' character are not searched.  Since the strnstr() function is a FreeBSD specific API, itshould only be used when portability is not a concern.

	Prototype				char strnstr (const char *big, const char *little, size_t len)

	Return values			If needle is an empty string, haystack is returned; if needle occurs nowhere in haystack, NULL is returned; otherwise a pointer to the first character of the first occurrence of needle is returned.
	
 */

char	*ft_strnstr(const char *h, const char *ne, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	temp;

	i = 0;
	if (ne[0] == '\0')
		return ((char *) h);
	while ((i < len) && (h[i] != '\0'))
	{
		k = i;
		j = 0;
		while (ne[j] == h[k]
			&& (j < (unsigned int)ft_strlen(ne)) && (k < len) && (ne[j] != '\0'))
		{
			if (j == 0)
				temp = k;
			if (j == (unsigned int)ft_strlen(ne) - 1)
				return ((char *) &h[temp]);
			j++;
			k++;
		}
		i++;
	}
	return (NULL);
}

/* int main()
{
    char hay[] = "I w will do will anything";
    char need[] = "will d";
    char *ret;

    ret = ft_strnstr(hay, need, 10);
    printf("%s", ret);
    return 0;
} */

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int n)
{
	unsigned char* ph;
	unsigned char* pn;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	unsigned int pn_len;
	unsigned int temp;

	ph = (unsigned char*) haystack;
	pn = (unsigned char*) needle;
	pn_len = strlen(needle);
	i = 0;
	if(pn[0] == '\0')
		return (char *) haystack;
	while ((i < n))
	{
		k = i;
		j = 0;
		while (pn[j] == ph[k] && (j <= pn_len) && (k < n))
		{
			if(j == 0)
				temp = k;
			if(j == pn_len - 1)
				return (char *) &ph[temp];
			j++;
			k++;
		}
		i++;
	}
	return NULL;
}
 */


/* #include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	temp;

	i = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while ((i < n) && (haystack[i] != '\0'))
	{
		k = i;
		j = 0;
		while (needle[j] == haystack[k]
			&& (j < strlen(needle)) && (k < n) && (needle[j] != '\0'))
		{
			if (j == 0)
				temp = k;
			if (j == strlen(needle) - 1)
				return ((char *) &haystack[temp]);
			j++;
			k++;
		}
		i++;
	}
	return (NULL);
}
 */