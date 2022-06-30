const int MAX = 2005;
const int inf = 2147483647;
const int SOURCE = 1;
const int SINK = 2;

int c[MAX][MAX];
int f[MAX][MAX];
vector<int> adj[MAX];

int maximumFlow(int source, int sink) {
	int ret = 0;

	while (true) {
		int parent[MAX] = {};
		queue<int> q;
		q.push(source);
		parent[source] = source;

		while (!q.empty() && !parent[sink]) {
			int curr = q.front();
			q.pop();

			for (int i = 0; i < adj[curr].size(); i++) {
				int next = adj[curr][i];

				if (c[curr][next] - f[curr][next] > 0 and !parent[next]) {
					q.push(next);
					parent[next] = curr;
				}
			}
		}

		if (!parent[sink])
			break;

		int flow = inf;
		for (int i = sink; i != source; i = parent[i])
			flow = min(flow, c[parent[i]][i] - f[parent[i]][i]);

		for (int i = sink; i != source; i = parent[i]) {
			f[parent[i]][i] += flow;
			f[i][parent[i]] -= flow;
		}

		ret += flow;
	}

	return ret;
}
