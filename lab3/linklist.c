/**************************************************************************************************/
/* Copyright (C) wakeam.imwork.net, 2017                                                          */   
/*                                                                                                */   
/*  FILE NAME             :  linklist.c                                                           */   
/*  PRINCIPAL             :  LiangXiaojian                                                        */   
/*  SUBSYSTEM NAME        :  menu                                                                 */   
/*  MODULE NAME           :  linklist                                                             */
/*  LANGUAGE              :  C                                                                    */   
/*  TARGET ENVIRONMENT    :  Any                                                                  */   
/*  DATE OF FIRST RELEASE :  2017/10/09                                                           */   
/*  DESCRIPTION           :  linklist for menu program                                            */   
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Create by LiangXiaojian, 2017/10/09
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

tDataNode* FindCmd(tDataNode* head, char* cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }
    tDataNode *p = head;
    while(p != NULL)
    {
        if(strcmp(p->cmd, cmd) == 0)
	{
	    return p;
	}
        p = p->next;
    }
    return NULL;
}

int ShowAllCmd(tDataNode* head)
{
    printf("Menu List:\n");
    tDataNode *p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
	p = p->next;
    }
    return 0;
}
