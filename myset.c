#include "set.h"

/*print a prompt for the user ">" */
void prompt() {
    printf("> ");
}

/**
 * parse and execute user commands, get as input command String containing the command and set_sets an Array is size 6 which is a set struct */
int seperate_command(char *command, set sets_groups[6]) {
    char *cmd = strtok(command, " \t");
    if (cmd == NULL) return 1; /* Continue reading commands */

    if (strcmp(cmd, "stop") == 0) {
        return 0; /* Stop the program */
    } else if (strcmp(cmd, "read_set") == 0) {
        char *setgroup = strtok(NULL, " ,\t");
        char *values = strtok(NULL, "");

        if (setgroup && values) {
            int set_index = (setgroup[0] == 'S' && setgroup[1] == 'E' && setgroup[2] == 'T' && setgroup[3] >= 'A' && setgroup[3] <= 'F' && setgroup[4] == '\0') ? setgroup[3] - 'A' : -1;
            if (set_index == -1) {
                printf("Undefined set name\n");
            } else {
                read_set(&sets_groups[set_index], values);
            }
        } else {
            printf("Missing parameter\n");
        }
    } else if (strcmp(cmd, "print_set") == 0) {
        char *setgroup = strtok(NULL, " \t,");
        char *extra = strtok(NULL, " \t,");

        if (setgroup) {
            int set_index = (setgroup[0] == 'S' && setgroup[1] == 'E' && setgroup[2] == 'T' && setgroup[3] >= 'A' && setgroup[3] <= 'F' && setgroup[4] == '\0') ? setgroup[3] - 'A' : -1;
            if (set_index == -1) {
                printf("Undefined set name\n");
            } else if (extra) {
                printf("Extraneous text after end of command\n");
            } else {
                print_set(&sets_groups[set_index]);
            }
        } else {
            printf("Missing parameter\n");
        }
    } else if (strcmp(cmd, "union_set") == 0 || strcmp(cmd, "intersect_set") == 0 || strcmp(cmd, "subtract_set") == 0 || strcmp(cmd, "symdiff_set") == 0) {
        char *setgroup1 = strtok(NULL, " \t,");
        char *setgroup2 = strtok(NULL, " \t,");
        char *setresult = strtok(NULL, " \t\n");

    if(setresult && strlen(setresult) > 4) {
            printf("Extraneous text after end of command\n");
    } 

       else if (setgroup1 && setgroup2 && setresult ) {
            int set_index1 = (setgroup1[0] == 'S' && setgroup1[1] == 'E' && setgroup1[2] == 'T' && setgroup1[3] >= 'A' && setgroup1[3] <= 'F' && setgroup1[4] == '\0') ? setgroup1[3] - 'A' : -1;
            int set_index2 = (setgroup2[0] == 'S' && setgroup2[1] == 'E' && setgroup2[2] == 'T' && setgroup2[3] >= 'A' && setgroup2[3] <= 'F' && setgroup2[4] == '\0') ? setgroup2[3] - 'A' : -1;
            int set_index_result = (setresult[0] == 'S' && setresult[1] == 'E' && setresult[2] == 'T' && setresult[3] >= 'A' && setresult[3] <= 'F' && setresult[4] == '\0') ? setresult[3] - 'A' : -1;

            if (set_index1 == -1 || set_index2 == -1 || set_index_result == -1) {
                printf("Undefined set name\n");
            } 

        else {
                if (strcmp(cmd, "union_set") == 0) {
                    union_set(&sets_groups[set_index_result], &sets_groups[set_index1], &sets_groups[set_index2]);
                } else if (strcmp(cmd, "intersect_set") == 0) {
                    intersect_set(&sets_groups[set_index_result], &sets_groups[set_index1], &sets_groups[set_index2]);
                } else if (strcmp(cmd, "subtract_set") == 0) {
                    subtract_set(&sets_groups[set_index_result], &sets_groups[set_index1], &sets_groups[set_index2]);
                } else if (strcmp(cmd, "symdiff_set") == 0) {
                    symdiff_set(&sets_groups[set_index_result], &sets_groups[set_index1], &sets_groups[set_index2]);
                }
            }
        } 
      else {
        printf("Extraneous text after end of command\n");
        }
    } else if (strcmp(cmd, "sub_set") == 0) {
        printf("Multiple consecutive commas\n");
    } else {
        printf("Undefined command name\n");
    }

    return 1; 
}

int main() {
    set sets_groups[6]; /* Array of the six sets (SETA, SETB, SETC, SETD, SETE, SETF) */
    char command[256];
    while (1) {
        prompt(); /* Print prompt "<"  for input */
        if (!fgets(command, sizeof(command), stdin)) break; 
        command[strcspn(command, "\n")] = 0;  
        printf("%s\n", command); 
        if (!seperate_command(command, sets_groups)) break; /* execute the command */
    }
    return 0;
}

