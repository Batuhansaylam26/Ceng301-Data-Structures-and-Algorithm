// DO NOT CHANGE THIS FILE
#ifndef IMAGINARYPOINT_H
#define IMAGINARYPOINT_H
class ImaginaryPoint{
private:
    int real_part; // a
    int imaginary_part;//b
public:
    ImaginaryPoint(int real, int imaginary);
    ~ImaginaryPoint();

    int get_magnitude_squared() const; // a*a + b*b

    int get_real_part() const;
    int get_imaginary_part() const;

    // Overload operators
    ImaginaryPoint operator+(const ImaginaryPoint& other) const;
    ImaginaryPoint operator-(const ImaginaryPoint& other) const;
    ImaginaryPoint operator*(const ImaginaryPoint& other) const;
    bool operator<(const ImaginaryPoint& other) const;
};
#endif
