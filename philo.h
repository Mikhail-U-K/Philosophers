#ifndef UNTITLED1_PHILO_H
#define UNTITLED1_PHILO_H

#include <pthread.h>
#include <limits.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct	s_philos {
	int				food_count;
	long			cur_time;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	pthread_t		philo;
	int				pid;
	long			thread_start;
	long			time_of_last_meal;
	long			start_eating;
	long			finish_eating;
}				t_philos;

typedef	struct	s_all {
	t_philos		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	messages_order;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
}				t_all;

int		ft_isdigit(int a);
int		ft_atoi(const char *str);
void	mutex_init(t_all *philo);
void	init_threads(t_all *philos);
void	*thread(void *phil);
#endif
