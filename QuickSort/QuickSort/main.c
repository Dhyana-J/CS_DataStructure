//
//  main.c
//  QuickSort
//
//  Created by Kaala on 2023/01/11.
//

#include <stdio.h>
#define SIZE 1000

/* Quick Sort
 - 피벗 기준으로 큰 값과 작은 값을 서로 교체하는 정렬기법
 - 값을 서로 교체하는 데 N번, 엇갈린 경우 원소가 반으로 나뉘어 재귀적으로 수행되므로 전체 원소 나누는 데 평균 logN번 소요.
 - O(NlogN)의 복잡도를 가지지만, 편향이 발생하면 O(N^2)이 되기도 함.
 */

int a[SIZE];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int start, int end){ //오름차순 정렬
    if(start>=end) return;
    int key = start, i = start + 1, j = end, temp;
    while(i <= j){ //엇갈릴 때 까지 반복
        while(i <= end && a[i] <= a[key]) i++; //피벗값보다 큰 수 찾기
        while(j > start && a[j] >= a[key]) j--; //피벗값보다 작은 수 찾기
        if(i > j) swap(&a[key], &a[j]); //엇갈렸을 경우 피벗값과 작은 값을 바꿔줌
        else swap(&a[i],&a[j]); //엇갈리지 않았을 경우 큰 값 작은 값 교체
    }
    //작은 값과 교체된 피벗값은 정렬완료이므로 다음턴 정렬에서 제외. 해당 값 기점으로 나눠진 배열을 다시 퀵정렬한다.
    quickSort(start, j-1);
    quickSort(j+1, end);
}

void show(int n){
    for(int i = 0; i<n; i++) printf("%d ",a[i]);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i = 0; i<n; i++) scanf("%d",&a[i]);
    quickSort(0, n-1);
    show(n);
    return 0;
}
