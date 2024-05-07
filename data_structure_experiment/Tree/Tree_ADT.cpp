/*头文件声明*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*定义常量*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define MAX_OTHERS 20 //其他信息的最大长度
#define FILENAME "data.txt" //文件名
#define MAX_NAME_LENGTH 20 //树的名字最大长度
#define MAX_TREE_NUM 10 //树的最大数量
/*定义数据元素类型*/
typedef int status;
typedef int KeyType;
/*二叉树结点数据类型定义*/
typedef struct { 
     KeyType  key;
     char others[MAX_OTHERS];
} TElemType; 
/*二叉链表结点的定义*/
typedef struct BiTNode{  
      TElemType  data;
      struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;
/*二叉树集合*/
typedef struct{
    struct{
        BiTree T;
        char name[MAX_NAME_LENGTH];
    }elem[MAX_TREE_NUM];
    int length; //树的数量
}TreeList;
TreeList TL; //全局变量，树的集合

/*函数声明*/
void PrintMenu1(); //打印主菜单
status CreateBiTree(BiTree &T,TElemType definition[]); //创建树
int SelectTree(TreeList TL, char name[]); //选择树
status ClearBiTree(BiTree &T); //清空树
void main2(BiTree &T,int loc); //子页面
void PrintMenu2(); //打印子菜单
status BiTreeEmpty(BiTree T); //判断树是否为空
int BiTreeDepth(BiTree T); //求树的深度
BiTree LocateNode(BiTree T,KeyType e); //定位结点
status Assign(BiTree &T,KeyType e,TElemType value); //赋值
BiTree GetSibling(BiTree T,KeyType e); //获得兄弟结点
void visit(BiTree T); //访问结点
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c); //插入结点
status DeleteNode(BiTree &T,KeyType e); //删除结点
BiTree GetParent(BiTree T,KeyType e); //获得父结点
status PreOrderTraverse(BiTree T,void (*visit)(BiTree)); //先序遍历
status InOrderTraverse(BiTree T,void (*visit)(BiTree)); //中序遍历
status PostOrderTraverse(BiTree T,void (*visit)(BiTree)); //后序遍历
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree)); //层序遍历


int main()
{
    PrintMenu1(); //打印主菜单 
    TL.length=0; //初始化树的数量
    int op=1;
    while(op)
    {
        //提示用户选择操作
        printf("\n|-------------------------------------------------------|\n"
                 "|----Please Choose Your Operation from Options above----|\n"
                 "|-------------------------------------------------------|\n\n");
        scanf("%d",&op); //输入功能选项
        system("cls"); //清屏
        PrintMenu1(); //打印主菜单
        switch(op)
        {
            case 1: //创建树
            {
                printf("|-------------------------------------------------------|\n"
                       "|----------You can create a total of %d trees.----------|\n",
                   MAX_TREE_NUM); //提示用户可以创建的树的数量
                if (TL.length > 1) //提示用户当前已经创建的树的数量
                printf("|---------Currently, %d trees have been created.---------|\n", TL.length);
                else
                printf("|----------Currently, %d tree has been created.----------|\n", TL.length);
                printf("|-------------------------------------------------------|\n\n");
                //提示用户输入树的名字
                printf("Please input the name of the tree you want to create:\n");
                scanf("%s",TL.elem[TL.length].name);
                //检查是否有相同名字的树
                if(SelectTree(TL, TL.elem[TL.length].name)!=-1)
                {
                    printf("ERROR:There is a tree with the same name!\n");
                    break;
                }
                //提示用户输入树的关键字和其他信息
                printf("Please input the key and others of the tree, end with -1(PreOrder):\n");
                TElemType definition[100];
                int i=0;
                //输入树的关键字和其他信息
                while(1)
                {
                    scanf("%d",&definition[i].key);
                    if(definition[i].key==-1) break;
                    scanf("%s",definition[i].others);
                    i++;
                }
                definition[i].key=-1; //结束标志
                if(CreateBiTree(TL.elem[TL.length].T,definition)==ERROR)
                {
                    printf("ERROR:There are same keys in the tree!\n");
                    break;
                }
                printf("The tree has been created successfully!\n");
                TL.length++; //树的数量加1
                break;
            }
            case 2: //删除树
            {
                printf("Please input the name of the tree you want to delete:\n");
                char delete_name[MAX_NAME_LENGTH];
                scanf("%s",delete_name);
                if(SelectTree(TL, delete_name)==-1)
                {
                    printf("ERROR:There is no such tree!\n");
                    break;
                }
                else
                {
                    ClearBiTree(TL.elem[SelectTree(TL, delete_name)].T); //销毁树
                    for(int i=SelectTree(TL, delete_name);i<TL.length-1;i++)
                    {
                        TL.elem[i]=TL.elem[i+1]; //前移
                    }
                    TL.length--;
                    printf("The tree has been deleted successfully!\n");
                }
                break;
            }
            case 3: //选择树
            {
                printf("Please input the name of the tree you want to select:\n");
                char select_name[MAX_NAME_LENGTH];
                scanf("%s",select_name);
                int loc=SelectTree(TL, select_name);
                if(loc==-1)
                {
                    printf("ERROR:There is no such tree!\n");
                    break;
                }
                main2(TL.elem[loc].T,loc); //调用子页面
                PrintMenu1(); //从子页面跳回时再次打印主菜单
                break;
            }
            case 6:
            {
                char search_name[MAX_NAME_LENGTH];
                printf("Please enter the name of the tree you want to query:\n");
                scanf("%s",search_name);
                if(SelectTree(TL, search_name)!=-1)
                    printf("The location of the tree is %d.\n",SelectTree(TL, search_name)+1);
                else 
                    printf("There is no tree named %s.\n", search_name);
                break;  
            }
            case 0: // 退出
                break;
            default:
                printf("The feature number is incorrect.\n"); // 功能选项错误         
        }
    }
    printf("Welcome to use this system next time!\n"); // 欢迎下次使用
    return 0;
}

