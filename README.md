

# Anya's Car Rental System (C++)

Submission for Assignment 1 **Course CS253**.



## Table Of Content 

* [Introduction](#Introduction)
* [Installation](#Installation)
* [Challenges](#Challenges)


## Introduction 
The mentioned application allows three types of users to register and log in -

    1. Manager
    2. Customer
    3. Employee

Welcome to Anya's car rental system!


                                        -----------------------------------
                                                  Login Process!
                                        -----------------------------------

Upon logging in, users can perform various operations such as viewing available cars, browsing rented cars, renting a car, clearing dues, and returning a car.

You must enter a given role as a string, e.g., manager, customer or employee.


### Car Attributes

- Brand
- Model
- Manufacture Year
- Plate Number (Unique Identifier)
- Condition (Rating 1-10)
- Price
- Rental Status
- Rented Date
- Returned Date
- Availability

The ```plateNumber``` attribute is a unique identifier throughout the code to identify the car. Rented contains the ID of the person to whom the car is rented. Condition is a rating of the car on a scale of 1 to 10.

The system automatically takes input of the rented date automatically when a car is rented similarly for returned time.
  
### Customer/Employee Attributes

- ID
- Password
- Rented Cars
- Fine Due
- Record (Feedback)

The system restricts user records, fines, and rental conditions to ensure fair usage. Customers are expected to return cars within a month, and fines are applied for late returns.

Managers have additional functionalities for managing cars and users, such as adding, updating, deleting cars or users and searching for specific customers or employees.

The record represents the user's feedback to the company and is a non-negative integer. An average customer record is 50; if you go below 40 points or your fine goes above 100,000, then the user would no longer be allowed to rent a car from this system again. If the condition of the car returned is less than five or if the car is returned later than the due date, then the record is decreased by 1. 

The customer is expected to return the car within one month of the borrowed date, and a fine is imposed as 1% of the price of the car rented per day delay.

The customer/employee is allowed to rent up to 5 cars at a time, and employees are offered a 15% discount on the car's rental price.


 

### Login as a Customer / Employee

We are prompted with the following options for doing so 
```
1. See Available Cars
2. Browse Rented Cars
3. Rent a Car
4. Clear Dues
5. Return a Car
6. Exit
```

Enter your choice:

You must enter the number given alongside the operation you intend to perform.  

Let us go over the options one by one.

**See Available cars**

It shows the list of cars available now, meaning they are in the car database, and nobody is renting them.

**Browse Rented Cars**

It lists all the cars you are currently browsing.

**Rent a Car**

On selecting this option, all the available cars, along with their details, will be displayed, and you will be required to enter the license/platenumber of one of them to rent.

**Clear Dues**

On selecting this option, you will be shown your current due amount and have to enter the amount you wish to pay. An error message will be displayed when entering an amount higher than the current due amount. If you enter an amount less than or equal to the current due, that amount will be deducted from your current due.

**Return a Car**

On selecting this option, you will be shown all the cars you are currently renting, and you will be asked to enter the license/plate number of the car you want to return, its condition and the delay in return.

### Manager
```
Id: Anya
Password: Anya
```
The manager is the default owner of the car in case it is not rented by anyone.

If we enter as a manager, the following options are dispalyed

                                  Manager Menu
                                -------------------
                        1. Add Car
                        2. Add User
                        3. Update Car
                        4. Delete Car
                        5. Delete User
                        6. Update User
                        7. Display Cars
                        8. Search Customer
                        9. Search Employee
                        10. Exit

Let us go over the options one by one.

**Add Car**

The manager will be prompted to enter the car details you want to add. If the manager tries to add a car with a license already in the system, an error will be displayed.

**Add User**

In this option, we can enter 1 for customer addition and 2 for employee addition. The ID and password of the user to be added are asked. If the manager tries to add a user with a username and password already present in the system, an error will be displayed.


**Update Car**

The manager can update the car's brand, model, condition and price. 

If the manager wants to update the person that the car is renting to make the car available or rent the car to someone, then the manager can look up the ID and password of that person and login with it to do so.

**Delete Car**

Enter the license/platenumber of the car that the manager wants to delete. This also deletes the car from the user database if anyone has rented it.

**Delete User**

Enter the ID of the user that the manager wants to delete. This also makes the car that the user may have rented automatically available.

**Update User**

Update the user's various details as asked by the prompt.

**Dispaly cars**

This displays the details of all the cars present in the car database.

**Search customer**

Enter the customer's ID that the manager wishes to search, and all the details will be displayed.


**Search Employee**

Enter the customer's ID that the manager wishes to search, and all the details will be displayed.

### Database
There are three databases present one each for car, customer and employee

#### Car database

There are 10 values present in each line for a customer which are in the order of brand, model, availibility, manufacture year, plate number, condition, price, rented person name, rented date and returned date 

A blank space is present whenever that value is not present in the database.

#### Employee/Customer database

There are 5 values present in each line namely id, password, rented cars seperated by a string, fine due, record value

There are 8 cars, 5 customers and 5 employees. 
## Installation

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Compile the program using your C++ compiler.
4. Run the compiled executable to start the application.

## Challenges

The development process encountered challenges such as handling user input, implementing fine calculations, and ensuring data integrity. The feedback system and record management added complexity but enhance the user experience.


