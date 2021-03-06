//
// 307. Range Sum Query - Mutable
// https://leetcode.com/problems/range-sum-query-mutable/
// 
// 15 / 15 test cases passed.	Status: Accepted
// Runtime: 360 ms
// Memory Usage: 151.3 MB
// 
// --
// Created by Zhiyong Pan
// Git commit time:      20/06/2021, 17:23:02
// LeetCode submit time: 24 minutes ago
// Submission detail page: https://leetcode.com/submissions/detail/510797653//
// Committed with a user script: https://gist.github.com/panzy/c126371311dc166a94e611de8f45e63c
//
// By moving the tree root from [0] to [1], the arithmetic becomes simpler.
class NumArray {
    // number of leaf nodes, obtained by aligning nums.size() to a power of two
    size_t n;
    // an implicit BST, each node value is the sum of its two children.
    // tree[1] = root, tree[0] is not used.
    vector<int> tree;

public:
    NumArray(const vector<int>& nums)
        : n(pow(2, ceil(log2(nums.size())))),
        tree(n * 2, 0)
    {
        copy(begin(nums), end(nums), end(tree) - n);

        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    
    void update(int index, int val) {
        // locate the leaf node: tree[nodePos] <=> nums[index]
        int nodePos = n + index;
        int delta = val - tree[nodePos];

        // update the leaf node and the parents on the path to the root
        while (true) {
            tree[nodePos] += delta;
            if (nodePos == 0)
                break;
            nodePos = nodePos / 2;
        }
    }
    
    int sumRange(int left, int right) {
        // approach: becase each layer has the same sum, and higher layer has shorter length,
        // our motivation is move upwards.

        // map array indices to tree node indices
        left += n;
        right += n;

        int sum = 0;
        
        while (left <= right) {
            // trim the current layer to align with two's power
            if (left % 2 == 1) {
                sum += tree[left++];
            }
            if (right % 2 == 0) {
                sum += tree[right--];
            }

            // move up
            left /= 2;
            right /= 2;
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */