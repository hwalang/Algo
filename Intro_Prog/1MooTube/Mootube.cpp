#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, Q;
vector<pair<int, int>> rel[5001];	// start -> (dist, end), ...

void Input()
{
	cin >> N >> Q;
	// N - 1�� !!
	for (int i = 0; i < N - 1; ++i)
	{
		int p, q, r;
		cin >> p >> q >> r;
		rel[p].push_back({ r, q });	// ���� �����Ѵٸ�, ù ��° ���Ҹ� �������� �����Ѵ�.
		rel[q].push_back({ r, p });
	}
}

int BFS(int start, int k)
{
	int ret = 0;
	bool visited[5001];
	queue<int> queue;

	memset(visited, 0, sizeof(visited));	// fill(0)

	queue.push(start);
	visited[start] = true;
	
	while (!queue.empty())
	{
		int cur = queue.front();
		queue.pop();

		int size = rel[cur].size();
		for (int i = 0; i < size; ++i)
		{
			int next = rel[cur][i].second;		// cur�� ������ ����� ��ȣ�� �����´�.
			int next_dist = rel[cur][i].first;	// cur�� ���� ����� �Ÿ��� �����´�.
			if (visited[next] == true || next_dist < k) continue;

			queue.push(next);
			visited[next] = true;
			ret++;		// k �̻��� ��带 ã��
		}
	}

	return ret;
}

void Solve()
{
	// ������ ���� ������ ��õ�Ѵ�.
	for (int i = 0; i < Q; ++i)
	{
		int k, v;
		cin >> k >> v;

		cout << BFS(v, k) << "\n";
	}
}


int main()
{
	Input();
	Solve();
}