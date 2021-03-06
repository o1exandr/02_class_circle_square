/*
Завдання 2.
Розробити класи Коло(радіус) та Квадрат(сторона). Класи повинні містити  методи обчислення площ фігур(square()) та довжин фігур(length(), довжина кола, периметр квадрата).
Використовуючи  множинне успадкування. визначити клас Коло_Вписане_У_Квадрат чи Квадрат_У_Коло(на вибір), який  містив би методи
o	конструктор за замовчуванням створює фігуру з колом 1 радіуса
o	конструктор  з параметром(передавати сторону квадрата(або радіус), радіус(сторону квадрата) кола перераховувати автоматично  по фомулі)
o	конструктор перетворення квадрата у комбіновану     фігуру(CircleInSquare(const Square &))
o	конструктор перетворення кола у комбіновану     фігуру(CircleInSquare(const Circle &))
o	обчислення  загальної довжини фігури(тобто довжина кола + периметр квадрата),
o	обчислення площі частини фігури ( площа описаної фігури - площа вписаної фігури).
o	встановлення  радіусу фігури(із збереженням пропорцій), метод встановлення радіусу фігури CicleInSquare(або SquareInCircle) повинен автоматично перерахувати сторону квадрата згідно відповідної формули
o	встановлення  сторони квадрата (із збереженням пропорцій), метод встановлення сторони квадрата для фігури CicleInSquare(або SquareInCircle) повинен автоматично перерахувати радіус круга
o	- метод виведення інформації про фігуру на екран
Використати множинне успадкування.
Протестувати роботу класів.

*/

#include "stdafx.h"
#include <iostream> 
#include <string>

double const PI = 3.141592;

using namespace std;

class Circle
{
protected:

	double radius;

public:

	Circle (double radius = 1):radius(radius)
	{}

	double getRadius() const
	{
		return radius;
	}

	void setRadius(double r)
	{
		radius = r;
	}

	double square()
	{
		return PI * radius * radius;
	}

	double length()
	{
		return 2 * PI * radius;
	}

	void print()
	{
		cout << "\n  Circle\nRadius:\t" << radius << "\nLength:\t" << length() << "\nSquare:\t" << square() << endl;
	}
};

class Square
{
protected:

	double side;

public:

	Square(double side = 1) :side(side)
	{}

	double getSide() const
	{
		return side;
	}

	void setSide(double s)
	{
		side = s;
	}

	double square()
	{
		return side * side;
	}

	double length()
	{
		return 4 * side;
	}

	void print()
	{
		cout << "\n  Square\nSide:\t" << side << "\nLength:\t" << length() << "\nSquare:\t" << square() << endl;
	}
};

class SquareInCircle : public Square, public Circle
{
protected:

public:

	//конструктор за замовчуванням створює фігуру з колом 1 радіуса
	SquareInCircle()
	{
		Circle::radius = 1;
		Square::side = sqrt(2);
	}

	//конструктор  з параметром(передавати сторону квадрата, радіус кола перераховувати автоматично  по фомулі)
	SquareInCircle(double side)
	{
		Square::side = side;
		Circle::radius = (sqrt(2) / 2) * side;
	}

	//конструктор перетворення квадрата у комбіновану  фігуру(SquareInCircle(const Square &))
	SquareInCircle(const Square & sqr)
	{
		Square::side = sqr.getSide();
		Circle::radius = (sqrt(2) / 2) * sqr.getSide();
	}

	//конструктор перетворення кола у комбіновану     фігуру(SquareInCircle(const Circle &))
	SquareInCircle(const Circle & crl)
	{
		Circle::radius = crl.getRadius();
		Square::side = crl.getRadius() * sqrt(2);
	}

	//обчислення  загальної довжини фігури(тобто довжина кола + периметр квадрата)
	double getTotalLength()
	{
		return Circle::length() + Square::length();
	}

	//обчислення площі частини фігури ( площа описаної фігури - площа вписаної фігури).
	double getPartSquare()
	{
		return Circle::length() - Square::length();
	}

	//встановлення  радіусу фігури(із збереженням пропорцій), метод встановлення радіусу фігури SquareInCircle
	//повинен автоматично перерахувати сторону квадрата згідно відповідної формули
	void setNewRadius(double r)
	{
		Circle::setRadius(r);
		Square::setSide(r * sqrt(2));
	}

	//встановлення  сторони квадрата(із збереженням пропорцій), метод встановлення сторони квадрата для фігури CicleInSquare
	//повинен автоматично перерахувати радіус круга
	void setNewSide(double s)
	{
		Square::setSide(s);
		Circle::setRadius((sqrt(2) / 2) * s);
	}

	//метод виведення інформації про фігуру на екран
	void print(string text = "") 
	{
		cout << "\n\t-- SquareInCircle --\t" << text;
		Circle::print();
		Square::print();
		cout << "\nTotal length (both figures):\t" << getTotalLength() << endl;
		cout << "Part of square (circle-square):\t" << getPartSquare() << endl;
		cout << "\t\t------\n";
	}

};

int main()
{
	Circle c;
	c.print();

	Square s(1);
	s.print();

	SquareInCircle obj1(s); //передаємо квадрат, навколо нього створюється коло
	obj1.print("//ctor with Square");
	SquareInCircle obj2(c); //передаємо коло, в нього вписується квадрат
	obj2.print("//ctor with Circle");
	obj2.setNewRadius(2);
	obj2.print("//setNewRadius");
	obj2.setNewSide(1);
	obj2.print("//setNewSide");
	


	cout << endl;
	system("pause");
	return 0;
}

