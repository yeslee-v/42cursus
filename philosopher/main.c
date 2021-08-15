#include "philo.h"

int main(int ac, char **av)
{
	t_thread thr;
	struct timeval start;
	struct timeval end;

	if ((ac < 4) || (ac > 5))
	{
		printf("ac is invalid\n");
		return (1);
	}
	init_philo(thr.philo);
	while (*av)
	{
		if (ft_atoi(*av) < 0)
		{
			printf("arg is invalid\n");
			return (1);
		}
		av++;
	}
	gettimeofday(&start, NULL);
	thr.philo->num_of_philo = ft_atoi(av[1]);
	thr.philo->time_to_die = ft_atoi(av[2]);
	thr.philo->time_to_eat = ft_atoi(av[3]);
	thr.philo->time_to_sleep = ft_atoi(av[4]);
	thr.thread = malloc(sizeof(pthread_t) * thr.philo->num_of_philo);
	if (!thr.thread)
	{
		printf("malloc error\n");
		return (1);
	}
	int i = -1;
	while (++i < thr.philo->num_of_philo)
	{
		// make thread
		// thread < -1 -> error
	}
	return (0);
}
