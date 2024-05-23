#include <stdio.h>

signed int codeOrNot;
char DCode;
signed int Age;
char aGroup;
// The age groups are: 'a' = Child, 'b' = Teen, 'c' = Adult, 'd' = Elder


// make sure to include the input functions
void ageStudentFinder () {
	printf("Input your Age: \n");
    scanf("%d", &Age);
    if(Age > 120 || Age < 0){
        printf("You entered an incorrect value for your age");
        ageStudentFinder();
    }


	printf("Do you have a code? (0 for no, 1 for yes): \n");
    scanf("%d", &codeOrNot);
    if (codeOrNot == 0 || codeOrNot == 1) {
    }
    else{
        printf("You entered a incorrect value");
        ageStudentFinder();
    }


	if (codeOrNot == 1){
	    printf("Which discount code do you have? (A, B, or C)");
        scanf("%c", &DCode);
        if (DCode == 'A' || DCode == 'B' ||  DCode == 'C'){
        }
        else {
            printf("You didn't enter a valid code, try again");
            ageStudentFinder();
        }
        
    }
    
}


int Discounts(int age, char code) {
    int totalDiscount = 0;
    switch (age) {
    case 0 ... 12:
        aGroup = 'a';
        break;
    case 13 ... 19:
        aGroup = 'b';
        break;
    case 20 ... 64:
        aGroup = 'c';
        break;
    case 65 ... 120:
        aGroup = 'd';
        break;
    default:
        printf("You entered an incorrect value for your age");
        ageStudentFinder();
        Discounts(Age, DCode);
        break;
    }

    switch (aGroup) {
    case 'a':
        totalDiscount = 50;
        break;

    case 'b':
        totalDiscount = 25;        
        break;

    case 'c':
        totalDiscount = 0;
        break;

    case 'd':
        totalDiscount = 30;
        break;
        
    default:
        break;
    }


    if (codeOrNot == 1){
        switch (code)
        {
        case 'A':
            totalDiscount += 5;
            break;
        case 'B':
            totalDiscount += 10;
            break;
        case 'C':
            totalDiscount += 15;
            break;    

        default:
            break;
        }
    }

    return totalDiscount;
}
	
int main(){
    ageStudentFinder();
    printf("Your total discount is %d \n", Discounts(Age, DCode));
}