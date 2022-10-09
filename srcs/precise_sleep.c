#include "../philo.h"

void    precise_sleep(size_t sleep_time)
{
    size_t    end_time;

    end_time = get_time() + sleep_time;
    while (get_time() < end_time)
        usleep(100);
}