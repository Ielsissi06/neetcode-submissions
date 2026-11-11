class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stud;
        int delta = 0;
        
        int i = 0;
        while (i < students.size() - delta) {
            if (sandwiches[i] == students[i + delta]) {
                i++;
            } else {
                stud.push(students[i+delta]);
                delta++;
            }
        }

        int rejected = 0;
        while (!stud.empty()) {
            if (rejected > stud.size()) break;
            if (stud.front() == sandwiches[i]) {
                rejected = 0;
                i++;
                stud.pop();
            } else {
                rejected++;
                stud.push(stud.front());
                stud.pop();
            }
        }

        return stud.size();
    }
};