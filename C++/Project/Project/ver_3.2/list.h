#ifndef LIST_H
#define LIST_H

typedef void(*FN_DELETE)(void*);

class Node{
	friend class List;

public:
	Node* GetNext() const;
	Node* GetPrev() const;
	void* GetData() const;

private:
	Node* prev;
	Node* next;
	void* data;
};

class List{
public:
	typedef void(*FN_DELETE)(void*);

public:
	List(FN_DELETE fnDelete = 0, bool deleteData = true);
	~List();

	void InsetNodeAfter(Node* node, void* data);
	void RemoveNode(Node* node);
	Node* GetHead() const;
	Node* GetTail() const;

	void RemoveAll();

private:
	Node* head;
	bool deleteData;
	FN_DELETE fnDel;
};

#endif
