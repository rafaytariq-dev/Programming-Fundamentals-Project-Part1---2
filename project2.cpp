//including input output stream
#include <iostream>
//including file stream
#include <fstream>
//using standard namespace
using namespace std;
//global constant variable column with value 4
const int column=4;
//global constant variable row with value 30
int row=30;
//add function decleration
void adddata( int dataArray[][column], int& currentrow)
//function definition start
{   //integer variable serialnum formed
    int serialnum;
    //integer variable orgprice formed
    int orgprice;
    //integer variable discount formed
    int discount;
    //integer variable newprice formed
    int newprice;
    //displaying info
    cout<<"Enter serial number: ";
    //take input from the user
    cin>>serialnum;
    //displaying info
    cout<<"Enter Original Price: ";
    //take input from the user
    cin>>orgprice;
    //displaying info
    cout<<"Enter discount on this art piece: ";
    //take input from the user
    cin>> discount;
    //displaying info
    cout<<"Enter new price after discount: ";
    //take input from the user
    cin>>newprice;
    //if the current row is less than the rows defined for the array
    if (currentrow < row) {
        // add serial number to column 1
        dataArray[currentrow][0] = serialnum;
        //add orginal price to column 2
        dataArray[currentrow][1] = orgprice;
        //add discount to column 3
        dataArray[currentrow][2] = discount;
        //add new price to colum 4
        dataArray[currentrow][3] = newprice;
        // increment the current row so that the data donot exceeds the columns defines
        currentrow++;
    }
    //if current row exceeds rows defined 
    else {
        //print and notify user that new data cannot be added
        cout << "Array is full. Cannot add more data." << endl;
    }
       
}

//search Array function decleration
void searchArray(const int dataArray[][column], int currentrow) {
    //integer variable searchvariable declared
    int searchvariable;
    //made a bool variable found 
    bool found = false;
    //displaying info
    cout << "Enter the variable you want to find: ";
    //take input from the user
    cin >> searchvariable;
    //nested loop to check rows and columns
    for (int i = 0; i < currentrow; i++) {
        //search columns
        for (int j = 0; j < column; j++) {
            //if row and column matches the search variable entered by the user
            if (dataArray[i][j] == searchvariable) {
                //bool value gives true
                found = true;
                //for user information, telling row and column where the searchvariable lies
                cout << "Variable found at line " << i + 1 << ", column " << j + 1 << "!" << endl;
            }
        }
    }
    //if bool value is false
    if (!found) {
        //user information, not found
        cout << "Variable not found." << endl;
    }
}

//Viewarray function decleration
void viewArray(const int dataArray[][column], int currentrow)
{   //print info for user ease
    cout << "Data in the array:\n";
    //nested loop to search rows
    for (int i = 0; i < currentrow; i++) {
        //nested loop to search columns
        for (int j = 0; j < column; j++) {
            //print out the array to display what is stored in the array
            cout << dataArray[i][j] << "\t";
            
        }
        //print endline so that info in the array starts with new line.
        cout << endl;
    }
    
}
//edit data function declarator
void editdata(int dataArray[][column], int currentrow) {
    // integer variable formed to find value that needs to be changed
    int editSerialNum;
    //print info for user ease
    cout << "Enter the serial number you want to edit: ";
    //take input from the user for the serial number that needs to be changed
    cin >> editSerialNum;
    //bool variable named found formed set to false
    bool found = false;
    //search rows
    for (int i = 0; i < currentrow; ++i) {
        //if in data array first value matches the serial number that the user wants to change
        if (dataArray[i][0] == editSerialNum) {
            //bool value gets true
            found = true;
            //Ask user to enter new serial number
            cout << "Enter new serial number: ";
            //take input and store in the array the row where the previous data was and column 0
            cin >> dataArray[i][0];
            //Ask user to enter price
            cout << "Enter new price: ";
            //take input and store in the array at the row where the previous data was and column 1
            cin >> dataArray[i][1];
            //Ask user to enter new serial number
            cout << "Enter new discout: ";
            //take input and store in the array at the row where the previous data was and column 2
            cin >> dataArray[i][2];
            //Ask user to enter new serial number
            cout << "Enter new price: ";
            //take input and store in the array at the row where the previous data was and column 3
            cin >> dataArray[i][3];
            //Print to tell user that record has been updated successfully
            cout << "Record updated successfully." << endl;
        }
    }
    //if bool value is false
    if (!found) {
        //print to tell user that serial number not found
        cout << "Serial number not found." << endl;
    }
}

//menu function declaration
void menu( int dataArray[][column], int currentrow )
{

   //making an integer variable to ask user what he wants to do
    int choice;
    //using a do while loop
    do{

    //print this body for users information    
    cout<<"Enter numbers from 1 till 5 to view menu: \n"
        <<"1: Search Record\n"
        <<"2: View Record\n"
        <<"3: Add Record\n"
        <<"4: Edit Record\n"
        <<"5: Exit Menu\n";
    //take input from user for menu choice
    cin>>choice;

    //assigning choice to switch statement
    switch(choice){
        //if user enters 1 in choice
        case 1:
        //run search record function
        searchArray(dataArray, currentrow);
        //stop after running the search function once
        break;

        //if user enters 2 in choice
        case 2:
        //run view record function
        viewArray(dataArray, currentrow);
        //stop after running the view function once
        break;

        //if user enters 3 in choice
        case 3:
        //run view record function
        adddata(dataArray, currentrow);
        //stop after running the add function once
        break;

        //if user enters 4 in choice
        case 4:
        //run edit record function
        editdata(dataArray, currentrow);
        //stop after running the edit function
        break;

        //if user enters 6 in choice
        case 5:
        //print exiting the program
        cout<<"Exiting the program\n";
        //exit the program
        exit(0);
    //switch statements closes    
    }
    //do statement closes
    }
    //while choice is not equal to 6
    while (choice != 5 );
    //print this body
    {
        //wrong input
        cout<<"Wrong Input";
    }
//function definition ends   
}
//main function starts
int main()
{   
    //making an array with row and column as global variables
    int dataArray [row][column];
    //integer named as current row given the value of 0
    int currentrow =0;
    //call menu function
    menu(dataArray, currentrow);
    //return 0 to main function
    return 0;
}