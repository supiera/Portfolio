#include "list.h"
#include "students.h"
#include <iostream>
#include <iomanip>
using namespace std;

List* CreateList(){
	Node* head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;

	List* list = new List;
	list->head = head;

	return list;
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

void RemoveNode(Node* node, bool deleteData){
	Node* before = node->prev;
	Node* after = node->next;

	before->next = after;
	after->prev = before;

	if (deleteData)
		delete node->data;
	delete node;
}

void ShowNames(List* students){
	Node* current = students->head->next;
	while (current != students->head){
		const Student* std = (Student*)current->data;
	}
}

void RemoveList(){
	
}