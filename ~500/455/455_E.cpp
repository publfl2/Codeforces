#include <stdio.h>
#include <vector>

struct Node{
	int l;
	int r;
	long long int maxL;
	long long int maxR;
	std::pair<long long int, long long int> line;
	Node* left = NULL;
	Node* right = NULL;
	
	Node(int l, int r, long long int maxL, long long int maxR, std::pair<long long int, long long int> line)
	{
		this->l = l;
		this->r = r;
		this->maxL = maxL;
		this->maxR = maxR;
		this->line = line;
	}
};

void addLine(Node* v, std::pair<long long int, long long int> val)
{
	if((v->maxL)<=val.first*(v->l)+val.second && (v->maxR)<=val.first*(v->r)+val.second)
	{
		v -> maxL = val.first*(v->l)+val.second;
		v -> maxR = val.first*(v->r)+val.second;
		v -> line = val;
	}
	else
	{
		int h = ((v->l) + (v->r))/2;
		makeNode(v->left,v->l,h,maxL,(v->line).first*h+(v->line).second,line);
		makeNode(v->right,h+1,v->r,(v->line).first*(h+1)+(v->line).second,maxR,line);
	}
}

void makeNode(Node* v, int l, int r, long long int maxL, long long int maxR, std::pair<long long int, long long int> line)
{
	if(v!=NULL) return;
	else v = new Node(l,r,maxL,maxR,line);
}


struct segTree{
	Node* value[400010];
	void addLine(int ind, std::pair<long long int, long long int> val, int l=1, int r=100000, int v=1)
	{
		if(l==r)
		{
			makeNode(value[v],1,100000,0,0,std::make_pair(0,0));
			addLine(value[v],val);
		}
		else
		{
			int h = (l+r)/2;
			if(ind<=h) addLine(ind,val,l,h,2*v);
			else addLine(ind,val,h+1,r,2*v+1);
			makeNode(value[v],1,100000,0,0,std::make_pair(0,0));
			addLine(value[v],val);
		}
	}
};
