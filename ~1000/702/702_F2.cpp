#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MAX (long long int)1e15
#define MIN 0

struct Treap{
	long long int key;
	long long int value;
	int index;
	long long int priority;
	long long int lazy1 = 0;
	long long int lazy2 = 0;
	Treap(long long int key, long long int value, int index, long long int priority)
	{
		this->key = key;
		this->value = value;
		this->index = index;
		this->priority = priority;
	}
	Treap* left = nullptr;
	Treap* right = nullptr;
};

void doPropagation(Treap* root)
{
	if(root==nullptr) return;
	if(root->left!=nullptr)
	{
		root->left->lazy1 += root->lazy1, root->left->lazy2 += root->lazy2;
		root->left->key += root->lazy1, root->left->value += root->lazy2;
	}
	if(root->right!=nullptr)
	{
		root->right->lazy1 += root->lazy1, root->right->lazy2 += root->lazy2;
		root->right->key += root->lazy1, root->right->value += root->lazy2;
	}
	root->lazy1 = root->lazy2 = 0;
}

Treap* rightRotate(Treap* root)
{
	Treap* A = root;
	Treap* B = root->left;
	Treap* C = root->right;
	Treap* D = root->left->left;
	Treap* E = root->left->right;
	doPropagation(A);
	doPropagation(B);
	A->left = E, A->right = C;
	B->left = D, B->right = A;
	return B;
}

Treap* leftRotate(Treap* root)
{
	Treap* B = root;
	Treap* D = root->left;
	Treap* A = root->right;
	Treap* E = root->right->left;
	Treap* C = root->right->right;
	doPropagation(B);
	doPropagation(A);
	B->left = D, B->right = E;
	A->left = B, A->right = C;
	return A;
}

Treap* insert(Treap* root, long long int key, long long int value, int index, long long int priority)
{
	doPropagation(root);
	if(root==nullptr)
	{
		Treap *newNode = new Treap(key,value,index,priority);
		return newNode;
	}
	else
	{
		if(key<=root->key)
		{
			root->left = insert(root->left,key,value,index,priority);
			if(root->left->priority > root->priority) root = rightRotate(root);
		}
		else
		{
			root->right = insert(root->right,key,value,index,priority);
			if(root->right->priority > root->priority) root = leftRotate(root);
		}
		return root;
	}
}

std::pair<Treap*,Treap*> split(Treap*root, long long int key)
{
	root = insert(root,key,0,0,MAX);
	Treap* L = root->left;
	Treap* R = root->right;
	delete root;
	return {L,R};
}

Treap* erase(Treap* root)
{
	doPropagation(root);
	if(root->left==nullptr && root->right == nullptr)
	{
		delete root;
		return nullptr;
	}
	else if(root->left==nullptr)
	{
		root = leftRotate(root);
		root->left = erase(root->left);
		return root;
	}
	else if(root->right==nullptr)
	{
		root = rightRotate(root);
		root->right = erase(root->right);
		return root;
	}
	else
	{
		if(root->left->priority>=root->right->priority)
		{
			root = rightRotate(root);
			root->right = erase(root->right);
			return root;
		}
		else
		{
			root = leftRotate(root);
			root->left = erase(root->left);
			return root;
		}
	}
}

Treap* merge(Treap* root1, Treap* root2)
{
	// root1<root2
	Treap* r = root1;
	doPropagation(root1);
	while(r->right!=nullptr) r = r->right,doPropagation(r);
	long long int key = r->key;
	Treap *newNode = new Treap(key,0,0,MIN);
	newNode->left = root1;
	newNode->right = root2;
	return erase(newNode);
}

Treap* move(Treap* root1, Treap* root2)
{
	// root1 -> root2
	doPropagation(root1);
	doPropagation(root2);
	if(root1==nullptr) return root2;
	else
	{
		insert(root2,root1->key,root1->value,root1->index,root1->priority);
		root2 = move(root1->left,root2);
		root2 = move(root1->right,root2);
		delete root1;
	}
}

long long int ans[200010];
void conclusion(Treap* root)
{
	doPropagation(root);
	if(root==nullptr) return;
	ans[root->index] = root->value;
	conclusion(root->left);
	conclusion(root->right);
}

Treap* root = nullptr;
long long int getRand()
{
	long long int s1 = rand();
	long long int s2 = rand();
	return 32768*s1+s2;
}

std::pair<int,int> x[200010];
bool cmp(std::pair<int,int> A, std::pair<int,int> B)
{
	if(A.second==B.second) return A.first<B.second;
	return A.second>B.second;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].first,&x[i].second);
	std::sort(x+1,x+a+1,cmp);
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		root = insert(root,c,0,i,getRand());
	}
	
	printf("!!\n");
	for(int i=1;i<=a;i++)
	{
		std::pair<Treap*,Treap*> P1 = split(root,x[i].first-1);
		if(P1.second!=nullptr)
		{
			P1.second->lazy1 -= x[i].first, P1.second->key -= x[i].first;
			P1.second->lazy2++, P1.second->value++;
		}
		std::pair<Treap*,Treap*> P2 = split(P1.second,2*x[i].first-1);
		P1.first = move(P2.first,P1.first);
		root = merge(P1.first,P2.second);
	}
	conclusion(root);
	
	for(int i=1;i<=b;i++) printf("%lld ",ans[i]);
}