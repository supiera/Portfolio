#include "list.h"

// ���ο� ��ũ�� ����Ʈ�� �����.
// fnDelete : ����Ÿ ���Ž� ȣ���� �Լ�
// ��ȯ�� : ���ο� ��ũ�� ����Ʈ�� ������
List* CreateList(FN_DELETE fnDelete)
{
	// ��� ��带 ����� �ʱ�ȭ�Ѵ�.
	Node* head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;


	// List ����ü�� ����� �ʱ�ȭ�Ѵ�.
	List* list = new List;
	list->head = head;

	// ������ ���� �Լ��� �ּҸ� �����Ѵ�.
	list->fnDel = fnDelete;

	// List ����ü�� ��ȯ�Ѵ�.
	return list;
}

// ����Ʈ�� �����Ѵ�. 
// ����Ʈ�� ��� ���� �����͵� �����Ѵ�.
// list : ����Ʈ
// deleteData : true�� ����� �����͵� �����Ѵ�.
void RemoveList(List* list, bool deleteData)
{
	// head ������ ������ ������ �����Ѵ�.
	Node* current = list->head;

	do
	{
		// ���� ��带 ���� ���̹Ƿ�
		// ���� ��带 ���صд�.
		Node* next = current->next;

		// ���� ����� �����͸� �����Ѵ�.
		if (deleteData)
		{
			if (list->fnDel)
				(*list->fnDel)(current->data);
			else
				delete current->data;
		}

		// ���� ��带 �����Ѵ�.
		delete current;

		// ���� ��带 �����Ѵ�.
		current = next;
	} while (current != list->head);
	// while() ���� ������ ���¿���
	// list->head�� ����Ű�� ���� �޸𸮴�
	// ������ ����������, list->headó��
	// �װ��� �ּҰ��� ����ϴ� ���� �������.

	// ����Ʈ�� �����Ѵ�.
	delete list;
}

// ������ ��带 ���Ѵ�.
// list : ����Ʈ
// ��ȯ�� : ����Ʈ�� ������ ���
Node* GetTail(List* list)
{
	// ��� ����� ���� ��带 ��ȯ�Ѵ�.
	// (��� ��� �ڱ� �ڽ��� ���� �ִ�.)
	return list->head->prev;
}

// ���ο� ��带 �߰��Ѵ�.
// node : �� ��� �ڿ� �� ��尡 �߰��ȴ�.
// data : �� ����� ����Ÿ
void InsertNodeAfter(Node* node, void* data)
{
	// ���ԵǷ��� ���� ��, �� ��带 ���س�����
	// �б� ���� �ҽ� �ڵ带 ���� �� �ִ�.
	Node* before = node;
	Node* after = node->next;

	// �� ��带 ����� �ʱ�ȭ�Ѵ�.
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	// node�� �ڿ� �ִ� ��尡 �� ��带 ����Ű���� �����.
	after->prev = newNode;

	// �Ű����� node�� �� ��带 ����Ű���� �����.
	before->next = newNode;
}

// ��带 �����Ѵ�.
// list : ��尡 ���Ե� ����Ʈ
// node : ������ ���
// deleteData : true�� ��尡 ����Ű�� ����Ÿ�� �����Ѵ�.
void RemoveNode(List* list, Node* node, bool deleteData)
{
	// node�� ��, �� ��带 ���س�����
	// �б� ���� �ҽ� �ڵ带 ���� �� �ִ�.
	Node* before = node->prev;
	Node* after = node->next;

	// node�� ���� ���� ���� ��带 �������ش�.
	before->next = after;
	after->prev = before;

	// ���� ����� �����͸� �����Ѵ�.
	if (deleteData)
	{
		if (list->fnDel)
			(*list->fnDel)(node->data);
		else
			delete node->data;
	}

	// ���� ��带 �����Ѵ�.
	delete node;
}

// ����� ���� ��带 ��ȯ�Ѵ�.
// node : �� ����� ���� ��尡 ��ȯ�ȴ�.
// ��ȯ�� : node�� ���� ���
Node* GetNext(Node* node)
{
	return node->next;
}

// ����� ���� ��带 ��ȯ�Ѵ�.
// node : �� ����� ���� ��尡 ��ȯ�ȴ�.
// ��ȯ�� : node�� ���� ���
Node* GetPrev(Node* node)
{
	return node->prev;
}

// ��忡 ������ �����͸� ��ȯ�Ѵ�.
// node : �� ����� �����͸� ��ȯ�Ѵ�.
// ��ȯ�� : node�� ������ ����Ÿ
void* GetData(Node* node)
{
	return node->data;
}
