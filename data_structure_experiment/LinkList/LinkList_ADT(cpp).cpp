// 用C++来写，不用考虑指针和参数回传，直接使用引用参数

/* 引用头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 定义常量 */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100  // 初始链表长度
#define LISTINCREMENT 10    // 每次新增长度
#define MAX_LIST_NUM 10     // 链表数量最大值
#define MAX_NAME_LENGTH 30  // 每个线性表名称长度最大值
#define FileName "data(cpp).txt" // 文件名
/* 定义数据元素类型 */
typedef int ElemType;
typedef int status;
/* 单链表(链式结构)结点的定义 */
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
/* 链表的集合类型定义 */
typedef struct
{
    struct
    {
        char name[MAX_NAME_LENGTH]; // 链表名称
        LinkList L;                 // 指向链表表头的指针
    } elem[MAX_LIST_NUM];
    int length; // 当前链表数量
} LISTS;
LISTS Lists; // 链表集合实例化为Lists对象(全局变量)


/* 函数声明 */
status checkList(LinkList L); // 判断链表是否初始化
void printMenu1(void); // 链表集合的管理菜单
void printMenu2(void); // 单个链表的操作菜单
status AddList(LISTS &LL,char *name); // 新增一个链表
status RemoveList(LISTS &LL,char *name); // 移除一个链表
status ShowAllLists(LISTS Lists); // 显示所有链表
int SelectList(LISTS Lists,char *name); // 选择一个链表并进入子菜单
void main2(LinkList &L); // 操作单个链表的子页面
status InitList(LinkList &L); // 初始化链表
status DestroyList(LinkList &L); // 销毁链表 
status ClearList(LinkList &L); // 清空链表元素 
status ListEmpty(LinkList L); // 判断链表是否为空 
int ListLength(LinkList L); // 链表长度 
status GetElem(LinkList L,int i,ElemType &e); // 获取第i个元素 
status LocateElem(LinkList L,ElemType e); // 获取元素位置 
status PriorElem(LinkList L,ElemType e,ElemType &pre); // 获取前驱元素
status NextElem(LinkList L,ElemType e,ElemType &next); // 获取后继元素 
status ListInsert(LinkList &L,int i,ElemType e); // 指定位置前插入元素
status ListDelete(LinkList &L,int i,ElemType &e); // 删除指定位置元素
void visit(ElemType item); // 用于遍历时输出 */
status ListTraverse(LinkList L,void (*visit)(ElemType)); // 显示当前链表所有元素


/* 主函数 */
int main()
{
    printMenu1();
    Lists.length=0;
    int op=1;
    while(op)
    {
        // 提示用户选择操作
        printf("\n|-------------------------------------------------------------|\n");
        printf(  "|-------Please Choose Your Operation from Options above-------|\n");
        printf(  "|-------------------------------------------------------------|\n\n");
        scanf("%d", &op); // 读取用户输入
        system("cls");    // 清屏
        printMenu1();
        switch(op)
        {
            case 1: // 创建一个链表
            {
                printf("|-------------------------------------------------------------|\n"
                       "|---------You can create a total of %d linear tables.---------|\n",
                       MAX_LIST_NUM); // 可创建线性表总数
                // 当前创建线性表的数量
                if (Lists.length > 1)
                    printf("|--------Currently, %d linear tables have been created.--------|\n", Lists.length);
                else
                    printf("|---------Currently, %d linear table has been created.---------|\n", Lists.length);
                printf("|-------------------------------------------------------------|\n\n");
                char add_name[MAX_NAME_LENGTH];
                printf("Please enter the name of the linear table you want to add : \n");
                scanf("%s", add_name);
                if (AddList(Lists, add_name) == OK) // 创建成功
                    printf("The linear table (name: %s) is created!\n", add_name);
                else
                    printf("The linear table already exists.\n");
                break;
            }
            case 2: // 删除一个链表
            {
                char remove_name[MAX_NAME_LENGTH];
                printf("Please enter the name of the linear table you want to delete : \n");
                scanf("%s", remove_name);
                if (RemoveList(Lists, remove_name) == OK) // 删除成功
                    printf("The linear table (name: %s) is deleted!\n", remove_name);
                else
                    printf("The linear table does not exist.\n");
                break;
            }
            case 3: // 显示所有链表
            {
                ShowAllLists(Lists);
                break;
            } 
            case 4: // 选择一个链表并进入子菜单
            {
                char select_name[MAX_NAME_LENGTH];
                printf("Please enter the name of the linear table you want to select : \n");
                scanf("%s", select_name);
                int loc = SelectList(Lists, select_name); // 所选链表在链表集合的位置
                if (loc != -1) // 所选链表存在
                    {
                        main2(Lists.elem[loc].L);  // 跳转至子页面
                        printMenu1();
                    }
                else
                    printf("The linear table does not exist.\n");
                break;
            }
            case 0:
                break;
            default:
                printf("The feature number is incorrect.\n"); // 功能选项错误
        }
    }
    printf("Welcome to use this system next time!\n");
    return 0;
}

