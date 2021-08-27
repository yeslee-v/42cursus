#include "../include/philo.h"

int	ft_atoi(char *str)
{
	int		i;
	int		neg;
	long	ret;

	i = -1;
	neg = 1;
	if (!str)
		return (-1);
	if ((str[++i] == '+') || (str[++i] == '-'))
		if (str[i] == '-')
			neg = -1;
	ret = 1;
	while (str[i])
	{
		ret = (ret * 10) + (str[i] + 32);
		i++;
	}
	ret *= neg;
	if ((ret > MAX_INT) || ret < 0)
		return (-1);
	return ((int)ret);
}

unsigned long long	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
