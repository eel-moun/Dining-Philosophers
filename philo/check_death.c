/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:54:04 by eel-moun          #+#    #+#             */
/*   Updated: 2022/10/23 18:56:36 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printd(char *str, t_util *data, t_philo *philo)
{
	pthread_mutex_lock(&data->to_print);
	if (data->is_alive)
		printf("%lld ms %d %s\n", (get_time() - data->start), philo->id, str);
	data->is_alive = 0;
}

void	eprint(char *str, t_util *data)
{
	pthread_mutex_lock(&data->to_print);
	if (data->is_alive)
		printf("%s\n", str);
	data->is_alive = 0;
}

int	check_eating(t_philo *philos)
{
	int	i ;

	i = 0;
	while (i < philos->data->nop && philos[i].note >= philos[i].data->tepme)
		i++;
	if (i == philos->data->nop)
	{
		philos->data->all_ate = 1;
		return (1);
	}
	return (0);
}

int	check_death(t_philo *philos)
{
	int			i;

	while (!philos->data->all_ate)
	{
		i = 0;
		while (i < philos->data->nop && philos->data->is_alive)
		{
			pthread_mutex_lock(&philos->data->e_check);
			if ((get_time() - philos[i].lte) > philos->data->ttd)
			{
				printd("died", philos->data, &philos[i]);
				return (1);
			}
			pthread_mutex_unlock(&philos->data->e_check);
			usleep(100);
			i++;
		}
		if (philos->data->ac == 6)
		{
			if (check_eating(philos))
				return (eprint("philos ate enough", philos->data), 1);
		}
	}
	return (0);
}
