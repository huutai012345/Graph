#include <iostream>
#include <fstream>
#define MAX 50
using namespace std;
int A[MAX][MAX], n, solt = 0;
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
void reset()
{
	for (int i = 1; i <= n; i++)
	{
		chuaxet[i] = true;
	}
}
void BFS(int u) 
{
	int queue[MAX], low = 1, high = 1, s;
	queue[low] = u; 
	chuaxet[u] = false;
	while (low <= high) 
	{
		s = queue[low]; 
		low = low + 1;
		for (int t = 1; t <= n; t++) 
		{
			if (A[s][t] && chuaxet[t]) 
			{
				high = high + 1;
				queue[high] = t;
				chuaxet[t] = false;
			}
		}
	}
}
void DFS(int u) 
{
	chuaxet[u] = false;
	for (int v = 1; v <= n; v++) 
	{
		if (A[u][v] && chuaxet[v])
		{
			DFS(v);
		}
	}
}

int Test_So_Lien_Thong() 
{
	for (int u = 1; u <= n; u++)
	{
		if (chuaxet[u])
		{
			return 1;
		}
	}
	return 0;
}

int Strong_Conective() 
{
	docfile();
	for (int u = 1; u <= n; u++) 
	{
		chuaxet[u] = false;
		DFS(u);
		if (Test_So_Lien_Thong())
		{
			return 0;
		}
		reset();
	}
	return 1;
}
int main() 
{
	if (Strong_Conective())
	{
		cout << "Do thi lien thong manh\n";
	}
	else
		cout<<"Do thi khong lien thong manh\n";
	system("pause");
	return 0;
}
