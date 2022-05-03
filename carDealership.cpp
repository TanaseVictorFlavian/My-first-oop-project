#include <iostream>
#include <string.h>
#include <list>
#include <windows.h>
#include <map>
#include <algorithm>


using namespace std;

void setConsoleColor(int x)
{
  HANDLE  hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, x);

}


class Car
{   
    static float currencyValue[4];
    string brand,  model , color, countryOrigin, bodyWork, fuelType, transmission, soundSystem, seatFabric, steeringWheelFabric,
           autoPilot, blueTooth, heatedSeat, airConditioner;
    int fabricationYear, pollutionNorm, engineSize, mileAge, enginePower, price, trunkVolume, stock;

public:

    //default constructor
    Car();

    //all parameter constructor
    Car(string , string , string , int , int , int , int , int , string , 
        string , string , string , string , string , string ,int, string ,  
        string , string , string , string, int);
    
    //general info constructor
    Car(string , string , string , int , int , int , int , int , string , string );
    
    //short info constructor
    Car(string brand, string model, int engineSize, int price);

    //copy constructor

    Car(const Car& car);

    //destructor
    ~Car();

    //overloaded "=" operator
    Car& operator = (const Car& car);

    //overloaded ">>" operator

    friend istream& operator >> (istream&,  Car&);

    //overloaded "<<" operator
    friend ostream& operator << (ostream&,  const Car&);

    //overloaded -- operator
    Car operator -- (int);
    Car& operator --();

    Car operator + (int);
    Car operator + (Car);
    friend Car operator + (int, Car);

    Car operator [](unsigned int index); 

    Car operator * (int);
    friend Car operator * (int, Car);
    
    void operator += (const Car&);
    void operator += (int);

    void operator *= (int);

    bool operator >= (double);
    bool operator >= (const Car&);

    bool operator == (Car);

    explicit operator int()
    {
        return (int)this -> price;
    }

    string getBrand();
   
    int getPrice();
    string getModel();
    
    void changeCarPrice(string currency);

};

float Car :: currencyValue[] =  {4.95, 1.1, 1, 0.84};
//default constructor "body"
Car :: Car() : brand("None"), model("None"), color("None"), engineSize(0), enginePower(0), price(9999999), mileAge(0), fabricationYear(0), transmission("None"), 
        bodyWork("None"), countryOrigin("None"), autoPilot("None"), blueTooth("None"), fuelType("None"), pollutionNorm(0), trunkVolume(0), soundSystem("None"),  
        heatedSeat("None"),stock(0), airConditioner("None"), seatFabric("None"), steeringWheelFabric("None") {};

//all parameter constructor body
Car :: Car(string brand, string model, string color, int engineSize, int enginePower, int price, int mileAge, int fabricationYear, string transmission, 
        string bodyWork, string countryOrigin, string autoPilot, string blueTooth, string fuelType, string pollutionNorm, int trunkVolume, string soundSystem,  
        string heatedSeat, string airConditioner, string seatFabric, string steeringWheelFabric, int stock)

{
    this -> brand = brand;
    this -> model = model;
    this -> color = color;
    this -> fuelType = fuelType;
    this -> bodyWork = bodyWork;
    this -> countryOrigin = countryOrigin;
    this -> enginePower = enginePower;
    this -> engineSize =  engineSize;
    this -> price =  price;
    this -> mileAge =  mileAge;
    this -> fabricationYear = fabricationYear;
    this -> transmission = transmission;
    this -> autoPilot =  autoPilot;
    this -> blueTooth = blueTooth;
    this -> fuelType =  pollutionNorm;
    this -> trunkVolume =  trunkVolume;
    this -> soundSystem =  soundSystem;
    this -> heatedSeat = heatedSeat;
    this -> airConditioner = airConditioner;
    this -> seatFabric = seatFabric;
    this -> steeringWheelFabric = steeringWheelFabric;
    this -> fuelType = fuelType;
    this -> stock = stock;
}


//general info constructor body

Car :: Car(string brand, string model, string color, int engineSize, int enginePower, 
    int price, int mileAge, int fabricationYear, string transmission, string fuelType):
    bodyWork("None"), countryOrigin("None"), autoPilot("None"), blueTooth("None"), pollutionNorm(), trunkVolume(0), soundSystem("None"),  
    heatedSeat("None"),stock(0), airConditioner("None"), seatFabric("None"), steeringWheelFabric("None")
{
    
    this -> brand = brand;
    this -> model = model;
    this -> color = color;
    this -> enginePower = enginePower;
    this -> engineSize =  engineSize;
    this -> price =  price;
    this -> mileAge =  mileAge;
    this -> fabricationYear = fabricationYear;
    this -> fuelType = fuelType;
    this -> transmission = transmission;

}

//short info constructor 
Car :: Car(string brand, string model, int engineSize, int price):
        color("None"), enginePower(0), price(9999999), mileAge(0), fabricationYear(0), transmission("None"), 
        bodyWork("None"), countryOrigin("None"), autoPilot("None"), blueTooth("None"), fuelType("None"), pollutionNorm(0), trunkVolume(0), soundSystem("None"),  
        heatedSeat("None"), stock(0), airConditioner("None"), seatFabric("None"), steeringWheelFabric("None")
{
    this -> brand = brand;
    this -> model = model;
    this -> engineSize =  engineSize;
    this -> price =  price;
}


//copy constructor body
Car :: Car (const Car& car)
{   
    this -> brand = car.brand;
    this -> model = car.model;
    this -> bodyWork = car.bodyWork;
    this -> countryOrigin = car.countryOrigin;
    this -> color = car.color;
    this -> enginePower = car.enginePower;
    this -> engineSize =  car.engineSize;
    this -> price =  car.price;
    this -> mileAge =  car.mileAge;
    this -> fabricationYear = car.fabricationYear;
    this -> autoPilot =  car.autoPilot;
    this -> blueTooth =  car.blueTooth;
    this -> fuelType =  car.pollutionNorm;
    this -> trunkVolume =  car.trunkVolume;
    this -> soundSystem =  car.soundSystem;
    this -> heatedSeat = car.heatedSeat;
    this -> airConditioner = car.airConditioner;
    this -> seatFabric = car.seatFabric;
    this -> steeringWheelFabric = car.steeringWheelFabric;
    this -> stock = car.stock;
    
}


//destructor body 

Car :: ~Car (){};
// overloaded "=" body

Car& Car :: operator = (const Car& car)
{   
    if(this != &car)
    {
        this -> brand = car.brand;
        this -> model = car.model;
        this -> bodyWork = car.bodyWork;
        this -> countryOrigin = car.countryOrigin;
        this -> color = car.color;
        this -> enginePower = car.enginePower;
        this -> engineSize =  car.engineSize;
        this -> price =  car.price;
        this -> mileAge =  car.mileAge;
        this -> fabricationYear = car.fabricationYear;
        this -> autoPilot =  car.autoPilot;
        this -> blueTooth =  car.blueTooth;
        this -> fuelType =  car.pollutionNorm;
        this -> trunkVolume =  car.trunkVolume;
        this -> soundSystem =  car.soundSystem;
        this -> heatedSeat = car.heatedSeat;
        this -> airConditioner = car.airConditioner;
        this -> seatFabric = car.seatFabric;
        this -> stock = car.stock;
        this -> steeringWheelFabric = car.steeringWheelFabric;
    }
    return *this;

}

istream& operator >> (istream& in, Car& car)
{
    cout << "Brand : " ; in >> car.brand;
    cout << "\nPrice : "; in >> car.price;
    cout << "\nModel : " ; in >> car.model;
    cout << "\nColor : " ; in >> car.color; 
    cout << "\nEngine size : "; in >> car.engineSize ;
    cout << "\nMile age (kilometeres) : "; in >> car.mileAge ;
    cout << "\nEngine power : " ; in >> car.enginePower;
    cout << "\nTransmision : "; in >> car.transmission ;
    cout << "\nFuel type : "; in >> car.fuelType;
    cout << "\nBodywork : "; in >> car.bodyWork; 
    cout << "\nCountry Origin : "; in >> car.countryOrigin; 
    cout << "\nSound system : "; in >> car.soundSystem;
    cout << "\nSeat fabric : " ; in >> car.seatFabric ;
    cout << "\nSteering wheel fabric : " ; in >>  car.steeringWheelFabric ;
    cout << "\nFabrication year : " ;in >> car.fabricationYear ;
    cout << "\nPollution norm : "; in >> car.pollutionNorm;
    cout << "\nAuto pilot(yes/no) : "; in >> car.autoPilot;
    cout << "\nTrunk Volume : "; in >> car.trunkVolume;
    cout << "\nBluetooth(yes/no) : " ; in >> car.blueTooth ;
    cout << "\nAir conditioner(yes/no) : "; in >> car.airConditioner;
    cout << "\nHeated seat(yes/no)"; in >> car.heatedSeat;
    cout << "\nAvailable stock : "; in >> car.stock;
    cout << '\n';
    
    return in;
    
}
ostream& operator << (ostream& out, const Car& car)
{
    out << "Brand : " << car.brand 
        << "\nPrice : " << car.price << " Euro"
        << "\nModel : " << car.model
        << "\nColor : " << car.color 
        << "\nEngine size : " << car.engineSize << " cm^3" 
        << "\nMile age (kilometeres) : " << car.mileAge 
        << "\nEngine power : " << car.enginePower << " HP"
        << "\nTransmision : " << car.transmission 
        << "\nFuel type : " << car.fuelType
        << "\nCountry Origin : " << car.countryOrigin 
        << "\nBodywork : " << car.bodyWork 
        << "\nSound system : " << car.soundSystem
        << "\nSeat fabric : " << car.seatFabric 
        << "\nSteering wheel fabric : " << car.steeringWheelFabric 
        << "\nFabrication year : " << car.fabricationYear 
        << "\nTrunk Volume : " << car.trunkVolume
        << "\nPollution norm : " << car.pollutionNorm
        << "\nAuto pilot : " << car.autoPilot
        << "\nBluetooth : " << car.blueTooth 
        << "\nAir conditioner : " << car.airConditioner
        << "\nHeated seat : " << car.heatedSeat
        << "\nStock available : " << car.stock
        << '\n';

    return out;
}

