// ============================================================

// Lab W7: C++ OOP Review - Classes, Encapsulation, Strings,

//         Copy Constructors, Operator Overloading

// ============================================================

#include <iostream>

#include <string>

#include <cstring>

using namespace std;

class Student {

private:

   string name;

   int id;

   double gpa;

public:

   // ----- Task 1: Constructors & Destructor -----

   Student() {

       // Initialize default values

       name = "Unknown";

       id = 0;

       gpa = 0.0;

   }

   Student(string n, int i, double g) {

       // Initialize all member variables

       name = n;

       id = i;

       gpa = g;

   }

   Student(const Student& other) {

       // Copy constructor (memberwise copy is sufficient here)

       name = other.name;

       id = other.id;

       gpa = other.gpa;

   }

   ~Student() {

       // Destructor with required format

       cout << "Student " << name << " destroyed" << endl;

   }

   // ----- Task 2: Getters -----

   string getName() const {

       return name;

   }

   int getId() const {

       return id;

   }

   double getGpa() const {

       return gpa;

   }

   // ----- Task 3: Setters with Validation -----

   void setName(string n) {

       // Name must not be empty

       if (!n.empty()) {

           name = n;

       }

   }

   void setGpa(double g) {

       // GPA must be between 0.0 and 4.0 (inclusive)

       if (g >= 0.0 && g <= 4.0) {

           gpa = g;

       }

   }

   // ----- Task 4: String Operation -----

   string getFormattedName() const {

       string upperName = name;

       // Convert each character to uppercase (safe cast)

       for (int i = 0; i < upperName.length(); i++) {

           upperName[i] = (char)toupper(upperName[i]);

       }

       return upperName;

   }

   // ----- Task 5: Operator Overloading -----

   bool operator==(const Student& other) const {

       // Students are equal if IDs match

       return id == other.id;

   }

   bool operator<(const Student& other) const {

       // Compare based on GPA

       return gpa < other.gpa;

   }

   friend ostream& operator<<(ostream& os, const Student& s) {

       // Output formatted student info

       os << "Student(" << s.name << ", ID: " << s.id << ", GPA: " << s.gpa << ")";

       // Return stream to allow chaining

       return os;

   }

};

// ================================

// Function Overloading

// ================================

Student findBestStudent(const Student& a, const Student& b) {

   // Return student with higher (or equal) GPA

   if (a < b ){

       return b;

   }

   return a ;

}

Student findBestStudent(Student arr[], int size) {

   // Find student with highest GPA

   Student best = arr[0];

   for (int i = 1; i < size; i++) {

       if (arr[i].getGpa() > best.getGpa()) {

           best = arr[i];

       }

   }

   return best;

}

// ================================

// MAIN

// ================================

int main() {

   Student s1;

   cout << "Default: " << s1 << endl;

   Student s2("Ali", 101, 3.5);

   Student s3("Ayse", 102, 3.8);

   cout << "s2: " << s2 << endl;

   cout << "s3: " << s3 << endl;

   Student s4(s2);

   cout << "Copy of s2: " << s4 << endl;

   cout << "s3 name: " << s3.getName() << endl;

   cout << "s3 GPA: " << s3.getGpa() << endl;

   s2.setGpa(5.0);

   cout << "s2 after invalid setGpa(5.0): " << s2 << endl;

   s2.setGpa(3.9);

   cout << "s2 after valid setGpa(3.9): " << s2 << endl;

   cout << "Formatted: " << s3.getFormattedName() << endl;

   cout << "s2 == s4? " << (s2 == s4 ? "Yes" : "No") << endl;

   cout << "s2 < s3? " << (s2 < s3 ? "Yes" : "No") << endl;

   Student best2 = findBestStudent(s2, s3);

   cout << "Best of two: " << best2 << endl;

   Student roster[] = {s1, s2, s3, s4};

   Student bestAll = findBestStudent(roster, 4);

   cout << "Best of all: " << bestAll << endl;

   return 0;

}
 
