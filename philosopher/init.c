#include "philo.h"

int	init_info(int ac, char **av, t_info *info)
{
	memset(info, 0, sizeof(t_info));
	info->num = ft_atoi(av[1]);
	if ((info->num < 0) || (info->num > 200))
	{
		printf("num of infosophers is invalid\n");
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
			printf("'num of must eat' is invalid\n");
			return (1);
		}
	}
	return (0);
}

void	init_philo(t_philo *philo)
{
	philo->lf_idx = -1;
	philo->rf_idx = -1;
	philo->std_time = get_time();
	philo->thread = NULL;
}
