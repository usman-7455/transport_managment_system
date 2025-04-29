#pragma once
#include	"super_interface.h"
#include	"friends.h"
using namespace std;
int adminp = 0;

void selection() {//main menu for selecting and display
	std::cout << "\t\t\t\tWELCOME TO TRANSPORT MANAGEMENT SYSTEM\n";
	std::cout << "\t\t\t\t***************************************\n\n";
	cout << "\t\t\t\t1)Add a customer\n";
	cout << "\t\t\t\t2)Add a driver\n";
	cout << "\t\t\t\t3)print list of all customers\n";
	cout << "\t\t\t\t4)print list of all drivers\n";
	cout << "\t\t\t\t5)Add a vehicle\n";
	cout << "\t\t\t\t6)print all vehicles\n";
	cout << "\t\t\t\t7)remove a customer\n";
	cout << "\t\t\t\t8)remove a driver\n";
	cout << "\t\t\t\t9)remove a vehicle\n";
	cout << "\t\t\t\t10)add a service to a driver\n";
	cout << "\t\t\t\t11)print all drivers above 4.5 rating\n";
	cout << "\t\t\t\t12)print all services\n";
	cout << "\t\t\t\t13)book a service\n";
	cout << "\t\t\t\t14)All booked services\n";
	cout << "\t\t\t\t15)Exit program\n";
}
void termination()//termination to out of scope
{
	cout << "NO MORE CAPACITY\n";
	exit(0);
}

