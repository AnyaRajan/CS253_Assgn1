#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
using namespace std;

class User;class manager;
class Car

{
    private:
    string brand;
    string model;
    int manufacture_year;
    string plateNumber;
    int condition;
    int price;
    
   //friend void update(vector<Car>& cars,string license);
    public:
    friend vector<Car> readCarDataFromFile( string& filename) ;
    friend void writeCarDataToFile(const vector<Car>& cars, const string& filename);
    string rented;
    string rented_date;
    string returned_date;
    
    string available;
    
    
    friend class manager;
    friend class User; // Forward declaration of class User
    friend class employee;
   

    void rent_request(string name) {
        available = "false";
        rented = name;
      
        auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // Convert to std::tm for formatting
    std::tm* timeStruct = std::localtime(&currentTime);

    // Format the date
    std::stringstream ss;
    ss << std::put_time(timeStruct, "%d-%m-%Y");

    // Get the formatted date as a string
     rented_date = ss.str();
        return;
    }
        
     void displayAttributes() const {
    cout << "Brand: " << brand << "\n";
    cout << "Model: " << model << "\n";
    cout << "Available: " << (available) << "\n";
    cout << "Year: " << manufacture_year << "\n";
    cout << "Plate: " << plateNumber << "\n";
    cout << "Condition: " << condition << "\n";
   // cout << "Price: " << price << "\n";
    cout << "Rented: " << rented << "\n";
    cout << "Rented Date: " << rented_date << "\n";
    cout << "Returned Date: " << returned_date << "\n";
}




int return_request(vector<Car>& cars, const string& plateNum) {
        for (auto& c : cars) {
            if (c.plateNumber == plateNum && c.available=="false") {
              
               c.available = "true"; 
               
                c.rented = "Anya"; // Set rented to empty string
          
     auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // Convert to std::tm for formatting
    std::tm* timeStruct = std::localtime(&currentTime);

    // Format the date
    std::stringstream ss;
    ss << std::put_time(timeStruct, "%d-%m-%Y");

    // Get the formatted date as a string
     returned_date = ss.str();
 cout<<"\t\tHow many days after the rented date is the car returned? ";
        int days;cin>>days;
    if (days < 30) {
    return 0;
} else {
    return days;
}return (days-30);
            
        
            
                    
        }
       
    }
     cout << "Car with plate number " << plateNum << " was not rented or is already returned." << endl;
    return 0;
}
};

class customer;class employee;class manager;
class User
{
    
protected:
string id;
string password;
vector<string> rented_cars;
int fine_due;
int record;

public:

friend class manager;
virtual void seeAvailableCars( vector<Car>& cars) {
        cout << "Available Cars:\n";
         cout << "\t\t\tBrand\t\tModel\t\tAvailable\tYear\t\tPlate\t\tCondition\tPrice\n";
    cout << "\t\t\t-----------------------------------------------------------------------------------------------\n";
    bool show=false;
       for (const auto& car : cars) {
        if(car.available == "true")
        {
        cout << "\t\t\t" << car.brand << "\t\t" << car.model << "\t\t" << (car.available ) << "\t\t"
             << car.manufacture_year << "\t\t" << car.plateNumber << "\t\t" << car.condition << "\t\t" << car.price <<"\n";show=true;
        }
    }
    if(!show)
    {
        cout<<"\t\t No available cars\n";
    }
        
    }
void displayMenu(vector<Car>& cars,vector<customer>& customers,vector<employee>& employees) {
        int choice;
        do {
    
            cout << "\n\n\t\t\t\tMenu\n";
            cout << "1. See Available Cars\n";
            cout << "2. Browse Rented Cars\n";
            cout << "3. Rent a Car\n";
            cout << "4. Clear Dues\n";
            cout << "5. Return a Car\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    seeAvailableCars(cars);
                    break;
                case 2:
                    browseRentedCars(cars);
                    break;
                case 3:
                    if(record>=40 && fine_due<=100000 && rented_cars.size()<=5)
                    {
                    rent_car(cars);
                    }
                    else{
                        cout<<"Sorry you lack enough credit points to rent a car.";
                    }
                    break;
                case 4:
                    clear_due();
                    break;
                case 5:
                    return_car(cars);
                    break;
                case 6:
                    cout << "Exiting Customer Menu\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }

            
        } while (choice != 6);
        //login(cars,customers,employees,manager1);see this afterwards
    }
    virtual void rent_car(vector<Car>& cars)
    {
        cout << "\t\t\t\t\t-----------------------------------\n";
        cout<<"\t\t\t\t\t\tThe following cars are available for rent\n";
        seeAvailableCars(cars);
        cout<<"\nPlease enter the license number of the car to be rented ";
        string license;cin>>license;
        for (auto& car : cars) 
        {
            if(car.plateNumber == license)
            {
                if (car.available =="true") {//check for status of customer there and then only
                    car.rent_request(id);
                    rented_cars.push_back(car.plateNumber);//called after object instantiation
                    cout << "\t\tCar with plate number " << car.plateNumber << " has been rented.\n" << endl;
                    fine_due += car.price;
                    cout<<car.price<<" has been added to your fine due\n";
                    cout<<"Your fine due is now "<<fine_due<<"\n";    
                    cout<<"Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                    return;
                } else {
                    cout << "\t\tCar with plate number " << car.plateNumber << " is not available for rent.\n" << endl;
                    cout<<"Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                    return;
                }
            }
        }
       cout<<"\t\tCar with plate number " << license << " not found.\n";

    }



