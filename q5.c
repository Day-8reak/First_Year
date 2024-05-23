#include <stdio.h>

void inputGrades(int grades[]){
    for (int i = 0; i < 5; i++)
    {
        printf("Input student %d's grade:", i);
        scanf("%d", &grades[i]);
    }
    
}

void analyzeGrades(int grades[]){
    int highest = grades[0];
    int lowest = grades[0];
    float average;

    for (int i = 0; i < 5; i++)
    {
        average += grades[i];
        if (grades[i] > highest)
        {
            highest = grades[i];
        }
        else if (grades[i] < lowest)
        {
            lowest = grades[i];
        }
    }
    printf("\nthe average of the 5 grades was: %f \n", average/5);
    printf("the lowest of the 5 grades was: %d \n", lowest);
    printf("the highest of the 5 grades was: %d \n", highest);
}

int main(){
    signed int Grades[5];
    inputGrades(Grades);
    analyzeGrades(Grades);
}
