#include <stdio.h>

int nums[] = {10, 15, 6, 11, 17, 8, 10, 29, 12, 9};
int First = 0;

int findFirstOccurence(int number){
    for( int i = 0; i<= sizeof(nums); i++) {
        if (nums[i] == number) {
            First = i;
        }
    }
    printf("Number: %d index: %d \n", number, First);
}

int main(){
    int x = 15;
    findFirstOccurence(x);
}