#include "../include/philo.h"
#include <unistd.h>

void	ready_to_eat(t_info *info, t_philo *philo)
{
	if (philo->info->total % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&(philo->info->mutex[philo->lf_idx]));
	pthread_mutex_lock(&(philo->info->mutex[philo->rf_idx]));
	philo->info->fork[philo->lf_idx] = philo->id;
	philo->info->fork[philo->rf_idx] = philo->id;
	philo->status = TAKE;
	print_status(get_time() - info->std_time, philo);
}

void	*do_philo(void *thread)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)thread;
	info = philo->info;
	while (1)
	{
		ready_to_eat(info, philo);
		usleep(200);
		if (info->die_flag == 1)
			break ;
		run_eat(info, philo);
		usleep(200);
		if (info->die_flag == 1)
			break ;
		run_sleep(info, philo);
		usleep(200);
		if (info->die_flag == 1)
			break ;
		run_think(info, philo);
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

	i = -1;
	now = 0;
	while (++i < info->total)
	{
		now = get_time() - philo->e_time;
		if (now > info->die)
		{
			info->die_flag = 1;
			print_status(now, philo);
			return (1);
		}
		if (philo[i].e_cnt == info->must_eat)
		{
			info->must_eat_cnt++;
			philo[i].e_cnt++;
		}
	}
	return (0);
}
