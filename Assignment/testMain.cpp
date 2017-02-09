#include <iostream>
#include "Hungarian.h"

using namespace std;

int main()
{
    // please use "-std=c++11" for this initialization of vector.
    vector< vector<double> > costMatrix;
    vector <string> driverNames;
    vector <char> custNames ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int noOfCustomer;
    int noOfDriver;
    cout<<endl<<"\t\t\tTaxi Company Assignment Solution"<<endl;
    cout<<"\t================================================================"<<endl;
    cout<<"\tNumber of Customer: ";
    cin>>noOfCustomer;
    cout<<"\tNumber of Driver: ";
    cin>>noOfDriver;
    cout<<"\t================================================================"<<endl;
    cout<<"\tDriver Names:"<<endl;
    for(int i=0;i<noOfDriver;i++)
    {
        string name;
        cout<<"\t"<<i+1<<". Driver "<<i+1<<": ";
        cin>>name;
        driverNames.push_back(name);
        cout<<endl;
    }
    cout<<"\t================================================================"<<endl;
    cout<<"\tPlease key in the cost needed to each driver by picking up the \n\tparticular customer."<<endl;
    for(int i=0;i<noOfDriver;i++)
    {
        cout<<endl;
        vector<double> driverCost;
        cout<<"\t"<<driverNames[i]<<": "<<endl;
        for(int j=0;j<noOfCustomer;j++)
        {
            double cost;
            cout<<"\tCustomer "<<custNames[j]<<": ";
            cin>>cost;
            driverCost.push_back(cost);
        }
        costMatrix.push_back(driverCost);

    }

//    for(int i=0;i<noOfDriver;i++)
//    {
//        for(int j=0;j<noOfCustomer;j++)
//            cout<<costMatrix[i][j]<<"\t";
//        cout<<endl;
//    }

    cout<<"\t================================================================"<<endl;
    cout<<"\tCost for each customer by driver:"<<endl<<endl;
    cout<<"\tDriver\\Customer";
    for(int i=0;i<noOfCustomer;i++)
    {
        cout<<"\t"<<custNames[i];
    }
    cout<<endl;
    for(int i=0;i<noOfDriver;i++)
    {
        cout<<"\t"<<driverNames[i]<<"\t";
        for(int j=0;j<noOfCustomer;j++)
        {
            cout<<"\t"<<costMatrix[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"\t================================================================"<<endl;
    cout<<endl;

//	vector< vector<double> > costMatrix = { { 9, 11, 14, 11, 7 },
//										  { 6, 15, 13, 13, 10 },
//										  { 12, 13, 6, 8, 8 },
//										  { 11, 9, 10, 12, 9 } ,
//										  { 7, 12, 14, 10, 14 } };

	HungarianAlgorithm HungAlgo;
	vector<int> assignment;

	double cost = HungAlgo.Solve(costMatrix, assignment);

//	for (unsigned int x = 0; x < costMatrix.size(); x++)
//		cout << x+1 << "," << assignment[x]+1 << "\t";
//
//	cout << "\ncost: " << cost << endl;

	cout<<"\tDriver\tCustomer\tCost"<<endl;
    for(int i=0;i<noOfDriver;i++)
    {
        int custIndex=assignment[i];
        cout<<"\t"<<driverNames[i]<<"\t"<<custNames[custIndex]<<"\t\t"<<costMatrix[i][custIndex]<<endl;
    }
    cout<<endl;
    cout<<"\tTotal cost: "<<cost<<endl;
    cout<<"\t================================================================"<<endl;

	return 0;
}
