#include "util.h"
#include <stdio.h>
#include "util.h"
#include "unistd.h"
#include <sys/time.h>
#include <pthread.h>

void test()
{
	int	cnt;

	cnt = 0;
	while (1)
	{
		printf("%d %d\n", sleep(1), ++cnt);
	}
}
int	main()
{
	struct timeval s_tv;
	struct timeval e_tv;
	struct timeval ps_tv;
	struct timeval pe_tv;
	int				cnt;
	pthread_t 		thread;

	int		time_i = 1234;
	char	*time = "1234 ";
	char	*id = "1 ";
	char	*say = "is thinking\n";
	int	write_sec;
	int write_usec;
	int	print_sec;
	int	print_usec;
	/*
	pthread_create(&thread, NULL, (void *)test, NULL);
	cnt = 0;
	while (1)
	{
		printf("%d %d\n", uxsleep(1000), ++cnt);
	}
	*/
	/*
	int i;
	i = -1;
	gettimeofday(&ps_tv, NULL);
	while (++i < 10000)
		printf("%d %d %s", 1234, 1, say);
	gettimeofday(&pe_tv, NULL);
	i = -1;
	gettimeofday(&s_tv, NULL);
	while (++i < 10000)
	{
		write(1, ft_itoa(time_i), 4);
		write(1, id, 1);
		write(1, say, 12);
	}
	gettimeofday(&e_tv, NULL);

	printf("print start : %ld.%d초\n", s_tv.tv_sec, s_tv.tv_usec);
	printf("print end : %ld.%d초\n", e_tv.tv_sec, e_tv.tv_usec);
	printf("print start : %ld.%d초\n", ps_tv.tv_sec, ps_tv.tv_usec);
	printf("print end : %ld.%d초\n", pe_tv.tv_sec, pe_tv.tv_usec);
	*/
	if (pthread_detach(thread))
		printf("error");
}
