#include "sims_public.h"
.
int admin_op(struct admin_data *padmin,struct teacher_link *ptlink)
{
	int op = -1;
	int backflag = 0;

	while(1)
	{
		op = display_adminui();
		switch(op)
		{
			case 1://modify admin password
				//do_modify_admin_password(...)
				break;
			case 2://Add New Teacher
				//do_add_new_teacher(...)
				break;
			case 3://Display All Teachers
				//do_diaplay_all_teachers(...)
				break;
			case 4://Delete A Teacher
				//do_delete_a_teacher(....)
				break;
			case 5://Modify A Teacher
				//do_modify_a_teacher(....)
				break;
			case 0:
				backflag = 1;
				break;
		}
		if(backflag)
		{
			break;
		}
	}

	return 0;
}
