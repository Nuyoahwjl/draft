#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*定义常量*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

/*定义数据类型*/
typedef int status;
typedef int ElemType;       // 数据元素类型定义
#define LIST_INIT_SIZE 100  // 线性表初始容量
#define LISTINCREMENT 10    // 线性表扩容容量
#define MAX_LIST_NUM 10     // 线性表数量最大值
#define MAX_NAME_LENGTH 30  // 每个线性表名称长度最大值
#define FileName "data.txt" // 文件名
// char FileName[MAX_NAME_LENGTH];

/*线性表（顺序结构）的定义*/
typedef struct
{
    ElemType *elem; // 存储空间基址
    int length;     // 当前长度
    int listsize;   // 当前分配的存储容量
} SqList;

/*线性表的集合类型定义*/
typedef struct
{
    struct
    {
        char name[MAX_NAME_LENGTH]; // 线性表名称
        SqList *L;                  // 指向线性表的指针
    } elem[MAX_LIST_NUM];
    int length; // 当前线性表数量
} LISTS;

/*全局变量*/
LISTS Lists;     // 线性表集合Lists
int current = 0; // 当前线性表在Lists中的位置

/*函数声明*/
void printMenu();                                         // 打印菜单
void clearAllList(LISTS Lists);                           // Lists初始化
status checkList(SqList *L);                              // 检查线性表合法性
void visit(ElemType item);                                // 用于遍历时输出
status InitList(SqList *L);                               // 初始化线性表
status DestroyList(LISTS *Lists,int current);                            // 销毁线性表
status ClearList(SqList *L);                              // 清空线性表
status ListEmpty(SqList L);                               // 判断线性表是否为空
int ListLength(SqList L);                                 // 获取线性表长度
status GetElem(SqList L, int i, ElemType *e);             // 获取线性表指定位置元素
int LocateElem(SqList L, ElemType e);                     // 定位元素在线性表中的位置
status PriorElem(SqList L, ElemType e, ElemType *pre);    // 获取指定元素的前驱
status NextElem(SqList L, ElemType e, ElemType *next);    // 获取指定元素的后继
status ListInsert(SqList *L, int i, ElemType e);          // 在指定位置插入元素
status ListDelete(SqList *L, int i, ElemType *e);         // 删除指定位置元素
status ListTraverse(SqList L, void (*visit)(ElemType));   // 遍历线性表
status SortCurrent(SqList *L);                            // 对当前线性表排序
ElemType MaxSubArray(SqList L);                           // 获取当前线性表的最大子数组和
int SubArrayNum(SqList L, ElemType k);                    // 获取当前线性表中和为k的连续子数组个数
void ShowAllList(LISTS Lists);                            // 显示所有线性表
SqList *ChangeList(char ListName[], int *current);        // 切换当前线性表
status RemoveList(LISTS *Lists, char ListName[], int *p); // 移除指定线性表
status SaveData(LISTS Lists);                             // 将线性表数据保存到文件
status LoadData(LISTS *LL);                               // 从文件加载线性表数据

/*打印菜单*/
void printMenu()
{
    printf("|---------Menu for Linear Table On Sequence Structure---------|\n");
    printf("|                                                             |\n");
    printf("|      1.  Create a List          2.  Destroy Current List    |\n");
    printf("|      3.  Clear current List     4.  Empty or Not            |\n");
    printf("|      5.  Show List Length       6.  Get Element             |\n");
    printf("|      7.  Locate Elem            8.  Get Prior Element       |\n");
    printf("|      9.  Get Next Element       10. Insert Element          |\n");
    printf("|      11. Delete Element         12. Show Current List       |\n");
    printf("|      13. Sort Current List      14. Max Sub Array           |\n");
    printf("|      15. Sub Array Num          16. Show All Lists          |\n");
    printf("|      17. Change Current List    18. Remove a List           |\n");
    printf("|      19. Save All Data          20. Load All Data           |\n");
    printf("|                        0.  EXIT                             |\n");
    printf("|                                                             |\n");
    printf("|-------------------------------------------------------------|\n\n");
    // printf("|-------Please Choose Your Operation from Options above-------|\n");
    // printf("|-------------------------------------------------------------|\n\n");
}