    void clear_due()
{
while (true) {
            cout << "\t\tYour total fine due is: " << fine_due << "\n";
            
            int amount;
            cout << "\t\tPlease enter the amount you wish to pay (enter 0 to cancel):\n ";
            cin >> amount;
            
            if (cin.fail()) { // Input validation
                cout << "\t\tInvalid input. Please enter a valid number.\n" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue; // Re-prompt for input
            }

            if (amount == 0) {
                cout << "\t\tPayment cancelled.\n" << endl;
                break; // Exit the loop
            }

            if (amount < 0) {
                cout << "\t\tInvalid input. Please enter a non-negative amount.\n" << endl;
                continue; // Re-prompt for input
            }

            if (amount > fine_due) {
                cout << "\t\tThe amount entered is greater than the amount to be paid. Please enter again.\n" << endl;
                continue; // Re-prompt for input
            }

            fine_due -= amount; // Deduct payment from dues
            cout << "\t\tYour amount due has been updated and now is:" << fine_due <<"\n"<< endl;
            break; // Exit the loop
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }
        return;
}
virtual void browseRentedCars(vector<Car>& cars) {
        if (rented_cars.empty()) {
            cout << "\t\tYou are not currently renting any cars.\n";
            return;
        }

        cout << "\t\tCars you are currently renting:\n";
        for (const auto& i : cars) {
           
                if(i.rented == id)
                {
                   i.displayAttributes();
                   cout << "Price: "<<i.price<<"\n";
                   cout<<"\n";
                }
        }
    }

    void return_car(vector<Car>& cars)

{
    browseRentedCars(cars);
    cout<<"\n";
    if(rented_cars.size()==0)
    {
        //cout<<"\t\tYou are not currently renting any cars.\n";
        return;
    }
    cout<<"\t\tPlease enter the license number of the car to be returned or press 0 to cancel: ";
    string license;cin>>license;
    if(license=="0" || license.size()==0)
    {
        cout<<"Returning to menu\n";
        return;
    }
     rented_cars.erase(std::remove(rented_cars.begin(), rented_cars.end(), license), rented_cars.end());
                 

    for(auto& Car: cars)
    {       if(Car.plateNumber==license)
            {
                cout << "\t\tEnter the condition of the car returned on a scale of 1 to 10: ";
                 int condition1;
                 cin >> condition1;
                  if (condition1 <= 5) {
                    record--;
                    Car.condition = condition1;
                  }
                fine_due = fine_due + 0.01*Car.price*Car.return_request(cars, license);
                cout<<"\t\t"<<"Your fine due is now"<<fine_due<<"\n";
                cout << "\t\tCar with plate number " << license << " has been returned." << endl;
                cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
                 return;
            }
            
        }
        cout << "\t\tCar with plate number " << license << " not found.\n" << endl;
        cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
    }
};



