#include "set.h"

/**
 * reads the elements and enters them into the specific set required, s is a Pointer to set struct and values is the string of the elements from the input */
void read_set(set *s, char *values) {
    char *endstr;
    long value;
    char *str1;
    int i;
    char *end;
    for (i = 0; i < sizeof(s->bits); i++) {
        s->bits[i] = 0;
    }
    str1 = strtok(values, ",");

    while (str1 != NULL) {
  
        while (isspace((unsigned char)*str1)) str1++; /* to jump over whitespace */
        end = str1 + strlen(str1) - 1; /* a pointer to the end of the current part of the string */
        while (end > str1 && isspace((unsigned char)*end)) end--;
        end[1] = '\0';
        if (*str1 == '\0') {
            printf("Multiple consecutive commas\n"); /* if the token is empty it means there were multiple consecutive commas */
            return;
        }

        value = strtol(str1, &endstr, 10);

        /* check if the value is not an integer */
        if (*endstr != '\0' && *endstr != '\n' && *endstr != '\r' && *endstr != ' ' && *endstr != '\t' && *endstr != ',') {
            printf("Invalid set member – not an integer\n");
            return;
        }

        /* check if the value is in the range */
        if (value >= 0 && value < MAX_SET_VALUE) {
            s->bits[value / 8] |= (1 << (value % 8));
        } else if (value == -1) {
            str1 = strtok(NULL, ",");
            if (str1) {
                printf("List of set members is not terminated correctly\n");
                return;
            } else {
                break;
            }
        } else {
            printf("Invalid set member – value out of range\n");
            return;
        }

        str1 = strtok(NULL, ",");
    }
}

/**
 * print the elements in the set, s is a Pointer to set struct */
void print_set(set *s) {
    int empty = 1;
    int i;
    for (i = 0; i < MAX_SET_VALUE; ++i) {
        if (s->bits[i / 8] & (1 << (i % 8))) {
            if (!empty) printf(", ");
            printf("%d", i);
            empty = 0;
        }
    }
    if (empty) {
        printf("The set is empty\n");
    } else {
        printf("\n");
    }
}

/**
 * make an union of two sets and puts the result into result Pointer, s1 Pointer to set A,s2 Pointer to set B
 */
void union_set(set *result, set *s1, set *s2) {
    int i;
    for (i = 0; i < sizeof(result->bits); ++i) {
        result->bits[i] = s1->bits[i] | s2->bits[i];
    }
}

/**
 * make an intersection of two sets and puts the result into result Pointer, s1 Pointer to set A ,s2 Pointer to set B
 */
void intersect_set(set *result, set *s1, set *s2) {
    int i;
    for (i = 0; i < sizeof(result->bits); ++i) {
        result->bits[i] = s1->bits[i] & s2->bits[i];
    }
}

/**
 * make a subtraction of two sets and puts the result into result Pointer, s1 Pointer to set A ,s2 Pointer to set B
 */
void subtract_set(set *result, set *s1, set *s2) {
    int i;
    for (i = 0; i < sizeof(result->bits); ++i) {
        result->bits[i] = s1->bits[i] & ~(s2->bits[i]);
    }
}

/**
 * make a symmetric difference of two sets and puts the result into result Pointer, s1 Pointer to set A ,s2 Pointer to set B
 */
void symdiff_set(set *result, set *s1, set *s2) {
    int i;
    for (i = 0; i < sizeof(result->bits); ++i) {
        result->bits[i] = s1->bits[i] ^ s2->bits[i];
    }
}

