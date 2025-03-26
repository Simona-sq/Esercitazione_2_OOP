#include <iostream>
#include "complex_number.hpp"

int main(void) 
{
    using co = complex_number<double>; //using co = complex_number<float>
    
    // Numeri complessi
    co c1(1,-3);
    co c2(-9,-6);
    co c3(3,0);
    co c4(0,9);

    // Somma double(float) + complex (implementata all'esterno della classe)
    co c5 = 3.5 + co(5,12); //co c5 = 3.5f + co(5,12);

    // Somma complex + double(float) (implementata all'interno della classe)
    co c6 = co(6,-5) + co(3.5); //co c6 = co(6,5) + 3.5f;

    // Somma complex + complex (implementata all'interno della classe)
    co c7 = c1 + c2;

    // Moltiplicazione double(float) * complex (implementata all'esterno della classe)
    co c8 = 3.5 * co(5,12); //co c8 = 3.5f * co(5,12);

    // Moltiplicazione complex * double(float) (implementata all'interno della classe)
    co c9 = co(6,-5) * co(3.5); //co c9 = co(6,-5) * 3.5f;

    // Moltiplicazione complex * complex (implementata all'interno della classe)
    co c10 = c1 * c2;


    /* Utilizzo di explicit: 

        co c11 = 3.5;
        std::cout << c11 <<std::endl;
        Questa operazione mi dà errore perchè il programma non converte autonomamente un
        double (3.5) in complex_number<double>.
        
        co c11 = co(3.5);
        std::cout << c11 <<std::endl;
        Scrivo espicitamente la conversione da double in complex_number<double>.
    */
    

    std::cout << "\nI numeri complessi hanno la seguente forma:" << std::endl;
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << c4 << std::endl;
    std::cout << "\nCioè sono composti da una parte reale..." << std::endl;
    std::cout << c1.real() << std::endl;
    std::cout << c2.real() << std::endl;
    std::cout << c3.real() << std::endl;
    std::cout << c4.real() << std::endl;
    std::cout << "\n...E da una parte immaginaria." << std::endl;
    std::cout << c1.imaginary() << std::endl;
    std::cout << c2.imaginary() << std::endl;
    std::cout << c3.imaginary() << std::endl;
    std::cout << c4.imaginary() << std::endl;
    std::cout << "\nInoltre, per ogni numero complesso, è definito il suo complesso coniugato." << std::endl;
    std::cout << c1.conjugate() << std::endl;
    std::cout << c2.conjugate() << std::endl;
    std::cout << c3.conjugate() << std::endl;
    std::cout << c4.conjugate() << std::endl;
    std::cout << "\nSi possono fare addizioni con i numeri complessi..." << std::endl;
    std::cout << "3.5 + (5+12i) = " << c5 << std::endl;
    std::cout << "(6-5i) + 3.5 = " << c6 << std::endl;
    std::cout << c1 << " + " << c2 << " = " << c7 << std::endl;
    std::cout << "\n...E anche moltiplicazioni con i numeri complessi." << std::endl;
    std::cout << "3.5 * (5+12i) = " << c8 << std::endl;
    std::cout << "(6-5i) * 3.5 = "<< c9 << std::endl;
    std::cout <<c1<<" * "<<c2<<" = "<< c10 << std::endl;

    return 0;
}