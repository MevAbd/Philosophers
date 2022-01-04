/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:04:24 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 19:06:43 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "struct.h"

int		ft_parsing(int ac, char **av);
t_info	*ft_fill_info(int ac, char **av);
t_philo	*ft_fill_philo(t_info *info);
#endif
