#include "sims_public.h"

static int main_loop(struct admin_data *padmin,struct teacher_link *pthead,struct student_link *pshead);
static int admin_login(struct admin_data *padmin);
static struct student_node * student_login(struct student_link *pslink);
static struct teacher_node * teacher_login(struct teacher_link *ptlink);

int admin_op(struct admin_data *padmin,struct teacher_link *ptlink);
int main(int argc,char *argv[])
{
	struct admin_data st_admin = {"admin","123456"};
	struct teacher_link *ptlink = create_teacher_link();
	struct student_link *pslink = create_student_link();

	main_loop(&st_admin,ptlink,pslink);	

	destroy_teacher_link(ptlink);
	ptlink = NULL;
	
	destroy_student_link(pslink);	
	pslink = NULL;
	return 0;
}

static int main_loop(struct admin_data *padmin,struct teacher_link *pthead,struct student_link *pshead)
{
	int op = -1;
	int exitflag = 0;
	struct teacher_node *ptnode = NULL;
	struct student_node *psnode = NULL;

	while(1)
	{
		/*显示主界面*/
		op = display_mainui();

		switch(op)
		{
			case 1://admin login
				if(0 == admin_login(padmin))
				{
					admin_op(padmin,pthead);
				}
				else
				{
					display_message("Admin Login Failed\n");
				}
				break;
			case 2://teacher login
				ptnode = teacher_login(pthead);
				if(ptnode != NULL)
				{
					//teacher_op(ptnode,pslink)
				}
				else
				{
					display_message("Teacher Login Failed\n");
				}
				break;
			case 3://student login
				psnode = student_login(pshead);
				if(psnode != NULL)
				{
					//student_op(psnode)
				}
				else
				{
					display_message("Student Login Failed\n");
				}
				break;
			case 0:
				exitflag = 1;
				break;
		}
		if(exitflag)
		{
			break;
		}
	}

	return 0;
}

static int admin_login(struct admin_data *padmin)
{
	char name[NAME_LEN] = "";
	char pass[PASS_LEN] = "";

	input_string(name,NAME_LEN,"Please input your username:\n");
	input_string(pass,PASS_LEN,"Please input your password:\n");
	
	if(strcmp(name,padmin->username))
	{
		display_message("Your Username is not correct\n");	
		return -1;
	}
	
	if(strcmp(pass,padmin->password))
	{
		display_message("Your Password is not correct\n");	
		return -2;
	}

	return 0;
}

static struct teacher_node * teacher_login(struct teacher_link *ptlink)
{
	return NULL;
}

static struct student_node * student_login(struct student_link *pslink)
{
	return NULL;
}