/* 操作单个链表的子页面 */
void main2(LinkList &L)
{
    system("cls");
    printMenu2();
    int op=1;
    int flag = 1; // 初次进入该页面，提醒用户初始化
    while(op)
    {
        if (L == NULL && flag)
        {
            printf("Don't forget to initialize current List.\n");
            flag = 0;
        }
        // 提示用户选择操作
        printf("\n|-------------------------------------------------------------|\n");
        printf(  "|-------Please Choose Your Operation from Options above-------|\n");
        printf(  "|-------------------------------------------------------------|\n\n");
        scanf("%d", &op); // 读取用户输入
        system("cls");    // 清屏
        printMenu2();
        switch(op)
        {
            case 1:
                if (InitList(L) == OK)
                    printf("Successfully initialized!\n");
                else
                    printf("You've initialized current List!\n");
                break;
            case 2:
                if (checkList(L))
                {
                    if (DestroyList(L) == OK)
                        printf("Successfully destroyed!\n");
                }
                break;
            case 3:
                if (checkList(L))
                {
                    if (ClearList(L) == OK)
                        printf("Successfully cleared!\n");
                }
                break;
            case 4:
                if (checkList(L))
                {
                    if (ListEmpty(L) == TRUE)
                        printf("The List is empty.\n");
                    else if (ListEmpty(L) == FALSE)
                        printf("The List is not empty.\n");
                }
                break;
            case 5:
                if (checkList(L))
                {
                    if (ListLength(L) != INFEASIBLE)
                        printf("The length of the List is : %d.\n", ListLength(L));
                }
                break;
            case 6:
                if (checkList(L)) // 已初始化
                {
                    if (ListLength(L))
                    {
                        printf("Please enter the position (between 1 to %d) you want to query:\n", ListLength(L));
                        int queryPosition; // 查询的位置
                        scanf("%d", &queryPosition);
                        ElemType queryResult;                             // 查询的结果
                        if (GetElem(L, queryPosition, queryResult) == OK) // 位置合法
                            printf("The element is %d.\n", queryResult);
                        else if (GetElem(L, queryPosition, queryResult) == ERROR) // 位置不合法
                            printf("The position is illegal.\n");
                    }
                    else
                        printf("There is no element.\n");
                }
                break;
            case 7:
                if (checkList(L))
                {
                    if (ListLength(L))
                    {
                        printf("Please enter the element you want to locate.\n");
                        ElemType queryElem_locate; // 查询的元素
                        scanf("%d", &queryElem_locate);
                        if (LocateElem(L, queryElem_locate) != ERROR) // 存在
                            printf("The position of %d is %d.\n", queryElem_locate, LocateElem(L, queryElem_locate));
                        else
                            printf("The element does not exist.\n"); // 不存在
                    }
                    else
                        printf("There is no element.\n");
                }
                break;
            case 8:
                if (checkList(L))
                {
                    if(ListLength(L))
                    { 
                        printf("Please enter the element you want to query:\n");
                        ElemType queryElem_prior, pre; // 查询的元素及前驱元素
                        scanf("%d", &queryElem_prior);
                        if (PriorElem(L, queryElem_prior, pre) == OK) // 位置合法且元素存在
                            printf("The prior element of %d is %d.\n", queryElem_prior, pre);
                        else if (PriorElem(L, queryElem_prior, pre) == ERROR) // 位置不合法或元素不存在
                            printf("failed to find.\n");
                    }
                    else printf("There is no element.\n");
                }    
                break;
            case 9:
                if (checkList(L))
                {
                    if (ListLength(L))
                    {
                        printf("Please enter the element you want to query:\n");
                        ElemType queryElem_next, next; // 查询的元素及后继元素
                        scanf("%d", &queryElem_next);
                        if (NextElem(L, queryElem_next, next) == OK) // 位置合法且元素存在
                            printf("The next element of %d is %d.\n", queryElem_next, next);
                        else if (NextElem(L, queryElem_next, next) == ERROR) // 位置不合法或元素不存在
                            printf("failed to find.\n");
                    }
                    else
                        printf("There is no element.\n");
                }
                break;
            case 10:
                if (checkList(L))
                {
                    printf("Position: (between 1 to %d)\n", ListLength(L) + 1); // 可供选择的位置
                    printf("Please enter the position and the element you want to insert:(spaced by space)\n");
                    int insertPosition;  // 插入的位置
                    ElemType insertElem; // 插入的元素
                    scanf("%d %d", &insertPosition, &insertElem);
                    if (ListInsert(L, insertPosition, insertElem) == OK) // 插入成功
                        printf("Successfully inserted.\n");
                    else if (ListInsert(L, insertPosition, insertElem) == ERROR) // 插入失败
                        printf("The position is illegal.\n");
                }
                break;
            case 11:
                if(checkList(L))
                {
                    if(ListLength(L))
                    {
                        printf("Position: (between 1 to %d)\n", ListLength(L)); // 可供选择的位置
                        printf("Please enter the position you want to delete:\n");
                        int deletePosition;  // 删除的位置
                        ElemType deleteElem; // 删除的元素
                        scanf("%d", &deletePosition);
                        if (ListDelete(L, deletePosition, deleteElem) == OK) // 删除成功
                            printf("Delete %d in position %d.\n", deleteElem, deletePosition);
                        else if (ListDelete(L, deletePosition, deleteElem) == ERROR) // 删除失败
                            printf("The position is illegal.\n");
                    }
                    else
                        printf("There is no element.\n");
                }
                break;
            case 12:
                if(checkList(L))
                {
                    if(ListLength(L))
                    {
                        if (ListTraverse(L, visit) == OK) // 成功遍历
                            printf("\nSuccessfully traveled all elements.\n");
                    }
                    else
                        printf("There is no element.\n");
                }
                break;
            case 0:
                system("cls");
                return;
            default:
                printf("The feature number is incorrect.\n");
        } // end of switch
    } // end of while
}

