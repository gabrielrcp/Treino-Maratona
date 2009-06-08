#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	int n,num;

	while(1)
	{
		scanf(" %d",&n);
		if (n == 0)
		       	break;
		vector< pair<int,int>  > v(n+1);
		for(int i=1; i<=n; i++)
		{
			scanf(" %d", &num);
			v.push_back (make_pair(num,i));
		}
		sort(v.begin()+1,v.end());

		vector<int> pos(n+1,0);
		for(int i=1; i<=n; i++)
		{
			   pos[i] = v[i].second;
			   for(int j=1; j<i; j++)
			   {
				   if (pos[i] < pos[j])
					   pos[i] = pos[j] - pos[i] + 1; 
			   }
		}
		for(int i=1; i<n;i++)
			printf("%d ",pos[i]);
		printf("%d\n",pos[n]);
	}
	return 0;
}
