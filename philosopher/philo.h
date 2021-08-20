#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/select.h>
# include <unistd.h>

# define FORK	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define DIE	5
# define FULL	6

# define MAX_INT 2147483648

typedef struct	s_info
{
	int					num;
	unsigned long long	die;
	unsigned long long	eat;
	unsigned long long	sleep;
	unsigned long long	must_eat;

	unsigned long long	std_time;

	pthread_mutex_t		*fork;
}				t_info;

typedef struct	s_philo
{
	int					e_cnt;
	int					lf_idx;
	int					rf_idx;
	pthread_t			*thread;
	t_info				*info;
}				t_philo;

/*
 * main.c
 */
int		main(int ac, char **av);

/*
 *init.c
 */
int		init_info(int ac, char **av, t_info *info);
void	init_philo(t_philo *philo);

/*
 * utils.c
 */
int					ft_atoi(char *str);
unsigned long long	get_time(void);

/*
 *print.c
 */
void	print_status(int status);

# endif
