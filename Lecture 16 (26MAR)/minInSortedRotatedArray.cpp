// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
class Solution {
public:
    int findMin(vector<int>& A) {
        int n=A.size();

        if(n==1) return A[0];
        int s=0,e=n-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            int next_idx=(mid+1)%n;
            int prev_idx=(mid-1 + n)%n;
            if(A[prev_idx] > A[mid] && A[next_idx] > A[mid])
            {
                return A[mid];
            }
            else if(A[mid] < A[e])
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findMin(vector<int>& A) {
        int n=A.size();

        if(n==1) return A[0];
        int s=0,e=n-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            int next_idx=(mid+1)%n;
            int prev_idx=(mid-1 + n)%n;
            if(A[prev_idx] > A[mid])
            {
                return A[mid];
            }
            else if(A[mid] < A[e])
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return -1;
    }
};