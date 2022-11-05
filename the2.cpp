#include <cmath>
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(int arr[], int n, int exp, long& number1, int& sizenumber)
{
    int output[n]; 
    int k=sizenumber;
    int m=pow(10,k);
    int i, count[m] = { 0 };
 

    for (i = 0; i < n; i++){
        number1++;
        count[(arr[i] / exp) % m]++;}
 
    for (i = 1; i < m; i++){
        number1++;
        count[i] += count[i - 1];}
 
    for (i = n - 1; i >= 0; i--) {
        number1++;
        output[count[(arr[i] / exp) % m] - 1] = arr[i];
        count[(arr[i] / exp) % m]--;
    }
 
    for (i = 0; i < n; i++){
        number1++;
        arr[i] = output[i];}
    
    
    
}
 void radixsort(int arr[], int n,long& number, int& size)
{
  
    int m = getMax(arr, n);
 
    
    for (int exp = 1; m / exp > 0; exp *= 10){
        
        countSort(arr, n, exp,number,size);}
}


long multiDigitRadixSort(int* arr, bool ascending, int arraySize, int groupSize, int maxDigitLength){
    long numberOfIterations = 0;
    int num, temp, i, j, t;  
    num=arraySize;
    if(maxDigitLength%groupSize==0){
    if(groupSize>=1){radixsort(arr,arraySize,numberOfIterations,groupSize);}
    
    numberOfIterations/=groupSize;
    }
    else{
        int u,p;
        int j;
        j=maxDigitLength%groupSize;

        radixsort(arr,arraySize,numberOfIterations,j);
        u=numberOfIterations;
        numberOfIterations=0;
        radixsort(arr,arraySize,numberOfIterations,groupSize);
        p=numberOfIterations;
        numberOfIterations=u+p;
        numberOfIterations/=maxDigitLength;
        
    }
   if(ascending==0){
            for ( i = 0, j = num - 1; i < num/2; i++, j--)  
    {     
        temp = arr[i];  
        arr[i] = arr[j];  
        arr[j] = temp;  
    }  
    }
    return numberOfIterations;
} 