//prefixed --
Car& Car :: operator--()
{   
    this -> stock--;
    return *this;
}
//postfixed
Car Car :: operator--(int)
{
    Car aux = *this;
    this -> stock--;
    return aux;

}



Car Car :: operator + (int x)
{
    Car aux(*this);
    aux.stock += x;
    return aux;
}

Car Car :: operator + (Car car)
{
    car.price += this -> price;
    return car;
}

Car operator + (int x, Car car)
{
    car.stock += x;
    return car;
}

Car Car :: operator [] (unsigned int index)
{
    return *this;
}

Car Car :: operator *(int x)
{
    Car aux(*this);
    aux.stock *= x;
    return aux;
}


Car operator * (int x, Car car)
{
    car.stock *= x;
    return car;
}
string Car :: getBrand()
{
    return this -> brand;
}

void Car :: operator += (const Car& car)
{
    this -> price += car.price;
}

void Car :: operator += (int x)
{
    this -> stock += x;
}

void Car :: operator *= (int x)
{
    this -> stock *= x;
}

bool Car :: operator >= (double x)
{
    if (this -> price >= x)
        return true;
    else
        return false;
}

bool Car :: operator >= (const Car& car)
{
    if(this -> price >= car.price)
        return true;
    else 
        return false;
}

bool Car :: operator == (Car car)
{
    if(this -> price == car.price && this -> brand == this -> brand)
        return true;
    else
        return false; 
}
string Car :: getModel()
{
    return this -> model;
}
void Car :: changeCarPrice(string currency)
{    
    if(currency == "USD")
        this -> price *= currencyValue[1];
    else if(currency == "RON")
        this -> price *= currencyValue[0];
    else if(currency == "GBP")
        this -> price *= currencyValue[3];
}
int Car :: getPrice()
{
    return this -> price;
}

class Client
{   
//private :
    list <Car> carsPurchased;
    char* name;
    string citzenship, adress, gender, email, phoneNumber;
    unsigned int age, unpaidMonths, monthsLeftOfPayment, monthsOfPayment, daysSinceLastPayment, previousPurchases;
    const int clientCode;
    static int clientID;
    double interestRate, thisMonthToBePaid, remainingSumToBePaid, sumPaidUntilNow, totalSumToBePaid, unpaidSum;
    float discount;
    bool paymentInInstallments;
    
    




public:

    void setAge(unsigned int age);
    unsigned int getAge();
   
    void setInterestRate(double );
    double getInterestRate();

    void setName(char* name);
    char* getName();
    
    void setSumPaidUntilNow(double);
    double getSumPaidUntilNow();

    void setCitzenship(string citzenship);
    string getCitzenship();
   
    void setGender(string gender);
    string getGender();
   
    void setAdress(string adress);
    string getAdress();
    
    void setEmployed(bool paymentInInstallments);
    bool getEmployed();
   
    void setPaymentInInstallments(bool paymentInInstallments);
    bool getPaymentInInstallments();
   
    void setUnpaidSum(double);
    double getUnpaidSum();

    void setUnpaidMonths(unsigned int);
    unsigned int getUnpaidMonths();
   
    void setMonthsLeftOfPayment(unsigned int monthsLeftOfPayment);
    unsigned int getMonthsLeftOfPayment();

    void setTotalSumToBePaid(double totalSumToBePaid);
    double getTotalSumToBePaid();
    
    void setDaysSinceLastPayment(unsigned int);
    unsigned int getDaysSinceLastPayment();
       
    unsigned int getClientCode();
    string getCountry();

    void calculateThisMonthPayment();
    
    void checkThisMonthPayment();
    
    
    void discountCalculator(Car/*,Dealership dealership*/);

    void calculateTotalSumToBePaid(Car);

    void setInfo();

    int purchasedCarsValue(Client);
    
    Car getLastCarPurchased();
   
    void setDiscount(double);

    void setRemainingSumToBePaid(double);
    double getRemainingSumToBePaid();

    void setThisMonthToBePaid(double);
    double getThisMonthToBePaid();

    int getPreviousPurchases();
    //default constructor
    Client();

    //all parameter constructor
    Client(char* , unsigned int , string,  string, string, string, string, double, unsigned int, unsigned int, 
    unsigned int, unsigned int, unsigned int, float, bool, 
    double ,double, double, double, double);

    //constructor for 1-time-pay cients
    Client(char*, unsigned int, string, string, string);
    
    //basic constructor
    Client(char*, unsigned int, string, string);
    
    //copy constructor  
    Client (const Client &client);

    //destructor 
    ~Client();

    //overloading "="
    Client& operator = (const Client& client);

    //overloading post-fixed "++" operator

    Client operator ++ (int);

    //overloading pre-fixed "++" operator
    Client& operator ++ ();

    //overlaoding ">>" operator
    friend istream& operator >> (istream&, Client&);
    //overloading "<<" operator 
    friend ostream& operator << (ostream&, const Client&);

    Car operator [](int);

    Client operator + (const Car&);
    friend Client operator + (const Car& , Client);

    Client operator + (Client);

    Client operator += (const Car&);
    
    int operator - (const Client);


    bool operator >= (const Client&);
    bool operator < (const Client&);

    bool operator == (const Client&);

    explicit operator int()
    {
        return (int)this -> age;
    }
};

int Client :: clientID = 10000;



//CONSTRUCTORS

//all parameter constructor body
Client :: Client(char* name, unsigned int age, string gender,  string citzenship , string adress, string phoneNumber, string email, double interestRate, 
                unsigned int monthsLeftOfPayment, unsigned int unpaidMonths, unsigned int monthsOfPayment, 
                unsigned int daySinceLastPayment, unsigned int previousPurchases, float discount, bool paymentInInstallments, 
                double thisMonthToBePaid, double remainingSumToBePaid, double sumPaidUntilNow, double totalSumToBePaid, double unpaidSum) : clientCode(clientID++)
{
    this -> age = age;
    this -> gender = gender; 
    this -> monthsLeftOfPayment = monthsLeftOfPayment;
    this -> totalSumToBePaid = totalSumToBePaid;
    this -> sumPaidUntilNow = sumPaidUntilNow;
    this -> remainingSumToBePaid = remainingSumToBePaid;
    this -> unpaidMonths = unpaidMonths;
    this -> thisMonthToBePaid = thisMonthToBePaid;
    this -> interestRate = interestRate;
    this -> monthsOfPayment = monthsOfPayment;
    this -> citzenship = citzenship;
    this -> adress = adress;
    this -> daysSinceLastPayment = daySinceLastPayment;
    this -> previousPurchases = previousPurchases;
    this -> unpaidSum = unpaidSum;
    this -> discount = discount;
    this -> paymentInInstallments = paymentInInstallments;
    this -> name = new char[strlen(name) + 1];
    this -> phoneNumber = phoneNumber;
    this -> email;
    this -> carsPurchased = carsPurchased;
    strcpy( this -> name, name);




};

//one-time buy constructor body
Client :: Client(char* name, unsigned int age, string adress, string phoneNumber, string email) : gender("None"), citzenship("None"), interestRate(0), 
                monthsLeftOfPayment(0), totalSumToBePaid(0), sumPaidUntilNow(0), remainingSumToBePaid(0), unpaidMonths(0), 
                thisMonthToBePaid(0), monthsOfPayment(0), unpaidSum(0), daysSinceLastPayment(0), previousPurchases(0),
                discount(0), paymentInInstallments(0),carsPurchased({}), clientCode(clientID++)
{   
    this -> age = age;
    this -> adress = adress;
    this -> phoneNumber = phoneNumber;
    this -> email = email;
    //calculateTotalSumToBePaid();

    this -> name = new char[strlen(name) + 1];
    strcpy( this -> name, name);
    
};

