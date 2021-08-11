#include "philo.h"

int main(int ac, char **av)
{
	if (ac != 6)
		write(2, "error\n", 6);
	while (*av)
	{
		printf("av is %s\n", *av);
		av++;
	}
}
