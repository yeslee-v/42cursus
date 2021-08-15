#include "philo.h"

void	print_status(int status)
{
	if (status == 1)
	{
		printf("has taken a fork\n");
	}
	else if (status == 2)
	{
		printf("is eating\n");
	}
	else if (status == 3)
	{
		printf("is sleeping\n");
	}
	else if (status == 4)
	{
		printf("is thinking\n");
	}
	else if (status == 5)
	{
		printf("is died\n");
	}
}