/// @brief ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class customer: public User
{
    public:
friend class manager;
friend vector<customer> readCustomerDataFromFile(const string& filename) ;
friend void writeCustomerDataToFile(const vector<customer>& customers, const string& filename);
friend bool authenticateCustomer(const string& current_username, const string& current_password,vector<customer> customers, int&i);
protected:
    void showUser(vector<customer> customers)
    {
        cout<<"-----------------------------------\n";
        cout<<"The details of the customer are as follows\n";
        
                cout<<"The id of the customer is "<<id<<"\n";
                cout<<"The password of the customer is "<<password<<"\n";
                cout<<"The fine due of the customer is "<<fine_due<<"\n";
                cout<<"The record of the customer is "<<record<<"\n";
                cout<<"The rented cars of the customer are as follows\n";
                for(auto j:rented_cars)
                {
                    cout<<j<<"\n";
                }
         
    }


};
/// @brief ///////////////////////////////////////////////////////////////////////////////////////////////////
class employee:public User
{
    public:
friend class manager;
 void browseRentedCars(vector<Car>& cars) {
        if (rented_cars.empty()) {
            cout << "\t\tYou are not currently renting any cars.\n";
            return;
        }

        cout << "\t\tCars you are currently renting:\n";
        for (const auto& i : cars) {
           
                if(i.rented == id)
                {
                   i.displayAttributes();
                   cout << "Price: "<<0.85*i.price<<"\n";
                   cout<<"\n";
                }
        }
    }

 void seeAvailableCars( vector<Car>& cars) {
        cout << "Available Cars:\n";
         cout << "\t\t\tBrand\t\tModel\t\tAvailable\tYear\t\tPlate\t\tCondition\tPrice\n";
    cout << "\t\t\t-----------------------------------------------------------------------------------------------\n";
    bool show=false;
       for (const auto& car : cars) {
        if(car.available == "true")
        {
        cout << "\t\t\t" << car.brand << "\t\t" << car.model << "\t\t" << (car.available ) << "\t\t"
             << car.manufacture_year << "\t\t" << car.plateNumber << "\t\t" << car.condition << "\t\t" << 0.85*car.price <<"\n";show=true;
        }
    }
    if(!show)
    {
        cout<<"\t\t No available cars\n";
    }
        
    }
friend bool authenticateEmployee(const string& current_username, const string& current_password,vector<employee> employees, int &i);
friend vector<employee> readEmployeeDataFromFile(const string& filename);
friend void writeEmployeeDataToFile(const vector<employee>& employees, const string& filename);

    protected:
    void showUser(vector<employee> employees)
    {
        cout<<"-----------------------------------\n";
        cout<<"The details of the customer are as follows\n";
         cout<<"The id of the employees is "<<id<<"\n";
                cout<<"The password of the employees is "<<password<<"\n";
                cout<<"The fine due of the employees is "<<fine_due<<"\n";
                cout<<"The record of the employees is "<<record<<"\n";
          cout<<"The rented cars of the employees are as follows\n";
                for(auto j:rented_cars)
                {
                    cout<<j<<"\n";
                }
         
    }
 void rent_car(vector<Car>& cars)
    {
        seeAvailableCars(cars);
        cout<<"\t\tPlease enter the license number of the car to be rented or press 0 to cancel";

        string license;cin>>license;
        if(license=="0" || license.size()==0)
        {
            cout<<"\t\tReturning to menu\n";
            return;
        }
        for (auto& car : cars) 
        {
            if(car.plateNumber == license)
            {
                if (car.available =="true") {//check for status of customer there and then only
                    car.rent_request(id);
                    rented_cars.push_back(car.plateNumber);//called after object instantiation
                    cout << "\t\tCar with plate number " << car.plateNumber << " has been rented.\n" << endl;
                    fine_due += 0.85*car.price;
                     cout<<"\t\t"<< 0.85*car.price<<" has been added to your fine due\n";
                    cout<<"\t\tYour fine due is now "<<fine_due<<"\n";    
                    cout<<"\t\tPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    return;
                } else {
                    cout << "\t\tCar with plate number " << car.plateNumber << " is not available for rent.\n" << endl;
                    return;
                }
            }
        }
        cout<<"\t\tCar with plate number " << license << " not found.\n";
return;
    }
};

