#ifndef _MIO_H
#define _MIO_H

#include "mlib.h"

void write(unsigned fd, const char *buf, size_t count);
void read(unsigned fd, char *buf, size_t count);

void print(const char *buf);

void scan(char *buf);

#endif