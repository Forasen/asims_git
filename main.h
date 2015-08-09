#ifndef __FUNC_H_
#define __FUNC_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

#define NM_LEN 20
#define PWD_LEN 10
#define ID_LEN 10
#define CNT 10
#define N 100

typedef struct account
{
	char usr_nm[NM_LEN];
	char usr_pwd[PWD_LEN];
	int usr_role;
	struct usr_account_tag *acc_next; 
}acc, *pacc;

typedef struct info
{
	char usr_id[ID_LEN];
	char usr_nm[NM_LEN];
	int usr_cs_id;
	int usr_cs_score;
	struct usr_info_tag *inf_next;
}inf, *pinf;

void load();
char* load_path(char* path);

void sea_by(pinf *pphead_inf);

void input_num(int n, int *role);

void show_start(int role);

void sea_inf(pinf* pphead_inf);//1
void add_inf(pinf* pphead_inf);//2
void upd_inf(pinf* pphead_inf);//3
void del_inf(pinf* pphead_inf);//4
void fetch_inf(pinf* pphead_inf);

void check_acc(char *name, char* pwd);
void add_acc(pacc* pphead_acc);//5
void upd_acc(pacc* pphead_acc);//6
void del_acc(pacc* pphead_acct);//7
void sea_acc(pacc* pphead_acc);//9
void fetch_acc(pacc* pphead_acc);

#endif