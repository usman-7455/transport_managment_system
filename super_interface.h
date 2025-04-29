#pragma once

#include	<fstream>
#include	<string>
#include	<windows.h>
#include	<iostream>
#include    <conio.h>
using namespace std;
static int harrypotter = 0;//to store the services
static int spiderman = 0;//to store the booking history
class TMS;
// Defining class name for storing first name and last name of a person
class name {
protected:
	// Declaring private variables f_name and l_name
	std::string f_name; // First Name
	std::string l_name; // Last Name
public:
	// Default constructor
	name();
	void display_name();
	// Constructor to set first and last name
	name(std::string, std::string);

	// Function to get first name
	std::string get_f_name();

	// Function to get last name
	std::string get_l_name();

	// Function to set first name
	void set_f_name(std::string);

	// Function to set last name
	void set_l_name(std::string);

	// Friend functions for input and output stream
	friend void assign_data(TMS& management);
	friend istream& operator>>(istream& in, name& obj);
	friend ostream& operator<<(ostream& out, name& obj);
};

// Defining class date for storing date
class date {
private:
	// Declaring private variables day, month and year
	int day;
	int month;
	int year;
public:
	// Default constructor
	date();
	void display_date();
	friend void read_booking_history(TMS& management);
	// Constructor to set day, month and year
	date(int dd, int mm, int yy);

	// Function to get day
	int get_day();

	// Function to get month
	int get_month();

	// Function to get year
	int get_year();

	// Function to set year
	void set_year(int);

	// Function to set month
	void set_month(int);

	// Function to set day
	void set_day(int);

	// Friend functions for input and output stream
	template<typename t1, typename t2>
	friend t1* invoker (t2&);
	friend void assign_data(TMS& management);
	friend istream& operator>>(istream& in, date& obj);
	friend ostream& operator<<(ostream& out, date& obj);
};

// Defining class m_time for storing time
class m_time
{
	// Declaring private variables hour, minute and second
	int hour;
	int sec;
	int min;
public:
	// Default constructor
	m_time();
	void display_time();
	friend void read_booking_history(TMS& management);
	// Constructor to set hour, minute and second
	m_time(int, int, int);

	// Function to get hour
	int get_hour();

	// Function to get minute
	int get_min();

	// Function to get second
	int get_sec();

	// Function to set hour
	void set_hour(int);

	// Function to set minute
	void set_min(int);

	// Function to set second
	void set_sec(int);

	// Friend functions for input and output stream

	friend istream& operator>>(istream& in,  m_time& obj);
	friend ostream& operator<<(ostream& out, m_time& obj);
};

class service {
	std::string source; // the starting point of the journey
	std::string destination; // the destination of the journey
	float distance; // the distance between the source and destination
	date bookingdate; // the date on which the service is booked
	m_time bookingtime; // the time at which the service is booked
	bool status; // the current status of the service (active or inactive)
	float fuelrate; // the fuel rate of the vehicle
	int car_id; // the ID of the car used for the service
	int driver_id; // the ID of the driver assigned to the service
	int vehicle_id; // the ID of the vehicle used for the service
	int serviceid;
	int customerbooked;
public:
	void display_service();
	friend service* get_bookinghistoryfrom(TMS& management, service* booking);
	friend void get_bookinghistory(TMS& management);
	friend service* booking_historyfunc(TMS& management, service* booking_history);
	//friend void read_booking_history(TMS& management);
	int get_serviceid();
	void set_serviceid(int);
	int get_customerbooked();
	void set_customerbooked(int);
	service();//default constructor
	service(string sour, string dest, float dist, date bdate, m_time btime, bool stat, float fuelrat, int ciid, int diid, int viid);
	void set_source(std::string); // function to set the starting point of the journey
	void set_destintion(std::string); // function to set the destination of the journey
	void set_distance(float); // function to set the distance between the source and destination
	void set_booking_date(int, int, int); // function to set the booking date of the service
	void set_booking_time(int, int, int); // function to set the booking time of the service
	void set_status_service(bool); // function to set the status of the service
	void set_driver_id(int); // function to set the driver ID of the service
	void set_vehicle_id(int); // function to set the vehicle ID of the service
	std::string  get_source();
	std::string  get_destination();
	float  get_distance();
	date  get_booking_date();
	m_time  get_time();
	bool  get_status();
	int  get_driver_id();
	int  get_vehicle_id();
	int  get_car_id();
	friend service* invoker(TMS&,service[]);
	friend istream& operator>>(istream& in,  service& obj); // friend function to overload the >> operator for input
	friend ostream& operator<<(ostream& out, service& obj); // friend function to overload the << operator for output
};

