#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Students {
private:
    int id;
    string name;
    int age;
    float test1, test2;
    float midterm;
    float finalExam;
    float totalScore;
    float attendance;
public:
    Students(int studentId, const string& studentName, int studentAge,
            double t1, double t2, double att, double mid, double finalEx)
        : id(studentId), name(studentName), age(studentAge),test1(t1), test2(t2), attendance(att),midterm(mid), finalExam(finalEx) {
        calculateTotalScore();
    }
    void calculateTotalScore(){
        totalScore = test1 + test2 + attendance + midterm + finalExam;
    }
    int getId();
    void setId(int id);
    string getName();
    void setName(string name);
    int getAge();
    void setAge(int age);
    float getTest1();
    void setTest1(float test1);
    float getTest2();
    void setTest2(float test2);
    float getMidterm();
    void setMidterm(float midterm);
    float getFinalExam();
    void setFinalExam(float finalExam);
    float getAttendance();
    void setAttendance(float attendance);
    float getTotalScore();
    void setTotalScore(){
         this->totalScore = this->test1 + this->test2 + this->attendance + this->midterm + this->finalExam;
    }

};
vector<Students> student;
int Students::getId(){
    return this->id;
}
void Students::setId(int id) {
    this->id = id;
}
string Students::getName(){
    return this->name;
}
void Students::setName(string Name) {
    this->name = Name;
}
int Students::getAge(){
    return this->age;
}
void Students::setAge(int age) {
    this->age = age;
}
float Students::getTest1(){
    return this->test1;
}
void Students::setTest1(float test1) {
    this->test1 = test1;
}
float Students::getTest2(){
    return this->test2;
}
void Students::setTest2(float test2) {
    this->test2 = test2;
}
float Students::getAttendance(){
    return this->attendance;
}
void Students::setAttendance(float attendance) {
    this->attendance = attendance;
}
float Students::getMidterm(){
    return this->midterm;
}
void Students::setMidterm(float midterm) {
    this->midterm = midterm;
}
float Students::getFinalExam(){
    return this->finalExam;
}
void Students::setFinalExam(float finalExam ) {
    this->finalExam = finalExam;
}
float Students::getTotalScore(){
    return this->totalScore;
}


int findIdStudent(int id){
    int findId;
    for(int i=0;i<student.size();i++){
        if(student[i].getId()==id){
            findId = i;
        }
    }
    return findId;
}

void view (){
    cout<<"==========================================================\n";
    cout<<"                          Menu                            \n";
    cout<<"==========================================================\n";
    cout<<"1. Them thong tin sinh vien\n";
    cout<<"2. Xoa thong tin sinh vien\n";
    cout<<"3. Cap nhat thong tin sinh vien\n";
    cout<<"4. Quan sat tat ca thong tin sinh vien\n";
    cout<<"5. Tinh diem trung binh cua mot sinh vien da chon\n";
    cout<<"6. Hien thi sinh vien co tong diem cao nhat\n";
    cout<<"7. Hien thi sinh vien co tong diem thap nhat\n";
    cout<<"8. Tim sinh vien boi ID\n";
    cout<<"9. Sap xep cac thong tin boi tong diem thi cua sinh vien\n";
    cout<<"0. Thoat chuong trinh\n";
    cout<<"Nhap lua chon cua ban:\n";
    cout<<"==========================================================\n";

}

void insertStudent(int &id){
    cout<<"Nhap cho sinh vien co id : "<<id<<"\n";
    string name;
    int age;
    float test1,test2,attendance,midterm,finalExam;
    cout<<"Nhap ten sinh vien : ";
    cin.ignore();
    getline(cin,name);
    cout<<"Nhap tuoi : ";
    cin>>age;
    cout<<"Nhap diem kiem tra lan 1 :";
    cin>>test1;
    cout<<"Nhap diem kiem tra lan 2 :";
    cin>>test2;
    cout<<"Nhap diem chuyen can : ";
    cin>>attendance;
    cout<<"Nhap diem kiem tra giua ki : ";
    cin>>midterm;
    cout<<"Nhap diem kiem tra cuoi ki :";
    cin>>finalExam;
    student.push_back(Students(id,name,age,test1,test2,attendance,midterm,finalExam));
    id++;

}
void showStudent(int i){
        cout<<"Id : ";
        cout<<student[i].getId()<<" \n";
        cout<<"Ten : ";
        cout<<student[i].getName()<<" \n";
        cout<<"Tuoi : ";
        cout<<student[i].getAge()<<" \n";
        cout<<"Diem kiem tra lan 1 : ";
        cout<<student[i].getTest1()<<" \n";
        cout<<"Diem kiem tra lan 2 : ";
        cout<<student[i].getTest2()<<" \n";
        cout<<"Diem chuyen can : ";
        cout<<student[i].getAttendance()<<" \n";
        cout<<"Diem kiem tra giua ki : ";
        cout<<student[i].getMidterm()<<" \n";
        cout<<"Diem kiem tra cuoi ki : ";
        cout<<student[i].getFinalExam()<<" \n";
        cout<<"Tong diem : ";
        cout<<student[i].getTotalScore()<<" \n";
}
void viewStudent(){
    for(int i=0;i<student.size();i++){
        showStudent(i);
    }

}

