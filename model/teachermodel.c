#include "sims_public.h"

/*创建节点*/
struct teacher_node *create_teacher_node(struct teacher_data *pdata)
{
	struct teacher_node *pnew = NULL;
	
	pnew = (struct teacher_node *)malloc(sizeof(struct teacher_node));
	if(NULL == pnew)
	{
		Print_Error("Malloc failed\n");
		return NULL;
	}
	memset(pnew,0,sizeof(struct teacher_node));

	memcpy(&pnew->data,pdata,sizeof(struct teacher_data));
	return pnew;
}

/*销毁节点*/
int destroy_teacher_node(struct teacher_node *pnode)
{
	if(pnode != NULL)
	{
		free(pnode);
		pnode = NULL;
	}

	return 0;
}

/*创建头节点-----创建空表*/
struct teacher_link *create_teacher_link()
{
	struct teacher_link *pnew = NULL;
	
	pnew = (struct teacher_link *)malloc(sizeof(struct teacher_link));
	if(NULL == pnew)
	{
		Print_Error("Malloc failed\n");
		return NULL;
	}
	memset(pnew,0,sizeof(struct teacher_link));

	return pnew;
}

/*销毁头节点-----先删除所有节点，然后释放头节点的空间*/
int destroy_teacher_link(struct teacher_link *phead)
{
	struct teacher_node *pnext = NULL;
	struct teacher_node *pnode = NULL;

	/*销毁所有节点*/
	pnode = phead->pstfirst;
	while(pnode != NULL)
	{
		pnext = pnode->pstnext;
		destroy_teacher_node(pnode);
		pnode = pnext;
	}
	
	/*释放头节点的空间*/
	free(phead);
	phead = NULL;
	return 0;
}


/*尾插*/
int insert_teacher_node_at_tail(struct teacher_link *phead,struct teacher_node *pnew)
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
int remove_teacher_node(struct teacher_link *phead,struct teacher_node *pnode)
{
	struct teacher_node *pprev = NULL;

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
		struct teacher_node *ptemp = NULL;

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

/*按工号查找节点*/
struct teacher_node * search_teacher_node_byid(struct teacher_link *phead,int id)
{
	struct teacher_node *pnode = NULL;

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
struct teacher_node * search_teacher_node_byname(struct teacher_link *phead,char *pname)
{
	struct teacher_node *pnode = NULL;

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
int modify_teacher_password(struct teacher_node *pnode,char *pnewpass)
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

