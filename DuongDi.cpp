#include <iostream>
#include<fstream>
#define MAX 50
using namespace std;
int A[MAX][MAX], n, truoc[MAX], s, t,tam[MAX];
bool chuaxet[MAX];
void docfile()
{
	ifstream FileIn;
	FileIn.open("input.txt", ios::in);
	FileIn >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			FileIn >> A[i][j];
		}
		chuaxet[i] = true;
	}
	FileIn.close();
}
void DFS(int u) 
{
	chuaxet[u] = false;
	for (int v = 1; v <= n; v++) 
	{
		if (A[u][v] && chuaxet[v]) 
		{
			truoc[v] = u; 
			DFS(v);
		}
	}
}
void BFS(int i) 
{
	int queue[MAX], low = 1, high = 1, u;
	queue[low] = i; 
	chuaxet[i] = false;
	while (low <= high) 
	{
		u = queue[low]; 
		low = low + 1;
		for (int v = 1; v <= n; v++) 
		{
			if (A[u][v] && chuaxet[v]) 
			{
				high = high + 1; 
				queue[high] = v;
				truoc[v] = u; 
				chuaxet[v] = false;
			}
		}
	}
}
void Duongdi() 
{
	int i = 1;
	if (truoc[t] == 0) 
	{
		cout << "Khong ton tai duong di\n";
		return;
	}
	cout << "Duong di:";
	int j = t; 
	while (truoc[j] != s) 
	{
		tam[i++] = truoc[j];
		j = truoc[j];
	}
	cout <<s<<"\t";
	for (int j = i-1; j >= 1; j--)
	{
		cout << tam[j] << "\t";
	}
	cout << t << endl;
}
int main() 
{
	docfile();
	cout << "Nhap dinh dau:";
	cin >> s;
	cout << "Nhap dinh cuoi:";
	cin >> t;
	//DFS(s);
	BFS(s);
	Duongdi();
	system("pause");
	return 0;
}
