#include "../include/philo.h"

int	intro_philo(int ac, char **av, t_info *info)
{
	int			i;
	int			ret;
	t_philo		*philo;

	if (init_info(ac, av, info))
		return (1);
	if (init_philo(info, &philo))
		return (1);
	info->thread = malloc(sizeof(pthread_t) * info->total);
	if (!(info->thread))
	{
		printf("malloc error\n");
		return (1);
	}
	i = -1;
	ret = 0;
	while (++i < info->total)
	{
		ret = pthread_create(&(info->thread[i]), NULL, do_philo, &philo[i]);
		if (ret == -1)
		{
			printf("Fail to make thread\n");
			return (1);
		}
		pthread_detach(info->thread[i]);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_info	info;

	if ((ac < 5) || (ac > 6))
	{
		printf("ac is invalid\n");
		return (1);
	}
	intro_philo(ac, av, &info);
	/*
	 *do_monitor(philo->;
	 */
	// mutex
	return (0);
}
