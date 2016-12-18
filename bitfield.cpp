// Битовое поле

#include "bitfield.h"

bitfield::bitfield(int len) 
{
	deg = 0;
	bitInTELEM = sizeof(TELEM)* 8;
	TELEM bits;
	if (len<=0) {
		throw ("Len<0"); //invalid_argument("Len<0...");
	}
	if (deg == 0)
	{
		if (bitInTELEM == 8)  deg = 3;
		if (bitInTELEM == 16) deg = 4;
		if (bitInTELEM == 32) deg = 5;
		if (bitInTELEM == 64) deg = 6;
		if (bitInTELEM == 128) deg = 7;
	}
	bits = (len + (bitInTELEM - 1)) >> deg;
	memLength = bits;
	bitLength = len;
	pMem = new TELEM[memLength];
	if (pMem != NULL)
	for (int i = 0; i < memLength; i++)	
		pMem[i] = 0;
}

bitfield::bitfield(const bitfield &bf) // конструктор копирования
{
	deg = 0;
	bitInTELEM = sizeof(TELEM)* 8;
	bitLength = bf.bitLength;
	memLength = bf.memLength;
	pMem = new TELEM[memLength];
	if (pMem != NULL)	
	for (int i = 0; i < memLength; i++)	
		pMem[i] = bf.pMem[i];
}

bitfield::~bitfield() {
	if (pMem != NULL) {
		delete[]pMem;
		pMem = NULL;
	}
	if (pMem) {
		std::cout << "Error clean " << pMem << std::endl;
	}
}

int bitfield::getIndex(const int n) const // индекс Мем для бита n
{
	return n >> deg;
}

TELEM bitfield::getBitMask(const int n) const // битовая маска для бита n
{
	return 1 << (n & (bitInTELEM - 1));
}

int bitfield::getLength(void) const // получить длину (к-во битов)
{
	return bitLength;
}

void bitfield::setBit(const int n) // установить бит
{
	if (n<0) {
		throw ("Bit < 0..."); //invalid_argument("Bit < 0...");
	}
	if (n>=bitLength) {
		throw ("bitLength < n..."); //invalid_argument("bitLength < n...");
	}
	pMem[getIndex(n)] = pMem[getIndex(n)] |= getBitMask(n);
}

void bitfield::clrBit(const int n) // очистить бит
{
	if (n<0) {
		throw ("Bit < 0..."); //invalid_argument("Bit < 0...");
	}
	if (n >= bitLength) {
		throw ("bitLength < n..."); //invalid_argument("bitLength < n...");
	}
	pMem[getIndex(n)] = pMem[getIndex(n)] &= ~getBitMask(n);
}

int bitfield::getBit(const int n) const // получить значение бита
{
	if (n<0) {
		throw ("n < 0..."); //invalid_argument("n < 0...");
	}
	if (n >= bitLength) {
		throw ("bitLength < n..."); //alid_argument("bitLength < n...");
	}
	if ((pMem[getIndex(n)] & getBitMask(n)) == 0) return 0;
	else return 1;
}


bitfield& bitfield::operator=(const bitfield &bf) // присваивание
{
	if (pMem != bf.pMem) {
		bitLength = bf.bitLength;
		memLength = bf.memLength;
		delete[]pMem;
		pMem = new TELEM[memLength];
		for (int i = 0; i < memLength; i++) {
			pMem[i] = bf.pMem[i];
		}
	}
	return *this;
}

int bitfield::operator==(const bitfield &bf) const // сравнение
{
	int result = 1;
	if (bitLength != bf.bitLength) result = 0;
	else
	for (int i = 0; i < memLength; i++)
	if (pMem[i] != bf.pMem[i]) { result = 0; break; }
	return result;
}

int bitfield::operator!=(const bitfield &bf) const // сравнение
{
	if (*this == bf) return 0; else return 1;
}

bitfield bitfield::operator|(const bitfield &bf) // операция "или"
{
	int tmpbitLength;//tmpbitLength хранит максимальную длину поля
	int minMem;//minMem хранит максимальное количество ячеек TELEM
	int n = 0;//счетчик
	if (bitLength >= bf.bitLength)
	{
		tmpbitLength = bitLength;
		minMem = memLength;
	}
	else
	{
		tmpbitLength = bf.bitLength;//tmpbitLength хранит максимальную длину поля
		minMem = bf.memLength;//minMem хранит максимальное количество ячеек TELEM
	}
	bitfield tmp(tmpbitLength);
	while (n<minMem) {
		tmp.pMem[n] = pMem[n] | bf.pMem[n];
		n++;
	}
	return tmp;
}

bitfield bitfield::operator&(const bitfield &bf) // операция "и"
{
	int tmpbitLength;//tmpbitLength хранит максимальную длину поля
	int minMem;//minMem хранит максимальное количество ячеек TELEM
	int n = 0;//счетчик
	if (bitLength >= bf.bitLength)
	{
		tmpbitLength = bitLength;
		minMem = memLength;
	}
	else
	{
		tmpbitLength = bf.bitLength;//tmpbitLength хранит максимальную длину поля
		minMem = bf.memLength;//minMem хранит максимальное количество ячеек TELEM
	}
	bitfield tmp(tmpbitLength);
	while (n<minMem) {
		tmp.pMem[n] = pMem[n] & bf.pMem[n];
		n++;
	}
	return tmp;
}

bitfield bitfield::operator~(void) // отрицание
{
	bitfield tmp(bitLength);
	for (int i = 0; i < bitLength; i++)
	{
		if (getBit(i) == 1) tmp.clrBit(i);
		else tmp.setBit(i);
	}
	return tmp;	
}

ostream& operator<<(ostream &os, const bitfield &bf) // вывод
{
	for (int i = 0; i < bf.bitLength; i++)
		os << bf.getBit(i);
	return os;
}
istream& operator>>(istream &is, bitfield &bf) // ввод
{
	char c;
	for (int i = 0; i < bf.bitLength; i++)
	{
		is >> c;
		if (c == '1') bf.setBit(i); else bf.clrBit(i);
	}
	return is;
}