#include "util.h"
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

/*
void	begin_philos_life(t_philosopher *philos, int len)
{
	if (philos->id % 2 == 0)
		uxsleep((double)rule->eat_time / 2);
	// 필로소퍼 활동
	// 먹고
	// 자고
	// 생각하고
}
*/

int	main()
{
	sem_t *test;
	pid_t	pid;

	int	i;

	test = (sem_t *)calloc(1, (sem_t));
	sem_init(&test[0], 0, 1);
/*
	i = -1;
	while (++i < 100) {
		pid = fork();
		if (pid == 0) {
			// 마지막은 늦게 출발
			begin_philos_life(t_philosopher *);
		}
	}
*/
	// 자식 프로세스 죽음 확인
	// 자식 프로세스 죽었는지 체크

}
