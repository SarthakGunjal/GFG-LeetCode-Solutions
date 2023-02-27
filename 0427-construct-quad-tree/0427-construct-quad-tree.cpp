/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:


    Node* recurse(vector<vector<int>>& preSum, int r1, int r2, int c1, int c2) {
        int sum = preSum[r2+1][c2+1] + preSum[r1][c1] - preSum[r1][c2+1] - preSum[r2+1][c1];

        if (sum == 0 || sum == (r2 - r1 + 1) * (c2 - c1 + 1)) {
            bool val = sum != 0;
            return new Node(val, true);
        }
        Node* node = new Node(false, false);

        int rm = r1 + (r2 - r1) / 2, cm = c1 + (c2 - c1) / 2;

        node->topLeft = recurse(preSum, r1, rm, c1, cm);
        node->topRight = recurse(preSum, r1, rm, cm+1, c2);
        node->bottomLeft = recurse(preSum, rm+1, r2, c1, cm);
        node->bottomRight = recurse(preSum, rm+1, r2, cm+1, c2);

        return node;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> preSum(n+1, vector<int>(n+1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                preSum[i][j] = preSum[i][j-1] + preSum[i-1][j] + grid[i-1][j-1] - preSum[i-1][j-1];
            }
        }

        return recurse(preSum, 0, n-1, 0, n-1);

    }
};