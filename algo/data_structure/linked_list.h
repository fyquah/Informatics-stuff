#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *link;

};

class LinkedList
{
private:
	Node *head;
	Node *tail;
	int number_of_elements;
	void recursiveTransverse(Node *tmp);
	Node * getNode();
public:
	LinkedList();
	~LinkedList();
	void create();
	void insert();
	void append(Node * new_node);
	void insertAt(int pos , Node * new_node); // O(N)
	void deleteAt(int pos);
	void display();
	int size();
	static Node * getNode(int data){
		Node * new_node = new Node;
		new_node->data = data;
		new_node->link = NULL;
		return new_node;
	}
};

void LinkedList::recursiveTransverse(Node * tmp){
	if(tmp == NULL)
		return;
	std::cout << tmp->data << std::endl;
	recursiveTransverse(tmp->link);
}

LinkedList::LinkedList(){
	head = NULL;
	tail = NULL;
}

LinkedList::~LinkedList(){
	Node * temp;
	while(head != NULL){
		temp = head;
		head = head->link;
		delete head;
	}
}

void LinkedList::create(){
	char ans;
	Node * new_node;
	while(true)
	{
		cout << "Any more nodes to be added? (Y/N)" << endl;
		cin >> ans;
		if(ans == 'n' || ans == 'N') break;
		new_node = getNode();
		append(new_node);
	}
}

void LinkedList::append(Node * new_node)
{
	number_of_elements++;
	if(head == NULL)
		head = tail = new_node;
	else {
		tail->link = new_node;
		tail = new_node;
	}
}

void LinkedList::insertAt(int pos , Node * new_node){
	if(pos >= number_of_elements){
		cerr << "Exceeded number of elements" << endl;
		return;
	}
	Node * temp = head;
	int count = 0;
	bool flag = true;

	if(pos == 0){
		new_node->link = temp;
		head = new_node;
	}
	else
		while(count < pos - 1){
			temp = temp->link;
			if(temp == NULL){
				flag = false;
				break;
			}
			count++;
		}

	if(flag) {
		new_node->link = temp->link;
		temp->link = new_node;
	}
	else
		cout << "Position not found!!" << endl;
}

void LinkedList::deleteAt(int pos){
	if(pos >= number_of_elements){
		cerr << "Exceeded number of elements" << endl;
		return;
	}
	Node * temp = head;
	int current = 0;
	if(pos == 0){
		head = head->link;
		delete temp;
	}
	else {
		while(current < pos -1){
			temp = temp->link;
			current++;
		}
		Node * prev;
		prev = temp;
		temp = temp->link;
		prev->link = temp->link;
		delete temp;
	}
}

Node * LinkedList::getNode()
{
	Node *new_node;
	new_node = new Node;
	cout << "Please enter data for new node" << endl;
	cin >> new_node->data;
	new_node->link = NULL;
	return (new_node);
}

void LinkedList::display(){
	recursiveTransverse(this->head);
}

inline int LinkedList::size() {
	return number_of_elements;
}
