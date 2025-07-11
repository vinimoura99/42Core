#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOS 2

pthread_mutex_t forks[NUM_PHILOS];

typedef struct s_philo
{
	int id;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
}	t_philo;

void	*philo_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (1)
	{
		printf("Philosopher %d is thinking 🧠\n", philo->id);
		usleep(500000); // pensa 0.5s

		printf("Philosopher %d tries to take forks 🍴\n", philo->id);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);

		printf("Philosopher %d is eating 🍝\n", philo->id);
		usleep(1000000); // come 1s

		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		printf("Philosopher %d finished eating and is sleeping 😴\n", philo->id);
		usleep(800000); // dorme 0.8s
	}
	return (NULL);
}

int	main(void)
{
	pthread_t threads[NUM_PHILOS];
	t_philo philos[NUM_PHILOS];

	// Inicializa os garfos
	for (int i = 0; i < NUM_PHILOS; i++)
		pthread_mutex_init(&forks[i], NULL);

	// Inicializa filósofos e cria as threads
	for (int i = 0; i < NUM_PHILOS; i++)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % NUM_PHILOS];
		pthread_create(&threads[i], NULL, philo_routine, &philos[i]);
	}

	// Espera as threads terminarem (não vão terminar)
	for (int i = 0; i < NUM_PHILOS; i++)
		pthread_join(threads[i], NULL);

	return (0);
}
