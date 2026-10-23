class Deque {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int val) : val(val), prev(nullptr), next(nullptr) {}
    };

public:
    ListNode* head;
    ListNode* tail;
    int size;
    Deque() {
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    bool isEmpty() {
        return (size == 0);
    }

    void append(int value) {
        ListNode* node = new ListNode(value);
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        size++;
    }

    void appendleft(int value) {
        ListNode* node = new ListNode(value);
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    int pop() {
        if (size == 0) return -1;
        ListNode* last = tail->prev;
        int val = last->val;
        last->prev->next = tail;
        tail->prev = last->prev;
        delete last;
        size--;
        return val;
    }

    int popleft() {
        if (size == 0) return -1;
        ListNode* first = head->next;
        int val = first->val;
        first->next->prev = head;
        head->next = first->next;
        delete first;
        size--;
        return val;   
    }
};
