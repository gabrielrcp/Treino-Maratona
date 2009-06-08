#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	int n,num;
	int ultpos;

	while(1)
	{
		scanf(" %d",&n);
		if (n == 0)
		       	break;
		vector< pair<int,int>  > v;
		for(int i=0; i<n; i++)
		{
			scanf(" %d", &num);
			v.push_back (make_pair(num,i+1));
		}
		sort(v.begin(),v.end());

		vector<int> pos(n,0);
		pos[0] = v[0].second;
		for (int i=1; i<n; i++)
		{
				pos[i] = v[i].second;
		 		ultpos = -1;
		 		for(int j=0; j<i; j++)
		 		{
		 				if(pos[j] == ultpos)
		 				{
		 						ultpos = -1;
		 				}
		 				else if (pos[i] < pos[j])
		 				{
		 						pos[i] = pos[j] - pos[i] + j + 1; 
		 						ultpos = pos[j];
		 				}
		 		}
		}
		for(int i=0; i<n-1;i++)
				printf("%d ",pos[i]);
		printf("%d\n",pos[n-1]);
	}
	return 0;
}
