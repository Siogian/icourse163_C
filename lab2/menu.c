/*************************************************
 * FILE:   menu.c
 * MODULE: Menu
 * AUTHOR: Xiaojian
 * UPDATE: 2017/09/24
 *************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Help();
float add();
float sub();
float mult();
float divi();

int main()
{
    char cmd[128];
    while(1)
    {
        printf("menu: ");
        scanf("%s", cmd);
	if(strcmp(cmd, "help") == 0)	
	{
	    Help();
	}
	else if(strcmp(cmd, "quit") == 0)
	{
	    exit(0);
	}
	else if(strcmp(cmd, "version") == 0)
	{
	    printf("Version: 0.1.1\n");
	}
	else if(strcmp(cmd, "restart") == 0)
	{
	    printf("Shutdowm ......\n");
	    sleep(1);
	    printf("Start    ......\n");
	    sleep(1);
	    printf("OK !\n");
	}
        else if(strcmp(cmd, "add") == 0)
	{
	    printf("%f\n", add());
	}
        else if(strcmp(cmd, "sub") == 0)
	{
	    printf("%f\n", sub());
	}
        else if(strcmp(cmd, "mult") == 0)
	{
	    printf("%f\n", mult());
	}
        else if(strcmp(cmd, "divi") == 0)
	{
	    printf("%f\n", divi());
	}
	else
	{
	    printf("Wrong cmd!\n");
	}
    }
    return 0;
}

void Help()
{
    printf("This is help cmd!\n\n");
    printf("help    \tList all cmd!\n");
    printf("quit    \tQuit this app!\n");
    printf("version \tShow it's version!\n");
    printf("restart \tRestart this app!\n");
    printf("add     \ta + b.\n");
    printf("sub     \ta - b.\n");
    printf("mult    \ta * b.\n");
    printf("divi    \ta / b.\n");
}

float add()
{
    float a, b;
    printf("a + b\n");
    printf("input a:");
    scanf("%f", &a);
    printf("input b:");
    scanf("%f", &b);
    return a + b;
}
float sub()
{
    float a, b;
    printf("a - b\n");
    printf("input a:");
    scanf("%f", &a);
    printf("input b:");
    scanf("%f", &b);
    return a - b;
}
float mult()
{
    float a, b;
    printf("a * b\n");
    printf("input a:");
    scanf("%f", &a);
    printf("input b:");
    scanf("%f", &b);
    return a * b;
}

float divi()
{
    float a, b;
    printf("a / b\n");
    printf("input a:");
    scanf("%f", &a);
    printf("input b:");
    scanf("%f", &b);
    return a / b;
}
