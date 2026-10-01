class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> visited(n2,0);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]&&visited[j]==0){
                    if(ans.empty() || ans.back()!=nums2[j]){
                        ans.push_back(nums1[i]);
                        visited[j]=1;
                        break;
                    }
                }
                if(nums1[i]<nums2[j]){
                    break;
                }
            }
        }
        return ans;
    }
};