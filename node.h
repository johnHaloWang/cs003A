#ifndef NODE_H
#define NODE_H
#include "iostream"
using namespace std;
typedef int ITEM_TYPE ;

struct Node{
   //member varables
   ITEM_TYPE _item;
   Node* _next;
   //constructors
   Node( );
   Node(ITEM_TYPE item);
   friend ostream& operator << (ostream& outs, const Node& printMe);
};

#endif // NODE_H
