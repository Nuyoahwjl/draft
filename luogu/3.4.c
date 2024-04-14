// //先进先出链表 
// #include <stdio.h>
// #include <stdlib.h>
// struct s_list{
//    int data;
//    struct s_list *next;
// };
// struct s_list *create_list(int *p);
// int main(void){
//    struct s_list *head=NULL,*p;
//    int s[]={1,2,3,4,5,6,7,8,0};
//    p=create_list(s);
// //    p=head;
//    while (p){
//        printf("%d\t",p->data);
//        p=p->next;
//    }
//    printf("\n");
//    return 0;  
// }
// struct s_list *create_list(int *p){
//    struct s_list *loc_head=NULL,*tail;
//    if(p[0]==0);
//    else {
//        loc_head=(struct s_list *)malloc(sizeof(struct s_list));
//        loc_head->data=*p++;
//        tail=loc_head;
//        while (*p)
//        {
//            tail->next=(struct s_list *)malloc(sizeof(struct s_list));
//            tail=tail->next;
//            tail->data=*p++;
//        }
//        tail->next=NULL;
       
//    }
//    return loc_head;
// }

// #include <stdio.h>
// #include <stdlib.h>
// struct s_list{
//    int data;
//    struct s_list *next;
// };
// void create_list(struct s_list **headp,int *p);
// int main(void){
//    struct s_list *head=NULL,*p;
//    int s[]={1,2,3,4,5,6,7,8,0};
//    create_list(&head,s);
//    p=head;
//    while (p){
//        printf("%d\t",p->data);
//        p=p->next;
//    }
//    printf("\n");
//    return 0;  
// }
// void create_list(struct s_list **headp,int *p){
//    struct s_list *loc_head=NULL,*tail;
//    if(p[0]==0);
//    else {
//        loc_head=(struct s_list *)malloc(sizeof(struct s_list));
//        loc_head->data=*p++;
//        tail=loc_head;
//        while (*p)
//        {
//            tail->next=(struct s_list *)malloc(sizeof(struct s_list));
//            tail=tail->next;
//            tail->data=*p++;
//        }
//        tail->next=NULL;
       
//    }
//    *headp=loc_head;
// }





// //先进后出链表 
// #include <stdio.h>
// #include <stdlib.h>
// struct s_list{
//    int data;
//    struct s_list *next;
// };
// struct s_list *create_list(int *p);
// int main(void){
//    struct s_list *head=NULL,*p;
//    int s[]={1,2,3,4,5,6,7,8,0};
//    p=create_list(s);
// //    p=head;
//    while (p){
//        printf("%d\t",p->data);
//        p=p->next;
//    }
//    printf("\n");
//    return 0;  
// }
// struct s_list *create_list(int *p){
//    struct s_list *head=NULL,*q;
//    while(*p){
//    	q=(struct s_list *)malloc(sizeof(struct s_list));
//    	q->data=*p;
//    	q->next=head;
//    	head=q;
//    	p++;
//    }
//    return head;
// }





// //回文字符串 
// #include <stdlib.h>
// #include <stdio.h>
// typedef struct c_node{
//    char data;  
// 	struct c_node *next;
// } C_NODE;
// void createLinkList(C_NODE **headp,C_NODE **headp1,char s[]);
// void judgePalindrome(C_NODE *head,C_NODE *head1);
// int main(){
// 	char s[100];
// 	scanf("%s",s);
// 	C_NODE *head=NULL,*head1=NULL;
// 	createLinkList(&head,&head1,s);
// 	judgePalindrome(head,head1);
// 	return 0;
// }
// void createLinkList(C_NODE **headp,C_NODE **headp1,char s[]) 
// {
//    char *p=s;
// 	C_NODE *loc_head=NULL,*tail;
//    loc_head=(C_NODE *)malloc(sizeof(C_NODE));
//    loc_head->data=*p++;
//    tail=loc_head;
//        while (*p!='\0')
//        {
//            tail->next=(C_NODE *)malloc(sizeof(C_NODE));
//            tail=tail->next;
//            tail->data=*p++;
//        }
//        tail->next=NULL;
//    *headp=loc_head;

//    C_NODE *loc_head1=NULL,*q;
//    p=s;
//    while(*p!='\0'){
//    	q=(C_NODE *)malloc(sizeof(C_NODE));
//    	q->data=*p++;
//    	q->next=loc_head1;
//    	loc_head1=q;
//    }
//    *headp1=loc_head1;
// }
// void judgePalindrome(C_NODE *head,C_NODE *head1)
// {
//    C_NODE *m,*n;
//    int flag=1;
//    for(m=head,n=head1;m!=NULL&&n!=NULL;m=m->next,n=n->next){
//        if(m->data!=n->data){
//            flag=0;
//            break;
//        }
//    }
//    if(flag==1) printf("true");
//    else printf("false");
// }





