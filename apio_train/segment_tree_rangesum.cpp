#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int N = 100;
int A[101];
int tree[410];
int lazy[410];

int query(int node, int cur_lo, int cur_hi, int lo , int hi) {
   if(lazy[node] != 0){
      tree[node] += lazy[node]* (cur_hi-cur_lo+1);
      if(cur_lo != cur_hi){
         lazy[node*2+1] += lazy[node];
         lazy[node*2+2] += lazy[node];
      }
      lazy[node] = 0;
   }

   if(cur_lo > hi || cur_hi < lo) 
      return 0;

   if(cur_lo >= lo && cur_hi <= hi)
      return tree[node];

   int mid = (cur_lo + cur_hi)/2;

   return query(node*2+1,cur_lo,mid,lo,hi) + query(node*2+2,mid+1,cur_hi,lo,hi);
}

void update(int node , int val, int cur_lo , int cur_hi , int lo , int hi)
{
   if(lazy[node] != 0){
      tree[node] += lazy[node]* (cur_hi-cur_lo+1);
      if(cur_lo != cur_hi){
         lazy[node*2+1] += lazy[node];
         lazy[node*2+2] += lazy[node];
      }
      lazy[node] = 0;
   }

   if(cur_hi < lo || cur_lo > hi)
      return;

   if(cur_lo >= lo && cur_hi <= hi){
      tree[node] += val * (cur_hi-cur_lo+1);
      if(cur_hi != cur_lo) {
         lazy[node*2+1] += val;
         lazy[node*2+2] += val;
      }
      return;
   }
   int mid = (cur_lo+cur_hi)/2;
   update(node*2+1,val,cur_lo,mid,lo,hi);
   update(node*2+2,val,mid+1,cur_hi,lo,hi);
   tree[node] = tree[node*2+1] + tree[node*2+2];   
}

int build(int node , int lo , int hi){
   int mid = (lo+hi)/2;
   if(lo == hi)
      return tree[node] = A[lo];
   return tree[node] = build(node*2+1,lo,mid) + build(node*2+2,mid+1,hi);
} 

int main()
{
   for(int i = 1 ; i <= 100 ; i++)
      A[i] = i;
   int a = 3;
   int b = 4;
   build(0,1,N);
   update(0,1,1,N,1,100);
   cout << query(0,1,N,44,50) << endl;
   return 0;
}