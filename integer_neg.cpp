/** @file   integer_neg.cpp
 @author Rishabh Prakash
 @SID    904319716
 @date   01/07/2015
 
 
 Creates class Integer, defining operations on it's objects,
 mimmicking the way int data types are stored on a computer
 and are operated upon.
 
 Stores Integers in sign and magnitude format as objects with
 a private member std::vector of bools, whose ith indices
 match the (i-1)th power of 2. 0th index stores sign.
 
 */

#include <iostream>
#include <vector>
#include <string>


///////////////////////// Declaration of Integer Class and Non-member Functions ///////////////////////


/** @class Integer
 
 @brief Stores Integers in binary as a std::vector of bools, with
 indices matching respective powers of 2.
 
 Integers stored as std::vector of bools as private member bits.
 
 */

class Integer {
public:
    Integer();
    Integer(int a);
    Integer(std::vector<bool> a);
    Integer(std::string a);
    
    bool getBit(unsigned long i) const;
    unsigned long getSize() const;
    
    bool compare(const Integer& subject) const;
    
    Integer& operator+=(const Integer& rhs);
    Integer& operator-=(const Integer& rhs);
    Integer& operator*=(const Integer& rhs);
    
    Integer operator+();
    Integer operator-();
    
    Integer& operator++();
    Integer& operator--();
    
    Integer operator++(int unused);
    Integer operator--(int unused);
    
    bool operator<(const Integer& rhs) const;
    bool operator==(const Integer& rhs) const;
    
    void print_as_int();
    void print_as_bits();
    
    Integer& operator&=(const Integer& rhs);
    Integer& operator|=(const Integer& rhs);
    Integer& operator^=(const Integer& rhs);
    Integer& operator>>=(const Integer& rhs);
    Integer& operator<<=(const Integer& rhs);
    
    Integer operator~();
    
private:
    std::vector<bool> bits;
    void clean_up();
    void setBit(bool value, unsigned int index);
    void addBit(bool value);
};

Integer operator+(Integer lhs, const Integer& rhs);
Integer operator-(Integer lhs, const Integer& rhs);
Integer operator*(Integer lhs, const Integer& rhs);

unsigned int power(unsigned int base, unsigned int exponent);
Integer TwosComplement(const Integer rhs);

bool operator> (const Integer& lhs, const Integer& rhs);
bool operator!=(const Integer& lhs, const Integer& rhs);
bool operator<=(const Integer& lhs, const Integer& rhs);
bool operator>=(const Integer& lhs, const Integer& rhs);

Integer operator&(Integer lhs, const Integer& rhs);
Integer operator|(Integer lhs, const Integer& rhs);
Integer operator^(Integer lhs, const Integer& rhs);
Integer operator>>(Integer lhs, const Integer& rhs);
Integer operator<<(Integer lhs, const Integer& rhs);


