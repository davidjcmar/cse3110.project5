#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#define X 25
#define Y 25
using namespace std;
class location
{
public:
	int id;
	int distance;
	location(int,int);
};
location::location(int new_id, int new_dist)
{
	id=new_id;
	distance=new_dist;
}

int BFS (int map[][Y], queue<int>&, int);

int main (void)
{
	cout<<"Hello World "<<X<<" "<<Y<<endl;
	int map[X][Y];
	queue<int> que;

	for (int i=0;i<Y;i++)
		for (int j=0;j<X;j++)
		{
			int buffer;
			cin>>buffer;
			map[i][j]=buffer;
		}
BFS(map,que,1);

	return 0;
}

int BFS (int map[][Y], queue<int> &que, int position)
{
	for (int i=0;i<Y;i++)
{
	for (int j=0;j<X;j++)
	{
		cout<<map[i][j]<<"\t";
	}
	cout<<endl;
}
	return 0
;}