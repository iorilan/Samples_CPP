#pragma once

////�ڵ���
class Node
{
public:
	////methods
	Node(void);
	Node(int data);
	~Node(void);

	/////members
	Node* next;
	int data;
};

////Ҷ�ӽڵ���
class TNode
{
public:
	////methods
	TNode(void);
	TNode(int data);
	~TNode(void);

	/////members
	TNode* left;
	TNode* right;
	int data;
};

////������
class MyLinkTable{
public:
	//////methods
	void RemovdeAt(int position,Node* head);
	void Add(Node* node,Node* head);
	void AddAfter(int position,Node* head,Node* node);
	bool IsEmpty(Node* head);
	void PrintNodes(Node* head);
	/////members
	Node* head;
};

/////////////��ջ��///////////////
class MyLinkStack{
public:
	////mothods
	void Push(Node* node,Node* top);
	Node* Pop(Node* top);
	bool IsEmpty(Node* top);
	void PrintStack(Node* top);

	////members
	Node* top;
};

//////////����������///////////

class BTree{
public:
	////methods
	void InsertNode(TNode* node);
	void PrintNode(TNode* head);
	TNode* FindValue(TNode* head,int value);
	TNode* Find(TNode* head,TNode* node);
	bool IsEmpty(TNode* head);
	////members
	TNode* head;

};