void main2(BiTree &T,int loc)
{
    system("cls"); // 清屏
    PrintMenu2(); // 打印子菜单
    int op = 1;
    while(op)
    {
        //提示用户选择操作
        printf("\n|-------------------------------------------------------|\n"
                 "|----Please Choose Your Operation from Options above----|\n"
                 "|-------------------------------------------------------|\n\n");
        scanf("%d",&op); //输入功能选项
        system("cls"); //清屏
        PrintMenu2(); //打印子菜单
        switch(op)
        {
            case 1:
            {
                if(BiTreeEmpty(T))  
                {
                    printf("Please input the key and others of the tree, end with -1(PreOrder):\n");
                    TElemType definition[100];
                    int i=0;
                    //输入树的关键字和其他信息
                    while(1)
                    {
                        scanf("%d",&definition[i].key);
                        if(definition[i].key==-1) break;
                        scanf("%s",definition[i].others);
                        i++;
                    }
                    definition[i].key=-1; //结束标志
                    if(CreateBiTree(T,definition)==ERROR)
                    {
                        printf("ERROR:There are same keys in the tree!\n");
                        break;
                    }
                    printf("The tree has been initialized successfully!\n");
                }
                else 
                {
                    printf("The data already exist.\n");
                    break;
                }
                break;
            }
            case 2:
            {
                if (BiTreeEmpty(T))
                {
                    break;
                }
                else
                {
                    ClearBiTree(T);
                    printf("The tree has been cleared successfully!\n");
                }
                break;
            }
            case 3:
            {
                ClearBiTree(T); 
                for(int i=loc;i<TL.length-1;i++)
                {
                    TL.elem[i]=TL.elem[i+1]; //前移
                }
                TL.length--;
                system("cls");
                printf("\nThe tree has been destoryed successfully!\n\n");
                return;
                break;
            }
            case 4:
            {
                if(BiTreeEmpty(T)) ;
                else printf("The tree is not empty.\n");
                break;
            } 
            case 5:
            {
                if(!BiTreeEmpty(T))
                    printf("The depth of the tree is %d.\n",BiTreeDepth(T));
                break;
            }
            case 6:
            {
                if(!BiTreeEmpty(T))
                {
                    KeyType e;
                    printf("Please input the key you want to locate:\n");
                    scanf("%d",&e);
                    BiTree p=LocateNode(T,e);
                    if(p==NULL) printf("The node is not found.\n");
                    else printf("The node is: %d,%s\n",p->data.key,p->data.others);
                }
                break;
            }
            case 7:
            {
                if(!BiTreeEmpty(T))
                {
                    KeyType e;
                    TElemType value;
                    printf("Please input the key you want to assign:\n");
                    scanf("%d",&e);
                    printf("Please input the value you want to assign:\n");
                    scanf("%d %s",&value.key,value.others);
                    if(Assign(T,e,value)==ERROR) printf("ERROR:There is a same key in the tree!\n");
                    else printf("The value has been assigned successfully!\n");
                }
                break;
            }
            case 8:
            {
                if(!BiTreeEmpty(T))
                {
                    KeyType e;
                    printf("Please input the key you want to get the sibling:\n");
                    scanf("%d",&e);
                    BiTree p=GetSibling(T,e);
                    if(p==NULL) printf("The node is not found.\n");
                    else printf("The sibling is: %d,%s\n",p->data.key,p->data.others);
                }
                break;
            }
            case 9:
            {
                if(!BiTreeEmpty(T))
                {
                    KeyType e;
                    int LR;
                    TElemType c;
                    printf("Please input the key you want to insert:\n");
                    scanf("%d",&e);
                    printf("Please input the LR you want to insert(0 for left,1 for right,-1 for root):\n");
                    scanf("%d",&LR);
                    printf("Please input the value you want to insert:\n");
                    scanf("%d %s",&c.key,c.others);
                    if(InsertNode(T,e,LR,c)==ERROR) printf("ERROR:There is a same key in the tree!\n");
                    else printf("The node has been inserted successfully!\n");
                }
                break;
            }
            case 10:
            {
                if(!BiTreeEmpty(T))
                {
                    KeyType e;
                    printf("Please input the key you want to delete:\n");
                    scanf("%d",&e);
                    if(DeleteNode(T,e)==ERROR) printf("The node is not found.\n");
                    else printf("The node has been deleted successfully!\n");
                }
                break;
            }
            case 11:
            {
                if(!BiTreeEmpty(T))
                {
                    printf("The PreOrderTraverse is:\n");
                    PreOrderTraverse(T,visit);
                    printf("\n");
                }
                break;
            }
            case 12:
            {
                if(!BiTreeEmpty(T))
                {
                    printf("The InOrderTraverse is:\n");
                    InOrderTraverse(T,visit);
                    printf("\n");
                }
                break;
            }
            case 13:
            {
                if(!BiTreeEmpty(T))
                {
                    printf("The PostOrderTraverse is:\n");
                    PostOrderTraverse(T,visit);
                    printf("\n");
                }
                break;
            }
            case 14:
            {
                if(!BiTreeEmpty(T))
                {
                    printf("The LevelOrderTraverse is:\n");
                    LevelOrderTraverse(T,visit);
                    printf("\n");
                }
                break;
            }
            case 0:
                system("cls");
                return;
            default:
                printf("The feature number is incorrect.\n"); // 功能选项错误
        }
    }
}

