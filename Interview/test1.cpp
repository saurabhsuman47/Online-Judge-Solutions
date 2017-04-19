#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int data;
	node *next;
};

class LinkedList{
	public:
		node *head ;
		node *tail ;
		void insert(int data){
			node *new_node = new node();
			new_node -> data = data;
			new_node -> next = NULL;
			if(head == NULL){
				head = new_node;
				tail = new_node;
			}
			else{
				tail -> next = new_node;
				tail = new_node;
			}
		}
		
		void print(){
			node *ptr = head;
			while(ptr != NULL){
				cout << ptr -> data << " ";
				ptr = ptr -> next;
			}
			cout<<endl;
		}
		int len(){
			int count = 0;
			node *ptr = head;
			while(ptr != NULL){
				count++;
				ptr = ptr -> next;
			}
			return count;
		}
		LinkedList(){
			head = NULL;
			tail = NULL;
		}

};

node* Xor(node *a, node *b){
	return (node*)((long)a ^ (long)b);
}

void MakeXorList(node* head){
	node *ptr = head;
	node *temp = NULL, *temp1 = NULL;
	while(ptr != NULL){
		ptr -> next = Xor(temp, (ptr -> next));
		temp1 = ptr;
		ptr = Xor(temp, ptr -> next);
		temp = temp1;
	}
}

void PrintXorList(node *ptr){
	node *temp = NULL, *temp1 = NULL;
	while(ptr != NULL){
		cout<<ptr -> data<<" ";
		temp1 = ptr;
		ptr = Xor(temp, ptr -> next);
		temp = temp1;
	}
	cout<<endl;
}

int main(){
	
	LinkedList list = LinkedList();
	for(int i = 1; i < 20; i++){
		list.insert(i);
	}
	int len = list.len();
	list.print();	

	MakeXorList(list.head);	
	int k = 5;

	node *tempr = NULL;
	node *currr = list.tail;
	node *templ = NULL;
	node *currl = list.head;

	for(int j = 0; j < len/(2*k); j++){
		
		for(int i = 0; i < k; i++){
			node *temp = currr;
			currr = Xor(currr -> next , tempr);
			tempr = temp;
		}

		node *temp1 = currr;
		node *temp2 = tempr;

		for(int i = 0; i < k; i++){		
			swap(temp2->data, currl->data);
			node *temp3 = Xor(temp2 -> next , temp1);
			temp1 = temp2;
			temp2 = temp3;

			node *temp = Xor(currl -> next, templ);
			templ = currl;
			currl = temp;			
		}
	}
	PrintXorList(list.head);

	return 0;
}