// //班级成绩单
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// struct stu{
// 	char number[20];
// 	char name[20];
// 	int english;
// 	int math;
// 	int physics;
// 	int c_code;
// 	int sum;
// 	double ave;
// 	struct stu *next;
// };
// struct stu *head,*tail;
// int n;
// void input(int i);
// void output1(void);
// void modify(void);
// void average(void);
// void output2(void);
// int main()
// {
//    int menu;
//    int i=0;
//    printf("班级成绩单\n");
//    printf("功能选项:0.退出\n");
//    printf("         1.输入每个学生各项信息\n"); 
//    printf("         2.输出每个学生各项信息\n");
//    printf("         3.修改指定学生的指定成绩\n");
//    printf("         4.统计每个学生的平均成绩\n");
//    printf("         5.输出各位学生的学号，姓名，总成绩和平均成绩\n");
//    do{
//        scanf("%d",&menu);
//        if(menu==1) 
// 		{
//        	i++;
// 			input(i);
// 		}
//        if(menu==2)
// 		{
//        	output1();
// 		}
//        if(menu==3)
// 		{
//        	modify();
// 		} 
// 	    if(menu==4)
// 		{
// 	    	average();
// 		} 
//        if(menu==5)
// 		{
// 			output2();
// 		}
//    }while(menu!=0);
//    return 0;
// }

// void input(int i)
// {
// 	printf("请输入学生人数：") ;
// 	scanf("%d",&n);
// 	printf("请输入每个学生的学号,姓名以及英语,高数,物理,C语言4门课的成绩并以空格隔开，不同学生用回车分隔\n");
// 	if(i==1)
// 	{
// 		head=(struct stu *)malloc(sizeof(struct stu));
// 		scanf("%s%s%d%d%d%d",head->number,head->name,&head->english,&head->math,&head->physics,&head->c_code);
// 		head->sum=head->english+head->math+head->physics+head->c_code;
// 		head->ave=1.0*head->sum/4;
// 		tail=head;
// 		for(int j=1;j<n;j++)
// 		{
// 			tail->next=(struct stu *)malloc(sizeof(struct stu));
// 			tail=tail->next;
// 			scanf("%s%s%d%d%d%d",tail->number,tail->name,&tail->english,&tail->math,&tail->physics,&tail->c_code);
// 			tail->sum=tail->english+tail->math+tail->physics+tail->c_code;
// 		    tail->ave=1.0*tail->sum/4;
// 		}
// 		tail->next=NULL;
// 	}
// 	else
// 	{
// 		for(int j=0;j<n;j++)
// 		{
// 			tail->next=(struct stu *)malloc(sizeof(struct stu));
// 			tail=tail->next;
// 			scanf("%s%s%d%d%d%d",tail->number,tail->name,&tail->english,&tail->math,&tail->physics,&tail->c_code);
// 			tail->sum=tail->english+tail->math+tail->physics+tail->c_code;
// 		    tail->ave=1.0*tail->sum/4;
// 		}
// 		tail->next=NULL;
// 	}
// }

// void output1(void)
// {
// 	printf("学号      \t姓名\t英语\t高数\t物理\tC语言\n"); 
// 	struct stu *p=head;
// 	while(p!=NULL){
// 		printf("%s\t%s\t%d\t%d\t%d\t%d\n",p->number,p->name,p->english,p->math,p->physics,p->c_code);
// 		p=p->next;
// 	}
// }

// void modify(void)
// {
// 	printf("请输入需要修改成绩的学生的学号，科目及相应成绩\n");
// 	printf("科目用代号表示 1-英语 2-高数 3-物理 4-C语言\n");
// 	char s[20];
// 	scanf("%s",s);
// 	int num,grade;
// 	scanf("%d%d",&num,&grade);
// 	struct stu *p=head;
// 	while(p!=NULL){
// 		if(strcmp(s,p->number)==0) break;
// 		p=p->next;
// 	}
// 	switch(num){
// 		case 1: p->english=grade; break;
// 		case 2: p->math=grade; break;
// 		case 3: p->physics=grade; break;
// 		case 4: p->c_code=grade; break;
// 	}
// 	p->sum=p->english+p->math+p->physics+p->c_code;
// 	p->ave=1.0*p->sum/4;
// }

// void average(void)
// {
// 	struct stu *p=head;
// //	while(p!=NULL){
// //		p->sum=p->english+p->math+p->physics+p->c_code;
// //		p->ave=1.0*p->sum/4;
// //		p=p->next;
// //	}
// 	printf("学号      \t姓名\t平均成绩\n");
// 	while(p!=NULL){
// 		printf("%s\t%s\t%.2lf\n",p->number,p->name,p->ave);
// 		p=p->next;
// 	}
// }

