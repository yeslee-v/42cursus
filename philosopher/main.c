#include "philo.h"

void	*do_philo(void *philo)
{
	int i;
	int	ret;

	i = -1;
	ret = 0;
	while (++i < arg->info->num)
	{
		ret = pthread_mutex_init(arg->thread[i], NULL);
		if (ret < 0)
		{
			printf("fail to make mutex\n");
			return ;
		}

	}
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
	init_philo(philo);
	if (init_info(ac, av, philo->info))
		return (1);
	philo->thread = malloc(sizeof(pthread_t) * philo->info->num);
	if (!(philo->thread))
	{
		printf("malloc error\n");
		return (1);
	}
	i = -1;
	ret = 0;
	while (++i < philo->info->num)
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
