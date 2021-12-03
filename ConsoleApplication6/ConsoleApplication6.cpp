#include<iostream>
#include <ctime>
#include <string>

using namespace std;
double getValueD()
{
	while (true)
	{
		cout << "Please input VALLUE";
		cout << '\n';
		double a;
		cin >> a;
		cout << '\n';

		if (cin.fail())
		{
			cin.clear(); // 
			cin.ignore(32767, '\n');
		}
		else return a;

	}

}
int getValue()
{
	while (true)
	{
		cout << '\n';
		int a;
		cin >> a;
		cout << '\n';

		if (cin.fail())
		{
			cin.clear(); // 
			cin.ignore(32767, '\n');
		}
		else return a;

	}

}
struct tovar
{
	int number_section;
	string name_object;
	double price;
	int vallue_object;
};
int add(tovar *store, int count,int count_2[])
{
	if (count_2[0]==0)
	{
		cout << "Please input vallue object in date?";
		cout << '\n';
		count = getValue();
		for (int i = 0; i < count; i++)
		{
			int schet = 1;
			cout << "Input number section" << endl;
			store[i].number_section = getValue();
			cout << "Input name object" << endl;
			cin >> store[i].name_object;
			cout << "Input price" << endl;
			store[i].price = getValueD();
			cout << "Input amount" << endl;
			store[i].vallue_object = getValue();
			for (int j = 0; j < schet; j++)
			{
				if ((store[j].name_object!= store[i].name_object)&&(store[j].price!=store[i].price))
				{
					count_2[1]++;
				}
			}
			schet++;
			system("cls");
		}
	}
	else 
	{
		cout << "Please input vallue object in date?";
		cout << '\n';
		count = getValue();
		count_2[1] = count_2[1] + count;
		for (int i = 0; i < count; i++)
		{
			string time_name;
			double time_price;
			cout << "Input name object" << endl;
			cin >>time_name;
			cout << "Input price" << endl;
			time_price=getValueD();
			for (int j = 0; j < count_2[1]; j++)
			{
				if ((store[j].name_object==time_name)&&(store[j].price==time_price))
				{
					store[j].vallue_object++;
					break;
				}
				else
				{
					store[count_2[1]+i+1].name_object = time_name;
					store[i].price = time_price;
					cout << "Input number section" << endl;
					store[i].number_section = getValue();
					cout << "Input amount" << endl;
					store[i].vallue_object = getValue();
				}
			}
			int schet = 1;
			for (int j = 0; j < schet; j++)
			{
				if ((store[j].name_object != store[i].name_object) && (store[j].price != store[i].price))
				{
					count_2[2]++;
				}
			}
			schet++;
			
			system("cls");
		}
	}
	count_2[0] = count_2[0] + 1;

	return count;

}
int main()
{
	int count = 100000;
	int count_2[2];
	count_2[0] = 0;
	count_2[1] = 0;
	count_2[2] = 0;
	tovar* store = new tovar[count];
	int solution = 0;
	while (solution != 5)
	{
		cout << "_____________________M.E.N.U_____________________" << endl;
		cout << '\n';
		cout << "Add new object :>>> 1" <<endl;
		cout << "Print base objects :>>> 2" << endl;
		cout << "Find objects for section :>>> 3" << endl;
		cout << "Find objects with vallue smaller then keep :>>> 4 " << endl;
		cout << "Exit with program :>>> 5" << endl;
		solution = getValue();
		switch (solution)
		{
		case 1:
			{
			add(store, count,count_2);
			break;
			}

		case 5:
				solution = 5;
				break;
		}


	}



}