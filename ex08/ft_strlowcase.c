/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 04:06:07 by aasselma          #+#    #+#             */
/*   Updated: 2022/05/24 04:07:16 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
char	*ft_strupcase(char *str)
=======
<<<<<<< HEAD
char	*ft_strupcase(char *str)
=======
char	*ft_strlowcase(char *str)
>>>>>>> push C02 pool
>>>>>>> C01 pool push
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

/* int main()
{
    char fc[] = "HELLO WORLD&FROM INT MAIN";
<<<<<<< HEAD
    ft_strupcase(fc);
=======
<<<<<<< HEAD
    ft_strupcase(fc);
=======
    ft_strlowcase(fc);
>>>>>>> push C02 pool
>>>>>>> C01 pool push
    printf("%s", fc);
    return 0;
}*/
