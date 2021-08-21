#include "philo.h"

void	ready_to_eat(t_philo *philo)
{
	if (philo->info->total % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&(philo->info->mutex[philo->lf_idx]));
	pthread_mutex_lock(&(philo->info->mutex[philo->rf_idx]));
	philo->status = TAKE;
	print_status(get_time() - philo->info->std_time, philo);
}
