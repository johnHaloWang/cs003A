#include "node.h"

Node::Node(){
   this->_item = NULL;
   this->_next = nullptr;
}
Node::Node(ITEM_TYPE item){
  this->_item = item;
  this->_next = nullptr;
}
ostream& operator << (ostream& outs, const Node& s){
    outs<<"["<<s._item<<"]->";
    return outs;
}
