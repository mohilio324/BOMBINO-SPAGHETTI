#include "libr_todo.c"





void main(){

LIST_TASK LIST;
string name, description, name2, name3;
int A = 0,iteratorforloop=0,numberoftasks=0,inputforendloop=5,input,inloop2=9, new, inloop3 = 9, v= 0, found2;




menu1:

loading();
PRINT_MENU();
scanf("%d", &input);
getchar();

switch(input){
    case 1: goto task_all_display;
    case 3: goto mark_task_complete_delete;
    case 5:system("cls"); help(); goto menu1;
    case 2: goto task_add;
    case 4: goto task_edit;
    default: exit(0);

}

return;


task_add:

while( inputforendloop !=0 && numberoftasks <= MAX_TASK)
{
fflush(stdout);
puts("\nAlright you can add tasks now\n");
puts("Provide the name please:\n>");
fgets(name, 23, stdin);
puts("Provide the description for this task:\n> ");
fgets(description, 245, stdin);


ADD_TASK(&iteratorforloop,&name,&description,&LIST);
numberoftasks++;
iteratorforloop ++;
puts("task added succefully, do you wanna add more tasks or stop right here?(1/0): ");
scanf("%d", &inputforendloop);
getchar();
if(inputforendloop == 0 || numberoftasks == MAX_TASK) {goto menu1;}

}
return;


task_edit:



if(numberoftasks == 0){ set_color(14);("No tasks insight");         set_color(15);
    Sleep(1000); goto menu1;}
else{
puts("Provide the name of task you wanna modify:\n> ");
fgets(name2 , 23, stdin);
int found = 0,i=0;
while(i<numberoftasks && inloop2!=0)
{
    if(strcmp(LIST[i].NAME , name2) == 0){
        found = 1;
        // add "do u really wannna continue modifying this task? press on n on the keyborad if no"
        puts("New name?\n>");
        fgets( LIST[i].NAME, 23, stdin);
        puts("New description?\n>");
        fgets(LIST[i].DESCRIPTION ,23, stdin);
        puts("Carry on searching others or go no? (1/0)");
        scanf("%d", inloop2);
        if(inloop2 == 0){goto menu1;}



    }
    i++;
}
if(found == 0) {Sleep(2500);set_color(12);("Task non existant or mistyped.\n");        set_color(15);
    Sleep(2500);goto task_edit;}
}
return;



task_all_display:

if(numberoftasks == 0){set_color(14);puts("No tasks insight please add first");        set_color(15);
    Sleep(2000); goto menu1;}

DISPLAY_ALL_TASKS(&LIST, numberoftasks);

puts("Main menu or finish session?(1/0)");
scanf("%d", new);

switch(new)
{
    case 1: goto menu1;
    case 0: exit(0);
    
}


return;

mark_task_complete_delete:
found2 = 0;
puts("Provide the name of the task you wanna mark as done:\n>");
fgets(name3, 23, stdin);
if(numberoftasks == 0){set_color(14);puts("No tasks insight please add some tasks first");  set_color(15);    Sleep(2000); goto menu1;}

while(v<numberoftasks && inloop3!=0)
{
 
   
    if(strcmp(LIST[v].NAME , name2) == 0){
found2 = 1;
       if(LIST[v].DONE == 1)
       {
        set_color(12);
        puts("Task is already done. ");
        set_color(15);
        Sleep(1000);
        goto mark_task_complete_delete;

       }
       else{
        LIST[v].DONE = 1;
        puts("Alright your task's state has been updated go to menu or carry on(0/1)?");
        scanf("%d", inloop3);
        if(inloop3 == 0){goto menu1;}
        else{goto mark_task_complete_delete; }
        
       }
      
        



    }
    v++;
}
if(found2 == 0) {set_color(12);puts("Task non existant or mistyped.\n");set_color(15);Sleep(2500);goto mark_task_complete_delete;}


return;

}
