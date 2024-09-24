//
// Created by Volodymyr Avvakumov on 23.09.2024.
//

#include <stdio.h>


int main(){
    int arr[] = {3, 5, 6, 8, 2};
    double n;
    scanf("%lf", &n);

    int counter = 0;
    for (int i = 0; i < 5; i++){
        if ((double)arr[i] < n){
            counter++;
        }

    }
    printf("%d", counter);
    return 0;
}