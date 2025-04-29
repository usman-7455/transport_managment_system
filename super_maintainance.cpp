#include"super_interface.h"
#include<string>
using namespace std;
//class name member functions
name::name() {}//default constructor
name::name(string first_name, string last_name) {
    f_name = first_name;
    l_name = last_name;
}//parametarized constructor
string name::get_f_name() { return f_name; }//returns first_name
string name::get_l_name() { return l_name; }//return last_name
void name::set_f_name(string first_name) { f_name = first_name; }//assignment to first_name
void name::set_l_name(string last_name) { l_name = last_name; }//assignment to last_name

//class date member functions
date::date() {}//default constructor
date::date(int dd, int mm, int yy) {
    day = dd;
    month = mm;
    year = yy;
}//parametarized constructor
//getter functions
int date::get_day() { return day; }//return day
int date::get_month() { return month; }//return month
int date::get_year() { return year; }//return year
//setter functions
void date::set_year(int yy) { year = yy; }//assignment to year
void date::set_month(int mm) { month = mm; }//assignment to month
void date::set_day(int dd) { day = dd; }//assignment to day

//class time member functions
m_time::m_time() {}//default constructor
m_time::m_time(int h, int m, int s) {
    hour = h;
    min = m;
    sec = s;
}//parametarized constructor
int m_time::get_hour() { return hour; }//return hour
int m_time::get_min() { return min; }//return minute
int m_time::get_sec() { return sec; }//return second
void m_time::set_hour(int h) { hour = h; }//assignment to hour
void m_time::set_min(int m) { min = m; }//assignment to minute
void m_time::set_sec(int s) { sec = s; }//assignment to second

//class service member functions

service::service() {}//default constructor
service::service(string sour, string dest, float dist, date bdate, m_time btime, bool stat, float fuelrat, int ciid, int diid, int viid) {

 source = sour;
 destination = dest;
 distance = dist;
 bookingdate = bdate;
 bookingtime = btime;
 status = stat;
 fuelrate = fuelrat;
 car_id = ciid;
 driver_id = diid;
 vehicle_id = viid;
}
// setter functions

void set_source(string source) {
    source = source;
}
void set_destination(string destination) {
    destination = destination;
}
void set_distance(float distance) {
    distance = distance;
}
void set_booking_date(int day, int month, int year) {
    day = day;
    month = month;
    year = year;
}
void set_booking_time(int hour, int minute, int second) {
    hour = hour;
    minute = minute;
    second = second;
}
void service::set_status_service(bool status) {
   this-> status = status;
}
void set_driver_id(int driver_id) {
    driver_id = driver_id;
}
void set_vehicle_id(int vehicle_id) {
    vehicle_id = vehicle_id;
}
void set_car_id(int car_id) {
    car_id = car_id;
}

// getter functions
string service::get_source() {
    return source;
}
string service::get_destination() {
    return destination;
}
float service::get_distance() {
    return distance;
}
date service::get_booking_date() {
    return bookingdate;
}
m_time service::get_time() {
    return bookingtime;
}
bool service::get_status() {
    return status;
}
int service::get_driver_id() {
    return driver_id;
}
int service::get_vehicle_id() {
    return vehicle_id;
}
int service::get_car_id() {
    return car_id;
}

//class ride member functions
ride::ride() {}
//parametarized constructor
ride::ride(service sr,int nop,string ridetype,float driverranking,float vehcileranking) {
    serviceride = sr;
    noofPassengers = nop;
    this->ridetype = ridetype;
    this->driverranking = driverranking;
    this->vehicleranking = vehicleranking;
}

//setter functions
void ride::set_noofpassengers(int num) { noofPassengers = num; }

void ride::set_ridetype(string type) { ridetype = type; }

void ride::set_driverranking(float ranking) { driverranking = ranking; }

void ride::set_vehicleranking(float ranking) { vehicleranking = ranking; }

//getter functions
int ride::get_noofpassengers() { return noofPassengers; }

string ride::get_ridetype() { return ridetype; }

float ride::get_driverranking() { return driverranking; }

float ride::get_vehicleranking() { return vehicleranking; }

//class delivery member functions
delivery::delivery() {}

delivery::delivery(service s, float gweight, string type) {
    sdelivery = s;
    goodweight = gweight;
    goodtype = type;
}

//setters getters
void delivery::set_goodweight(int weight) { goodweight = weight; }

void delivery::set_goodtype(string type) { goodtype = type; }

float delivery::get_goodweight() { return goodweight; }

service delivery::get_sdelivery() { return sdelivery; }

string delivery::get_goodtype() { return goodtype; }

//class person member functions
person::person() {}

person::person(name n, date d, int a, int id) {
    pname = n;
    dob = d;
    age = a;
    pid = id;
}

//setters getters
name person::get_pname() { return pname; }

date person::get_pdate() { return dob; }

int person::get_page() { return age; }

int person::get_pid() { return pid; }

void person::set_ppname(string first, string last) {
    pname.set_f_name(first);
    pname.set_l_name(last);
}

void person::set_pdate(int day, int month, int year) {
    
    dob.set_day(day);
    dob.set_month(month);
    dob.set_year(year);
    
}

