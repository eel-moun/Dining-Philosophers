/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:55:08 by eel-moun          #+#    #+#             */
/*   Updated: 2022/10/23 17:48:31 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill(t_util *data, int ac, char **av)
{
	data->ac = ac;
	data->nop = ft_atoi(av[1]);
	data->ttd = ft_atoi(av[2]);
	data->tte = ft_atoi(av[3]);
	data->tts = ft_atoi(av[4]);
	if (ac == 6)
		data->tepme = ft_atoi(av[5]);
	data->is_alive = 1;
	data->all_ate = 0;
}

int	philo_filler(t_philo *philos, t_util *data)
{
	int	i;

	i = 0;
	data->start = get_time();
	while (i < data->nop)
	{		
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].note = 0;
		if (pthread_create(&philos[i].th, NULL, &routine, philos + i))
			return (eprint("pthread_create error!", data), 0);
		philos[i].lte = get_time();
		pthread_detach(philos[i].th);
		i++;
	}
	return (1);
}
