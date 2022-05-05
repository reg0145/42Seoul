#include <unistd.h>
#include <signal.h>

void f(int sig, siginfo_t *siginfo, void *unused)
{
    write(1, "data", 4);
}

int main()
{
    struct sigaction sig;
    
    sig.sa_flags = SA_SIGINFO | SA_NODEFER;
    sig.sa_sigaction = f;
    sigaction(SIGUSR1, &sig, NULL);
    sleep(100);
    write(1, "end", 3);
}