#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


int recFunc(int* , size_t , int , int *,unsigned (*fp)(int*, size_t));
unsigned sumArrayDigits(int*, size_t);

int main()
{
    int arr[] = {5, 23, 77, 123, 681, 9,772, 16};
    int index = 4;
    int step = 0;
    size_t count = 8;

    recFunc(arr, count, 4, &step, sumArrayDigits);

    printf("%d\n",recFunc(arr, count, 4, &step, sumArrayDigits));

    
    return 0;
}

int recFunc(int* arr, size_t count, int index, int *step, unsigned (*fp)(int*, size_t)){
    

    if(index > count){
        return *step;
    }
    
    if(fp(arr+index, count) %2){

    *step++;
    index += 3;

    recFunc(arr, count, index, step, sumArrayDigits);

    } else {

    *step++;
     index += 2;

    recFunc(arr, count, index, step, sumArrayDigits);

    }



}
 
unsigned sumArrayDigits(int* arr, size_t count){

    int sum = 0;
    int rem = 0;

    for(int i = 0; i < count; i++){

        int num = *(arr + i);

        while(num){

        rem = num % 10;
        sum += rem;
        num = num /10;
    
        }
    
    }
    return sum;
}