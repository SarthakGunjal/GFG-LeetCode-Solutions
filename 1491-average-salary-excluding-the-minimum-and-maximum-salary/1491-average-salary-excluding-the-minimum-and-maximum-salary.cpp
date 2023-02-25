class Solution {
public:
    double average(vector<int>& salary) {
        
int count=0;
double sum=0;
int maxi=INT_MIN,mini=INT_MAX;
for(int i=0;i<salary.size();i++){
maxi=max(maxi,salary[i]);
mini=min(mini,salary[i]);
}
for(int i=0;i<salary.size();i++){
if(salary[i]==maxi || salary[i]==mini)
continue;
else{
sum=sum+salary[i];
count++;
}
}
double ans=sum/count;
return ans;

    }
};