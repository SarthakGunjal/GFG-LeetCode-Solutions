class Solution {
public:
    string interpret(string cmd) 
    {
        string ans = "";
        for(int i = 0; i < cmd.size(); i++)
        {
            if(cmd[i]=='(' && cmd[i+1]==')')
            {
                ans += 'o';
                i++;
            }
            else if(cmd[i]=='(' && cmd[i+1]=='a')
            {
                ans += "al";
                i = i+3;
            }
            else
            {
                ans += cmd[i];
            }
        }    
        return ans;
    }
};