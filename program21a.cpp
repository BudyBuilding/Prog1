#include "std_lib_facilities.h"


template<typename C>
C ins(C mp, int k)
	{
		
		string b;
		int a;

		for(int i = 0; i < k; i++)
		{
			cout << "Please enter a string" << endl;
			cin >> b;

			cout << "Please enter a value" << endl;
			cin >> a;
			mp[b] = a;
		
		}
		return mp;
	}

template<typename C>
int sum(const C mp)
	{
		int sm = 0;

		for(const auto& p : mp)
			sm = sm + p.second;

		return sm;

	}


template<typename C>
map<int,string> copyinv(const C mp)
	{
		map<int, string> ma;

		for(const auto& p : mp)
			{
				ma[p.second] = p.first;
			}
		return ma;
	}



int main()
{
map<string, int> msi;
msi = ins(msi, 10);

for (const auto& p : msi)
{
	cout << p.first << ':' << p.second << endl;
}
cout << endl; 

msi.erase("Jack");
for (const auto& p : msi)
{
	cout << p.first << ':' << p.second << endl;
}

for (const auto& p : mis)
{
	cout << p.first << ':' << p.second << endl;
}


cout << sum(msi) << endl;
map<int, string>  mis;
mis = copyinv(msi);

for (const auto& p : mis)
{
	cout << p.first << ':' << p.second << endl;
}
cout << endl; 




	return 0;
}