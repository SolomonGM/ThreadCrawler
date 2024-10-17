#include <iostream>
#include <vector>

int main() {
    //Test case grades
    std::vector<int> grades = {100, 98, 15, 30, 25, 70, 82, 66, 78, 40};
    
    // Array to store the count for each cluster
    int clusters[10] = {0};  // Initialize all counts to zero
    
    for (int grade : grades) {
        if (grade >= 0 && grade <= 100) {
            // Determine which cluster the grade falls into
            ++clusters[grade / 10];
        }
    }
    
    // Output the cluster counts
    for (int count : clusters) {
        std::cout << count;
    }
    
    std::cout << std::endl;
    
    return 0;
}
