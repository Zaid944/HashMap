#include <bits/stdc++.h>
using namespace std;
class bucket
{
    vector<int> v;

public:
    void add(int x)
    {
        if (find(v.begin(), v.end(), x) == v.end())
        {
            v.push_back(x);
        }
    }
    void remove(int x)
    {
        if (find(v.begin(), v.end(), x) == v.end())
            return;
        v.erase(find(v.begin(), v.end(), x));
    }
    bool search(int x)
    {
        return find(v.begin(), v.end(), x) != v.end();
    }
};
class HashSet
{
    vector<bucket> h;
    int num_of_buckets;
    int hashFunction(int data)
    {
        return data % num_of_buckets;
    }

public:
    HashSet(int buckets_required)
    {
        num_of_buckets = buckets_required;
        h.resize(buckets_required);
    }
    void insert(int data)
    {
        int h_no = hashFunction(data);
        h[h_no].add(data);
    }
    void remove(int data)
    {
        int h_no = hashFunction(data);
        h[h_no].remove(data);
    }
    bool search(int data)
    {
        int h_no = hashFunction(data);
        return h[h_no].search(data);
    }
};
int main(){
    HashSet hs(10);
    hs.insert(10);
    hs.insert(5);
    //collision
    hs.insert(11);
    hs.insert(1);
    hs.insert(21);
    hs.insert(31);
    //collision
    cout << hs.search(12) << endl;
}