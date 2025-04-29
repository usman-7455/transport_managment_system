#pragma once
#include"super_interface.h"
#include<string>
//class name insertion and exertion
istream& operator>>(istream& in, name& obj) { 
	cout << "Enter first name\n";
	in >> obj.f_name;
	cout << "Enter last name\n";
	in >> obj.l_name;
	return in;
}
ostream& operator<<(ostream& out, name& obj) {
	out <<obj.f_name<<" " << obj.l_name ;
	return out;
}
//class date insertion and exertion
istream& operator>>(istream& in, date& obj) {
	cout << "Enter date\n";
	cout << "Enter day\n";
	in >> obj.day;
	cout << "Enter month no\n";
	in >> obj.month;
	cout << "Enter year\n";
	in >> obj.year;
	return in;
}
ostream& operator<<(ostream& out, date& obj) {
	out << " " << obj.day << " " << obj.month << " " << obj.year ;
	return out;
}
//class m_time insertion and exertion
istream& operator>>(istream& in,  m_time& obj) {
	cout << "Enter hour in 12 hour format\n";
	in >> obj.hour;
	cout << "Enter minutes in range of 1 to 60\n";
	in >> obj.min;
	cout << "Enter seconds in range of 1 to 60\n";
	in >> obj.sec;
	return in;
}
ostream& operator<<(ostream& out, m_time& obj) {
	out << " " << obj.hour << "  " << obj.min << "  " << obj.sec ;
	return out;
}
//class service insertion and exertion
istream& operator>>(istream& in, service& obj) {
	cout << "ENter service id\n";
	in >> obj.serviceid;
	cout << "Enter source\n";
	in >> obj.source;
	cout << "Enter destination\n";
	in >> obj.destination;
	cout << "ENter distance\n";
	in >> obj.distance;
	cout << "Enter booking date\n";
	in >> obj.bookingdate;
	cout << "ENter booking time\n";
	in >> obj.bookingtime;
	obj.status = 0;
	cout << "Enter fuel rate\n";
	in >> obj.fuelrate;
	cout << "Enter car_id\n";
	in >> obj.car_id;
	cout << "Enter driver_id\n";
	in >> obj.driver_id;
	cout << "Enter vehicle id same as car id\n";
	in >> obj.vehicle_id;
	obj.customerbooked = 0;
	return in;
}
ostream& operator<<(ostream& out,  service& obj) { 
	out << obj.serviceid << " ";
	out  << obj.source << " ";
	out << obj.destination << " ";
	out << obj.distance << " ";
	out << obj.bookingdate << " ";
	out << obj.bookingtime <<" ";
	out << obj.status << " ";
	out << obj.fuelrate << " ";
	out << obj.car_id << " ";
	out << obj.driver_id << " ";
	out << obj.vehicle_id << " ";
	out << obj.customerbooked << " ";
	return out;
}
//class vehicles insertion and exertion
istream& operator>>(istream& in, vehicle& obj)
{
	cout << "Enter vehicle id\n";
	in >> obj.vid;
	cout << "Enter registration number\n";
	in >> obj.registrationno;
	cout << "ENter average milage\n";
	in >> obj.avgMileage;
	cout << "Enter license type\n";
	in >> obj.LicenceType;
	cout << "ENter status 1 for available 0 for not available\n";
	in >> obj.status;
	cout << "Enter fueltype(diesel or petrol)*DON'T GIVE SPACES OR YOU WILL DIE*\n";
	in >> obj.fueltype;
	cout << "Enter overall ranking(1 to 5)\n";
	in >> obj.overallranking;
	cout << "ENter manufacturing date\n";
	in >> obj.manufacturingDate;
	return in;
}
ostream& operator<<(ostream& out, vehicle& obj)
{
	out << "The vehicle id is " << obj.vid << endl;
	out << "The registration number is " << obj.registrationno << endl;
	out << "The average mileage is " << obj.avgMileage << endl;
	out << "The license type is " << obj.LicenceType << endl;
	out << "The availability status is 1 for yes 0 for no " << obj.status << endl;
	out << "The fuel type is " << obj.fueltype << endl;
	out << "The overall ranking of this vehicle is " << obj.overallranking << endl;
	out << "The manufacturing date is " << obj.manufacturingDate << endl;
	return out;
}

