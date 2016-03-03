/* TCPmechod.c - main, echo */
#include<pthread.h>
#include <sys/types.h>
#include<sys/signal.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include<errno.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <netinet/in.h>


#define QLEN 32 /* maximum connection queue length */
#define BUFSIZE 4096

#define INTERVAL 5  /* secs */


struct{
    pthread_mutex_t st_mutex;
    unsigned int st_concount;
    unsigned int st_contotal;
    unsigned long st_contime;
    unsigned long st_bytecount;
} stats;

void prstats(void);
extern int errno;
int errexit(const char *format, ...);
int passiveTCP(const char *service, int qlen);
int TCPechod(int fd);

/*------------------------------------------------------------------------
 * main - Concurrent TCP server for ECHO service
 *------------------------------------------------------------------------
 */

int main(int argc, char *argv[])
{
    pthread_t th;
    pthread_attr_t ta;
    char *service = "echo"; /* service name or port number */
    struct sockaddr_in fsin; /* the from address of a client */
    int msock,ssock;      /* master server socket */
    unsigned int alen;      /* from-address length */

    switch (argc)
    {
        case    1:
            break;
        case    2:
            service = argv[1];
            break;
        default:
            errexit("usage: TCPechod [port]\n");
    }

    msock = passiveTCP(service, QLEN);

    (void) pthread_attr_init(&ta);
    (void) pthread_attr_setdetachstate(&ta, PTHREAD_CREATE_DETACHED);
    (void) pthread_mutex_init(&stats.st_mutex,0);

    if(pthread_create(&th, &ta, (void * (*) (void *))prstats,0)<0)
        errexit("pthread_create(prstats): %s\n", strerror(errno));

    while (1)
    {
        alen = sizeof(fsin);

        ssock = accept(msock, (struct sockaddr *)&fsin, &alen);
        if (ssock < 0)
            errexit("accept: %s\n", strerror(errno));

        if(pthread_create(&th, &ta, (void * (*) (void *))TCPechod,(void *)ssock) < 0)
            errexit("pthread_create: %s\n", strerror(errno));

    }
}

/*------------------------------------------------------------------------
 * TCPechod - echo data until end of life
 *------------------------------------------------------------------------
 */

int TCPechod(int fd)
{
    time_t start;
    char buf[BUFSIZE];
    int cc;

    start = time(0);

    (void) pthread_mutex_lock(&stats.st_mutex);
    stats.st_concount++;
    (void) pthread_mutex_unlock(&stats.st_mutex);

    while(cc=read(fd, buf, sizeof buf))
    {
        if(cc<0)
            errexit("echo read: %s\n", strerror(errno));

        if (write(fd, buf, cc) < 0)
            errexit("echo write: %s\n", strerror(errno));

        (void) pthread_mutex_lock(&stats.st_mutex);
        stats.st_bytecount += cc;
        (void) pthread_mutex_unlock(&stats.st_mutex);

    }

    (void) close(fd);
    (void) pthread_mutex_lock(&stats.st_mutex);
    stats.st_contime += time(0) - start;
    stats.st_concount--;
    stats.st_contotal++;
    (void) pthread_mutex_unlock(&stats.st_mutex);

    return 0;
}

/*------------------------------------------------------------------------
 * prstats - print server statistical data
 *------------------------------------------------------------------------
 */

void prstats(void)
{
    time_t now;

    while(1)
    {
        (void) sleep(INTERVAL);

        (void) pthread_mutex_lock(&stats.st_mutex);
        now = time(0);
        (void) printf("---- %s", ctime(&now));
        (void) printf("%-32s: %u\n", "current connections" , stats.st_concount);
        (void) printf("%-32s: %u\n", "completed connections" , stats.st_contotal);
        if(stats.st_contotal)
        {
            (void) printf("%-32s: %.2f (secs) \n", "Average complete connection time", (float)stats.st_contime / (float)stats.st_contotal);

            (void) printf("%-32s: %.2f (secs) \n", "Average byte", (float)stats.st_bytecount / (float)stats.st_contotal + stats.st_concount);
        }

        (void) printf("%-32s: %lu \n\n", "Total byte count", stats.st_bytecount);
        (void) pthread_mutex_unlock(&stats.st_mutex);

    }
}













