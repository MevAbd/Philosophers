/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:07:57 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 14:11:57 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_verif_nb(int ac, char **av, int nb, int i)
{
	char	*str;

	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		str = ft_itoa(nb, 0);
		if (ft_strncmp(str, av[i], ft_strlen(av[i])) != 0)
		{
			write(1, "Error\nIs not a number\n", 22);
			free(str);
			return (1);
		}
		if ((i == 1 || i == 2 || i == 5) && (nb <= 0))
		{
			printf("%s\n", "Not negative number for :");
			printf("%s\n", "[nb_philo][time_to_die][nb_eat]");
			free(str);
			return (1);
		}
		free(str);
		i++;
	}
	return (0);
}

int	ft_parsing(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
	{
		printf("%s\n", "Error\n[nb_philo]\n[time_to_die]\n[time_to_eat]");
		printf("%s\n", "[time_to_sleep]\n[nb_eat]");
		return (1);
	}
	return (ft_verif_nb(ac, av, 0, 1));
}
