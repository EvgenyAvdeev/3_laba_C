#include <stdio.h>
#include <math.h>


unsigned long long int fact(int m) {
    if (m == 0)
        return 1;
    return(m * fact(m - 1));
}



int main() {

    int m, flag, step = 0;
    float x, sum = 0, acc, sum_l = -1; 
    printf("Enter 1 if you want to calculate with a given accuracy, 2 if you want to calculate with a given number of steps: ");
    scanf_s("%d", &flag);

    switch (flag)
    {
    case 1:
        printf("Enter the number and the accuracy of the calculation: ");
        scanf_s("%f %f", &x, &acc); 
        if (acc < 0) {
            printf("ERROR\n");
            break;
        }
        for (step; ; step++) {
            
            sum += (pow(x,2* step)) / (fact(2*step));
            if (sum - sum_l <= acc) {
                break;
            }
            printf("%f\t%f\n", sum_l, sum); 
            sum_l = sum; 
        }
        printf("%f\t%f\n", sum_l, sum);  
        printf("Taylor series - ch(%f) = %f\n", x, sum); 
        printf("math.h - ch(%f) = %f\n", x, cosh(x)); 
        break;

    case 2:
        printf("Enter the number and number of steps: ");
        scanf_s("%f %d", &x, &m);
        if (m < 0) {
            printf("ERROR\n");
            break;
        }
        for (int i = 0; i < m; i++) {
            sum += (pow(x, 2 * i)) / (fact(2 * i)); 
        }
        printf("Taylor series - ch(%f) = %f\n", x, sum);
        printf("math.h - ch(%f) = %f\n", x, cosh(x));
        break;

    default:
        printf("ERROR\n");
    }


	return 0;
}

