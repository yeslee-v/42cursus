#include "philo.h"

int	init_philo(int ac, char **av, t_philo *philo)
{
	memset(philo, 0, sizeof(t_philo));
	philo->num = ft_atoi(av[1]);
	if ((philo->num < 0) || (philo->num > 200))
	{
		printf("num of philosophers is invalid\n");
		return (1);
	}
	philo->die = ft_atoi(av[2]);
	philo->eat = ft_atoi(av[3]);
	philo->sleep = ft_atoi(av[4]);
	if ((philo->die < 60) || (philo->eat < 60) || (philo->sleep < 60))
	{
		printf("time is under than 60\n");
		return (1);
	}
	if (ac == 5)
	{
		philo->must_eat = ft_atoi(av[5]);
		if (philo->must_eat < 0)
		{
			printf("'num of must eat' is invalid\n");
			return (1);
		}
	}
	return (0);
}