/*Lists初始化，将所有线性表指针置为空*/
void clearAllList(LISTS Lists)
{
    // 遍历所有线性表指针，将其置为空
    for (int i = 0; i < MAX_LIST_NUM; i++)
        Lists.elem[i].L = NULL;
}

/*检查当前线性表是否合法*/
status checkList(SqList *L)
{
    // 检查线性表指针是否为空，为空则输出提示信息
    if (!L)
    {
        printf("The linear table does not exist.\n");
        printf("You can enter 1 to create a list or 17 to choose a list.\n");
        return FALSE;
    }
    // 检查线性表是否已经初始化，未初始化则输出提示信息
    else if (!L->elem)
    {
        printf("You need to initialize first.\n");
        return FALSE;
    }
    // 线性表合法，返回TRUE
    else
        return TRUE;
}

/*用于遍历时输出*/
void visit(ElemType item)
{
    // 输出当前遍历到的元素
    printf("%d ", item);
}

/*主函数*/
int main()
{
    printMenu();         // 打印菜单
    clearAllList(Lists); // 初始化Lists
    SqList *L = NULL;    // 当前线性表指针
    Lists.length = 0;    // 当前线性表数量初始化为0
    int op = 1;          // 操作选项
    while (op)
    {
        // 提示用户选择操作
        printf("\n|-------------------------------------------------------------|\n");
        printf("|-------Please Choose Your Operation from Options above-------|\n");
        printf("|-------------------------------------------------------------|\n\n");
        scanf("%d", &op); // 读取用户输入
        system("cls");    // 清屏
        printMenu();
        switch (op)
        {
        case 1: // 创建线性表
            printf("|-------------------------------------------------------------|\n");
            printf("|---------You can create a total of %d linear tables.---------|\n", MAX_LIST_NUM); // 可创建线性表总数
            // 当前创建线性表的数量
            if (Lists.length > 1)
                printf("|--------Currently, %d linear tables have been created.--------|\n", Lists.length);
            else
                printf("|---------Currently, %d linear table has been created.---------|\n", Lists.length);
            printf("|-------------------------------------------------------------|\n\n");
            if (Lists.length < MAX_LIST_NUM) // 容量未满
            {
                printf("|-------------------------------------------------------------|\n");
                printf("|--When you create a linear table, it is selected by default--|\n");
                printf("|-------------------------------------------------------------|\n");
                printf("\nPlease enter the name of the linear table you want to add : \n");
                char s[MAX_NAME_LENGTH];
                scanf("%s", s); // 新增线性表名称
                int flag = 1;   // 新增的线性表是否存在
                for (int i = 0; i < Lists.length; i++)
                {
                    // 在已有线性表中查找
                    if (strcmp(Lists.elem[i].name, s) == 0)
                        flag = 0;
                }
                if (flag) // 新增线性表不存在
                {
                    Lists.elem[Lists.length].L = (SqList *)malloc(sizeof(SqList));
                    strcpy(Lists.elem[Lists.length].name, s);
                    L = Lists.elem[Lists.length].L; // 当前线性表指针指向新创建的线性表
                    current = Lists.length;         // 更新当前位置
                    L->elem = NULL;                 // 初始化为空
                    Lists.length++;                 // 线性表数量加一
                    // 初始化
                    if (InitList(L) == OK)
                        printf("The linear table (name: %s) is created!\n", s);
                    else
                        printf("Failed to create a linear table!\n");
                }
                else // 新增线性表存在
                    printf("The linear table already exists.\n");
                getchar();
                break;
            }
            else
            {
                printf("Capacity is full!\n"); // 容量已满
                getchar();
                break;
            }
        case 2: // 销毁当前线性表
            if (checkList(L))
            {
                if (DestroyList(&Lists,current) == OK) // 销毁成功
                {    
                    L=NULL;
                    printf("The linear table was successfully destroyed.\n");
                }
            }
            getchar();
            break;
        case 3: // 清空当前线性表
            if (checkList(L))
            {
                if (ClearList(L) == OK) // 清空成功
                    printf("The linear table was successfully cleared.\n");
            }
            getchar();
            break;
        case 4: // 判断当前线性表是否为空
            if (checkList(L))
            {
                if (ListEmpty(*L) == TRUE) // 为空
                    printf("The linear table is empty.\n");
                else if (ListEmpty(*L) == FALSE) // 不为空
                    printf("The linear table is not empty.\n");
            }
            getchar();
            break;
        case 5: // 获取当前线性表长度
            if (checkList(L))
            {
                if (ListLength(*L) != INFEASIBLE) // 返回长度
                    printf("The length of the linear table is:%d\n", ListLength(*L));
            }
            getchar();
            break;
        case 6: // 获取指定位置元素
            if (checkList(L))
            {
                printf("Please enter the position (between 1 to %d) you want to query:\n", ListLength(*L));
                int queryPosition; // 查询的位置
                scanf("%d", &queryPosition);
                ElemType queryResult;                               // 查询的结果
                if (GetElem(*L, queryPosition, &queryResult) == OK) // 位置合法
                    printf("The element is %d.\n", queryResult);
                else if (GetElem(*L, queryPosition, &queryResult) == ERROR) // 位置不合法
                    printf("The position is illegal.\n");
            }
            getchar();
            break;
        case 7: // 定位元素在线性表中的位置
            if (checkList(L))
            {
                printf("Please enter the element you want to locate.\n");
                ElemType queryElem_locate; // 查询的元素
                scanf("%d", &queryElem_locate);
                if (LocateElem(*L, queryElem_locate) != ERROR) // 存在
                    printf("The position of %d is %d.\n", queryElem_locate, LocateElem(*L, queryElem_locate));
                else
                    printf("The element does not exist.\n"); // 不存在
            }
            getchar();
            break;
        case 8: // 获取指定元素的前驱
            if (checkList(L))
            {
                printf("Please enter the element you want to query:\n");
                ElemType queryElem_prior, pre; // 查询的元素及前驱元素
                scanf("%d", &queryElem_prior);
                if (PriorElem(*L, queryElem_prior, &pre) == OK) // 位置合法且元素存在
                    printf("The prior element of %d is %d.\n", queryElem_prior, pre);
                else if (PriorElem(*L, queryElem_prior, &pre) == ERROR) // 位置不合法或元素不存在
                    printf("failed to find.\n");
            }
            getchar();
            break;
        case 9: // 获取指定元素的后继
            if (checkList(L))
            {
                printf("Please enter the element you want to query:\n");
                ElemType queryElem_next, next; // 查询的元素及后继元素
                scanf("%d", &queryElem_next);
                if (NextElem(*L, queryElem_next, &next) == OK) // 位置合法且元素存在
                    printf("The next element of %d is %d.\n", queryElem_next, next);
                else if (NextElem(*L, queryElem_next, &next) == ERROR) // 位置不合法或元素不存在
                    printf("failed to find.\n");
            }
            getchar();
            break;
        case 10: // 在指定位置插入元素
            if (checkList(L))
            {
                printf("Position: (between 1 to %d)\n", ListLength(*L) + 1); // 可供选择的位置
                printf("Please enter the position and the element you want to insert:(spaced by space)\n");
                int insertPosition;  // 插入的位置
                ElemType insertElem; // 插入的元素
                scanf("%d %d", &insertPosition, &insertElem);
                if (ListInsert(L, insertPosition, insertElem) == OK) // 插入成功
                    printf("Successfully inserted.\n");
                else if (ListInsert(L, insertPosition, insertElem) == ERROR) // 插入失败
                    printf("The position is illegal.\n");
            }
            getchar();
            break;
        case 11: // 删除指定位置元素
            if (checkList(L))
            {
                printf("Position: (between 1 to %d)\n", ListLength(*L)); // 可供选择的位置
                printf("Please enter the position you want to delete:\n");
                int deletePosition;  // 删除的位置
                ElemType deleteElem; // 删除的元素
                scanf("%d", &deletePosition);
                if (ListDelete(L, deletePosition, &deleteElem) == OK) // 删除成功
                    printf("Delete %d in position %d.\n", deleteElem, deletePosition);
                else if (ListDelete(L, deletePosition, &deleteElem) == ERROR) // 删除失败
                    printf("The position is illegal.\n");
            }
            getchar();
            break;
        case 12: // 显示当前线性表
            if (checkList(L))
            {
                if (ListTraverse(*L, visit) == OK) // 成功遍历
                    printf("Successfully traveled all elements.\n");
            }
            getchar();
            break;
        case 13: // 对当前线性表进行排序
            if (checkList(L))
            {
                if (SortCurrent(L) == OK) // 成功排序
                    printf("Successfully sorted.\n");
            }
            getchar();
            break;
        case 14: // 获取当前线性表的最大子数组和
            if (checkList(L))
            {
                if (L->length)
                    printf("Max Sub=%d", MaxSubArray(*L)); // 最大和
                else
                    printf("List length = 0, failed to find.\n"); // 表中无元素
            }
            getchar();
            break;
        case 15: // 获取当前线性表中和为k的连续子数组个数
            if (checkList(L))
            {
                if (L->length)
                {
                    printf("Please enter the sum of the continuous subarrays you want to query:\n");
                    int k;
                    scanf("%d", &k);
                    int num = SubArrayNum(*L, k);
                    if (num > 1) // 和为k的子数组个数
                        printf("There are %d continuous subarrays with an sum of %d.\n", num, k);
                    else
                        printf("There is %d continuous subarray with an sum of %d.\n", num, k);
                }
                else
                    printf("List length = 0, failed to find.\n"); // 表中无元素
            }
            getchar();
            break;
        case 16:                   // 显示所有线性表
            if (Lists.length == 0) // 表中无元素
                printf("There are no linear tables.\n");
            else
                ShowAllList(Lists);
            getchar();
            break;
        case 17: // 切换当前线性表
            printf("Please enter the name you want to change to:\n");
            char temp_change[MAX_NAME_LENGTH]; // 要切换的表的名称
            scanf("%s", temp_change);
            if ((L = ChangeList(temp_change, &current)) != NULL) // 切换成功
                printf("Successfully changed.\n");
            else // 表不存在
                printf("There is no linear table named %s.\n", temp_change);
            getchar();
            break;
        case 18: // 删除指定线性表
            printf("Please enter the name you want to remove:\n");
            char temp_remove[MAX_NAME_LENGTH]; // 要删除的表的名称
            scanf("%s", temp_remove);
            int p;
            if (RemoveList(&Lists, temp_remove, &p) == OK) // 该表存在
            {
                printf("Successfully removed.\n");
                if (p == current) // 如果删除的是当前表
                    L = NULL;
                else if (p < current)
                    current -= 1; // 位置前移
            }
            else // 该表不存在
                printf("There is no linear table named %s.\n", temp_remove);
            getchar();
            break;
        case 19:
            SaveData(Lists);
            printf("Successfully Saved.\n");
            getchar();
            break;
        case 20:
            printf("Are you sure you want to read from the file?\n");
            printf("The data that is not currently saved will be gone.\n");
            printf("confirm:1  cancel:0\n");
            int choice;
            scanf("%d", &choice);
            if (choice)
            {
                if (LoadData(&Lists) == OK)
                // LoadData();
                {
                    L = NULL;
                    printf("Successfully Loaded.\n");
                    printf("Now you can enter 16 to query all linear tables in the file.");
                }
            }
            getchar();
            break;
        case 0:
            break;
        default:
            printf("The feature number is incorrect.\n");
        } // end of switch
    }     // end of while
    printf("Welcome to use this system next time!\n");
    return 0;
}