int main()
{
//    std::string input = "10";
//    Integer a = input;
//   
//    a.print_as_bits(); std::cout << std::endl;
   
    
    int int_value;
    
    std::cout << "Please input an integer a: ";
    std::cin >> int_value;
    Integer a = int_value; // Create Integer type with input value
    
    std::cout << "The base-2 representation of a is: "; a.print_as_bits(); std::cout << std::endl;
    
    std::cout << "Please input an integer b: ";
    std::cin >> int_value;
    Integer b = int_value; // Create Integer type with input value
    
    std::cout << "The base-2 representation of b is: "; b.print_as_bits(); std::cout << std::endl;
    
    // Lets do some basic arithmetic
    
    Integer plusequals = a; plusequals += b;
    plusequals.print_as_bits(); std::cout << std::endl;
    
    Integer minusequals = a; minusequals -= b;
    minusequals.print_as_bits(); std::cout << std::endl;
    
    Integer timesequals = a; timesequals *= b;
    timesequals.print_as_bits(); std::cout << std::endl;
    
    Integer plus = a + b;   plus.print_as_bits(); std::cout << std::endl;       // a + b
    Integer minus = a - b;  minus.print_as_bits(); std::cout << std::endl;      // a * b
    Integer times = a * b;  times.print_as_bits(); std::cout << std::endl;
    
    Integer prefix_increment = ++a; prefix_increment.print_as_bits(); std::cout << std::endl;
    Integer postfix_increment = a++; postfix_increment.print_as_bits(); std::cout << std::endl;
    
    Integer prefix_decrement = --a; prefix_decrement.print_as_bits(); std::cout << std::endl;
    Integer postfix_decrement = a--; postfix_decrement.print_as_bits(); std::cout << std::endl;
    
    Integer negative = -a; negative.print_as_bits(); std::cout << std::endl;
    Integer positive = +b; positive.print_as_bits(); std::cout << std::endl;
    
    
    // Obtain two more integer values from user
    
    std::cout << "Please input an integer c: ";
    std::cin >> int_value;
    Integer c = int_value; // Create Integer type with input value
    
    std::cout << "The base-2 representation of a is: "; c.print_as_bits(); std::cout << std::endl;
    
    std::cout << "Please input an integer d: ";
    std::cin >> int_value;
    Integer d = int_value; // Create Integer type with input value
    
    std::cout << "The base-2 representation of b is: "; d.print_as_bits(); std::cout << std::endl;
    

    // Comparison operators
    
    if (c>d)    std::cout << "c > d"  << std::endl;
    if (c>=d)   std::cout << "c >= d" << std::endl;
    if (c<d)    std::cout << "c < d"  << std::endl;
    if (c<=d)   std::cout << "c <= d" << std::endl;
    if (c==d)   std::cout << "c == d" << std::endl;
    if (c!=d)   std::cout << "c != d" << std::endl;
    
    Integer andequals = c; andequals &= d;
    andequals.print_as_bits(); std::cout << std::endl;
    
    Integer orequals = c; orequals |= d;
    orequals.print_as_bits(); std::cout << std::endl;
    
    Integer xorequals = c; xorequals ^= d;
    xorequals.print_as_bits(); std::cout << std::endl;
    
    Integer shiftupequals = c; shiftupequals <<= 2;
    shiftupequals.print_as_bits(); std::cout << std::endl;
    
    Integer shiftdownequals = c; shiftdownequals >>= 1;
    shiftdownequals.print_as_bits(); std::cout << std::endl;
    
    Integer negation = ~c; negation.print_as_bits(); std::cout << std::endl;
    
    Integer the_and = c & d; the_and.print_as_bits(); std::cout << std::endl;
    Integer the_or = c | d; the_or.print_as_bits(); std::cout << std::endl;
    Integer the_xor = c ^ d; the_xor.print_as_bits(); std::cout << std::endl;
    
    Integer shift_up = c << 2; shift_up.print_as_bits(); std::cout << std::endl;
    Integer shift_down = d >> 2; shift_down.print_as_bits(); std::cout << std::endl;
    
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

Integer::Integer(int a)
{
    if ( a >= 0)
    {
        bits.push_back(false);
        
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
    else if ( a < 0 )
    {
        bits.push_back(true);
        
        for (size_t i = 0; -a > 0; i++)
        {
            bits.push_back((-a)%2);
            a = a/2;
        }
    }
}

Integer::Integer(std::string a)
{
    Integer base = 1;
    Integer output  = 0;
    
    unsigned long length = a.length();
    for(unsigned long i = 0; i < length; ++i)
    {
        unsigned int current = static_cast<unsigned int>(a[i]);
        if((current < 48)||(current > 57))
        {
            std::cout << "Invalid input! Integer initialized to zero." << std::endl;
            bits = {false, false};
        }
        
        Integer int_current = a[length - i - 1];
        output += (int_current*base);
        base *= 10;
    }
    *this = output;
}


/** Clean Up: removes trailing zeroes in binary.
 
 */

void Integer::clean_up()
{
    for (long i = bits.size() - 1; i > 1; --i)
    {
        if (bits[i] == true)
        {
            break;
        }
        bits.pop_back();
    }
}

void Integer::setBit(bool value, unsigned int index)
{
    bits[index] = value;
}

void Integer::addBit(bool value)
{
    bits.push_back(value);
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


///////////////////////////////////// Output to Console Functions /////////////////////////////////////



/** Outputs Integer to console in base 2 representation.
 
 */

void Integer::print_as_bits()
{
    this->clean_up();
    
    unsigned long size = bits.size();
    
    if (bits[0] == true)
    {
        std::cout << "-";
    }
    else
    {
        std::cout << " ";
    }
    
    std::cout << "(";
    for (size_t i = bits.size() - 1; i > 0; --i)
    {
        std::cout << bits[i];
    }
   
    std::cout << ")_2";
}

/** Outputs Integer to console in base 10 representation.
 
 */

void Integer::print_as_int()
{
    int output = 0;
    unsigned long size = bits.size();
    
    for (unsigned int i = 1; i < size; ++i)
    {
        output += (bits[i]*power(2, i-1));
    }
    
    if (bits[0] == 1)
    {
        std::cout << (-output);
    }
    else
    {
        std::cout << " " << output;
    }
}


/////////////////////////////////// Overloaded Bitwise Operators ///////////////////////////////////

/** Performs bitwise & on Integer
 
 */

Integer& Integer::operator&=(const Integer& rhs)
{
    
    if (getSize() >= rhs.getSize())       // case when *this is larger in size than parameter integer.
    {
        size_t i = 0;
        for (i = 0; i < rhs.getSize(); ++i)
        {
            bits[i] = bits[i]&rhs.getBit(i);
        }
        for (size_t j = i; j < getSize(); ++j)    // iteration for indices after end of smaller integer.
        {
            bits[i] = false;
        }
        
        this->clean_up();
        return *this;
    }
    else                                // case when *this is larger in size than parameter integer.
    {
        size_t i = 0;
        for (i = 0; i < getSize(); ++i)
        {
            bits[i] = bits[i]&rhs.getBit(i);
        }
        for (size_t j = i; j < rhs.getSize(); ++j)    // iteration for indices after end of smaller integer.
        {
            bits.push_back(false);
        }
        
        this->clean_up();
        return *this;
    }
}

/** Performs bitwise | on Integer
 
 */

Integer& Integer::operator|=(const Integer& rhs)
{
    if (getSize() >= rhs.getSize())       // case when *this is larger in size than parameter integer.
    {
        size_t i = 0;
        for (i = 0; i < rhs.getSize(); ++i)
        {
            bits[i] = bits[i]|rhs.getBit(i);
        }
        
        this->clean_up();
        return *this;
    }
    else                                // case when *this is larger in size than parameter integer.
    {
        size_t i = 0;
        for (i = 0; i < getSize(); ++i)
        {
            bits[i] = bits[i]|rhs.getBit(i);
        }
        for (size_t j = i; j < rhs.getSize(); ++j)    // iteration for indices after end of smaller integer.
        {
            bits.push_back(rhs.getBit(j));
        }
        
        this->clean_up();
        return *this;
    }

}

/** Performs bitwise ^ on Integer
 
 */

Integer& Integer::operator^=(const Integer& rhs)
{
    if (getSize() >= rhs.getSize())       // case when *this is larger in size than parameter integer.
    {
        size_t i = 0;
        for (i = 0; i < rhs.getSize(); ++i)
        {
            bits[i] = bits[i]^rhs.getBit(i);
        }
        for (size_t j = i; j < getSize(); ++j)    // iteration for indices after end of smaller integer.
        {
            bits[j] = bits[j]^false;
        }
        
        this->clean_up();
        return *this;
    }
    else                                // case when *this is larger in size than parameter integer.
    {
        size_t i = 0;
        for (i = 0; i < getSize(); ++i)
        {
            bits[i] = bits[i]^rhs.getBit(i);
        }
        for (size_t j = i; j < rhs.getSize(); ++j)    // iteration for indices after end of smaller integer.
        {
            bits.push_back(rhs.getBit(j)^false);
        }
        
        this->clean_up();
        return *this;
    }

}

/** Performs bitwise downshift by parameter Integer, on Integer
 
 */

Integer& Integer::operator>>=(const Integer& rhs)
{
    std::vector<bool>::iterator i = bits.begin();
    
    for (Integer counter = 0; counter != rhs; ++counter)
    {
        bits.erase(++i);
        i = bits.begin();
        
        if (bits.size() == 1)
        {
            bits.assign(2, false);
            return *this;
        }
    }
    return *this;
}

/** Performs bitwise upshift by parameter Integer, on Integer
 
 */

Integer& Integer::operator<<=(const Integer& rhs)
{
    std::vector<bool>::iterator i = bits.begin();
    
    for (Integer counter = 0; counter != rhs; ++counter)
    {
        bits.insert(++i, false);
        i = bits.begin();
    }
    return *this;
}

/** Performs bitwise negation on Integer
 
 */
Integer Integer::operator~()
{
    Integer clone = *this;
    unsigned long size = clone.getSize();
    
    for (size_t i = 0; i < size; ++i)
    {
        clone.setBit(!(bits[i]), i);
    }
    
    return clone;
}

// Overloaded binary bitwise operators, using member bitwise function implementations.


Integer operator&(Integer lhs, const Integer& rhs)
{
    return lhs&=rhs;
}

Integer operator|(Integer lhs, const Integer& rhs)
{
    return lhs|=rhs;
}

Integer operator^(Integer lhs, const Integer& rhs)
{
    return lhs^=rhs;
}

Integer operator>>(Integer lhs, const Integer& rhs)
{
    return lhs>>=rhs;
}

Integer operator<<(Integer lhs, const Integer& rhs)
{
    return lhs<<=rhs;
}



///////////////////// Arithmetic Functions and Overloaded Arithmetic Operators /////////////////////



/** Overloaded += operator by, adds value of parameter integer to Integer invoking.
 
 @param     const Integer reference to rhs
 
 @returns   Integer reference to modified *this
 
 */
Integer& Integer::operator+=(const Integer& rhs)
{
    if ((bits[0] == false)&&(rhs.getBit(0) == false))
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
        return *this;
    }
    
    else if ((bits[0] == true)&&(rhs.getBit(0) == true))
    {
        Integer intClone;
        unsigned long rhsSize = rhs.getSize();
        for (size_t i = 0; i < rhsSize; ++i)
        {
            intClone.addBit(rhs.getBit(i));
        }
        
        intClone.setBit(false, 0);
        this->setBit(false, 0);
        
        *this+=intClone;
        
        bits[0] = true;
        return *this;
    }
    
    
    else if ((bits[0] == true)&&(rhs.getBit(0) == false))
    {
        Integer integerClone;
        unsigned long rhsSize = rhs.getSize();
        for (size_t i = 0; i < rhsSize; ++i)
        {
            integerClone.addBit(rhs.getBit(i));
        }
        
        if (this->getSize() > integerClone.getSize())
        {
            unsigned long limit = this->getSize();
            for (size_t i = integerClone.getSize(); i < limit; ++i)
            {
                integerClone.addBit(false);
            }
        }
        else if (this->getSize() < integerClone.getSize())
        {
            unsigned long limit = integerClone.getSize();
            for (size_t i = this->getSize(); i < limit; ++i)
            {
                bits.push_back(false);
            }
        }
        
        // Convert to Two's Complement for arithmetic
        bits[0] = false;
        
        unsigned long size = this->getSize();
        for (size_t i = 0; i < size; ++i)
        {
            bits[i] = ~bits[i];
        }
        
        bits[0] = false;
        (*this)+=1;
        bits[0] = true;
        
        
        // Perform addition using two's complement
        bool carryover = false;
        
        size_t i = 0;
        unsigned long end = integerClone.getSize();
        for (i = 0; i < end; ++i)
        {
            if ((bits[i] + integerClone.getBit(i) + carryover) == 0)
            {
                bits[i] = false;
                carryover = false;
            }
            else if ((bits[i] + integerClone.getBit(i) + carryover) == 1)
            {
                bits[i] = true;
                carryover = false;
            }
            else if ((bits[i] + integerClone.getBit(i) + carryover) == 2)
            {
                bits[i] = false;
                carryover = true;
            }
            else if ((bits[i] + integerClone.getBit(i) + carryover) == 3)
            {
                bits[i] = true;
                carryover = true;
            }
        }
        
        // Convert back to sign and magnitude
        if ((carryover == true)&&(bits[0] == true))
        {
            bits[0] = false;
        }
        else if ((carryover == false)&&(bits[0] == true))
        {
            unsigned long j = this->getSize();
            for (size_t i = 1; i < j; ++i)
            {
                bits[i] = ~bits[i];
            }
            
            this->setBit(false, 0);
            (*this)+=1;
            this->setBit(true, 0);
        }
        return *this;
    }
    

    else if ((bits[0] == false)&&(rhs.getBit(0) == true))
    {
        Integer rhsCopy = rhs;
        rhsCopy.setBit(false, 0);
        bits[0] = true;
        
        (*this)+=rhsCopy;
        
        if (bits[0] == true)
        {
            bits[0] = false;
        }
        else
        {
            bits[0] = true;
        }
    
        return *this;
    }
    return *this;
}

/** Adds two Integers and returns value of sum.
 
 @param lhs     Integer whose value is modified and returned by function.
 @param rhs     Reference to Integer, second parameter to be added.
 
 @returns       Value of sum.
 
 */

Integer operator+(Integer lhs, const Integer& rhs)
{
    return lhs+=rhs;
}

/** Unary - operator, reverses sign of Integer.
 
 @returns value of modified Integer

 */

Integer Integer::operator-()
{
    Integer output = *this;
    
    if (bits[0] == true)
    {
        output.setBit(false, 0);
    }
    else
    {
        output.setBit(true, 0);
    }
    return output;
}

/** Overloaded -= operator by, subtracts value of parameter integer to Integer invoking.
 
 @param     const Integer reference to rhs
 
 @returns   Integer reference to modified *this
 
 */


Integer& Integer::operator-=(const Integer& rhs)
{
    Integer clone = rhs;
    clone = -clone;
    
    return (*this)+=clone;
}


/** Subtracts two Integers and returns value of difference.
 
 @param lhs     Integer whose value is modified and returned by function.
 @param rhs     Reference to Integer, second parameter to be added.
 
 @returns       Value of difference.
 
 */
Integer operator-(Integer lhs, const Integer& rhs)
{
    return lhs-=rhs;
}


/** Unary - operator, maintains sign of Integer.
 
 @returns value of modified Integer
 */
Integer Integer::operator+()
{
    Integer output = *this;
    return output;
}

/** Compares two Integers, returns true if *this is greater or equal,
 false if smaller than parameter Integer.
 
 @param subject     const int reference to parameter Integer being compared
 
 @returns           boolean true if *this is greater or equal to,
 false if *this is smaller than parameter Integer.
 
 */

bool Integer::compare(const Integer& subject) const
{
    if ((bits[0] == false)&&(subject.getBit(0) == false))
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
    
    else if ((bits[0] == true)&&(subject.getBit(0) == true))
    {
        Integer clone = subject;
        clone = -clone;
        
        clone+=(*this);
        
        if (clone.getBit(0) == false)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    else
    {
        if (bits[0] == true)
        {
            return false;
        }
        else if (subject.getBit(0) == true)
        {
            return true;
        }
    }
    return true;
}

/** Multiplies two Integers by adding the larger to itself the smaller number of times.
 It uses the compare function and += function to perform this.
 
 @param rhs     const Integer reference to parameter Integer.
 
 @returns       *this with final value after multiplication.
 
 */

Integer& Integer::operator*=(const Integer& rhs)
{
    
    if (((this->getSize() == 2)&&(bits[1] == false)) || ((rhs.getSize() == 2)&&(rhs.getBit(1) == false))) //case when either is zero.
    {
        bits.assign(2, false);
        return *this;
    }

    else if ((bits[0] == false)&&(rhs.getBit(0) == false))
    {
        Integer increment = 1;
        
        
        if (this->compare(rhs) == true)       // *this is larger, its initial value gets added to it rhs number of times.
        {
            Integer temp = *this;
            
            for (Integer i = 1; i.compare(rhs) != true; i+=(increment))
            {
                *this+=(temp);
            }
        }
        else                                       // rhs is larger, *this gets initial value of rhs, and this value is added        to it
        {                                          // *this number of times.
            Integer limit = *this;
            *this = rhs;
            Integer temp = rhs;
            
            for (Integer i = 1; i.compare(limit) != true; i+=(increment))
            {
                *this+=(temp);
            }
        }
        this->clean_up();                          // clean up any trailing zeros.
        return *this;
    }
    
    
    else if ((bits[0] == true)&&(rhs.getBit(0) == false))
    {
        bits[0] = false;
        (*this)*=rhs;
        bits[0] = true;
        
        this->clean_up();                          // clean up any trailing zeros.
        return *this;
    }
    
    else if ((bits[0] == false)&&(rhs.getBit(0) == true))
    {
        Integer clone = rhs;
        clone = -clone;
        
        (*this)*=clone;
        bits[0] = true;
        
        this->clean_up();                          // clean up any trailing zeros.
        return *this;
    }
    
    else
    {
        bits[0] = false;
        Integer clone = rhs;
        clone = -clone;
        
        (*this)*=clone;
        
        this->clean_up();                          // clean up any trailing zeros.
        return *this;
    }
    return *this;
}

/** Multiplies two Integers and returns value of product.
 
 @param lhs     Integer whose value is modified and returned by function.
 @param rhs     Reference to Integer, second parameter to be added.
 
 @returns       Value of product.
 
 */


/** Overloaded * operator using *=
 
 @returns      Integer value of product
*/

Integer operator*(Integer lhs, const Integer& rhs)
{
    return lhs*=rhs;
}

// Overloaded postfix and prefix increment/decrement operators.
// Using +=, -=
// Postfix returns by value, increment after code is executed.
// Prefix returns by reference

Integer& Integer::operator++()
{
    return (*this)+=1;
}

Integer& Integer::operator--()
{
    return (*this)-=1;
}

Integer Integer::operator++(int unused)
{
    Integer clone = *this;
    ++(*this);
    
    return clone;
}

Integer Integer::operator--(int unused)
{
    Integer clone = *this;
    --(*this);
    
    return clone;
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


