/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int> v;
        int idx =0;

        int prev_val = head->val;

        idx++;

        ListNode* temp = head->next;

        while(temp->next != nullptr)
        {
            int val = temp->val;

            int next_val = temp->next->val;

            if(val < next_val && val < prev_val)
            {
                v.push_back(idx);
            }
            if(val > next_val && val > prev_val)
            {
                v.push_back(idx);
            }

            prev_val = val;

            idx++;
            temp = temp->next;
        }

        if(v.empty() || (int)v.size()==1) return {-1,-1};

        for(auto i : v) cout<<i<<" ";
        cout<<endl;

        int maxi = abs(v[0]-v[(int)v.size()-1]);
        int mini = INT_MAX;
        for(int i =0; i<(int)v.size()-1; i++)
        {
            mini = min(mini , abs(v[i]-v[i+1]));
        }


        return {(mini==INT_MAX? -1: mini ),maxi};
    }
};