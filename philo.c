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
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->philo_count);
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
}

void		thread_creation(t_all *phils)
{
	int		i;

	i = -1;
	while (++i < phils->philo_count)
	{
		if (pthread_create(&phils->philos[i].philo, NULL, thread, &phils->philos[i]))
		{
			printf("couldn't create new thread");
			exit(0);
		}
	}
	i = -1;
	while (++i < phils->philo_count)
	{
		if (pthread_join(phils->philos[i].philo, NULL))
		{
			printf("couldn't join threads");
			exit(0);
		}
	}
}

void		init_threads(t_all *phils)
{
	int		i;
	long	start;

	i = -1;
	start = get_cur_time();
	phils->deaf_status = 0;
	while (++i < phils->philo_count)
	{
		phils->philos[i].pid = i + 1;
		phils->philos[i].left_fork = phils->forks[i];
		phils->philos[i].right_fork = phils->forks[(i + 1) % phils->philo_count];
		phils->philos[i].thread_start = start;
		phils->philos[i].time_of_last_meal = 0;
		phils->philos[i].message = phils->messages_order;
		printf("%d\n", phils->philos[i].pid);
	}
	thread_creation(phils);
}
