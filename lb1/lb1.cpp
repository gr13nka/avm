#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string.h>

template<typename T>
unsigned long long printBinaryNum(T num)
{
	unsigned long long bits = *reinterpret_cast<unsigned long long*>(&num);
	int byte = 8;

    for (int i = sizeof(long) * byte - 1; i >= 0; --i) {
        std::cout << ((bits >> i) & 1);
    }

    std::cout << '\n';
	return bits;
}
void read_values(int& start, int& amount, int& times, int& direction)
{
	std::cout << "Enter from which bit to move"<< '\n';
	std::cin >> start;
	std::cout << "Enter amount of bit to move"<< '\n';
	std::cin >> amount;
	std::cout << "Enter in which direction to move, 1 for right and 0 for left"<< '\n';
	std::cin >> direction;
	std::cout << "Enter how many times to move"<< '\n';
	std::cin >> times;

	times = times % amount;
}

unsigned long long cycle_move(unsigned long long bits)
{
	int start, amount, times, direction;
//	read_values(start, amount, times, direction);
	start = direction = 0;
	amount = 3;
	times = 1;

	unsigned long long Max = 922337203685477600;
	int bittomove = 0;

	if(times == amount)
		return bits;

	int changed_bits[64] = {0};
	
	//filling array
	for(int i = 64; i>=0; --i)
	{
		changed_bits[i] = (bits>>i)&1;
		std::cout << changed_bits[i];
	}
	std::cout << '\n';

	int last;
	for(int i = 0; i<=times; i++)
	{
		last = changed_bits[amount];

		for(int j = start+1; j<amount-1; j++)
		{
			changed_bits[j] = changed_bits[j+1];
		}

		changed_bits[start] = last;
	}
	
	for(int i = 64; i>=0; --i)
	{
		std::cout << changed_bits[i];
	}

return  bits;
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
	//std::cin >> d;

	std::cout << "Enter long "<< '\n';
//	std::cin >> l;

    std::cout << "Binary representation of double: ";
    d_result = printBinaryNum(d);

    std::cout << "Binary representation of long: ";
    l_result = printBinaryNum(l);

	cycle_move(l_result);
		
    return 0;
}
