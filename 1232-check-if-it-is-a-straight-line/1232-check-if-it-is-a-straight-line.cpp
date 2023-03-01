class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];
        if(x1!=x2){
        float m = ((float)y1-(float)y2)/((float)x1-(float)x2);
        float c=((float)x2*(float)y1-(float)x1*(float)y2)/((float)x2-(float)x1);

        for(int i=0;i<coordinates.size();i++){
            int x=coordinates[i][0];
            int y=coordinates[i][1];
            // cout<<m<<x<<y<<endl;
            // cout<<y-m*x-c<<endl;
            if(y-m*x-c!=0) return false;
            }

        }
        else {
            for(int i=0;i<coordinates.size();i++){
                if(coordinates[i][0]!=x1) return false;
            }

        }
        return true;
    }
};