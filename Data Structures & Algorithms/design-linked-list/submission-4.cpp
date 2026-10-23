class MyLinkedList {
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

    MyLinkedList() {
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode* curr = head->next;
        for (int i = 0; i < index && curr->next != nullptr; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        ListNode* prev = head;
        for (int i = 0; i < index && prev->next != nullptr; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* node = new ListNode(val);
        node->next = curr;
        curr->prev = node;
        prev->next = node;
        node->prev = prev;
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        ListNode* prev = head;
        for (int i = 0; i < index && prev->next != nullptr; i++) {
            prev = prev->next;
        }
        ListNode* del = prev->next;
        ListNode* next = del->next;
        prev->next = next;
        next->prev = prev;
        delete del;
        size--;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */