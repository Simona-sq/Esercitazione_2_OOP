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
    
    // Stampe
    std::cout << "\nI numeri complessi hanno la seguente forma:\n" << c1 << "\n" << c2 << "\n" << c3 << "\n" << c4 << "\n\nCioè sono composti da una parte reale...\n" << c1.real() << "\n" << c2.real() << "\n" << c3.real() << "\n" << c4.real() << "\n\n...E da una parte immaginaria.\n" << c1.imaginary() << "\n" << c2.imaginary() << "\n" << c3.imaginary() << "\n" << c4.imaginary() << "\n\nInoltre, per ogni numero complesso, è definito il suo complesso coniugato.\n" << c1.conjugate() << "\n" << c2.conjugate() << "\n" << c3.conjugate() << "\n" << c4.conjugate() << std::endl;
    std::cout << "\nSi possono fare addizioni con i numeri complessi..." << "\n3.5 + (5+12i) = " << c5 << "\n(6-5i) + 3.5 = " << c6 << '\n' << c1 << " + " << c2 << " = " << c7 << std::endl;
    std::cout << "\n...E anche moltiplicazioni con i numeri complessi.\n" << "3.5 * (5+12i) = " << c8 << "\n(6-5i) * 3.5 = "<< c9 << '\n' <<c1<<" * "<<c2<<" = "<< c10 << std::endl;

    return 0;
}