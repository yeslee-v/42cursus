#include "../include/philo.h"

int	ft_isdigit(int num)
{
	if ((num >= '0') && (num <= '9'))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		neg;
	long	ret;

	i = 0;
	neg = 1;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	ret = 0;
	while (ft_isdigit(str[i]))
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	ret *= neg;
	if ((ret > MAX_INT) || ret <= 0)
		return (-1);
	return ((int)ret);
}

unsigned long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	custom_usleep(int time)
{
	unsigned long long	goal;

	goal = time + get_time();
	while (goal > get_time())
		usleep(100);
}
