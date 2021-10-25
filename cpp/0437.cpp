#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v) {}
};

// Complexity O(n)
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> prefixSum = {{0, 1}};
        return sumUp(0, root, prefixSum, targetSum);
    }

    int sumUp(
        int runningSum,
        TreeNode* node,
        unordered_map<int, int>& prefixSum,
        const int targetSum
    ) {
        if (!node) return 0;
        runningSum += node->val;
        // note the order in case of targetSum = 0
        int count = prefixSum[runningSum - targetSum];
        prefixSum[runningSum] += 1;
        if (node->left) count += sumUp(runningSum, node->left, prefixSum, targetSum);
        if (node->right) count += sumUp(runningSum, node->right, prefixSum, targetSum);
        prefixSum[runningSum] -= 1;
        return count;
    }
};

// class Solution {
// public:
//     int counter = 0;
//     int target = 0;
//     int pathSum(TreeNode* root, int targetSum) {
//         this->target = targetSum;
//         // for (auto v: possibleRootPathSum(root))
//         //     cout << v << " ";
//         possibleRootPathSum(root);
//         return this->counter;
//     }

//     void matchTarget(int val) {
//         if (val == this->target) {
//             this->counter++;
//         }
//     }

//     vector<int> possibleRootPathSum(TreeNode* root) {
//         if (!root) return {};
//         vector<int> vec = {root->val};
//         matchTarget(root->val);
//         if (root->left) {
//             for (auto v: possibleRootPathSum(root->left)) {
//                 int sum = v + root->val;
//                 vec.push_back(sum);
//                 matchTarget(sum);
//             }
//         }
//         if (root->right) {
//             for (auto v: possibleRootPathSum(root->right)) {
//                 int sum = v + root->val;
//                 vec.push_back(sum);
//                 matchTarget(sum);
//             }
//         }
//         return vec;
//     }
// };

int main() {
    return 0;
}