status InitList(SqList *L)
{
    if (L == NULL)
        return ERROR;
    if (L->elem == NULL)
    {
        L->elem = (int *)malloc(sizeof(int) * LIST_INIT_SIZE);
        L->listsize = LIST_INIT_SIZE;
        L->length = 0;
        return OK;
    }
    else
        return INFEASIBLE;
}

status DestroyList(LISTS *Lists,int current)
{
    free(Lists->elem[current].L);
    for (int i = current; i < Lists->length; i++)
    {
        Lists->elem[i] = Lists->elem[i + 1];
    }
    Lists->length--;
    return OK;
}

status ClearList(SqList *L)
{
    if (L->elem == NULL)
        return INFEASIBLE;
    else
    {
        L->length = 0;
        return OK;
    }
}

status ListEmpty(SqList L)
{
    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        if (L.length == 0)
            return TRUE;
        else
            return FALSE;
    }
}

int ListLength(SqList L)
{
    if (L.elem == NULL)
        return INFEASIBLE;
    else
        return L.length;
}

status GetElem(SqList L, int i, ElemType *e)
{
    if (L.elem == NULL)
        return INFEASIBLE;
    else if (i <= 0 || i > L.length)
        return ERROR;
    else
    {
        *e = L.elem[i - 1];
        return OK;
    }
}

