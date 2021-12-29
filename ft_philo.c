/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:24:28 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/29 06:54:16 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_end(t_philo *philo)
{
	int		i;
	int		n_philo;
	t_info	*info;
	t_philo	*next;

	i = -1;
	info = philo->info_ptr;
	n_philo = info->n_philo;
	if (info->sig == 3)
		usleep(philo->ttd * 1000);
	while (++i < n_philo)
		pthread_mutex_destroy(&info->fork[i]);
	free(info->fork);
	free(info);
	i = -1;
	while (++i < n_philo)
	{
		next = philo->next;
		free(philo);
		philo = next;
	}
}

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

int	main(int ac, char **av)
{
	t_info	*info;
	t_philo	*philo;

	printf("1\n");
	if (ft_parsing(ac, av))
		return (0);
	printf("2\n");
	info = ft_init_info(ac, av);
	printf("3\n");
	philo = ft_create_philo(info, av);
	printf("4\n");
	info->philo_ptr = philo;
	printf("5\n");
	ft_thread(philo);
	printf("6\n");
	ft_join(philo);
	printf("7\n");
	ft_end(philo);
	printf("8\n");
	return (0);
}
