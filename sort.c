#include<stdio.h>

//insertion

void insertion()
{
    int n;
    printf("enter size of the array");
    scanf("%d",&n);

    int arr[n];
    printf("enter elements for the array");
    for(int i=0; i<n; i++)
    {
    scanf("%d",&arr[i]);
    }

    for(int i=0; i<n; i++)
    {
        int current = arr[i];
        int j = i-1;

        while(arr[j] > current && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = current;
    }

    for(int i=0; i<n; i++){
     printf("%d ",arr[i]);
    }
}

// quick sort
void swap(int arr[],int i, int j){

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

int partition( int arr[], int l, int r){
    int pivot = arr[r];
    int i=l-1;

    for (int j=l; j<r; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }

    swap(arr,i+1,r);
    return i+1;
 }

void quicksort(int arr[], int l, int r)
 {
    if(l<r)
    {
        int pi=partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
 }

//binary with bubble
void bubblesort(int arr[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binarysearch(int arr[], int n, int target)
{
    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            high = mid -1;
        }
        else
        {
            low = mid + 1;
        }
    }
    

    return -1;
}

//selection
void selection()
{
   int n;
    printf("enter size of the array");
    scanf("%d",&n);

    int arr[n];
    printf("enter elements for the array");
    for(int i=0; i<n; i++)
    {
    scanf("%d",&arr[i]);
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[i])
            {
                int temp = arr [j];
                arr[j] = arr[i];
                arr[i] = temp;

            }
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }


}

//merge

    //merge two subarrays l and m int arr

    void merge(int arr[], int p,int q,int r)
    {
        // create l - a[p..q] and m - a[q+1..r]
        int n1 = q-p+1;
        int n2 = r-q;

        int l[n1], m[n2];

        for(int i = 0 ; i < n1 ; i++)
        l[i] = arr[p+i];

        for(int j = 0; j < n2; j++)
        m[j] = arr[q+1+j];

        //maintain current index of sub arrays and main array

        int i, j, k;
        i = 0;
        j = 0;
        k = p;
        
        // Until we reach either end of either L or M, pick larger among
       // elements L and M and place them in the correct position at A[p..r]
       
       while(i < n1 && j <n2)
       {
        if(l[i] <= m[j])
        {
            arr[k] = l[i];
            i++;
        }

        else
        {
            arr[k] = m[j];
            j++;
        }
        k++;
       }
        // When we run out of elements in either L or M,
        // pick up the remaining elements and put in A[p..r]

        while (i < n1)
        {
            arr[k] = l[i];
            i++;
            k++;
        }
        while (i < n2)
        {
            arr[k] = m[j];
            j++;
            k++;
        }
    }    

        // divide the array into sub arrays , sort them AND merge them
        void mergesort (int arr[], int l, int r)
        
        {
            if( l < r)
            {
                int m = l+(r-l)/2;

                mergesort(arr, l, m);
                mergesort(arr, m+1, r);

                //merge the sorted subarrays
                merge(arr, l ,m , r);
            }
        }
    
int main()
{
  //bubble sort

    /*int no;
    printf("Enter total no's: ");
    scanf("%d",&no);

    int arr[no];

    printf("Enter no's:\n");
    for(int i = 0;i < no; i++)
    {
        scanf("%d",&arr[i]);
    }

    int n = no;
    int target;

    bubblesort(arr,n);

    printf("sorted array is: ");

    for(int i = 0;i < no; i++)
    {
        printf("%d   ",arr[i]);
    }


     printf("\nenter the no you want to find: ");
    scanf("%d",&target);

    int reasult = binarysearch(arr, n, target);

    if (reasult != -1)
       printf("Element is found at index %d\n",reasult);

    else
       printf("Element is not found ");


    return 0;   
    */

 //  insertion short

   //insertion();


//quick sort

   /* int n;
    printf("enter size of the array");
    scanf("%d",&n);

    int arr[n];
    printf("enter elements for the array");
    for(int i=0; i<n; i++)
    {
    scanf("%d",&arr[i]);
    }
    quicksort(arr , 0, n-1);
    for(int i=0; i<n;i++)
    {
       printf("%d ",arr[i]);
    }*/

   //selection();


    int n;
    printf("enter size of the array");
    scanf("%d",&n);

    int arr[n];
    printf("enter elements for the array");
    for(int i=0; i<n; i++)
    {
    scanf("%d",&arr[i]);
    }
     mergesort(arr, 0, n-1);
    for(int i=0; i<n;i++)
    {
       printf("%d ",arr[i]);
    }

}