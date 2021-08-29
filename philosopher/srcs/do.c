#include "../include/philo.h"
#include <unistd.h>

void	ready_to_eat(t_philo *philo)
{
	if (philo->info->total % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&(philo->info->mutex[philo->lf_idx]));
	pthread_mutex_lock(&(philo->info->mutex[philo->rf_idx]));
	philo->info->fork[philo->lf_idx] = philo->id;
	philo->info->fork[philo->rf_idx] = philo->id;
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
		usleep(100);
		printf("die: %d\n", info->die_flag);
		if (info->die_flag == 1)
			break ;
		printf("hi\n");
		run_eat(philo);
		usleep(100);
		if (info->die_flag == 1)
			break ;
		run_sleep(philo);
		usleep(100);
		if (info->die_flag == 1)
			break ;
		run_think(philo);
		usleep(100);
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
