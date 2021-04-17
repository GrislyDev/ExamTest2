#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Routes
{
	string number;
	string driverName;
	string routeName;
	string seats;
};

void AddRoute(Routes* pRoutes, int& pCount);
void SearchRoute(Routes* pRoutes, int pCount);

int main()
{
	int count = 0;
	Routes routes[10] = {};
	string option;
	cout << "Type in the commands and instructions you want and then press enter.\n\n" 
			<< "add - This command allows you to add new routes.\n"
			<< "search - This command allows you to search for routes by parameter.\n\n";

	while (true)
	{
		cout << "> ";
		cin >> option;

		if (option == "add")
			AddRoute(routes, count);
		else if (option == "search")
			SearchRoute(routes, count);
		else
			cout << "Error!\n";
	}
}

void AddRoute(Routes* pRoutes, int &pCount)
{
	cin.get();
	cout << endl;
	if (pCount < 10)
	{
		cout << "Adding a route " << pCount + 1 << "/10..\n\n";
		cout << "The bus number: ";
		getline(cin, pRoutes[pCount].number);
		cout << "The name of the driver: ";
		getline(cin, pRoutes[pCount].driverName);
		cout << "The route name: ";
		getline(cin, pRoutes[pCount].routeName);
		cout << "The numbers of seats: ";
		getline(cin,pRoutes[pCount].seats);
		cout << "The route was added.\n\n";
		pCount++;
	}
	else
		cout << "Added the maximum number of routes.\n";
}

void SearchRoute(Routes* pRoutes, int pCount)
{
	cin.get();
	cout << endl;
	string key;
	cout << "Search by route name.Enter the route: ";
	getline(cin, key);
	for (int i = 0; i < pCount; i++)
	{
		if (pRoutes[i].routeName == key)
		{
			cout << "\tBus number: " << pRoutes[i].number 
				<< "\tDriver: " << pRoutes[i].driverName
				<< "\tRoute: " << pRoutes[i].routeName 
				<< "\tSeats: " << pRoutes[i].seats << endl;
		}
	}
}