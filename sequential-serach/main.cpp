#include <iostream>
#include <string>

#include "ArrayList.h"

int main()
{
    ArrayList<int> intList(100);
    ArrayList<std::string> stringList;

    int number;

    std::cout << "Enter 5 integers: " << std::endl;

    for (int c = 0; c < 5; c++)
    {
        std::cin >> number;

        intList.insertAt(c, number);
    }

    std::cout << std::endl;
    std::cout << "The list you entered is: ";
    intList.print();

    std::cout << std::endl;

    std::cout << "Enter the item to be deleted:";
    std::cin >> number;
    intList.remove(number);

    std::cout << "After removing " << number << ", the list is:" << std::endl;

    intList.print();
    std::cout << std::endl;

    std::string str;

    std::cout << "Enter 5 strings: " << std::endl;

    for (int c = 0; c < 5; c++)
    {
        std::cin >> str;

        stringList.insertAt(c, str);
    }

    std::cout << std::endl;
    std::cout << "The list you entered is: " << std::endl;
    stringList.print();

    std::cout << std::endl;

    std::cout << "Enter the string to be deleted: ";
    std::cin >> str;

    stringList.remove(str);

    std::cout << "After removing " << str << ", the list is:" << std::endl;

    stringList.print();

    std::cout << std::endl;

    return 0;
}