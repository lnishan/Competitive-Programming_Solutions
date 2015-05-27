#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <deque>

using namespace std;

typedef unsigned long long int LLU;

deque<int> p1, p2;

set<LLU> vst;
set<LLU>::iterator it;

int main()
{
	p1.clear(); p2.clear(); vst.clear();
	int n1, n2;
	int i, j, n, ai, cnt = 0;
	LLU st;
	cin >> n;
	cin >> n1;
	for (i = 0; i < n1; i++)
	{
		cin >> ai;
		p1.push_back(ai);
	}
	cin >> n2;
	for (i = 0; i < n2; i++)
	{
		cin >> ai;
		p2.push_back(ai);
	}
	
	while (p1.size() && p2.size())
	{
		n1 = p1.front();
		p1.pop_front();
		
		n2 = p2.front();
		p2.pop_front();
		if (n1 > n2)
		{
			p1.push_back(n2);
			p1.push_back(n1);
		}
		else
		{
			p2.push_back(n1);
			p2.push_back(n2);
		}
		st = 0;
		for (i = 0; i < p1.size(); i++)
			st = st * 11 + p1[i];
		st *= 11;
		for (i = 0; i < p2.size(); i++)
			st = st * 11 + p2[i];
		it = vst.find(st);
		if (it != vst.end()) break;
		vst.insert(st);
		
		++cnt;
	}
	
	if (p1.size() && p2.size())
	{
		puts("-1");
	}
	else
	{
		cout << cnt << " ";
		if (p1.size())
			cout << "1";
		else
			cout << "2";
	}
	return 0;
}
