class LinkedList {
    struct Node {
        int val;
        Node* next;
    };

public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        Node* curr = head;
        for (int i = 0; i < index && curr != nullptr; i++) {
            curr = curr->next;
        }
        if (curr == nullptr) {
            return -1;
        }
        return curr->val;
    }

    void insertHead(int val) {
        Node* input = new Node;
        input->val = val;
        input->next = head;
        head = input;

        if (tail == nullptr) {
            tail = input;
        }
    }
    
    void insertTail(int val) {
        Node* input = new Node;
        input->val = val;
        input->next = nullptr;
        if (tail == nullptr) {
            head = input;
        } else {
            tail->next = input;
        }
        tail = input;
    }

    bool remove(int index) {
        if (index == 0) {
            if (head == nullptr) return false;

            Node* target = head;
            head = head->next;

            if (head == nullptr) tail = nullptr;

            delete target;
            return true;
        }

        Node* curr = head;

        for (int i = 0; i < index - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr || curr->next == nullptr) {
            return false;
        }

        Node* target = curr->next;
        curr->next = target->next;

        if (target == tail) tail = curr;
        delete target;
        return true;
    }

    vector<int> getValues() {
        vector<int> vals;
        Node* curr = head;
        while (curr != nullptr) {
            vals.push_back(curr->val);
            curr = curr->next;
        }
        return vals;
    }
};
