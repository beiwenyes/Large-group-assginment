#include <stdio.h>
#include <stdlib.h>
#include "test.h"
struct Node *InitList(struct Node *L)//����������
{
    L = (struct Node *)malloc(sizeof(struct Node));//Ϊָ�����ռ�
    L ->next = NULL;//��ָ��ָ��NULL������������
    printf("�����ʼ���ɹ�\n");

    return L;
};
struct Node *creatList(struct Node *L,int e)//��ӽڵ�
{
    int i;
    struct Node *p;
    struct Node *q = L;


    for(i = 1;i<e;i++)
    {
        p =(struct Node *)malloc(sizeof(struct Node));
        p->data=i;
        p->next=NULL;//β����ÿ�
        q->next=p;
        q = p;//ָ�����
    };
    return L;
};
struct Node *InsertList(struct Node *L,int i,int e)//����ڵ��ڵ�i��λ�ã������ֵΪe
{
    struct Node *p;
    struct Node *s;
    int k = 0;
    if(i<0)
        printf("�����λ�ò�����\n");//�������С��0ʱ����
    p=L;//��ͷ��ʼ
    while(p!=NULL&&k<i-1)//���ҵ�i-1���ڵ�
    {
        p=p->next;
        k++;
    };
    if(p==NULL)//���Ǳ�����������û�ҵ����򱨴�
        printf("�����λ�ò�����");

    else
    {
        s =(struct Node*)malloc(sizeof(struct Node));//����Ҫ�����ָ��
        s->data=e;//��e��ֵ��������ֵ
        s->next=p->next;//��s���뵽p֮��
        p->next=s;//p������s
        printf("����ɹ�\n");
     };
     return L;
};

struct Node *SearchList(struct Node*L,int e)//����ֵΪe�Ľڵ�
{
    struct Node *p;
    p=L->next;//p�ӵ�һ���ڵ㿪ʼ
    while(p!=NULL){//�������NUll���ж�pָ���ֵ�Ƿ�Ϊ��Ҫ��e��ֵ����������һ��ֱ���ҵ��򷵻�p
        if(p->data!=e)
            p =p->next;
        else break;

    };
    if(p == NULL)
        printf("δ�ҵ���Ҫ��ֵ������������");//�Ҳ���ʱ����
    return p;
};


struct Node *DeleteList(struct Node*L,int i)//ɾ����i���ڵ��ĵ�һ���ڵ�
{

    struct Node *p;
    struct Node *r;


    int k=0,e;
    p=L;
    while(p->next!=NULL&&k<i)//��pָ��Ĳ���NULL����kС��iʱ��pָ��Ҫɾ���Ľڵ�ǰ
    {
        p=p->next;
        k++;
    };
    r=p->next;
    e = r->data;//��rָ���ֵ����e
    p->next=r->next;//�޸�ָ��ɾ���ڵ�
    return L;


};
void TraverseList(struct Node *L)//��������
{
  struct Node *p;
  p=L;//��ͷ��ʼ
  printf("����������������ݣ�");
  while(p->next!=NULL)//���p����ָ��NULL�����pָ������ݲ���������һ���ڵ�
  {
    printf("%d",p->data);
    p=p->next;
  };
};
void ReverseEvenList(struct Node *L)//��������
{
  struct Node *p;
  struct Node *t;
  struct Node *q;
  p = NULL;
  t = L->next;
  q = t->next;//��������ָ�룬һ��ָ��NULL��һ��ָ��ͷ���ָ�����һ��λ�ã�һ��ָ��ͷ���ָ������¸�λ��
  if(t == NULL||q==NULL)//����ǿ������ֻ��һ���ڵ����ò���
    printf("�ñ��ò��ˣ������Ľڵ���");
  while(q)
  {
    t->next = p;//tָ��NULLȻ��p��t��λ�ã�t��q��λ�ã�Ȼ��q��һ��ѭ��ֱ��q�ߵ�NULL
    p = t;
    t = q;
    q = q->next;

  };
   t->next = p;//����ĩβ
   L->next =t;//���½�ͷ���ָ���ú���׸��ڵ�
};
struct Node *FindMidNode(struct Node *L)//Ѱ��ָ���е�
{
    int e;
    struct Node *fast=L;//��������ָ��
    struct Node *slow=L;
    while(fast->next!=NULL&&fast->next->next!=NULL)//������δ�ߵ�NULLʱһֱ��
    {
        fast = fast->next->next;
        slow = slow->next;
    };
    e = slow->data;//�����ָ������ʱ���ĸպ��������е�
    printf("������е��ǣ�%d",e);
    return slow;
};
struct Node *IsLoopList(struct Node *L)//�ж������Ƿ�ɻ�
{
    struct Node *fast = L;//����2��ָ�룬һ����һ����
    struct Node *slow = L;
    while(fast->next!=NULL&&fast->next->next!=NULL)//��fast����һ���Լ����¸�����NULLʱ��fast������slow��һ��
    {
        fast = fast->next->next;
        slow = slow->next;
        if((fast = fast->next->next) ==NULL)//����fast���굽��NULL�����޻�
            printf("�����޻�");
        if(slow == fast)//���fast��slow�������л�
            printf("�����л�");


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
        printf("1.�������б�\n");
        printf("2.��ӽڵ�\n");
        printf("3.����ڵ�\n");
        printf("4.���ҽڵ�\n");
        printf("5.ɾ���ڵ�\n");
        printf("6.��������\n");
        printf("����������ʵ�ֵĹ������\n");
        scanf("%d",&z);
        switch(z)
        {
        case 1:
          InitList(L);
          break;
        case 2:
            printf("������Ҫ���뼸���ڵ㣺\n");
            scanf("%d",&e);
            creatList(L,e);
        case 3:

          printf("������Ҫ�����λ���Լ����������\n");
          scanf("%d %d",&i,&e);
          InsertList(L,i,e);
          break;
        case 4:
            printf("������Ҫ���ҵ�ֵ��\n");
            scanf("%d",&e);
            SearchList(L,e);
            break;
        case 5:
            printf("������Ҫɾ���Ľڵ��ǰһ���ڵ���ţ�\n");
            scanf("%d",&e);
            DeleteList(L,e);
            break;
        case 6:
            TraverseList(L);
            break;
        default:
          printf("�����������������");
          break;
        }

    }





    system("pause");
    return 0;
};
