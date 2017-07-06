
/** @file   integer.cpp
    @author Rishabh Prakash
    @SID    904319716
    @date   01/07/2015
 
 
Creates class Integer, defining operations on it's objects,
mimmicking the way int data types are stored on a computer
and are operated upon.
 
Stores Integers in binary as objects with a private member
std::vector of bools, whose indices match the placeholder
power of 2.

*/

#include <iostream>
#include <vector>


///////////////////////// Declaration of Integer Class and Non-member Functions ///////////////////////


/** @class Integer
 
 @brief Stores Integers in binary as a std::vector of bools, with
        indices matching respective powers of 2.

 Integers stored as std::vector of bools as private member bits.
 
*/

class Integer {
public:
    Integer();
    Integer(unsigned int a);
    Integer(std::vector<bool> a);
    
    bool getBit(unsigned long i) const;
    unsigned long getSize() const;
    
    bool compare(const Integer& subject) const;
    
    void plus_equals(const Integer& rhs);
    void times_equals(const Integer& rhs);
    
    Integer& operator+=(const Integer& rhs);
    Integer& operator*=(const Integer& rhs);
    
    bool operator<(const Integer& rhs) const;
    bool operator==(const Integer& rhs) const;
    
    void print_as_int() const;
    void print_as_bits() const;
    
private:
    std::vector<bool> bits;
    void clean_up();
};

Integer plus (Integer lhs, const Integer& rhs);
Integer multiply(Integer lhs, const Integer& rhs);

Integer operator+(Integer lhs, const Integer& rhs);
Integer operator*(Integer lhs, const Integer& rhs);

unsigned int power(unsigned int base, unsigned int exponent);

bool operator> (const Integer& lhs, const Integer& rhs);
bool operator!=(const Integer& lhs, const Integer& rhs);
bool operator<=(const Integer& lhs, const Integer& rhs);
bool operator>=(const Integer& lhs, const Integer& rhs);


/////////////////////////////////////////// Main Routine ////////////////////////////////////////////


/** Main routine.
 
*/

int main( int argc, const char* argv[] )
{
    unsigned int uint_value;
    
    std::cout << "Please input an integer a: ";
    std::cin >> uint_value;
    Integer a = uint_value; // Create Integer type with input value
    
    std::cout << "The base-2 representation of a is: "; a.print_as_bits(); std::cout << std::endl;
    
    std::cout << "Please input an integer b: ";
    std::cin >> uint_value;
    Integer b = uint_value; // Create Integer type with input value
    
    std::cout << "The base-2 representation of b is: "; b.print_as_bits(); std::cout << std::endl;
    
    // Lets do some basic arithmetic
    
    Integer c = a + b;      // a + b
    Integer d = a * b;      // a * b
    
    // Print out values
    
    std::cout << "a + b = "; c.print_as_int(); std::cout <<" = "; c.print_as_bits();std::cout << std::endl;
    std::cout << "a * b = "; d.print_as_int(); std::cout <<" = "; d.print_as_bits();std::cout << std::endl;
    
    // Test comparison functions
    
    if (a>b)    std::cout << "a > b"  << std::endl;
    if (a>=b)   std::cout << "a >= b" << std::endl;
    if (a<b)    std::cout << "a < b"  << std::endl;
    if (a<=b)   std::cout << "a <= b" << std::endl;
    if (a==b)   std::cout << "a == b" << std::endl;
    if (a!=b)   std::cout << "a != b" << std::endl;
    
    return 0;
    
    
}


//////////////////// Implementation of Integer Class and Non-member Functions //////////////////////


/** Default constructor for Integer class.
 
 Initializes vector of bools to the empty vector.
 
*/

Integer::Integer()
{
    bits = {};
}


/** Constructor for Integer class.
 
 @param a   Unsigned int to be stored in binary
 
 Converts a into binary and stores it in private member vector of bools (bits)
 with indices matching powers of 2.
 
 */

Integer::Integer(unsigned int a)
{
    if (a == 0)
    {
        bits.push_back(false);
    }
    
    for (size_t i = 0; a > 0; i++)
    {
        bits.push_back(a%2);
        a = a/2;
    }
    
}


