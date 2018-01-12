// c++Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include "Node.h"

using namespace std;

////STL LAB
void SampleOfListFind();
void SampleOfListInsert();
void SampleOfListRemove();

void PrintElement(string& element)
{
cout<<element<<endl;
}

///////END///////////////

////Althrithm lab

////ŷ������㷨(�������������Լ��)
int God(int M,int N)
{
int rem ;
while(N > 0)
{
rem=M%N;
M=N;
N=rem;
}
return M;
}

////�����������еĺͣ����Ӷ�O(n)
int GetMaxSubSeq(int* arr,int len)
{
	////�Ƿ����������
	if(arr==NULL)
	{
	return -1;
	}

	////ȫ�Ǹ��������
int index = 0;
int maxNum = arr[0];
for(int i = 0;i<len;i ++){
if(arr[i] < 0)
{
index++;
maxNum = maxNum > arr[i] ? maxNum:arr[i];
}
else
{
break;
}
}
if(index == len)
{
return maxNum;
}

////��ȫ�Ǹ��������

int sum = 0;
int max = 0;
for(int i=0;i < len;i ++)
{
	sum += arr[i];
max=max<sum?sum :max;
sum=sum>0?sum:0;
}

return max;
}


/////�����������еĺ�,���Ӷ�O(n^2)
int GetMaxSubSequence(int* arr,int len)
{
	int i, j;
    int curSum; /* ��ǰ���к� */
    int maxSum; /* ������к� */

    /* ��ʼ����������к�Ϊ���е�һ��Ԫ�� */
    maxSum = arr[0];

    /* ���ѭ��������������ʼλ�� */
    for (i = 0; i < len; i++)
    {
        /* ��ʼλ��Ϊi����ʼ����ǰ��Ϊ0 */
        curSum = 0;

        /* �ڲ�ѭ�����������н���λ�� */
        for (j = i; j < len; j++)
        {
            /* ���������кͣ�������������кͱȽϣ�������������к� */
            curSum = curSum + arr[j];

            /* ����������кͱȽϣ�������������к� */
            if (curSum > maxSum)
            {
                maxSum = curSum;
            }
        }
	}
		return maxSum;
}


int _tmain(int argc, _TCHAR* argv[])
{
///////////////////////link table test/////////////////
////��������
//MyLinkTable* lt = new MyLinkTable;
//lt->head = new Node;
//Node* n = lt->head;
//for(int i= 1 ;i < 10;i ++){
//Node* p = new Node(i);
//////��ĩβ׷�ӽڵ�
//lt->Add(p,lt->head);
//}
//
//////��ӡ
//lt->PrintNodes(lt->head);
//
//////�ڵ�7��λ�ú������ڵ�
//Node* sevenNode = new Node(77);
//lt->AddAfter(7,lt->head,sevenNode);
//////��ӡ
//lt->PrintNodes(lt->head);
//////ɾ��������ڵ�
//lt->RemovdeAt(0,lt->head);
//////��ӡ
//lt->PrintNodes(lt->head);

//////////////////////end////////////////


////////////////////////link stack test/////////////

//MyLinkStack* ls = new MyLinkStack;
//ls->top = new Node(0);
//for(int i = 1;i < 10;i ++)
//{
//ls->Push(new Node(i),ls->top);
//}
//
//ls->PrintStack(ls->top);
//Node* tmp = ls->Pop(ls->top);
//delete tmp;
//ls->PrintStack(ls->top);

///////////////////////end//////////////////

//////BTRee Test////////////////////////////

TNode *head = new TNode;
head->data = 7;

BTree *btree = new BTree;
btree->head = head;


btree->InsertNode(new TNode(3));
btree->InsertNode(new TNode(1));
btree->InsertNode(new TNode(2));
btree->InsertNode(new TNode(6));
btree->InsertNode(new TNode(4));
btree->InsertNode(new TNode(8));
btree->InsertNode(new TNode(9));




btree->PrintNode(btree->head);

TNode* targetNode = btree->FindValue(btree->head,9);
if(NULL == targetNode){
cout<<"can not found";
}
else{
cout<<targetNode->data<<endl;
}
/////////End/////////////////////////////////


cin.get();
	return 0;
}

/////////////////////STL////////////////////

///����Ԫ��
///summary
///
void SampleOfListFind()
{
	////����һ������
list<string> fruitList;
////���ϵĵ�����
list<string>::iterator fruitIterator;
////����һЩԪ��
fruitList.push_back("apple");
fruitList.push_back("pineApple");
fruitList.push_back("starApple");
////��ͼ����һ��Ԫ�أ����ѵ�ַ���ظ�������
fruitIterator = find(fruitList.begin(),fruitList.end(),
					 "apple");

if(fruitIterator==fruitList.end()){
	////��������ַ�ڼ���β������ʾû���ҵ�
cout<<"not found"<<endl;
}
else{
	////����ҵ���Ԫ��
cout<< *fruitIterator<<endl;
}

}

///////////
////summary
////����Ԫ��
void SampleOfListInsert(){
////����һ������
list<string> fruitList;
////����һ��������
list<string>::iterator fruitIterator;

////����һЩԪ��
fruitList.push_back("apple");
fruitList.push_back("pineApple");
fruitList.push_back("starApple");
fruitIterator = fruitList.begin();
fruitIterator=fruitIterator ++;
fruitList.insert(fruitIterator,"secondApple");



////ʹ��forѭ������֤���
for(fruitIterator = fruitList.begin();fruitIterator!=
	fruitList.end();fruitIterator++){
cout<<*fruitIterator<<endl;
}

////����
fruitList.sort();

////ʹ��foreachѭ����ӡԪ��
for_each(fruitList.begin(),fruitList.end(),PrintElement);

}

////summary
////�Ƴ�Ԫ��
////////////
void SampleOfListRemove(){
////����һ������
list<string> fruitList;
////����һ��������
list<string>::iterator fruitIterator;

////����һЩԪ��
fruitList.push_back("apple");
fruitList.push_back("pineApple");
fruitList.push_back("starApple");
fruitList.push_back("apple4");
fruitList.push_back("apple5");
fruitList.push_back("apple6");
fruitList.push_back("apple7");
fruitList.push_back("apple8");
fruitList.push_back("apple9");
fruitList.push_back("apple10");
fruitList.push_back("apple11");
fruitList.push_back("apple12");
////�Ƴ����һ��Ԫ��
fruitList.pop_back();
////�Ƴ���һ��Ԫ��
fruitList.pop_front();
////��һ��ָ�룬�Ƴ�ָ���Ԫ��
fruitList.erase(++++fruitList.begin());
////�Ƴ�ָ��Ԫ��
fruitList.remove("apple6");

for_each(fruitList.begin(),fruitList.end(),PrintElement);
}

/////////////////////////////END//////////////////