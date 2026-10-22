class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = (int)flowerbed.size();
	bool allZero = true;
	int cnt =0;
	for(int i =0; i<sz ; i++)
	{
		if(flowerbed[i] == 1) {allZero=false; break;}
		cnt++;
	}

	if(allZero) return ((cnt+1)/2) >= n;
	int ans =0;
    int cnt1=0;
	int i =0; int j = sz-1;
	while(i<sz && flowerbed[i]==0) 
	{
		cnt1++;
		i++;
}	
ans += cnt1/2;
cnt1=0;
while(j>=0 && flowerbed[j]==0) 
	{
		cnt1++;
		j-=1;
}
ans += cnt1/2;

vector<int> idx;
for(int k =i; k<=j ; k++)
{
	if(flowerbed[k] == 1) idx.push_back(k);
}

for(int i =0; i<idx.size()-1; i++)
{
	int diff = idx[i+1] - idx[i] -1;
	if(diff%2==0) 
	{
		ans+= (diff-1)/2;
	}
	else
	{
		ans += diff/2;
	}
}

if(ans>=n) return true;
else return false;

    }
};