/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
//Helo//
//hi//
//ok//
#include <stdio.h>  
   
int main() {  
    int i,j, rows;
     
    printf("Enter the number of rows\n");
    scanf("%d", &rows); 
   
    for(i=1; i<=rows; i++){ 
        for(j=1; j <= rows; j++){
            if(j < i){
                printf(" ");
            } else {
                printf("*");
            }
        } 
        printf("\n");  
    }  
   
    return 0;  
}
