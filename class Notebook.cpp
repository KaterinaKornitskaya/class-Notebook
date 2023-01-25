// class Notebook.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

/*
 Создать класс ноутбук. На основе других объектов, таких как:
 - Процессор
 - ОЗУ
 - Мышка
 - Веб-камера
 - Принтер
 - Видеокарта
 Каждый объект представлен отдельным классом. Собрать ноутбук, используя 
 агрегацию и композицию.
*/

class CPU					// класс процессор 
{
	std::string name;		// название
	short num_of_cores;		// кол-во ядер
	double price;			// цена
public:
	CPU() : name{ nullptr }, num_of_cores{ 0 }, price { 0 } 
	{
		std::cout << "CPU Constructor by default\n";
	}

	CPU(short Num_of_cores, double Price) 
		: name{ "INTEL CORE I5" }, num_of_cores{ Num_of_cores }, price{ Price }
	{ 
		std::cout << "CPU Constructor with parameters\n";
	}

	void Show()  // вывод на экран
	{
		std::cout << "CPU - name: " << name << std::endl
			<< "CPU - number of cores: " << num_of_cores << std::endl
			<< "CPU - price: " << price << std::endl;
	}

	double get_price() const  // доступ к полю цена
	{
		return price;
	}
};

class RAM					// класс ОЗУ
{
	std::string name;		// название
	short memory;			// объем памяти
	double price;			// цена
public:
	RAM() : name{ nullptr }, memory{ 0 }, price{ 0 }
	{
		std::cout << "RAM Constructor by default\n";
	}

	RAM(short Memory, double Price)
		: name{ "DDR4 SDRAM" }, memory{ Memory }, price{ Price }
	{
		std::cout << "RAM Constructor with parameters\n";
	}

	void Show()  // вывод на экран
	{
		std::cout << "RAM - name: " << name << std::endl
			<< "RAM - memory: " << memory << std::endl
			<< "RAM - price: " << price << std::endl;
	}

	double get_price() const  // доступ к полю цена
	{
		return price;
	}
};

class Mouse					// класс Мышь
{
	std::string type;		// тип
	double price;			// цена
public:
	Mouse() : type{ nullptr }, price{ 0 }
	{
		std::cout << "Mouse Constructor by default\n";
	}

	Mouse(double Price)
		: price{ Price }, type{ "WIRELESS OPTICAL MOUSE" }
	{
		std::cout << "Mouse Constructor with parameters\n";
	}

	void Show()  // вывод на экран
	{
		std::cout << "Mouse - type: " << type << std::endl
			<< "Mouse - price: " << price << std::endl;
	}

	double get_price() const  // доступ к полю цена
	{
		return price;
	}
};

class Webcam				// класс Веб-камера
{							
	std::string type;		// тип
	double price;			// цена
public:
	Webcam() : type{ nullptr }, price{ 0 }
	{
		std::cout << "Webcam Constructor by default\n";
	}

	Webcam(double Price)
		: price{ Price }, type{ "WEBCAM" }
	{
		std::cout << "Webcam Constructor with parameters\n";
	}

	void Show()  // вывод на экран
	{
		std::cout << "Webcam - type: " << type << std::endl
			<< "Webcam - price: " << price << std::endl;
	}

	double get_price() const  // доступ к полю цена
	{
		return price;
	}
};

class Printer				// класс Принтер
{							 
	std::string type;		// тип
	double price;			// цена
public:
	Printer() : type{ nullptr }, price{ 0 }
	{
		std::cout << "Printer Constructor by default\n";
	}

	Printer(double Price)
		: price{ Price }, type{ "LASER" }
	{
		std::cout << "Printer Constructor with parameters\n";
	}

	void Show()  // вывод на экран
	{
		std::cout << "Printer - type: " << type << std::endl
			<< "Printer - price: " << price << std::endl;
	}

	double get_price() const  // доступ к полю цена
	{
		return price;
	}
};

class Graphics_card			// класс Видеокарта
{							
	std::string type;		// тип
	double price;			// цена
public:
	Graphics_card() : type{ nullptr }, price{ 0 }
	{
		std::cout << "Graphics Card Constructor by default\n";
	}

	Graphics_card(double Price)
		: price{ Price }, type{ "GRAPHICS CARD" }
	{
		std::cout << "Graphics Card Constructor with parameters\n";
	}

	void Show()  // вывод на экран
	{
		std::cout << "Graphics Card - type: " << type << std::endl
			<< "Graphics Card - price: " << price << std::endl;
	}

	double get_price() const  // доступ к полю цена
	{
		return price;
	}
};

class Notebook  // класс Ноутбук, на основе объектов предыдущих классов
{
	double price;

	// используем агрегацию - если считаем, что ноутбук может существовать
	// без данных объектов
	// используем композицию - если считаем, что ноутбук НЕ может 
	// существовать без данных объектов
	CPU* obj_cpu;				// указатель на объект, созданный в классе
								//  CPU (агрегация)
	RAM* obj_ram;				// указатель на объект, созданный в классе
								//  RAM (агрегация)
	Mouse obj_mouse;			// создан новый объект (композиция)
	Webcam obj_webcam;			// создан новый объект (композиция)
	Printer obj_printer;		// создан новый объект (композиция)
	Graphics_card* obj_gcard;	// указатель на объект, созданный в классе
								//  Graphics_card (агрегация)


public:
	Notebook(CPU* cpu, RAM *ram, double p_mouse, 
		double p_web, double p_print, Graphics_card* gcard )
		: obj_cpu(cpu), obj_ram(ram), obj_mouse(p_mouse),
		obj_webcam(p_web), obj_printer(p_print), obj_gcard(gcard)
	{
		std::cout << "Notebook Constructor with parameters\n";
	}

	double get_price()  // общая цена - сумма цен всех используемых объектов
	{
		price = obj_cpu->get_price() + obj_ram->get_price()
			+ obj_mouse.get_price() + obj_webcam.get_price()
			+ obj_printer.get_price() + obj_gcard->get_price();
		return price;		
	}

	void Show()  // вывод на экран
	{
		obj_cpu->Show();
		obj_ram->Show();
		obj_mouse.Show();
		obj_webcam.Show();
		obj_printer.Show();
		obj_gcard->Show();
		std::cout << "Total price of notebook = " 
			<< get_price() << std::endl;
	}

	~Notebook()
	{
		std::cout << "Notebook Destructor\n";
	}
};

int main()
{
	CPU obj1{ 6, 7000 };
	RAM obj2{ 16, 2500 };
	Graphics_card obj3{ 4000 };

	Notebook obj_nbook(&obj1, &obj2, 800, 1500, 3500, &obj3);
	obj_nbook.Show();

	return 0;
}