void person::set_page(int a) {
    age = a;
}

void person::set_pid(int id) {
    pid = id;
}
static int c1 = 0;
static int c2 = 0;
//class customer member functions
customer::customer()
{
    servicesbooked = 0;
    //default constructor
}
customer::customer(person p,int id) {
    customi = p;
    cid = id;
    servicesbooked = 0;
}
void customer::set_servicesbooked(int a)
{
    servicesbooked = a;
}
int customer::getCId() const { return cid; }
void customer::setCId(int cid) { cid = cid; }
//class driver member functions
int driver::service_no = 1;
driver::driver(person per, int id, int nol, float rank, int exp, int st) {
    d = per;
    did = id;
    noofLicences = nol;
    overallranking = rank;
    experience = exp;
    status = st;
}

driver::driver() {}
void driver::initializer_service()
{
    serviceHistory = new service[service_no];
}
void driver::get_service(int a)
{
    harrypotter++;
    cin >> serviceHistory[a-1];
    //file handling
    ofstream outer;
    outer.open("servicesdriver.txt",ios::app);
   
    if (outer.is_open())
    {
        outer << serviceHistory[a - 1] << endl;
        outer.close();
    }
}

void driver::assign_licenselist()
{
    licencelist = new char [noofLicences];
}
int driver::getdid() const { return did; }

int driver::getNoOfLicences() const { return noofLicences; }

float driver::getOverallRanking() const { return overallranking; }

float driver::getSalary() const { return salary; }

int driver::getExperience() const { return experience; }

int driver::getStatus() const { return status; }


void driver::set_id(int id) { did = id; }

void driver::set_overallranking(float rank) { overallranking = rank; }

void driver::set_salary(float sal) { salary = sal; }

void driver::set_experience(int exp) { experience = exp; }

void driver::set_Status(int st) { status = st; }

driver::~driver() {}

//class feature member functions
feature::feature() {}
feature::feature(string desc, float c) {
    description = desc;
    cost = c;
}

//getter setters
float feature::get_cost() { return cost; }
string feature::get_description() { return description; }
void feature::set_cost(float c) { cost = c; }
void feature::set_description(string desc) { description = desc; }

//class vehicle member functions
vehicle::vehicle(int id, int regno, float avgmil, string l_type, string fuel_ty, float rank, date md,service obj) {
    vid = id;
    registrationno = regno;
    avgMileage = avgmil;
    LicenceType = l_type;
    fueltype = fuel_ty;
    overallranking = rank;
    manufacturingDate = md;


}
vehicle::vehicle() {}
void vehicle::assign_feature(int no_of_features){
    list = new feature[no_of_features];
}

//setters getters
int vehicle::get_vid() { return vid; }
int vehicle::get_registrationno() { return registrationno; }
float vehicle::get_avg_milage() { return avgMileage; }
string vehicle::get_license_type() { return LicenceType; }
bool vehicle::get_status() { return status; }
string vehicle::get_fueltype() { return fueltype; }
float vehicle::get_overallranking() { return overallranking; }
date vehicle::get_manufacturingdate() { return manufacturingDate; }
feature vehicle::get_list() { return *list; }

void vehicle::set_vid(int id) { vid = id; }
void vehicle::set_registrationno(int num) { registrationno = num; }
void vehicle::set_avg_milage(float milage) { avgMileage = milage; }
void vehicle::set_license_type(string ltype) { LicenceType = ltype; }
void vehicle::set_status(bool stat) { status = stat; }
void vehicle::set_fueltype(string ftype) { fueltype = ftype; }
void vehicle::set_overallranking(float rank) { overallranking = rank; }
void vehicle::set_manufacturingdate(int dd, int mm, int yy) {
    manufacturingDate.set_day(dd);
    manufacturingDate.set_month(mm);
    manufacturingDate.set_year(yy);
}
void vehicle::set_list(string description, float cost) {
    
}
vehicle::~vehicle() {};
//class transportation_vehicle member functions
transportation::transportation() {}
transportation::transportation(vehicle v, string nam, float weight) {
    vh = v;
    name = nam;
    max_weight = weight;
}
string transportation::get_name() { return name; }
float transportation::get_max_weight() { return max_weight; }
void transportation::set_name(string nam) { name = nam; }
void transportation::set_max_weight(float weight) { max_weight = weight; }
//class ride_vehicles member functions
ridev::ridev(vehicle v, string nam, int seats=0) {
    vh = v;
    name = nam;
    this->seats = seats;
}
ridev::ridev() {}
void ridev::set_seats(int s) { seats = s; }
void ridev::set_name(std::string n) { name = n; }
int ridev::get_seats() { return seats; }
string ridev::get_name() { return name; }
//class common vehicle member finctions
common_vehicle::common_vehicle(ridev rv, transportation tv)
{
    this->rv = rv;
    this->tv = tv;
}
//class small member funtions
smallv::smallv(){}
smallv::smallv(ridev rv)
{
    this->rv = rv;
}
//class large member functions
large::large(){}
large::large(ridev rv)
{
    this->rv = rv;
}
//class light member functions
light::light(){}
light::light(transportation t)
{
    t1 = t;
}
//class heavy member functions
heavy::heavy(){}
heavy::heavy(transportation t)
{
    t2 = t;
}
//class tms member functions
TMS::TMS()
{
    custom = new customer[15];
    drive = new driver[10];
    veh = new vehicle[15];
}
TMS::~TMS()
{
    delete[]custom;
    delete[]drive;
    delete[]veh;
    custom = NULL;
    drive = NULL;
    veh = NULL;
}
int service::get_serviceid()
{
    return serviceid;
}
int service::get_customerbooked()
{
    return customerbooked;
}
void service::set_serviceid(int a)
{
    serviceid = a;
}
void service::set_customerbooked(int a)
{
    customerbooked = a;
}
void customer::servicesbookedincrease()
{
    servicesbooked++;
}
int customer::get_servicesbooked()
{
    return  servicesbooked;
}
void customer::allocatebooking()
{
    bookinghistory = new service[servicesbooked];
    if (servicesbooked > 1)
    {
        service* ptr = new service[servicesbooked];
        for (int i = 0; i < servicesbooked - 1; i++)
        ptr[i] = bookinghistory[i];
        bookinghistory = ptr;
    }
}
void customer::set_entity(service& obj)
{
    bookinghistory[servicesbooked - 1] = obj;
}

