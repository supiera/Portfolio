#include "list.h"

// 새로운 링크드 리스트를 만든다.
// fnDelete : 데이타 제거시 호출할 함수
// 반환값 : 새로운 링크드 리스트의 포인터
List* CreateList(FN_DELETE fnDelete)
{
	// 헤드 노드를 만들고 초기화한다.
	Node* head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;


	// List 구조체를 만들고 초기화한다.
	List* list = new List;
	list->head = head;

	// 데이터 제거 함수의 주소를 보관한다.
	list->fnDel = fnDelete;

	// List 구조체를 반환한다.
	return list;
}

// 리스트를 제거한다. 
// 리스트의 모든 노드와 데이터도 제거한다.
// list : 리스트
// deleteData : true면 노드의 데이터도 제거한다.
void RemoveList(List* list, bool deleteData)
{
	// head 노드부터 마지막 노드까지 제거한다.
	Node* current = list->head;

	do
	{
		// 현재 노드를 지울 것이므로
		// 다음 노드를 구해둔다.
		Node* next = current->next;

		// 현재 노드의 데이터를 제거한다.
		if (deleteData)
		{
			if (list->fnDel)
				(*list->fnDel)(current->data);
			else
				delete current->data;
		}

		// 현재 노드를 제거한다.
		delete current;

		// 현재 노드를 갱신한다.
		current = next;
	} while (current != list->head);
	// while() 문에 도달한 상태에서
	// list->head가 가리키는 곳의 메모리는
	// 해제된 상태이지만, list->head처럼
	// 그곳의 주소값만 사용하는 것은 상관없다.

	// 리스트를 제거한다.
	delete list;
}

// 마지막 노드를 구한다.
// list : 리스트
// 반환값 : 리스트의 마지막 노드
Node* GetTail(List* list)
{
	// 헤드 노드의 이전 노드를 반환한다.
	// (헤드 노드 자기 자신일 수도 있다.)
	return list->head->prev;
}

// 새로운 노드를 추가한다.
// node : 이 노드 뒤에 새 노드가 추가된다.
// data : 새 노드의 데이타
void InsertNodeAfter(Node* node, void* data)
{
	// 삽입되려는 곳의 앞, 뒤 노드를 구해놓으면
	// 읽기 쉬운 소스 코드를 만들 수 있다.
	Node* before = node;
	Node* after = node->next;

	// 새 노드를 만들고 초기화한다.
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	// node의 뒤에 있던 노드가 새 노드를 가리키도록 만든다.
	after->prev = newNode;

	// 매개변수 node가 새 노드를 가리키도록 만든다.
	before->next = newNode;
}

// 노드를 제거한다.
// list : 노드가 포함된 리스트
// node : 제거할 노드
// deleteData : true면 노드가 가리키는 데이타도 제거한다.
void RemoveNode(List* list, Node* node, bool deleteData)
{
	// node의 앞, 뒤 노드를 구해놓으면
	// 읽기 쉬운 소스 코드를 만들 수 있다.
	Node* before = node->prev;
	Node* after = node->next;

	// node의 이전 노드와 다음 노드를 연결해준다.
	before->next = after;
	after->prev = before;

	// 현재 노드의 데이터를 제거한다.
	if (deleteData)
	{
		if (list->fnDel)
			(*list->fnDel)(node->data);
		else
			delete node->data;
	}

	// 현재 노드를 제거한다.
	delete node;
}

// 노드의 다음 노드를 반환한다.
// node : 이 노드의 다음 노드가 반환된다.
// 반환값 : node의 다음 노드
Node* GetNext(Node* node)
{
	return node->next;
}

// 노드의 이전 노드를 반환한다.
// node : 이 노드의 이전 노드가 반환된다.
// 반환값 : node의 이전 노드
Node* GetPrev(Node* node)
{
	return node->prev;
}

// 노드에 보관된 데이터를 반환한다.
// node : 이 노드의 데이터를 반환한다.
// 반환값 : node에 보관된 데이타
void* GetData(Node* node)
{
	return node->data;
}
