#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class air_data
{
public:
	int value;
	int order_info;
	string plus_info;
};
air_data distance_info[120];

//class air_distance
//{
//public:
//	int value;
//	int count;
//	string info;
//};
//
//air_distance one_distance[15];
//air_distance two_distance[25];

const char * filename = "data.txt";
//vector<int> g_data;

void dataprocess();
void one_distance_calculate();
void two_distance_calculate();

int main()
{
	dataprocess();
	one_distance_calculate();
	two_distance_calculate();

	int test_count = 0;
	for (int i = 0; i < 40; i++)
	{
		/*if (distance_info[i].order_info == 1)
		{
		cout << "V1 :" << distance_info[i].value << endl;
		test_count++;
		}*/

		if (distance_info[i].order_info == 2)
		{
			cout << "V2 :" << distance_info[i].value << " " << distance_info[i].plus_info << endl;
			test_count++;
		}


	}

	cout << endl << "Total: " << test_count << endl;

	system("pause");
	return 0;
}

void dataprocess()
{
	ifstream in(filename);
	int temp = 0;
	for (int i = 0; i < 120; i++)
	{
		in >> temp;
		distance_info[i].value = temp;
	}
}

void one_distance_calculate()
{
	distance_info[0].order_info = 1;
	distance_info[1].order_info = 1;

	int count = 2;
	int num = 2;

	while (count < 15)
	{
		bool flag = 0;
		for (int i = 0; (i < num - 1) && !flag; i++)
		{
			for (int j = i + 1; (j < num) && !flag; j++)
			{
				if (distance_info[num].value == distance_info[i].value + distance_info[j].value)
				{
					flag = 1;
				}
			}
		}
		if (flag == 0)
		{
			distance_info[num].order_info = 1;
			distance_info[num].order_info = 1;
			count++;
		}
		num++;
	}
}

void two_distance_calculate()
{
	int count = 0;
	while (count < 40)
	{
		for (int i = 0; i < (count - 1); i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (distance_info[count].value == distance_info[i].value + distance_info[j].value)
					if (distance_info[i].order_info == 1 && distance_info[j].order_info == 1)
					{
						distance_info[count].order_info = 2;
						distance_info[count].plus_info += to_string(i + 1) + ";" + to_string(j + 1) + "  ";
					}
			}
		}
		count++;
	}
}
