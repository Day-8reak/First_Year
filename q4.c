#include <stdio.h>
#include <stdbool.h>

int Year = 6969;

bool leapYearNot(int year){
    if (year % 4 == 0){

        if (year % 100 == 0){

            if (year % 400 == 0) {
                
                return true;
            }
            return false;
        }
        return true;    
    }
    return false;
}

int main(){
    if (leapYearNot(Year)){
        printf("%d is a leap year \n", Year);
    }

    else if (!leapYearNot(Year)){
        printf("%d isn't a leap year \n", Year);
    }
}