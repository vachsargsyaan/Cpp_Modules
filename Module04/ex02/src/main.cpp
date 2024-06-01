#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    // Animal a;
    // (void)a;
	Animal **meta = new Animal*[100];
    for (int i = 0; i < 50; i++)
        meta[i] = new Cat();
    for (int i = 50; i < 100; i++)
        meta[i] = new Dog();
    for (int i = 0; i < 100; i++)
    {
        meta[i]->makeSound();
        delete meta[i];
    }
    delete [] meta;
	return (0);
}