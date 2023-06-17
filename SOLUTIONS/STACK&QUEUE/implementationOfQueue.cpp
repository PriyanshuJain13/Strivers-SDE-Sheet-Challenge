struct queue
{
    int size,cap;
    int *arr;
    queue(int c)
    {
        cap = c;
        size = 0;
        arr = new int(cap);
    }
    void enqueue(int x)
    {
        if(isFull()) return;
        arr[size] = x;
        size++;
    }

    //only O(n)
    void dequeue()
    {
        if(isEmpty()) return;
        for (int i = 0; i < size-1; i++)
        {
            arr[i] = arr[i+1];

        }
        size--;
    }

    int getFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return 0;//index of 1st member of queue
        }
        
    }
    int getRear()
    {
        if(isEmpty())
        {
            return -1;
        }
        else{
            return size-1;
        }
    }

    bool isFull()
    {
        return (size == cap);
    }

    bool isEmpty()
    {
        return(size == 0);
    }
    int size()
    {
        return size;
    }
};
