/*
### Use Floyd’s cycle detection only when you know array values are in [1..n] and array length is n+1. ###

nums = [1, 3, 4, 2, 2]
Index:  0  1  2  3  4
Value:  1  3  4  2  2

Interpret the array as a linked list
Each index points to the next index given by the value at that index:

Start at:
nums[0] = 1 → next index is 1

nums[1] = 3 → next index is 3

nums[3] = 2 → next index is 2

nums[2] = 4 → next index is 4

nums[4] = 2 → next index is 2 (cycle starts here)

0 → 1 → 3 → 2 → 4    ## Cycle Formed ##
           ||___||

*/

int findDuplicate(const std::vector<int>& arr) {
    int slow = arr[0];
    int fast = arr[0];
    /*
        nums = [1, 3, 4, 2, 2]
        Index:  0  1  2  3  4
        Value:  1  3  4  2  2
    */ 

    // Step 1: Find intersection point inside the cycle
    while (true)
    {
        slow = arr[slow]; // 3, 2, 4, 2
        fast = arr[arr[fast]]; // 2, 2, 2
        if(arr[slow]==arr[fast])
            break;
    }
    slow = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow; // Both pointers meet at duplicate number
}    
