#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SET_VALUE 128

typedef struct {
    unsigned char bits[MAX_SET_VALUE / 8];
} set;

void read_set(set *s, char *values);
void print_set(set *s);
void union_set(set *result, set *s1, set *s2);
void intersect_set(set *result, set *s1, set *s2);
void subtract_set(set *result, set *s1, set *s2);
void symdiff_set(set *result, set *s1, set *s2);

#endif /* SET_H */

