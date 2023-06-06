#include "sims_public.h"

int print_all_student(struct student_link *phead);
int print_sort_student(struct student_node **pp,int cnt);
int main(int argc,char *argv[])
{
	struct student_link *phead = create_student_link();
	struct student_data data = {1,"zhangsan","123456",'M',"2000-9-16",71,82,63};
	struct student_node *pnew = NULL;
	
	pnew = create_student_node(&data);
	insert_student_node_at_tail(phead,pnew);
#if 1 
	data.id = 2;
	strcpy(data.username,"lisi");
	strcpy(data.password,"111111");
	data.sex = 'F';
	strcpy(data.birth,"2001-10-11");
	data.chn = 51;
	data.eng = 62;
	data.math = 93;
	pnew = create_student_node(&data);
	insert_student_node_at_tail(phead,pnew);
	
	data.id = 3;
	strcpy(data.username,"ruhua");
	strcpy(data.password,"222222");
	data.sex = 'F';
	strcpy(data.birth,"2001-1-19");
	data.chn = 81;
	data.eng = 76;
	data.math = 83;
	pnew = create_student_node(&data);
	insert_student_node_at_tail(phead,pnew);

	data.id = 4;
	strcpy(data.username,"siyu");
	strcpy(data.password,"333333");
	data.sex = 'F';
	strcpy(data.birth,"2001-9-1");
	data.chn = 82;
	data.eng = 67;
	data.math = 95;
	pnew = create_student_node(&data);
	insert_student_node_at_tail(phead,pnew);
#endif
	print_all_student(phead);

	{
		struct student_node **ppsort = NULL;
		ppsort = sort_students_by_score(phead,4);
		print_sort_student(ppsort,phead->cnt);
		destroy_sorted_space(ppsort);
		ppsort = NULL;
	}	
	{
		struct student_node *pnode = search_student_node_byid(phead,1);
		remove_student_node(phead,pnode);
		destroy_student_node(pnode);
		pnode = NULL;
		printf("##############After Remove###############################\n");
		print_all_student(phead);
	}

	destroy_student_link(phead);
	phead = NULL;
	return 0;
}

int print_all_student(struct student_link *phead)
{
	struct student_node *pnode = NULL;
	
	printf("The len of student-link-list is %d\n",phead->cnt);
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

int print_sort_student(struct student_node **pp,int cnt)
{
	int i = 0;
	
	printf("%-4s %-20s %-4s %6s %6s %6s %6s %s\n","ID","Name","Sex","Math","Chn","Eng","Total","Birthdate");
	for(i = 0;i < cnt;i++)
	{
		printf("%-4d %-20s %-4c %6.1f %6.1f %6.1f %6.1f %s\n",
			   (*(pp+i))->data.id,
			   (*(pp+i))->data.username,
			   (*(pp+i))->data.sex,
			   (*(pp+i))->data.math,
			   (*(pp+i))->data.chn,
			   (*(pp+i))->data.eng,
			   (*(pp+i))->data.eng + (*(pp+i))->data.chn + (*(pp+i))->data.math,
			   (*(pp+i))->data.birth
			  );
	}

	return 0;
}
