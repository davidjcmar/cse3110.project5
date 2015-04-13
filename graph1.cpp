#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#define X 25

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

int BFS (int map[][X],bool visit[], queue<int>&, int);

int main (void)
{
//	cout<<"Hello World "<<X<<" "<<X<<endl;
	int map[X][X];
	bool visit[X];
	queue<int> que;

	for (int i=0;i<X;i++)
	{
		for (int j=0;j<X;j++)
		{
			int buffer;
			cin>>buffer;
			map[i][j]=buffer;

		}
		visit[i]=false;
	}
/* bfs call */
cout<<"BFS: ";
que.push(0);
visit[0]=true;
BFS(map,visit,que,0);
/* dfs call */
for (int i=0;i<X;i++)
	visit[i]=false;
cout<<endl<<"DFS: ";
	return 0;
}

int BFS (int map[][X], bool visit[], queue<int> &que, int position)
{
	string temp0;
	cin>>temp0;
	if (que.empty())
		return 0;
	else
	{
		for (int j=0;j<X;j++)
		{
			if (map[position][j]!=0)
			{
				if (!visit[j])
				{
					que.push(j);
					visit[j]=true;
				}
			}
		}
		int temp=que.front();
		cout<<(que.front()+1)<<" ";
		if ((que.front()+1)==X)
		{
			cout<<"heyo";
			while (que.empty()!=true)
				que.pop();
		}
		else
		{
			que.pop();
		}
			BFS(map,visit,que,temp);
	}
/*	for (int i=0;i<X;i++)
	{
		for (int j=0;j<X;j++)
		{
			cout<<map[i][j]<<"\t";
		}
		cout<<endl;
	}
*/
	return 0
;}