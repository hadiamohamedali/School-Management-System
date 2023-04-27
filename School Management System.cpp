#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Student
{
      public :
      char name[100];
      int age , id , degree;
};
class Teacher
{
public :
    char name[100];
    char subject[100];
    int age , id;
};
void writeStudent()
{
   fstream outfile1;
   outfile1.open("Student.txt" , ios::out | ios::app);
   Student s; char x;
   do
   {
       cout << "Enter The Name Of Student : ";
       cin >> s.name; cout << endl;
       cout << "Enter The Age Of Student : ";
       cin >> s.age; cout << endl;
       cout << "Enter The ID Of Student : ";
       cin >> s.id; cout << endl;
       cout << "Enter The Degree Of Student : ";
       cin >> s.degree; cout << endl;
       //write file
       outfile1.write((char*)&s , sizeof(s));
       cout << "Enter Any Record Again(Y / N) : ";
       cin >> x; cout << endl;
   }while(x == 'Y');
   outfile1.close();
}
void readStudent()
{
    ifstream in1; Student s;
    in1.open("Student.txt" ,ios::in);
    if(in1.is_open())
    {
       cout << "Name\tAge\tID\tDegree"  << endl;
       in1.read((char*)&s , sizeof(s));
       while(!in1.eof())
       {
           cout << s.name << "\t" << s.age << "\t" << s.id << "\t" << s.degree << endl;
           in1.read((char*)&s , sizeof(s));
       }
       in1.close();
    }
    else
    {
        cout << "------File Not Found------" << endl;
    }
}
void searchStudent()
{
  char str[100];
  cout << "Enter The Name Search For : ";
  cin >> str; cout << endl;
  bool found = false;
  ifstream in1; Student s;
  in1.open("Student.txt" , ios::in);
  if(in1.is_open())
  {
      in1.read((char*)&s , sizeof(s));
      while(!in1.eof())
      {
          if(strcmp(str , s.name) == 0)
          {
              cout << "Name\tAge\tID\tDegree" << endl;
              cout << s.name << "\t" << s.age << "\t" << s.id << "\t" << s.degree << endl;
              found = true;
          }
          in1.read((char*)&s , sizeof(s));
      }
      if(!found)
      {
        cout << "----Name Not Found----" << endl;
      }
      in1.close();
  }
  else
  {
      cout << "----File Not Found----" << endl;
  }
}
void UpdateStudent()
{
    char str[100];
    cout << "Enter The Name Update For : ";
    cin >> str; cout << endl;
    bool found = false;
    fstream in1; Student s;
    in1.open("Student.txt", ios::in | ios::out);
    if(in1.is_open())
    {
        in1.read((char*)&s , sizeof(s));
        while(!in1.eof())
        {
            if(strcmp(str , s.name) == 0)
            {
               cout << "Enter The New Degree For : " << str << endl;
               cin >> s.degree;
               int CurPos = in1.tellg();
               int StuSize = sizeof(s);
               in1.seekp(CurPos - StuSize , ios::beg);
               in1.write((char*) &s , sizeof(s));
               in1.seekg(CurPos - StuSize , ios::beg);
               in1.read((char*) &s , sizeof(s));
               cout << "Name\tAge\tID\tDegree" << endl;
               cout << s.name <<"\t"<<s.age<<"\t"<<s.id<<"\t"<<s.degree<<endl;
               found = true;
               break;
            }
            in1.read((char*)&s , sizeof(s));
        }
        if(!found)
        {
            cout << "----Name Not Found----" << endl;
        }
        in1.close();
    }
    else
    {
        cout << "----File Not Found----" << endl;
    }
}
void DeleteStudent()
{


     char str[100];
     cout << "Enter The Name Delete For : ";
     cin >> str; cout << endl;
     bool found = false;
     Student s;
     ifstream in1("Student.txt", ios::in);
     ofstream out1("NewStudent.txt" , ios::out | ios::app);
    if(in1.is_open())
    {
        in1.read((char*)&s , sizeof(s));
        while(!in1.eof())
        {
            if(strcmp(str , s.name) != 0)
            {
              out1.write((char*)&s , sizeof(s));
              found = true;
            }
            in1.read((char*)&s , sizeof(s));
        }
        if(!found)
        {
            cout << "----Name Not Found----" << endl;
        }
        in1.close();
        out1.close();
        remove("Student.txt");
        rename("NewStudent.txt" , "Student.txt");
    }
    else
    {
        cout << "----File Not Found----" << endl;
    }
  readStudent();

}
void writeTeacher()
{
   fstream outfile1;
   outfile1.open("Teacher.txt" , ios::out | ios::app);
   Teacher t; char x;
   do
   {
       cout << "Enter The Name Of Teacher : ";
       cin >> t.name; cout << endl;
       cout << "Enter The Age Of Teacher : ";
       cin >> t.age; cout << endl;
       cout << "Enter The ID Of Teacher : ";
       cin >> t.id; cout << endl;
       cout << "Enter The Subject Of Teacher : ";
       cin >> t.subject; cout << endl;
       //write file
       outfile1.write((char*)&t , sizeof(t));
       cout << "Enter Any Record Again(Y / N) : ";
       cin >> x; cout << endl;
   }while(x == 'Y');
   outfile1.close();
}
void readTeacher()
{
     ifstream in1; Teacher t;
    in1.open("Teacher.txt" ,ios::in);
    if(in1.is_open())
    {
       cout << "Name\tAge\tID\tSubject"  << endl;
       in1.read((char*)&t , sizeof(t));
       while(!in1.eof())
       {
           cout << t.name << "\t" << t.age << "\t" << t.id << "\t" << t.subject << endl;
           in1.read((char*)&t , sizeof(t));
       }
       in1.close();
    }
    else
    {
        cout << "------File Not Found------" << endl;
    }
}
void searchTeacher()
{
   char str[100];
  cout << "Enter The Name Search For : ";
  cin >> str; cout << endl;
  bool found = false;
  ifstream in1; Teacher t;
  in1.open("Teacher.txt" , ios::in);
  if(in1.is_open())
  {
      in1.read((char*)&t , sizeof(t));
      while(!in1.eof())
      {
          if(strcmp(str , t.name) == 0)
          {
              cout << "Name\tAge\tID\tsubject" << endl;
              cout << t.name << "\t" << t.age << "\t" << t.id << "\t" << t.subject<< endl;
              found = true;
          }
          in1.read((char*)&t , sizeof(t));
      }
      if(!found)
      {
        cout << "----Name Not Found----" << endl;
      }
      in1.close();
  }
  else
  {
      cout << "----File Not Found----" << endl;
  }
}
void updateTeacher()
{
     char str[100];
    cout << "Enter The Name Update For : ";
    cin >> str; cout << endl;
    bool found = false;
    fstream in1; Teacher t;
    in1.open("Teacher.txt", ios::in | ios::out);
    if(in1.is_open())
    {
        in1.read((char*)&t , sizeof(t));
        while(!in1.eof())
        {
            if(strcmp(str , t.name) == 0)
            {
               cout << "Enter The New ID For : " << str << endl;
               cin >> t.id;
               int CurPos = in1.tellg();
               int techSize = sizeof(t);
               in1.seekp(CurPos - techSize , ios::beg);
               in1.write((char*) &t , sizeof(t));
               in1.seekg(CurPos - techSize , ios::beg);
               in1.read((char*) &t , sizeof(t));
               cout << "Name\tAge\tID\tSubject" << endl;
               cout << t.name <<"\t"<<t.age<<"\t"<<t.id<<"\t"<<t.subject<<endl;
               found = true;
               break;
            }
            in1.read((char*)&t , sizeof(t));
        }
        if(!found)
        {
            cout << "----Name Not Found----" << endl;
        }
        in1.close();
    }
    else
    {
        cout << "----File Not Found----" << endl;
    }
}
void deleteTeacher()
{
         char str[100];
     cout << "Enter The Name Delete For : ";
     cin >> str; cout << endl;
     bool found = false;
     Teacher t;
     ifstream in1("Teacher.txt", ios::in);
     ofstream out1("NewTeacher.txt" , ios::out | ios::app);
    if(in1.is_open())
    {
        in1.read((char*)&t , sizeof(t));
        while(!in1.eof())
        {
            if(strcmp(str , t.name) != 0)
            {
              out1.write((char*)&t , sizeof(t));
              found = true;
            }
            in1.read((char*)&t , sizeof(t));
        }
        if(!found)
        {
            cout << "----Name Not Found----" << endl;
        }
        in1.close();
        out1.close();
        remove("Teacher.txt");
        rename("NewTeacher.txt" , "Teacher.txt");
    }
    else
    {
        cout << "----File Not Found----" << endl;
    }
  readTeacher();

}
int main()
{
   cout << "\t\t\t\t\t========School Management System========" << endl;
     cout << "**************Your Choise************" << endl;
     int choise;
      do
     {
         cout << "1.Write Student\t\t 2.Read Student\n3.Search Student\t4.Update Student\n5.Delete Student\t";
         cout << "6.Write Teacher\n7.Read Teacher\t\t8.Search Teacher\n9.Update Teacher\t10.Delete Teacher" << endl;
         cin >> choise;
         switch(choise)
         {
         case 1:
            writeStudent();
            break;
         case 2:
            readStudent();
            break;
         case 3:
            searchStudent();
            break;
         case 4:
            UpdateStudent();
            break;
         case 5:
            DeleteStudent();
            break;
         case 6:
            writeTeacher();
            break;
         case 7:
            readTeacher();
            break;
         case 8:
           searchTeacher();
            break;
         case 9:
            updateTeacher();
            break;
         case 10:
            deleteTeacher();
            break;
         case 11:
            cout << "==========Thank You=========" << endl;
         }
     }while(choise != 11);



    return 0;
}
