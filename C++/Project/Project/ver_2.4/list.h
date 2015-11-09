#ifndef LIST_H
#define LIST_H

typedef void(*FN_DELETE)(void*);

struct Node{
	Node* prev; 
	Node* next;	
	void* data;	
};

struct List{
	Node* head;			
	FN_DELETE fnDel;	
};


List* CreateList(FN_DELETE fnDelete);
void RemoveList(List* list, bool deleteData);
Node* GetTail(List* list);

void InsertNodeAfter(Node* node, void* data);
void RemoveNode(Node* node);
Node* GetNext(Node* node);
Node* GetPrev(Node* node);
void* GetData(Node* node);

#endif
