#ifndef TEACHER_H
#define TEACHER_H

struct teacher_data
{
	int id;
	char username[NAME_LEN];
	char password[PASS_LEN];
	char sex;
	char birth[DATE_LEN];
};

struct teacher_node
{
	struct teacher_data data;
	struct teacher_node *pstnext;
};

struct teacher_link
{
	int cnt;
	struct teacher_node *pstlast;
	struct teacher_node *pstfirst;
};

/*创建节点*/
struct teacher_node *create_teacher_node(struct teacher_data *pdata);

/*销毁节点*/
int destroy_teacher_node(struct teacher_node *pnode);

/*创建头节点-----创建空表*/
struct teacher_link *create_teacher_link();

/*销毁头节点-----先删除所有节点，然后释放头节点的空间*/
int destroy_teacher_link(struct teacher_link *phead);


/*尾插*/
int insert_teacher_node_at_tail(struct teacher_link *phead,struct teacher_node *pnew);

/*移除指定节点*/
int remove_teacher_node(struct teacher_link *phead,struct teacher_node *pnode);

/*按工号查找节点*/
struct teacher_node * search_teacher_node_byid(struct teacher_link *phead,int id);
/*按用户名查找节点*/
struct teacher_node * search_teacher_node_byname(struct teacher_link *phead,char *pname);

/*修改指定节点的密码*/
int modify_teacher_password(struct teacher_node *pnode,char *pnewpass);

#endif
