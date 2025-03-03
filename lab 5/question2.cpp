#include <iostream>
#include <stdexcept> 
using namespace std;

class LoanHelper {
    const float rateOfInterest;
    float principalAmount;
    int numberOfMonths;
    float totalLoanAmount;

public:
    LoanHelper(float rate, float amount, int months) 
        : rateOfInterest(rate), principalAmount(amount), numberOfMonths(months) {
        if (rate < 0 || rate > 0.5) {
            throw invalid_argument("Invalid interest rate.");
        }
    }

    void calculateLoan() {
        float monthlyPayment;
        monthlyPayment = principalAmount / numberOfMonths;
        monthlyPayment = monthlyPayment * (1 + rateOfInterest);
        cout << "You have to pay " << monthlyPayment << " every month for " << numberOfMonths << " months.";
    }
};

int main() {
    LoanHelper loan1(0.3, 2000, 4);
    loan1.calculateLoan();
}
