#include <stdio.h>
#include <stdlib.h>

void show(int x[][9] , int m , int n){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void findc(int* c){
    switch (*c) {
        case 0:
        case 1:
        case 2:
            *c = 1;
            return;

        case 3:
        case 4:
        case 5:
            *c= 4;
            return;

        case 6:
        case 7:
        case 8:
            *c = 7;
            return;
    }
}

//0 for false ; 1 for true
int isValid(int arr[9][9],int x, int y,int num){
    int check = 1;
    int i,j;

    //row checking
    for ( i = 0; i < 9 ; ++i) {
        if(i == x){
            continue;
        }
        if(arr[i][y] == num){
            check = 0;
            return check;
        }
    }

    // column check
    for (j = 0; j < 9;  ++j) {
        if(j == y){
            continue;
        }
        if(arr[x][j] == num){
            check = 0;
            return check;
        }
    }

    // block checking
    i = x;
    j = y;
    findc(&i);
    findc(&j);

    for (int k = i-1; k < i+2; ++k) {
        for (int l = j-1; l < j+2 ; ++l) {
            if(k == x && l == y){
                continue;
            }

            if(arr[k][l] == num){
                check = 0;
                return check;
            }
        }
    }

    return check;
}

void whenDone(int arr[9][9]){
    for (int i = 0; i < 9; ++i) {
        int sum = 0;
        for (int j = 0; j < 9; ++j) {
            sum = sum + arr[i][j];
        }

        if(sum != 55){
            return;
        }
    }
    show(arr,9,9);
}

void solve(int arr[9][9]){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if(arr[i][j] == 0){
                for (int k = 1; k <= 9; ++k) {
                    if(isValid(arr,i,j,k)){
                        arr[i][j] = k;
                        whenDone(arr);
                        solve(arr);
                        arr[i][j] = 0;
                    }

                    if(k == 9){
                        arr[i][j] = 0;
                        return;
                    }
                }

                if(!(isValid(arr,i,j,1) || isValid(arr,i,j,2) || isValid(arr,i,j,3) || isValid(arr,i,j,4) || isValid(arr,i,j,5) || isValid(arr,i,j,6) || isValid(arr,i,j,7) || isValid(arr,i,j,8) || isValid(arr,i,j,9))){
                    arr[i][j] = 0;
                    return;
                }
            }
        }
    }

    show(arr,9,9);
    exit(0);
}

int main() {
    int arr[9][9];

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\n");

    solve(arr);
    return 0;
}
