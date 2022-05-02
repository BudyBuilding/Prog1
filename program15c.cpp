#include "std_lib_facilities.h"

struct Person
{
	
	Person(string namee = "Anonymous", string snamee = "Guy" , int agee = -1 ):
		fname{ namee }, sname {snamee}, age{ agee } {}

			string name1()
				{
					return fname;
				};

					string name2()
				{
					return sname;
				};

		
			int age1()
				{
					return age;
				};
		

	int age;
	string fname;
	string sname;
	
	};	

ostream& operator<<(ostream& os, Person p)
{
return os << p.name1() << '\t' << p.name2() << '\t' << p.age1();

}

istream& operator>>(istream& is, Person& p)
{
	string fprotname;
	string sprotname;
	int protage;

	cout << "Please enter the first name" << '\n';
cin >> fprotname;
	for(int i = 0; i < fprotname.size(); i++)
		{
			if (fprotname[i] == ';' || 
				fprotname[i] == ':' || 
				fprotname[i] == '"' || 
				fprotname[i] == '[' || 
				fprotname[i] == ']' || 
				fprotname[i] == '*' || 
				fprotname[i] == '&' ||
				fprotname[i] == '^' ||
				fprotname[i] == '%' || 
				fprotname[i] == '$' || 
				fprotname[i] == '#' || 
				fprotname[i] == '@' ||
				fprotname[i] == '!' || 
				fprotname[i] == '.'  )
				{
					error( "The first name contain bad characters!");
				}

		} 

	cout << "Please enter the second name" << '\n';
cin >> sprotname;
	for(int i = 0; i < sprotname.size(); i++)
		{
			if (sprotname[i] == ';' || 
				sprotname[i] == ':' || 
				sprotname[i] == '"' || 
				sprotname[i] == '[' || 
				sprotname[i] == ']' || 
				sprotname[i] == '*' || 
				sprotname[i] == '&' ||
				sprotname[i] == '^' ||
				sprotname[i] == '%' || 
				sprotname[i] == '$' || 
				sprotname[i] == '#' || 
				sprotname[i] == '@' ||
				sprotname[i] == '!' || 
				sprotname[i] == '.'  )
				{
					error( "The second name contain bad characters!");
				}

		} 

	cout << "Please enter an age" << '\n';
cin >> protage;
	if (protage < 0 || protage > 150)
		{
			error("Wrong age!");
		}
	p.fname = fprotname;
	p.sname = sprotname;	
	p.age = protage;	


return is;
}


int main()
{
	Person p;
	Person p1;
	cout << p << '\n';
	cout << p.name1() << '\t' << p.name2() << '\t' << p.age1() << '\n';


	vector <Person> vecpers;

	for (int i = 0; i < 2; i++)
	{
		cin >> p;
		vecpers.push_back(p);

	}

	for (int i = 0; i < 2; i++)
	{
		cout << vecpers[i] << '\n';
	}

return 0;
}
