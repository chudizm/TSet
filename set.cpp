// ���������

#include "set.h"

set::set(int mp) :bitf(mp)//�����������
{
	maxPower = mp;
}

set::set(const set &s) : bitf(s.bitf)// ����������� �����������
{
	maxPower = s.maxPower;
}

set::set(const bitfield &bf) : bitf(bf)// ����������� �������������� ����
{
	maxPower = bf.getLength();
}

set::operator bitfield() // �������� �������������� � bitfield
{
	bitfield result(bitf);
	return result;
}

int set::getMaxPower(void) const // ������������ �������� ���������/�������� ����. �-�� ��-���
{
	return maxPower;
}

int set::isMember(const int Elem) const // ��������� ������� �������� � ���������/������� ���������?
{
	return bitf.getBit(Elem);
}
void set::toNull()
{
	for (int i = 0; i < getMaxPower(); i++)
		del(i);
}
void set::ins(const int Elem) // �������� ������� � ���������
{
	if ((Elem < maxPower)&&(Elem >= 0))
		bitf.setBit(Elem);
	else
		cout << "wrong element";
}

void set::del(const int Elem) //������� ������� �� ��������� 
{
	bitf.clrBit(Elem);
}

set& set::operator=(const set &s) // ������������
{
	bitf = s.bitf;
	maxPower = s.getMaxPower();
	return *this;
}

int set::operator==(const set &s) const // ���������
{
	return bitf == s.bitf;
}

int set::operator!=(const set &s) const // ���������
{
	return bitf != s.bitf;
}

set set::operator+(const set &s) // �����������
{
	set result(bitf | s.bitf);
	return result;
}

set set::operator+(const int Elem) // ����������� � ���������
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

set set::operator-(const int Elem) // �������� � ���������
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

set set::operator*(const set &s) // �����������
{
	set result(bitf & s.bitf);
	return result;
}

set set::operator~(void) // ����������
{
	set result(~bitf);
	return result;
}

void set::outAsBitfield() // ����� ��� ������� ����
{
	for (int i = 0; i < getMaxPower(); i++)
		cout << isMember(i);
}

istream &operator>>(istream &is, set &s) // ����
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

ostream& operator<<(ostream &os, const set &s) // �����
{
	os << "( ";
	for (int i = 0; i < s.getMaxPower(); i++)
		if (s.isMember(i))
			os << i << "; ";
	os << ") ";
	return os;
}