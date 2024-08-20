#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H




#include <iostream>





class ExampleClass
{
public:
    // Constructor
    ExampleClass();

    // Destructor
    ~ExampleClass();

    // Member functions
    void exampleFunction();

private:
    // Member variables
    int someVariable;
    double anotherVariable;
};

#endif // EXAMPLECLASS_H