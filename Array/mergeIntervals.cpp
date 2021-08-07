/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compare(Interval a,Interval b){
     return a.start<=b.start;
 }
 
vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
    A.push_back(newInterval);
    sort(A.begin(),A.end(),compare);
    int n = A.size();
    vector<Interval> ans;
        
    for(int i=0;i<n-1;i++){
          if(A[i].end>=A[i+1].start){
              A[i+1].start=min(A[i].start,A[i+1].start);
              A[i+1].end=max(A[i].end,A[i+1].end);
          }
          else ans.push_back(A[i]);
    }
    ans.push_back(A[n-1]);
    return ans;
}
