#include "sims_public.h"

int print_all_teacher(struct teacher_link *phead);
int main(int argc,char *argv[])
{
	struct teacher_link *phead = create_teacher_link();
	struct teacher_data data = {1,"zhangsan","123456",'M',"2000-9-16"};
	struct teacher_node *pnew = NULL;
	
	pnew = create_teacher_node(&data);
	insert_teacher_node_at_tail(phead,pnew);
#if 1
	data.id = 2;
	strcpy(data.username,"lisi");
	strcpy(data.password,"111111");
	data.sex = 'F';
	strcpy(data.birth,"2001-10-11");
	pnew = create_teacher_node(&data);
	insert_teacher_node_at_tail(phead,pnew);
	
	data.id = 3;
	strcpy(data.username,"ruhua");
	strcpy(data.password,"222222");
	data.sex = 'F';
	strcpy(data.birth,"2001-1-19");
	pnew = create_teacher_node(&data);
	insert_teacher_node_at_tail(phead,pnew);

	data.id = 4;
	strcpy(data.username,"siyu");
	strcpy(data.password,"333333");
	data.sex = 'F';
	strcpy(data.birth,"2001-9-1");
	pnew = create_teacher_node(&data);
	insert_teacher_node_at_tail(phead,pnew);
#endif
	print_all_teacher(phead);

	{
		struct teacher_node *pnode = search_teacher_node_byid(phead,1);
		remove_teacher_node(phead,pnode);
		destroy_teacher_node(pnode);
		pnode = NULL;
		printf("##############After Remove###############################\n");
		print_all_teacher(phead);
	}

	destroy_teacher_link(phead);
	phead = NULL;
	return 0;
}

int print_all_teacher(struct teacher_link *phead)
{
	struct teacher_node *pnode = NULL;
	
	printf("The len of teacher-link-list is %d\n",phead->cnt);
	printf("%-4s %-20s %-4s %s\n","ID","Name","Sex","Birthdate");
	pnode = phead->pstfirst;
	while(pnode != NULL)
	{
		printf("%-4d %-20s %-4c %s\n",
			   pnode->data.id,
			   pnode->data.username,
			   pnode->data.sex,
			   pnode->data.birth
			  );
		pnode = pnode->pstnext;
	}

	return 0;
}
