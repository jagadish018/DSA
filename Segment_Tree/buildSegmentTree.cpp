#include<bits/stdc++.h>
using namespace std;

void buildSegmentTree(vector<int>&arr,int i,int l,int r,vector<int>&segTree){
  if(l==r){
    segTree[i]=arr[l];
    return;
  }
    int mid=(l+r)/2;
  buildSegmentTree(arr,2*i+1,l,mid,segTree);
  buildSegmentTree(arr,2*i+2,mid+1,r,segTree);
  segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

int main(){
  vector<int>arr={1,3,5,7,9,11};
  int n=arr.size();
  vector<int>segTree(2*n,0);
  buildSegmentTree(arr,0,0,n-1,segTree);
  for(int i=0;i<2*n;i++){
    cout<<segTree[i]<<" ";
  }
  return 0;
}