void PrintMenu1()
{
    printf("|================Menu for multiple Trees================|\n");
    printf("|-------------------------------------------------------|\n");
    printf("|              1.    Create a Tree                      |\n");
    printf("|              2.    Delete a Tree                      |\n");
    printf("|              3. Select a single Tree                  |\n");
    printf("|              4. Save All Data To File                 |\n");
    printf("|              5. Load All Data From File               |\n");
    printf("|              6.    Search a Tree                      |\n");
    printf("|              0.         EXIT                          |\n");
    printf("|=======================================================|\n\n");
}

void PrintMenu2()
{
    printf("|================Menu for single Tree===================|\n");
    printf("|-------------------------------------------------------|\n");
    printf("|   1.  Init Current Tree     2.  Clear Current Tree    |\n");
    printf("|   3.  Destory Current Tree  4.  Empty or Not          |\n");
    printf("|   5.  Depth of the Tree     6.  Locate Node           |\n");   
    printf("|   7.  Assign Value          8.  GetSibling            |\n"); 
    printf("|   9.  Insert a Node         10. Delete a Node         |\n"); 
    printf("|   11. PreOrderTraverse      12. InOrderTraverse       |\n"); 
    printf("|   13. PostOrderTraverse     14. LevelOrderTraverse    |\n");
    printf("|=======================================================|\n\n");
}

