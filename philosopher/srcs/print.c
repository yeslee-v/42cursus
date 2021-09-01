#include "../include/philo.h"
#include <pthread.h>

void	run_eat(t_info *info, t_philo *philo)
{
	if ((philo->info->fork[philo->lf_idx] == philo->id) && \
			(philo->info->fork[philo->rf_idx] == philo->id))
	{
		philo->status = EAT;
		philo->e_time = get_time();
		print_status(get_time() - info->std_time, philo);
		philo->e_cnt++;
	}
	custom_usleep(100);
}

void	run_sleep(t_info *info, t_philo *philo)
{
	philo->status = SLEEP;
	print_status(get_time() - info->std_time, philo);
	philo->info->fork[philo->lf_idx] = -1;
	philo->info->fork[philo->rf_idx] = -1;
	pthread_mutex_unlock(&(philo->info->mutex[philo->lf_idx]));
	pthread_mutex_unlock(&(philo->info->mutex[philo->rf_idx]));
	custom_usleep(usleep(100));
}

void	run_think(t_info *info, t_philo *philo)
{
	philo->status = THINK;
	print_status(get_time() - info->std_time, philo);
}

void	print_status(int time, t_philo *philo)
{
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
}
