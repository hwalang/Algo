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
	// N - 1개 !!
	for (int i = 0; i < N - 1; ++i)
	{
		int p, q, r;
		cin >> p >> q >> r;
		rel[p].push_back({ r, q });	// 만약 정렬한다면, 첫 번째 원소를 기준으로 정렬한다.
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
			int next = rel[cur][i].second;		// cur과 인접한 노드의 번호를 가져온다.
			int next_dist = rel[cur][i].first;	// cur과 인접 노드이 거리를 가져온다.
			if (visited[next] == true || next_dist < k) continue;

			queue.push(next);
			visited[next] = true;
			ret++;		// k 이상인 노드를 찾음
		}
	}

	return ret;
}

void Solve()
{
	// 질문에 따라 영상을 추천한다.
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