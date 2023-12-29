//Arts Gallery Management System
//Entities:
//1.Serial Number
//2.Type of Art
//3.Painter Name
//4.Mode of Art

//input output library
#include<iostream>
//file library
#include<fstream>
//string library
#include<string>

//using standard namespace
using namespace std;

//Declare functions
void add_record();
//Declare functions
void edit_record();
//Declare functions
void view_record();
//Declare functions
void search_record();
//Declare functions
void delete_record();
//Declare functions
void view_menu();


//declarator
void add_record()
//function lines
{   
    //creating an output file stream named as fout
    ofstream fout;
    //opening file arts.txt and appending the file
    fout.open("arts.txt", ios::app);
    //declaring variables
    int serialnumber;
    //declaring variables
    string typeofart;
    //declaring variables
    string paintername;
    //declaring variables
    string modeofart;
    
    //displaying information
    cout<<"Enter Serial Number\n";
    //input info
    cin>>serialnumber;
    //displaying information
    cout<<"Enter Type of Art\n";
    //input info
    cin>>typeofart;
    //displaying information
    cout<<"Enter Painter Name\n";
    //input information
    cin>>paintername;
    //displaying information
    cout<<"Enter Mode of Art\n";
    //input information
    cin>>modeofart;
    //writing data into the file
    fout<<serialnumber<<"\t"<<typeofart<<"\t"<<paintername<<"\t"<<modeofart<<"\t"<<endl;
    //closing file
    fout.close ();
    //closing function description
}

//declarator
void view_record()
//function definition
{
//creating an input file stream named fin
ifstream fin;
//opening file named arts.txt
fin.open("arts.txt");
//declaring variables
int serialnumber;
//declaring variables
string typeofart;
//declaring variables
string paintername;
//declaring variables
string modeofart;
//displaying information
cout<<"Serial Number\tType of Art\tPainter Name\tMode of Art\n";
//if user inputs serial number, type of art, painter name and mode of art;
while (fin>>serialnumber>>typeofart>>paintername>>modeofart)
//print this body
{
    cout<<serialnumber<<"\t"<<typeofart<<"\t"<<paintername<<"\t"<<modeofart;
}
//close the file
fin.close();
//function definition ends
}

//declarator
void search_record()
//function body
{
    //making a new variable named searchart
    int searchart;
    //displaying info
    cout<<"Enter Serial Number\n";
    //input variable search art
    cin>>searchart;
    //creating input file stream named fin
    ifstream fin;
    //opening file arts.txt
    fin.open("arts.txt");
    //decalring variables
    int serialnumber;
    //decalring variables
    string typeofart;
    //decalring variables
    string paintername;
    //declaring variables
    string modeofart;
    //if user inputs serial number,type of Art,painter name ,mode of art.
    while (fin>>serialnumber>>typeofart>>paintername>>modeofart);
    {
        //if searchart matches serial number
        if (searchart == serialnumber)
        //print this body
        {
            //displaying info
            cout<<"Art piece found!\n";
        }
        //else if searchart doesnot matches serial number
        else if (searchart != serialnumber)
        //print this body
        {
            goto notfound;
        }
    //closing while statement    
    }
    notfound:
    cout<<"Art Piece not found";

//function definition ends
}

//declarator
void edit_record()
//function body
{   //creating input file stream fin
    ifstream fin;
    //creating input file stream fout
    ofstream fout;
    //creating integer variable
    int oldserial, serialnumber, newserial;
    //creating string variables
    string typeofart, paintername, modeofart;
    //asking user to enter serial number to edit
    cout << "Enter the serial number you want to edit: ";
    //take input
    cin >> oldserial;
    //opening file arts.txt
    fin.open("arts.txt");
    //opening file artstemp.txt
    fout.open("artstemp.txt");

    //if files donot open
    if (!fin || !fout)
    //print body
    {   //Tell user that files failed to open
        cout << "Runtime_Error: File not opening" << endl;
        return;
    }
    //creating bool variable found 
    bool found = false;
    //read the data from file arts.txt
    while (fin >> serialnumber >> typeofart >> paintername >> modeofart)
    {   //if serial number = old serial
        if (serialnumber == oldserial)
        {   //bool variable equals to true
            found = true;
            
        }
        //else
 else
        {
            //print the variables in new file
            fout << serialnumber << "  " << typeofart << "   " << paintername << "   " << modeofart << endl;
        }
        // if bool variable found 
        if (found)
        {   
            found=false;
            //ask user to input new serial number
            cout << "Enter new serial number: ";
            // enter new serial number
            cin >> newserial;
            //ask user to enter art type
         cout<<"Enter type of art: ";
         // enter type of art
            cin>>typeofart;
            //ask user to enter new painter name
            cout<<"Enter new painter name: ";
            //enter new painter name
            cin>>paintername;
            //ask user to enter new mode of art
            cout<<"Enter new mode of art: ";
            //enter mode of art
            cin>>modeofart;
            //print all this new data to new file
            fout << newserial << "   " << typeofart << "   " << paintername << "   " << modeofart << endl;
            //tell user that data is updated successfully
            cout << "\n\nRecord updated successfully." << endl;
    }       // to prevent printing the original record
            continue;
        }
        //close arts.txt
    fin.close();
    //close artstemp.txt
    fout.close();
    //delete old file
    remove("arts.txt");
    //rename temporary file as arts.txt
    rename("artstemp.txt", "arts.txt");
        
}




