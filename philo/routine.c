/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:55:04 by eel-moun          #+#    #+#             */
/*   Updated: 2022/10/23 18:57:32 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char *str, t_util *data, t_philo *philo)
{	
	pthread_mutex_lock(&data->to_print);
	if (data->is_alive)
		printf("%lld ms %d %s\n", (get_time() - data->start), philo->id, str);
	pthread_mutex_unlock(&data->to_print);
}

void	ft_usleep(long long tts)
{
	long long	time_end;

	time_end = (get_time() + tts);
	while (get_time() < time_end)
	{
		usleep(50);
	}
}

void	eating(t_philo *philos)
{
	int	i;

	i = ((philos->id) % philos->data->nop);
	pthread_mutex_lock(&philos->data->forks[philos->id - 1]);
	print("has taken his 1st fork", philos->data, philos);
	pthread_mutex_lock(&philos->data->forks[i]);
	print("has taken his 2nd fork", philos->data, philos);
	pthread_mutex_lock(&philos->data->e_check);
	print("is eating", philos->data, philos);
	philos->lte = get_time();
	pthread_mutex_unlock(&philos->data->e_check);
	ft_usleep(philos->data->tte);
	philos->note++;
	pthread_mutex_unlock(&philos->data->forks[philos->id - 1]);
	pthread_mutex_unlock(&philos->data->forks[i]);
}

void	*routine(void *philo)
{
	t_philo		*philos;

	philos = (t_philo *) philo;
	if (!(philos->id % 2))
		usleep(3000);
	while (philos->data->is_alive)
	{
		eating(philos);
		if (philos->data->all_ate || !philos->data->is_alive)
			break ;
		print("is sleeping", philos->data, philos);
		ft_usleep(philos->data->tts);
		if (philos->data->all_ate || !philos->data->is_alive)
			break ;
		print("is thinking", philos->data, philos);
	}
	return (0);
}
