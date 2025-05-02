#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>




void set_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}




#define MAX_TASK (10)

typedef char string[23];



typedef struct TASK
{

    string NAME;
    string DESCRIPTION;
    struct tm CREATION_TIME; 
    int DONE;

} TASK;

typedef TASK LIST_TASK[10];

void PRINT_MENU()
{

    // code later the menu needed
    system("cls");
set_color(10);
    printf("\n==================================\n");
    printf("\n         MANAGEMNT MENU \n");
    printf("\n==================================\n");

    printf("\n1-Display the list of tasks.\n2-Add new tasks.\n3-Mark tasks as completed or remove them.\n4-Edit or update tasks\n5-help\n6-EXIT\n");
    set_color(15);
}

void DISPLAY_TIME_DATE(struct tm t)
{

    printf("\nCREATION Date and Time of this task: %d-%02d-%02d %02d:%02d:%02d\n",
           t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
           t.tm_hour, t.tm_min, t.tm_sec);
}

void PRINT_INFO(TASK task)
{

    DISPLAY_TIME_DATE(task.CREATION_TIME);                        // add date creation and due and time search a way to do it
    printf("\n>>>Description of the task: %s", task.DESCRIPTION); // add description
    printf("\n>>>Name of the task: %s", task.NAME);               // add name

    if (task.DONE == 1)
    {
        puts("\n>>STATE: \ndone");
    }
    else
    {
        puts("\n>>STATE: pending");
    }
}

void switch_button(const char character, const char *message)
{
    printf(message);
    while (1)
    {

        if (GetAsyncKeyState(character) & 0x8000)
        {

            break;
        }
        else
        {
            puts("retry");
        }
    }
}

void ADD_TASK(int *count, string *name, string *description, LIST_TASK *list)
{

    if (*count < MAX_TASK)
    {
        strcpy((*list)[*count].DESCRIPTION, *description);
        strcpy((*list)[*count].NAME, *name);
        (*list)[*count].DONE = 0;

        time_t tmm = time(NULL);
        struct tm *t = localtime(&tmm);

        (*list)[*count].CREATION_TIME = *t;
    }
    else
    {
        set_color(12);
        puts("no space\n");
        set_color(15);

    }
}

void DISPLAY_ALL_TASKS(LIST_TASK *list, int numberoftasks)
{

    for (int i = 0; i < numberoftasks; i++)
    {
        
        printf("\n%d- %s\n ", i + 1, (*list)[i].NAME);
        PRINT_INFO(*list[i]);
    }
}

void loading()
{

    int start = 0, increment = 0, sleeper;

    do
    {

        increment = (rand() % 12) + 2;   // randomising the incremntaion
        sleeper = (rand() % 500) + 200; // daki kif kif akken ad iban ad yatel chuya

        start = start + increment;
        set_color(1);
        printf("\r[###### - %d%% -######]", start);
        Sleep(sleeper);

    } while (start <= 98);
}

void help()
{

    printf(" THIS IS THE PRIVATE PROPERTY OF MEHDI CHERBI\n PROTCTED BY COPYRIGHT \n ANY COMMENTS OR COMPLAINTS MUST BE DIRECTED TO HIM\n THIS IS A SPAGHETTI_CODE VERSION OF A TASK MANAGER. I AIN'T CLAIMING IT'S PERFECT BUT IT'S A STEP MORE TO LEARN NEW CONCEPTS. DATA STRUCT RIP");
    set_color(12);
    puts("\n\npress esc to go back");
    set_color(15);
    while (1)
    {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            break;
        }
    }
}
