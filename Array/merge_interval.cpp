/*
Input: [[1,3], [2,6] ,[8,10] ,[8,9], [9,11],[15,18], [2,4] ,[16,17]]
Output: [[1,6],[8,11],[15,18]]
*/
vector<vector<int>> merge(vector<vector<int>>& arr) {
        auto itr = arr.begin();
        vector<vector<int>> merge;
        // arr = [[1,5], [2,4], [3,3]]
        sort(arr.begin(), arr.end()); // a < b; a.2 < b.2; lexographic
        vector<int> last(arr[0]); // store last ; 1st pair_of_element
        for(int i = 1; i<arr.size(); i++){            
           if(last[1] >= arr[i][0]){                                
                last[1] = max(last[1], arr[i][1]); // overlap; 5                             
            }else{
                // no overlap last[0] = needn't to modify
                merge.push_back(last);
                last = arr[i];
            }         
        }
        merge.push_back(last);
        return merge;
    }