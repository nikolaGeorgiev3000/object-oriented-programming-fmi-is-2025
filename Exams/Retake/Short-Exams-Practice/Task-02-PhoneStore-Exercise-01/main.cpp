/*
Да се реализира кратка програма, която да демонстрира с помощта на допълнителни функции, ако е необходимо:
    * как се създава магазин с определен начален капитал;
    * добавянето на няколко различни мобилни телефона;
    * премахва от магазина най-евтиния телефон с марка Samsung;
*/


#include "Store.h"


int main() {
    // Testing Telephone
    Telephone t1("N1", "Nokia", 25.0);
    Telephone t2("N2", "Nokia", 30.0);

    // t1.print(std::cout);
    // t2.print(std::cout);


    Telephone t3(t1);

    // t3.print(std::cout);
    t3 = t2;
    // t3.print(std::cout);


    // Testing Smartphone
    Smartphone s1("Android", 8, "S25 Ultra", "Samsung", 2500);
    Smartphone s2("iOS", 8, "16 Pro", "Apple", 2800);

    // s1.print(std::cout);
    // s2.print(std::cout);

    Smartphone s3(s1);
    // s3.print(std::cout);
    s3 = s2;
    // s3.print(std::cout);


    // Testing Store
    Store st1(100000);

    // Add phones
    st1.addTelephone(&s2);
    st1.addTelephone(&t2);
    st1.addTelephone(&s3);

    // st1.print(std::cout);

    std::cout << std::endl;

    // Remove phones
    st1.removeTelephone("N2", "Nokia");
    // st1.print(std::cout);

    return 0;
}