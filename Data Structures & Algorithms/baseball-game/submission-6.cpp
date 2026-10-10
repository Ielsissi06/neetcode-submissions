class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> score;
        int sum = 0;
        for (const string& op : operations) {
            if (op == "+") {
                int x = score.top(); score.pop();
                int y = x + score.top();
                score.push(x);
                score.push(y);
                sum += y;

            } else if (op == "D") {
                score.push(2*score.top());
                sum += score.top();

            } else if (op == "C") {
                sum -= score.top();
                score.pop();

            } else {
                score.push(stoi(op));
                sum += score.top();
            }
        }
        return sum;
    }
};