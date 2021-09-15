void Solution::sortColors(vector<int> &A) {
    int i=0, j=0, k=A.size()-1; 
    while(j<=k) {
        if(A[j] == 0)   swap(A[i++], A[j]);
        if(A[j] == 2)   swap(A[j], A[k--]);
        else j++;
    }
}
