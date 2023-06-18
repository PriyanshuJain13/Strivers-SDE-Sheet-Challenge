class LFUCache {
    unordered_map<int,pair<int,int>> cache;
    vector<deque<int>> counter;
    int max_size, num_elements;

    void increment_element(int key) {

        cache[key].second++;

        while (counter.size() <= cache[key].second)
            counter.push_back(deque<int>());

        counter[cache[key].second].push_back(key);
    }

    void remove_LFU_element() {
        bool success = false;

        for (int i = 0; i < counter.size() && !success; i++) {

            while (!counter[i].empty() && !success) {

                if (cache[counter[i].front()].second == i) {
                    success = true;
                    cache.erase(counter[i].front());
                    num_elements--;
                }
                counter[i].pop_front(); 
            }
        }
    }

public:
    LFUCache(int c) {
        max_size = c;
        num_elements = 0;
        counter = {{}};
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        increment_element(key);

        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (max_size == 0) return;

        if (cache.find(key) != cache.end()) {
            cache[key].first = value;
            increment_element(key);
            return;
        }

        if (num_elements == max_size)
            remove_LFU_element();

        cache[key] = make_pair(value,0);
        counter[0].push_back(key);
        num_elements++;
    }
};
