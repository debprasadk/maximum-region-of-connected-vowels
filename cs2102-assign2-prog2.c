/*
Name: Debprasad Kundu
Roll No.: cs2102
Date:30th January, 2022
Programme Description: find out the number of cells in the maximum region of connected 
vowels in the given matrix
*/

#include <stdio.h>

#define max(x,y) (x>y) ? x:y

int check_vowel(char ch){
    ch = ch | 0x20;
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1;
    else
        return 0;
}

int element_in_region(int m, int n, int matrix[][n], int r, int c, int count){
    int p = matrix[r][c];
    if(1 == p){
        count++;
        matrix[r][c] = 0;
        if(0 <= r-1 && 0 <= c-1)
            count = element_in_region(m, n, matrix, r-1, c-1, count);
        if(0 <= r-1)
            count = element_in_region(m, n, matrix, r-1, c, count);
        if(0 <= r-1 && n > c+1)
            count = element_in_region(m, n, matrix, r-1, c+1, count);
        if(0 <= c-1)
            count = element_in_region(m, n, matrix, r, c-1, count);
        if(n > c+1)
            count = element_in_region(m, n, matrix, r, c+1, count);
        if(m > r+1 && 0 <= c-1)
            count = element_in_region(m, n, matrix, r+1, c-1, count);
        if(m > r+1)
            count = element_in_region(m, n, matrix, r+1, c, count);
        if(m > r+1 && n > c+1)
            count = element_in_region(m, n, matrix, r+1, c+1, count);
    }
    return count;
}

int main()
{
    int m, n, i, j;
    char str[10];
    printf("Enter row and column : ");
    scanf("%d%d", &m, &n);
    int matrix[m][n];
    char  ch[m][n];
    printf("Enter elements : ");
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            scanf("%s", str);
            ch[i][j] = str[0];
            if (1 == check_vowel(ch[i][j]))
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    int count = 0, count1;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(1 == matrix[i][j]){
                count1 = 0;
                count1 = element_in_region(m, n, matrix, i, j, count1);
                count = (count1 > count) ? count1 : count;
            }
        }       
    }       
    printf("\n%d",count);   
    return 0;
}