#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Student {
    private:
    int rollno,age;
    string name;

    public:
    Student(int stdRollNo,string stdName,int stdAge)
    {
        rollno = stdRollNo;
        name = stdName;
        age = stdAge;
    }

    void setRollNo(int stdRollNo) {
        rollno = stdRollNo;
    }
    int getRollNo() {
        return rollno;
    }

    void setName(string stdName) {
        name = stdName;
    }
    string getName() {
        return name;
    }

    void SetAge(int stdAge) {
        age = stdAge;
    }
    int getAge() {
        return age;
    }

    void displayStudent() {
        cout<<"Roll No : "<<rollno<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }
};

//ADDING A NEW STUDENT TO THE DATABASE
void addNewStudent(vector<Student> &Students) {
    int rollno,age;
    string name;

    cout<<"Enter Roll No : ";
    cin>>rollno;
    for(int i=0; i<Students.size(); i++)
    {
        if(Students[i].getRollNo() == rollno)
        {
            cout<<"STUDENT WITH THIS ROLL NO ALREADY EXISTS";
            return;
        }
    }

    cout<<"Enter Name : ";
    cin>>name;

    cout<<"Enter Age :";
    cin>>age;

    Student s(rollno,name,age);
    Students.push_back(s);
    fstream fout;
    fout.open("StudentDatabase.txt",ios::out);
    if(!fout) 
    {
        cout<<"ERROR IN CREATING FILE !!"<<endl;
    }
    else
    {
        cout<<"FILE CREATED SUCCESSFULLY"<<endl;
        s.displayStudent();
        fout.write((char*)&s,sizeof(s));
    }
    fout.close();
    cout<<"DATA STORED AND FILE CLOSED SUCCESSFULLY"<<endl;

    cout<<"STUDENT DETAIL STORED IN THE DATABASE SUCCESSFULLY"<<endl;
}

//DISPLAYING THE LIST OF ALL STUDENTS
void DisplayAllStudents(vector<Student> &Students) {
    if(Students.empty()) {
        cout<<"NO STUDENTS RECORD FOUND"<<endl;
        return;
    }

    for(int i=0; i<Students.size(); i++)
    {
        Students[i].displayStudent();
        cout<<endl<<endl;
    }
}

//SEARCH FOR A STUDENT
void SearchStudent(vector<Student> &Students) {
    int rollno;
    cout<<"Enter Roll No : ";
    cin>>rollno;

    for(int i=0; i<Students.size(); i++) {
        if(Students[i].getRollNo() == rollno) {
            cout<<"-------------STUDENT FOUND !!!!-------------"<<endl;
            Students[i].displayStudent();
            return;
        }
    }
}

//UPDATION OF A STUDENT'S RECORD
void UpdateStudent(vector<Student> &Students) {
    int rollno;
    string name;
    cout<<"Enter a Roll No : ";
    cin>>rollno;
    cout<<"Enter a name : ";
    cin.ignore();
    cin>>name;

    for(int i=0; i<Students.size(); i++) {
        if(Students[i].getRollNo() == rollno & Students[i].getName() == name)
        {
            int newRollNo,newAge;
            string newName;
            cout<<"Enter a new Roll No : ";
            cin>>newRollNo;
            Students[i].setRollNo(newRollNo); 

            cout<<"Enter a new name : ";
            cin>>newName;
            Students[i].setName(newName);

            cout<<"Enter a new age :";
            cin>>newAge;
            Students[i].SetAge(newAge);

            return;
        }
    }
}

//DELETING A RECORD OF THE STUDENT
void DeleteStudent(vector<Student> &Students) {
    int rollno;
    string name;
    cout<<"Enter a roll no: ";
    cin>>rollno;
    cout<<"Enter a name: ";
    cin>>name;

    for(int i=0; i<Students.size(); i++) {
        if(Students[i].getRollNo() == rollno && Students[i].getName() == name) {
            Students.erase((Students.begin()+i));
            cout<<" STUDENT REMOVED SUCCESSFULLY "<<endl;
        }
    }
}

int main() {
    vector<Student> Students;
    char choice;

    do {
        system("cls");
        int op;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"STUDENT MANAGEMENT SYSTEM "<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<" 1. ADD A NEW STUDENT"<<endl;
        cout<<" 2. DISPLAY LIST OF ALL STUDENTS"<<endl;
        cout<<" 3. SEARCH FOR A STUDENT"<<endl;
        cout<<" 4. UPDATE THE DETAILS OF A STUDENT"<<endl;
        cout<<" 5. DELETE THE RECORD OF A STUDENT"<<endl;
        cout<<" 6. EXIT"<<endl;
        cin>>op;
        
        switch (op)
        {
        case 1:
            addNewStudent(Students);
            break;
        
        case 2:
            DisplayAllStudents(Students);
            break;

        case 3:
            SearchStudent(Students);
            break;

        case 4:
            UpdateStudent(Students);
            break;

        case 5:
            DeleteStudent(Students);
            break;

        case 6:
            exit(1);
            break;

        default:
            cout<<"INVALID OPTION NUMBER. PLEASE SELECT FROM 1-6.";
            break;
        }

        cout<<"DO YOU WANT TO CONTINUE ? [Y/N]";
        cin>>choice;
    }   while (choice == 'Y' || choice =='y');

    return 0;
}