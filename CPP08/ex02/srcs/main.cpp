#include <iostream>
#include <list>
#include "../inc/MutantStack.hpp"

using std::cout;
using std::endl;
using std::list;

int main()
{
	//MUTANT STACK;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	cout << mstack.top() << endl;
	mstack.pop();
	cout << mstack.size() << endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	cout << *it << endl;
	++it;
	}
	std::stack<int> s(mstack);
	
	//LIST
	list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	cout << mlist.back() << endl;
	mlist.pop_back();
	cout << mlist.size() << endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	list<int>::iterator it2 = mlist.begin();
	list<int>::iterator ite2 = mlist.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
	cout << *it2 << endl;
	++it2;
	}
	list<int> l(mlist);

return 0;
}