class Solution {
 
    void merge(vector<pair<int, int>>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<pair<int, int>> nums1;
        vector<pair<int, int>> nums2;

        for (int i = 0; i < n1; i++) {
            nums1.push_back(nums[i + left]);
        }

        for (int i = 0; i < n2; i++) {
            nums2.push_back(nums[i + mid + 1]);
        }

        int counter = 0;
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (nums1[i].first <= nums2[j].first) {
                for(int t = i + 1; t < n1 && counter > 0; t++) 
                    result[nums1[t].second] += counter;
                counter = 0;
                nums[k] = nums1[i];
                k++;
                i++;
            }
            else {
                result[nums1[i].second]++;
                counter++;
                nums[k] = nums2[j];
                k++;
                j++;
            }
        }

        while (i < n1) {
             for (int t = i + 1; t < n1; t++)
                result[nums1[t].second] += counter;
            nums[k] = nums1[i];
            i++;
            k++;
        }

        while (j < n2) {
            nums[k] = nums2[j];
            j++;
            k++;
        }
    }

    void counterMergeSort(vector<pair<int, int>>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            counterMergeSort(nums, left, mid);
            counterMergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

public:
    vector<int> result;

    vector<int> countSmaller(vector<int>& nums) {
        result.resize(nums.size());

        vector<pair<int, int>> pairNums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            pairNums[i].first = nums[i];
            pairNums[i].second = i;
        }

        counterMergeSort(pairNums, 0, pairNums.size() - 1);

        return result;
    }
};
