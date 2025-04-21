#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main (void)
{
    int rc;
    
    rc = system ("cat /proc/cpuinfo");
    if (rc == -1)
    {
        printf("Bash не запускается.\n");
    } else {
        printf("Результат работы программы: %d\n ", WEXITSTATUS ( rc));
    }
    return (EXIT_SUCCESS);
    }


