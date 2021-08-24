#include "philo.h"

void	ready_to_eat(t_philo *philo)
{
	if (philo->info->total % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&(philo->info->mutex[philo->lf_idx]));
	pthread_mutex_lock(&(philo->info->mutex[philo->rf_idx]));
	philo->info->fork[philo->lf_idx] = philo->num;
	philo->info->fork[philo->rf_idx] = philo->num;
	philo->status = TAKE;
	print_status(get_time() - philo->info->std_time, philo);
}

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
		if (info->die_flag == 1)
			break ;
		run_sleep(philo);
		if (info->die_flag == 1)
			break ;
		run_think(philo);
		if (info->die_flag == 1)
			break ;
	}
	return (thread);
}

/*
 *void	do_monitor(t_philo *philo)
 *{
 *    
 *}
 */
