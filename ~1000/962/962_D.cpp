#include <stdio.h>
#include <set>

std::set<int> s;
int main()
{
	s.insert(1);
	s.insert(3);
	s.insert(7);
	s.insert(6);
	s.insert(9);
	printf("%s\n",s.find(7)!=s.end()?"YES":"NO");
	printf("%s\n",s.find(8)!=s.end()?"YES":"NO");
}