//class rdiev insertion and exertion
istream& operator>>(istream& in, ride& obj) {
	cout << "ENter service ride\n";
	in >> obj.serviceride;
	cout << "Enter number of passenegers\n";
	in >> obj.noofPassengers;
	cout << "ENter ride type\n";
	in >> obj.ridetype;
	cout << "ENter driver_ranking\n";
	in >> obj.driverranking;
	cout << "ENter vehicle ranking\n";
	in >> obj.vehicleranking;
	return in;
}
ostream& operator<<(ostream& out, ride& obj) {
	out << "The service details are as follows\n";
	out << obj.serviceride;
	out << "The number of passengers are\n";
	out << obj.noofPassengers;
	out << "The ride type is \n";
	out << obj.ridetype;
	out << "The driver ranking is \n";
	out << obj.driverranking;
	out << "The vehicle ranking is \n";
	out << obj.vehicleranking;
	return out;
}
//class delivery insertion and exertion
istream& operator>>(istream& in, delivery& obj) {
	cout << "\tEnter delivery service\n";
	in >> obj.sdelivery;
	cout << "\tENter the weight of goods\n";
	in >> obj.goodweight;
	cout << "\tENter the good type(DON'T give spaces or you will die)\n";
	in >> obj.goodtype;
	return in;
}
ostream& operator<<(ostream& out, delivery& obj) { 
	out << "The delivery service is ::\n";
	out << "\t" << obj.sdelivery;
	out << "The weight of goods is \n\t" << obj.goodweight << endl;
	out << "The good type is \n\t" << obj.goodtype << endl;
	return out;
}
// //class person insertion and exertion
istream& operator>>(istream& in, person& obj) { 
	cout << "ENter name\n";
	in >> obj.pname;
	cout << "Enter date of birth\n";
	in >> obj.dob;
	cout << "Enter age\n";
	in >> obj.age;
	cout << "Enter person ID\n";
	in >> obj.pid;
	return in;
}
ostream& operator<<(ostream& out, person& obj) {//cout<<customer 
	out  << obj.pid << " ";
	out << obj.pname<<" ";
	out << obj.dob<<" ";
	out <<obj.age << " ";
	
	return out;
}
//class customer insertion and exertion
istream& operator>>(istream& in, customer& obj) {//cin>>customer
	cout << "ENter details of customer\n";
	in >> obj.customi;
	cout << "Enter customer id(same as person id)\n";
	in >> obj.cid;
	return in;
}
ostream& operator<<(ostream& out, customer& obj) {
	out <<obj.customi;
	out  << obj.cid ;
	return out;
}
//class driver insertion and exertion
istream& operator>>(istream& in, driver& obj) { 
	cout << "ENter details of driver\n";
	in >> obj.d;
	cout << "ENter driver id \n";
	in >> obj.did;
	cout << "ENter no_of_licenses\n";
	in >> obj.noofLicences;
	cout << "ENter overall ranking\n";
	in >> obj.overallranking;
	cout << "ENter salary\n";
	in >> obj.salary;
	cout << "ENter experice in years\n";
	in >> obj.experience;
	cout << "status of driver 1)free 2)not free 3)cancelled(enter the numbers carefully or you will die)\n";
	in >> obj.status;
	return in;
}
ostream& operator<<(ostream& out, driver& obj) { 
	out << obj.d << " ";
	out << obj.did << " ";
	out  << obj.noofLicences << " ";
	out << obj.salary << " ";
	out  << obj.experience << " ";
	out << obj.status << " ";
	return out;

}
//class feature insertion and exertion
istream& operator>>(istream& in, feature& obj) {
	cout << "Enter the ID of feature\n";
	in >> obj.fid;
	cout << "Enter description of feature\n";
	getline(in, obj.description);
	cout << "ENter cost of the feature\n";
	cin >> obj.cost;
	return in;
}
ostream& operator<<(ostream& out, feature& obj) {
	out  << obj.fid << endl;
	out  << obj.description << endl;
	out << obj.cost << endl;
	return out;
}
//class transportation insertion and exertion
istream& operator>>(istream& in, transportation& obj) {
	cout << "Enter vehicle details\n";
	in >> obj.vh;
	cout << "ENter name of vehicle \n";
	in >> obj.name;
	cout << "ENter max weight the vehicle can handle\n";
	in >> obj.max_weight;
	return in;
}
ostream& operator<<(ostream& out, transportation& obj) {
	out << obj.vh;
	out << obj.name;
	out << obj.max_weight;
	return out;
}
//class light_vehicle insertion and exertion
istream& operator>>(istream& in, light& obj) { 
	cout << "Enter the details of vehicle\n";
	in >> obj.t1;
	return in;
}
ostream& operator<<(ostream& out, light& obj) {
	out << obj.t1;
	return out;
}
//class heay_vehicle insertion and exertion
istream& operator>>(istream& in, heavy& obj) { 
	cout << "Enter vehicle details\n";
	in >> obj.t2;
	int dummy_max_weight = 0; bool var = true;
	while (var)
	{
		try
		{
			if (obj.t2.get_max_weight() > 1000)
				throw "exception";
		}
		catch (string s)
		{
			cout << "Enter again(I told you are you stupid?)\n";
			in >> dummy_max_weight;
			if (dummy_max_weight < 1000)
				var = false;
		}
	}
	return in;
}
ostream& operator<<(ostream& out, heavy& obj) { 
	out << "The vehicle details of heavy vehicles are\n";
	out << obj.t2;
	return out;
}
//class ride_vehicle insertion and exertion
istream& operator>>(istream& in, ridev& obj) {
	cout << "Enter vehicle information\n";
	in >> obj.vh;
	cout << "ENter name of vehicle\n";
	in >> obj.name;
	cout << "ENter no of seats\n";
	in >> obj.seats;
	return in;
}
ostream& operator<<(ostream& out, ridev& obj) {
	out  << obj.name << endl;
	out  << obj.vh << endl;
	out  << obj.seats << endl;
	return out;
}
//class common_vehicle insertion and exertion
istream& operator>>(istream& in, common_vehicle& obj) {
	cout << "ENter vehicle details\n";
	in >> obj.rv;
	cout << "Enter details as a transport vehicle\n";
	in >> obj.tv;
	return in;
}
ostream& operator<<(ostream& out, common_vehicle& obj) {
	out << obj.rv;
	out << obj.get_max_weight();
	return out;
}
//class small_vehicle insertion and exertion
istream& operator>>(istream& in, smallv& obj) {
	cout << "ENter details of the vehicle\n";
	in >> obj.rv;
	return in;
}
ostream& operator<<(ostream& out, smallv& obj) { 
	
	out << obj.rv;
	return out;

}
//class large_vehicle insertion and exertion
istream& operator>>(istream& in, large& obj) {
	cout << "ENter details of the vehicle\n";
	in >> obj.rv;
	return in;
}
ostream& operator<<(ostream& out, large& obj) {
	
	out << obj.rv;
	return out;
}