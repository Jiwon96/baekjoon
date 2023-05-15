#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define NUMOFNODES 200000

using namespace std;

class Node {
public:
	int node1;
	int node2;
	int dist;

	Node(int x, int y, int d) {
		this->node1 = x;
		this->node2 = y;
		this->dist = d;
	}

	bool operator<(Node& node) {
		return ((this->dist) < (node.dist));
	}
};



struct comp {
	bool operator() (Node& x, Node& y) {
		return x.dist > y.dist;
	}
};

int parent[NUMOFNODES] = { 0 };


int find(int x) {
	if (parent[x] == x) return x;
	else {
		int parentx = find(parent[x]);
		parent[x] = parentx; // root change
		return parentx;
	}
}

void merge(int x, int y) {
	int parentx = find(x);
	int parenty = find(y);
	if (parentx == parenty) return;
	parent[parenty] = parentx;
}

bool isGraph(int x, int y) {
	int parentx = find(x);
	int parenty = find(y);
	if (parentx == parenty) return true;
	else return false;
}


int m, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	while (!(m == 0 && n == 0)) {
		
		//init;
		int retsum = 0; //총 그래프 합
		int dist_sum = 0; //MST dist 합
		priority_queue<Node, vector<Node>, comp> pq; // init
		int edgesum = 0; 

		for (int i = 0; i < m; i++)
			parent[i] = i;

		//input
		for (int i = 0; i < n; i++) {
			int num1, num2, dist;
			cin >> num1 >> num2 >> dist;
			pq.push(Node(num1, num2, dist));
			retsum += dist;
		}
		/*
		while (!pq.empty()) {
			cout << pq.top().node1  << " " << pq.top().node2 << "\n";
			pq.pop();
		}
		*/
		
		while (edgesum != (m - 1)) {
			Node n1 = pq.top();
			pq.pop();
			
			if (!isGraph(n1.node1, n1.node2)) {
				dist_sum += n1.dist;
				//cout << dist_sum <<" ";
				merge(n1.node1, n1.node2);
				edgesum++;
			}

		}
		
		cout << retsum - dist_sum << "\n";
		cin >> m >> n;
	}

	return 0;
}