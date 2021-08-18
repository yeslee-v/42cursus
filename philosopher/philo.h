#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define DIE	5

# define MAX_INT 2147483648

typedef struct	s_per
{
	int			num;
	unsigned long long			die;
	unsigned long long			eat;
	unsigned long long			sleep;
	unsigned long long			must_eat;

	pthread_mutex_t	*fork;
}				t_per;

typedef struct	s_philo
{
	int			l_fork;
	int			r_fork;
	pthread_t	*thread;
	t_per		*per;
}				t_philo;

/*
 * main.c
 */
int		main(int ac, char **av);

/*
 *init.c
 */
int		init_philo(int ac, char **av, t_philo *philo);

/*
 * utils.c
 */
int		ft_atoi(char *str);

/*
 *print.c
 */
void	print_status(int status);

# endif
