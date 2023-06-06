#ifndef STUDENT_H
#define STUDENT_H

struct student_data
{
	int id;
	char username[NAME_LEN];
	char password[PASS_LEN];
	char sex;
	char birth[DATE_LEN];
	float math;
	float chn;
	float eng;
};

struct student_node
{
	struct student_data data;
	struct student_node *pstnext;
};

struct student_link
{
	int cnt;
	struct student_node *pstlast;
	struct student_node *pstfirst;
};

/*创建节点*/
struct student_node *create_student_node(struct student_data *pdata);

/*销毁节点*/
int destroy_student_node(struct student_node *pnode);

/*创建头节点-----创建空表*/
struct student_link *create_student_link();

/*销毁头节点-----先删除所有节点，然后释放头节点的空间*/
int destroy_student_link(struct student_link *phead);


/*尾插*/
int insert_student_node_at_tail(struct student_link *phead,struct student_node *pnew);

/*移除指定节点*/
int remove_student_node(struct student_link *phead,struct student_node *pnode);

/*按工号查找节点*/
struct student_node * search_student_node_byid(struct student_link *phead,int id);
/*按用户名查找节点*/
struct student_node * search_student_node_byname(struct student_link *phead,char *pname);

/*修改指定节点的密码*/
int modify_student_password(struct student_node *pnode,char *pnewpass);

/*按各科成绩对所有学生进行从高到低的排序
	type:
		1.按数学成绩排序 
		2.按语文成绩排序 
		3.按英语成绩排序 
		4.按总分成绩排序 
*/
struct student_node **sort_students_by_score(struct student_link *phead,int type);

/*销毁排序结果空间*/
int destroy_sorted_space(struct student_node **ppsort);
#endif
