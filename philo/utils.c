/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:55:11 by eel-moun          #+#    #+#             */
/*   Updated: 2022/10/23 17:28:56 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_errors(t_util data)
{
	if (data.nop <= 0 || data.ttd <= 0 || data.tte <= 0 || data.tts <= 0)
		return (write(2, "Argument not valid!\n", 20), 0);
	if (data.ac == 6 && data.tepme <= 0)
		return (write(2, "Error number of tepme!\n", 23), 0);
	if (data.nop < 1)
		return (write(2, "Error number of philosophers!\n", 30), 0);
	return (1);
}

int	check(int value, int r, char *str, int i)
{
	if (r == 1)
	{
		while (str[i])
		{
			if (!(str[i] >= '0' && str[i++] <= '9'))
				return (0);
		}
		return (value);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	signe;
	int	r;

	i = 0;
	nb = 0;
	signe = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	r = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = 1;
		nb = (str[i++] - 48) + (nb * 10);
	}
	return (check(nb * signe, r, (char *)str, i));
}

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
