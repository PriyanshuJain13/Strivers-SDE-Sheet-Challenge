class LRUCache {
public:
    vector<int>values, repeated;
    int capacity, curr_size;
    queue<int> cacheQueue;
    LRUCache(int capacity) {
      values = vector<int> (10002, -1);
      repeated = vector<int> (10002, 0);
      curr_size = 0;
      cacheQueue = queue<int> ();
      this->capacity = capacity;
    }
    
    int get(int key) {
       if(values[key] != -1) {
           cacheQueue.push(key);
           repeated[key]++;
       }
       return values[key];
    }
    
    void put(int key, int value) {
        if(values[key] == -1) {
            curr_size++;
            cacheQueue.push(key);
            values[key] = value;
        }
        else {
            cacheQueue.push(key);
            values[key] = value;
            repeated[key]++;
        }
        
        if(curr_size > capacity) {
            while(repeated[cacheQueue.front()] != 0) {
                repeated[cacheQueue.front()]--;
                cacheQueue.pop();
            }
            curr_size--;
            int leastUsedKey = cacheQueue.front();
            values[leastUsedKey] = -1;
            cacheQueue.pop();
        }
    }
};
