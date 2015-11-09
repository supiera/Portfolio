#include "list.h"

List::List(FN_DELETE fnDelete, bool deleteData){
	this->fnDel = fnDelete;
	this->deleteData = deleteData;

	head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;
}


List::~List(){
	RemoveAll();
	delete head;
	head = 0;
}

void List::RemoveAll(){
	Node* current = head->next;
	while(current != head){
		Node* next = current->next;

		if(deleteData){
			if(fnDel)
				(*fnDel)(current->data);
			else
				delete current->data;
		}
		delete current;
		current = next;
	}
	head->next = head;
	head->prev = head;
}

Node* List::GetHead() const {return head;}
Node* List::GetTail() const {return head->prev;}


void List::InsertNodeAfter(Node* node, void* data){
	Node* before = node;
	Node* after = node->next;

	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	after->prev = newNode;
	before->next = newNode;
}

void List::RemoveNode(Node* node){
	Node* before = node->prev;
	Node* after = node->next;

	before->next = after;
	after->prev = before;

	if (deleteData){
		if (fnDel)
			(*fnDel)(node->data);
		else
			delete node->data;
	}

	delete node;
}

Node* Node::GetNext() const {return next;}
Node* Node::GetPrev() const {return prev;}
void* Node::GetData() const {return data;}
