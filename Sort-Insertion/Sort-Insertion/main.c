//
//  main.c
//  Sort-Insertion
//
//  Created by Kaala on 2023/01/06.
//

#include <stdio.h>
#define SIZE 1000

/*
 Insertion Sort(삽입 정렬)
 
 각 숫자를 적절한 위치에 삽입하는 기법.
 들어갈 위치 탐색에 N번,
 삽입 횟수 N번,
 시간복잡도 O(N^2)
 
 일반적으로, 선택 정렬보다 빠르다.
 */

int a[SIZE];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortMethod1(int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j>0; j--){
            if(a[j-1] > a[j]) swap(&a[j], &a[j-1]);
        }
    }
}

void sortMethod2(int n){
    for(int i = 0; i < n - 1; i++){
        int j = i;
        while(j >= 0 && a[j] > a[j+1]){
            swap(&a[j], &a[j+1]);
            j--;
        }
    }
}

int main(){
    int n;
    printf("배열 크기 입력 : ");
    scanf("%d",&n);
    printf("\n데이터 입력 : ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    sortMethod1(n);
//    sortMethod2(n);
    
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    
    return 0;
    
}
