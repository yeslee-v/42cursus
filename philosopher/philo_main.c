#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int ret;

	i = -1;
	if (!str || (str[++i] == '-'))
		return (-1);
	ret = 1;
	while (str[++i])
		ret *= (str[i] + 32);
	return (ret);
}

void	init_philo(t_philo *philo)
{
	philo->num_of_philo = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
}

int main(int ac, char **av)
{
	t_philo philo;

	if (ac != 5)
	{
		write(2, "error\n", 6);
		return (1);
	}
	init_philo(&philo);
	philo.num_of_philo = ft_atoi(av[1]);
	philo.time_to_die = ft_atoi(av[2]);
	philo.time_to_eat = ft_atoi(av[3]);
	philo.time_to_sleep = ft_atoi(av[4]);
	return (0);
}
