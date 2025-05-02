#ifndef LIBR_TODO_H
#define LIBR_TODO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>


#define MAX_TASK 10

// Type Definitions
typedef char string[23];



typedef struct TASK {
    string NAME;
    string DESCRIPTION;
    struct tm CREATION_TIME;
    int DONE;
} TASK;

typedef TASK LIST_TASK[MAX_TASK];

// Function Declarations
void set_color(int);
void PRINT_MENU();
void DISPLAY_TIME_DATE(struct tm t);
void PRINT_INFO(TASK task);
void switch_button(const char character, const char *message);
void ADD_TASK(int *count, string *name, string *description, LIST_TASK *list);
void DISPLAY_ALL_TASKS(LIST_TASK *list, int numberoftasks);
void loading();
void help();

#endif // LIBR_TODO_H
