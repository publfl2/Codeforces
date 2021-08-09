#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
int bigRand()
{
	return (rand()*32768+rand())%1234567;
}

struct Treap{
	int key,key_lazy;
	int value,value_lazy;
	int priority;
	int index;
	Treap* left;
	Treap* right;
	Treap(int key, int value, int index)
	{
		this->key = key;
		key_lazy = 0;
		this->value = value;
		value_lazy = 0;
		this->priority = bigRand();
		this->index = index;
		left = right = nullptr;
	}
	Treap(int key, int value, int index, int priority)
	{
		this->key = key;
		key_lazy = 0;
		this->value = value;
		value_lazy = 0;
		this->priority = priority;
		this->index = index;
		left = right = nullptr;
	}
};
void update(Treap* head)
{
	if(head==nullptr) return;
	head->key+=head->key_lazy;
	head->value+=head->value_lazy;
	if(head->left!=nullptr)
	{
		head->left->key_lazy += head->key_lazy;
		head->left->value_lazy += head->value_lazy;
	}
	if(head->right!=nullptr)
	{
		head->right->key_lazy += head->key_lazy;
		head->right->value_lazy += head->value_lazy;
	}
	head->key_lazy = 0,head->value_lazy = 0;
}
Treap* rightRotate(Treap* head)
{
	Treap* A = head->right;
	Treap* B = head->left->left;
	Treap* C = head->left->right;		
	Treap* D = head;
	Treap* E = head->left;
	update(D),update(E);
	D->right = A;
	D->left = C;
	E->right = D;
	E->left = B;
	head = E;
	return head;
}
Treap* leftRotate(Treap* head)
{
	Treap* A = head->left;
	Treap* B = head->right->left;
	Treap* C = head->right->right;
	Treap* D = head;
	Treap* E = head->right;
	update(D),update(E);
	D->left = A;
	D->right = B;
	E->left = D;
	E->right = C;
	head = E;
	return head;
}
Treap* insert(Treap* head, int key, int value,int index, int priority=-1)
{
	update(head);
	if(head==nullptr)
	{
		if(priority==-1) priority = bigRand();
		return new Treap(key,value,index,priority);
	}
	if(head->key>key)
	{
		head->left = insert(head->left,key,value,index,priority);
		if(head->left->priority>head->priority) head = rightRotate(head);
		return head;
	}
	else
	{
		head->right = insert(head->right,key,value,index,priority);
		if(head->right->priority>head->priority) head=leftRotate(head);
		return head;
	}
}
std::pair<Treap*,Treap*> split(Treap* head, int key)
{
	Treap* T = insert(head,key-1,0,0,1234567);
	return std::make_pair(T->left,T->right);
}
Treap* rotate(Treap* head)
{
	printf("%d??\n",head->key);
	update(head);
	Treap* A = head->left;
	Treap* B = head->right;
	update(A),update(B);
	if(A=nullptr&&B==nullptr)
	{
		delete head;
		return nullptr;
	}
	else if(A==nullptr)
	{
		head = leftRotate(head);
		head->left = rotate(head->left);
		return head;
	}
	else if(B==nullptr)
	{
		head = rightRotate(head);
		head->right = rotate(head->right);
		return head;
	}
	else
	{
		if(A->priority<B->priority)
		{
			head = leftRotate(head);
			head->left = rotate(head->left);
			return head;
		}
		else
		{
			head = rightRotate(head);
			head->right = rotate(head->right);
			return head;
		}
	}
}
Treap* merge(Treap* left, Treap* right)
{
	if(left==nullptr) return right;
	if(right==nullptr) return left;
	
	Treap* T = right;
	while(T->left!=nullptr) T = T->left;
	Treap* A;
	A->key = (T->key),A->priority = -1;
	A->left = left, A->right = right;
	
	return rotate(A);
}
Treap* merge2(Treap* head, Treap* node)
{
	if(node==nullptr) return head;
	update(node);
	head = merge2(head,node->left);
	head = merge2(head,node->right);
	head = insert(head,node->key,node->value,node->index,node->priority);
	return head;
}
int ans[200010];
void getAns(Treap* head)
{
	if(head==nullptr) return;
	update(head);
	//printf("%d : %d %d\n",head->index,head->key,head->value);
	ans[head->index] = head->value;
	getAns(head->left);
	getAns(head->right);
}

std::pair<int,int> P[200010];
bool cmp(std::pair<int,int> A, std::pair<int,int> B)
{
	if(A.second==B.second) return A.first<B.first;
	return A.second>B.second;
}
Treap* T;
int main()
{
	int a,b,c;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&P[i].first,&P[i].second);
	std::sort(P+1,P+a+1,cmp);
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&c);
		T = insert(T,c,0,i);
	}
	for(int i=1;i<=a;i++)
	{
		std::pair<Treap*,Treap*> A = split(T,P[i].first);
		if(A.second==nullptr)
		{
			T = A.first;
			continue;
		}
		A.second->key_lazy-=P[i].first;
		A.second->value_lazy++;
		std::pair<Treap*,Treap*> B = split(A.second,P[i].first);
		Treap* C = merge2(A.first,B.first);
		T = merge(C,B.second);
	}
	getAns(T);
	for(int j=1;j<=b;j++) printf("%d ",ans[j]);
}
