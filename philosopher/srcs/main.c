#include "../include/philo.h"

int main(int ac, char **av)
{
	/*
	 *int			i;
	 *int			ret;
	 */
	t_philo		philo;

	(void)av;
	if ((ac < 4) || (ac > 5))
	{
		printf("ac is invalid\n");
		return (1);
	}
	printf("1\n");
	printf("info: %d\n", philo.num);
	/*
	 *if (init_philo(philo.info, &philo) || init_info(ac, av, philo.info))
	 *    return (1);
	 *printf("2\n");
	 *philo.thread = malloc(sizeof(pthread_t) * philo.info->total);
	 *if (!(philo.thread))
	 *{
	 *    printf("malloc error\n");
	 *    return (1);
	 *}
	 *i = -1;
	 *ret = 0;
	 *while (++i < philo.info->total)
	 *{
	 *    ret = pthread_create(&(philo.thread[i]), NULL, do_philo, &philo[i]);
	 *    if (ret == -1)
	 *    {
	 *        printf("Fail to make thread\n");
	 *        return (1);
	 *    }
	 *    pthread_detach(philo.thread[i]);
	 *}
	 */
	/*
	 *do_monitor(philo);
	 */
	// mutex
	return (0);
}
