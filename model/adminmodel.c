#include "sims_public.h"

int modify_admin_password(struct admin_data *padmin,char *passwd)
{
	int len = 0;

	if(passwd == NULL || padmin == NULL)
	{
		Print_Error("Input param is invalid\n");
		return -1;
	}

	len = strlen(passwd);
	if(len > PASS_LEN - 1)
	{
		Print_Error("New password is too long\n");
		return -1;
	}

	strcpy(padmin->password,passwd);
	return 0;
}