void customer::get_booking_history(int i,TMS&management)
{
    for (int j = 0; j < management.custom[i].get_servicesbooked(); j++)
    {
        cout << management.custom[i].bookinghistory[j] << endl;
    }
}
void name::display_name() {
    cout << "The name of person is :" << f_name << " " << l_name<< endl;
}
void date::display_date() {
    cout << "The Date in day/month/year is : " << day << "/" << month << "/" << year<< endl;
}
void m_time::display_time() {
    cout << "Time in hours:minutes:seconds is : " << hour << ":" << min << ":" << sec<< endl;
}
void service::display_service() {
    cout << "Service Details:" << endl;
    cout << "Source: " << source << endl;
    cout << "Destination: " << destination << endl;
    cout << "Distance: " << distance << endl;
    cout << "Booking Date is : " << endl;
    bookingdate.display_date();
    cout << "Booking Time is : " << endl;
    bookingtime.display_time();
    cout << "Status: " << (status ? "Active" : "Inactive") << endl;
    cout << "Fuel Rate: " << fuelrate << endl;
    cout << "Car ID: " << car_id << endl;
    cout << "Driver ID: " << driver_id << endl;
    cout << "Vehicle ID: " << vehicle_id<< endl;
}
void ride::display_ride() {
    cout << "\tRide Details" << endl;
    cout << "Number of Passengers: " << noofPassengers << endl;
    cout << "Ride Type: " << ridetype << endl;
    cout << "Driver Ranking: " << driverranking << endl;
    cout << "Vehicle Ranking: " << vehicleranking << endl;
    cout << "Service Details:" << endl;
    serviceride.display_service();
}
void delivery::display_delivery() {
    cout << "Delivery Details:" << endl;
    cout << "Good Weight: " << goodweight << " kg" << endl;
    cout << "Good Type: " << goodtype << endl;
    cout << "Service Details:" << endl;
    sdelivery.display_service();
}
void person::display_person() {
    cout << "Person Details:" << endl;
    cout << "ID: " << pid << endl;
    cout << "Name: " << endl;
    pname.display_name();
    cout << "Date of Birth: " << endl;
    dob.display_date();
    cout << "Age: " << age<< endl;
}
void customer::display_customer() {
    cout << "Customer Details:" << endl;
    cout << "ID: " << cid << endl;
    cout << "Person Details:" << endl;
    customi.display_person();
}
void driver::display_driver() {
    cout << "Driver Details:" << endl;
    cout << "ID: " << did << endl;
    cout << "Person Details:" << endl;
    d.display_person();
    cout << "No. of Licences: " << noofLicences << endl;
    cout << "Overall Ranking: " << overallranking << endl;
    cout << "Salary: " << salary << endl;
    cout << "Experience: " << experience << " years" << endl;
    cout << "Status: " << status<< endl;
}
void feature::display_feature() {
    cout << "Feature Details:" << endl;
    cout << "Description: " << description << endl;
    cout << "Cost: " << cost<< endl;
}
void vehicle::display_vehicle() {
    cout << "Vehicle Details:" << endl;
    cout << "Vehicle ID: " << vid << endl;
    cout << "Registration Number: " << registrationno << endl;
    cout << "Average Mileage: " << avgMileage << endl;
    cout << "License Type: " << LicenceType << endl;
    cout << "Fuel Type: " << fueltype << endl;
    cout << "Overall Ranking: " << overallranking << endl;
    cout << "Manufacturing Date: " << endl;
    manufacturingDate.display_date();
    // Display the features of the vehicle using the list member variable
}
void transportation::display_transportation() {
    cout << "Transportation Details:" << endl;
    cout << "Name: " << name << endl;
    cout << "Max Weight: " << max_weight << endl;
    // Display the details of the associated vehicle using the vh member variable
    vh.display_vehicle();
}