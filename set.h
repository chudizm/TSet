#pragma once
#include "bitfield.h"
#include <iostream>

class set
{
private:
  int maxPower;       // ������������ �������� ���������
  bitfield bitf; // ������� ���� ��� �������� ������������������� �������
  void toNull();	  // �������� ��-��
public:
  set(int mp);
  set(const set &s);       // ����������� �����������
  set(const bitfield &bf); // ����������� �������������� ����
  operator bitfield();      // �������������� ���� � �������� ����
  // ������ � �����
  int getMaxPower(void) const;     // ������������ �������� ���������
  void ins(const int Elem);       // �������� ������� � ���������
  void del(const int Elem);       // ������� ������� �� ���������
  int isMember(const int Elem) const; // ��������� ������� �������� � ���������
  // ���������-������������� ��������
  int operator== (const set &s) const; // ���������
  int operator!= (const set &s) const; // ���������
  set& operator=(const set &s);  // ������������
  set operator+ (const int Elem); // ����������� � ���������
                                   // ������� ������ ���� �� ���� �� ��������
  set operator- (const int Elem); // �������� � ���������
                                   // ������� ������ ���� �� ���� �� ��������
  set operator+ (const set &s);  // �����������
  set operator* (const set &s);  // �����������
  set operator~ (void);           // ����������
  void outAsBitfield();			   // ����� ��������� ��� �������� ����
  friend istream &operator>>(istream &is, set &bf);
  friend ostream &operator<<(ostream &os, const set &bf);
};