class ride {
	service serviceride; // an object of the service class to store the details of the ride
	int noofPassengers; // the number of passengers in the ride
	string ridetype; // the type of ride (intercity or intracity)
	float driverranking; // the driver's ranking on a scale of 0 to 5
	float vehicleranking; // the vehicle's ranking on a scale of 0 to 5
public:
	void display_ride();
	ride(); // default constructor
	ride(service,int,string,float,float); // constructor with parameters
	friend istream& operator>>(istream& in, ride& obj); // friend function to overload the >> operator for input
	friend ostream& operator<<(ostream& out,ride& obj); // friend function to overload the << operator for output
	void set_noofpassengers(int); // function to set the number of passengers in the ride
	void set_ridetype(std::string); // function to set the type of ride
	void set_driverranking(float); // function to set the driver's ranking
	void set_vehicleranking(float); // function to set the vehicle's ranking
	int get_noofpassengers(); // function to get the number of passengers in the ride
	std::string get_ridetype(); // function to get the type of ride
	float get_driverranking(); // function to get the driver's ranking
	float get_vehicleranking(); // function to get the vehicle's ranking
};

class delivery {
	service sdelivery; // a service object to represent the delivery service
	float goodweight; // the weight of goods in kilograms
	std::string goodtype; // the type of goods being delivered
	//you can add more members here if required
	//add member functions
public:
	void display_delivery();
	delivery(); // a default constructor
	delivery(service, float, std::string); // a constructor that takes arguments to initialize the members
	void set_goodweight(int); // a member function to set the weight of the goods
	void set_goodtype(std::string); // a member function to set the type of the goods
	float get_goodweight(); // a member function to get the weight of the goods
	service get_sdelivery(); // a member function to get the service object representing the delivery service
	std::string get_goodtype(); // a member function to get the type of the goods
	friend istream& operator>>(istream& in, delivery& obj); // a friend function to read data from an input stream into the object
	friend ostream& operator<<(ostream& out,  delivery& obj); // a friend function to write data from the object to an output stream
};

// A class to store the details of a person
class person {
private:
	name pname; // Object to store the name of the person
	date dob; // Object to store the date of birth of the person
	int age; // Age of the person
	int pid; // ID of the person
public:
	// Default constructor
	person();
	void display_person();
	// Parameterized constructor
	person(name, date, int, int);

	// Getter functions
	name get_pname();
	date get_pdate();
	int get_page();
	int get_pid();

	// Setter functions
	void set_ppname(std::string, std::string);
	void set_pdate(int, int, int);
	void set_page(int);
	void set_pid(int);

	// Overloaded input/output operators as friends
	friend void assign_data(TMS& management);
	friend istream& operator>>(istream& in,  person& obj);
	friend ostream& operator<<(ostream& out,  person& obj);
};

// A class to store the details of a customer
class customer {
private:
	int servicesbooked;
	person customi; // Object to store the details of the customer
	int cid; // ID of the customer
	service* bookinghistory; // Array to store the addresses of services booked by the customer
	// More members can be added here if required
public:
	void display_customer();
	friend service* get_bookinghistoryfrom(TMS& management, service* booking);
	void get_booking_history(int i, TMS& management);
	// Getter and setter functions for the ID of the customer
	friend void read_booking_history(TMS& management);
	customer();
	void set_servicesbooked(int a);
	friend void paste_bookinghistory(TMS& management);
	friend service* get_bookinghistory(TMS& management,service*);
	customer(person,int);
	void set_custom(person c);
	person get_custom();
	int getCId() const;
	void setCId(int cid);
	//section booking history
	void servicesbookedincrease();
	int get_servicesbooked();
	void allocatebooking();
	void set_entity(service&obj);//to settle down the service
	//section booking history over
	// Overloaded input/output operators as friends
	friend void assign_data(TMS& management);
	friend istream& operator>>(istream& in,  customer& obj);
	friend ostream& operator<<(ostream& out,customer& obj);
};

// A class to store the details of a driver
class driver {
private:
	person d; // Object to store the details of the driver
	int did; // ID of the driver
	int noofLicences; // Number of licenses held by the driver
	float overallranking; // Overall ranking of the driver
	float salary; // Salary of the driver
	int experience; // Experience of the driver
	int status; // Status of the driver (1 for free, 2 if booked and 3 if canceled)
	char* licencelist; // Array to store the types of licenses held by the driver
	service* serviceHistory; // Array to store the addresses of services provided by the driver
	// More members can be added here if required
public:
	void display_driver();
	friend void increase_service(TMS& management, int drivernumber);
	friend void store_service_driver(TMS& management);
	static int service_no;
	// Parameterized constructor
	driver(person, int, int, float, int, int);
	void assign_licenselist();
	// Default constructor
	driver();
	void get_service(int);
	void initializer_service();
	// Getter functions
	int getdid() const;
	int getNoOfLicences() const;
	float getOverallRanking() const;
	float getSalary() const;
	int getExperience() const;
	int getStatus() const;

	// Setter functions
	void set_id(int);
	void set_overallranking(float);
	void set_salary(float);
	void set_experience(int);
	void set_Status(int);
	~driver();
	// Overloaded input/output operators as friends
	

	friend void assign_data(TMS& management);
	friend istream& operator>>(istream& in, driver& obj);
	friend ostream& operator<<(ostream& out,driver& obj);
};

// A class to store the details of a feature
class feature {
	int fid; // ID of the feature
	std::string description; // Description of the feature
	float cost; // Cost of the feature
public:
	void display_feature();
	// Default constructor
	feature();

	// Parameterized constructor
	feature(std::string, float);

