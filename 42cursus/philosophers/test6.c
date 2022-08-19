#include "util.h"
#include <stdio.h>
#include "util.h"
#include "unistd.h"
#include <sys/time.h>
#include <pthread.h>


void test(int *p_cnt)
{
	*p_cnt = 10;
	while (1)
	{
		printf("%d %d\n", sleep(1), ++(*p_cnt));
	}
}

int data(int data)
{
	return data;
}

void test2(int *p_cnt)
{
	int data1 = 1;
	while (1)
	{
		data1 = data(*p_cnt);
		if (data1 == 20)
			printf("ok");
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
	int	*p_cnt;
	p_cnt = (int *)ft_calloc(1, sizeof(int));
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
	pthread_create(&thread, NULL, (void *)test, (void *)p_cnt);
	pthread_detach(thread);
	pthread_create(&thread, NULL, (void *)test2, (void *)p_cnt);
	pthread_detach(thread);
	while(1)
		continue ;
}
