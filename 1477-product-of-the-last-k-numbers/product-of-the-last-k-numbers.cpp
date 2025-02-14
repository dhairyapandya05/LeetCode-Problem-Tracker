class ProductOfNumbers {
private:
    vector<int> arr;
    vector<long long> ppro;
    int idx;
public:
    ProductOfNumbers() {
        arr = {};
    }
    
    void add(int num) {
        int n = arr.size();
        if(arr.size()==0){
            if(num==0){
                idx = n;
                arr.push_back(num);
                ppro.push_back(1);
            }
            else{
                arr.push_back(num);
                ppro.push_back(num);
            }
        }
        else{
            if(num==0){
                idx = n;
                arr.push_back(num);
                ppro.push_back(1);
            }
            else{
                arr.push_back(num);
                ppro.push_back(num*ppro[n-1]);
            }
        }

    }
    
    int getProduct(int k) {
       int n = arr.size();
       if (k > n) return 0;
        if (idx >= n - k) return 0;

        return ppro[n-1] / (n-k-1 >= 0 ? ppro[n-k-1] : 1);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */