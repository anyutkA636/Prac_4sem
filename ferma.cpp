#include <iostream>
#include <string>
using namespace std;

enum Type_of_animal { cow, goat };
enum Sex_of_the_animal { male, female };
enum Contain { bottle, can, tank };

class Animal {
private:
    string name;
    int age;
	bool health;
	Type_of_animal type;
	Sex_of_the_animal gender;	

public:
	 virtual void MakeSound() = 0;
	 void Init_name(string _name) { name = _name; };
	 void Init_age(int _age) { age = _age; };
	 void Init_health() {health = true;};
	 void Init_gender(Sex_of_the_animal _gender) { gender = _gender; };
	 
	 int Get_gender() {return gender;};
    
};

class Product {
private:
	bool freshness;
	int price;
public:
	virtual void Trade(int count) = 0;
	int Get_price() {return price;};
};


class Milk_Cow: public Product {
private:
	int liters;
public:
	void Add_milk(int l) {
		liters += l;
	};
	virtual void Trade(int count) {
		int p = Get_price() * count;
		cout << count << "litres of milk cost" << p << "dollars" << endl;
	};
	int Get_liters() {return liters; };
};


class Cow: public Animal, public Milk_Cow {
private:
	int count = 0;
	int liters_of_milk = 3;
	
public:
	Cow (string _name, int _age, Sex_of_the_animal _gender) {
		count++;
		Init_name(_name);
		Init_age(_age);
		Init_health();
		Init_gender(_gender);
	}
		
    virtual void MakeSound() {
        cout << "Muuuu" << endl;
    }  
    void Milking_cows() {
		if (Get_gender() == female) {
			Add_milk(liters_of_milk);
			cout << "The cow is milked." << endl;
		}
		else
			cout << "It is a bull." << endl;
	}
	int GetCount() { return count; }
		
};


class Goat: public Animal {
private:
	int count = 0;
	int liters_of_milk = 2;
	
public:
	Goat (string _name, int _age, Sex_of_the_animal _gender) {
		count++;
		Init_name(_name);
		Init_age(_age);
		Init_health();
		Init_gender(_gender);
	}
		
    virtual void MakeSound() {
        cout << "Beeee" << endl;
    };
    
	int GetCount() { return count; }
		
};


class Сontainer {
private:
	Contain type;
	int count = 0;
	bool full;
	int remainder = 0;
	
public:
    Сontainer(Contain _type) {
        type = _type;
        full = false;
    }
	void Fill(int liters) {
		int l;
		l = l - remainder;
		full = true;
		if (type == bottle)
			l = 1;
		else if (type == can)
			l = 20;
		else if (type == tank)
			l = 100;
		count += liters / l;
		remainder = l - liters % l;
		if (remainder != l)
			count += 1;
			full = false;
	}
	int Get_Count() {return count;};
};
	

int main()
{
    Cow C("Emma", 2, female);
    C.MakeSound(); 
    cout << C.Get_liters() << " liters of cow milk" << endl;
    C.Milking_cows();
    cout << C.Get_liters() << " liters of cow milk" << endl;
    C.Milking_cows();
    cout << C.Get_liters() << " liters of cow milk" << endl;
    Cow A("Bully", 4, male);
    A.Milking_cows();
    
    Сontainer Can1(can);
    Can1.Fill(6);
    cout << Can1.Get_Count() << " containers in stock" << endl ;
}
