/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:55:20 by eel-moun          #+#    #+#             */
/*   Updated: 2022/10/23 18:58:46 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philos, t_util data)
{
	int	i;

	i = 0;
	while (i < data.nop)
		pthread_mutex_destroy(&data.forks[i++]);
	pthread_mutex_destroy(&data.to_print);
	pthread_mutex_destroy(&data.e_check);
	free(philos);
	free(data.forks);
}

int	init(t_util *data)
{
	int	i;

	i = 0;
	while (i < data->nop)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL))
			return (1);
	}
	if (pthread_mutex_init(&data->to_print, NULL))
		return (1);
	if (pthread_mutex_init(&data->e_check, NULL))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_util	data;
	t_philo	*philos;
	int		i;

	i = 0;
	if (ac != 5 && ac != 6)
		return (write(2, "error\n", 22), 0);
	fill(&data, ac, av);
	if (!check_errors(data))
		return (0);
	philos = malloc(sizeof(t_philo) * data.nop);
	if (!philos)
		return (0);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.nop);
	if (!data.forks)
		return (free(philos), 0);
	if (init(&data))
		return (write(2, "error\n", 18), 0);
	if (!philo_filler(philos, &data))
		return (0);
	if (check_death(philos))
		return (free_all(philos, data), 0);
}