//declarator
void delete_record()
//function definition starts
{
//Initialize variable to store user data read from file along with serial number of record to be deleted
int serialdel, serial;
string typeofart, paintername, modeofart;
//Ask user to enter serial number that he wants to delete
cout << "Enter serial number of art piece that needs to be deleted: ";
//take input of serial number
cin >> serialdel;
//Print line for formatting
cout << endl;
//creating input file stream named fin
ifstream fin;
//opening file named arts.txt
fin.open("arts.txt");
//if file doesnot open
if (!fin) 
// print this body
{
//Notify user that file failed to open
cout << "Runtime_Error: File not opening" << endl;
return;
}
//creating output file stream named fout
ofstream fout;
//operning file newarts.txt
fout.open("newarts.txt");
//if file doesnot open
if (!fout) 
//print this body
{
//Notifying user that file failed to open
cout << "Runtime_Error: File not opening" << endl;
return;
}
//Read data from arts.txt one record at a time
while (fin >> serial >> typeofart >> paintername >> modeofart) {
    //Dont write to new file if serial number matches to the serial number that user wants to delete
	if (serial == serialdel) {
		
	}
	//Write data to updated file
		else {
			fout << serial << " " << typeofart << " " << paintername << " " << modeofart << endl;;
		}
	}
	//Close arts.txt
	fin.close();
	//Closing newarts.txt
	fout.close();

	//Deleting the old file
	remove("arts.txt");
	//Updated file newarts.txt is named to arts.txt so that it is opened in the next iteration of program
	rename("newarts.txt", "arts.txt");
}


//declarator
void view_menu()
//function definition starts
{   //making an integer variable to ask user what he wants to do
    int choice;
    //using a do while loop
    do{

    //print this body for users information    
    cout<<"\nEnter numbers from 1 till 6 to view menu: \n"
        <<"1: Search Record\n"
        <<"2: View Record\n"
        <<"3: Add Record\n"
        <<"4: Edit Record\n"
        <<"5: Delete Record\n"
        <<"6: Exit Menu\n";
    //take input from user for menu choice
    cin>>choice;

    //assigning choice to switch statement
    switch(choice){
        //if user enters 1 in choice
        case 1:
        //run search record function
        search_record();
        //stop after running the search function once
        break;

        //if user enters 2 in choice
        case 2:
        //run view record function
        view_record();
        //stop after running the view function once
        break;

        //if user enters 3 in choice
        case 3:
        //run view record function
        add_record();
        //stop after running the add function once
        break;

        //if user enters 4 in choice
        case 4:
        //run edit record function
        edit_record();
        //stop after running the edit function
        break;

        //if user enters 5 in choice
        case 5:
        //run delete record function
        delete_record();
        //stop after running the edit function
        break;

        //if user enters 6 in choice
        case 6:
        //print exiting the program
        cout<<"Exiting the program\n";
        //exit the program
        exit(0);
    //switch statements closes    
    }
    //do statement closes
    }
    //while choice is not equal to 6
    while (choice != 6 );
    //print this body
    {
        //wrong input
        cout<<"Wrong Input";
    }
//function definition ends   
}

//calling main function
int main()
//function body
{
//run view menu function
view_menu();
//return 0 to integer type in main function
return 0;
//function body ends
}