void deleteStudent(){
    int input,checkDelete;
    cout<<"Hay Nhap id sinh vien ban can xoa : ";
    cin>>input;
    cout<<"========Hay kiem tra thong tin truoc khi xoa=============\n";
    int idStudent = findIdStudent(input);
    showStudent(idStudent);
    cout<<"==========================================================\n";
    cout<<"Ban co dong y xoa khong neu dong y hay chon 1 khong chon thi chon 0\n";
    cin>>checkDelete;
    if(checkDelete==1){
        student.erase(student.begin()+(input-1));
        cout<<"Da xoa thong tin hoan tat\n";
    }

}
void updateStudent(int i){
    int id;
    string name;
    int age;
    float test1, test2;
    float midterm;
    float finalExam;
    float totalScore;
    float attendance;
        cout<<"Ten : ";
        cin.ignore();
        getline(cin,name);
        student[i].setName(name);
        cout<<"Tuoi : ";
        cin>>age;
        student[i].setAge(age);
        cout<<"Diem kiem tra lan 1 : ";
        cin>>test1;
        student[i].setTest1(test1);
        cout<<"Diem kiem tra lan 2 : ";
        cin>>test2;
        student[i].setTest2(test2);
        cout<<"Diem chuyen can : ";
        cin>>attendance;
        student[i].setAttendance(attendance);
        cout<<"Diem kiem tra giua ki : ";
        cin>>midterm;
        student[i].setMidterm(midterm);
        cout<<"Diem kiem tra cuoi ki : ";
        cin>>finalExam;
        student[i].setFinalExam(finalExam);
        student[i].setTotalScore();
}
void storeStudent(){
    int input;
    cout<<"Hay Nhap id sinh vien ban can cap nhap";
    cin>>input;
    cout<<"========Hay kiem tra thong tin truoc khi cap nhap=============\n";
    int idStudent = findIdStudent(input);
    showStudent(idStudent);
    cout<<"==========================================================\n";
    cout<<"Bat dau cap nhap thong tin sinh vien \n";
    updateStudent(input);
}
void maxTotalScore(){
    int maxcnt = student[0].getTotalScore();
    int index =0;
    for(int i=1;i<student.size();i++){
        if(maxcnt<student[i].getTotalScore()){
            maxcnt=student[i].getTotalScore();
            index =i;
        }
    }
    cout<<"Thong tin nguoi co tong diem cao nhat la :\n";
    showStudent(index);
}
void minTotalScore(){
    int mincnt = student[0].getTotalScore();
    int index =0;
    for(int i=1;i<student.size();i++){
        if(mincnt>student[i].getTotalScore()){
            mincnt=student[i].getTotalScore();
            index =i;
        }
    }
    cout<<"Thong tin nguoi co tong diem thap nhat la :\n";
    showStudent(index);
}
void  averageScore(){
    int id;
    cout<<"Hay nhap id cua sinh vien ban can tinh trung binh cong : ";
    cin>>id;
    int idStudent = findIdStudent(id);
    float averageScore = student[idStudent].getTotalScore() / 5 ;
    cout<<"Diem Trung Binh Cong Sinh vien "<<student[idStudent].getName()<<" : "<<averageScore<<"\n";

}
void findStudent(){
    int id;
    cout<<"Hay nhap id cua sinh vien ban can tim : ";
    cin>>id;
    int idStudent = findIdStudent(id);
    showStudent(idStudent);
}
bool cmp(Students a, Students b){
    if(a.getTotalScore()>b.getTotalScore()) return true;
    return false;
}
void sortStudent(){
    sort(student.begin(),student.end(),cmp);
    for(int i =0; i<student.size();i++){
        showStudent(i);
    }
}

int main()
{
    int id =1;
    int option;

    while(1){
        do{
            view();
            cin>>option;
        }while(option>9 || option<0);
        switch (option){
            case 0:
                return 0;
                break;
            case 1:
                insertStudent(id);
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                storeStudent();
                break;
            case 4:
                viewStudent();
                break;
            case 5:
                averageScore();
                break;
            case 6:
                maxTotalScore();
                break;
            case 7:
                minTotalScore();
                break;
            case 8:
                findStudent();
                break;
            case 9:
                sortStudent();
                break;

        }
    }

    return 0;
}
