#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check[15];

int gcd(int a, int b)
{
	int tmp;

	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int primeCount(int n)
{
	int cnt = 0;
	for (int i = 1; i * i <= n; i++)
	{
		if (i * i == n)
		{
			cnt++;
		}
		else if (n % i == 0)
		{
			cnt += 2;
		}
	}

	return cnt;
}

class Edge
{
public:
	int node[2];
	int distance;

	Edge(int node1, int node2)
	{
		this->node[0] = node1;
		this->node[1] = node2;
		this->distance = primeCount(lcm(node1, node2)) * gcd(node1, node2);
	}
};

int compare(Edge& a, Edge& b)
{
	return a.distance > b.distance;
}

int getParent(int node)
{
	if (check[node] == node) return node;
	return getParent(check[node]);
}

void unionParent(int node1, int node2)
{
	node1 = getParent(node1);
	node2 = getParent(node2);
	if (check[node1] > check[node2]) check[node2] = node1;
	else check[node1] = node2;
}

bool isCycle(int node1, int node2)
{
	node1 = getParent(node1);
	node2 = getParent(node2);
	return node1 == node2;
}

char change(int n)
{
	int arr[] = { 8, 9, 4, 12, 15, 10, 6 };
	char c;
	for (int i = 0; i < 7; i++)
	{
		if (n == arr[i])
		{
			c = i + 'A';
			break;
		}
	}
	return c;
}

int main()
{
	vector<Edge> v;
	int A = 8, B = 9, C = 4, D = 12, E = 15, F = 10, G = 6;
	//int A = 6, B = 12, C = 5, D = 7, E = 4, F = 8, G = 15;
	int sum = 0;

	v.push_back(Edge(A, B));
	v.push_back(Edge(A, C));
	v.push_back(Edge(A, D));
	v.push_back(Edge(B, D));
	v.push_back(Edge(B, G));
	v.push_back(Edge(C, E));
	v.push_back(Edge(C, F));
	v.push_back(Edge(D, E));
	v.push_back(Edge(E, F));
	v.push_back(Edge(E, G));
	v.push_back(Edge(F, G));

	for (int i = 0; i <= 12; i++)
	{
		check[i] = i;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		//cout << v[i].distance << "->";
		if (!isCycle(v[i].node[0], v[i].node[1]))
		{
			sum += v[i].distance;
			printf("도로(%c, %c)의 산업가치   %d\t선택\n", change(v[i].node[0]), change(v[i].node[1]), v[i].distance);
			unionParent(v[i].node[0], v[i].node[1]);
		}
	}
	cout << "도로의  산업가치의 합  " << sum;
}