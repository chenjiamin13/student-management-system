#include "sims_public.h"

/*创建节点*/
struct student_node *create_student_node(struct student_data *pdata)
{
	struct student_node *pnew = NULL;
	
	pnew = (struct student_node *)malloc(sizeof(struct student_node));
	if(NULL == pnew)
	{
		Print_Error("Malloc failed\n");
		return NULL;
	}
	memset(pnew,0,sizeof(struct student_node));

	memcpy(&pnew->data,pdata,sizeof(struct student_data));
	return pnew;
}

/*销毁节点*/
int destroy_student_node(struct student_node *pnode)
{
	if(pnode != NULL)
	{
		free(pnode);
		pnode = NULL;
	}

	return 0;
}

/*创建头节点-----创建空表*/
struct student_link *create_student_link()
{
	struct student_link *pnew = NULL;
	
	pnew = (struct student_link *)malloc(sizeof(struct student_link));
	if(NULL == pnew)
	{
		Print_Error("Malloc failed\n");
		return NULL;
	}
	memset(pnew,0,sizeof(struct student_link));

	return pnew;
}

/*销毁头节点-----先删除所有节点，然后释放头节点的空间*/
int destroy_student_link(struct student_link *phead)
{
	struct student_node *pnext = NULL;
	struct student_node *pnode = NULL;

	/*销毁所有节点*/
	pnode = phead->pstfirst;
	while(pnode != NULL)
	{
		pnext = pnode->pstnext;
		destroy_student_node(pnode);
		pnode = pnext;
	}
	
	/*释放头节点的空间*/
	free(phead);
	phead = NULL;
	return 0;
}


/*尾插*/
int insert_student_node_at_tail(struct student_link *phead,struct student_node *pnew)
{
	if(phead->pstlast == NULL)
	{
		phead->pstlast = pnew;
		phead->pstfirst = pnew;
	}
	else
	{
		phead->pstlast->pstnext = pnew;
		phead->pstlast = pnew;
	}

	pnew->pstnext = NULL;

	phead->cnt++;
	return 0;
}

/*移除指定节点*/
int remove_student_node(struct student_link *phead,struct student_node *pnode)
{
	struct student_node *pprev = NULL;

	if(phead == NULL || pnode == NULL)
	{
		Print_Error("Input param is invalid\n");
		return -1;
	}

	if(phead->pstfirst == NULL)
	{
		Print_Error("The link-list is empty\n");
		return -1;
	}

	if(pnode == phead->pstfirst)//被移除节点为第一个节点
	{
		phead->pstfirst = pnode->pstnext;
	}
	else
	{
		struct student_node *ptemp = NULL;

		/*pprev指向被移除节点前一个节点*/
		ptemp = phead->pstfirst;
		while(ptemp != NULL)
		{
			if(ptemp->pstnext == pnode)
			{
				pprev = ptemp;
				break;
			}
			ptemp = ptemp->pstnext;
		}
		if(pprev == NULL)
		{
			Print_Error("The node is not in link-list\n");
			return -1;
		}

		pprev->pstnext = pnode->pstnext;
	}

	if(pnode->pstnext == NULL)//被移除节点为最后一个节点
	{
		phead->pstlast = pprev;
	}

	pnode->pstnext = NULL;

	phead->cnt--;
	return 0;
}

/*按学号查找节点*/
struct student_node * search_student_node_byid(struct student_link *phead,int id)
{
	struct student_node *pnode = NULL;

	pnode = phead->pstfirst;
	while(pnode != NULL)
	{
		if(id == pnode->data.id)
		{
			break;
		}
		pnode = pnode->pstnext;
	}

	return pnode;
}

/*按用户名查找节点*/
struct student_node * search_student_node_byname(struct student_link *phead,char *pname)
{
	struct student_node *pnode = NULL;

	pnode = phead->pstfirst;
	while(pnode != NULL)
	{
		if(strcmp(pname,pnode->data.username) == 0)
		{
			break;
		}
		pnode = pnode->pstnext;
	}

	return pnode;
}

