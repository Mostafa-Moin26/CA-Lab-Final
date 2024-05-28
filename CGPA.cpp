#include<bits/stdc++.h>

using namespace std;

struct Course {
    string name;
    double marks;
    double grade;
    string letterGrade;
    int credit;
};

void convertMarksToGPA(double marks, double &grade, string &letterGrade) {
    if (marks > 80) {
        grade = 4.00, letterGrade = "A+";
    } else if (marks > 75) {
        grade = 3.75, letterGrade = "A";
    } else if (marks > 70) {
        grade = 3.50, letterGrade = "A-";
    } else if (marks > 65) {
        grade = 3.25, letterGrade = "B+";
    } else if (marks > 60){
        grade = 3.00, letterGrade = "B";
    } else if (marks > 55){
        grade = 2.75, letterGrade = "B-";
    } else if (marks > 50){
        grade = 2.50, letterGrade = "C+";
    } else if (marks > 45){
        grade = 2.25, letterGrade = "C";
    } else if (marks > 40){
        grade = 2.00, letterGrade = "C-";
    } else if (marks > 32){
        grade = 1.75, letterGrade = "D";
    } else {
        grade = 0.0, letterGrade = "F";
    }
}


double calculateCGPA(const vector<Course>& courses) {
    double totalGradePoints = 0.0;
    int totalCredit = 0;

    for (const auto& course : courses) {
        totalGradePoints += course.grade * course.credit;
        totalCredit += course.credit;
    }

    if (totalCredit == 0) {
        return 0.0;
    }

    return totalGradePoints / totalCredit;
}

int main() {
    vector<Course> courses;
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < numCourses; ++i) {
        Course course;

        cout << "Enter the name of course " << (i + 1) << ": ";
        getline(cin, course.name);

        cout << "Enter the marks for " << course.name << " (out of 100): ";
        cin >> course.marks;

       convertMarksToGPA(course.marks, course.grade, course.letterGrade);

        cout << "Enter the credit hours for " << course.name << ": ";
        cin >> course.credit;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        courses.push_back(course);
    }

    cout << "\nGrades and GPA for each course:\n";
    cout << "--------------------------------\n";
    for (const auto& course : courses) {
        cout << "Course: " << course.name << endl;
        cout << " Marks: " << course.marks << endl;
        cout << " GPA: " << fixed << setprecision(2) << course.grade << endl;
        cout << " Letter Grade: " << course.letterGrade << endl;
        cout << " Credit Hours: " << course.credit << endl;
    }

    double cgpa = calculateCGPA(courses);
    cout << "\nThe CGPA is: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
