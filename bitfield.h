#pragma once
#include <iostream>

using namespace std;

typedef unsigned int TELEM;

class bitfield
{
private:
  int  bitLength; // длина битового поля - макс. к-во битов
  TELEM *pMem; // память для представления битового поля
  int  memLength; // к-во эл-тов Мем для представления бит.поля
  unsigned int bitInTELEM; // = sizeof(TELEM)* 8; // бит в ячейке памяти на текущей аппаратной машине
  int deg;//bitInTELEM - это два в степени deg на текущей аппаратной машине
  // методы реализации
  int   getIndex(const int n) const; // индекс в pМем для бита n       (#О2)
  TELEM getBitMask (const int n) const; // битовая маска для бита n       (#О3)
public:
  bitfield(int len);                //                                   (#О1)
  bitfield(const bitfield &bf);    //                                   (#П1)
  ~bitfield();                      //                                    (#С)
  // доступ к битам
  int getLength(void) const;      // получить длину (к-во битов)           (#О)
  void setBit(const int n);       // установить бит                       (#О4)
  void clrBit(const int n);       // очистить бит                         (#П2)
  int  getBit(const int n) const; // получить значение бита               (#Л1)
  // битовые операции
  int operator==(const bitfield &bf) const; // сравнение                 (#О5)
  int operator!=(const bitfield &bf) const; // сравнение
  bitfield& operator=(const bitfield &bf); // присваивание              (#П3)
  bitfield  operator|(const bitfield &bf); // операция "или"            (#О6)
  bitfield  operator&(const bitfield &bf); // операция "и"              (#Л2)
  bitfield  operator~(void);                // отрицание                  (#С)
  friend istream &operator>>(istream &is, bitfield &bf);       //      (#О7)
  friend ostream &operator<<(ostream &os, const bitfield &bf); //      (#П4)
};