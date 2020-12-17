void arrange(vector<int> &A) {
    int n = A.size();
    for(int i=0; i<n; i++){
        A[i] = (A[A[i]]%n)*n + A[i];
    }
    for(int i=0; i<n; i++){
        A[i] = A[i]/n;
    }
 }

int main (){
    //code
    vector<int> v{2, 3, 4, 1, 2};
    arrange(v);
    for(auto i:v) {
        cout<<i<<" ";
    }
    return 0;
}
