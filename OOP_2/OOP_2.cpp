
#include <iostream>
using namespace std;

// OOP_for_WorkWith_metods

//class Drob {
//    int num;
//    int denum;
//
//public:
//    
//    Drob(int num, int denum) {
//        this->num = num;
//        this->denum = denum;
//    }
//
//    int getNum() {
//        return num;
//    }
//    int getDenum() {
//        return denum;
//    }
//
//    void showDrob() {
//        cout << num << "/" << denum << endl;
//    }
//};

//class MathDrob {
//    
//public:
//
//    Drob* addDrob(Drob*& dr1, Drob*& dr2) {
//        
//        int num;
//        int denum;
//        num = dr1->getNum() * dr2->getDenum() + dr1->getDenum() * dr2->getNum();
//        denum = dr1->getDenum() * dr2->getDenum();
//        Drob* dr = new Drob(num, denum);
//        return dr;
//    }
//};
/* Drob* dr1 = new Drob(2, 3);
    Drob* dr2 = new Drob(1, 2);

    Drob* dr = (new MathDrob())->addDrob(dr1, dr2);

    dr1->showDrob();
    dr2->showDrob();
    dr->showDrob();*/

class Dist {
    string name;
    int* marks = nullptr;
    int counter = 0;

public:
    Dist(){
        // Default
    }
    Dist(string name) {
        this->name = name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }
    int* getMark() {
        return marks;
    }

    void addMark(int mark) {
        int* buf = new int[counter + 1];

        for (int i = 0; i < counter; i++)
        {
            buf[i] = marks[i];
        }

        buf[counter] = mark;
        delete[] marks;
        marks = buf;
        counter++;
    }

    // Показ оценок
    void showMark() {

        for (int i = 0; i < counter; i++)
        {
            cout << " " << marks[i];
        }
        cout << endl;
    }

};

class Student {
    Dist* dists = nullptr;
    string fio;
    string phone;
    int id;
    float midMark;
    int posInGroup;
    int posInRive;
    int countDist = 0;

public:

    // Конструкторы
    Student() {
        // Default
    }
    Student(string fio, string phone, int id) {
        this->fio = fio;
        this->phone = phone;
        this->id = id;
    }

    // Get-ры
    string getIFio() {
        return fio;
    }
    string getPhone() {
        return phone;
    }
    float getmidMark() {
        return midMark;
    }
    int getId() {
        return id;
    }
    int getposInGroup() {
        return posInGroup;
    }
    int getposInRive() {
        return posInRive;
    }

    // Set-ры
    void setPhone(string phone) {
        this->phone = phone;
    }
    void setmidMark(float midMArk) {
        this->midMark = midMArk;
    }
    void setPosInGroup(int posInGroup) {
        this->posInGroup = posInGroup;
    }
    void setPosInRive(int posInRive) {
        this->posInRive = posInRive;
    }

    // Показ
    void showStudent() {
        cout << fio << " " << id << " " << phone << endl;
        for (int i = 0; i < countDist; i++)
        {
            cout << dists[i].getName() << ":";
            dists[i].showMark();
        }
    }
    // Добавление дисциплины
    void addDist(string nameDist) {

        Dist newDist(nameDist);

        Dist* bufDist = new Dist[countDist + 1];
        for (int i = 0; i < countDist; i++)
        {
            bufDist[i] = dists[i];
        }

        bufDist[countDist++] = newDist;
        delete[] dists;
        dists = bufDist;
    }
   
};

class Group {
    string numGroup;
    Student* students;
    int count = 0;

public:

    // Конструктор
    Group(string numGroup) {
        this->numGroup = numGroup;
    }
    // Добавление
    void addStudent(const Student& student) {
        Student* bufStud = new Student[count + 1];

        for (int i = 0; i < count; i++)
        {
            bufStud[i] = students[i];
        }

        bufStud[count] = student;
        delete[] students;
        students = bufStud;
        count++;
    }
    // Поиск студента по id
    Student* searchStudent(int id) {

        for (int i = 0; i < count; i++)
        {
            if (id == students[i].getId()) {
                //students[i].showStudent();
                return &students[i];
            }
        }
        return nullptr;
    }
    // Удаление
    void deleteStudent(int id) {
       
        Student* searchSt = searchStudent(id);
        if (searchSt != nullptr) {
            
            if (count == 1) {
                delete[] students;
                students = nullptr;
            }
            else {
                int index = 0;
                for (int i = 0; i < count; i++)
                {
                    if (searchSt == &students[i]) {
                        index = i;
                        break;
                    }
                }

                Student* bufStud = new Student[count - 1];
                for (int i = 0; i < index; i++)
                {
                    bufStud[i] = students[i];
                }

                for (int i = index + 1; i < count; i++)
                {
                    bufStud[i - 1] = students[i];
                }
                delete[] students;
                students = bufStud;
            }
 
            count--;
        }

       
    }
    // Показ студентов в группе
    void showGroup() {

        for (int i = 0; i < count; i++)
        {
            students[i].showStudent();
            cout << endl;
        }

        cout << endl;
    }
};

void main()
{
    setlocale(LC_ALL, "Rus");
   
    Student st1("Вася", "+7824546", 652423);
    Student st2("Вася1", "+7824546", 3);
    Student st3("Вася2", "+783", 633);
    Student st4("Вася3", "+7283", 63376);
    
    Group gr1("SA");
    cout << "start group" << endl;
    gr1.showGroup();
    cout << "after add students" << endl;

    gr1.addStudent(st1);
    gr1.addStudent(st2);
    gr1.addStudent(st3);
    gr1.addStudent(st4);

    gr1.showGroup();
    cout << "after remove students" << endl;
    gr1.deleteStudent(633);
    gr1.showGroup();

    cout << " after add mathematic" << endl;

}