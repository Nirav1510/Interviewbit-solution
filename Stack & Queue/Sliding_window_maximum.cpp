vector<int> slidingMaximum(const vector<int> &A, int B) {
    deque<int> l;
    vector<int> v;
    int i=0,j=0;
    while(j<A.size()){
        
        while(l.size()>0 && l.back()<A[j]){
            l.pop_back();
        }
        l.push_back(A[j]);
        
        if(j-i+1<B) j++;
        
        else if(j-i+1==B){
            v.push_back(l.front());
            
            if(l.front()==A[i]){
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return v;
}
