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
	thr.philo->num = ft_atoi(av[1]);
	if (thr.philo->num > 200)
	{
		printf("philosopher is over than 200\n");
		return (1);
	}
	thr.philo->die = ft_atoi(av[2]);
	thr.philo->eat = ft_atoi(av[3]);
	thr.philo->sleep = ft_atoi(av[4]);
	if ((thr.philo->eat < 60) || (thr.philo->sleep < 60) || (thr.philo->die < 60))
	{
		printf("time is under than 60\n");
		return (1);
	}
	thr.thread = malloc(sizeof(pthread_t) * thr.philo->num);
	if (!thr.thread)
	{
		printf("malloc error\n");
		return (1);
	}
	int i = -1;
	while (++i < thr.philo->num)
	{
		// make thread
		// thread < -1 -> error
	}
	return (0);
}
