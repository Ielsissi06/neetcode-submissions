class DynamicArray {
public:
    int* arr;
    int cap;
    int size;

    DynamicArray(int capacity) {
        if (capacity > 0) {
            arr = new int[capacity];
            cap = capacity;
            size = 0;
        }
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (size + 1 <= cap) {
            arr[size] = n;
            size++;
        } else {
            resize();
            arr[size] = n;
            size++;
        }
    }

    int popback() {
        return arr[--size];
    }

    void resize() {
        int* arr2 = new int[2*cap];
        for (int i = 0; i < getSize(); i++) {
            arr2[i] = arr[i];
        }
        cap *= 2;
        delete[] arr;
        arr = arr2;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
