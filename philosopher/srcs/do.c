#include "../include/philo.h"
#include <unistd.h>

void	ready_to_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->info->mutex[philo->lf_idx]);
		pthread_mutex_lock(&philo->info->mutex[philo->rf_idx]);
	}
	else
	{
		pthread_mutex_lock(&philo->info->mutex[philo->rf_idx]);
		pthread_mutex_lock(&philo->info->mutex[philo->lf_idx]);
	}
	philo->info->fork[philo->lf_idx] = philo->id;
	philo->info->fork[philo->rf_idx] = philo->id;
	philo->status = TAKE;
	print_status(get_time() - philo->info->std_time, philo);
}

void	*do_philo(void *thread)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)thread;
	info = philo->info;
	if (philo->id % 2 == 0)
		usleep(50);
	while (1)
	{
		ready_to_eat(philo);
		if (info->die_flag == 1)
			break ;
		run_eat(philo);
		if (info->die_flag == 1)
			break ;
		run_sleep(philo);
		if (info->die_flag == 1)
			break ;
		run_think(philo);
	}
	return (thread);
}

int	check_must_eat(t_info *info, t_philo *philo)
{
	int	i;

	if (info->must_eat && (info->must_eat_cnt == info->total))
		return (1);
	i = -1;
	while (++i < info->total)
	{
		if (philo[i].e_cnt == info->must_eat)
		{
			info->must_eat_cnt++;
			philo[i].e_cnt++;
		}
	}
	return (0);
}

int	check_is_die(t_info *info, t_philo *philo)
{
	int					i;
	unsigned long long	now;
	unsigned long long present;

	i = -1;
	now = 0;
	while (++i < info->total)
	{
		present = get_time();
		now = present - philo[i].e_time;
		if (now > info->die)
		{
			printf("now : %llu, present : %llu, etime : %llu\n", now, present, philo[i].e_time);
			info->die_flag = 1;
			philo[i].status = DIE;
			print_status(now, &philo[i]);
			return (1);
		}
		if (philo[i].e_cnt == info->must_eat)
		{
			info->must_eat_cnt++;
			philo[i].e_cnt++;
		}
		usleep(50);
	}
	return (0);
}
