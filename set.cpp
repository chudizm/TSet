// Множество

#include "set.h"

set::set(int mp) :bitf(mp)//конструктор
{
	maxPower = mp;
}

set::set(const set &s) : bitf(s.bitf)// конструктор копирования
{
	maxPower = s.maxPower;
}

set::set(const bitfield &bf) : bitf(bf)// конструктор преобразования типа
{
	maxPower = bf.getLength();
}

set::operator bitfield() // оператор преобразования к bitfield
{
	bitfield result(bitf);
	return result;
}

int set::getMaxPower(void) const // Максимальная мощность множества/получить макс. к-во эл-тов
{
	return maxPower;
}

int set::isMember(const int Elem) const // Проверить наличие элемента в множестве/элемент множества?
{
	return bitf.getBit(Elem);
}
void set::toNull()
{
	for (int i = 0; i < getMaxPower(); i++)
		del(i);
}
void set::ins(const int Elem) // Включить элемент в множество
{
	if ((Elem < maxPower)&&(Elem >= 0))
		bitf.setBit(Elem);
	else
		cout << "wrong element";
}

void set::del(const int Elem) //Удалить элемент из множества 
{
	bitf.clrBit(Elem);
}

set& set::operator=(const set &s) // присваивание
{
	bitf = s.bitf;
	maxPower = s.getMaxPower();
	return *this;
}

int set::operator==(const set &s) const // сравнение
{
	return bitf == s.bitf;
}

int set::operator!=(const set &s) const // сравнение
{
	return bitf != s.bitf;
}

set set::operator+(const set &s) // объединение
{
	set result(bitf | s.bitf);
	return result;
}

set set::operator+(const int Elem) // объединение с элементом
{
	if (Elem > bitf.getLength())
	{
		throw ("Elem > Length");
	}
	bitfield temp(maxPower);
	temp.setBit(Elem);
	set result(bitf | temp);
	return result;
}

set set::operator-(const int Elem) // разность с элементом
{
	if (Elem > bitf.getLength())
	{
		throw ("Elem > Length");
	}
	bitfield temp(maxPower);
	temp.setBit(Elem);
	set result(bitf & temp);
	return result;
}

set set::operator*(const set &s) // пересечение
{
	set result(bitf & s.bitf);
	return result;
}

set set::operator~(void) // дополнение
{
	set result(~bitf);
	return result;
}

void set::outAsBitfield() // вывод как битовое поле
{
	for (int i = 0; i < getMaxPower(); i++)
		cout << isMember(i);
}

istream &operator>>(istream &is, set &s) // ввод
{
	s.toNull();
	int d;
	for (int i = 0; i < s.getMaxPower(); i++)
	{
		is >> d;
		if (d != -1)
			s.ins(d);
		else
			break;
	}
	return is;
}

ostream& operator<<(ostream &os, const set &s) // вывод
{
	os << "( ";
	for (int i = 0; i < s.getMaxPower(); i++)
		if (s.isMember(i))
			os << i << "; ";
	os << ") ";
	return os;
}