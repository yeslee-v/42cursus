#include "philo.h"

void	*do_philo(void *thread)
{
	t_info	*info;
	t_philo *philo;

	philo = (t_philo *)thread;
	info = philo->info;
	while (1)
	{
		ready_to_eat(philo);
		if (info->die_flag == 1)
			break ;
		run_eat(philo);
		/*
		 *if (info->die_flag == 1)
		 *    break ;
		 *run_sleep(philo);
		 *if (info->flag == 1)
		 *    break ;
		 *run_think(philo);
		 *if (info->flag == 1)
		 *    break ;
		 */
	}
	return (thread);
}

int main(int ac, char **av)
{
	int			i;
	int			ret;
	t_philo		*philo;

	if ((ac < 4) || (ac > 5))
	{
		printf("ac is invalid\n");
		return (1);
	}
	if (init_philo(philo->info, &philo) || init_info(ac, av, philo->info))
		return (1);
	philo->thread = malloc(sizeof(pthread_t) * philo->info->total);
	if (!(philo->thread))
	{
		printf("malloc error\n");
		return (1);
	}
	i = -1;
	ret = 0;
	while (++i < philo->info->total)
	{
		ret = pthread_create(&(philo->thread[i]), NULL, do_philo, &philo[i]);
		if (ret == -1)
		{
			printf("Fail to make thread\n");
			return (1);
		}
	}
	return (0);
}