int get_featureno()
{
	int dummynumberoffeatures;
	cout << "Enter no of features a vehicle have\n";
	cin >> dummynumberoffeatures;
	return dummynumberoffeatures;
}
int customeru = 0;//static variable to keep count of customers added
extern int driveru = 0;//static variable to keep count of drivers added
int vehicleu = 0;//static variable to keep count of vehicle added
int invasion = 0;
void store_static()//storing the values of variables that can be used as static
{
	ofstream out;
	ifstream in;
	out.open("static.txt", ios::out);
	if (out.is_open())
	{
		out << customeru << " ";
		out << driveru << " ";
		out << vehicleu << " ";
		out << invasion << " ";
		out << harrypotter << " ";
		out << spiderman<<" ";
		out << adminp << " ";
		out.close();
	}
}
void get_static()//getting the values of variables as static
{
	int a = 0, i = 0;
	ofstream out;
	ifstream in;
	in.open("static.txt", ios::in);
	if (in.is_open())
	{
		while (!in.eof())
		{
			in >> customeru;
			in >> driveru;
			in >> vehicleu;
			in >> invasion;
			in >> harrypotter;
			in >> spiderman;
			in >> adminp;
		}
		in.close();
	}

}
void paste_bookinghistory(TMS& management)
{
	ofstream out;
	out.open("bookinghistory.txt", ios::app);
	if (out.is_open())
	{
		for (int i = 0; i < customeru; i++)
		{

			for (int j = 0; j < management.custom[i].get_servicesbooked(); j++)
			{
				out << management.custom[i].bookinghistory[j];
				out << endl;
			}
			out.close();
		}

	}
}
void writedata(TMS& management)
{
	//to store all data of customer in a text file
	ofstream out;
	out.open("customers.txt", ios::out);
	cout << customeru;
	if (out.is_open())
	{
		for (int i = 0; i < customeru; i++)
			out << management.custom[i] << endl;
		out.close();
	}
	//to store all data of driver in a text file
	ofstream outi;
	outi.open("drivers.txt", ios::out);
	if (outi.is_open())
	{
		for (int i = 0; i < driveru; i++)
			outi << management.drive[i] << endl;
		outi.close();
	}
	//to store data of vehicles in a text file
	ofstream outu;
	outu.open("vehicles.txt", ios::out);
	if (outu.is_open())
	{
		for (int i = 0; i < vehicleu; i++)
			outu << management.veh[i] << endl;
		outu.close();
	}
	paste_bookinghistory(management);//store the booking history of a customer
}
void assign_data(TMS& management)//bimaar function
{
	//to get data from a file of driver
	ifstream in;
	in.open("customers.txt", ios::in);
	if (in.is_open())
	{
		for (int i = 0; i < customeru; i++) {
			in >> management.custom[i].customi.pid;
			in >> management.custom[i].customi.pname.f_name;
			in >> management.custom[i].customi.pname.l_name;
			in >> management.custom[i].customi.dob.day;
			in >> management.custom[i].customi.dob.month;
			in >> management.custom[i].customi.dob.year;
			in >> management.custom[i].customi.age;
			in >> management.custom[i].cid;
		}

		in.close();
	}
	//to get data from a text file of drivers
	ifstream din;
	din.open("drivers.txt", ios::in);
	if (din.is_open())
	{
		for (int i = 0; i < driveru; i++) {
			din >> management.drive[i].d.pid;
			din >> management.drive[i].d.pname.f_name;
			din >> management.drive[i].d.pname.l_name;
			din >> management.drive[i].d.dob.day;
			din >> management.drive[i].d.dob.month;
			din >> management.drive[i].d.dob.year;
			din >> management.drive[i].d.age;
			din >> management.drive[i].did;
			din >> management.drive[i].noofLicences;
			din >> management.drive[i].salary;
			din >> management.drive[i].experience;
			din >> management.drive[i].status;
		}

		din.close();
	}
	//to get the data of vehicles from a file
	ifstream  vin;
	vin.open("vehicles.txt", ios::in);
	if (vin.is_open())
	{
		for (int i = 0; i < vehicleu; i++) {
			vin >> management.veh[i].vid;
			vin >> management.veh[i].registrationno;
			vin >> management.veh[i].avgMileage;
			vin >> management.veh[i].LicenceType;
			vin >> management.veh[i].status;
			vin >> management.veh[i].fueltype;
			vin >> management.veh[i].overallranking;
			vin >> management.veh[i].manufacturingDate.day;
			vin >> management.veh[i].manufacturingDate.month;
			vin >> management.veh[i].manufacturingDate.year;
		}

		vin.close();
	}

}
void store_service_driver(TMS& management)//1010
{
	ofstream out;
	out.open("servicesdriver.txt", ios::out);//1010

	if (out.is_open())
	{
		for (int i = 0; i < driveru; i++)
		{
			for (int j = 0; j < management.drive[i].service_no; j++)
			{
				out << management.drive[i].serviceHistory[j];
				out << endl;
			}

		}
		out.close();
	}


}
void increase_service(TMS& management, int drivernumber) {//to increase the array size of service

	management.drive[drivernumber].service_no++;
	service* dumb = new service[management.drive[drivernumber].service_no];
	for (int j = 0; j < management.drive[drivernumber].service_no - 1; j++) {
		dumb[j] = management.drive[drivernumber].serviceHistory[j];
	}
	delete[]management.drive[drivernumber].serviceHistory;
	management.drive[drivernumber].serviceHistory = dumb;
	dumb = NULL;
}
void printmore4(TMS& management)
{
	int s;
	int dummyrating;
	cout << "ENter the rating you want drivers of\n";
	cin >> dummyrating;
	cout << "1)above than given rating\n";
	cout << "2)Less than given rating\n";
	cout << "3)Equal to this rating\n";
	cin >> s;
	if (s == 1) {//greater than given
		for (int i = 0; i < driveru; i++)
		{
			if (management.drive[i].getOverallRanking() > dummyrating)
				management.drive[i].display_driver();
		}
	}
	if (s == 2) {//less than given
		for (int i = 0; i < driveru; i++)
		{
			if (management.drive[i].getOverallRanking() < dummyrating)
				management.drive[i].display_driver();
		}
	}
	if (s == 3) {//equal to given
		for (int i = 0; i < driveru; i++)
		{
			if (management.drive[i].getOverallRanking() == dummyrating)
				management.drive[i].display_driver();
		}
	}
}

