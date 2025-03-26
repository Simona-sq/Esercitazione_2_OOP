#pragma once

template<typename F>
    requires std::floating_point<F>
class complex_number
{
	// INTERNO DELLA CLASSE
    // Attributi privati
    F re_part;
    F im_part;

public:
    // Costruttore di default
    complex_number()
        : re_part(0), im_part(0) {}

    // Costruttore user-defined: evito conversioni automatiche
    explicit complex_number(F a)
        : re_part(a), im_part(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }

    // Costruttore user-defined
    complex_number(F a, F b)
        : re_part(a), im_part(b) {}

    // Metodi per ottenere parte reale e immaginaria e il coniugato
    F real(void) const {
        return re_part;
    }

    F imaginary(void) const {
        return im_part;
    }

    complex_number<F> conjugate(void) const {
        return complex_number<F>(re_part, -im_part);
    }

    // Overload +=
    complex_number& operator+=(const complex_number& other) {
        F a = re_part;
        F b = im_part;
        F c = other.re_part;
        F d = other.im_part;
        re_part = a+c;
        im_part = b+d;
        return *this;
	}

    // Overload + (Somma complex + F)
    complex_number operator+(const complex_number& other) const {
        complex_number complex = *this;
        complex += other;
        return complex;
    }

    // Overload *=
    complex_number& operator*=(const complex_number& other) {
        F a = re_part;
        F b = im_part;
        F c = other.re_part;
        F d = other.im_part;
        re_part = a*c-b*d;
        im_part = a*d+b*c;
        return *this;
	}

    // Overload * (Moltiplicazione complex * F)
    complex_number operator*(const complex_number& other) const {
        complex_number complex = *this;
        complex *= other;
        return complex;
    }
};

// ESTERNO DELLA CLASSE

// Somma F + complex
template<typename F>
complex_number<F>
operator+(const F& f, const complex_number<F>& complex)
{
    return complex_number<F>(complex.real() + f, complex.imaginary());
}

// Moltiplicazione F * complex
template<typename F>
complex_number<F>
operator*(const F& f, const complex_number<F>& complex)
{
    return complex_number<F>(complex.real() * f, complex.imaginary() * f);
}

// Overload dell'operatore << per gli output
template<typename F>
std::ostream&
operator<<(std::ostream& os, const complex_number<F>& complex) 
{
    if (complex.imaginary() < 0)
        os << complex.real() << "-" << std::abs(complex.imaginary()) << "i";
    else if (complex.imaginary() > 0)
        os << complex.real() << "+" << std::abs(complex.imaginary()) << "i";
    else 
        os << complex.real();
    return os;
}

