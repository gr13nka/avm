#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string.h>

union {
	int num;
	long lnum;
	double dnum;
}data;

int convert_to_bin(float num)
{
	float binary;
	std::string len = std::to_string(num);
	int num_len = len.length();
	std::cout<< len<<'\n';

	for(num_len; num>1 ;num_len--)
	{
		binary = num/(2*num_len);
	}
	
	return binary;
}

int convert_num(float num)
{
	//for float
	int P = 127;

	//convert to bin
	convert_to_bin(15.123456212127);
	std::cout << num;

	return 0;
}

template<typename T>
T read_num()
{
	T num;
	std::cout << "Enter a number" << '\n';
	std::cin >> num;
	return num;
}

void printDoubleBinary(double num) {
    unsigned long long bits = *reinterpret_cast<unsigned long long*>(&num);
	//reinterpret_cast - change type without changing bits
	//double is 64 bits, same as unsigned long long
	int byte = 8;

    for (int i = sizeof(double) * byte - 1; i >= 0; --i) {
        std::cout << ((bits >> i) & 1);
    }

    std::cout << std::endl;
}

unsigned long long printLongBinary(long value) {
    unsigned long long bits = *reinterpret_cast<unsigned long long*>(&value);
	int byte = 8;

    for (int i = sizeof(long) * byte - 1; i >= 0; --i) {
        std::cout << ((bits >> i) & 1);
    }

    std::cout << '\n';
	return bits;
}

void cycle_move(unsigned long long bits)
{
	int i,j,n,direction;
	std::cout << "Enter from which bit to move"<< '\n';
	std::cin >> i;
	std::cout << "Enter until which bit to move"<< '\n';
	std::cin >> j;
	std::cout << "Enter in which direction to move, 1 for right and 0 for left"<< '\n';
	std::cin >> direction;
	std::cout << "Enter how many times to move"<< '\n';
	std::cin >> n;

	int byte = 8;
	unsigned long long changing_bits;
	unsigned long long a[sizeof(bits)];

	//append part of bits to an array
	for (i;i<j;i++)
	{
		a[i] = (bits >> j*byte);
		std::cout<< a[i];
	}

	//cycle the array
	
	

}

int main() {
    double d = 1.5;
    long l = 111111111115;
	unsigned long long d_result;
	unsigned long long l_result;

	//same size 
	std::cout <<"long " << sizeof(long);
	std::cout <<"double " << sizeof(double);
	std::cout <<"unsigned long long" << sizeof(unsigned long long) << '\n';

	std::cout << "Enter double "<< '\n';
	std::cin >> d;

	std::cout << "Enter long "<< '\n';
	std::cin >> l;

    //std::cout << "Binary representation of double: ";
   // d_result = printDoubleBinary(d);

    std::cout << "Binary representation of long: ";
    l_result = printLongBinary(l);


    return 0;
}
