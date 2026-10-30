#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    string regno;
    float marks;

    void inputdetails()
    {
        cout << "Enter student name: ";
        getline(cin >> ws, name);

        cout << "Enter registration number: ";
        cin >> regno;

        cout << "Enter marks: ";
        cin >> marks;
    }

    void displaydetails()
    {
        cout << "\nName: " << name;
        cout << "\nRegistration Number: " << regno;
        cout << "\nMarks: " << marks;
        cout << "\nGrade: " << getgrade() << "\n";
    }

    char getgrade()
    {
        if(marks >= 70)
            return 'A';
        else if(marks >= 60)
            return 'B';
        else if(marks >= 50)
            return 'C';
        else if(marks >= 40)
            return 'D';
        else
            return 'E';
    }
};

int main()
{
    Student students[50];
    int count = 0;
    int choice;

    do
    {
        cout << "\n=== STUDENT MANAGEMENT SYSTEM ===\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count < 50)
            {
                students[count].inputdetails();
                count++;
                cout << "Student Added Successfully!\n";
            }
            else
            {
                cout << "Student Limit Reached!\n";
            }
            break;

        case 2:
            if (count == 0)
            {
                cout << "No Student Registered.\n";
            }

            for (int i = 0; i < count; i++)
            {
                students[i].displaydetails();
            }
            break;

        case 3:
            {
                string searchReg;
                bool found = false;

                cout << "Enter registration number: ";
                cin >> searchReg;

                for (int i = 0; i < count; i++)
                {
                    if (students[i].regno == searchReg)
                    {
                        students[i].displaydetails();
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Student Not Found!\n";
                }
                break;
            }

        case 4:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }
    } while(choice != 4);

    return 0;
}