service* invoker(TMS& management, service allservices[])
{
	service* ptr = new service[harrypotter];
	ifstream in;
	in.open("servicesdriver.txt", ios::in);
	if (in.is_open())
	{
		int saviour;
		for (int i = 0; i < harrypotter; i++)
		{
			in >> ptr[i].serviceid;
			in >> ptr[i].source;
			in >> ptr[i].destination;
			in >> ptr[i].distance;
			in >> saviour;
			ptr[i].bookingdate.set_day(saviour);
			in >> saviour;
			ptr[i].bookingdate.set_month(saviour);
			in >> saviour;
			ptr[i].bookingdate.set_year(saviour);
			in >> saviour;
			ptr[i].bookingtime.set_hour(saviour);
			in >> saviour;
			ptr[i].bookingtime.set_min(saviour);
			in >> saviour;
			ptr[i].bookingtime.set_sec(saviour);
			in >> ptr[i].status;
			in >> ptr[i].fuelrate;
			in >> ptr[i].car_id;
			in >> ptr[i].driver_id;
			in >> ptr[i].vehicle_id;
			in >> ptr[i].customerbooked;
		}
	}
	for (int i = 0; i < harrypotter; i++)
	{
		allservices[i] = ptr[i];
	}
	return ptr;
}
//service* get_bookinghistoryfrom(TMS& management, service* booking)
//{
//	service* ptr = new service[harrypotter];
//	ifstream in;
//	in.open("bookinghistory.txt", ios::in);
//	if (in.is_open())
//	{
//		int saviour;
//		for (int i = 0; i < spiderman; i++)
//		{
//			in >> ptr[i].serviceid;
//			in >> ptr[i].source;
//			in >> ptr[i].destination;
//			in >> ptr[i].distance;
//			in >> saviour;
//			ptr[i].bookingdate.set_day(saviour);
//			in >> saviour;
//			ptr[i].bookingdate.set_month(saviour);
//			in >> saviour;
//			ptr[i].bookingdate.set_year(saviour);
//			in >> saviour;
//			ptr[i].bookingtime.set_hour(saviour);
//			in >> saviour;
//			ptr[i].bookingtime.set_min(saviour);
//			in >> saviour;
//			ptr[i].bookingtime.set_sec(saviour);
//			in >> ptr[i].status;
//			in >> ptr[i].fuelrate;
//			in >> ptr[i].car_id;
//			in >> ptr[i].driver_id;
//			in >> ptr[i].vehicle_id;
//			in >> ptr[i].customerbooked;
//		}
//	}
//	for (int i = 0; i < harrypotter; i++)
//	{
//		booking[i] = ptr[i];
//	}
//	return ptr;
//}
void adminblock(TMS&management,service*allservices,service*booking)
{
	
		int selection1;
		selection();//function that displays the menu
		std::cout << "Enter your selection \n";
		cin >> selection1;
		if (selection1 == 14)//booking history of all customers
		{
			for (int i = 0; i < customeru; i++)
			{
				std::cout << booking[i] << endl;
			}
		}
		if (selection1 == 13)//book a service
		{
			std::cout << management.custom[0].get_servicesbooked();
			bool khatam = true;
			int id;
			std::cout << "Enter the id of service you want to book\n";
			cin >> id;
			for (int i = 0; i < harrypotter && khatam; i++)
			{
				if (allservices[i].get_serviceid() == id)
				{
					if (allservices[i].get_status() == true)
					{
						std::cout << "\tSorry for the inconvenience\nthis service is taken shortly you have to check this \nin few days to avail that\n";
						khatam = false;
					}
					else {
						std::cout << "Enter your customer id\n";
						cin >> id;
						allservices[i].set_customerbooked(id);
						allservices[i].set_status_service(true);
						for (int k = 0; k < customeru; k++)
						{
							if (management.custom[k].getCId() == id)
							{
								management.custom[k].servicesbookedincrease();
								management.custom[k].allocatebooking();
								management.custom[k].set_entity(allservices[i]);
								break;
							}
						}
					}
				}
			}
			spiderman++;
		}

		if (selection1 == 12)//print all services
		{

			for (int i = 0; i < harrypotter; i++)
				allservices[i].display_service();
			std::cout << endl;
		}
		if (selection1 == 11)
		{
			printmore4(management);
		}
		if (selection1 == 10)//add a service to respective driver
		{
			harrypotter++;
			invasion++;
			std::cout << "invasion" << invasion << endl;

			int dummyid;
			std::cout << "Enter the id of driver you want to add a service\n";
			cin >> dummyid;
			for (int i = 0; i < driveru; i++)
			{
				if (management.drive[i].getdid() == dummyid)
				{
					dummyid = i;
					break;
				}
			}
			std::cout << management.drive[dummyid].service_no << endl;
			std::cout << "ENter the service\n";
			management.drive[dummyid].initializer_service();
			if (invasion > 1)
				increase_service(management, dummyid);
			management.drive[dummyid].get_service(management.drive[dummyid].service_no);
			std::cout << harrypotter << "harry" << endl;
		}
		if (selection1 == 1)//adds a customer
		{
			std::cout << "selected to add a new customer\n";
			std::cout << "Enter details of a customer\n";
			cin >> management.custom[customeru];

			customeru++;
			if (customeru > 14)
				termination();
		}
		else if (selection1 == 2)//adds a new driver;
		{
			std::cout << "selected to add a new driver\n";
			std::cout << "Enter details of the driver\n";
			cin >> management.drive[driveru];
			if (driveru > 9)
				termination();
			driveru++;
		}
		else if (selection1 == 3)//to print list of all customers
		{
			for (int i = 0; i < customeru; i++)
			{
				management.custom[i].display_customer();
			}
		}
		else if (selection1 == 4)//print list of all drivers
		{
			for (int i = 0; i < driveru; i++)
			{
				management.drive[i].display_driver();
			}
		}
		else if (selection1 == 5)//add a vehicle
		{
			int a = get_featureno();
			std::cout << "selected to add a new vehicle\n";
			std::cout << "Enter details of the vehicle\n";
			cin >> management.veh[vehicleu];
			std::cout << "Enter feature list of vehicle\n";
			management.veh[vehicleu].assign_feature(a);
			for (int i = 0; i < a; i++)
				cin >> management.veh[vehicleu].list[i];
			if (customeru > 14)
				termination();
			vehicleu++;
		}
		else if (selection1 == 6)//out all vehicles
		{
			for (int i = 0; i < vehicleu; i++)
			{
				management.veh[i].display_vehicle();
			}
		}
		//remove a customer
		else if (selection1 == 7)//remove a customer
		{
			int removalid = 0;
			std::cout << "Enter the customer id of driver you want to remove\n";
			cin >> removalid;
			for (int i = 0; i < customeru; i++)
			{
				if (management.custom[i].getCId() == removalid)
				{
					for (int j = 0; j < customeru - i; j++)
					{
						management.custom[i + j] = management.custom[i + j + 1];
						if (i + j + 1 == customeru - 1)
							break;
					}
				}

			}
			customeru--;
		}
		//remove a driver
		else if (selection1 == 8)//remove a driver
		{
			int removalid = 0;
			std::cout << "Enter the driver id of driver you want to remove\n";
			cin >> removalid;//ID of driver which has to be removed
			for (int i = 0; i < driveru; i++)
			{
				if (management.drive[i].getdid() == removalid)
				{
					for (int j = 0; j < driveru - i; j++)
					{
						management.drive[i + j] = management.drive[i + j + 1];
						if (i + j + 1 == driveru - 1)//check for out of bound
							break;
					}
				}

			}
			driveru--;
		}
		//remove a vehicle
		else if (selection1 == 9)//remove a vehicle
		{
			int removalid = 0;
			std::cout << "Enter the vehicle id of vehicle you want to remove\n";
			cin >> removalid;
			for (int i = 0; i < vehicleu; i++)
			{
				if (management.veh[i].get_vid() == removalid)
				{
					for (int j = 0; j < vehicleu - i; j++)
					{
						management.veh[i + j] = management.veh[i + j + 1];
						if (i + j + 1 == vehicleu - 1)//check
							break;
					}
				}

			}
			vehicleu--;
		}
	

}
void customerblock(TMS& management, service* allservices, service* booking)
{
	int selection1;
	cout << "\t\t\t\t3)print list of all customers\n";
	cout << "\t\t\t\t4)print list of all drivers\n";
	cout << "\t\t\t\t11)print all drivers above 4.5 rating\n";
	cout << "\t\t\t\t12)print all services\n";
	cout << "\t\t\t\t13)book a service\n";
	cout << "\t\t\t\t14)All booked services\n";
	cout << "\t\t\t\t6)print all vehicles\n";
	cout << "Enter your selection\n";
	cin >> selection1;
	if (selection1 == 3)//to print list of all customers
	{
		for (int i = 0; i < customeru; i++)
		{
			management.custom[i].display_customer();
		}
		}
	else if (selection1 == 4)//print list of all drivers
	{
		for (int i = 0; i < driveru; i++)
		{
			management.drive[i].display_driver();
		}
	}
	if (selection1 == 14)//booking history of all customers
	{
		for (int i = 0; i < customeru; i++)
		{
			std::cout << booking[i] << endl;
		}
	}
	if (selection1 == 13)//book a service
	{
		std::cout << management.custom[0].get_servicesbooked();
		bool khatam = true;
		int id;
		std::cout << "Enter the id of service you want to book\n";
		cin >> id;
		for (int i = 0; i < harrypotter && khatam; i++)
		{
			if (allservices[i].get_serviceid() == id)
			{
				if (allservices[i].get_status() == true)
				{
					std::cout << "\tSorry for the inconvenience\nthis service is taken shortly you have to check this \nin few days to avail that\n";
					khatam = false;
				}
				else {
					std::cout << "Enter your customer id\n";
					cin >> id;
					allservices[i].set_customerbooked(id);
					allservices[i].set_status_service(true);
					for (int k = 0; k < customeru; k++)
					{
						if (management.custom[k].getCId() == id)
						{
							management.custom[k].servicesbookedincrease();
							management.custom[k].allocatebooking();
							management.custom[k].set_entity(allservices[i]);
							break;
						}
					}
				}
			}
		}
		spiderman++;
	}

	if (selection1 == 12)//print all services
	{

		for (int i = 0; i < harrypotter; i++)
			allservices[i].display_service();
		std::cout << endl;
	}
	if (selection1 == 11)
	{
		printmore4(management);
	}
	else if (selection1 == 6)//out all vehicles
	{
		for (int i = 0; i < vehicleu; i++)
		{
			management.veh[i].display_vehicle();
		}
	}
}
void driverblock(TMS& management, service* allservices, service* booking)
{
	int selection1;
	cout << "\t\t\t\t10)add a service to a driver\n";
	cout << "\t\t\t\t11)print all drivers above 4.5 rating\n";
	cout << "\t\t\t\t12)print all services\n";
	cout << "\t\t\t\t5)Add a vehicle\n";
	cin >> selection1;
	if (selection1 == 5)//add a vehicle
		{
			int a = get_featureno();
			std::cout << "selected to add a new vehicle\n";
			std::cout << "Enter details of the vehicle\n";
			cin >> management.veh[vehicleu];
			std::cout << "Enter feature list of vehicle\n";
			management.veh[vehicleu].assign_feature(a);
			for (int i = 0; i < a; i++)
				cin >> management.veh[vehicleu].list[i];
			if (customeru > 14)
				termination();
			vehicleu++;
		}
	if (selection1 == 12)//print all services
	{

		for (int i = 0; i < harrypotter; i++)
			allservices[i].display_service();
		std::cout << endl;
	}
	if (selection1 == 11)
	{
		printmore4(management);
	}
	if (selection1 == 10)//add a service to respective driver
	{
		harrypotter++;
		invasion++;
		std::cout << "invasion" << invasion << endl;

		int dummyid;
		std::cout << "Enter the id of driver you want to add a service\n";
		cin >> dummyid;
		for (int i = 0; i < driveru; i++)
		{
			if (management.drive[i].getdid() == dummyid)
			{
				dummyid = i;
				break;
			}
		}
		std::cout << management.drive[dummyid].service_no << endl;
		std::cout << "ENter the service\n";
		management.drive[dummyid].initializer_service();
		if (invasion > 1)
			increase_service(management, dummyid);
		management.drive[dummyid].get_service(management.drive[dummyid].service_no);
		std::cout << harrypotter << "   services added don't worry" << endl;
	}
}
void displayImage(const std::string& imagePath) {
	std::ifstream file(imagePath);
	if (!file) {
		std::cerr << "Failed to open the image file: " << imagePath << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}

	file.close();
}