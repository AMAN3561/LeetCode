class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    double median;
    MedianFinder() { median = 0; }

    void addNum(int num) {
        if (maxheap.size() == minheap.size()) {
            if (num > median) {
                // insert in right :
                minheap.push(num);
                median = minheap.top();
            } else {
                // insert in left.
                maxheap.push(num);
                median = maxheap.top();
            }
        } else if (maxheap.size() == minheap.size() + 1) {
            // maxheap ka size bada h by 1'
            if (num > median) {
                // insert in right
                minheap.push(num);
                median = (minheap.top() + maxheap.top()) / 2.0;
            } else {
                // insert in left
                // max already bada hai sidha insert nhh kr sakte
                // 1 element offloadd kro
                int element = maxheap.top();
                maxheap.pop();
                minheap.push(element);
                // now ineseert num in left
                maxheap.push(num);
                median = (minheap.top() + maxheap.top()) / 2.0;
            }
        } else if (maxheap.size() + 1 == minheap.size()) {
            // minheap ka size bada ha by 1;
            if (num > median) {
                // insert in right
                // min already bada hai sidha insert nhh kr sakte
                // 1 element offloadd kro
                int element = minheap.top();
                minheap.pop();
                maxheap.push(element);
                // now insert num in right
                minheap.push(num);
                median = (minheap.top() + maxheap.top()) / 2.0;
            } else {
                maxheap.push(num);
                median = (minheap.top() + maxheap.top()) / 2.0;
            }
        }
    }
double
findMedian() {
    return median;
}
}
;

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */