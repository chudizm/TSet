#pragma once
#include "bitfield.h"
#include <iostream>

class set
{
private:
  int maxPower;       // максимальная мощность множества
  bitfield bitf; // битовое поле для хранения характеристического вектора
  void toNull();	  // обнулить мн-во
public:
  set(int mp);
  set(const set &s);       // конструктор копирования
  set(const bitfield &bf); // конструктор преобразования типа
  operator bitfield();      // преобразование типа к битовому полю
  // доступ к битам
  int getMaxPower(void) const;     // максимальная мощность множества
  void ins(const int Elem);       // включить элемент в множество
  void del(const int Elem);       // удалить элемент из множества
  int isMember(const int Elem) const; // проверить наличие элемента в множестве
  // теоретико-множественные операции
  int operator== (const set &s) const; // сравнение
  int operator!= (const set &s) const; // сравнение
  set& operator=(const set &s);  // присваивание
  set operator+ (const int Elem); // объединение с элементом
                                   // элемент должен быть из того же универса
  set operator- (const int Elem); // разность с элементом
                                   // элемент должен быть из того же универса
  set operator+ (const set &s);  // объединение
  set operator* (const set &s);  // пересечение
  set operator~ (void);           // дополнение
  void outAsBitfield();			   // вывод множества как битового поля
  friend istream &operator>>(istream &is, set &bf);
  friend ostream &operator<<(ostream &os, const set &bf);
};