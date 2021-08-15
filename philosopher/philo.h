#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define DIE	5

# define MAX_INT 2147483648

typedef struct	s_philo
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_must_eat;

	pthread_mutex_t	fork;
}				t_philo;

typedef struct	s_thread
{
	pthread_t	*thread;
	t_philo		*philo;
}				t_thread;

/*
 * main.c
 */
int		main(int ac, char **av);

/*
 *init.c
 */
void	init_philo(t_philo *philo);
int		ft_atoi(char *str);

/*
 *print.c
 */
void	print_status(int status);

# endif
