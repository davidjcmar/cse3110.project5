#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#define X 25

using namespace std;

int BFS (int map[][X],bool visit[],queue<int>&,int);
int DFS (int map[][X],bool visit[],stack<int>&);
int main (void)
{
//	cout<<"Hello World "<<X<<" "<<X<<endl;
	int map[X][X]; // edges
	bool visit[X]; // visited vertices
	queue<int> que;
	stack<int> stak;
	/* load map */
	for (int i=0;i<X;i++)
	{
		for (int j=0;j<X;j++)
		{
			int buffer;
			cin>>buffer;
			map[i][j]=buffer;

		}
		visit[i]=false; // init visit array
	}
/* bfs call */
cout<<"BFS: ";
que.push(0); // enqueueueueue first vertex
visit[0]=true; // set visit value
BFS(map,visit,que,0); // BFS call
/* dfs call */
/* reset visit array */
for (int i=0;i<X;i++)
	visit[i]=false;
stak.push(0); // push first vertex to stack
visit[0]=true; // set visit value
cout<<endl<<"DFS: ";
//cout.flush(); // debugging
DFS(map,visit,stak); // DFS call
cout<<endl;
	return 0;
}
/* breadth first search */
int BFS (int map[][X], bool visit[], queue<int> &que, int position)
{
	/* if finished */
	if (que.empty())
		return 0;
	/* not finished */
	else
	{
		for (int j=0;j<X;j++)
		{
			/* if there is an edge */
			if (map[position][j]!=0)
			{
				/* and it hasn't been noted already */
				if (!visit[j])
				{
					que.push(j); // push that business on the stack
					visit[j]=true; // and mark it visited
				}
			}
		}
		int temp=que.front(); // get front value
		cout<<(que.front()+1)<<" "; // and print it
		/* jk, we finished */
		if ((que.front()+1)==X)
		{
			/* empty queue */
			while (que.empty()!=true) 
				que.pop();
		}
		else
		{
			que.pop(); // dequeueueueue front element
		}
			BFS(map,visit,que,temp); // recursion!
	}
/*	testing */
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
/* depth first search */
int DFS (int map[][X],bool visit[],stack<int> &stak)
{
//	cout.flush(); // debugging
	/* we done */
	if (stak.empty()==true)
		return 0;
	/* we not done */
	else
	{
		int temp=stak.top(); // get top value
		cout<<(stak.top()+1)<<" "; // print that ish out
		/* jk, actually done */
		if ((stak.top()+1)==X)
		{	
			/* empty stack */
			while (stak.empty()!=true)
				stak.pop();
			visit[X]=true;
			DFS(map,visit,stak);
		}	
		/* for real not done */
		else
		{
			stak.pop(); // pop top element
			/* put chillens on the stack */
			for (int j=(X-1);j>=0;j--)
			{
				if (map[temp][j]!=0) // if there's an edge
					if (!visit[j]) // and it hasn't been noted
					{
						stak.push(j); // put that ish on the stack
						visit[j]=true; // and mark it visited
					}
			}
			DFS(map,visit,stak); // GD recursion yay!!!!
		} 
	}	
	return 0;
}