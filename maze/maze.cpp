#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

#define infinite 2000

class Point {
public: 
	Point() {
		x = y = 0;
		Dist = infinite;	
		last = NULL;
	}
	void showPath(void) {
		Point *cur = this;	
		Point *next;
		char buf[4096];
		memset(buf, 0, sizeof(buf));
		int index = -1;
		while(cur->x!=0 || cur->y!=0) {
			next = cur->last;		
			if(next->x > cur->x)
				buf[++index] = 'L';
			else if(next->x < cur->x)
				buf[++index] = 'R';
			else if(next->y < cur->y)
				buf[++index] = 'D';
			else if(next->y > cur->y)
				buf[++index] = 'U';
			cur = next;
		}
		for(index; index>=0; index--)
			cout << buf[index];

/*
			cout << this->x << "," << this->y << " " << endl;
			cout << this->Dist << endl;

			Point *cur = this->last;

			cout << cur->x << "," << cur->y << " " << endl;
			cout << cur->Dist << endl;
*/

	}
	int x;
	int y;
	int Dist;
	Point *last;
};

#define row 30
#define col 50
class Graph {
public:
	Graph() {
		cout << "Grapph.. " << endl;
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				Map[i][j].x = j;	
				Map[i][j].y = i;	
			}	
		}	
	}			
	void showDist(void) {
		for(int i=0; i<row; i++) {	
			for(int j=0; j<col; j++)
				cout << Map[i][j].Dist << "\t";
			cout << endl;
		}		
	}

	Point Map[row][col];
};

class Queue {
public:
	Queue() {
		front = rear = 0;	
	}
	bool IsEmpty() {
		return rear == front;	
	}
	void Enqueue(Point p) {
		Q[rear++] = p;
	}
	Point& Dequeue(void) {
		return Q[front++];	
	}
	int giveIndex(void) {
		return rear;	
	}
 	Point Q[col*row*100];
	int front;
	int rear;
};



void BFS(Graph &G) {
	ifstream read("1.txt");	
	char Pass[row][col];
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			read >> Pass[i][j];		
	read.close();

	int Visted[row][col];
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			Visted[i][j] = 0;

	Queue q;			
	Point cur;
	cur.Dist = 0;
	G.Map[0][0] = cur;
	q.Enqueue(cur);	
	//cout << q.giveIndex() << endl;
	while(!q.IsEmpty()) {
		cur = q.Dequeue();		
	//	cout << q.giveIndex() << endl;
		Visted[cur.y][cur.x] = 1;
		if(cur.x<col-1 && Pass[cur.y][cur.x+1] == '*'
			&& !Visted[cur.y][cur.x+1]) {
			if(G.Map[cur.y][cur.x+1].Dist > cur.Dist+1) {
				G.Map[cur.y][cur.x+1].Dist = cur.Dist+1;		
				G.Map[cur.y][cur.x+1].last = &G.Map[cur.y][cur.x];
			}
			q.Enqueue(G.Map[cur.y][cur.x+1]);
		}
		if(cur.y<row-1 && Pass[cur.y+1][cur.x] == '*' 
			&& !Visted[cur.y+1][cur.x]) {
			if(G.Map[cur.y+1][cur.x].Dist > cur.Dist+1) {
				G.Map[cur.y+1][cur.x].Dist = cur.Dist+1;		
				G.Map[cur.y+1][cur.x].last = &G.Map[cur.y][cur.x];
			}
			q.Enqueue(G.Map[cur.y+1][cur.x]);
		}
		if(cur.x>0 && Pass[cur.y][cur.x-1] == '*'
			&& !Visted[cur.y][cur.x-1]) {
			if(G.Map[cur.y][cur.x-1].Dist > cur.Dist+1) {
				G.Map[cur.y][cur.x-1].Dist = cur.Dist+1;		
				G.Map[cur.y][cur.x-1].last = &G.Map[cur.y][cur.x];
			}
			q.Enqueue(G.Map[cur.y][cur.x-1]);
		}
		if(cur.y>0 && Pass[cur.y-1][cur.x] == '*'
			&& !Visted[cur.y-1][cur.x]) {
			if(G.Map[cur.y-1][cur.x].Dist > cur.Dist+1) {
				G.Map[cur.y-1][cur.x].Dist = cur.Dist+1;		
				G.Map[cur.y-1][cur.x].last = &G.Map[cur.y][cur.x];
			}
			q.Enqueue(G.Map[cur.y-1][cur.x]);
		}
	}
}

int main() {
	Graph g;
	BFS(g);
//	g.showDist();		
	g.Map[row-1][col-1].showPath();	
	
	cout << endl;
}

