#include "main.h"

void input_num(int n, int role)
{
	pinf phead_inf;
	pinf phead_acc;
	int a;
	switch (n)
	{
	case 1:sea_inf(&phead_inf,role);
		break;
	case 2:add_inf(&phead_inf);
		break;
	case 3:upd_inf(&phead_inf);
		break;
	case 4:del_inf(&phead_inf);
		break;
	case 5:add_acc(&phead_acc);
		break;
	case 6:upd_acc(&phead_acc);
		break;
	case 7:del_acc(&phead_acc);
		break;
	case 8:sea_acc(&phead_acc);
		break;
	default:exit(0);
		break;
	}
}