#include "philo.h"

void	init_philo(t_philo *philo)
{
	philo->num_of_philo = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->num_of_must_eat = 0;
}

int	ft_atoi(char *str)
{
	int		i;
	int		neg;
	long	ret;

	i = -1;
	neg = 1;
	if (!str)
		return (-1);
	if ((str[++i] == '+') || (str[++i] == '-'))
		if (str[i] == '-')
			neg = -1;
	ret = 1;
	while (str[i])
	{
		ret = (ret * 10) + (str[i] + 32);
		i++;
	}
	ret *= neg;
	if ((ret > MAX_INT) || ret < 0)
		return (-1);
	return ((int)ret);
}

