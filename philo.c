#include "philo.h"

long	get_cur_time()
{
	struct timeval	time;
	long			ret_val;

	gettimeofday(&time, NULL);
	ret_val = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ret_val);
}

void	sleep_time(long amount_of_time_to_wait)
{
	long	current_time;
	long	period_of_time;

	current_time = get_cur_time();
	period_of_time = current_time + amount_of_time_to_wait;
	while (period_of_time > current_time)
	{
		usleep(1);
		current_time = get_cur_time();
	}
}

void	mutex_init(t_all *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_count)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL))
		{
			printf("Mutex initialisation error!");
			exit(0);
		}
		++i;
	}
	pthread_mutex_init(&philo->messages_order, NULL);
	pthread_mutex_init(&philo->philos->right_fork, NULL);
	pthread_mutex_init(&philo->philos->left_fork, NULL);
}

void		thread_creation(t_all *phils)
{
	int		i;

	i = -1;
	while (++i <= phils->philo_count)
	{
		pthread_create(&phils->philos[i].philo, NULL, thread, &phils->philos[i]);
	}
}

void		init_threads(t_all *phils)
{
//	phils->philos = (t_philos *)malloc(sizeof(t_philos) * phils->philos->philo_count);
	phils->philos[phils->philo_count];//stack
	int		i;
	long	start;

	i = -1;
	start = get_cur_time();
	while (++i <= phils->philo_count)
	{
		phils->philos[i].pid = i + 1;
		phils->philos[i].left_fork = phils->forks[i];
		phils->philos[i].right_fork = phils->forks[(i + 1) % phils->philo_count];
		phils->philos[i].thread_start = start;
		phils->philos[i].time_of_last_meal = 0;
	}
	thread_creation(phils);
}
