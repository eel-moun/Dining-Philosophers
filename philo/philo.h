/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:55:17 by eel-moun          #+#    #+#             */
/*   Updated: 2022/10/23 20:15:09 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_util{
	int				ac;
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				tepme;
	int				is_alive;
	int				all_ate;
	long long		start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	to_print;
	pthread_mutex_t	e_check;
}	t_util;

typedef struct s_philo{
	int			id;
	long long	lte;
	int			note;
	pthread_t	th;
	t_util		*data;
}	t_philo;

void		*routine(void *philo);
int			ft_check_death(t_philo philos);
void		fill(t_util *data, int ac, char **av);
int			philo_filler(t_philo *philos, t_util *data);
int			ft_atoi(const char *str);
long long	get_time(void);
int			check_death(t_philo *philos);
int			check_eating(t_philo *philos);
void		ft_usleep(long long tts);
void		eprint(char *str, t_util *data);
int			check_errors(t_util data);
void		print(char *str, t_util *data, t_philo *philo);
#endif