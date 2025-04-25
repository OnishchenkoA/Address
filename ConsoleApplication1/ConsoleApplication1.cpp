#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

class address
{
private:
	std::string town;
	std::string strit;
	int house;
	int apart;
	std::string output_adress{};
public:
	address(std::string town, std::string strit, int house, int apart)
	{
		this->town = town;
		this->strit = strit;
		this->house = house;
		this->apart = apart;
	}

	address()
	{
		std::string town;
		std::string strit;
		int house = 0;
		int apart = 0;
	}

	std::string get_output_address()
	{
		output_adress = town + " , " + strit + " , " + std::to_string(house) + " , " + std::to_string(apart);
		return output_adress;
	}
};

	std::string* mass_addr(int N)
	{
		std::string* addr = new std::string[N]{};
		return addr;
	}

	void del(address* addr, int N)
	{
		delete[]addr;
		addr = NULL;
	}

	void out_adr(address* addr, int N)
	{
		std::ofstream adr1("out.txt");
		if (adr1.is_open())
		{
			adr1 << N << std::endl;
			for (int i = N - 1; i >= 0; i--)
			{
				adr1 << addr[i].get_output_address() << std::endl;
			
			}
		}
		else {
			std::cout << "Ошибка открытия файла!" << std::endl;
		}
		adr1.close();
};

	int main(int argc, char** argv)
	{
		setlocale(LC_ALL, "russian");
		std::string town;
		std::string strit;
		int house = 0;
		int apart = 0;
		std::ifstream adr("in.txt");
		int N = 0;
		adr >> N;
		address* addr = new address[N];
	for (int i = 0; i < N; i++)
	{
		adr >> town >> strit >> house >> apart;
		addr[i] = address(town, strit, house, apart);
	}
	adr.close();
	out_adr(addr, N);
    del(addr, N);
}
	