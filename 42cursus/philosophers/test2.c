#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	eating()
{

}

void wrap_func(void (*func)(), int time)
{
	struct timeval	pre;
	struct timeval	now;

	gettimeofday(&pre, NULL);
	func();
	//sleep();
	gettimeofday(&now, NULL);
}

int main ()
{
	char* ptr;
	ptr = "%d  is eating";
	int (*func)(const char *msg, ...);

	func = printf;
}