// void output2(void)
// {
// 	printf("学号      \t姓名\t总成绩\t平均成绩\n");
// 	struct stu *p=head;
// 	while(p!=NULL){
// 		printf("%s\t%s\t%d\t%.2lf\n",p->number,p->name,p->sum,p->ave);
// 		p=p->next;
// 	}
// }





// //成绩排序
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// /*每位学生的信息*/
// struct information {
// 	char number[20];
// 	char name[20];
// 	int english;
// 	int math;
// 	int physics;
// 	int c_code;
// 	int sum;
// 	double ave;
// };
// struct stu {
// 	struct information data;
// 	struct stu* next;
// };
// struct stu* head, * tail;
// int n, total = 0;
// void input(int i);
// void output1(void);
// void modify(void);
// void average(void);
// void output2(void);
// void sort(void);
// int main()
// {
// 	int menu;
// 	int i = 0;
// 	do {
// 		scanf("%d", &menu);
// 		switch (menu) {
// 		case 1: i++; input(i); break;
// 		case 2: output1(); break;
// 		case 3: modify(); break;
// 		case 4: average(); break;
// 		case 5: output2(); break;
// 		}
// 	} while (menu != 0);
// 	return 0;
// }

// /*建立先进先出链表*/
// void input(int i)
// {
// 	scanf("%d", &n);
// 	total += n;
// 	/*若为首次输入，则用尾插法创建链表*/
// 	if (i == 1)
// 	{
// 		/*创建头节点*/
// 		head = (struct stu*)malloc(sizeof(struct stu));
		
// 		scanf("%s %s %d %d %d %d", head->data.number, head->data.name, &head->data.english, &head->data.math, &head->data.physics, &head->data.c_code);
		
// 		head->data.sum = head->data.english + head->data.math + head->data.physics + head->data.c_code;
		
// 		head->data.ave = 1.0 * head->data.sum / 4;
		
// 		tail = head;


// 		for (int j = 1; j < n; j++)
// 		{
// 			tail->next = (struct stu*)malloc(sizeof(struct stu));
			
// 			tail = tail->next;
			
// 			scanf("%s %s %d %d %d %d", tail->data.number, tail->data.name, &tail->data.english, &tail->data.math, &tail->data.physics, &tail->data.c_code);
			
// 			tail->data.sum = tail->data.english + tail->data.math + tail->data.physics + tail->data.c_code;
			
// 			tail->data.ave = 1.0 * tail->data.sum / 4;
// 		}
// 		tail->next = NULL;
// 	}
// /*若非首次输入，则在上轮链表的尾指针tail后继续插入*/
// 	else
// 	{
// 		for (int j = 0; j < n; j++)
// 		{
// 			tail->next = (struct stu*)malloc(sizeof(struct stu));
			
// 			tail = tail->next;
			
// 			scanf("%s %s %d %d %d %d", tail->data.number, tail->data.name,&tail->data.english, &tail->data.math, &tail->data.physics, &tail->data.c_code);
			
// 			tail->data.sum = tail->data.english + tail->data.math + tail->data.physics + tail->data.c_code;
			
// 			tail->data.ave = 1.0 * tail->data.sum / 4;
// 		}
// 		tail->next = NULL;
// 	}
// /*调用排序函数，按平均成绩升序排序*/
// 	sort();
// }

// void output1(void)
// {
// 	struct stu* p = head;
// 	while (p != NULL) {
// 		printf("%s %s %d %d %d %d\n", p->data.number, p->data.name, p->data.english, p->data.math, p->data.physics, p->data.c_code);
// 		p = p->next;
// 	}
// }

// void modify(void)
// {
// 	char s[20];
// 	scanf("%s", s);
// 	int num, grade;
// 	scanf("%d%d", &num, &grade);
// 	struct stu* p = head;
// 	while (p != NULL) {
// 		if (strcmp(s, p->data.number) == 0) break;
// 		p = p->next;
// 	}
// 	switch (num) {
// 	case 1: p->data.english = grade; break;
// 	case 2: p->data.math = grade; break;
// 	case 3: p->data.physics = grade; break;
// 	case 4: p->data.c_code = grade; break;
// 	}
// /*修改成绩后应重新计算总成绩和平均成绩并排序*/
// 	p->data.sum = p->data.english + p->data.math + p->data.physics + p->data.c_code;
// 	p->data.ave = 1.0 * p->data.sum / 4;
// 	sort();
// }

// void average(void)
// {
// 	struct stu* p = head;
// 	while (p != NULL) {
// 		printf("%s %s %.2lf\n", p->data.number, p->data.name, p->data.ave);
// 		p = p->next;
// 	}
// }

