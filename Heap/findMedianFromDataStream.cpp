class MedianFinder
{
public:
    /** initialize your data structure here. */

    priority_queue<int> lower;                             // max_heap for lower half elements
    priority_queue<int, vector<int>, greater<int>> higher; // min_heap for upper half elements
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (lower.size() > higher.size())
        {
            if (number < median)
            {
                higher.push(lower.top());
                lower.pop();
                lower.push(number);
            }
            else
            {
                higher.push(number);
            }
            // median = (lower.top() + higher.top()) / 2;
        }
        else if (lower.size() == higher.size())
        {
            if (number < median)
            {
                lower.push(number);
                // median = (double)lower.top();
            }
            else
            {
                higher.push(number);
                // median = (double)higher.top();
            }
        }
        else
        {
            if (number > median)
            {
                lower.push(higher.top());
                higher.pop();
                higher.push(number);
            }
            else
            {
                lower.push(number);
            }
            median = (lower.top() + higher.top()) / 2;
        }
    }

    double findMedian()
    {
        return lower.size() > higher.size() ? lower.top() : (double)(lower.top() + higher.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */