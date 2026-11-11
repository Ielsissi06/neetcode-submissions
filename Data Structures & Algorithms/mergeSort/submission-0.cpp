// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> merge(vector<Pair>& left, vector<Pair>& right) {
        if (left.size() == 0) return right;
        if (right.size() == 0) return left;

        if (left[0].key <= right[0].key) {
            vector<Pair> tail(left.begin() + 1, left.end());
            vector<Pair> result = merge(tail, right);
            result.insert(result.begin(), left[0]);
            return result;
        } else {
            vector<Pair> tail(right.begin() + 1, right.end());
            vector<Pair> result = merge(left, tail);
            result.insert(result.begin(), right[0]);
            return result;
        }
    }

    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if (pairs.size() <= 1) return pairs;

        int mid = pairs.size() / 2;

        vector<Pair> left(pairs.begin(), pairs.begin() + mid);
        left = mergeSort(left);
        vector<Pair> right(pairs.begin() + mid, pairs.end());
        right = mergeSort(right);

        return merge(left, right);
    }
};
