class MedianFinder {
private:
    priority_queue<int>max_heap;
    priority_queue<int, std::vector<int>, std::greater<int>>min_heap;
public:
    
    void addNum(int num) {
        if(max_heap.empty() || (max_heap.top()>num) )
            max_heap.push(num);
        else
            min_heap.push(num);
        if(max_heap.size()>min_heap.size())
        {
            if(max_heap.top() > num)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            else
                min_heap.push(num);
        }
        else
        {
            if(num <= max_heap.top())
                max_heap.push(num);
            else
                {
                    min_heap.push(num);
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
        }
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size())  
            return max_heap.empty() ? 0 : ((max_heap.top()+min_heap.top())/2.0);
        else
            return (max_heap.size()>min_heap.size()) ? max_heap.top():min_heap.top();
    }
};
