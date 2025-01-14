#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, const struct timespec *rem) {
    int res = syscall(__NR_nanosleep, req, rem);

    if (res < 0) {
        errno = -res;
        return -1;
    }
    return 0;
}
