#ifndef LIST_H
#define LIST_H

struct Node{
	Node* prev;
	Node* next;
	void* data;
};

struct List{
	Node* head;
};

List* CreateList();
void InsertNodeAfter();
void RemoveNode();
void ShowNames();
void RemoveList();

#endif