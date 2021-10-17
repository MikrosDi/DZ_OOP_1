
#include <cmath>
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cassert>
#include <string> 

using namespace std;

//Task 1
/*Создать класс Power, который содержит два вещественных числа.
Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел.
Еще создать два метода: один с именем set, который позволит присваивать значения переменным, 
второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. 
Задать значения этих двух чисел по умолчанию.*/

class Power	
{	
private:
	float one_power;
	float two_power;
public:
	
	Power() : one_power(2.2), two_power(4.4) {
		setlocale(LC_ALL, "rus");
		
		cout << "\n" << "Power(Конструктор)\n" << "one_power - " << one_power << "\ntwo_power - " << two_power << endl;
	}

	void setPower(float one, float two) {
		
		one_power = one;
		two_power = two;
		cout << "\n" << "setPower:\n" << "one - " << one << "\n" <<"two - " << two << endl;
	}

	void calculate ()
	{
		setlocale(LC_ALL, "rus");
	
		cout << "\nРезультат возведения первого числа (one) в степень второго числа (two) = " << pow(one_power, two_power) << endl;
	}

};

	//Task 2
	/*Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include <cstdint> для доступа к этому типу).
		Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
		Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha.
		Написать функцию print(), которая будет выводить значения переменных-членов.*/

	class RGBA
	{
	public:

		uint8_t m_red;
		uint8_t m_green;
		uint8_t m_blue;
		uint8_t m_alpha;


		RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255) {

		}

		RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
		{
			m_red = r;
			m_green = g;
			m_blue = b;
			m_alpha = a;
		}

		void Print()
		{
			cout << "m_red=" << static_cast<int>(m_red) <<
				" m_green=" << static_cast<int>(m_green) <<
				" m_blue=" << static_cast<int>(m_blue) <<
				" m_alpha=" << static_cast<int>(m_alpha) << '\n';
		}

	};

	/*
	Task 3
	 Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
	private-массив целых чисел длиной 10;
	private целочисленное значение для отслеживания длины стека;
	public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
	public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
	public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
	public-метод с именем print(), который будет выводить все значения стека.
	*/

	class Stack
	{
	private:
		int m_array[10];
		int m_next;

	public:

		void reset()
		{
			m_next = 0;
			for (int i = 0; i < 10; ++i)
				m_array[i] = 0;
		}

		bool push(int value)
		{
			if (m_next == 10)
				return false;

			m_array[m_next++] = value;
			return true;
		}

		int pop()
		{
			assert(m_next > 0);
			int val = m_array[m_next - 1];
			--m_next;
			return val;
			return m_array[--m_next];
		}

		void print()
		{
			std::cout << "( ";
			for (int i = 0; i < m_next; ++i)
				std::cout << m_array[i] << ' ';
			std::cout << ")\n";
		}
	};




	int main()
	{

		{
			//Task 1
			cout << "Task 1" << endl;

			Power power;
			power.setPower(2.66, 4.34);
			power.calculate();
		};

		{
			//Task 2
			cout << "\nTask 2" << endl;

			int r_cin, g_cin, b_cin, a_cin;
			cout << "r = ";
			cin >> r_cin;
			cout << "g = ";
			cin >> g_cin;
			cout << "b = ";
			cin >> b_cin;
			cout << "a = ";
			cin >> a_cin;

			RGBA rgba((uint8_t(r_cin)), (uint8_t(g_cin)), (uint8_t(b_cin)), (uint8_t(a_cin)));
			rgba.Print();

		};

		{
			//Task 3
			cout << "\nTask 3" << endl;

			Stack stack;
			stack.reset();

			stack.print();

			stack.push(3);
			stack.push(7);
			stack.push(5);
			stack.print();

			stack.pop();
			stack.print();

			stack.pop();
			stack.pop();

			stack.print();
		};

		return 0;
	};

