#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream read("maze.txt");
	ofstream write("1.txt");
	char temp[4096] = {0};
	int cur = -1;
	/*
	while(!read.eof()) {
		read >> temp[++cur];		
		temp[cur] = temp[cur]=='0'? '*' : '-';
		write << temp[cur];
		if((cur+1)%50 == 0)
			write << '\n';
	}
	*/

	char ch;
	while(1) {
		read >> ch;	
		if(!read.good())
			break;
		temp[++cur]	= ch;
		write << temp[cur];
		if((cur+1)%50 == 0)
			write << '\n';
	}

	read.close();
	write.close();	
		
 	return 0;
}
