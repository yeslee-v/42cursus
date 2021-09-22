#include "../include/philo.h"
#include <pthread.h>

void	run_eat(t_philo *philo)
{
	if ((philo->info->fork[philo->lf_idx] == philo->id) && \
			(philo->info->fork[philo->rf_idx] == philo->id))
	{
		philo->e_time = get_time();
		philo->status = EAT;
		philo->e_cnt++;
		print_status(get_time() - philo->info->std_time, philo);
	}
	custom_usleep(philo->info->eat);

}

void	run_sleep(t_philo *philo)
{
	philo->status = SLEEP;
	print_status(get_time() - philo->info->std_time, philo);
	philo->info->fork[philo->lf_idx] = -1;
	philo->info->fork[philo->rf_idx] = -1;
	pthread_mutex_unlock(&philo->info->mutex[philo->lf_idx]);
	pthread_mutex_unlock(&philo->info->mutex[philo->rf_idx]);
	custom_usleep(philo->info->sleep);
}

void	run_think(t_philo *philo)
{
	philo->status = THINK;
	print_status(get_time() - philo->info->std_time, philo);
}

void	print_status(int time, t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	printf("%dms %d ", time, (philo->id + 1));
	if (philo->status == TAKE)
		printf("has taken a fork\n");
	else if (philo->status == EAT)
		printf("is eating\n");
	else if (philo->status == SLEEP)
		printf("is sleeping\n");
	else if (philo->status == THINK)
		printf("is thinking\n");
	else if (philo->status == DIE)
		printf("died\n");
	pthread_mutex_unlock(&philo->info->print_mutex);
}
