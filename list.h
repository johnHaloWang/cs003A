#ifndef LIST_H
#define LIST_H
#include "node.h"


class List{
  public:
    List();
    void insertheadlist(int i);
    void insertBefore(Node * beforeThis, int insertThis);
    void insertAfter(Node * &afterThis, int insertThis);
    Node * previousNode(Node * previousToThis);
    Node * whereThisGoes(int item);
    void insert(int number);
    Node * copylist();
    bool isempty();
    void insertToList(int number);
    Node * at(int n);
    void clearlist();
    int deleteNode(Node * &deleteThis);
    void buildlink(int intArr[], int size);

  private:
    Node * head;
    void PrintList(Node * head);//good
    Node * SearchList(Node * head, ITEM_TYPE key);//good
    void Inserthead(Node *&head, ITEM_TYPE insertThis);
    void InsertBefore(Node * &head, Node * beforeThis, ITEM_TYPE insertThis);
    void InsertAfter(Node * &head, Node * &afterThis, ITEM_TYPE insertThis);
    Node * PreviousNode(Node * head, Node * previousToThis);
    Node * WhereThisGoes(Node * head, ITEM_TYPE item);
    Node * CopyList(Node *head);
    bool isEmpty(Node *head);
    void insert(Node * &head, ITEM_TYPE number);
    Node * At(Node *head, int n);
    void * ClearList(Node *&head);
    ITEM_TYPE Delete(Node * &head, Node * &deleteThis);
    void BuildLink(Node *&head, ITEM_TYPE intArr[], ITEM_TYPE size);
};

#endif // LIST_H
