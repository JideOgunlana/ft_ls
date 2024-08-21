/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 04:47:11 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/04 13:00:27 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
	Description:			The C library function int atoi(const char *str) converts the string argument str to an integer (type int)

	Prototype:				int atoi(const char *str)

	Parameters:				str − This is the string representation of an integral number.

	Return Value:			This function returns the converted integral number as an int value. If no valid conversion could be performed, it returns zero.

 */

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13)) // check if the str has a space, horizontal or vertical tabs, e.t.c (i.e for control characters / Non-printing character)
		str++;
	if (*str == '-')								// check to know if the str should become a negative number
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')				// check to know the string exists in the range of a valid integral number
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}



/* int main ()
{
	char a[] = "1234"; // 1234
	char b[] = "3hello5"; // 3
	char c[] = "+-2hi mate! 42"; // 0
	printf("%d\n", ft_atoi(a));
	printf("%d\n", ft_atoi(b));
	printf("%d", ft_atoi(c));
	return 0;
} */

