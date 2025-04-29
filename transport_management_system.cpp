#include	"super_interface.h"
#include     "functions.h"
using namespace std;

int main()
{

	TMS management;//object of super class
	//int selection1;//selection variable
	get_static();
	assign_data(management);
	service* allservices=new service[harrypotter];
	service* booking = new service[spiderman];
	invoker(management,allservices);
	//get_bookinghistoryfrom(management,booking);
	int selection2;
	bool carryon=true;
	while (carryon) {
		system("cls");
		std::cout << "\t\t\t\t\t\t1)ADMIN\n\t\t\t\t\t\t2)customer\n\t\t\t\t\t\t3)driver\n\t\t\t\t\t\t4)exit\n";
		cin >> selection2;
		if (selection2 == 1)
		{

			cout << "WELCOME TO ADMIN BLOCK\n";
			adminblock(management, allservices, booking);

		}
		else if (selection2 == 2)
		{
			cout << "Welcome to customer block\n";
			customerblock(management, allservices, booking);
		}
		else if (selection2 == 3)
		{
			cout << "Welcome to driver block\n";
			driverblock(management, allservices, booking);
		}
		else if (selection2 == 4)
		{
			cout << "Thanks for using this transport management system\n";
			carryon = false;
		}
		Sleep(5000);//to pause for 5 seconds
	}
	store_static();//function that stores static variables on file
	////servicesbooked(management);
	writedata(management);//function that stores updated data on files
	
	adminp++;
	std::system("pause");
	return 0;
}