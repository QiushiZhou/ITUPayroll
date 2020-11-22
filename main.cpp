#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class Employee {
public:
    int empcode;
    string name;
    string addr;
    string phno;
    string date;
    string desg;
    string grade;
    double loan;
    double bs; //basic salary
    double hs; //house allowance
    Employee(int empcode = 0,
             string name = "",
             string addr = "",
             string phno = "",
             string date = "",
             string desg = "",
             string grade = "",
             double loan = 0,
             double bs = 0,
             double hs = 0
    ) {

        this->empcode = empcode;
        this->name = name;
        this->addr = addr;
        this->phno = phno;
        this->date = date;
        this->desg = desg;
        this->grade = grade;
        this->loan = loan;
        this->bs = bs;
        this->hs = hs;
    }

    void input() {

        cout << "Enter empcode: ";
        cin >> empcode;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, addr);
        cout << "Enter Phone Number: ";
        getline(cin, phno);
        cout << "Enter Date (dd/mm/yy): ";
        getline(cin, date);
        cout << "Enter Designation: ";
        getline(cin, desg);
        cout << "Enter Grade: ";
        getline(cin, grade);
        cout << "Enter Loan: ";
        cin >> loan;
        cout << "Enter Basic Salary: ";
        cin >> bs;
        cout << "Enter House Allowance: ";
        cin >> hs;
    }

    void display() {

        cout << "Empcode: ";
        cout << empcode;
        cout << "Name: " << name << endl;
        cout << "Address: " << addr << endl;
        cout << "Phone Number: " << phno << endl;
        cout << "Date(dd/mm/yy): " << date << endl;
        cout << "Designation : " << desg << endl;
        cout << "Grade: " << grade << endl;
        cout << "Loan: " << loan << endl;
        cout << "Basic Salary: " << bs << endl;
        cout << "House Allowance: " << hs << endl;

    }

    void writeToFile() {
        fstream fout;
        fout.open("Employee.txt", fstream::out | fstream::app);
        fout << "Empcode: ";
        fout << empcode;
        fout << "Name: " << name << endl;
        fout << "Address: " << addr << endl;
        fout << "Phone Number: " << phno << endl;
        fout << "Date(dd/mm/yy): " << date << endl;
        fout << "Designation : " << desg << endl;
        fout << "Grade: " << grade << endl;
        fout << "Loan: " << loan << endl;
        fout << "Basic Salary: " << bs << endl;
        fout << "House Allowance: " << hs << endl;

        fout.close();
    }

    void printSlip() {
        int days;
        int hours;
        cout << "Enter number of Days Employee Worked: ";
        cin >> days;
        cout << "Enter number of Hours Employee Worked: ";
        cin >> hours;
        //rate per hour
        double gross = (bs + hs) / 176; //20 days per month and 8 hours a day
        //net gross per month
        gross = gross * (days * hours);
        //tax 15% of salary
        double tax = gross * 0.15;
        cout << "GROSS SALARY: " << gross << endl;
        cout << "TAX AT 15%: " << tax << endl;
        cout << "NET : " << gross - tax << endl;
    }
};

class ManagementSystem {
public:
    vector<Employee> emp;

    void display() {
        for (int i = 0; i < emp.size(); ++i) {
            emp[i].display();
        }
    }

    Employee *search() {
        int empCode;
        cout << "Enter an Employee Code: ";
        cin >> empCode;
        for (int i = 0; i < emp.size(); ++i) {
            if (emp[i].empcode == empCode)
                return &emp[i];
        }
        return NULL;
    }

    bool del() {
        int empCode;
        cout << "Enter an Employee Code: ";
        cin >> empCode;
        for (int i = 0; i < emp.size(); ++i) {
            if (emp[i].empcode == empCode) {
                //erase ith element from array
                emp.erase(emp.begin() + i);
                return true;
            }
        }
        return false;
    }
};

int main() {
    ManagementSystem M;
    ofstream f("Employee.txt");
    f.close();
    int choice = 0;
    while (choice != 8) {
        cout << "1. Add New Employee\n";
        cout << "2. Modify Employee Record\n";
        cout << "3. Delete Employee Record\n";
        cout << "4. Print Salary Slip\n";
        cout << "5. Display an Employee Record\n";
        cout << "6. Display List of Employee\n";
        cout << "7. Write to File\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                Employee E;
                E.input();
                M.emp.push_back(E);
            }
                break;
            case 2: {
                Employee *E = M.search();
                if (E != NULL)
                    E->input();
                else
                    cout << "Employee not found\n";
            }
                break;
            case 3: {
                bool result = M.del();
                if (result)
                    cout << "SUCCESSFUL DELETE\n";
                else
                    cout << "Employee not found\n";
            }
                break;
            case 4: {
                Employee *E = M.search();
                if (E != NULL)
                    E->printSlip();
                else
                    cout << "Employee not found\n";

            }
                break;
            case 5: {
                Employee *E = M.search();
                if (E != NULL)
                    E->display();
                else
                    cout << "Employee not found\n";

            }
                break;
            case 6: {
                M.display();
            }
                break;
            case 7: {
                for (int i = 0; i < M.emp.size(); ++i)
                    M.emp[i].writeToFile();
            }
                break;
            case 8: {
                cout << "BYE!!!\n";
            }
                break;
            default:
                cout << "Enter a valid choice\n";
        }
    }
    return 0;

}