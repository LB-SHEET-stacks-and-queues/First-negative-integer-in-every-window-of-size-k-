//ref -> aditya rajiv u tube

vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k) 
{
   vector<long long> ans;
   
   queue<long long> q;
   
   int i;
   /* Process first k (or first window) elements of array */
    for (i = 0; i < k; i++)
    {
        // Add current element at the rear of q if it is a negative integer
        if (a[i] < 0)
            q.push(a[i]);
    }
    //first window se required element nikaalo
        if(!q.empty())
        {
            ans.push_back(q.front());
        }
        else 
        {
            ans.push_back(0);
        }
    
     // Process rest of the elements, i.e., from arr[k] to arr[n-1]
     
     int front_marker=0;  //previous window ka front mark karega
     //jaise jaise window aage badhegi vaise vaise prev window ka front element remove hote
     //rehna chaiye kyuki nayi window me kuch aur aayga
     
    for ( i = k; i < n; i++)
    {
        if(a[front_marker]==q.front())
        {
            q.pop();
        }
        
        front_marker++;
        
        //nayi nayi window me ek ek ghusaayenge kyuki ek baar window me sab daala agar 
        //starting me to baadme jyada kaam nhi bachta. ek daalo ek nikaalo type ka rehta sirf
        if (a[i] < 0)
            q.push(a[i]);
            
        if(!q.empty())
        {
            ans.push_back(q.front());
        }
        else 
        {
            ans.push_back(0);
        }
        
    }
   
   return ans;
}
