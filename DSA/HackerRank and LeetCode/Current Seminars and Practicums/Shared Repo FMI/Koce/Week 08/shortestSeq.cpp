class Solution {
public:
   int shortestSequence(vector<int> & rolls, int k) {
    int n=rolls.size();
    set<int> st;
    int ans=1;
    
    for(int i=0;i<n;i++){
        st.insert(rolls[i]);
        
        if(st.size()==k){
			// we are updating our ans as we our forming all sub-sequence of size ans
            ans++;
            st.clear();
        }
    }
    return ans;
}
};
