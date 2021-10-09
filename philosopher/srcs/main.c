#include "../include/philo.h"

void	intro_philo(int ac, char **av, t_info *info)
{
	int			i;
	int			ret;
	t_philo		*philo;

	if (init_info(ac, av, info) || init_philo(info, &philo))
		return ;
	i = -1;
	ret = 0;
	while (++i < info->total)
	{
		usleep(50);
		ret = pthread_create(&(info->thread)[i], NULL, do_philo, &philo[i]);
		if (ret == -1)
		{
			printf("Fail to make thread\n");
			return ;
		}
		pthread_detach(info->thread[i]);
	}
	while (1)
	{
		if (check_must_eat(info, philo) || check_is_die(info, philo))
			break ;
	}
	free(philo);
}

int	main(int ac, char **av)
{
	int		i;
	t_info	info;

	i = -1;
	if ((ac < 5) || (ac > 6))
	{
		printf("ac is invalid\n");
		return (1);
	}
	intro_philo(ac, av, &info);
	free(info.fork);
	free(info.thread);
	ft_pthread_mutex_destroy(&info);
	return (0);
}
