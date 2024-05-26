#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

class Observer 
{
public:	
	virtual void onWarning(const std::string& message) {}
	virtual void onError(const std::string& message) {}
	virtual void onFatalError(const std::string& message) {}
	virtual ~Observer() = default;
};

class Observed_object //наблюдаемыи класс
{
private:
	std::vector<Observer*> observers;	

public:
	// зарегистрировать наблюдателя
	void registerObserver(Observer* observer)
	{
		observers.push_back(observer);
	}

	void RemoveObserver(Observer* observer)
	{
		auto it = std::remove(observers.begin(), observers.end(), observer);
		observers.erase(it, observers.end());
	}


	void warning(const std::string& message) const   
	{
		for (auto observer : observers)
		{
			observer->onWarning(message);
		}
	}

	void error(const std::string& message) const   
	{
		for (auto observer : observers)
		{
			observer->onError(message);
		}
	}

	void fatalError(const std::string& message) const   
	{
		for (auto observer : observers)
		{
			observer->onFatalError(message);

		}
	}
};

class Display_warning : public Observer
{
private:	
	Observed_object* warning;
public:
	Display_warning(Observed_object* obj):warning(obj)
	{
		obj->registerObserver(this);
	}

	void onWarning(const std::string& message) 
	{
		std::cout << "Сообщение: " << message << std::endl;
		warning->RemoveObserver(this);
	}
};

class Display_error : public Observer 
{
private:
	Observed_object* error;
public:
	Display_error(Observed_object* obj) :error(obj)
	{
		obj->registerObserver(this);
	}

	void onError(const std::string& message)
	{
		//std::cout << "Ошибка: " << message << std::endl;
		std::ofstream rf;
		rf.open("Текст.txt");
		if (!rf.is_open()) { std::cout << "not open!"; }
		rf << message << std::endl;
		rf.close();
		error->RemoveObserver(this);
	}
};

class Display_fatalError : public Observer
{
private:
	Observed_object* fatalError;
public:
	Display_fatalError(Observed_object* obj) :fatalError(obj)
	{
		obj->registerObserver(this);
	}

	void onFatalError(const std::string& message)
	{
		std::cout << "Критическая ошибка: " << message << std::endl;
		std::ofstream rf;
		rf.open("Текст.txt");
		if (!rf.is_open()) { std::cout << "not open!"; }
		rf << message << std::endl;
		rf.close();
		fatalError->RemoveObserver(this);
	}
};





int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string mes{ "Test message" };
	std::string fe_mes{ "fatal_error!" };

	Observed_object* object = new Observed_object;
	Display_warning* disw = new Display_warning(object);
	Display_error* dise = new Display_error(object);
	Display_fatalError* disfe =new Display_fatalError(object);

	object->warning(mes);
	object->error(mes);
	object->fatalError(fe_mes);

	delete disw;
	delete dise;
	delete disfe; 

	return 0;
}