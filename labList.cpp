
#include <iostream>

using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val=0, ListNode* next=0)
    : val(val), next(next) {}
};

class LinkedList
{
private:
  ListNode* header;
  ListNode* tail;
  void free_list();

public:
  LinkedList();
  ~LinkedList();
  void print_list();
  void insert_front(valueType x);
  void append(valueType x);
};


LinkedList::LinkedList()
{
  header = new ListNode(0);
  tail = header;
  free_list();
}
void LinkedList::print_list()
{
  ListNode* node = header->next;
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}


void LinkedList::free_list()
{

  while(header!=0){
    ListNode *temp = header->next;
    delete header ;
    header = temp;
  }

}
void LinkedList::append(valueType x)
{
  ListNode *temp = new ListNode(x);
  *temp = header->next;
  header->next = temp;
  header = temp;

}

void LinkedList::insert_front(valueType x)
{
  ListNode *new_node = new ListNode(x,header->next);
    header->next = new_node;
  ListNode *temp = new ListNode(x);
  *temp = header->next;
  header->next = temp;
  header = temp;
}

int main()
{
   LinkedList list;
  int t;

  cin >> t;
  for(int i = 0; i < t; i++) {
    int dir, val;
    cin >> dir >> val;
    if(dir == 1) {
      list.insert_front(val);
    } else {
      list.append(val);
    }
  }
  list.print_list();
}
