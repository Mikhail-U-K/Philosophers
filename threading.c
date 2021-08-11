#include "philo.h"

void	*thread(void *phil)
{
	t_philos		*thread;
	int				i;

	i = 0;
	thread = (t_philos *)phil;
	while (1)
	{

	}
	return NULL;
}

void		is_sleeping(t_philos *cur_philo)
{

}

void		is_eating(t_philos *cur_philo)
{
	pthread_mutex_lock(&cur_philo->right_fork);
	pthread_mutex_lock(&cur_philo->left_fork);
	pthread_mutex_lock(&cur_philo->message);
	printf("%ld ms id %d is eating\n", get_cur_time() - cur_philo->start_eating, cur_philo->pid);
	sleep_time(cur_philo->time_to_eat);
	pthread_mutex_unlock(&cur_philo->message);
	pthread_mutex_unlock(&cur_philo->left_fork);
	pthread_mutex_unlock(&cur_philo->right_fork);
	
}

void		is_thinking(t_philos *cur_philo)
{

}