#include "ImaginaryPoint.h"

// Constructor
ImaginaryPoint::ImaginaryPoint(int real, int imaginary)
{
    real_part=real;
    imaginary_part=imaginary;
}

// Destructor
ImaginaryPoint::~ImaginaryPoint()
{

}

// Calculate magnitude squared
int ImaginaryPoint::get_magnitude_squared() const
{
    return real_part*real_part+imaginary_part*imaginary_part;
}

// Getter for real part
int ImaginaryPoint::get_real_part() const
{
    return real_part;
}

// Getter for imaginary part
int ImaginaryPoint::get_imaginary_part() const
{
    return imaginary_part;
}

// Overload addition operator
ImaginaryPoint ImaginaryPoint::operator+(const ImaginaryPoint& other) const
{
    return ImaginaryPoint(real_part + other.real_part, imaginary_part + other.imaginary_part);
}

// Overload subtraction operator
ImaginaryPoint ImaginaryPoint::operator-(const ImaginaryPoint& other) const
{
    return ImaginaryPoint(real_part - other.real_part,imaginary_part - other.imaginary_part);
}

// Overload multiplication operator
ImaginaryPoint ImaginaryPoint::operator*(const ImaginaryPoint& other) const
{
    return ImaginaryPoint(real_part * other.real_part-imaginary_part*other.imaginary_part,real_part * other.imaginary_part+imaginary_part*other.real_part);
}

// Overload less than operator
bool ImaginaryPoint::operator<(const ImaginaryPoint& other) const
{
    return get_magnitude_squared()<other.get_magnitude_squared();
}
