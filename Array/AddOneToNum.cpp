vector<int> Solution::plusOne(vector<int> &a) {
    
    int n = a.size();0;
    int carry = 1;
    
    for(int i=n-1; i>=0; i--)
    {
            int temp = a[i] + carry;
            a[i] = temp%10;
            carry = temp/10;
    }
    if(!carry){
        while(a[0]==0)
        {
            a.erase(a.begin());
        }
    }
    else{
        a.insert(a.begin(),1);
    }
    return a;
}
