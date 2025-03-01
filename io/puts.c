#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <string.h>

int puts(const char *str){
    while (*str){
        if (write(1, str, 1) != 1)
            return -1;
        str++;
    }
    if (write(1, "\n", 1) != 1)
        return -1;

    return 0;
}
