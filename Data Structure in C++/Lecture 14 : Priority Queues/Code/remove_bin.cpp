#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }


    int removeMin() 
	{
		if(isEmpty()) 
			return 0;		// Priority Queue is empty
		
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		// down-heapify

		int parentIndex = 0;
		int leftChildIndex = 1;
		int rightChildIndx = 2;
	
		while(leftChildIndex < pq.size()) //if leftIndex is within range, rightIndex hoga hi
		{
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) 
				minIndex = leftChildIndex;
			
			if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) //possibly only left child exist
				minIndex = rightChildIndx;

			if(minIndex == parentIndex) //upper se neeche changes kre ha humne (down heapify), agar upper ka sahi hoagaya ha
			                            //neeche ka sahi hi hoga
				break;
				
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}
		return ans;
	}
    
};