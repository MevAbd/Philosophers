/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:02:00 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/29 22:52:41 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_join(t_philo *philo)
{
	int		i;
	t_philo	*cpy;

	i = philo->info_ptr->n_philo;
	cpy = philo;
	while (i)
	{
		pthread_join(cpy->t_id, NULL);
		cpy = cpy->next;
		i--;
	}
}

void	ft_thread(t_philo *philo)
{
	int		i;
	t_philo	*cpy;

	i = philo->info_ptr->n_philo;
	cpy = philo;
	while (i)
	{
		pthread_create(&cpy->t_id, NULL, (void *)&ft_loop, cpy);
		cpy = cpy->next;
		i--;
	}
}

t_philo	*ft_create_one(t_info *info, int i, char **av)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = i;
	philo->die = 0;
	philo->ttd = ft_atoi(av[2]);
	philo->tte = ft_atoi(av[3]);
	philo->tts = ft_atoi(av[4]);
	philo->info_ptr = info;
	philo->next = NULL;
	philo->stalk = 0;
	philo->verif = 0;
	return (philo);
}

t_philo	*ft_create_philo(t_info *info, char **av)
{
	t_philo	*philo;
	t_philo	*in;
	t_philo	*last;
	int		i;

	i = 0;
	philo = NULL;
	while (i < info->n_philo)
	{
		if (!philo)
			philo = ft_create_one(info, i + 1, av);
		else
		{
			in = ft_create_one(info, i + 1, av);
			ft_lstadd_back(&philo, in);
		}
		i++;
	}
	last = ft_lstlast(philo);
	last->next = philo;
	return (philo);
}
