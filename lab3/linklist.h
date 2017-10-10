/**************************************************************************************************/
/* Copyright (C) wakeam.imwork.net, 2017                                                          */   
/*                                                                                                */   
/*  FILE NAME             :  linklist.h                                                           */   
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
 * Create by LiangXiaojian, 2017/10/09
 *
 */
 
/* data struct and its operations */

typedef struct DataNode
{
    char*  cmd;
    char*  desc;
    int    (*handler)();
    struct DataNode *next;
} tDataNode;

/* find a cmd in the linklist and return the datanode point */
tDataNode* FindCmd(tDataNode* head, char* cmd);
/* show all cmd in linklist */
int ShowAllCmd(tDataNode* head);