//default constructor body
Client :: Client() : name("None"), age(0), gender("None"), citzenship("None") , adress("None"), interestRate(0), 
                monthsLeftOfPayment(0), totalSumToBePaid(0), sumPaidUntilNow(0), remainingSumToBePaid(0), unpaidMonths(0), 
                thisMonthToBePaid(0), monthsOfPayment(0), unpaidSum(0), daysSinceLastPayment(0), previousPurchases(0),
                discount(0), paymentInInstallments(0), clientCode(clientID++), phoneNumber("None"), email("None"), carsPurchased({}){}
//basic constructor body
Client :: Client(char* name, unsigned int age, string phoneNumber, string email) : name("None"), age(0), gender("None"), citzenship("None") , adress("None"), interestRate(0), 
                monthsLeftOfPayment(0), totalSumToBePaid(0), sumPaidUntilNow(0), remainingSumToBePaid(0), unpaidMonths(0), 
                thisMonthToBePaid(0), monthsOfPayment(0), unpaidSum(0), daysSinceLastPayment(0), previousPurchases(0),
                discount(0), paymentInInstallments(0), phoneNumber("None"), email("None"), clientCode(clientID++)
{   
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
    this -> age = age;
    this -> email = email;
}

//copy constructor body
Client :: Client(const Client& client) : clientCode(clientID)
{   
    
    this -> age = client.age;
    this -> gender = client.gender; 
    this -> monthsLeftOfPayment = client.monthsLeftOfPayment;
    this -> totalSumToBePaid = client.totalSumToBePaid;
    this -> sumPaidUntilNow = client.sumPaidUntilNow;
    this -> remainingSumToBePaid = client.remainingSumToBePaid;
    this -> unpaidMonths = client.unpaidMonths;
    this -> thisMonthToBePaid = client.thisMonthToBePaid;
    this -> interestRate = client.interestRate;
    this -> monthsOfPayment = client.monthsOfPayment;
    this -> citzenship = client.citzenship;
    this -> adress = client.adress;
    this -> daysSinceLastPayment = client.daysSinceLastPayment;
    this -> previousPurchases = client.previousPurchases;
    this -> unpaidSum = client.unpaidSum;
    this -> discount = client.discount;
    this -> paymentInInstallments = client.paymentInInstallments;
    this -> phoneNumber = client.phoneNumber;
    this -> email = client.email;
    this -> carsPurchased = client.carsPurchased;

    this -> name = new char[strlen(client.name) + 1];
    strcpy( this -> name, client.name);
}

//destructor body

Client :: ~Client()
{
    if(this -> name != NULL)
        delete [] this -> name;
}

//overloaded "=" body for Client objects

Client& Client :: operator = (const Client& client)
{
    if(this != &client) {
        if(this -> name != NULL) 
        {
            delete [] this -> name;
        }        

    this -> age = client.age;
    this -> gender = client.gender; 
    this -> monthsLeftOfPayment = client.monthsLeftOfPayment;
    this -> totalSumToBePaid = client.totalSumToBePaid;
    this -> sumPaidUntilNow = client.sumPaidUntilNow;
    this -> remainingSumToBePaid = client.remainingSumToBePaid;
    this -> unpaidMonths = client.unpaidMonths;
    this -> thisMonthToBePaid = client.thisMonthToBePaid;
    this -> interestRate = client.interestRate;
    this -> monthsOfPayment = client.monthsOfPayment;
    this -> citzenship = client.citzenship;
    this -> adress = client.adress;
    this -> daysSinceLastPayment = client.daysSinceLastPayment;
    this -> previousPurchases = client.previousPurchases;
    this -> unpaidSum = client.unpaidSum;
    this -> discount = client.discount;
    this -> paymentInInstallments = client.paymentInInstallments;
    this -> phoneNumber = client.phoneNumber;
    this -> email = client.email;
    this -> carsPurchased = client.carsPurchased;

    this -> name = new char[strlen(client.name) + 1];
    strcpy( this -> name, client.name);
    }
    return *this;
}

//overloaded "++" body (postfixed)

Client Client :: operator ++ (int)
{
    
    Client aux = *this;
    this -> monthsOfPayment++;
    return aux;
}

//overloaded "++" body(prefixed)
Client& Client :: operator++()
{
    this -> monthsOfPayment++;
    return *this;
}

//overlaoded ">>" body

istream& operator >> (istream& in,  Client& client)
{   
    char name[100];
    cout << "Name : ";
    in >> name;
    if(client.name != NULL)
        delete[] client.name;
    
    client.name = new char[strlen(name) + 1];
    strcpy(client.name, name);
    
    cout << "Age : ";
    in >> client.age;

    cout << "Citzenship : ";
    in >> client.citzenship;

    cout << "Adress : ";
    in >> client.adress;

    cout << "Gender : ";
    in >> client.gender;

    cout << "Email : ";
    in >> client.email;

    cout << "Phone number : ";
    in >> client.phoneNumber;

   // client.setInfo();
    return in;
}

//overloaded "<<" body

ostream& operator << (ostream& out, const Client& client)
{
    out << "-------------Client " << client.clientCode << "-------------"
        << "\n\nName : " << client.name 
        << "\nAge : " << client.age 
        << "\nGender : " << client.age 
        << "\nCitzenship : " << client.citzenship 
        << "\nAdress : " << client.adress 
        << "\nEmail : " << client.email
        << "\nPhone number : " << client.phoneNumber 
        << "\nPrevious purchases : " << client.previousPurchases
        << "\nCars purchased : ";
        if(client.carsPurchased.size() != 0)
            for(auto x : client.carsPurchased)
                out << x.getBrand() << "-" << x.getModel() << ' ';  
    if(client.paymentInInstallments)
    {
        out << "\nTotal sum to be paid : " << client.totalSumToBePaid
            << "\nInterest rate : " << client.interestRate
            << "\nDiscount : " << client.discount
            << "\nThis month to be paid : " << client.thisMonthToBePaid
            << "\nMonths left of payment : " << client.monthsLeftOfPayment
            << "\nMonths of payment(until now) : " << client.monthsOfPayment 
            << "\nRemaining sum to be paid : " << client.remainingSumToBePaid 
            << "\nSum paid until now : " << client.sumPaidUntilNow
            << "\nDays since last payment : " << client.daysSinceLastPayment
            << "\nUnpaid sum  : " << client.unpaidSum << '\n';
    }

    return out;
}

Car Client :: operator [](int index) 
{   
    
    // daca se da un index gresit programul afiseaza valori random
    // nu inteleg de ce...
    if(index >= 0 && index < this -> carsPurchased.size())
        {   
            list<Car> :: iterator it;
            it = this -> carsPurchased.begin();
            advance(it, index); 
            return *it;
        }
    setConsoleColor(12);
    cout << "List index out of range!\n";
    setConsoleColor(15);
}

Client Client :: operator + (const Car& car)
{   
    Client aux(*this);
    aux.carsPurchased.push_back(car);
    return aux;
}

Client operator + (const Car& car, Client client)
{
    client.carsPurchased.push_back(car);
    return client;
}

Client Client :: operator += (const Car &car)
{
    this -> carsPurchased.push_back(car);
    return *this;
}

int Client :: operator - (Client client)
{
    return purchasedCarsValue(*this) - purchasedCarsValue(client);
}

bool Client :: operator >= (const Client& client)
{
    if(this -> age >= client.age)
        return true;
    return false;
} 

bool Client :: operator < (const Client& client)
{
    if(this -> age < client.age)
        return true;
    else 
        return false;
} 

bool Client :: operator == (const Client& client)
{
    if (this -> age == client.age)
        return true;
    else 
        return false; 
}


void Client :: calculateThisMonthPayment()
{   
    this -> thisMonthToBePaid = (double) this -> remainingSumToBePaid / this -> monthsLeftOfPayment;  
    this -> thisMonthToBePaid = this -> thisMonthToBePaid *  this -> unpaidMonths * /*getLatePaymentTax()*/ 0.02 + this -> thisMonthToBePaid + this -> unpaidSum;   
}

void Client :: checkThisMonthPayment()
{
    if(this -> daysSinceLastPayment > 60 && this -> monthsLeftOfPayment > 0)
    {
        this -> unpaidMonths ++;
        this -> unpaidSum += thisMonthToBePaid;

    }
    if(this -> sumPaidUntilNow == this -> totalSumToBePaid)
    {
        this -> previousPurchases ++;
        this -> monthsLeftOfPayment = 0;
    }
}


void Client :: calculateTotalSumToBePaid(Car car)
{
    this -> totalSumToBePaid = car.getPrice() + interestRate * this -> totalSumToBePaid - discount;
}

int Client :: purchasedCarsValue (Client client)
{
    int sum = 0;
    for(auto x : client.carsPurchased)
        sum += x.getPrice();
    return sum;
}
Car Client :: getLastCarPurchased()
    {
        list<Car> :: iterator itr;
        itr = -- this -> carsPurchased.end();
        return *itr;
    }

void Client :: setDiscount(double x)
{
    this -> discount = x;
}

int Client :: getPreviousPurchases()
{
    return this -> previousPurchases;
}
void Client :: setInfo()
    {   
    
        if(this -> carsPurchased.size() > 0)
            this -> previousPurchases = this -> carsPurchased.size() - 1;
        
        calculateTotalSumToBePaid(getLastCarPurchased());
        this -> remainingSumToBePaid = totalSumToBePaid;
        calculateThisMonthPayment();
       

    }

Client Client :: operator + (Client client)
{
    for(auto x : this -> carsPurchased)
        client.carsPurchased.push_back(x);
    
    return client;

}
//setters/getters bodies
void Client :: setInterestRate(double x)
{
    this -> interestRate = x;
}
double Client :: getInterestRate()
{
    return this -> interestRate;
}

void Client :: setAge(unsigned int age)
{
    this -> age = age;
}
    
unsigned int Client :: getAge()
{
    return this -> age;
}
void Client :: setName(char* name)
{
    if(this -> name != NULL)
        delete [] this -> name;
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
}
char* Client :: getName()
{
    return this -> name;
}

void Client :: setCitzenship(string citzenship)
{
    this -> citzenship = citzenship;
}
string Client :: getCitzenship()
{
    return this -> citzenship;
}

void Client :: setGender(string gender)
    {
        this -> gender = gender;
    }
    
string Client :: getGender()
    {
        return this -> gender;
    }

void Client :: setAdress(string adress)
{
    this -> adress = adress;    
}
string Client :: getAdress()
    {
    return this -> adress;
    }

void Client :: setUnpaidMonths(unsigned int unPaidMonths)
{
    this -> unpaidMonths = unPaidMonths;
}
    
unsigned int Client :: getUnpaidMonths()
{
    return this -> unpaidMonths;
}

void Client :: setUnpaidSum(double unPaidSum)
{
    this -> unpaidSum = unpaidSum;
}
    
double Client :: getUnpaidSum()
{
    return this -> unpaidMonths;
}

void Client :: setMonthsLeftOfPayment(unsigned int monthsLeftOfPayment)
{
    this -> monthsLeftOfPayment = monthsLeftOfPayment;
}
    
unsigned int Client :: getMonthsLeftOfPayment()
{
    return this -> monthsLeftOfPayment;
}

void Client :: setTotalSumToBePaid(double totalSumToBePaid)
{
    this -> totalSumToBePaid = totalSumToBePaid;
}
    
double Client :: getTotalSumToBePaid()
{
    return this -> totalSumToBePaid;
}

void Client :: setDaysSinceLastPayment(unsigned int daysSinceLastPayment)
{
    this -> daysSinceLastPayment = daysSinceLastPayment;
}

void Client :: setPaymentInInstallments(bool paymentInInstallments)
{
    this -> paymentInInstallments = paymentInInstallments;
}
bool Client :: getPaymentInInstallments()
{
    return this -> paymentInInstallments;
}
unsigned int Client :: getClientCode()
{ 
    return this -> clientCode;
}

double Client :: getRemainingSumToBePaid()
{
    return this -> remainingSumToBePaid;

}

void Client :: setRemainingSumToBePaid(double x)
{
    this -> remainingSumToBePaid -= x;
}

double Client :: getSumPaidUntilNow()
{
    return this -> sumPaidUntilNow;
}

void Client :: setSumPaidUntilNow(double x)
{
    this -> sumPaidUntilNow += x;
}

void Client :: setThisMonthToBePaid(double thisMonthToBePaid)
{
    this -> thisMonthToBePaid = thisMonthToBePaid;
}

double Client :: getThisMonthToBePaid()
{
    return this -> thisMonthToBePaid;
}
class Factory
{   
    string name, adress, country; 
    int availableTrailers, size, productionPerWeek, numberOfCars, monthsOfDelivery;
    double transportationTax;
    int* deliveryHistory;

public:

    Factory();
    Factory(string , string , string , int , int,
            long , double , int, int, int*, int);
    Factory(string , string , string);
    Factory(int, int);

    Factory (const Factory&);
    ~Factory();

    Factory operator = (const Factory&);

    friend istream& operator >> (istream&, Factory&);
    friend ostream& operator << (ostream&, const Factory&);
    
    Factory operator ++ (int);
    Factory& operator ++();

    double operator *(double);
    friend double operator * (double, Factory);

    double operator / (double);
    friend double operator / (double, Factory);

    Factory operator[](int);

    void operator *= (double);
    void operator /= (double);

    bool operator == (const Factory&);
    bool operator >= (const Factory&);

    string getName();

    int calculateCarStock();
    double getTransportationTax()
    {
        return this -> transportationTax;
    }
    
    explicit operator int();
    void setDeliveryHistoy(int* deliveryHistory, unsigned int monthsOfDelivery)
    {   
        this -> deliveryHistory = new int[monthsOfDelivery];

        for(int i = 0 ; i < monthsOfDelivery ; ++i)
            this -> deliveryHistory[i] = deliveryHistory[i];

    }
    int* getDeliveryHistory()
    {
        return this -> deliveryHistory;
    }
};

Factory :: Factory() : name("None"), adress("None"), country("None"), size(0), availableTrailers(0),
                       transportationTax(0), productionPerWeek(0), numberOfCars(0) {}


Factory :: Factory(string name, string adress, string country, int size, int availableTrailers,
            long productionExpenses, double transportationTax, int productionPerWeek, int numberOfCars, int* deliveryHistory, int monthsOfDelivery)

{
    this -> name = name;
    this -> adress = adress;
    this -> country = country;
    this -> size = size;
    this -> transportationTax = transportationTax;
    this -> productionPerWeek = productionPerWeek;
    this -> productionPerWeek = productionPerWeek;
    this -> numberOfCars = numberOfCars;
    this -> availableTrailers = availableTrailers;
    this -> monthsOfDelivery = monthsOfDelivery;
    this -> deliveryHistory = new int [monthsOfDelivery];
    for(int i = 0; i < monthsOfDelivery; ++i)
        this -> deliveryHistory[i] = deliveryHistory[i]; 
}

Factory :: ~Factory() 
{
    if(this -> deliveryHistory != NULL)
        delete [] this -> deliveryHistory;
};

Factory :: Factory(string name, string adress, string country): size(0), availableTrailers(0),
                       transportationTax(0), productionPerWeek(0), numberOfCars(0)
{   
    this -> name = name;
    this -> adress = adress;
    this -> country = country;

}

Factory :: Factory(int transportationTax, int numberOfCars) : name("None"), adress("None"), country("None"), size(0), availableTrailers(0), productionPerWeek(0)
{
    this -> transportationTax = transportationTax;
    this -> numberOfCars = numberOfCars;

}

Factory :: Factory(const Factory& factory)
{
    this -> name = factory.name;
    this -> adress = factory.adress;
    this -> country = factory.country;
    this -> size = factory.size;
    this -> numberOfCars = factory.numberOfCars;
    this -> transportationTax = factory.transportationTax;
    this -> productionPerWeek = factory.productionPerWeek;
    this -> availableTrailers = factory.availableTrailers;
    this -> monthsOfDelivery = factory.monthsOfDelivery;
    for(int i = 0; i < this -> monthsOfDelivery ; ++i)
        this -> deliveryHistory[i] = factory.deliveryHistory[i];
}

Factory Factory :: operator = (const Factory& factory)
{
    if(this != &factory)
    {   
        if(this -> deliveryHistory != NULL)
            delete [] this -> deliveryHistory;

        this -> name = factory.name;
        this -> adress = factory.adress;
        this -> country = factory.country;
        this -> size = factory.size;
        this -> numberOfCars = factory.numberOfCars;
        this -> transportationTax = factory.transportationTax;
        this -> productionPerWeek = factory.productionPerWeek;
        this -> availableTrailers = factory.availableTrailers; 
        this -> monthsOfDelivery = factory.monthsOfDelivery;
        this -> deliveryHistory = new int [factory.monthsOfDelivery];
        for(int i = 0; i < this -> monthsOfDelivery ; ++i)
            this -> deliveryHistory[i] = factory.deliveryHistory[i];

    }   
    return *this;
}

istream& operator >> (istream& in, Factory& factory)
{
    cout << "Name : " ; in >> factory.name;
    cout << "\nAdress : " ; in >> factory.adress;
    cout << "\nCountry : " ; in >> factory.country;
    cout << "\nSize : " ; in >> factory.size;
    cout << "\nProduction/week : " ; in >> factory.productionPerWeek;
    cout << "\nNumber of cars : " ; in >> factory.numberOfCars;
    cout << "\nTransportation tax (per car transported): " ; in >> factory.transportationTax;
    cout << "\nAvailable trailers : " ; in >> factory.availableTrailers;
    cout << '\n';
    return in;
}