int LocateElem(SqList L, ElemType e)
{
    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        int i = 0;
        for (i; i < L.length; i++)
        {
            if (L.elem[i] == e)
                return i + 1;
        }
        if (i >= L.length)
            return ERROR;
    }
}

status PriorElem(SqList L, ElemType e, ElemType *pre)
{
    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        int i = 0;
        for (i; i < L.length; i++)
        {
            if (L.elem[i] == e)
            {
                if (i == 0)
                    return ERROR;
                else
                {
                    *pre = L.elem[i - 1];
                    return OK;
                }
            }
        }
        if (i >= L.length)
            return ERROR;
    }
}

status NextElem(SqList L, ElemType e, ElemType *next)
{
    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        int i = 0;
        for (i; i < L.length; i++)
        {
            if (L.elem[i] == e)
            {
                if (i == L.length - 1)
                    return ERROR;
                else
                {
                    *next = L.elem[i + 1];
                    return OK;
                }
            }
        }
        if (i >= L.length)
            return ERROR;
    }
}

status ListInsert(SqList *L, int i, ElemType e)
{
    if (L->elem == NULL)
        return INFEASIBLE;
    if (i <= 0 || i > L->length + 1)
        return ERROR;
    else
    {
        if (L->length >= L->listsize)
        {
            ElemType *newbase;
            newbase = (ElemType *)realloc(L->elem, sizeof(ElemType) * L->listsize + LISTINCREMENT);
            if (newbase)
            {
                L->elem = newbase;
                L->listsize += LISTINCREMENT;
            }
        }
    }
    for (int j = L->length - 1; j >= i - 1; j--)
        L->elem[j + 1] = L->elem[j];
    L->elem[i - 1] = e;
    L->length++;
    return OK;
}

