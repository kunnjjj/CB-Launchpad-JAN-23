class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        int n=A.size();

        // deque<pair<int,int>> dq;
        deque<int> dq2; 
        vector<int> ans;
        for(int i=0;i<n;i++)
        {   
            // pair<int,int> cur={A[i],i};
      
            // while(!dq.empty() && dq.front().second<= i-k) // in this case you can use if also
            // {
            //     // jab dq khali nahi hai and frontelement ka index <= i-k tab tak remove it
            //     dq.pop_front();
            // }   

            while(!dq2.empty() && dq2.front() <= i-k)
            {
                dq2.pop_front();
            }



            // while(!dq.empty() && cur.first >= dq.back().first)
            // {
            //     // jab dq khali nahi hai end element at back ki vaue <= cur tab tak remove it
            //     dq.pop_back();
            // }

            while(!dq2.empty() && A[i] >= A[dq2.back()])
            {
                dq2.pop_back();
            }

            // push cur element
            // dq.push_back(cur);
            dq2.push_back(i);


            if(i>=k-1)
            {
                // ans.push_back(dq.front().first);
                ans.push_back(A[dq2.front()]);
            }
        }
        return ans;


    }
};