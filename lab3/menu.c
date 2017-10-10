/**************************************************************************************************/
/* Copyright (C) wakeam.imwork.net, 2017                                                          */   
/*                                                                                                */   
/*  FILE NAME             :  menu.c                                                               */   
/*  PRINCIPAL             :  LiangXiaojian                                                        */   
/*  SUBSYSTEM NAME        :  menu                                                                 */   
/*  MODULE NAME           :  nemu                                                                 */
/*  LANGUAGE              :  C                                                                    */   
/*  TARGET ENVIRONMENT    :  Any                                                                  */   
/*  DATE OF FIRST RELEASE :  2017/10/09                                                           */   
/*  DESCRIPTION           :  main for menu program                                                */   
/**************************************************************************************************/

/*
 * Revision log:
 * Create by LiangXiaojian, 2017/10/09
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "linklist.h"

int Help();
int Quit();
int Restart();
int Add();
int Sub();
int Mult();
int Divi();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

/* menu program */

static tDataNode head[] = 
{
    {"help", "this is help cmd!", Help, &head[1]},
    {"version", "menu program v1.0", NULL, &head[2]},
    {"quit", "quit from menu program.", Quit, &head[3]},
    {"restart", "restart this menu program", Restart, &head[4]},
    {"add", "a + b = ?", Add, &head[5]},
    {"sub", "a - b = ?", Add, &head[6]},
    {"mult", "a * b = ?", Add, &head[7]},
    {"divi", "a / b = ?", Add, NULL}
};

int main()
{
    /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
	printf("input a cmd number > ");
	scanf("%s", cmd);
	tDataNode *p = FindCmd(head, cmd);
	if(p == NULL)
	{
	    printf("This is a wrong cmd!\n");
	    continue;
	}
	printf("%s - %s\n", p->cmd, p->desc);
	if(p->handler != NULL)
	{
	    p->handler();
	}
    }
}

int Help()
{
    ShowAllCmd(head);
    return 0;
}

int Quit()
{
    exit(0);
}

int Restart()
{
    printf("Shutdowm ......\n");
    sleep(1);
    printf("Start    ......\n");
    sleep(1);
    printf("OK !\n");
}

int Add()
{
    float a, b;
    printf("a + b\n");
    printf("input a:");
    scanf("%f", &a);
    printf("input b:");
    scanf("%f", &b);
    printf("%3f + %3f = %3f\n", a, b, a + b);
    return 0;
}

int Sub()
{
    float a, b;
    printf("a - b\n");
    printf("input a:");
    scanf("%f", &a);
    printf("input b:");
    scanf("%f", &b);
    printf("%3f - %3f = %3f\n", a, b, a - b);
    return 0;
}

int Mult()
{
    float a, b;
    printf("a * b\n");
    printf("input a:");
    scanf("%f", &a);
    printf("input b:");
    scanf("%f", &b);
    printf("%3f * %3f = %3f\n", a, b, a * b);
    return 0;
}

int Divi()
{
    float a, b;
    printf("a / b\n");
    printf("input a:");
    scanf("%f", &a);
    printf("input b:");
    scanf("%f", &b);
    printf("%3f / %3f = %3f\n", a, b, a / b);
    return 0;
}
