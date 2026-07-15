#define _POSIX_C_SOURCE 199309L
#include "stopwatch.h"
#include <time.h>

Stopwatch stopwatch_start(void)
{
  Stopwatch sw;
  clock_gettime(CLOCK_MONOTONIC, &sw.start);
  return sw;
}

void stopwatch_stop(Stopwatch *sw)
{
  clock_gettime(CLOCK_MONOTONIC, &sw->end);
}

float stopwatch_ms(const Stopwatch *sw)
{
  long sec_diff = (long)(sw->end.tv_sec - sw->start.tv_sec);
  long ns_diff = sw->end.tv_nsec - sw->start.tv_nsec;
  return (float)sec_diff * 1000.0f + (float)ns_diff / 1000000.0f;
}
