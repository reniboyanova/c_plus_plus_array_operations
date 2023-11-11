#include <iostream>
#include <algorithm>

class Student
{
public:
    std::string m_name;
    int m_age;
    char m_gender;
    float m_programmingGrade;

    // Student(){}

    Student(std::string name, int age, char gender, float programmingGrade)
        : m_name(name), m_age(age), m_gender(gender), m_programmingGrade(programmingGrade)
    {
    }
};

bool compareByGrade(const Student &s1, const Student &s2)
{
    return s1.m_programmingGrade < s2.m_programmingGrade;
}

bool compareByName(const Student &s1, const Student &s2)
{
    return s1.m_name < s2.m_name;
}

bool compareWithSmallestGradeToPass(const Student &s)
{
    return s.m_programmingGrade < 6;
}

int main()
{

    // int size = 0;
    // std::cout << "Please insert thenumber of students: " << std::endl;
    // std::cin >> size;

    // Student *students = new Student[size];

    // for (size_t i = 0; i < size; i++)
    // {
    //     Student s;

    //     std::cout << "Insert name of student: " << std::endl;
    //     std::cin >> s.m_name;

    //     std::cout << "Age of student: " << std::endl;
    //     std::cin >> s.m_age;

    //     std::cout << "Gender of student: " << std::endl;
    //     std::cin >> s.m_gender;

    //     std::cout << "Graduate of student: " << std::endl;
    //     std::cin >> s.m_programmingGrade;
    // }

    // delete[] students;

    Student students[5] = {
        {"Reni", 32, 'f', 10},
        {"Bobi", 34, 'm', 6},
        {"Aleks", 22, 'm', 8},
        {"Saldina", 28, 'f', 9},
        {"Beni", 31, 'f', 5}};

    std::sort(students, students + 5, compareByGrade);
    std::reverse(students, students + 5);

    for (int i = 0; i < 5; i++)
    {
        std::cout << students[i].m_name << '\t' << students[i].m_programmingGrade << std::endl;
    }

    std::cout << "Max grade student is: ";
    Student *maxGradeStudent = std::max_element(students, students + 5, compareByGrade);

    std::cout << maxGradeStudent->m_name << " with grade of: " << maxGradeStudent->m_programmingGrade << std::endl;

    std::cout << "Min grade student is: ";

    Student *minGraduateStudent = std::min_element(students, students + 5, compareByGrade);

    std::cout << minGraduateStudent->m_name << " with grade of: " << minGraduateStudent->m_programmingGrade << std::endl;

    Student *firstPassedStudent = std::find_if(students, students + 5, compareWithSmallestGradeToPass);
    std::cout << firstPassedStudent->m_name << " with grade of: " << firstPassedStudent->m_programmingGrade;

    return 0;
}