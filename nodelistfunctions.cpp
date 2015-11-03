#include "nodelistfunctions.h"
/*
Create a simple program where you create, display,
search, delete elements within a linked list.

Watch your function arguments. Pointer parameters are passed by
reference to some functions and by value to others.
*/
/*  Prints the items in list. Uses setw( ) to space the items on the output stream */
void PrintList(Node * current){//head
  cout<<"H->";
  while(current!=NULL){
      cout<<*current;
      current = current->_next;
  }
    cout<<"|||"<<endl;
}
Node * SearchList(Node *head, ITEM_TYPE key){
    while(head->_next != nullptr && head->_item!=key)
       head = head->_next;
    head=(head->_item!=key)?nullptr:head;
    return head;
}
void Inserthead(Node *&head, ITEM_TYPE insertThis){
    Node * newHead = new Node(insertThis);
    newHead->_next = head;
    head = newHead;
}
/* Takes a pointer to an item in the list (previousToThis)
 * and returns a pointer to the node before the designated node.
 * Returns NULL if the node is the first node in the list.
*/

Node * PreviousNode(Node * head, Node * previousToThis){
    if(head->_item==previousToThis->_item)
        return NULL;
    while(head->_next->_item!=previousToThis->_item)
        head = head->_next;
    return head;
}

/*
 * Takes a value (insertThis), and a pointer to a node in
 * the list (beforeThis) and inserts the value before the designated node.
*/

void InsertBefore(Node * &head, Node * beforeThis, ITEM_TYPE insertThis){
  //take linked list pointed to by head, right before node, pointed to by beforeThis, insert a node with the
  //value insertThis

    if(beforeThis==head){
        Inserthead(head, insertThis);
    }else{
        Node * nodeWalker2 = PreviousNode(head, beforeThis);
        Inserthead(nodeWalker2->_next, insertThis);
    }
}
/*
 * Takes a value (insertThis) and a pointer to a node in the list
 * (afterThis) and inserts the value after the designated node
 */
void InsertAfter(Node * &head, Node * &afterThis, ITEM_TYPE insertThis){
  //Node * nodeWalker = SearchList(head, afterThis->_item);
  Node * insertedNote = new Node(insertThis);
  insertedNote->_next=afterThis->_next;
  afterThis->_next=insertedNote;
}

/*
 * Takes a pointer to a node in the list (deleteThis) and removes that node
 * from the list. Deletes the node and returns the item contained within.
 */
ITEM_TYPE Delete(Node * &head, Node * &deleteThis){
    Node * nodeWalker = SearchList(head, deleteThis->_item);
    ITEM_TYPE i = nodeWalker->_item;
    Node *tempNode;
    if(head->_item == deleteThis->_item){
           tempNode = head->_next;
           head = tempNode;
    }else{
          tempNode = PreviousNode(head, deleteThis);
          tempNode->_next=nodeWalker->_next;
          nodeWalker->_next=tempNode;
    }
    return i;
}
/*
 * Takes a value (item) and returns a pointer to the node after which
 * the item belongs in the list.  Assumes the list is sorted.
 * Returns NULL if the item belongs at the head of the list.
 */

Node * WhereThisGoes(Node * head, ITEM_TYPE item){
  if(head->_item==item)
       return NULL;
  while(head->_next != nullptr){
      if(head->_item<item && head->_next->_item > item)
             return head;
      else if(head->_item>item){
            return head;
      }
      head = head->_next;
  }
  return head;
}

/*
 * Takes a list (head) and returns a pointer to
 * a linked list that is a copy of this list.
 */
Node * CopyList(Node *head){
     Node * copyNodeList= new Node();
     Node * walker = copyNodeList;
     if(head->_next==nullptr)
         return nullptr;
      while(head!=nullptr){
          if(walker->_item==NULL){
                  walker->_item = head->_item;
                  Inserthead(walker, head->_item);
          }else{
              InsertAfter(copyNodeList, walker, head->_item);
          }
          head=head->_next;
          walker=walker->_next;
       }
       return copyNodeList;
}
/*
 * Takes a list (head) and deletes
 * all the nodes in the list
 */
void * ClearList(Node *&head){

  if(head==NULL){
        return nullptr;
    }

   Node * current = head;
   Node * nextNode;
    while(current!=NULL){
       nextNode = current->_next;
       delete current;
       current=nextNode;
       PrintList(current);

    }
    head = NULL;
}
/*
 * Takes a position (n) and returns
 * a pointer to the nth position in the list
 */
Node * At(Node *head, int n){
  Node * walker = head;
  int counter =n;
  while(walker->_next != nullptr && counter>0){
     walker = walker->_next;
     counter--;
  }
  return walker;
}
/* in-house utility
 * Takes a pointer and check if it is null
 * if it is this is the head
 */
bool isEmpty(Node *head){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}
/* in-house utility (for data testing)
*/
void BuildLink(Node *&head, ITEM_TYPE intArr[], ITEM_TYPE size){//** see below
    for(int i=size-1; i>=0; i--){
        insert(head, intArr[i]);
    }
}
void insert(Node * &head, ITEM_TYPE number){
            Node* temp = new Node(number);
            temp->_next = head;
            head = temp;
}