/// @brief //////////////////////////////////////////////////////////////////////////////////

class manager
{
    private:
    string id;
     string password;

    public:
    friend bool authenticateManager(const string& current_username, const string& current_password,manager manager1);
    manager(const string& id, const string& password) : id(id), password(password){}
    // Function to add a new car
    void addCar(vector<Car>& cars) {
        string brand1, model1, plateNumber1, rented_date1, returned_date1;
    bool available1;
    int manufacture_year1, condition1, price1;

    cout << "Enter brand: ";
    cin >> brand1;

    cout << "Enter model: ";
    cin >> model1;

    cout << "Enter manufacture year: ";
    cin >> manufacture_year1;

    cout << "Enter plate number: ";
    cin >> plateNumber1;

    cout << "Enter condition: ";
    cin >> condition1;

    cout << "Enter price: ";
    cin >> price1;
    for(auto i:cars)
    {
        if(i.plateNumber==plateNumber1)
        {
            cout<<"The car with plate number "<<plateNumber1<<" is already present in the store\n";
            return;
        }
    }
    //see for already some info
    Car car1;
        car1.brand=brand1;
        car1.model=model1;
        car1.available=1;
        car1.manufacture_year=manufacture_year1;
        car1.plateNumber=plateNumber1;
        car1.condition=condition1;
        car1.price=price1;
        car1.rented=id;
        cars.push_back(car1);
     cout << "Car with plate number " << plateNumber1 << " added to the store.\n";
     return;
    
}
       

    void addUser(vector<employee>& employees,vector<customer>& customers) 
    {
        string id1,password1;
        vector<string> rented_cars1;int fine_due1=0;int record1 =50; int number_of_faults=0;
        cout<<"\t\tPlease enter the role of the user you want to add"<<"\n"<<"1.Customer"<<"\n"<<"2.Employee"<<"\n";
        int role;cin>>role;
        if(role==1)
        {
             cout<<"Please enter the id of the customer you wish to add\n";
             cin>>id1;
             cout<<"Please enter the password of the customer you wish to add\n";
             cin>>password1;
             for(auto i:customers)
                {
                    if(i.id==id1 && i.password==password1)
                    {
                        cout<<"The customer is already added\n";return;
                    }
                }
             customer c;
             c.id=id1;
                c.password=password1;
                c.fine_due=0;
                c.record=50;
                customers.push_back(c);
                
        }  
        else if(role==2)
        {
         cout<<"Please enter the id of the employee you wish to add\n";
             cin>>id1;
             cout<<"Please enter the password of the employee you wish to add\n";
             cin>>password1; 
                for(auto i:employees)
                {
                    if(i.id==id1 && i.password==password1)
                    {
                        cout<<"The employeeis already added\n";return;
                    }
                }
                employee E;
                E.id=id1;
                E.password=password1;
                E.rented_cars=rented_cars1;
                E.fine_due=0;
                E.record=50;
                employees.push_back(E);
               
        }
        else{cout<<"Sorry the input is invalid";}
        return;
        
    }
            void updateCar(vector<Car>& cars) 
    {
         cout<<"\t\t\t\t\tPlease enter the details of the updated car\n";
         cout << "\t\t\t\t\t-----------------------------------------\n";
         cout<<"Please enter the license of the car you wish to update: ";
         string license1;cin>>license1;
     
        for (auto& car : cars) {
            if (car.plateNumber == license1) {
                
                cout<<"Enter the new license in case it needs to be updated or else re-enter old one: ";
                string license2;cin>>license2;
                if(license2.size()!=0)
                {
                    car.plateNumber=license2;
                }
                cout << "Enter brand: ";
                cin >> car.brand;
                cout<<"Enter model: ";
                cin>>car.model;
                cout << "Enter condition: ";
               

                cout << "Enter price: ";
                cin >> car.price;
                cout << "Car with plate number " << car.plateNumber << " updated.\n";
                return;
            }
        }
        cout<<"The car with license "<<license1<<"was not found\n";
    }
    

