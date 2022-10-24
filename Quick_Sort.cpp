// Best Case: O(nlog(n))
// Worst Case: O(n^2)                   [when sorted list is used]

// Selecting middle element as pivot can help use reduce the time complexity back to nlog(n) for the worst case But there can still be an arrangemet of elements which would have a time complexity of n^2

// Other suggestion would be take random elements as pivot, but still there is a possibility of encountering a case where the time complexity becaomes n^2

// So the worst case time complexity of Quick Sort remains to be O(n^2)

// The stack would range from log(n) to n

#include <iostream>

using namespace std;

int Part(int a[],int lo,int hi){
    int pivot = a[lo];
    int i=lo;
    int j=hi;

    while (i<j){
        do{
            i++;
        }while(a[i]<=pivot);

        do{
            j--;
        }while(a[j]>pivot);

        if (i<j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    a[lo] = a[j];
    a[j] = pivot;
    return j;
}

void QS(int a[],int lo,int hi){
    if (lo<hi){
        int mid = Part(a,lo,hi);
        QS(a,lo,mid);
        QS(a,mid+1,hi);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    QS(arr,0,n);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}