/** Clean Up: removes trailing zeroes in binary.
 
*/

void Integer::clean_up()
{
    for (long i = bits.size() - 1; i >= 0; --i)
    {
        if (bits[i] == true)
        {
            break;
        }
        bits.pop_back();
    }
}


/** Constructor for Integer class.
 
 @param a   vector of bools
 
 Initializes private member bits, a vector of bools with
 indice values matching that of a's, and then cleans bits up.
 
*/

Integer::Integer(std::vector<bool> a)
{
    bits = a;
    this->clean_up();
}


/** Exponentiates a number.
 
 @param base        unsigned int to be exponentiated.
 @param exponent    unsigned int power to which base is exponentiated.
 
 @returns bases exponentiated value. I wrote this to be used in the print_as_int() member function.
 
*/

unsigned int power(unsigned int base, unsigned int exponent)
{
    unsigned int output = 1;
    for (size_t i = 0; i < exponent; ++i)
    {
        output *= base;
    }
    return output;
}


/** Retrieves parameter indice entry from private member bits.
 
 @param i   unsigned int indice from where element of bits is to be retrieved
 
 @returns boolean value of given indice element of private member bits.
 
*/

bool Integer::getBit(unsigned long i) const
{
    bool currentBit = bits[i];
    return currentBit;
}


/** Tells us size of private member bits.
 
 @returns size of private member bits using getSize() member function of std::vector.
 
*/

unsigned long Integer::getSize() const
{
    return bits.size();
}



///////////////////// Arithmetic Functions and Overloaded Arithmetic Operators /////////////////////



/** Adds value of parameter Integer to function calling Integer.
 
 @param rhs     const Integer reference to Integer whose value is added to *this.
 
*/

void Integer::plus_equals(const Integer& rhs)
{
    bool carryover = false;                                 // initializes carryover of addition to zero.
    
    if (getSize() > rhs.getSize())                          // case when *this is larger in size than parameter integer.
    {
        size_t i = 0;
        for (i = 0; i < rhs.getSize(); ++i)
        {
            if ((bits[i] + rhs.getBit(i) + carryover) == 0)
            {
                bits[i] = false;
                carryover = false;
            }
            else if ((bits[i] + rhs.getBit(i) + carryover) == 1)
            {
                bits[i] = true;
                carryover = false;
            }
            else if ((bits[i] + rhs.getBit(i) + carryover) == 2)
            {
                bits[i] = false;
                carryover = true;
            }
            else if ((bits[i] + rhs.getBit(i) + carryover) == 3)
            {
                bits[i] = true;
                carryover = true;
            }
            
        }
        for (size_t j = i; j < getSize(); ++j)          // iteration for indices after end of smaller integer.
        {                                               // depend only on indices of bigger integer.
            if ((bits[j] + carryover) == 0)
            {
                bits[j] = false;
                carryover = false;
            }
            else if ((bits[j] + carryover) == 1)
            {
                bits[j] = true;
                carryover = false;
            }
            else if ((bits[j] + carryover) == 2)
            {
                bits[j] = false;
                carryover = true;
            }
            else if ((bits[j] + carryover) == 3)
            {
                bits[j] = true;
                carryover = true;
            }
        }
        if (carryover == true)
        {
            bits.push_back(true);                       // if finally there exists a carryover, add digit.
        }
    }
    
    if (getSize() <= rhs.getSize())                     // case when *this is smaller in size than rhs.
    {
        size_t i = 0;
        for (i = 0; i < getSize(); ++i)
        {
            if ((bits[i] + rhs.getBit(i) + carryover) == 0)
            {
                bits[i] = false;
                carryover = false;
            }
            else if ((bits[i] + rhs.getBit(i) + carryover) == 1)
            {
                bits[i] = true;
                carryover = false;
            }
            else if ((bits[i] + rhs.getBit(i) + carryover) == 2)
            {
                bits[i] = false;
                carryover = true;
            }
            else if ((bits[i] + rhs.getBit(i) + carryover) == 3)
            {
                bits[i] = true;
                carryover = true;
            }
            
        }
        for (size_t j = i; j < rhs.getSize(); ++j)
        {
            if ((rhs.getBit(j) + carryover) == 0)
            {
                bits.push_back(false);
                carryover = false;
            }
            else if ((rhs.getBit(j) + carryover) == 1)
            {
                bits.push_back(true);
                carryover = false;
            }
            else if ((rhs.getBit(j) + carryover) == 2)
            {
                bits.push_back(false);
                carryover = true;
            }
            
            else if ((rhs.getBit(j) + carryover) == 3)
            {
                bits.push_back(true);
                carryover = true;
            }
        }
        if (carryover == true)
        {
            bits.push_back(true);
        }
    }
    this->clean_up();                               // clean up an trailing zeros.
}