	// Getter functions
	float get_cost();
	std::string get_description();

	// Setter functions
	void set_cost(float);
	void set_description(std::string);

	// Overloaded input/output operators as friends
	friend istream& operator>>(istream& in,feature& obj);
	friend ostream& operator<<(ostream& out,feature& obj);
};

// vehicle class for storing information about a vehicle
class vehicle {
	// member variables
	int vid;
	int registrationno;
	float avgMileage;
	string LicenceType; // License required for driving the vehicle string
	bool status; // false for free, true if booked in a service already
	string fueltype;
	float overallranking;
	date manufacturingDate;

public:
	void display_vehicle();
	// constructors
	vehicle(int, int, float, std::string, std::string, float, date,service);
	vehicle();
	feature* list;
	service** serviceHistory;
	// getter methods
	void assign_feature(int);//function to assign space to feature lists;
	void assign_servicehistory(service,int&,int&);
	int get_vid();
	int get_registrationno();
	float get_avg_milage();
	std::string get_license_type();
	bool get_status();
	std::string get_fueltype();
	float get_overallranking();
	date get_manufacturingdate();
	feature get_list();

	// setter methods
	void set_vid(int);
	void set_registrationno(int);
	void set_avg_milage(float);
	void set_license_type(std::string);
	void set_status(bool);
	void set_fueltype(std::string);
	void set_overallranking(float);
	void set_manufacturingdate(int, int, int);
	void set_list(std::string, float);
	~vehicle();
	// friend functions to overload >> and <<
	friend void assign_data(TMS& management);
	friend istream& operator>>(istream& in, vehicle& obj);
	friend ostream& operator<<(ostream& out,  vehicle& obj);
};

// transportation class for storing information about a mode of transportation
class transportation {
	// member variables
	vehicle vh;
	std::string name;
	float max_weight;

public:
	void display_transportation();
	// constructors
	transportation();
	transportation(vehicle, std::string, float);

	// getter methods
	std::string get_name();
	float get_max_weight();

	// setter methods
	void set_name(std::string);
	void set_max_weight(float);

	// friend functions to overload >> and <<
	friend istream& operator>>(istream& in, transportation& obj);
	friend ostream& operator<<(ostream& out, transportation& obj);
};

// light class for storing information about a light mode of transportation
class light {
	// member variables
	transportation t1;
public:
	// constructors
	light();
	light(transportation);

	// friend functions to overload >> and <<
	friend istream& operator>>(istream& in, light& obj);
	friend ostream& operator<<(ostream& out, light& obj);
};

// heavy class for storing information about a heavy mode of transportation
class heavy {
	// member variables
	transportation t2;

public:
	// constructors
	heavy();
	heavy(transportation);

	// friend functions to overload >> and <<
	friend istream& operator>>(istream& in, heavy& obj);
	friend ostream& operator<<(ostream& out,heavy& obj);
};

// ridev class for storing information about a ride vehicle
class ridev {
	// member variables
	vehicle vh;
	std::string name;
	int seats;//seats in the vehicles for passenegers

public:
	// constructors
	ridev(vehicle, std::string, int);
	ridev();

	// getter and setter methods
	void set_seats(int);
	void set_name(string n);
	int get_seats();
	string get_name();

	// friend functions to overload >> and <<
	friend istream& operator>>(istream& in, ridev& obj);
	friend ostream& operator<<(ostream& out,ridev& obj);
};

// This class represents a common vehicle that combines the features of a ridev and a transportation
class common_vehicle : public ridev, public transportation {
	ridev rv;
	transportation tv;
public:
	// Constructor that takes a ridev and a transportation object as parameters
	common_vehicle(ridev, transportation);
	// Default constructor
	common_vehicle();
	// Overloaded input/output stream operators for handling input/output of common_vehicle objects
	friend istream& operator>>(istream& in, common_vehicle& obj);
	friend ostream& operator<<(ostream& out,  common_vehicle& obj);
};

// This class represents a small vehicle that inherits from a ridev
class smallv {
	ridev rv;
public:
	smallv();
	// Constructor that takes a ridev object as a parameter
	smallv(ridev);
	// Overloaded input/output stream operators for handling input/output of small vehicle objects
	friend istream& operator>>(istream& in, smallv& obj);
	friend ostream& operator<<(ostream& out, smallv& obj);
};

// This class represents a large vehicle that inherits from a ridev
class large {
	ridev rv;
public:
	large();
	// Constructor that takes a ridev object as a parameter
	large(ridev);
	// Overloaded input/output stream operators for handling input/output of large vehicle objects
	friend istream& operator>>(istream& in, large& obj);
	friend ostream& operator<<(ostream& out, large& obj);
};

// This class represents a transportation management system (TMS) that contains drivers, customers, and vehicles
class TMS {
public:
	driver* drive; // Pointer to an array of driver objects
	customer* custom; // Pointer to an array of customer objects
	vehicle* veh; // Pointer to an array of vehicle objects
	//Default constructor
	TMS();
	//destructor1
	~TMS();
};
class information {
public:
	int readservice;
	int servicecustomerid;
	information()
	{
		readservice = 0;
		servicecustomerid = 0;
	}
};