ostream& operator << (ostream& out, const Factory& factory)
{
    out << "------------" << factory.name << "------------"
        << "\nAdress : " << factory.adress 
        << "\nCountry : " << factory.country
        << "\nUsable area : " << factory.size << "m^2"
        << "\nProduction/week : " << factory.productionPerWeek 
        << "\nCars available : " << factory.numberOfCars
        << "\nTransportation tax : " << factory.transportationTax
        << "\nAvailable trailers : " << factory.availableTrailers 
        << '\n';
        
        return out;
        


    //further description
}

Factory& Factory :: operator ++ ()
{
    this -> transportationTax++;
    return *this;
}

Factory Factory :: operator ++(int)
{
    Factory aux(*this);
    this -> transportationTax++;
    return aux;
}

double Factory :: operator * (double x)
{
    return this -> transportationTax * x;
}

double operator * (double x, Factory factory)
{
    return factory.transportationTax * x;
}

double Factory :: operator / (double x)
{
    return this -> transportationTax / x;
}

double operator / (double x, Factory factory)
{
    return factory.transportationTax / x;
}

Factory Factory :: operator[](int index)
{
    return *this;
}

void Factory :: operator *= (double x)
{
    this -> transportationTax *= x;
}

void Factory :: operator /= (double x)
{
    this -> transportationTax /= x;
}

bool Factory :: operator >= (const Factory& factory)
{   
    if(this -> size >= factory.size)
        return true;
    else    
        return false;
}

bool Factory :: operator == (const Factory& factory)
{
    if(this -> name == factory.name)
        return true;
    else
        return false;
}


Factory :: operator int ()
{
    return (int)this -> size;
}

string Factory :: getName()
{
    return this -> name;
}

int Factory :: calculateCarStock()
{
    return this-> numberOfCars * this -> transportationTax;
}
class Dealership
{

    map<int, Client> clientList;
    map<string, map<string, Car>> carList;
    
    float latePaymentTax[4];
    int sales, monthlySalaryExpenses, numberOfEmployees, numberOfCars;
    long value; 
    double averageSalary, averageCarPrice, revenue, profit, expenses;
    string name, adress, city, country;
   
public :
    
    Dealership (int sales, long value, double revenue, double profit, double expenses, int numberOfCars, int numberOfEmployees, int monthlySalaryExpenses,
                string name, string adress, string city, string country, float[]);

    Dealership ();

    Dealership(string name, string adress, string city, string country);

    Dealership(string name, long value, double revenue);

    Dealership (const Dealership& dealership);

   ~Dealership();

    Dealership operator = (const Dealership& Dealership);
            
    friend istream& operator >> (istream&, Dealership&);
    friend ostream& operator << (ostream&, const Dealership&);

    Dealership operator [](int);
    Dealership& operator ++ ();
    Dealership operator ++(int);

    Dealership operator +(Dealership);
    Dealership operator += (Dealership);
   
    Dealership operator +(Client&);
    Dealership operator += (Client&);
    
    Dealership operator + (Car&);
    Dealership operator += (Car&);


    friend Dealership operator + (Client&, Dealership);
    friend Dealership operator + (Car&, Dealership);


    Dealership operator *(int);
    friend Dealership operator * (int, Dealership);
    Dealership operator *= (int);
    explicit operator int(); 

    void sortCarsByName();
    void printCarList();

    bool operator >= (const Dealership&);
    bool operator == (const Dealership&);

    void setNumberOfCars(int x)
    {
        this -> numberOfCars = x;
    }

    int getNumberOfCars()
    {
        return this -> numberOfCars;
    }
    void calculateValue();
    void calculateAverageCarPrice();
    void updateRevenue(int);
    void refillStock(string, string, int, Factory);
    void calculateProfit();
    void setDealershipInfo();
    void showClients();
    void interestRateSetter(int, Client&);
    void discountCalculator(Car, Client&);
    void makePayment(Client&);
    Car getCar(string, string);
    bool checkCar(string, string);
    string getName()
    {
        return this -> name;
    }

};
bool Dealership :: checkCar(string brand, string model)
{   
    bool ok1 = 0, ok2 = 0;
    for(auto x : this -> carList)
        if(brand == x.first)
        {   ok1 = 1;
            break;
        }
    if (ok1)
        for(auto x : carList[brand])
            if(model == x.first)
                {
                    ok2 = 1;
                    break;
                }
    else
        return 0;
    
    if(ok1 == 1 && ok2 == 1)
        return 1;
    else
        return 0;

}

Car Dealership :: getCar(string brand, string model)
{
    return this -> carList[brand][model];
}

Dealership :: Dealership (int sales, long value, double revenue, double profit, double expenses, int numberOfCars, int numberOfEmployees, int monthlySalaryExpenses,
                          string name, string adress, string city, string country, float latePaymentTax[])
{
    
    this -> sales = sales;
    this -> revenue = revenue;
    this -> profit = profit;
    this -> expenses = expenses;
    this -> numberOfCars = numberOfCars;
    this -> numberOfEmployees = numberOfEmployees;
    this -> name = name;
    this -> adress = adress;
    this -> city = city;
    this -> country = country;
    this -> value = value;
    for(int i = 0 ; i < 3 ; ++i)
    {
        this -> latePaymentTax[i] = latePaymentTax[i];
    }

}
Dealership :: Dealership (): sales(0), value(0), revenue(0), profit(0), expenses(0), numberOfCars(0), numberOfEmployees(0), monthlySalaryExpenses(0),
                            name("None"), adress("None"), city("None"), country("None") {};

Dealership :: Dealership (string nume, string adress, string city, string country) : sales(0), value(0), revenue(0), profit(0), expenses(0), numberOfCars(0), numberOfEmployees(0), monthlySalaryExpenses(0)
{
    this -> name = name;
    this -> adress = adress;
    this -> city = city;
    this -> country = country;
}

Dealership :: Dealership (string name, long value, double revenue) : sales(0), profit(0), expenses(0), numberOfCars(0), numberOfEmployees(0), monthlySalaryExpenses(0),
                            adress("None"), city("None"), country("None")
{
    this -> name = name;
    this -> value = value;
    this -> revenue = revenue;
}   

Dealership :: Dealership(const Dealership& dealership)
{   
    this -> sales = dealership.sales;
    this -> revenue = dealership.revenue;
    this -> profit = dealership.profit;
    this -> expenses = dealership.expenses;
    this -> numberOfCars = dealership.numberOfCars;
    this -> numberOfEmployees = dealership.numberOfEmployees;
    this -> name = dealership.name;
    this -> adress = dealership.adress;
    this -> city = dealership.city;
    this -> country = dealership.country;
    this -> value = dealership. value;

    for(auto x : dealership.clientList)
        this -> clientList[x.first] = x.second;

    for(auto x : dealership.carList)
        for(auto y : x.second)
            this -> carList[x.first][y.first] = y.second; 

    
    for(int i = 0 ; i < 3 ; ++i)
    {
        this -> latePaymentTax[i] = dealership.latePaymentTax[i];
    }
}

Dealership Dealership :: operator = (const Dealership& dealership)
{   
    if(this !=&dealership)
    {
        this -> sales = dealership.sales;
        this -> revenue = dealership.revenue;
        this -> profit = dealership.profit;
        this -> expenses = dealership.expenses;
        this -> numberOfCars = dealership.numberOfCars;
        this -> numberOfEmployees = dealership.numberOfEmployees;
        this -> name = dealership.name;
        this -> adress = dealership.adress;
        this -> city = dealership.city;
        this -> country = dealership.country;
        this -> value = dealership.value;

        for(auto x : dealership.clientList)
            this -> clientList[x.first] = x.second;
        
        for(auto x : dealership.carList)
            for(auto y : x.second)
                this -> carList[x.first][y.first] = y.second; 

        for(int i = 0 ; i < 3 ; ++i)
    {
        this -> latePaymentTax[i] = dealership.latePaymentTax[i];
    }

    }
    return *this;
}

Dealership :: ~Dealership(){}


istream& operator >> (istream& in, Dealership& dealership)
{       
    cout << "\nName : "; in >> dealership.name;
    cout << "\nAdress : " ; in >> dealership.adress; 
    cout << "\nCity : " ; in >> dealership.city;
    cout << "\nCountry : " ; in >> dealership.country; 
    cout << "\nNumber of cars : " ; in >> dealership.numberOfCars; 
    cout << "\nNumber of employees : " ; in >> dealership.numberOfEmployees ;
    int input;
    cout <<"\nTax for 1 unpaid month : "; in >> dealership.latePaymentTax[0];
    for(int i = 1; i < 3; ++i)
    {
        cout << "Tax for " << i + 1 << " unpaid months : ";
        in >> input;
        dealership.latePaymentTax[i] = input; 
    }
    cout << "\n";
    dealership.setDealershipInfo();
    return in;
}

