
#include <iostream>
#include <string>
using namespace std;

// OOP_for_WorkWith_metods
/*
// __________________________________________________________________________
1. Группа должна содержать массив студентов
id +
фио +
номер-телефона +
ср.балл +
рейтинг в группе +
рейтинг в потоке +

возможность добавления студента в группу +
удаление из группы по id +
вывод всех студентов +
поиск студента по id +
// __________________________________________________________________________
-----Текущее-----
Добавить класс, содержащий название дисциплины и массив оценок +

Добавить метод добавления студенту необходимой дисциплины +
а также добавление оценок в указанную дисциплину конкретному студенту +
// __________________________________________________________________________
*/

// Класс дисциплина
class Dist {
    string name;
    int* marks = nullptr;
    int counter = 0;

public:
    Dist() {
        // Default
    }
    Dist(string name) {
        this->name = name;
    }
    // Конструктор копирования
    Dist(const Dist& dist) {
        this->name = dist.name;
        this->counter = dist.counter;

        marks = new int[dist.counter];
        for (int i = 0; i < dist.counter; i++)
        {
            marks[i] = dist.marks[i];
        }
    }
    void operator = (Dist dist) {
        this->name = dist.name;
        this->counter = dist.counter;

        marks = new int[dist.counter];
        for (int i = 0; i < dist.counter; i++)
        {
            marks[i] = dist.marks[i];
        }
    }
    // Деструктор
    ~Dist() {
        delete[] marks;
    }

    // Set-ры
    void setName(string name) {
        this->name = name;
    }
    // Get-ры
    string getName() {
        return name;
    }
    int* getMark() {
        return marks;
    }
    int getCounter() {
        return counter;
    }

    void addMark(int mark) {
        int* buf = new int[counter + 1];

        for (int i = 0; i < counter; i++)
        {
            buf[i] = marks[i];
        }

        buf[counter++] = mark;
        delete[] marks;
        marks = buf;
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
    // Конструктор копирования
    Student(const Student& st) {
        this->fio = st.fio;
        this->phone = st.phone;
        this->id = st.id;
        this->midMark = st.midMark;
        this->posInGroup = st.posInGroup;
        this->posInRive = st.posInRive;
        this->countDist = st.countDist;

        dists = new Dist[st.countDist];
        for (int i = 0; i < st.countDist; i++)
        {
            dists[i] = st.dists[i];
        }
    }
    // Деструктор
    ~Student(){
        delete[] dists;
    }

    // Get-ры
    string getFio() {
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
    int getCountDist() {
        return countDist;
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

    Dist* searchDist(string name) {

        for (int i = 0; i < this->countDist; i++)
        {
            if (name == dists[i].getName()) {
                return &dists[i];
            }
        }
        return nullptr;

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
    // Конструктор копирования
    Group(const Group& group) {
        this->numGroup = group.numGroup;
        this->count = group.count;

        students = new Student[group.count];
        for (int i = 0; i < group.count; i++)
        {
            students[i] = group.students[i];
        }
    }
    // ~Деструктор
    ~Group() {
        delete[] students;
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
    // Добавление оценки студенту
    void addMarkSudent(Student student, string name, int mark) {
        
        Student* searchSt = searchStudent(student.getId());
        Dist* searchDist = searchSt->searchDist(name);
        
        if (searchSt != nullptr && searchDist != nullptr) {
            searchDist->addMark(mark);
        }
    }

    // Добавление дисциплины студенту
    void addDistStudent(Student student, string name) {
        Student* searchSt = searchStudent(student.getId());

        if (searchSt != nullptr) {
            searchSt->addDist(name);
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
    cout << "\tstart group" << endl;
    gr1.showGroup();
    cout << "\tafter add students" << endl;

    gr1.addStudent(st1);
    gr1.addStudent(st2);
    gr1.addStudent(st3);
    gr1.addStudent(st4);

    gr1.showGroup();
    cout << "\tafter remove students" << endl;
    gr1.deleteStudent(633);
    gr1.showGroup();

    cout << "\tafter add mathematic && biology" << endl;
    gr1.addDistStudent(st1,"math");
    gr1.addDistStudent(st1, "biology");
    
    gr1.showGroup();

    cout << "\tafter add marks mathematic && biology" << endl;

    gr1.addMarkSudent(st1, "math", 4);
    gr1.addMarkSudent(st1, "math", 3);
    gr1.addMarkSudent(st1, "math", 5);
    gr1.addMarkSudent(st1, "biology", 4);
    gr1.addMarkSudent(st1, "biology", 2);
    gr1.addMarkSudent(st1, "biology", 3);
    gr1.addMarkSudent(st1, "biology", 4);
    gr1.addMarkSudent(st1, "biology", 5);

    gr1.showGroup();

}