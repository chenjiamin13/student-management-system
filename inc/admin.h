#ifndef ADMIN_H
#define ADMIN_H

struct admin_data
{
	char username[NAME_LEN];
	char password[PASS_LEN];
};

int modify_admin_password(struct admin_data *padmin,char *passwd);


#endif
