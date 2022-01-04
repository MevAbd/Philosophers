/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:32:03 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 22:49:39 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <stdlib.h>
# include "struct.h"

int		ft_atoi(char const *s);
int		ft_strncmp(char const *s1, char const *s2, size_t n);

char	*ft_itoa(int n, unsigned int j);

size_t	ft_strlen(const char *str);

t_philo	*ft_lstlast(t_philo *philo);

#endif
