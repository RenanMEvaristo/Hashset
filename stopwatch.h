#pragma once

#include <time.h>

typedef struct
{
  struct timespec start;
  struct timespec end;
} Stopwatch;

Stopwatch stopwatch_start(void);
void stopwatch_stop(Stopwatch *sw);
float stopwatch_ms(const Stopwatch *sw);
