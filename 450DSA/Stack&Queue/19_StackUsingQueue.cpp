class Stack {
	// Define the data members.

   public:
   queue<int> q;
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q.push(element);
    }

    int pop() {
        // Implement the pop() function.
        if(q.size() == 0) return -1;
        if(q.size() == 1) {
            int temp = q.back();
            q.pop();
            return temp;
        }
        for(int i = 0; i < q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
        int temp = q.front();
        q.pop();
        return temp;
    }

    int top() {
        // Implement the top() function.
        if(q.size() == 0) return -1;
        return q.back();
    }
};