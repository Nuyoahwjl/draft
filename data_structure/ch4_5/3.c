#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *ch;
    int length;
}HString;

void initdata(HString *S,char *s);
void replace(HString *S,HString T,HString V);
int strindex(HString *S,HString T,int pos);
void strdelete(HString *S,int i,int len);
void strinsert(HString *S,HString V,int i);

int main()
{
    char s[100],t[100],v[100];
    gets(s);
    gets(t);
    gets(v);
    HString S,T,V;
    initdata(&S,s);
    initdata(&T,t);
    initdata(&V,v);

    replace(&S,T,V);
    printf("%d\n",S.length);
    for(int i=0;i<S.length;i++)
    printf("%c",S.ch[i]);
    return 0;
}

void initdata(HString *S,char *s)
{
    S->length=strlen(s);
    S->ch=(char *)malloc(S->length*sizeof(char));
    for(int i=0;i<S->length;i++)
        S->ch[i]=s[i];
}

void replace(HString *S,HString T,HString V)
{
    int i=0;
    while((i=strindex(S,T,i))!=-1)
    {
        strdelete(S,i,T.length);
        strinsert(S,V,i);
        i+=V.length;
    }
}

int strindex(HString *S,HString T,int pos)
{
    if(pos>=0)
    {
        int i=pos;
        while(i<=S->length-T.length)
        {
            int flag=1;
            for(int j=i,k=0;k<T.length;j++,k++)
            {
                if(S->ch[j]!=T.ch[k])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                return i;
            }
            else ++i;
        }
        return -1;
    }
}

void strdelete(HString *S,int i,int len)
{
    int temp=S->length-len-i;
    for(int j=0;j<temp;j++)
    {
        S->ch[i+j]=S->ch[i+j+len];
    }
    S->length-=len;
}

void strinsert(HString *S,HString V,int i)
{
    char *new;
    new=(char *)realloc(S->ch,(S->length+V.length)*sizeof(char));
    if(new) S->ch=new;
    int temp=S->length-i;
    S->length+=V.length;
    for(int j=temp;j>=0;j--)
    {
        S->ch[i+j+V.length-1]=S->ch[i+j-1];
    }
    for(int j=0;j<V.length;j++)
    {
        S->ch[i+j]=V.ch[j];
    }
}







// char *temp;
// while(temp=strstr(temp,T.ch))
// {
//     if(T.length>=V.length)
//     {
//         for(int i=0;i<V.length;i++)
//         {
//             *temp=V.ch[i];
//             temp++;
//         }
//     int d=T.length-V.length;
//     char *c=temp;
//     for(int i=0;i<d;i++)
//     {
//         *c=*(c+d);
//     }
//     S->length-=d;
//     }
//     else
//     {
//         int d=V.length-T.length;
//         char *c=temp+V.length;
//     }
// }