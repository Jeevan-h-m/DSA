int heap[10000]; int size;

void push(int x){ int i=size++;
while(i>0 && heap[(i-1)/2]<x){ heap[i]=heap[(i-1)/2]; i=(i-1)/2;
}
heap[i]=x;
}
int pop(){
int top=heap[0];
int last=heap[--size]; int i=0;
while(i*2+1<size){ int child=i*2+1;
if(child+1<size && heap[child+1]>heap[child]) child++;

if(last>=heap[child]) break;

heap[i]=heap[child]; i=child;
}
heap[i]=last; return top;
}
int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize){

size=0;
long fuel=startFuel; int i=0,stops=0;

while(fuel<target){

while(i<stationsSize && stations[i][0]<=fuel){ push(stations[i][1]);
i++;
}
if(size==0) return -1;
 
fuel+=pop(); stops++;
}

return stops;
}
