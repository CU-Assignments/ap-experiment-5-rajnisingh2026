#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        for (int row = 0; row < n; row++) {
            minHeap.push({matrix[row][0], row, 0});
        }

        int result = -1;
        while (k--) {
            auto top = minHeap.top();
            minHeap.pop();
            result = top[0];
            int row = top[1], col = top[2];

            if (col + 1 < n) {
                minHeap.push({matrix[row][col + 1], row, col + 1});
            }
        }

        return result;
    }
};

