class MyCircularDeque {
public:
    int front;
    int rear;
    int size;
    int capacity;
    vector<int>arr;
    MyCircularDeque(int k) {
        front = -1;
        rear = -1;
        capacity = k;
        size = 0;
        vector<int>v(k);
        arr = v;
    }
    bool insertFront(int value) {
        if(size == capacity) return false;
        else if(front == -1 && rear == -1){
            front = rear = 0;
            arr[front] = value;
        }
        else if(front == 0) 
        {
            front = capacity-1;
            arr[front] = value;
        } 
        else {
            front--;            //agar front first/last ko chor kr kahi 
            arr[front] = value;    //vv h toh front++ krenge element delete krne ke liya
        } 
        size++;
        return true;             
    }
    bool insertLast(int value) {
        if(size == capacity) return false;
        else if(front == -1 && rear == -1){
                front = rear = 0;
                arr[rear] = value;
        } 
        else if(rear == capacity-1) {
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        } 
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size == 0) return false;
        else if(front == capacity-1) front = 0;
        else front++;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size == 0) return false;
        else if(rear == 0)  rear = capacity-1;
        else rear--;
        size--;
        return true;
    }
    
    int getFront() {
        if(size == 0) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(size == 0) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == capacity);
    }
};

