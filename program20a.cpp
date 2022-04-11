#include "std_lib_facilities.h"


int* fill_array(int* a)
{
	int* arr1 = new int[*a];
	for (int i = 0; i < *a; i++)
		arr1[i] = i;
	 
	return arr1;
};

vector<int>* fill_vec(int* a)
{
	vector<int>* vec = new vector<int>;
	for(int i = 0; i < *a; i++)
		(*vec).push_back(i); 

	return vec;
};

template<typename Iterator>
Iterator& operator++(Iterator& p){ return p + 1;}


template<typename Iterator>
void print(Iterator first, Iterator last)
 	{
 		for(Iterator p = first; p!= last; p++)
 			cout << *p << '\t'; 
 		cout << endl;

 	}

template<typename Iterator>
void copy(Iterator first1, Iterator last1,
		Iterator first2)
 	{
 		Iterator p2 = first2;
 		for(Iterator p1 = first1; p1!= last1; p1++)
 		{	*p2 = *p1;
 			p2++;
 		}


 	}

template<typename Iterator>
void inc(Iterator first, Iterator last, int a)
 	{
 		for(Iterator pr = first; pr!= last; pr++)
 			*pr = *pr + a;
 	}

template<typename Iterator>
Iterator find(Iterator first, Iterator last, int a)
 	{
 		Iterator b = last;
 		for(Iterator p = first; p!= last; p++)
 			if (*p == a)
 				b = p;
 			return b;
 	}


template<typename Iterator>
int find(Iterator first, Iterator last, int a)
 	{
 		int b = last - first;
 		int i = 0;
 		for(Iterator p = first; p!= last; p++)
 		{	if (*p == a)
 				b = i;
 			i++;
 		};
 			return b;
 	}

template<typename C>
struct Link
{
	Link(const C& v = C(), Link* p = 0,Link* s = 0)
	:prev(p), succ(s), val(v) {}

		Link* prev;
		Link* succ;
		C val;
	
};

template<typename C>
class lst
{
public:
	lst(): first(new Link<C>()), 
	last(first) {}
	
	class iterator;

	iterator begin() {return iterator(first);}
	iterator end() {return iterator(last);}



	iterator insert(iterator p, const C& v);
	iterator erase(iterator p);

	void printt();
	
	void push_back(const C& val);
	void push_front(const C& val);

	C* front() {return *first;}
	C* back() {return *last;}

	Link<C>* first;
	Link<C>* last;

};

template<typename C>
class lst<C>::iterator {

	Link<C>* curr;

public: 
	iterator(Link<C>* p):curr{p} {}
	iterator& operator++() {curr = curr->succ; return *this;}
	iterator& operator--() {curr = curr->prev; return *this;}
	C operator*() { return curr->val;}

	bool operator==(const iterator& b) const 
		{return curr==b.curr;}
	bool operator!=(const iterator& b) const 
		{return curr!=b.curr;}




};

template<typename C>
void lst<C>::push_front(const C& v)
{
	first = new Link<C>(v, 0, first);

}





int main(){
	lst<int> ls;
	int length = 5;

	lst<int>::iterator d = ls.begin();
	lst<int>::iterator k = ls.end();
 
	for (int i = 0; cin >> i;)
		ls.push_front(i);
	print(d,k);


 	int main(){
	

	
	int* aray = fill_array(&length);
	vector<int>* vec = fill_vec(&length);
	
	print(aray, aray + length);
	inc(&(*vec)[0], &(*vec)[0] + (*vec).size(), 5);
	print(&(*vec)[0], &(*vec)[0] + (*vec).size());
	copy(aray, aray + length, &(*vec)[0]);
	print(&(*vec)[0], &(*vec)[0] + (*vec).size());
	
	int a = find(aray, aray + length, 3);
	cout << a << endl;



	cout << "before inc" << endl;
	print(aray, aray + length);
	inc(aray, aray + length, 2);
	cout << "after inc" << endl;
	print(aray, aray + length);
	
		
	cout << &length << endl; 
	vector<int>* vec = fill_vec(&length);
	vector<int>* vec1 = vec;
	int* aray1 = aray;



	cout << "before inc" << endl;
	print(&(*vec)[0], &(*vec)[0] + (*vec).size());
	inc(&(*vec)[0], &(*vec)[0] + (*vec).size(), 5);
	cout << "after inc" << endl;
	print(&(*vec)[0], &(*vec)[0] + (*vec).size());	



	print(aray, aray + length);
	print(&(*vec)[0], &(*vec)[0] + (*vec).size() );

delete vec;
delete aray;
	return 0;
}