#include <stdio.h>
#define MAX 100

int main(){
    int n,k,a[MAX];
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter k: ");
    scanf("%d",&k);
    for(int i=1;i<n;i++){
        if(a[i]%k!=a[0]%k){
            printf("Not possible\n");
            return 0;
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    int median=a[n/2];
    int ops=0;
    for(int i=0;i<n;i++){
        if(a[i]>median)
            ops+=(a[i]-median)/k;
        else
            ops+=(median-a[i])/k;
    }
    printf("Output: %d\n",ops);
    return 0;
}
