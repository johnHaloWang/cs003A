#include <iostream>
#include "node.h"
#include "nodelistfunctions.h"
using namespace std;
void unit_testing_node();
void printNode(Node * head);
int main()
{
  unit_testing_node();
  return 0;
}
void printNode(Node * head){
  if(head!=nullptr)
      PrintList(head);
  else
      cout<<"Not in the list"<<endl;
}

void unit_testing_node(){
      //link list input
      ITEM_TYPE intArr[]={1,2,3,4, 8,9};
      Node * head = NULL;
      cout<<"Building the list ...."<<endl;
      cout<<"The list is: ";
      BuildLink(head, intArr, sizeof(intArr)/sizeof(intArr[0]));
      PrintList(head);
      cout<<endl<<endl<<endl;
      Node * backCpy = CopyList(head);
      cout<<"Unit testing for search function one: "<<endl;
      cout<<"searching for the second element in the list (2)"<<endl;
      head = SearchList(head,2);
      printNode(head);
      cout<<endl<<endl<<endl;
      cout<<"Unit testing for search function two: "<<endl;
      cout<<"searching for the n element in the list (10) -- should not find it"<<endl;
      Node * nodesearch = SearchList(head, 10);
      printNode(nodesearch);
      cout<<endl<<endl<<endl;
      cout<<"Unit testing for insert head (value 10000): "<<endl;
      Inserthead(head, 10000);
      printNode(head);
      cout<<endl<<endl<<endl;
      cout<<"Unit testing for copyList: "<<endl;
      Node * copyNode = CopyList(head);
      printNode(copyNode);
      cout<<endl<<endl<<endl;
      cout<<"Unit testing for delete (value 4): "<<endl;
      Node * deleteThis = SearchList(head, 4);
      int i = Delete(head, deleteThis);

      cout<<"The deleted item content is: "<<i<<endl;
      printNode(head);
      cout<<endl<<endl<<endl;
      cout<<"Unit testing for delete (value 10000): "<<endl;
      deleteThis = SearchList(head, 10000);
      printNode(deleteThis);
      i = Delete(head, deleteThis);
      cout<<"The deleted item content is: "<<i<<endl;
      printNode(head);
      cout<<endl<<endl<<endl;

      cout<<"Unit testing for insertAfter (find node value 3 then insertAfter 4): "<<endl;
      nodesearch = SearchList(head, 3);
      InsertAfter(head, nodesearch, 4);
      printNode(head);
      cout<<endl<<endl<<endl;

      cout<<"Unit testing for insertBefore (find node value 2 then insertBefore 1): "<<endl;
      nodesearch = SearchList(head, 2);
      InsertBefore(head, nodesearch, 1);
      printNode(head);
      cout<<endl<<endl<<endl;

      cout<<"Unit testing for  WhereThisGoes: seeking the place for 44, it shold return the last note"<<endl;
      head = WhereThisGoes(head, 44);
      printNode(head);
      head = CopyList(backCpy);
      PrintList(head);
      head = WhereThisGoes(head, 6);
      printNode(head);
      cout<<endl<<endl<<endl;
      cout<<"Unit testing for clearList()"<<endl;
      head = CopyList(backCpy);
      cout<<"current list: "<<endl;
      printNode(head);

      ClearList(head);
      cout<<"After Cleaned: "<<endl;
      //printNode(head);
      Inserthead(head, 10000);
      printNode(head);


}
