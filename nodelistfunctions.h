#ifndef NODELISTFUNCTIONS_H
#define NODELISTFUNCTIONS_H
#include "node.h"

void PrintList(Node * head);//good
Node * SearchList(Node * head, ITEM_TYPE key);//good
void Inserthead(Node *&head, ITEM_TYPE insertThis);
void InsertBefore(Node * &head, Node * beforeThis, ITEM_TYPE insertThis);
void InsertAfter(Node * &head, Node * &afterThis, ITEM_TYPE insertThis);
Node * PreviousNode(Node * head, Node * previousToThis);
Node * WhereThisGoes(Node * head, ITEM_TYPE item);
Node * CopyList(Node *head);
bool isEmpty(Node *head);
void BuildLink(Node *&head, ITEM_TYPE intArr[], ITEM_TYPE size);
void insert(Node * &head, ITEM_TYPE number);
Node * At(Node *head, int n);
void * ClearList(Node *&head);
ITEM_TYPE Delete(Node * &head, Node * &deleteThis);

#endif // NODELISTFUNCTIONS_H
