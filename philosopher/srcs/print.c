#include "../include/philo.h"
#include <pthread.h>

void	run_eat(t_info *info, t_philo *philo)
{
	if ((philo->info->fork[philo->lf_idx] == philo->id) && \
			(philo->info->fork[philo->rf_idx] == philo->id))
	{
		philo->e_time = get_time();
		philo->status = EAT;
		print_status(get_time() - info->std_time, info, philo);
		philo->e_cnt++;
	}
	custom_usleep(info->eat);
}

void	run_sleep(t_info *info, t_philo *philo)
{
	philo->status = SLEEP;
	print_status(get_time() - info->std_time, info, philo);
	philo->info->fork[philo->lf_idx] = -1;
	philo->info->fork[philo->rf_idx] = -1;
	pthread_mutex_unlock(&(philo->info->mutex[philo->lf_idx]));
	pthread_mutex_unlock(&(philo->info->mutex[philo->rf_idx]));
	custom_usleep(info->sleep);
}

void	run_think(t_info *info, t_philo *philo)
{
	philo->status = THINK;
	print_status(get_time() - info->std_time, info, philo);
}

void	print_status(int time, t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->print_mutex));
	printf("%d %d ", time, (philo->id + 1));
	if (philo->status == 1)
		printf("has taken a fork\n");
	else if (philo->status == 2)
		printf("is eating\n");
	else if (philo->status == 3)
		printf("is sleeping\n");
	else if (philo->status == 4)
		printf("is thinking\n");
	else if (philo->status == 5)
		printf("is died\n");
	pthread_mutex_lock(&(info->print_mutex));
}
