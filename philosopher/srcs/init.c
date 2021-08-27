#include "../include/philo.h"

int	init_info(int ac, char **av, t_info *info)
{
	int i;

	memset(info, 0, sizeof(t_info));
	info->fork = malloc(sizeof(int *) * info->total);
	memset(info->fork, -1, sizeof(t_info));
	info->total = ft_atoi(av[1]);
	if ((info->total < 0) || (info->total > 200))
	{
		printf("total of infosophers is invalid\n");
		return (1);
	}
	info->die = ft_atoi(av[2]);
	info->eat = ft_atoi(av[3]);
	info->sleep = ft_atoi(av[4]);
	if ((info->die < 60) || (info->eat < 60) || (info->sleep < 60))
	{
		printf("time is under than 60\n");
		return (1);
	}
	if (ac == 5)
	{
		info->must_eat = ft_atoi(av[5]);
		if (info->must_eat < 0)
		{
			printf("'total of must eat' is invalid\n");
			return (1);
		}
	}
	info->std_time = get_time();
	info->mutex = malloc(sizeof(pthread_mutex_t) * info->total);
	i = -1;
	while (++i < info->total)
		pthread_mutex_init(&(info->mutex)[i], NULL);
	return (0);
}

int	init_philo(t_info *info, t_philo **philo)
{
	int	i;

	printf("init_philo: here\n");
	memset(info, 0, sizeof(t_info));
	i = -1;
	*philo = malloc(sizeof(t_philo) * info->total);
	if (!(*philo))
	{
		printf("philo malloc error\n");
		return (1);
	}
	while (++i < info->total)
	{
		if (i == 0)
			(*philo)[i].lf_idx = info->total - 1;
		else
			(*philo)[i].lf_idx = i - 1;
		(*philo)[i].rf_idx = i;
		(*philo)[i].thread = NULL;
	}
	return (0);
}