status ListDelete(SqList *L, int i, ElemType *e)
{
    if (L->elem == NULL)
        return INFEASIBLE;
    if (i <= 0 || i > L->length)
        return ERROR;
    *e = L->elem[i - 1];
    for (int j = i - 1; j < L->length - 1; j++)
        L->elem[j] = L->elem[j + 1];
    L->length--;
    return OK;
}

status ListTraverse(SqList L, void (*visit)(ElemType))
{
    if (L.elem == NULL)
        return INFEASIBLE;
    if (L.length)
    { // 迭代次数
        int literate_time = 0;
        for (; literate_time < L.length; literate_time++)
        { // 对每一个元素执行visit函数，此处visit函数的作用是打印元素
            visit(L.elem[literate_time]);
        }
        printf("\n");
        return OK;
    }
    else
    {
        printf("List length = 0, failed to travel.\n");
        return ERROR;
    }
}

status SortCurrent(SqList *L)
{
    if (L->length)
    {
        for (int i = L->length - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (L->elem[j] > L->elem[j + 1])
                {
                    int temp = L->elem[j];
                    L->elem[j] = L->elem[j + 1];
                    L->elem[j + 1] = temp;
                }
            }
        }
        return OK;
    }
    else
    {
        printf("List length = 0, failed to sort.\n");
        return ERROR;
    }
}

ElemType MaxSubArray(SqList L)
{
    if (L.length)
    {
        int max_sum = L.elem[0];
        int current_sum = L.elem[0];
        // 从数组的第二个元素开始遍历
        for (int i = 1; i < L.length; i++)
        {
            // 更新当前子数组的和，使其为当前元素值与当前元素值与前一个子数组的和中的较大值
            current_sum = (current_sum + L.elem[i] > L.elem[i]) ? current_sum + L.elem[i] : L.elem[i];
            // 更新最大和，使其为当前子数组的和和最大和中的较大值
            max_sum = (current_sum > max_sum) ? current_sum : max_sum;
        }
        return max_sum;
    }
}

