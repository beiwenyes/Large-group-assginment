#ifndef TEST_H_INCLUDE
#define TEST_H_INCLUDE
struct Node{
    int data;
    struct Node *next;

}*L;
struct Node *InitList(struct Node *L);
struct Node *InsertList(struct Node *L,int i,int e);
struct Node *SearchList(struct Node*L,int e);
struct Node *DeleteList(struct Node*L,int i);
void TraverseList(struct Node *L);
void ReverseEvenList(struct Node *L);
struct Node *FindMidNode(struct Node *L);
struct Node *IsLoopList(struct Node *L);
struct Node *creatList(struct Node *L,int e);
#endif
