#include "../include/philo.h"

void	run_eat(t_philo *philo)
{
	ready_to_eat(philo);
	philo->status = EAT;
	philo->e_time = get_time();
	print_status(get_time(), philo);
	philo->e_cnt++;
}

/*
 *void	run_sleep(t_philo *philo)
 *{
	philo->status = SLEEP;
 *
 *}
 *
 *void	run_think(t_philo *philo)
 *{
	philo->status = THINK;
 *
 *}
 */

void	print_status(int time, t_philo *philo)
{
	printf("%d %d ", time, philo->num);
	if (philo->status == 1)
	{
		printf("has taken a fork\n");
	}
	else if (philo->status == 2)
	{
		printf("is eating\n");
	}
	else if (philo->status == 3)
	{
		printf("is sleeping\n");
	}
	else if (philo->status == 4)
	{
		printf("is thinking\n");
	}
	else if (philo->status == 5)
	{
		printf("is died\n");
	}
}
