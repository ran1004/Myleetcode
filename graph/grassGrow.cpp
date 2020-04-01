#include<iostream>

using namespace std;

const int row = 10;
const int col = 10;
char Map[row][col]; 
int delta[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

class node {
public:
	node(int a, int b) {
		x = a, y = b;		
	}
	node() {};
	int x;
	int y;
	int gen;
};

class queue {
public:
	queue() {
		rear = front = 0;	
	}	
	void EnQueue(node n) {
		arr[rear++] = n;	
	}
	node DeQueue(void) {
		return arr[front++];	
	} 
	int IsEmpty(void) {
		return front == rear;	
	}
	node arr[col*row];	
	int front;
	int rear;
};

int main() {
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			Map[i][j] = '-';
		const int N = 7;
		int a, b;
		a = 4;
		b = 4;
		node cur(a, b);
		cur.gen = 0;
		int vis[row][col];
		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++)
				vis[i][j] = 0;
		vis[b][a] = 1;
		queue q;
		q.EnQueue(cur);
		while(!q.IsEmpty()) {
			cur = q.DeQueue();
			if(cur.gen >= N)
				break;
			Map[cur.y][cur.x] = '*';
			for(int k=0; k<4; k++) {
				int x = cur.x + delta[k][1];	
				int y = cur.y + delta[k][0];
				if(x<0 || y<0 || x>=col || y>=row
				    || vis[y][x])
						continue;
				//cout << x << "," << y << endl;
				node p(x, y);
				p.gen = cur.gen+1;
				vis[y][x] = 1;
				q.EnQueue(p);
			}
		}
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++)	
			cout << Map[i][j];
		cout << endl;
	}
}