    void updateUserAfterCarDeletion(const string& username, const string& deletedPlateNumber, vector<employee>& employees, vector<customer>& customers) {
    for (auto& employee : employees) {
        cout<<employee.id;
        if (employee.id == username) {
      
            for(string& i:employee.rented_cars)
            {  
                if(i== deletedPlateNumber)
                {  
                    employee.rented_cars.erase(std::remove(employee.rented_cars.begin(), employee.rented_cars.end(), deletedPlateNumber),employee.rented_cars.end());

                }
            }
            return;
        }
    }

    for (auto& customer : customers) {
    
    if (customer.id == username) {
        
        for(string& i:customer.rented_cars)
            {   
                if(i== deletedPlateNumber)
                {  
                    customer.rented_cars.erase(std::remove(customer.rented_cars.begin(), customer.rented_cars.end(), i), customer.rented_cars.end());
                }
            }
       
        return;
    }
}

}



    void deleteCar( vector<Car>& cars ,vector<employee>& employees,vector<customer>& customers)
    {   
         cout<<"\t\tPlease enter the license of the car you wish to delete: ";
         string license1;cin>>license1;
        for (auto it = cars.begin(); it != cars.end(); ++it) {
            if (it->plateNumber == license1) {
                string n=it->rented;
                
            updateUserAfterCarDeletion(n,license1,employees,customers);
            cars.erase(it);
                std::cout << "\t\tCar with plate number " << license1 << " deleted.\n";
                return;
            }
            
        }
        cout << "\t\tCar with plate number " << license1 << " not found.\n";
    }
   


void updateCarsAfterUserDelete(const string& username, vector<Car>& cars) {
    for (auto& car : cars) 
    {
       // cout<<"Hey2\n";
        if (car.rented == username) {
            //cout<<"Hey1\n";
            // Update the car attributes after user deletion
            car.available = "true";
            car.rented = "Anya";
            car.rented_date = " ";
            car.returned_date = " ";
        }
    }
}

   