/* 判断链表是否初始化 */
status checkList(LinkList L)
{
    if(L==NULL)
    {
        printf("You haven't initialized.\n");
        return FALSE;
    }
    return TRUE;
}

/* 链表集合的管理菜单 */
void printMenu1()
{
    printf("|=================Menu for multiple LinkLists=================|\n");
    printf("|-------------------------------------------------------------|\n");
    printf("|                 1.    Create a LinkList                     |\n"); // 打印操作1的描述
    printf("|                 2.    Delete a LinkList                     |\n"); // 打印操作2的描述
    printf("|                 3.    Show all LinkLists                    |\n"); // 打印操作3的描述
    printf("|                 4. Select a single LinkList                 |\n"); // 打印操作4的描述
    printf("|                 0.          EXIT                            |\n"); // 打印操作0的描述
    printf("|=============================================================|\n\n");
}

/* 单个链表的操作菜单 */
void printMenu2()
{
    printf("|===================Menu for single LinkList==================|\n");
    printf("|-------------------------------------------------------------|\n");
    printf("|      1.  Init Current List      2.  Destroy Current List    |\n");
    printf("|      3.  Clear Current List     4.  Empty or Not            |\n");
    printf("|      5.  Show List Length       6.  Get Element             |\n");
    printf("|      7.  Locate Element         8.  Get Prior Element       |\n");
    printf("|      9.  Get Next Element       10. Insert Element          |\n");
    printf("|      11. Delete Element         12. Show All Element        |\n");
    printf("|                        0.  EXIT                             |\n");
    printf("|-------------------------------------------------------------|\n\n");
}

/* 新增一个链表 */
status AddList(LISTS &LL,char *name)
{
    // 查询是否存在同名链表
    for (int i = 0; i < LL.length; i++)
        if (strcmp(LL.elem[i].name, name) == 0)
            return INFEASIBLE;
    // 不存在，可以新增
    strcpy(LL.elem[LL.length].name, name); // 给链表名称赋值
    LL.elem[LL.length].L = NULL;           // 头指针初始化为空(未初始化状态)
    LL.length++;                            // 长度加一
    return OK;
}

/* 移除一个链表 */
status RemoveList(LISTS &LL,char *name)
{
    // 查询是否存在
    for (int loc = 0; loc < LL.length; loc++)
    {
        if (strcmp(LL.elem[loc].name, name) == 0) // 存在
        {
            // DestroyList(LL.elem[loc].L); // 先销毁本身空间
            for (int i = loc; i < LL.length - 1; i++)
                LL.elem[i] = LL.elem[i + 1];
            LL.length--;
            return OK; // 移除成功
        }
    }
    return ERROR; // 不存在，返回错误
}

