class MovingAverage {
public:
    /** Initialize your data structure here. */
     
    queue<int> q;
    int sum;
    int size;

    MovingAverage(int size) {
	q = queue<int>();
        sum = 0;
        this->size = size;        
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) { sum -= q.front(); q.pop(); }
        return 1.0 * sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
