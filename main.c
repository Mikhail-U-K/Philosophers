#include <stdio.h>
#include "philo.h"

void	validation(char **args) {
	int		i;
	int		j;

	i = 0;
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				printf("not valid argument");
				exit(0);
			}
		}
	}
}

void	parser(int args, char **argv, t_all *philo)
{
	int		i;

	philo->philo_count = ft_atoi(argv[1]);
	philo->philos = (t_philos *)malloc(sizeof(t_philos) * philo->philo_count);
	i = -1;
	while (++i < philo->philo_count)
	{
		philo->philos[i].time_to_die = ft_atoi(argv[2]);
		philo->philos[i].time_to_eat = ft_atoi(argv[3]);
		philo->philos[i].time_to_sleep = ft_atoi(argv[4]);
		if (args == 6)
			philo->philos[i].food_count = ft_atoi(argv[5]);
		else
			philo->philos[i].food_count = 0;
	}
}

int main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		t_all	phil;
		validation(argv);
		parser(argc, argv, &phil);
		mutex_init(&phil);
		init_threads(&phil);
	}
	else
		printf("Wrong number of arguments\n");
	return 0;
}