    // Function to delete a customer
    void deleteUser(vector<customer>& customers,vector<employee>& employees,vector<Car>& cars) 
    {   cout<<"Please enter the number of the role of the user you wish to delete\n 1.Customer\n 2.Employee: ";
        int r;cin>>r;
        if(r==1)
        {
        cout<<"\t\tPlease enter the id of the user you wish to delete\n";
        string customerId;
        cin>>customerId;
        for (auto it = customers.begin(); it != customers.end(); ++it) {
            if (it->id == customerId) {
                for (string& license : it->rented_cars) {

                      updateCarsAfterUserDelete(it->id, cars);
                      }
                      customers.erase(it);
                
                       cout << "\t\tCustomer with ID " << customerId << " deleted.\n";
                return;
            }
        }
        cout << "\t\tCustomer with ID " << customerId << " not found.\n";
    }
    else if(r==2)
    {
        cout<<"\t\tPlease enter the id of the employee you wish to delete\n";
        string customerId;cin>>customerId;
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->id == customerId) {
                for(auto i:it->rented_cars)
                {
                   updateCarsAfterUserDelete(it->id,cars);
                }
                 employees.erase(it);
                 cout << "\t\tEmployee with ID " << customerId << " deleted.\n";
                return;
            }
        }
        cout << "\t\tEmployee with ID " << customerId << " not found.\n";
    }
    else{
        cout<<"\t\t\t\t\tInvalid Input\n";
        cout<<"\t\t\t\t\t----------------------------------------------------\n";
    }
    }
    
    void updateUser(vector<customer>& customers,vector<employee>& employees)
    {
        cout<<"Please enter the role of the user you wish to update\n 1.Customer\n 2.Employee";
        int r;cin>>r;
        if(r==1)
        {
        cout<<"Please enter the name of the user you wish to update\n";
        string customerId;cin>>customerId; 
        for (auto it = customers.begin(); it != customers.end(); ++it) {
            if (it->id == customerId) {
                cout<<"Please enter the password of the user you wish to update:\n";
                string password1;cin>>password1;
                it->password=password1;
                cout<<"Enter the fine due of the user you wish to update\n";
                cin>>it->fine_due;
                return;
            }
        }
        cout << "Customer with ID " << customerId << " not found.\n";
    }
    else if(r==2)
    {
        cout<<"Please enter the id of the employee you wish to delete";
        string customerId;cin>>customerId;
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->id == customerId) {
                cout<<"Please enter the password of the user you wish to update:\n";
                string password1;cin>>password1;
                it->password=password1;
                cout<<"Enter the fine due of the user you wish to update\n";
                cin>>it->fine_due;
                
                return;
            }
        }
        cout << "Employeen with ID " << customerId << " not found.\n";
    }
    else{
        cout<<"\t\t\t\t\tInvalid Input\n";
        cout<<"\t\t\t\t\t----------------------------------------------------\n";
    }
    }
   void display(const vector<Car>& cars) {
    cout << "\t\t\t\t\t Displaying Cars\n";
cout << "\t\t\t\t\t----------------\n";

if (cars.empty()) {
    cout << "\t\t\t\t\tNo cars to display.\n";
    return;
}

cout << "------------------------------------------------------------\n";

for (const auto& car : cars) {
    cout << "Brand: " << car.brand << "\n";
    cout << "Model: " << car.model << "\n";
    cout << "Available: " << (car.available) << "\n";
    cout << "Year: " << car.manufacture_year << "\n";
    cout << "Plate: " << car.plateNumber << "\n";
    cout << "Condition: " << car.condition << "\n";
    cout << "Price: " << car.price << "\n";
    cout << "Rented to: " << car.rented << "\n";
    cout << "Rented date: " << car.rented_date << "\n";
    cout << "Returned date: " << car.returned_date << "\n";
    cout << "------------------------------------------------------------\n";
}
}
void menu(vector<Car>& cars, vector<employee>& employees, vector<customer>& customers) {
        int choice;

        do {
            
            cout << "\t\t\t\tManager Menu\n";
            cout << "\t\t\t\t-------------------\n";
            cout << "\t\t\t1. Add Car\n";
            cout << "\t\t\t2. Add User\n";
            cout << "\t\t\t3. Update Car\n";
            cout << "\t\t\t4. Delete Car\n";
            cout << "\t\t\t5. Delete User\n";
            cout << "\t\t\t6. Update User\n";
            cout << "\t\t\t7. Display Cars\n";
            cout << "\t\t\t8. Search Customer\n";
            cout<< "\t\t\t9. Search Employee\n";
            cout << "\t\t\t10. Exit\n";

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addCar(cars);
                    break;
                case 2:
                    addUser(employees,customers);
                    break;
                    case 3:
                    updateCar(cars);
                    break;
                case 4:
                    deleteCar(cars,employees,customers);
                    break;
                case 5:
                    deleteUser( customers,employees,cars);
                    break;
                case 6:
                    updateUser( customers,employees);
                    break;
                case 7:
            
                    display(cars);
                    break;
                    case 8:
                    {
                    cout<<"Please enter the id of the customer you wish to search\n";
                    string id;cin>>id;bool flag=false;
                    for(auto i:customers)
                    {
                        if(i.id==id)
                        {
                            i.showUser(customers);flag=true;
                        }
                    }
                    if(!flag)
                    {
                        cout<<"The customer with id "<<id<<" was not found\n";
                    }
                    break;
                    }
                    case 9:
                    {
                    cout<<"Please enter the id of the employee you wish to search\n";
                    string id1;cin>>id1;bool flag=false;
                    for(auto i:employees)
                    {
                        if(i.id==id1)
                        {
                            i.showUser(employees);flag=true;
                        }
                    }
                    if(!flag)
                    {
                        cout<<"The employee with id "<<id1<<" was not found\n";
                    }
                    break;
                    }
                case 10:
                    cout << "Exiting Manager Menu\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }

            // Pause to allow the user to read the output
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        } while (choice != 10);
    }
};








