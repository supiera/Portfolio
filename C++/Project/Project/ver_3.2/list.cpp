#include "list.h"

List* CreateList(FN_DELETE fnDelete) {
	Node* head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;

	List* list = new List;
	list->head = head;

	list->fnDel = fnDelete;

	return list;
}

void RemoveList(List* list, bool deleteData){
	Node* current = list->head;

	do {
		Node* next = current->next;
		if (deleteData){
			if (list->fnDel)
				(*list->fnDel)(current->data);
			else
				delete current->data;
		}
		delete current;
		current = next;
	} while(current != list->head);

	delete list;
}

Node* GetTail(List* list){
	return list->head->prev;
}

void InsertNodeAfter(Node* node, void* data){
	Node* before = node;
	Node* after = node->next;

	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	after->prev = newNode;
	before->next = newNode;
}

void RemoveNode(List* list, Node* node, bool deleteData){
	Node* before = node->prev;
	Node* after = node->next;

	before->next = after;
	after->prev = before;

	if (deleteData){
		if (list->fnDel)
			(*list->fnDel)(node->data);
		else
			delete node->data;
	}

	delete node;
}

Node* GetNext(Node* node){return node->next;}

Node* GetPrev(Node* node){return node->prev;}

void* GetData(Node* node){return node->data;}