ostream& operator << (ostream& out, const Dealership& dealership)
{
    out << "----------------"<< dealership.name<<"----------------"
        << "\nAdress : " << dealership.adress 
        << "\nCity : " << dealership.city
        << "\nCountry : " << dealership.country 
        << "\nValue : " << dealership.value 
        << "\nRevenue : " << dealership.revenue 
        << "\nNumber of clients : " << dealership.clientList.size()
        << "\nNumber of cars : " << dealership.numberOfCars 
        << "\nNumber of employees : " << dealership.numberOfEmployees 
        << "\nSales : " << dealership.sales 
        << "\nAverage car price : " << dealership.averageCarPrice 
        << "\nValue : " << dealership.value;
    
        out << "\nTax for 1 unpaid month : " << dealership.latePaymentTax[0];
        for (int i = 1 ; i < 3; ++i)
            out << "\nTax for " << i + 1 << " unpaid months : " << dealership.latePaymentTax[i]; 
    
    out << '\n';    
    return out;
}

Dealership Dealership :: operator [](int index)
{
    return *this;
}

//pre-fixed ++
Dealership& Dealership :: operator ++()
{
    this -> sales++;
    return *this;
}

Dealership Dealership :: operator ++(int)
{
   
    Dealership aux = *this;
    this -> sales++;
    return aux;
}
//merge the dealerships
Dealership Dealership :: operator + (Dealership dealership1)
{
    
    dealership1.expenses += this -> expenses;
    dealership1.monthlySalaryExpenses += this -> monthlySalaryExpenses;
    dealership1.value += this -> value;
    dealership1.numberOfEmployees += this -> numberOfEmployees; 
    dealership1.numberOfCars += this -> numberOfCars;
    dealership1.profit += this -> profit;
    dealership1.revenue += this -> revenue;
    dealership1.sales += this -> sales;
    for(auto x : this -> clientList)
        dealership1.clientList[x.first] = x.second;

    return dealership1;
  
}

Dealership Dealership :: operator += (Dealership dealership)
{
    this -> expenses +=  dealership.expenses;
    this -> monthlySalaryExpenses += dealership.monthlySalaryExpenses;
    this -> value +=  dealership.value;
    this -> numberOfEmployees += dealership.numberOfEmployees; 
    this -> numberOfCars += dealership.numberOfCars;
    this -> profit += dealership.profit;
    this -> revenue += dealership.revenue;
    this -> sales += dealership. sales;
    for(auto x : dealership.clientList)
        this -> clientList[x.first] = x.second;

    return *this;
}

Dealership Dealership :: operator + (Client& client)
{   
    Dealership aux(*this);
    aux.clientList[client.getClientCode()] = client;
    return aux;

}

Dealership Dealership :: operator += (Client& client) 
{
    this -> clientList[client.getClientCode()] = client;
    return *this;
}

Dealership operator + (Client& client, Dealership dealership)
{
    dealership.clientList[client.getClientCode()] = client;
    return dealership;
}

Dealership Dealership :: operator +(Car& car)
{   
    Dealership aux(*this);
    aux.carList[car.getBrand()][car.getModel()] = car;
    return aux;
} 

Dealership Dealership :: operator += (Car& car) 
{
    this -> carList[car.getBrand()][car.getModel()] = car;
    return *this;
}

Dealership operator +(Car& car, Dealership dealership)
{
    dealership.carList[car.getBrand()][car.getModel()] = car;
    return dealership;
}

// obj * x
Dealership Dealership :: operator * (int x)
{
    Dealership aux(*this);
    aux.monthlySalaryExpenses *=  x;
    aux.numberOfCars *= x;
    aux.numberOfEmployees *= x;
    aux.value *= x;

    return aux;

}

Dealership Dealership :: operator *= (int x)
{
    Dealership aux(*this);
    this -> monthlySalaryExpenses *= x;
    this -> numberOfCars *= x;
    this -> numberOfEmployees *= x;
    this -> value *= x;

    return aux;

}
// nu iese
// void Dealership :: sortCarsByName()
// {
//     string* v;
//     v = new string [this -> carList.size()];
//     map<string,map<string, Car>> sortedMap;

//     int i = 0;
//     for(auto x : this -> carList)
//         v[i++] = x.first;
    
//     sort(v, v + carList.size() - 1);
//     i = 0;
//     for(auto x : this -> carList)
//         sortedMap[v[i++]] = x.second;
    
//     printCarList(sortedMap);

// }

void Dealership :: printCarList()
{
    for(auto i : this -> carList)
    {    
        cout << "------------------" << i.first << "------------------\n";
        for(auto x : i.second)
            cout << x.second << '\n';
    }

}
//x * obj
Dealership operator * (int x, Dealership dealership)
{
    dealership.monthlySalaryExpenses *= x;
    dealership.numberOfCars *= x;
    dealership.numberOfEmployees *= x;
    dealership.value *= x; 
    return dealership;
}

Dealership :: operator int()
{
    return (int)this -> revenue; 
}

bool Dealership :: operator >= (const Dealership& dealership)
{
    if(this -> value >= dealership.value)
        return true;
    else    
        return false;
}

bool Dealership :: operator == (const Dealership& dealership)
{
    if(this -> value == dealership.value)
        return true;
    else
        return false;
}

void Dealership :: calculateAverageCarPrice()
{
    this -> averageCarPrice = (double) this -> value / this -> numberOfCars;  
}
void Dealership :: calculateValue()
{   
    int sum = 0;
    for(auto x : this -> carList)
        for(auto y : x.second)
            sum += y.second.getPrice();
    this -> value = sum;
}

void Dealership :: updateRevenue(int sum)
{
    this -> revenue += sum;

}

void Dealership :: refillStock(string brand, string model, int numberOfCars, Factory factory)
{
    this -> carList[brand][model] += numberOfCars;
    this -> expenses += factory.getTransportationTax() * numberOfCars;
}

void Dealership :: calculateProfit()
{
    this -> profit = this -> revenue - this -> expenses;
}


void Dealership :: setDealershipInfo()
{
    calculateValue();
    calculateAverageCarPrice();
    calculateProfit();
}

void Dealership :: showClients()
{
    for(auto x : this -> clientList)
    cout << x.second << '\n';
}

void Dealership :: interestRateSetter(int plan, Client& client)
{
    switch (plan)
    {
        case 36 : {
                client.setInterestRate(0.75);
                client.setMonthsLeftOfPayment(36);
                break;
        }
        case 60 : {
                client.setInterestRate(0.15); 
                client.setMonthsLeftOfPayment(60);
                break;
        }
        case 120 :{
                client.setInterestRate(0.2); 
                client.setMonthsLeftOfPayment(120);
                break; 
        }
    }
}
void Dealership :: discountCalculator(Car car, Client& client)
{   
    switch (client.getPreviousPurchases())
    {
        case 1 : client.setDiscount(0.075 * car.getPrice());
                break;
        case 2: client.setDiscount(0.1 * car.getPrice());
                break;
    }
}

void Dealership :: makePayment(Client& client)
{   
   
    this -> sales++;
    client.setUnpaidMonths(0);
    client.setMonthsLeftOfPayment(client.getMonthsLeftOfPayment() - 1);
    client.setRemainingSumToBePaid(client.getRemainingSumToBePaid());
    client.setSumPaidUntilNow(client.getThisMonthToBePaid());
    client.setThisMonthToBePaid(0);
    client ++;
    client.setUnpaidSum(0);
    client.setDaysSinceLastPayment(0);
    
}