// void output2(void)
// {
// 	struct stu* p = head;
// 	while (p != NULL) {
// 		printf("%s %s %d %.2lf\n", p->data.number, p->data.name, p->data.sum, p->data.ave);
// 		p = p->next;
// 	}
// }

// /*交换数据域的冒泡排序：按平均成绩升序排序*/
// //void sort(void)
// //{
// //	/*total表示总人数*/
// //	struct stu* p = head;
// //	struct information temp;
// //	for (int i = 1; i < total; i++) {
// //		p = head;                //共进行total-1轮，每一轮p应从head开始 
// //		for (int j = 0; j < total - i; j++) {
// //			if (p->data.ave > p->next->data.ave) {
// //				temp = p->data;
// //				p->data = p->next->data;
// //				p->next->data = temp;
// //			}
// //			p = p->next;
// //		}
// //	}
// //}

// /*交换指针域的冒泡排序*/ 
// void sort(void)
// {
// 	struct stu *p,*last,*q;
// 	for (int i = 1; i < total; i++) {
// 		/*头节点特殊，应单独判断*/ 
// 		if(head->data.ave > head->next->data.ave ){
// 			q=head->next;
// 			head->next=head->next->next;
// 			q->next=head;
// 			head=q;
// 		}
// 		p = head;                
// 		for (int j = 1; j < total - i; j++) {
// 			last=p;
// 			p=p->next;
// 			if(p->data.ave > p->next->data.ave){
// 				last->next=p->next;
// 				p->next=p->next->next;
// 				last->next->next=p;
// 			}
// 			p=last->next;//p回退一格 
// 		}
// 	}
// }





// //利用值栈（线性数组）求解逆波兰表达式 
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// int stack[100];
// int *top=stack;
// /*入栈*/ 
// void push(int x)
// {
// 	*top++=x;
// }
// /*出栈*/
// int out(void)
// {
// 	return *--top;
// } 
// int main()
// {
// 	int x,num,temp;
// 	char c;
// 	while((c=getchar())!='\n')
// 	{
// 		if(isdigit(c))
// 		{
// 			num=0;
// 			do{
// 				num=num*10+c-'0';
// 				c=getchar();
// 			}while(c!=' ');
// 			push(num);
// 		}
// 		else if(c=='-'){
// 			c=getchar();
// 			if(isdigit(c)){
// 				num=0;
// 				do{
// 					num=num*10+c-'0';
// 					c=getchar();
// 				}while(c!=' ');
// 				push(0-num);
// 			}
// 			else{
// 				temp=out();
// 			    push(out()-temp);
// 			}
// 		}
// 		else if(isgraph(c))
// 		{
// 			switch(c){
// 				case '+': push(out()+out()); break;
// //				case '-': temp=out();
// //						  push(out()-temp);
// //						  break;
// 				case '*': push(out()*out()); break;
// 				case '/': temp=out();
// 						  push(out()/temp);
// 						  break;
// 			}
// 		}
// 	}
// 	printf("%d",out());
// 	return 0;
// }





// //利用值栈(先进后出链表)求解逆波兰表达式 
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// struct stack{
// 	int data;
// 	struct stack *next;
// };
// struct stack *head=NULL;
// /*入栈*/ 
// void push(int x)
// {
// 	struct stack *p=(struct stack *)malloc(sizeof(struct stack));
// 	p->data=x;
// 	p->next=head;
// 	head=p;//新节点成为首节点 
// }
// /*出栈*/
// int out(void)
// {
// 	int x=head->data;
// 	struct stack *p=head;
// 	head=head->next;//回退一格
// 	free(p);  
// 	return x;
// } 
// int main()
// {
// 	int x,num,temp;
// 	char c;
// 	while((c=getchar())!='\n')
// 	{
// 		if(isdigit(c))
// 		{
// 			num=0;
// 			do{
// 				num=num*10+c-'0';
// 				c=getchar();
// 			}while(c!=' ');
// 			push(num);
// 		}
// 		else if(c=='-'){
// 			c=getchar();
// 			if(isdigit(c)){
// 				num=0;
// 				do{
// 					num=num*10+c-'0';
// 					c=getchar();
// 				}while(c!=' ');
// 				push(0-num);
// 			}
// 			else{
// 				temp=out();
// 			    push(out()-temp);
// 			}
// 		}
// 		else if(isgraph(c))
// 		{
// 			switch(c){
// 				case '+': push(out()+out()); break;
// //				case '-': temp=out();
// //						  push(out()-temp);
// //						  break;
// 				case '*': push(out()*out()); break;
// 				case '/': temp=out();
// 						  push(out()/temp);
// 						  break;
// 			}
// 		}
// 	}
// 	printf("%d",out());
// 	return 0;
// }