bool authenticateEmployee(const string& current_username, const string& current_password,vector<employee> employees, int &i) {
    bool success = false;
    for (const auto& employee : employees) {
        if (employee.id == current_username && employee.password == current_password) {
            success = true;
            break;

        }
        i++;
    }

    if (success)
        return true;
    else
        return false;
}
bool authenticateCustomer(const string& current_username, const string& current_password,vector<customer> customers, int&i) {
    bool success = false;
    for (const auto& customer : customers) {
        if (customer.id == current_username && customer.password == current_password) {
            success = true;
            break;
        }
        i++;
    }

    if (success)
        return true;
    else
       return false;
}
bool authenticateManager(const string& current_username, const string& current_password,manager manager1) {
    bool success = false;
   {
        if (manager1.id == current_username && manager1.password == current_password) {
            success = true;
           
        }
        
    }

    if (success)
        return true;
    else
       return false;
}





void login(vector<Car>& cars, vector<customer>& customers, vector<employee>& employees, manager& manager1) {
    string password = " ";
    string username;
    bool authenticate = true;
    int i = 0;

    do {
        cout << "\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\t  Login Process!\n";
        cout << "\t\t\t\t\t-----------------------------------\n";
        cout << "Please enter your role: manager, customer, or employee\n";
        cout << "Please enter 0 and ENTER to exit\n";
        

        string role;
        cin >> role;if(role=="0") break;
        
        if (role != "manager" && role != "customer" && role != "employee") {
            cout << "Invalid role entered. Please enter a valid role (manager, customer, or employee): \nPress 0 and ENTER to exit\n";
            cin >> role;
            if(role == "0")
            {
                break;
            }
        } 
        else {
            cout << "\n\n\n\n\t\t\t\t\t Please, Enter the username: ";
            cin >> username;
            cout << "\n\n\n\n\t\t\t\t\t Please, Enter the password: ";
            cin >> password;

            if (role == "manager") {
                if (authenticateManager(username, password, manager1)) {
                    manager1.menu(cars, employees, customers);
                } else {
                    authenticate = false;
                }
            } else if (role == "customer") {
                if (authenticateCustomer(username, password, customers, i)) {
                    customers[i].displayMenu(cars, customers, employees);
                } else {
                    authenticate = false;
                }
            } else if (role == "employee") {
                if (authenticateEmployee(username, password, employees, i)) {
                    employees[i].displayMenu(cars, customers, employees);
                } else {
                    authenticate = false;
                }
            }

        }
    } while (authenticate);
    if(!authenticate)
    {
        cout<<"\t\tPassword and id don't match. Please try again.\n";
        cout << "\t\tPress Enter to continue...";
            cin.ignore();
            cin.get();
       login(cars,customers,employees,manager1);
    }
    cout << "\nExiting login process.\n";
}

