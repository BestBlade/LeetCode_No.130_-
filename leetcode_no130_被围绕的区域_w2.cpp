/* ------------------------------------------------------------------|
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	递归法
*
*	执行用时：12 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：9.7 MB, 在所有 C++ 提交中击败了99.96%的用户
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
int n, m;

void dfs(vector<vector<char>>& board, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') {
        return;
     }
    board[i][j] = 'A';
    dfs(board, i - 1, j);
    dfs(board, i + 1, j);
    dfs(board, i, j - 1);
    dfs(board, i, j + 1);
}

void solve(vector<vector<char>>& board) {
    n = board.size();
    if (!n) {
        return;
    }
    m = board[0].size();
    for (int i = 0; i < m; i++) {
        dfs(board, 0, i);
        dfs(board, n - 1, i);
    }
    for (int i = 1; i < n - 1; i++) {
        dfs(board, i, 0);
        dfs(board, i, m - 1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'A') {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
    return;
}