/* 显示所有链表 */
status ShowAllLists(LISTS Lists)
{
    if(Lists.length==0) printf("There are no linear tables.\n");
    for (int i = 0; i < Lists.length; i++)
    {
        printf("num%d\n", i+1);                  // 打印序号
        printf("name:%s\n", Lists.elem[i].name); // 打印名称
        printf("elements:");
        if (Lists.elem[i].L == NULL) // 未初始化
            printf("You haven't initialized.");
        else if (Lists.elem[i].L->next == NULL) // 无元素
            printf("none");
        else
            ListTraverse(Lists.elem[i].L,visit); //遍历
        printf("\n");
    }
    return OK;
}

/* 选择一个链表并进入子菜单 */
int SelectList(LISTS Lists, char *name)
{
    for (int i = 0; i < Lists.length; i++)
        if (strcmp(Lists.elem[i].name, name) == 0) // 所选链表存在
            return i; // 返回位置
    return -1;
}

/* 初始化链表 */
status InitList(LinkList &L)
{
    if(L==NULL)
    {
        L=(LinkList)malloc(sizeof(LNode));
        L->next=NULL;
        return OK;
    }
    else return INFEASIBLE;
}

/* 销毁链表 */
status DestroyList(LinkList &L)
{
    if(L)
    {
        LinkList p=L;
        while(L)
        {
            L=L->next;
            free(p);
            p=L;
        }
        return OK;
    }
    else return INFEASIBLE;
}

/* 清空链表元素 */
status ClearList(LinkList &L)
{
    if(L)
    {
        LinkList p=L->next;
	    L->next=NULL;
	    DestroyList(p);
        return OK;
    }
    else return INFEASIBLE;
}

/* 判断链表是否为空 */
status ListEmpty(LinkList L)
{
    if(L)
    {
        if(L->next) return FALSE;
        else return TRUE;
    }
    else return INFEASIBLE;
}

/* 链表长度 */
int ListLength(LinkList L)
{
    if(L)
    {
        int i=0;
        while(L->next)
        {
            i++;
            L=L->next;
        }
        return i;
    }
    else return INFEASIBLE;
}

/* 获取第i个元素 */
status GetElem(LinkList L, int i, ElemType &e)
{
    if (L)
    {
        int len = ListLength(L);
        if (i <= 0 || i > len)
            return ERROR;
        else
        {
            while (i--)
                L = L->next;
            e = L->data;
            return OK;
        }
    }
    else
        return INFEASIBLE;
}

/* 获取元素位置 */
int LocateElem(LinkList L,ElemType e)
{
    if(L)
    {
        int i=0;
        L=L->next;
        while(L)
        {
            i++;
            if(L->data==e) return i;
            L=L->next;
        }
        return ERROR;
    }
    else return INFEASIBLE;
}

/* 获取前驱元素 */
status PriorElem(LinkList L,ElemType e,ElemType &pre)
{
    if(L)
    {
        if(L->next==NULL) return ERROR;
        if(L->next->data==e) return ERROR;
        else
        {
            L=L->next;
            while(L->next)
            {
                if(L->next->data==e) 
                {
                    pre=L->data;
                    return OK;
                }
                L=L->next;
            }
            return ERROR;
        }
    }
    else return INFEASIBLE;
}

/* 获取后继元素 */
status NextElem(LinkList L,ElemType e,ElemType &next)
{
    if(L)
    {
        if(L->next==NULL) return ERROR;
        L=L->next;
        while(L)
        {
            if(L->data==e)
            {
                if(L->next==NULL) return ERROR;
                else{
                    next=L->next->data;
                    return OK;
                }
            }
            L=L->next;
        }
        return ERROR;
    }
    else return INFEASIBLE;
}

/* 指定位置前插入元素 */
status ListInsert(LinkList &L,int i,ElemType e)
{
    if(!L) return INFEASIBLE;
    int len=ListLength(L);
    if(i<1||i>len+1) return ERROR;
    LinkList ll=L;
    while(--i) ll=ll->next;
    LinkList p=ll->next;
    LinkList temp=(LinkList)malloc(sizeof(LNode));
    temp->data=e;
    ll->next=temp;
    temp->next=p;
    return OK;
}

/* 删除指定位置元素 */
status ListDelete(LinkList &L,int i,ElemType &e)
{
    if(!L) return INFEASIBLE;
    int len=ListLength(L);
    if(i<1||i>len) return ERROR;
    LinkList ll=L;
    while(--i) ll=ll->next;
    LinkList p=ll->next;
    e=p->data;
    ll->next=ll->next->next;
    free(p);
    return OK;
}

/* 用于遍历时输出 */
void visit(ElemType item)
{
    // 输出当前遍历到的元素
    printf("%d ", item);
}

/* 显示当前链表所有元素 */
status ListTraverse(LinkList L,void (*visit)(ElemType))
{
    if(!L) return INFEASIBLE;
    while(L->next)
    {
        L=L->next;
        visit(L->data);
    }
    return OK;
}
