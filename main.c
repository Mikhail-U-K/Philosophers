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
//	*philo = (t_philos *)malloc(sizeof (t_philos));
	philo->philo_count = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (args == 6)
		philo->philos->food_count = ft_atoi(argv[5]);
	else
		philo->philos->food_count = 0;
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
	printf("Wrong number of arguments\n");
	return 0;
}
