#include "std_lib_facilities.h"

template<typename Iterator>
Iterator& operator++(Iterator& p){ return p + 1;}

template<typename Iterator>
void print(Iterator first, Iterator last)
 	{
 		for(Iterator p = first; p!= last; p++)
 			cout << *p << '\n'; 
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



bool low(const double& a, const double& b)
	{return a<b;}


 template<typename Iterator, typename C>
C suma(Iterator first, Iterator last, const C sm)
 	{
 		C a = sm;
 		Iterator p = first;
 		while (p != last)
 		{
 			a = a + *p;
 			p++;
 		}

 		return a;
 	}

template<typename Iterator>
 	double avg(Iterator first, Iterator last)
 		{
 			double sm = 0.0;
 			sm = suma(first, last, 0.0);

 			return sm/(last - first);
 		}

template<typename Iterator, typename BinOP, typename C>
C copy(Iterator first, Iterator last,
		Iterator first2, C va, BinOP pred)
 	{

 		Iterator p = first;
 		Iterator p1 = first2;
 		double avg1 = avg(first, last);
 		while (p !=last)
 		{
 			if (pred(*p, avg1))
 			{
 				(va).push_back(*p);
 			}
 			p++;
 			p1++;
 		}
return va;
 	}



int main(){
vector <double> vd = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8,
		9.9, 10.10, 11.11, 12.12, 13.13, 14.14, 15.15, 16.16};

print(vd.begin(), vd.end());

vector <int> vi(16);

copy(vd.begin(), vd.end(), vi.begin());
print(vi.begin(), vi.end());

for (int i = 0; i < 16; i++)
{
	cout << '(' << vd[i] << ' ' << vi[i] << ')' << endl;

}

double summ = suma(vd.begin(), vd.end(), 0.0);
cout << summ << endl;

int summ1 = suma(vi.begin(), vi.end(), 0);
cout << summ1 << endl;
cout << summ - summ1 << endl;


print(vd.begin(), vd.end());
reverse(vd.begin(), vd.end());
print(vd.begin(), vd.end());

double av = avg(vd.begin(), vd.end());
cout << av << endl;

vector<double> vd2;
vd2 = copy(vd.begin(), vd.end(), vd2.begin(),vd2,  low);

print(vd2.begin(), vd2.end());
sort(vd2.begin(), vd2.end());
print(vd2.begin(), vd2.end());


return 0;
}