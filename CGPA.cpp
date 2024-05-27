#include<bits/stdc++.h>

using namespace std;

struct Course {
    string name;
    double marks;
    double grade;
    string letterGrade;
    int credit;
};

double convertMarksToGPA(double marks) {
    if (marks > 80) return 4.00;
    else if (marks > 75) return 3.75;
    else if (marks > 70) return 3.50;
    else if (marks > 65) return 3.25;
    else if (marks > 60) return 3.00;
    else if (marks > 55) return 2.75;
    else if (marks > 50) return 2.50;
    else if (marks > 45) return 2.25;
    else if (marks > 40) return 2.00;
    else if (marks > 32) return 1.75;
    else return 0.0;
}

string convertMarksToLetterGrade(double marks) {
    if (marks > 80) return "A+";
    else if (marks > 75) return "A";
    else if (marks > 70) return "A-";
    else if (marks > 65) return "B+";
    else if (marks > 60) return "B";
    else if (marks > 55) return "B-";
    else if (marks > 50) return "C+";
    else if (marks > 45) return "C";
    else if (marks > 40) return "C-";
    else if (marks > 32) return "D";
    else return "F";
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

        course.grade = convertMarksToGPA(course.marks);
        course.letterGrade = convertMarksToLetterGrade(course.marks);

        cout << "Enter the credit hours for " << course.name << ": ";
        cin >> course.credit;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        courses.push_back(course);
    }

    cout << "\nGrades and GPA for each course:\n";
    cout << "--------------------------------\n";
    for (const auto& course : courses) {
        cout << "Course: " << course.name
             << ", Marks: " << course.marks
             << ", GPA: " << fixed << setprecision(2) << course.grade
             << ", Letter Grade: " << course.letterGrade
             << ", Credit Hours: " << course.credit << endl;
    }

    double cgpa = calculateCGPA(courses);
    cout << "\nThe CGPA is: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
