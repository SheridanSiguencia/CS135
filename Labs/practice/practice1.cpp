//practice 1


#include <iostream>

int main()
{
    int person_one, person_two;

//person 1
    std::cout<< "Enter person one's age: ";
    std::cin >> person_one;
    std::cout << std::endl;

//person 2
    std::cout<< "Enter person two's age: ";
        std::cin >> person_two;
    std::cout << std::endl;

    
    if(person_one > person_two)
        std::cout<< "Person 1 is older than person 2 by " << person_one - person_two << " years";
    else if (person_one == person_two)
        std::cout << "You both the same age!!";
    else         
        std:: cout << "Person 2 is older than person 1 by " << person_two - person_one << " years";
    
    
    return 0;
}