/*
6. Remove (erase) two Items identified by name from vi.
7. Remove (erase) two Items identified by iid from vi.
8. Repeat the exercise with a list<Item> rather than a vector<Item>.
Now try a map:
1. Define a map<string,int> called msi.
2. Insert ten (name,value) pairs into it, e.g., msi["lecture"]=21.
3. Output the (name,value) pairs to cout in some format of your choice.
4. Erase the (name,value) pairs from msi.
5. Write a function that reads value pairs from cin and places them in msi.
6. Read ten pairs from input and enter them into msi.
7. Write the elements of msi to cout.
8. Output the sum of the (integer) values in msi.
9. Define a map<int,string> called mis.
10. Enter the values from msi into mis; that is, if msi has an element ("lecture",21), mis should have an element
(21,"lecture").
11. Output the elements of mis to cout.
More vector use:
1. Read some floating-point values (at least 16 values) from a file into a vector<double> called vd.
2. Output vd to cout.
3. Make a vector vi of type vector<int> with the same number of elements as vd; copy the elements from vd into vi.
4. Output the pairs of (vd[i],vi[i]) to cout, one pair per line.
5. Output the sum of the elements of vd.
6. Output the difference between the sum of the elements of vd and the sum of the elements of vi.
7. There is a standard library algorithm called reverse that takes a sequence (pair of iterators) as arguments; reverse vd,and output vd to cout.
8. Compute the mean value of the elements in vd; output it.
9. Make a new vector<double> called vd2 and copy all elements of vd with values lower than (less than) the mean into
vd2.
10. Sort vd; output it again.
*/

#include "std_lib_facilities.h"


struct Item 
{ 
	string name; 
	int iid; 
	double value;  
}; 

template<typename Iterator>
Iterator& operator++(Iterator& p){ return p + 1;}


template<typename Iterator>
void print(Iterator first, Iterator last)
 	{
 		for(Iterator p = first; p!= last; p++)
 			cout << (*p).name << '\t'
 				 << (*p).iid << '\t'
 				 << (*p).value << endl; 
 		cout << endl;

 	}

template<typename Iterator>
Iterator findnm(Iterator first, Iterator last,const string& elem)
 	{
 		Iterator b = last;
 		
 		for(Iterator p = first; p!= last; p++)
 			if ((*p).name == elem)
 				b = p;
 			return b;
 	}

template<typename Iterator>
Iterator findid(Iterator first, Iterator last,const int& elem)
 	{
 		Iterator b = last;
 		
 		for(Iterator p = first; p!= last; p++)
 			if ((*p).iid == elem)
 				b = p;
 			return b;
 	} 	

int main(){ 
list<Item> lst;
vector<Item> vi;
string iname = "file";
ifstream ist {iname};
if (!ist) error("can't open input file ",iname);

Item a;
for(int i = 0; i < 10; i++)
{
	ist >> a.name;
	ist >> a.iid;
	ist >> a.value;
	vi.push_back(a);
}
ist.close();
print(vi.begin(), vi.end());

sort(vi.begin(), vi.end(), 
	[](const Item& a, const Item& b) {return a.name < b.name;});

print(vi.begin(), vi.end());
cout << endl;

sort(vi.begin(), vi.end(), 
	[](const Item& a, const Item& b) {return a.iid < b.iid;});

print(vi.begin(), vi.end());
cout << endl;

sort(vi.begin(), vi.end(), 
	[](const Item& a, const Item& b) {return a.value > b.value;});

print(vi.begin(), vi.end());

Item it ={"horse shoe",99,12.34};
vi.push_back(it);
it ={"Canon S400", 9988,499.95};
vi.push_back(it);

print(vi.begin(), vi.end());
cout << endl;

string nam;
cout << "Please enter a name to delete" << endl;
cin >> nam;
int pos = findnm(vi.begin(), vi.end(), nam) - vi.begin();
vi.erase(vi.begin() + pos );

print(vi.begin(), vi.end());
cout << endl;

int id;
cout << "Please enter a name to delete" << endl;
cin >> id;
pos = findid(vi.begin(), vi.end(), id) - vi.begin();
vi.erase(vi.begin() + pos );

print(vi.begin(), vi.end());
cout << endl;

for(int i = 0; i < 10; i++)
{
	ist >> a.name;
	ist >> a.iid;
	ist >> a.value;
	lst.push_back(a);
}
ist.close();

print(lst.begin(), lst.end());


	return 0;
}