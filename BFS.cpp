#include<iostream>
#include<fstream>
#define MAX 50
int a[MAX][MAX];
bool ktXet[MAX];
int n;
using namespace std;
void docfile()
{
	ifstream FileIn;
	FileIn.open("input.txt", ios::in);
	FileIn >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			FileIn >> a[i][j];
		}
		ktXet[i] = true;
	}
	FileIn.close();
}
void BFS(int i)
{
	int queue[100], low = 1, high = 1;
	queue[low] = i; 
	ktXet[i] = false;
	while (low <= high) 
	{
		i = queue[low]; 
		low = low + 1;
		cout << i << "\t";
		for (int j = 1; j <= n; j++) 
		{
			if (a[i][j] == 1 && ktXet[j]) 
			{
				high = high + 1; 
				queue[high] = j;
				ktXet[j] = false;
			}
		}
	}
}
int main()
{
	docfile();
	BFS(1);
	cout << endl;
	system("pause");
	return 0;
}
