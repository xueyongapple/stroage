#include <stdio.h>
#include <unistd.h>
#include "make_log.h"


int main(int argc ,char *argv[])
{
    pid_t pid = 0;
    char buf[1024] = {0};
    int fd[2];
    if ( pipe(fd) < 0)
    {
        printf("error");
    }

        pid = fork();
        if (pid < 0)
        {
            return -2;
        }
        else if (pid ==0)
        {
            close(fd[0]);
            
            dup2(fd[1], STDOUT_FILENO);
            execlp("fdfs_updload_file", "fdfs_upload_file", "/etc/fdfs/client.conf", "test.c", NULL);
            printf("-------");
        }
        else if (pid > 0)
        {
            close(fd[1]);
           read(fd[0], buf, 1024);
           LOG("1111", "2222", "===" );
        }


    return 0;
}
