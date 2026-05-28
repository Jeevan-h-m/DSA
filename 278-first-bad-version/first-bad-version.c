// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) { bool result;
long low=1; long high=n;
while(low<=high){
long mid=(low+high)/2; if(!isBadVersion(mid)){
low=mid+1;
}
else{
high=mid-1;
}
}
return low;
}
