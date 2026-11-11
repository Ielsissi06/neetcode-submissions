class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int prefer1 = 0;
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 1) prefer1++;
        }
        int prefer0 = students.size() - prefer1;

        for (int i = 0; i < sandwiches.size(); i++) {
            if ((sandwiches[i] == 0 && prefer0 == 0) || (sandwiches[i] == 1 && prefer1 == 0)) break;
            if (sandwiches[i] == 0) prefer0--;
            else if (sandwiches[i] == 1) prefer1--;
        }

        return prefer0 + prefer1;
    }
};