void visit(BiTree T)
{
    printf("%d,%s ",T->data.key,T->data.others);
}

status BiTreeEmpty(BiTree T)
{
    if(T==NULL) 
    {
        printf("The tree is empty.\n");
        return TRUE;
    }
    else return FALSE;
}

status CreateBiTree(BiTree &T,TElemType definition[])
{
    static int i=0;
    if(i==0) //第一次调用时检查是否有相同的关键字
    {
        for(int j=0;definition[j].key!=-1;j++)
        {
            for(int k=j+1;definition[k].key!=-1;k++)
            {
                if(definition[j].key==definition[k].key&&definition[k].key!=0) 
                return ERROR;
            }
        }
    }

    if(definition[i].key==-1) return OK; //递归结束条件
        
    if(definition[i].key==0) //0表示空树
    {
        T=NULL;
        i++;
        return OK;
    }
    else //非空树
    {
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=definition[i];
        i++;
        CreateBiTree(T->lchild,definition);
        CreateBiTree(T->rchild,definition);
    }
    return OK;
}

int SelectTree(TreeList TL, char name[])
{
    for(int i=0;i<TL.length;i++)
    {
        if(strcmp(TL.elem[i].name,name)==0) return i; //找到树
    }
    return -1; //未找到树
}

status ClearBiTree(BiTree &T)
{
    if(T==NULL) return OK;
    ClearBiTree(T->lchild);
    ClearBiTree(T->rchild);
    free(T);
    T=NULL;
    return OK;
}

int BiTreeDepth(BiTree T)
{
    if(T==NULL) return 0;
    int ldepth=BiTreeDepth(T->lchild);
    int rdepth=BiTreeDepth(T->rchild);
    return (ldepth>rdepth?ldepth:rdepth)+1;
}

BiTree LocateNode(BiTree T,KeyType e)
{
    if(T==NULL) return NULL;
    if(T->data.key==e) return T;
    BiTree p=LocateNode(T->lchild,e);
    if(p!=NULL) return p;
    p=LocateNode(T->rchild,e);
    return p;
}

status Assign(BiTree &T,KeyType e,TElemType value)
{
    BiTree p=LocateNode(T,e);
    if(p==NULL) return ERROR;
    else if(value.key!=e&&LocateNode(T,value.key)!=NULL) 
        return ERROR; // 检查是否有相同的关键字
    p->data=value;
    return OK;
}

BiTree GetSibling(BiTree T,KeyType e)
{
    if(T==NULL) return NULL;
    if(T->lchild!=NULL&&T->lchild->data.key==e) return T->rchild;
    if(T->rchild!=NULL&&T->rchild->data.key==e) return T->lchild;
    BiTree p=GetSibling(T->lchild,e);
    if(p!=NULL) return p;
    p=GetSibling(T->rchild,e);
    return p;
}

status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入结点。此题允许通过增加其它函数辅助实现本关任务
{
    BiTree p=LocateNode(T,e);
    if(p==NULL) return ERROR;
    else if(LocateNode(T,c.key)!=NULL) 
        return ERROR; // 检查是否有相同的关键字
    if(LR==-1)
    {
        BiTree q=(BiTree)malloc(sizeof(BiTNode));
        q->data=c;
        q->lchild=NULL;
        q->rchild=T;
        T=q;
    }
    if(LR==0)
    {
        BiTree q=(BiTree)malloc(sizeof(BiTNode));
        q->data=c;
        q->lchild=NULL;
        q->rchild=p->lchild;
        p->lchild=q;
    }
    if(LR==1)
    {
        BiTree q=(BiTree)malloc(sizeof(BiTNode));
        q->data=c;
        q->lchild=NULL;
        q->rchild=p->rchild;
        p->rchild=q;
    }
    return OK;
}