int SubArrayNum(SqList L, ElemType k)
{
    int count = 0;
    // 遍历数组，计算以每个元素为起点的子数组的和
    for (int i = 0; i < L.length; i++)
    {
        int sum = 0;
        // 将当前元素与后续元素相加，直到子数组和大于等于 k 或者到达数组末尾
        for (int j = i; j < L.length; j++)
        {
            sum += L.elem[j];
            // 如果子数组和等于 k，增加计数
            if (sum == k)
            {
                count++;
                // break;
            }
        }
    }
    return count;
}

void ShowAllList(LISTS Lists)
{
    for (int i = 0; i < Lists.length; i++)
    {
        printf("name:%s\n", Lists.elem[i].name);
        printf("elements:");
        if (checkList(Lists.elem[i].L) == !TRUE)
            return;
        for (int j = 0; j < Lists.elem[i].L->length; j++)
            visit(Lists.elem[i].L->elem[j]);
        printf("\n");
    }
}

SqList *ChangeList(char ListName[], int *current)
{
    for (int i = 0; i < Lists.length; i++)
    {
        if (strcmp(Lists.elem[i].name, ListName) == 0)
        {
            *current = i;
            return Lists.elem[i].L;
        }
    }
    return NULL;
}

status RemoveList(LISTS *Lists, char ListName[], int *p)
{
    for (int i = 0; i < Lists->length; i++)
    {
        if (strcmp(Lists->elem[i].name, ListName) == 0)
        {
            free(Lists->elem[i].L);
            *p = i;
            for (int j = i; j < Lists->length; j++)
            {
                Lists->elem[i] = Lists->elem[i + 1];
            }
            Lists->length--;
            return OK;
        }
    }
    return ERROR;
}

status SaveData(LISTS Lists)
{
    // printf("Please enter the filename:\n");
    // scanf("%s",FileName);
    FILE *fp = fopen(FileName, "w"); // 覆盖写入
    // 尝试打开，如果文件不存在，则创建文件
    if (fp == NULL)
        fp = fopen(FileName, "wb");
    int literate_time = 0;
    for (; literate_time < Lists.length; literate_time++)
    {
        if (Lists.elem[literate_time].L) //&& Lists.elem[literate_time].L->length//&&Lists.elem[literate_time].L->elem
        {                                // 按照一定格式将数据保存到文件中
            fprintf(fp, "name:%s length:%d\n", Lists.elem[literate_time].name, Lists.elem[literate_time].L->length);
            for (int i = 0; i < Lists.elem[literate_time].L->length; i++)
                fprintf(fp, "%d\n", Lists.elem[literate_time].L->elem[i]);
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
    return OK;
}

status LoadData(LISTS *LL)
// 还有一种读取方法为仅显示，但当前Lists并不会更新为文件中内容。
// Lists只是暂存的，如果没有Save就去Load，当前暂存的Lists会被文件内容覆盖。
{ // 尝试打开文件
    // printf("Please enter the filename:\n");
    // scanf("%s",FileName);
    FILE *fp = fopen(FileName, "r");
    if (fp == NULL)
    { // 如果文件不存在
        printf("File doesn't exist\n");
        return ERROR;
    }
    int literate_time = 0;
    char current_list_name[MAX_NAME_LENGTH];
    ElemType current_elem;
    int list_length;
    LL->length = 0;
    // 不断读取直到文件尾，即EOF
    while (literate_time < MAX_LIST_NUM && fscanf(fp, "name:%s length:%d\n", current_list_name, &list_length) != EOF)
    { // 打印log
        // printf("current_list_name = %s, list_length = %d\n", current_list_name, list_length);
        printf("Reading a linear table with the name %s.\n", current_list_name);

        // free(ListTracker[current_list_num]);
        LL->elem[literate_time].L = (SqList *)malloc(sizeof(SqList));
        strcpy(LL->elem[literate_time].name, current_list_name);
        LL->elem[literate_time].L->length = list_length;
        LL->elem[literate_time].L->listsize = LIST_INIT_SIZE;
        LL->elem[literate_time].L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
        // 若已销毁的线性表被存进文件，那么读取文件时自动为其初始化
        for (int i = 0; i < list_length; i++)
        {
            fscanf(fp, "%d\n", &current_elem);
            printf("element %d is being read.\n", i + 1);
            (LL->elem[literate_time].L->elem)[i] = current_elem;
        }
        literate_time++;
        LL->length++;
        fscanf(fp, "\n");
    }
    return OK;
}