int main()
{   
    string password = "123";
    setConsoleColor(15);
    
    Client c1("Client1", 24, "male", "ro", "Street1 building1 apartment1", "07XXXXXXX","email@.gmail.com", 0.075, 20, 0, 16, 10, 0, 0, true, 250.75, 13000, 10000, 23000, 0);
    Client c2("Client2", 30, "male", "ro", "Street2 building2 apartment2", "07XXXXXXX","email@.gmail.com", 0.175, 40, 0, 20, 15, 0, 0, true, 350.2, 15000, 70000, 33000, 150.75);
    Client c3("Client2", 34, "male", "ro", "Street3 building3 apartment3", "07XXXXXXX","email@.gmail.com", 0.075, 30, 0, 12, 15, 0, 0, true, 450.2, 12000, 100000, 43000, 0);


    Car car1("Car1","Model1", "Blue", 2500, 300, 20000, 100000, 2020, "4x4", "SUV", "GER", "Yes", "yes", "Diesel", "EURO4", 50, "7+1", "yes", "yes", "leather", "leather", 200);
    Car car2("Car2", "Model2" ,"blue", 4500 , 500, 50000, 75000, 2021, "Front" , "coupe", "GER", "yes", "yes",  "Diesel", "EURO6", 30, "7+1",  "yes", "yes",  "leather",  "leather", 300);
    Car car3("Car3", "Model3" ,"blue", 3500 , 200, 3000, 875000, 2010, "4x4" , "SUV", "BG", "yes", "no",  "Diesel", "EURO6", 60, "5+1",  "yes", "no",  "leather",  "leather", 100);
    float taxes []= {2.5, 5, 10};
    
    Dealership d1(100, 2050100, 110000.53, 50000, 10000, 100, 50, 5000, "DEALERSHIP1", "ADRESS1", "CITY1", "COUNTRY1", taxes);
    Dealership d2(520, 2053000, 153040.53, 45000, 10000, 100, 530, 15000, "DEALERSHIP2", "ADRESS2", "CITY2", "COUNTRY2", taxes);
    Dealership d3(400, 2045000, 413030.53, 30000, 100, 1000, 30, 4500, "DEALERSHIP3", "ADRESS3", "CITY3", "COUNTRY3", taxes);



    // Factory f1("FACTORY1", "ADRESSFACTORY1" , "RO", 2040, 30, 15000, 107, 500, 1000);
    // Factory f2("FACTORY2", "ADRESSFACTORY2" , "RO", 4532, 24, 40000, 321, 403, 2000);
    // Factory f3("FACTORY3", "ADRESSFACTORY3" , "RO", 3500, 33, 21000, 700, 400, 3000);


    c1 += car1;
    c2 += car2;
    c3 += car3;

    d1 += c1;
    d2 += c2;
    d3 += c3;

    d1 += car1;
    d2 += car2;
    d3 += car3;

//Menu
while(true)
{   
    string userInput;
    cout << "You log in as : " 
        << "\n1. Administrator"
        << "\n2. Client"
        << "\n3. Exit";
    setConsoleColor(9);
    cout << "\nYour answer : ";
    cin >> userInput;
    system("cls");
    setConsoleColor(15);
    
    if(userInput == "1")
    {   
        while(true)
        {
            string userInput;
            cout << "Enter the password : ";
            cin >> userInput;
            if(userInput != password)
                {   
                    string userInput;
                    setConsoleColor(12);
                    cout << "\nAccess denied!\n";
                    setConsoleColor(15);
                    cout << "Do you want to enter the password again ? (y/n) : ";
                    cin >> userInput;
                    if(userInput == "y")
                    {  
                        system("cls");
                        continue;
                    }
                    else 
                    {   
                        system("cls");
                        break;
                    }
                    
                }
            else
            {
                while(true)
                {   
                    system("cls");
                    setConsoleColor(15);
                    string userInput;
                    cout << "Choose one of the following actions : "
                        << "\n1.View data"
                        << "\n2.Back";
                    setConsoleColor(9);
                    cout << "\nYour answer : ";
                    cin >> userInput;
                    if(userInput == "1")
                    {  
                        while(true)
                        {   
                            system("cls");
                            setConsoleColor(15);
                            string userInput;
                            system("cls");
                            cout << "1.View dealership info "
                                << "\n2.View car info "
                                << "\n3.View client info "
                                << "\n4.View factory info "
                                << "\n5.Back";
                            setConsoleColor(9);
                            cout << "\nYour answer : ";
                            cin >> userInput;
                            setConsoleColor(15);
                            if(userInput == "4")
                            {
                                while(true)
                                {    
                                    system("cls");
                                    setConsoleColor(15);
                                    string userInput;
                                    cout << "Select one of the followings : "
                                        // << "\n1." << f1.getName()
                                        // << "\n2." << f2.getName()
                                        // << "\n3." << f3.getName()
                                        << "\n4.Back";
                                    setConsoleColor(9);
                                    cout << "\nYour answer : ";
                                    cin >> userInput;
                                    setConsoleColor(15);
                                    if(userInput == "1")
                                    {
                                        while(true)
                                        {   
                                            system("cls");
                                            setConsoleColor(15);
                                            string userInput;
                                            system("cls");
                                            // cout << f1;
                                            setConsoleColor(12);
                                            cout << "\nTo go back enter anything : ";
                                            cin >> userInput;
                                            setConsoleColor(15);
                                            break;
                                        }
                                    }
                                    else if(userInput == "2")
                                    {
                                        while(true)
                                        {   
                                            system("cls");
                                            setConsoleColor(15);    
                                            string userInput;
                                            system("cls");
                                            // cout << f2;
                                            setConsoleColor(12);
                                            cout << "\nTo go back enter anything : ";
                                            cin >> userInput;
                                            setConsoleColor(15);
                                            break;
                                        }
                                    }
                                    else if(userInput == "3")
                                    {
                                        while(true)
                                        {   
                                            system("cls");
                                            setConsoleColor(15);
                                            string userInput;
                                            system("cls");
                                            // cout << f3;
                                            setConsoleColor(12);
                                            cout << "\nTo go back enter anything : ";
                                            cin >> userInput;
                                            setConsoleColor(15);
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        system("cls");
                                        break;
                                    }
                                    
                                    
                                }
                            }
                            else if(userInput == "5")
                            {
                                system("cls");
                                break;
                            }
                            else
                            {
                                while(true)
                                {   
                                    system("cls");
                                    setConsoleColor(15);
                                    string userInput;
                                    cout << "Choose one of the followings : "
                                        << "\n1." << d1.getName() 
                                        << "\n2." << d2.getName() 
                                        << "\n3." << d3.getName()
                                        << "\n4.Back";
                                    setConsoleColor(9);
                                    cout << "\nYour answer : ";
                                    cin >> userInput;
                                    setConsoleColor(15);
                                    system("cls");

                                    if(userInput == "1")
                                    {
                                        string userInput;
                                        cout << "1.View dealership info"
                                            << "\n2.View dealership clients"
                                            << "\n3.View cars available"
                                            << "\n4.Back";
                                        setConsoleColor(9);
                                        cout << "\nYour answer : ";
                                        cin >> userInput;
                                        setConsoleColor(15);
                                        system("cls");

                                        if(userInput == "1")
                                        {
                                            while(true)
                                            {       
                                                system("cls");
                                                setConsoleColor(15);
                                                string userInput;
                                                d1.calculateAverageCarPrice();
                                                cout << d1;
                                                setConsoleColor(12);
                                                cout << "To go back enter anything : ";
                                                cin >> userInput;
                                                setConsoleColor(15);
                                                system("cls");
                                                break;

                                            }
                                        }
                                        else if(userInput == "2")
                                        {
                                            while(true)
                                            {   
                                                system("cls");
                                                setConsoleColor(15);
                                                string userInput;
                                                d1.showClients();
                                                setConsoleColor(12);
                                                cout << "To go back enter anything : ";
                                                cin >> userInput;
                                                setConsoleColor(15);
                                                system("cls");
                                                break;

                                            }
                                        }
                                        else if(userInput == "3")
                                        {
                                            while(true)
                                            {   

                                                system("cls");
                                                setConsoleColor(15);
                                                string userInput;
                                                d1.printCarList();
                                                setConsoleColor(12);
                                                cout << "To go back enter anything : ";
                                                cin >> userInput;
                                                setConsoleColor(15);
                                                system("cls");
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;

                                        }
                                    }
                                    if(userInput == "2")
                                    {
                                        string userInput;
                                        cout << "1.View dealership info"
                                            << "\n2.View dealership clients"
                                            << "\n3.View cars available"
                                            << "\n4.Back";
                                        setConsoleColor(9);
                                        cout << "\nYour answer : ";
                                        cin >> userInput;
                                        setConsoleColor(15);
                                        system("cls");

                                        if(userInput == "1")
                                        {
                                            while(true)
                                            {       
                                                system("cls");
                                                setConsoleColor(15);
                                                string userInput;
                                                d2.calculateAverageCarPrice();
                                                cout << d2;
                                                setConsoleColor(12);
                                                cout << "To go back enter anything : ";
                                                cin >> userInput;
                                                setConsoleColor(15);
                                                system("cls");
                                                break;

                                            }
                                        }
                                        else if(userInput == "2")
                                        {
                                            while(true)
                                            {   
                                                system("cls");
                                                setConsoleColor(15);
                                                string userInput;
                                                d2.showClients();
                                                setConsoleColor(12);
                                                cout << "To go back enter anything : ";
                                                cin >> userInput;
                                                setConsoleColor(15);
                                                system("cls");
                                                break;

                                            }
                                        }
                                        else if(userInput == "3")
                                        {
                                            while(true)
                                            {   

                                                system("cls");
                                                setConsoleColor(15);
                                                string userInput;
                                                d2.printCarList();
                                                setConsoleColor(12);
                                                cout << "To go back enter anything : ";
                                                cin >> userInput;
                                                setConsoleColor(15);
                                                system("cls");
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;

                                        }
                                    }
                                    else if(userInput == "3")
                                    {
                                        string userInput;
                                        cout << "1.View dealership info"
                                            << "\n2.View dealership clients"
                                            << "\n3.View cars available"
                                            << "\n4.Back";
                                        setConsoleColor(9);
                                        cout << "\nYour answer : ";
                                        cin >> userInput;
                                        setConsoleColor(15);
                                        system("cls");

                                        if(userInput == "1")
                                        {
                                            while(true)
                                            {       
                                                system("cls");
                                                setConsoleColor(15);
                                                string userInput;
                                                d3.calculateAverageCarPrice();
                                                cout << d3;
                                                setConsoleColor(12);
                                                cout << "To go back enter anything : ";
                                                cin >> userInput;
                                                setConsoleColor(15);
                                                system("cls");
                                                break;

                                            }
                                        }
                                        else if(userInput == "2")
                                        {
                                            while(true)
                                            {   
                                                system("cls");
                                                setConsoleColor(15);
                                                string userInput;
                                                d3.showClients();
                                                setConsoleColor(12);
                                                cout << "To go back enter anything : ";
                                                cin >> userInput;
                                                setConsoleColor(15);
                                                system("cls");
                                                break;

                                            }
                                        }
                                        else if(userInput == "3")
                                        {
                                            while(true)
                                            {   

                                                system("cls");
                                                setConsoleColor(15);
                                                string userInput;
                                                d3.printCarList();
                                                setConsoleColor(12);
                                                cout << "To go back enter anything : ";
                                                cin >> userInput;
                                                setConsoleColor(15);
                                                system("cls");
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;

                                        }
                                    }
                                else
                                {
                                    system("cls");
                                    break;
                                }
                            }
                        }
                            
                            
                    }
                    
                }
                    

            else
            {
                system("cls");
                break;
            }       
                }
    
                
             }
         }
    }
    else if(userInput == "2")
    {   
        while(true)
        {   
            string userInput;
            system("cls");
            setConsoleColor(15);
            cout << "Choose the dealership :"
            << "\n1." << d1.getName() 
            << "\n2.Back";        
            setConsoleColor(9);
            cout << "\nYour answer : ";
            cin >> userInput;
            system("cls");
            setConsoleColor(15);
        if(userInput == "1")
        {
            while(true)
            {   
                string userInput;
                system("cls");
                setConsoleColor(15);
                cout << "You're logging in as : "
                    <<"\n1.New client"
                    <<"\n2.Existing client"
                    <<"\n3.Back";
                setConsoleColor(9);
                cout << "\nYour answer : ";
                cin >> userInput;
                system("cls");
                setConsoleColor(15);

                if(userInput == "1")
                {   
                    while(true)
                    {
                        string userInput;
                        system("cls");
                        setConsoleColor(15);
                        cout << "1.Register"
                            <<"\n2.Back";
                        setConsoleColor(9);
                        cout <<"\nYour answer : ";
                        cin >> userInput;
                        setConsoleColor(15);
                        if(userInput == "1")
                        {
                            string userInput;
                            Client client10000;
                            cin >> client10000;
                            system("cls");
                            setConsoleColor(9);
                            cout << "Wonderful! Now let's take the next step!";
                            while(true)
                            {
                                setConsoleColor(15);
                                cout <<"Choose one of the following actions :"
                                    <<"\n1.View cars"
                                    <<"\n2.Buy a car"
                                    <<"\n3.Back";
                                setConsoleColor(9);
                                cout <<"\nYour answer : ";
                                cin >> userInput;
                                setConsoleColor(15);
                                if(userInput == "1")
                                {
                                    while(true)
                                    {   
                                        system("cls");
                                        setConsoleColor(15);
                                        string userInput;
                                        d1.printCarList();
                                        setConsoleColor(12);
                                        cout << "To go back enter anything : ";
                                        cin >> userInput;
                                        setConsoleColor(15);
                                        system("cls");
                                        break;
                                    }
                                }
                                else if(userInput != "2")
                                {
                                    system("cls");
                                    break;
                                }
                                else if(userInput == "2")
                                {
                                    while(true)
                                    {
                                        system("cls");
                                        setConsoleColor(15);
                                        string userInput;
                                        cout << "Payment in installments ?"
                                            <<"\n1.Yes"
                                            <<"\n2.No"
                                            <<"\n3.Back";
                                        setConsoleColor(9);
                                        cout <<"\nYour answer : ";
                                        cin >> userInput;
                                        setConsoleColor(15);
                                        if(userInput == "2")
                                        {
                                            while(true)
                                            {   
                                                client10000.setPaymentInInstallments(0);
                                                system("cls");
                                                setConsoleColor(15);
                                                string userInput, brand, model;
                                                cout << "Enter the brand and the model of the car you would like to buy : "
                                                    << "\nBrand : "; cin >> brand;
                                                cout << "\nModel : "; cin >> model;
                                                if(!d1.checkCar(brand, model))
                                                {
                                                    setConsoleColor(12);
                                                    cout <<"\nWe couldn't find the car you are looking for in this dealership :(";
                                                    continue;
                                                }
                                                else
                                                    {   
                                                        string userInput;
                                                        
                                                        system("cls");
                                                        cout << "Choose the currency : "
                                                            <<"\nEUR"
                                                            <<"\nRON"
                                                            <<"\nUSD"
                                                            <<"\nGBP";
                                                        setConsoleColor(9);
                                                        cout <<"\nYour answer : ";
                                                        cin >> userInput;
                                                        setConsoleColor(15);
                                                        system("cls");
                                                        d1.getCar(brand, model).changeCarPrice(userInput);
                                                        cout << "\nYou'll have to pay " << d1.getCar(brand, model).getPrice() << " " << userInput;
                                                        cout << "\nDo you proceed to make the payment ?"
                                                            << "\n1.Yes"
                                                            << "\n2.No";
                                                        setConsoleColor(9);
                                                        cout <<"\nYour answer : ";
                                                        cin >> userInput;
                                                        setConsoleColor(15);
                                                        if(userInput == "No")
                                                            return 0;
                                                        else
                                                        {   
                                                            system("cls");
                                                            client10000 += d1.getCar(brand, model);
                                                            d1 += client10000;
                                                            setConsoleColor(14);
                                                            cout <<"Fantastic! You'll receive an email with all the following steps you have to take. STAY TUNED!";
                                                            return 0;
                                                        }

                                                    }

                                            }
                                        }
                                        else if(userInput != "1")
                                        {
                                            system("cls");
                                            break;
                                        }
                                        else if(userInput == "1")
                                        {   
                                            string userInput;
                                            cout << "Choose one of the following plans"
                                                <<"\n1. 2.5 year payment with 7.5'%' interest rate" 
                                                <<"\n2. 5 year payment with 15'%' interest rate"
                                                <<"\n3. 10 year payment with 20'%' interest rate";
                                                setConsoleColor(9);
                                                cout <<"\nYour answer : ";
                                                cin >> userInput;
                                                setConsoleColor(15);
                                                if(userInput == "1")
                                                    d1.interestRateSetter(36, client10000);
                                                if(userInput == "2")
                                                    d1.interestRateSetter(60, client10000);
                                                if(userInput == "3")
                                                    d1.interestRateSetter(120, client10000);
                                                system("cls");
                                                while(true)
                                                {   
                                                    client10000.setPaymentInInstallments(0);
                                                    system("cls");
                                                    setConsoleColor(15);
                                                    string userInput, brand, model;
                                                    cout << "Enter the brand and the model of the car you would like to buy : "
                                                        << "\nBrand : "; cin >> brand;
                                                    cout << "\nModel : "; cin >> model;
                                                    if(!d1.checkCar(brand, model))
                                                    {
                                                        setConsoleColor(12);
                                                        cout <<"\nWe couldn't find the car you are looking for in this dealership :(";
                                                        continue;
                                                    }
                                                    else
                                                        {   
                                                            string userInput;
                                                            
                                                            system("cls");
                                                            cout << "Choose the currency : "
                                                                <<"\nEUR"
                                                                <<"\nRON"
                                                                <<"\nUSD"
                                                                <<"\nGBP";
                                                            setConsoleColor(9);
                                                            cout <<"\nYour answer : ";
                                                            cin >> userInput;
                                                            setConsoleColor(15);
                                                            system("cls");
                                                            d1.getCar(brand, model).changeCarPrice(userInput);
                                                            cout << "\nYou'll have to pay " << d1.getCar(brand, model).getPrice() +  d1.getCar(brand, model).getPrice() * client10000.getInterestRate() << " " << userInput;
                                                            cout << "\nDo you proceed to make the acquisition ?"
                                                                << "\n1.Yes"
                                                                << "\n2.No";
                                                            setConsoleColor(9);
                                                            cout <<"\nYour answer : ";
                                                            cin >> userInput;
                                                            setConsoleColor(15);
                                                            if(userInput == "No")
                                                                return 0;
                                                            else
                                                            {   
                                                                system("cls");
                                                                client10000 += d1.getCar(brand, model);
                                                                d1 += client10000;
                                                                setConsoleColor(14);
                                                                cout <<"Fantastic! You'll receive an email with all the following steps you have to take. STAY TUNED!";
                                                                return 0;
                                                            }
                                                        }

                                                    }

                                            }
                                                

                                        }

                                    }
                                }
                            }
                        }    
                    }

                }
            }
        }   
    }
}

    return 0;

}