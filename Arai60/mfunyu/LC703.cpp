/* Kth Largest Element in a Stream */

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : kth(k) {
        for (auto n : nums) {
            add(n);
        }
    }

    int add(int val) {
        sorted.push(val);
        if (sorted.size() > kth) {
            sorted.pop();
        }
        return sorted.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> sorted;
    int kth;
};
