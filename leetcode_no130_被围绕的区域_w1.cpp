/* ------------------------------------------------------------------|
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	种子填充法/迭代法
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：9.7 MB, 在所有 C++ 提交中击败了99.88%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


void solve(vector<vector<char>>& board) {
    if (!board.size() || !board[0].size()) {
        return;
    }
    queue<pair<int, int>> q;
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < m; i++) {
        if (board[0][i] == 'O') {
            q.push({ 0,i });
            board[0][i] = 'A';
        }
        if (board[n - 1][i] == 'O') {
            q.push({ n - 1,i });
            board[n - 1][i] = 'A';
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if (board[i][0] == 'O') {
            q.push({ i,0 });
            board[i][0] = 'A';
        }
        if (board[i][m - 1] == 'O') {
            q.push({ i,m - 1 });
            board[i][m - 1] = 'A';
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x + 1 < n && board[x + 1][y] == 'O') {
            board[x + 1][y] = 'A';
            q.push({ x + 1,y });
        }
        if (x - 1 >= 0 && board[x - 1][y] == 'O') {
            board[x - 1][y] = 'A';
            q.push({ x - 1,y });
        }
        if (y + 1 < m && board[x][y + 1] == 'O') {
            board[x][y + 1] = 'A';
            q.push({ x,y + 1 });
        }
        if (y - 1 >= 0 && board[x][y - 1] == 'O') {
            board[x][y - 1] = 'A';
            q.push({ x,y - 1 });
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'A') {
                board[i][j] = 'O';
            }
            else if(board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
    return;
}

int main() {
    vector<vector<char>> board = { {'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'} };
    solve(board);
}