vector<customer> readCustomerDataFromFile(const string& filename) {
    vector<customer> customers;
    ifstream file(filename);

    if (!file) {
        cerr << "\t\tError opening file: " << filename << endl;
        return customers;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string userId, userPassword, rentedCarsStr;
        int userFineDue, userRecord, userNumberOfFaults;

        
        ss >> userId >> userPassword >> rentedCarsStr >> userFineDue >> userRecord ;

        // Tokenize the rented cars string based on commas
        vector<string> rentedCars;
        stringstream rentedCarsStream(rentedCarsStr);
        string car;
        while (getline(rentedCarsStream, car, ',')) {
            rentedCars.push_back(car);
        }

        customer cust;
        cust.id=userId;
        cust.password=userPassword;
        cust.rented_cars=rentedCars;
        cust.fine_due=userFineDue;
        cust.record=userRecord;

        customers.push_back(cust);
    }

    file.close();
    return customers;
}
void writeCustomerDataToFile(const vector<customer>& customers, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& cust : customers) {
        file << cust.id << " "
             << cust.password << " ";

       
        for (size_t i = 0; i < cust.rented_cars.size(); ++i) {
            file << cust.rented_cars[i];
            if (i < cust.rented_cars.size() - 1) {
                file << ",";
            }
        }

        file << " " << cust.fine_due << " " << cust.record << "\n";
    }

    file.close();
}
vector<employee> readEmployeeDataFromFile(const string& filename) {
    vector<employee> employees;
    ifstream file(filename);

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return employees;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string userId, userPassword, rentedCarsStr;
        int userFineDue, userRecord, userNumberOfFaults;
        ss >> userId >> userPassword >> rentedCarsStr >> userFineDue >> userRecord ;

        vector<string> rentedCars;
        stringstream rentedCarsStream(rentedCarsStr);
        string car;
        while (getline(rentedCarsStream, car, ',')) {
            rentedCars.push_back(car);
        }
 employee emp;
 emp.id=userId;
    emp.password=userPassword;
    emp.rented_cars=rentedCars;
    emp.fine_due=userFineDue;
    emp.record=userRecord;

        employees.push_back(emp);
    }

    file.close();
    return employees;
}

void writeEmployeeDataToFile(const vector<employee>& employees, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& emp : employees) {
        file << emp.id << " "
             << emp.password << " ";

       
        for (size_t i = 0; i < emp.rented_cars.size(); ++i) {
            file << emp.rented_cars[i];
            if (i < emp.rented_cars.size() - 1) {
                file << ",";
            }
        }

        file << " " << emp.fine_due << " " << emp.record << "\n";
    }

    file.close();
    cout << "Employee data written to file: " << filename << endl;
}

vector<Car> readCarDataFromFile( string& filename) 
    {
    vector <Car> cars;
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return cars;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string brand1, model1, plateNumber1;
        int condition1;
        string available1;
        int manufacture_year1, price1;
        string rented1, rented_date1, returned_date1;
        ss >> brand1 >> model1>> available1>> manufacture_year1>> plateNumber1 >> condition1 >> price1>>rented1>> rented_date1>>returned_date1; 
        Car car1;
        car1.brand=brand1;
        car1.model=model1;
        car1.available=available1;
        car1.manufacture_year=manufacture_year1;
        car1.plateNumber=plateNumber1;
        car1.condition=condition1;
        car1.price=price1;
        car1.rented=rented1;
        car1.rented_date=rented_date1;
        car1.returned_date=returned_date1;
        cars.push_back(car1);
       
    }

    file.close();
    return cars;
}
void writeCarDataToFile(const vector<Car>& cars, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& car : cars) {
        file << car.brand << " "
             << car.model << " "
             << car.available << " "
             << car.manufacture_year << " "
             << car.plateNumber << " "
             << car.condition << " "
             << car.price << " "
             << car.rented << " "
             << car.rented_date << " "
             << car.returned_date << "\n";
    }

    file.close();
    cout << "Data written to file: " << filename << endl;
}


int main()
{   
   string filename = "Cute.txt";
   vector<Car> cars = readCarDataFromFile(filename);
   string filename2 ="customer.txt";
   string filename3="employee.txt";
   vector<customer> customers=readCustomerDataFromFile(filename2);
   vector<employee> employees=readEmployeeDataFromFile(filename3);
   manager manager1("Anya","Anya");
   cout << "Welcome to Anya's car rental system!" << endl;
   login(cars,customers,employees,manager1);
    writeCarDataToFile(cars, filename);
    writeCustomerDataToFile(customers, filename2);
    writeEmployeeDataToFile(employees, filename3);
   return 0;
}

