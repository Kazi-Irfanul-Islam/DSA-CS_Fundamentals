#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;
        
        while(left <= mid and right <= high) {
            if(arr[left] < arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();
    
    Solution obj;
    obj.mergeSort(arr, 0, n - 1);
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    return 0;
}

/*
    Time Complexity Analysis - 
                                O(nlogn) ->   The divide Step (O(logn)) and The merge Step(O(n))
                                When you multiply the height of the tree (log n) 
                                by the work done at each level (n), you get O(nlogn).

    Space Complexity Analysis - 
                                O(n)
                                The Temporary Array (O(n)):
                                The Recursion Stack (O(logn)):
                                When calculating Big-O, we drop the smaller term (O(logn)) because 
                                the O(n) temporary array dominates the memory usage,
                                leaving us with a total space complexity of O(n).
*/