/** Overloaded += operator by using plus_equals function in its implementation.
 
 @param     const Integer reference to rhs
 
 @returns   Integer reference to modified *this
 
*/

Integer& Integer::operator+=(const Integer& rhs)
{
    this->plus_equals(rhs);
    return *this;
}


/** Compares two Integers, returns true if *this is greater or equal,
    false if smaller than parameter Integer.
 
 @param subject     const int reference to parameter Integer being compared
 
 @returns           boolean true if *this is greater or equal to,
                    false if *this is smaller than parameter Integer.
 
*/

bool Integer::compare(const Integer& subject) const
{
    if (this->getSize() != subject.getSize())                   // Case when the two Integers have unequal size.
    {
        unsigned long limit = 0;
        
        (this->getSize() > subject.getSize()) ?                 // sets iteration limit to end of larger Integer.
        limit = this->getSize() : limit = subject.getSize();
        
        if (this->getSize() > subject.getSize())                // if Integer calling compare is larger, iterate down indices.
        {
            for (size_t i = subject.getSize(); i < limit; ++i)  // return true if it has a higher significant digit.
            {
                if (bits[i] == true)
                {
                    return true;
                }
            }
        }
        else                                                    // if parameter Integer is larger, iterate down its indices.
        {
            for (size_t i = this->getSize(); i < limit; ++i)    // return false if it has a higher significant digit.
            {
                if (subject.getBit(i) == true)
                {
                    return false;
                }
            }
        }
    }
    else                                                        // Case when both Integers have same size.
    {
        for (long i = this->getSize() - 1; i >= 0; --i)
        {
            if (bits[i] > subject.getBit(i))                    // return true/false based on which of the two
            {                                                   // dominates a disagreement at a higher significant
                return true;                                    // digit. Do so by iterating down indices and checking.
            }
            else if (bits[i] < subject.getBit(i))
            {
                return false;
            }
        }
    }
    return true;                                                // No disagreements. They are equal, return true.
}


/** Multiplies two Integers by adding the larger to itself the smaller number of times.
    It uses the compare function and plus_equals function to perform this.
 
 @param rhs     const Integer reference to parameter Integer.
 
 @returns       *this with final value after multiplication.
 
 */

void Integer::times_equals(const Integer& rhs)
{
    Integer increment = 1;
    
    if (((getSize() == 1)&&(bits[0] == false)) || ((rhs.getSize() == 1)&&(rhs.getBit(0) == false))) //case when either is zero.
    {
        bits.assign(1, false);
    }
    else if (this->compare(rhs) == true)       // *this is larger, its initial value gets added to it rhs number of times.
    {
        Integer temp = *this;
        
        for (Integer i = 1; i.compare(rhs) != true; i.plus_equals(increment))
        {
            this->plus_equals(temp);
        }
    }
    else                                       // rhs is larger, *this gets initial value of rhs, and this value is added to it
    {                                          // *this number of times.
        Integer limit = *this;
        *this = rhs;
        Integer temp = rhs;
        
        for (Integer i = 1; i.compare(limit) != true; i.plus_equals(increment))
        {
            this->plus_equals(temp);
        }
    }
    this->clean_up();                          // clean up any trailing zeros.
}

/** Overloaded *= operator by using times_equals function in its implementation.
 
 @param     const Intgeger reference to rhs
 
 @returns   Integer reference to modified *this
 
 */

