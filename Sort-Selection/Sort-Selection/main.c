//
//  main.c
//  Sort-Selection
//
//  Created by Kaala on 2023/01/06.
//

#include <stdio.h>
#include <limits.h>
#define SIZE 1000

/*
 Selection Sort(선택 정렬)
 
 가장 작은 것을 선택해 앞으로 보내는 기법
 가장 작은 것을 탐색하는 데 N번,
 앞으로 보내는 데 N번으로,
 시간 복잡도는 O(N^2)
 */

int a[SIZE];


int swap(int *a, int *b){ //정렬에서는, 두 원소의 위치를 바꾸는 경우가 많으므로 구현해두면 좋음
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}


int main(){
    int n, min, index;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++){ // O(N)
        min = INT_MAX;
        for(int j = i; j < n; j++){ // 정렬 완료한 index는 건너 뛰어야하므로 j=i부터.
            if(min > a[j]){
                min = a[j];
                index = j;
            }
        }
        swap(&a[i], &a[index]);
    }
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