status DeleteNode(BiTree &T,KeyType e)
//删除结点。
//1.如关键字为e的结点度为0，删除即可;
//2.如关键字为e的结点度为1，用关键字为e的结点孩子代替被删除的e位置;
//3.如关键字为e的结点度为2，用e的左子树(简称为LC)代替被删除的e位置，将e的右子树(简称为RC)作为LC中最右节点的右子树。
//成功删除结点后返回OK，否则返回ERROR。
{
    BiTree p = LocateNode(T, e);
    if (p == NULL)
        return ERROR;
    if (p == T)
    {
        if(p->lchild==NULL&&p->rchild==NULL)
        {
            free(p);
            T=NULL;
            return OK;
        }
        if(p->lchild!=NULL&&p->rchild==NULL)
        {
            T=T->lchild;
            free(p);
            return OK;
        }   
        if(p->lchild==NULL&&p->rchild!=NULL)
        {
            T=T->rchild;
            free(p);
            return OK;
        }
        if(p->lchild!=NULL&&p->rchild!=NULL)
        {
            BiTree q=p->lchild;
            while(q->rchild!=NULL) q=q->rchild;
            q->rchild=p->rchild;
            T=T->lchild;
            free(p);
            return OK;
        }
    }
    else
    {
        if (p->lchild == NULL && p->rchild == NULL)
        {
            BiTree q=GetParent(T,e);
            if(q->lchild!=NULL&&q->lchild->data.key==e) q->lchild=NULL;
            else q->rchild=NULL;    
            free(p);
            return OK;
        }
        if (p->lchild != NULL && p->rchild == NULL)
        {
            BiTree q=GetParent(T,e);
            if(q->lchild!=NULL&&q->lchild->data.key==e) q->lchild=p->lchild;
            else q->rchild=p->lchild;   
            free(p);
            return OK;
        }
        if (p->lchild == NULL && p->rchild != NULL)
        {
            BiTree q=GetParent(T,e);
            if(q->lchild!=NULL&&q->lchild->data.key==e) q->lchild=p->rchild;
            else q->rchild=p->rchild;
            free(p);
            return OK;
        }
        if (p->lchild != NULL && p->rchild != NULL)
        {
            BiTree q=GetParent(T,e);
            BiTree r=p->lchild;
            while(r->rchild!=NULL) r=r->rchild;
            r->rchild=p->rchild;
            if(q->lchild!=NULL&&q->lchild->data.key==e) q->lchild=p->lchild;
            else q->rchild=p->lchild;
            free(p);
            return OK;
        }
    }
    return OK;
}

BiTree GetParent(BiTree T,KeyType e) 
{
    if(T==NULL) return NULL;
    if(T->lchild!=NULL&&T->lchild->data.key==e) return T;
    if(T->rchild!=NULL&&T->rchild->data.key==e) return T;
    BiTree p=GetParent(T->lchild,e);
    if(p!=NULL) return p;
    p=GetParent(T->rchild,e);
    return p;
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//先序遍历二叉树T
{
    if(T)
    {
        visit(T);
        PreOrderTraverse(T->lchild,visit);
        PreOrderTraverse(T->rchild,visit);
    }
    return OK;
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍历二叉树T
{
    BiTree stack[100];
    int top=0;
    stack[top++]=T;
    while(top)
    {
        T=stack[top-1];
        while(T)
        {
            T=T->lchild;
            stack[top++]=T;
        }
        top--;
        if(top)
        {
            T=stack[--top];
            visit(T);   
            stack[top++]=T->rchild;
        }
    }
    return OK;
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//后序遍历二叉树T
{
    if(T)
    {
        PostOrderTraverse(T->lchild,visit);
        PostOrderTraverse(T->rchild,visit);
        visit(T);
    }
    return OK;
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    BiTree queue[100];
    int front=0,rear=0;
    queue[rear++]=T;
    while(front!=rear)
    {
        T=queue[front++];
        visit(T);
        if(T->lchild!=NULL) queue[rear++]=T->lchild;
        if(T->rchild!=NULL) queue[rear++]=T->rchild;
    }
    return OK;
}


