#include "std_lib_facilities.h"


template<typename T> 
struct S {
	S(): val{0}
	{ };
	S(T aa): val{aa}
	{ };

T& get() {return val;};
T& get() const {return val;};

void set(T p) {val = p;};



T& operator=(const T& p)
{
return p.get();
};	

	private:
		T val;
		
};




int main(){

	
	S<int> a = {5} ;
	S<int> x = {5} ;
	S<double> b = {0.1} ;
	S<char> c = {'c'};
	S<string> d = {"Johhny"};
	cout << "a.val" << '\n';		
	cin >> a.val ;	
	cout << "b.val" << '\n';		
	cin >> b.val ;	
	cout << "c.val" << '\n';		
	cin >> c.val ;	
	cout << "d.val" << '\n';		
	cin >> d.val ;	
		
	cout << a.get() << '\n';
	cout << b.get() << '\n';
	cout << c.get() << '\n';
	cout << d.get() << '\n';
	a.set(7);
	cout << a.get() << '\n';
	b.set(7.1);
	cout << b.get() << '\n';	
	c.set('d');
	cout << c.get() << '\n';
	d.set("Stalker");
	cout << d.get() << '\n';

	a = x;
	cout << get(a) << '\n';
	cout << a.get() << '\n';
	a.read_val();
	cout << a.get() << '\n';

	cout << b.get() << '\n';
	b.read_val();
	cout << b.get() << '\n';

	cout << c.get() << '\n';
	c.read_val();
	cout << c.get() << '\n';

	cout << d.get() << '\n';
	d.read_val();
	cout << d.get() << '\n';



	return 0;
}