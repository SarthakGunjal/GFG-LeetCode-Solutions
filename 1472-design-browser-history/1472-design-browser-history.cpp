class BrowserHistory {
public:

    stack<string> curr;
    stack<string> next;

    BrowserHistory(string homepage) {
        curr.push(homepage);
    }
    
    void visit(string url) {
       while(!next.empty()){
            next.pop();
        }

        curr.push(url); 
    }
    
    string back(int steps) {
        string res = "";
        while(steps-- && curr.size() > 1){
            next.push(curr.top());
            curr.pop();
        }

        res = curr.top();
        return res;
    }
    
    string forward(int steps) {
        string res = "";
        while(steps-- && !next.empty()){
            curr.push(next.top());
            next.pop();
        }

        res = curr.top();
        return res;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */