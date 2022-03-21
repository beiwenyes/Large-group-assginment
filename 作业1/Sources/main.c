#include <stdio.h>
#include <stdlib.h>
#include "test.h"
struct Node *InitList(struct Node *L)//创建空链表
{
    L = (struct Node *)malloc(sizeof(struct Node));//为指针分配空间
    L ->next = NULL;//将指针指向NULL来创建空链表
    printf("链表初始化成功\n");

    return L;
};
struct Node *creatList(struct Node *L,int e)//添加节点
{
    int i;
    struct Node *p;
    struct Node *q = L;


    for(i = 1;i<e;i++)
    {
        p =(struct Node *)malloc(sizeof(struct Node));
        p->data=i;
        p->next=NULL;//尾结点置空
        q->next=p;
        q = p;//指针后移
    };
    return L;
};
struct Node *InsertList(struct Node *L,int i,int e)//插入节点在第i个位置，插入的值为e
{
    struct Node *p;
    struct Node *s;
    int k = 0;
    if(i<0)
        printf("插入的位置不合理\n");//输入的数小于0时报错
    p=L;//重头开始
    while(p!=NULL&&k<i-1)//查找第i-1个节点
    {
        p=p->next;
        k++;
    };
    if(p==NULL)//若是遍历了整个表都没找到，则报错
        printf("插入的位置不合理");

    else
    {
        s =(struct Node*)malloc(sizeof(struct Node));//创建要插入的指针
        s->data=e;//将e的值赋予插入的值
        s->next=p->next;//将s插入到p之后
        p->next=s;//p连接上s
        printf("插入成功\n");
     };
     return L;
};

struct Node *SearchList(struct Node*L,int e)//查找值为e的节点
{
    struct Node *p;
    p=L->next;//p从第一个节点开始
    while(p!=NULL){//如果不是NUll则判断p指向的值是否为所要的e的值，不是则走一格，直到找到则返回p
        if(p->data!=e)
            p =p->next;
        else break;

    };
    if(p == NULL)
        printf("未找到所要的值，请重新输入");//找不到时报错
    return p;
};


struct Node *DeleteList(struct Node*L,int i)//删除第i个节点后的第一个节点
{

    struct Node *p;
    struct Node *r;


    int k=0,e;
    p=L;
    while(p->next!=NULL&&k<i)//当p指向的不是NULL并且k小于i时将p指向要删除的节点前
    {
        p=p->next;
        k++;
    };
    r=p->next;
    e = r->data;//将r指向的值赋予e
    p->next=r->next;//修改指针删除节点
    return L;


};
void TraverseList(struct Node *L)//遍历链表
{
  struct Node *p;
  p=L;//从头开始
  printf("这是链表的所有数据：");
  while(p->next!=NULL)//如果p不是指向NULL则输出p指向的数据并且走向下一个节点
  {
    printf("%d",p->data);
    p=p->next;
  };
};
void ReverseEvenList(struct Node *L)//倒置链表
{
  struct Node *p;
  struct Node *t;
  struct Node *q;
  p = NULL;
  t = L->next;
  q = t->next;//定义三个指针，一个指向NULL，一个指向头结点指向的下一个位置，一个指向头结点指向的下下个位置
  if(t == NULL||q==NULL)//如果是空链表或只有一个节点则倒置不了
    printf("该表倒置不了，请检查表的节点数");
  while(q)
  {
    t->next = p;//t指向NULL然后p到t的位置，t到q的位置，然后q走一格，循环直到q走到NULL
    p = t;
    t = q;
    q = q->next;

  };
   t->next = p;//处理末尾
   L->next =t;//重新将头结点指向倒置后的首个节点
};
struct Node *FindMidNode(struct Node *L)//寻找指针中点
{
    int e;
    struct Node *fast=L;//创建快慢指针
    struct Node *slow=L;
    while(fast->next!=NULL&&fast->next->next!=NULL)//当他们未走到NULL时一直走
    {
        fast = fast->next->next;
        slow = slow->next;
    };
    e = slow->data;//当快的指针走完时慢的刚好在链表中点
    printf("链表的中点是：%d",e);
    return slow;
};
struct Node *IsLoopList(struct Node *L)//判断链表是否成环
{
    struct Node *fast = L;//创建2个指针，一个快一个慢
    struct Node *slow = L;
    while(fast->next!=NULL&&fast->next->next!=NULL)//当fast的下一个以及下下个不是NULL时让fast走两格slow走一格
    {
        fast = fast->next->next;
        slow = slow->next;
        if((fast = fast->next->next) ==NULL)//若是fast走完到了NULL则是无环
            printf("链表无环");
        if(slow == fast)//如果fast和slow相遇是有环
            printf("链表有环");


    };
    return fast;
};

int main()
{
    struct Node *L;
    int z,i,e;
    z = 1;
    while(z != 0)
    {
        printf("---------\n");
        printf("1.创建空列表\n");
        printf("2.添加节点\n");
        printf("3.插入节点\n");
        printf("4.查找节点\n");
        printf("5.删除节点\n");
        printf("6.遍历链表\n");
        printf("请输入您想实现的功能序号\n");
        scanf("%d",&z);
        switch(z)
        {
        case 1:
          InitList(L);
          break;
        case 2:
            printf("请输入要加入几个节点：\n");
            scanf("%d",&e);
            creatList(L,e);
        case 3:

          printf("请输入要插入的位置以及插入的数据\n");
          scanf("%d %d",&i,&e);
          InsertList(L,i,e);
          break;
        case 4:
            printf("请输入要查找的值：\n");
            scanf("%d",&e);
            SearchList(L,e);
            break;
        case 5:
            printf("请输入要删除的节点的前一个节点序号：\n");
            scanf("%d",&e);
            DeleteList(L,e);
            break;
        case 6:
            TraverseList(L);
            break;
        default:
          printf("输入错误，请重新输入");
          break;
        }

    }





    system("pause");
    return 0;
};