/*修改指定节点的密码*/
int modify_student_password(struct student_node *pnode,char *pnewpass)
{
	int len = 0;

	if(pnode == NULL || NULL == pnewpass)
	{
		Print_Error("Input param is invalid\n");
		return -1;
	}

	len = strlen(pnewpass);
	if(len > PASS_LEN - 1)
	{
		Print_Error("new password is too long\n");
		return -1;
	}

	strcpy(pnode->data.password,pnewpass);
	return 0;
}

/*按数学成绩排序用的比较函数*/
/*注意：pv1为被排序数组中元素的地址，此处应转换成struct student_node **类型的二级指针后使用*/
static int cmp_math_score(const void *pv1,const void *pv2)
{
	float sc1 = (*(struct student_node **)pv1)->data.math;
	float sc2 = (*(struct student_node **)pv2)->data.math;

	if(sc1 == sc2)
	{
		return 0;
	}
	else if(sc1 > sc2)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

/*按语文成绩排序用的比较函数*/
/*注意：pv1为被排序数组中元素的地址，此处应转换成struct student_node **类型的二级指针后使用*/
static int cmp_chn_score(const void *pv1,const void *pv2)
{
	float sc1 = (*(struct student_node **)pv1)->data.chn;
	float sc2 = (*(struct student_node **)pv2)->data.chn;

	if(sc1 == sc2)
	{
		return 0;
	}
	else if(sc1 > sc2)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

/*按英语成绩排序用的比较函数*/
/*注意：pv1为被排序数组中元素的地址，此处应转换成struct student_node **类型的二级指针后使用*/
static int cmp_eng_score(const void *pv1,const void *pv2)
{
	float sc1 = (*(struct student_node **)pv1)->data.eng;
	float sc2 = (*(struct student_node **)pv2)->data.eng;

	if(sc1 == sc2)
	{
		return 0;
	}
	else if(sc1 > sc2)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

/*按总分成绩排序用的比较函数*/
/*注意：pv1为被排序数组中元素的地址，此处应转换成struct student_node **类型的二级指针后使用*/
static int cmp_total_score(const void *pv1,const void *pv2)
{
	float sc1 = (*(struct student_node **)pv1)->data.math + 
                (*(struct student_node **)pv1)->data.chn +
                (*(struct student_node **)pv1)->data.eng;
	float sc2 = (*(struct student_node **)pv2)->data.math + 
                (*(struct student_node **)pv2)->data.chn +
                (*(struct student_node **)pv2)->data.eng;

	if(sc1 == sc2)
	{
		return 0;
	}
	else if(sc1 > sc2)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

/*按各科成绩对所有学生进行从高到低的排序
    type:
        1.按数学成绩排序 
        2.按语文成绩排序 
        3.按英语成绩排序 
        4.按总分成绩排序 
*/
struct student_node **sort_students_by_score(struct student_link *phead,int type)
{
	struct student_node **pp = NULL;
	struct student_node *pnode = NULL;
	int i = 0;
	int (*pf)(const void *,const void *) = NULL;

	if(phead == NULL || type < 1 || type > 4 || phead->cnt == 0)
	{
		Print_Error("Input param is invalid\n");
		return NULL;
	}

	/*分配空间用于存放phead->cnt个节点的地址值*/
	pp = (struct student_node **)malloc(phead->cnt * sizeof(struct student_node *));
	if(NULL == pp)
	{
		Print_Error("Malloc Failed\n");
		return NULL;
	}
	memset(pp,0,phead->cnt * sizeof(struct student_node *));

	/*将链表中每个节点的地址存放到上面分配的空间中*/
	pnode = phead->pstfirst;
	while(pnode != NULL)
	{
		*(pp + i) = pnode;
		i++;
		pnode = pnode->pstnext;
	}

	/*该空间实际是一个存放所有节点地址的数组,选择好相应的比较函数,对该数组进行快速排序*/
	switch(type)
	{
		case 1:
			pf = cmp_math_score;
			break;
		case 2:
			pf = cmp_chn_score;
			break;
		case 3:
			pf = cmp_eng_score;
			break;
		case 4:
			pf = cmp_total_score;
			break;
	}
	qsort(pp,phead->cnt,sizeof(struct student_node *),pf);

	/*返回空间首地址*/
	return pp;
}

/*销毁排序结果空间*/
int destroy_sorted_space(struct student_node **ppsort)
{
	if(ppsort != NULL)
	{
		free(ppsort);
		ppsort = NULL;
	}

	return 0;
}


