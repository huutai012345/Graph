#include<iostream>
#include<fstream>
using namespace std;
int a[100][100];
bool ktXet[100];
int n;
void docfile()
{
	ifstream FileIn;
	FileIn.open("input.txt",ios::in);
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
void xuat()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
void DFS_DeQui(int i)
{
	cout << i << "\t";
	ktXet[i] = false;
	for (int j = 1; j <= n; j++)
	{
		if (ktXet[j] && a[i][j] == 1)
		{
			DFS_DeQui(j);
		}
	}
}
void DFS_KhuDeQui(int i)
{
	int Stack[100], dau = 1, s;
	Stack[dau] = i;
	ktXet[i] = false;
	cout << i << "\t";
	while (dau > 0)
	{
		s = Stack[dau--];
		for (int j = 1; j <= n; j++)
		{
			if (ktXet[j] && a[s][j])
			{
				cout << j << "\t";
				ktXet[j] = false;
				Stack[++dau] = s;
				Stack[++dau] = j;
				break;
			}
		}
	}
}
int main()
{
	docfile();
	//DFS_DeQui(1);
	DFS_KhuDeQui(1);
	cout << endl;
	system("pause");
	return 0;
}
