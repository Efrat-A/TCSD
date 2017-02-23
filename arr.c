#include <stdio.h>
void
func(int arr[], int size,int flag) {
    
for(int i=0;i<size;++i){
    for(int j=0;j<size;++j){
        if(flag == 0) scanf("%d",&arr[size*i+j]);
        if(flag == 1) printf("%d ",arr[size*i + j] );
    }printf("\n");}
}
void main (){
/*
int arr[2][2]={0,1,2,3};


for(int i=0;i<2;++i)
    for(int j=0;j<2;++j)
        printf("\n%p : arr+i:%p + %d ",(arr+ i)[j],(*(arr+i)+j),*(*(arr+i)+j));
*/

// quest2
//
int size;



scanf("%d", &size);
printf(" \n Tohen start");
if (size > 1) {

    int arr[size + size*size];
    func(arr, size, 0);
    func(arr,size,1);
}
printf("\n\nEND");
}
