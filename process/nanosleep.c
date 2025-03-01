#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *request, const struct timespec *remaining) {
    long ret = syscall(__NR_nanosleep, request, remaining);
    if (ret == 0) {
        return 0;
    }
    errno = -ret;
    return -1;
}
