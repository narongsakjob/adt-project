#include <iostream>
using namespace std;

typedef int valueType;

struct ListNode{
	valueType val;
	ListNode* next;

	ListNode ( valueType val, ListNode* next = 0 ) : val( val ), next( next ){
	}

};

class LinkedList {
	private :
		ListNode* header;
		ListNode* tail;

	public :
		LinkedList();
		//~LinkedList();
		void print_list();
		int count_list();
  		void insert_tail(valueType x);
  		valueType get_front();
  		void delete_front();
  		bool is_empty();
};

LinkedList::LinkedList() {
	header = new ListNode(0);
	tail = header;
}



void LinkedList::print_list()
{
  ListNode* node = header->next;
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

int LinkedList::count_list()
{
	int i=0;
  	ListNode* node = header->next;
  	while(node != 0) {
    	i++;
    	node = node->next;
  	}
  	return i;
}

void LinkedList::insert_tail( valueType x ){
	ListNode *new_node = new ListNode ( x , 0 );
	if ( header == tail ) header->next = new_node;
	tail->next = new_node;
	tail = new_node;

}

valueType LinkedList::get_front(){
	ListNode *temp = header -> next;
	return temp -> val;

}

void LinkedList::delete_front(){
	if ( is_empty()){
		throw "Error: list is empty";
	}
	ListNode * front = header -> next;
	if (tail == front) tail = header;
	header -> next = front -> next;
	delete front;
}

bool LinkedList::is_empty(){
	return header -> next == 0;
}


int main(){

  LinkedList linklist1;
  int n;
  cin >> n;

  for( int i = 1 ; i <= n ; i++ ){
    int check;
    cin >> check;
    if( check == 1 ){
      int numOne;
      cin >> numOne;

      for( int j = 0 ; j < numOne ; j++ ){

        int temp;
        cin >> temp;
        linklist1.insert_tail(temp);

      }

    }else if(check == 2){
      cout <<linklist1.get_front()<<endl;
      linklist1.delete_front();
    }

  }

  cout << linklist1.count_list() << endl;



}