Integer& Integer::operator*=(const Integer& rhs)
{
    this->times_equals(rhs);
    return *this;
}

/** Adds two Integers and returns value of sum.
 
 @param lhs     Integer whose value is modified and returned by function.
 @param rhs     Reference to Integer, second parameter to be added.
 
 @returns       Value of sum.
 
 */

Integer plus(Integer lhs, const Integer& rhs)
{
    lhs.plus_equals(rhs);
    return lhs;
}

/** Overloaded int to int adition (+) operator by using plus non-member function in its implementation.
 
 @param lhs     Integer to be added
 @param rhs     const reference to parameter Integer to be added
 
 @returns       Integer value of sum
 
 */

Integer operator+(Integer lhs, const Integer& rhs)
{
    return plus(lhs, rhs);
}

/** Multiplies two Integers and returns value of product.
 
 @param lhs     Integer that gets modified in function.
 @param rhs     Reference to Integer, second parameter to be multiplies.
 
 @returns       Value of product.
 
 */

Integer multiply(Integer lhs, const Integer& rhs)
{
    lhs.times_equals(rhs);
    return lhs;
}

/** Overloaded int by int multiplication (*) operator by using plus non-member function in its implementation.
 
 @param lhs     Integer to be multiplied
 @param rhs     const reference to parameter Integer to be multiplied
 
 @returns       Integer value of product
 
 */

Integer operator*(Integer lhs, const Integer& rhs)
{
    return multiply(lhs, rhs);
}



/////////////////////////////// Overloaded Logical/Boolean Operators ///////////////////////////////



/** Overloaded < operator, returns true if *this is less than parameter Integer.
 
 @param rhs     const Integer reference to parameter Integer.
 
 @returns       boolean *this < rhs.
 
 */

bool Integer::operator<(const Integer& rhs) const
{
    return ((rhs.compare(*this))&&(!(this->compare(rhs))));
}


/** Overloaded == operator, returns true if *this is equal to parameter Integer.
 
 @param rhs     const Integer reference to parameter Integer.
 
 @returns       boolean *this == rhs.
 
 */

bool Integer::operator==(const Integer& rhs) const
{
    return ((this->compare(rhs))&&(rhs.compare(*this)));
}


/** Overloaded <= operator, returns true if *this is less than or equal to parameter Integer.
 
 @param rhs     const Integer reference to parameter Integer.
 
 @returns       boolean *this < rhs.
 
 */

bool operator<=(const Integer& lhs, const Integer& rhs)
{
    return (lhs<rhs)||(lhs==rhs);
}


/** Overloaded > operator, returns true if *this is greater than parameter Integer.
 
 @param rhs     const Integer reference to parameter Integer.
 
 @returns       boolean *this > rhs.
 
*/

bool operator>(const Integer& lhs, const Integer& rhs)
{
    return !(lhs<=rhs);
}


/** Overloaded != operator, returns true if *this not equal parameter Integer.
 
 @param rhs     const Integer reference to parameter Integer.
 
 @returns       boolean *this != rhs.
 
*/

bool operator!=(const Integer& lhs, const Integer& rhs)
{
    return !(lhs==rhs);
}


/** Overloaded >= operator, returns true if *this is greater than or equal to parameter Integer.
 
 @param rhs     const Integer reference to parameter Integer.
 
 @returns       boolean *this >= rhs.
 
*/

bool operator>=(const Integer& lhs, const Integer& rhs)
{
    return !(lhs<rhs);
}



///////////////////////////////////// Output to Console Functions /////////////////////////////////////



/** Outputs Integer to console in base 2 representation.
 
*/

void Integer::print_as_bits() const
{
    unsigned long size = bits.size();
    
    std::cout << "(";
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << bits[bits.size() - i - 1];
    }
    std::cout << ")_2";
}

/** Outputs Integer to console in base 10 representation.
 
*/

void Integer::print_as_int() const
{
    unsigned int output = 0;
    unsigned long size = bits.size();
    
    for (unsigned int i = 0; i < size; ++i)
    {
        output += (bits[i]*power(2, i));
    }
    std::cout << output;
}




