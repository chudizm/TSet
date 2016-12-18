#pragma once
#include <iostream>

using namespace std;

typedef unsigned int TELEM;

class bitfield
{
private:
  int  bitLength; // ����� �������� ���� - ����. �-�� �����
  TELEM *pMem; // ������ ��� ������������� �������� ����
  int  memLength; // �-�� ��-��� ��� ��� ������������� ���.����
  unsigned int bitInTELEM; // = sizeof(TELEM)* 8; // ��� � ������ ������ �� ������� ���������� ������
  int deg;//bitInTELEM - ��� ��� � ������� deg �� ������� ���������� ������
  // ������ ����������
  int   getIndex(const int n) const; // ������ � p��� ��� ���� n       (#�2)
  TELEM getBitMask (const int n) const; // ������� ����� ��� ���� n       (#�3)
public:
  bitfield(int len);                //                                   (#�1)
  bitfield(const bitfield &bf);    //                                   (#�1)
  ~bitfield();                      //                                    (#�)
  // ������ � �����
  int getLength(void) const;      // �������� ����� (�-�� �����)           (#�)
  void setBit(const int n);       // ���������� ���                       (#�4)
  void clrBit(const int n);       // �������� ���                         (#�2)
  int  getBit(const int n) const; // �������� �������� ����               (#�1)
  // ������� ��������
  int operator==(const bitfield &bf) const; // ���������                 (#�5)
  int operator!=(const bitfield &bf) const; // ���������
  bitfield& operator=(const bitfield &bf); // ������������              (#�3)
  bitfield  operator|(const bitfield &bf); // �������� "���"            (#�6)
  bitfield  operator&(const bitfield &bf); // �������� "�"              (#�2)
  bitfield  operator~(void);                // ���������                  (#�)
  friend istream &operator>>(istream &is, bitfield &bf);       //      (#�7)
  friend ostream &operator<<(ostream &os, const bitfield &bf); //      (#�4)
};