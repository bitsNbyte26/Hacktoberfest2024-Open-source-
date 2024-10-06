#include <bits/stdc++.h>
using namespace std;

// Base class: Employee
class Employee
{
protected:
    int id, deptId;
    string name;
    double basicSalary;

public:
    // Constructor to initialize Employee details
    Employee(int empId, string empName, int empDeptId, double empBasicSalary)
        : id(empId), name(empName), deptId(empDeptId), basicSalary(empBasicSalary) {}

    // Virtual method to compute net salary
    virtual double computeNetSalary()
    {
        return 0;
    }

    // Display employee details
    void displayDetails()
    {
        cout << "Employee ID: " << id << "\nName: " << name << "\nDepartment ID: " << deptId << "\nBasic Salary: â‚¹" << basicSalary << endl;
    }
};

//--------------------------------------------------------------------------------------------------Derived class: Manager
class Manager : public Employee
{
private:
    double perfBonus;

public:
    // Constructor to initialize Manager details
    Manager(int empId, string empName, int empDeptId, double empBasicSalary, double empPerfBonus)
        : Employee(empId, empName, empDeptId, empBasicSalary), perfBonus(empPerfBonus) {}

    // Override computeNetSalary for Manager (basicSalary + perfBonus)
    double computeNetSalary() override
    {
        return basicSalary + perfBonus;
    }
};

//---------------------------------------------------------------------------------------------------Derived class: Worker
class Worker : public Employee
{
private:
    int hoursWorked;
    double hourlyRate;

public:
    // Constructor to initialize Worker details
    Worker(int empId, string empName, int empDeptId, double empBasicSalary, int empHoursWorked, double empHourlyRate)
        : Employee(empId, empName, empDeptId, empBasicSalary), hoursWorked(empHoursWorked), hourlyRate(empHourlyRate) {}

    // Override computeNetSalary for Worker (basicSalary + (hoursWorked * hourlyRate))
    double computeNetSalary() override
    {
        return basicSalary + (hoursWorked * hourlyRate);
    }

    // Method to return the hourly rate of the worker
    double getHourlyRate()
    {
        return hourlyRate;
    }
};

int main()
{
    // Create Manager object
    // Manager mgr(101, "MgrObj", 201, 50000, 15000);

    // Create Worker object
    // Worker wrk(102, "WorObj", 202, 30000, 40, 500);

    vector<Employee *> employees;

    int ch;
    do
    {
        cout << "1. Hire manager , 2. Hire worker 3.Display Employee Details 4.exit " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            // Display Manager details and compute net salary
            // mgr.displayDetails();
            int id;
            string name;
            int deptId;
            double basicSalary, perfBonus;
            cout << "Enter Manager ID, Name, Department ID, Basic Salary, Performance Bonus: ";
            cin >> id >> ws;
            getline(cin, name);
            cin >> deptId >> basicSalary >> perfBonus;
            employees.push_back(new Manager(id, name, deptId, basicSalary, perfBonus));
            cout << "Manager hired successfully.\n";
            break;
        }
        case 2:
        {
           
            int id;
            string name;
            int deptId;
            double basicSalary;
            int hoursWorked;
            double hourlyRate;
            cout << "\nEnter Worker Details:" << endl;
            cin >> id >> ws;
            getline(cin, name);
            cin >> deptId >> basicSalary >> hoursWorked >> hourlyRate;
            employees.push_back(new Worker(id, name, deptId, basicSalary, hoursWorked, hourlyRate));
            cout << "worker hired successfully" << endl;

            break;
        }
        case 3:
        {
            if (employees.empty())
            {
                cout << "No record found" << endl;
            }
            else
            {
                for (int i = 0; i < employees.size(); ++i)
                {
                    employees[i]->displayDetails();
                    cout << employees[i] << endl;
                }
            }
            // cout << "Net Salary of Manager: â‚¹" << mgr.computeNetSalary() << endl;
            // cout << "Net Salary of Worker: â‚¹" << wrk.computeNetSalary() << endl;
            break;
        }
        case 4:
            break;
        }
    } while (ch != 4);
    return 0;
}
