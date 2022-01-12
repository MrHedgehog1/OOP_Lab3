#include <iostream>
#include <vector>

const int DIY = 360;
const int DIM = 30;
class Date{
private:
    int _day;
    int _month;
    int _year;

public:
    Date(int day, int month, int year);
    ~Date();
    void set_day(int day);
    void set_month(int month);
    void set_year(int year);
    void display_info() const;

    Date parseDays(int days);
    int operator-(const Date &other);

    friend int operator+(const Date &other, const Date &other1);
    friend bool operator==(const Date &other, const Date &other1);
};
Date::Date(int day, int month, int year) {
    _day = day;
    _month = month;
    _year = year;
}
void Date::display_info() const {
    std::cout << "day - " << _day << " month - " << _month << " years - " << _year << std::endl;
}
Date Date::parseDays(int days) {
    int years = days / DIY;
    int months = (days % DIY) / DIM;
    days = ((days % DIY)% DIM);
    return Date(days,months,years);
}
Date::~Date(){

}
int fun (int m1,int dm,int d1,int g)
{
    switch(m1)
    {
        case 1:
            dm=0+d1;
            break;
        case 2:
            dm=31+d1;
            break;
        case 3:
            if (g-(g/4)*4==0)dm=d1+60;
            else dm=59+d1;
            break;
        case 4:
            if (g-(g/4)*4==0)dm=91+d1;
            else dm=90+d1;
            break;
        case 5:
            if (g-(g/4)*4==0) dm=121+d1;
            else dm=120+d1;
            break;
        case 6:
            if (g-(g/4)*4==0) dm=152+d1;
            else dm=151+d1;
            break;
        case 7:
            if (g-(g/4)*4==0) dm=182+d1;
            else dm=181+d1;
            break;
        case 8:
            if (g-(g/4)*4==0) dm=213+d1;
            else dm=212+d1;
            break;
        case 9:
            if (g-(g/4)*4==0) dm=244+d1;
            else dm=243+d1;
            break;
        case 10:
            if (g-(g/4)*4==0) dm=274+d1;
            else dm=273+d1;
            break;
        case 11:
            if (g-(g/4)*4==0) dm=305+d1;
            else dm=304+d1;
            break;
        case 12:
            if (g-(g/4)*4==0) dm=335+d1;
            else dm=334+d1;
            break;
    }
    return dm;
}
int Date::operator-(const Date &other){
    int year = 0, days0 = 0, days = 0, daysInMonths = 0;
    year = this->_year - other._year;
    days0 = (year / 4)+1;
    days = year*365;
    days += days0;
    daysInMonths = fun(other._month,daysInMonths,other._day,year);
    days-=daysInMonths;
    daysInMonths=0;
    std::cout << days << "\nh\n";
    return days;
}
int operator+(const Date &other, const Date &other1){
    int year = 0, days0 = 0, days = 0, daysInMonths = 0;
    year = other1._year + other._year;
    days0 = (year / 4)+1;
    days = year*365;
    days += days0;
    daysInMonths = fun(other._month,daysInMonths,other._day,year);
    days+=daysInMonths;
    daysInMonths=0;
    std::cout << days << "\nh\n";
    return days;
}
bool operator ==(const Date &other, const Date &other1){
    return (other._day == other1._day)&&(other._month == other1._month)&&(other._year == other1._year);
}
std::vector <int> input_d()
{
    std::vector <int> in_date;
    double temp;

    std::cout << "Введите день от 1 до 31 : ";
    std::cin >> temp;
    in_date.insert(in_date.end(), temp);
    std::cout << "Введите месяц от 1 до 12: ";
    std::cin >> temp;
    in_date.insert(in_date.end(), temp);
    std::cout << "Введите год: ";
    std::cin >> temp;
    in_date.insert(in_date.end(), temp);

    return in_date;
}
/*int fun (int m1,int dm,int d1,int g);
int _tmain()
{
    int g1,g2,m1,m2,d2,i,d,d1,d0,g,dm=0;
    std::cout<<"Введите 1 дату год мес день"<<std::endl;
    std::cin>>g1>>m1>>d1;
    std::cout<<"Введите 2 дату год мес день"<<std::endl;
    std::cin>>g2>>m2>>d2;
    g=g2-g1;
    d0=(g/4)+1;
    d=g*365;
    d+=d0;
    dm=fun (m1,dm,d1,g1);
    d-=dm;
    dm=0;
    dm=fun (m2,dm,d2,g2);
    d+=dm;
    std::cout<<d;
    std::cin>>i;

    return 0;
}

int fun (int m1,int dm,int d1,int g)
{
    switch(m1)
    {
        case 1:
            dm=0+d1;
            break;
        case 2:
            dm=31+d1;
            break;
        case 3:
            if (g-(g/4)*4==0)dm=d1+60;
            else dm=59+d1;
            break;
        case 4:
            if (g-(g/4)*4==0)dm=91+d1;
            else dm=90+d1;
            break;
        case 5:
            if (g-(g/4)*4==0) dm=121+d1;
            else dm=120+d1;
            break;
        case 6:
            if (g-(g/4)*4==0) dm=152+d1;
            else dm=151+d1;
            break;
        case 7:
            if (g-(g/4)*4==0) dm=182+d1;
            else dm=181+d1;
            break;
        case 8:
            if (g-(g/4)*4==0) dm=213+d1;
            else dm=212+d1;
            break;
        case 9:
            if (g-(g/4)*4==0) dm=244+d1;
            else dm=243+d1;
            break;
        case 10:
            if (g-(g/4)*4==0) dm=274+d1;
            else dm=273+d1;
            break;
        case 11:
            if (g-(g/4)*4==0) dm=305+d1;
            else dm=304+d1;
            break;
        case 12:
            if (g-(g/4)*4==0) dm=335+d1;
            else dm=334+d1;
            break;
    }
    return dm;
}*/
void print_baseDate(const std::vector <Date> &other ){
    std::cout << "Все имеющиеся в базе даты:" << std::endl;
    for (int i = 0; i <size(other); i++){
        std::cout << "Запись номер " << i << std::endl;
        other[i].display_info();
    }
}
int main() {
    Date a(15, 10, 5);
    Date b(1,2,2);

    std::vector <Date> dates_entry;
    std::vector <int> input_date;
    int i;
    char command;
    bool exit = false;

    dates_entry.push_back(a);
    dates_entry.push_back(b);
    while (!exit){
            std::cout << "\nКомандное меню приветствует вас. Вы можете: \n";
            std::cout << "\t1. Создать запись даты.\n";
            std::cout << "\t2. Сложить даты.\n";
            std::cout << "\t3. Вычетание даты из даты.\n";
            std::cout << "\t4  добавить к дате заданное колличество дней\n";
            std::cout << "\t5. Сравнить даты.\n";
            std::cout << "\t6. Посмотреть записи о треугольниках.\n";
            std::cout << "\t0. Выход из программы.\n";
            std::cout << "Команда: ";
            std::cin >> command;
            std::cin.ignore();
            switch (command)
            {
                case '1':
                   input_date = input_d();
                   dates_entry.push_back(Date(input_date[0],input_date[1],input_date[2]));
                   break;
                case '2':
                    std::cout << "Все имеющиеся в базе даты:" << std::endl;
                    for (i = 0; i <size(dates_entry); i++){
                        std::cout << "Запись номер " << i << std::endl;
                        dates_entry[i].display_info();
                    }
            }
            int result=0;
            result = a + b;
            std::cout << "\nresult - " << result;
            //_tmain();
            std::cout << "\nHello, World!" << std::endl;
            return 0;

        }}