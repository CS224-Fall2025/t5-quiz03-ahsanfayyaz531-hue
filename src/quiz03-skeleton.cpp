#include <iostream>
using namespace std;


class Employee{
    private:
        static int empcount;
    protected:
        string name;
        double salary;
    public:
        Employee(string n, double s): name(n), salary(s){
            empcount+=1;
        }

        virtual void displayinfo(){
            cout << "Name: " << name << endl;
            cout << "Salary: " << salary << endl;
        }

        static int showtotalemployee(){
            return empcount;
        }

        virtual ~ Employee(){
            cout << "Destroy Employee" << endl;
        }

};

int Employee::empcount = 0;

class staff: public Employee{
    private:
        string department;
    public:
        staff(string n, double s, string d): Employee(n,s), department(d){


        }
        void displayinfo() override{
            cout << "Name: " << name << endl;
            cout << " (" << department <<") ";
            cout << "Salary: " << salary << endl;
        }

        ~staff(){
            cout << "destroy staff"<< endl;
        }
};

class faculty: public Employee{
    private:
        string department;
    public:
        faculty(string n, double s, string d): Employee(n,s), department(d){

        }

        void displayinfo() override{
            cout << "Name: " << name << endl;
            cout << " (" << department <<") ";
            cout << "Salary: " << salary << endl;
        }

        ~faculty(){
            cout << "destroy faculty"<< endl;
        }
};




int main() {
    int n;
    cout << "How many numbers of employee? " << endl;
    cin >> n;
    Employee* emp[n];
    //assuming that n = 2;
    int x = Employee::showtotalemployee();
    cout << "Total employees: " << x << endl;
    emp[0] = new staff("Ali", 7500, "staff");
    emp[1] = new faculty("Salman", 8000, "faculty");
    for(int i = 0; i < n; i++){
        emp[i] -> displayinfo();
    }
    for(int i = 0; i < n; i++){
        delete emp[i];
    }



}