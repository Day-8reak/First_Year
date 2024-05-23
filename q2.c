#include <stdio.h>

int StudOrNot;
int Age;


// make sure to include the inputs functions
void ageStudentFinder () {
	printf("Input your Age: \n");
	scanf("%d", &Age);
	if (Age < 0 || Age > 120)
	{
		printf("You gave an incorrect output \n");
		ageStudentFinder();
	}
	if (Age > 5 && Age < 30)
	{
		printf("Are you a Student or not? (0 for not, 1 for student): \n");
		scanf("%d", &StudOrNot);
		if (StudOrNot == 0 || StudOrNot == 1)
		{
		}
		else{
			printf("You gave an incorrect output \n");
			ageStudentFinder();
		}
	}
}

int discountFinder(int age, int stud) {
	int discount = 0;
    if(age == 18 && stud == 0) {
	    discount = 20;
    }
	if (age <= 18 || stud == 1) {
	    discount = 30;
    }
    if(age == 25 && stud == 1){
	    discount = 40;
    }
    if (age > 65 && age < 120) {
	    discount = 50;
    }
    return discount;
}

int main () {
	ageStudentFinder();
	printf( "Your discount is: %d \n", discountFinder(Age, StudOrNot));
	
	
}
