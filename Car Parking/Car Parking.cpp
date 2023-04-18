//Car Parking System CP PROJECT
//It is working perfectely on dev c++ but for vs 2019 4996 warning is to be disabled
#include <iostream> //Header files 
#include<cstdio>
#include <ctime>
#include <string>
#include <fstream>
#include<cmath>
using namespace std;
//user defined functions
float fee(string, float);  //to calculate amount
int out(); //for time is being parked 
int in(); //to check if file exist of not
void file(); //to remove/delete the file
void r_file(); //to change password of admin
string password();  //to change password of admin
struct vehicle_details //structure variables to hold vehicle details
{
    int prkingid;  //to hold parking id
    int in_h, in_m, in_s; //to hold time in hr,min and sec 
    string reg_num; //to hold vehicle registration no.
    string veh_type; //to hold vehicle type car/bike
    time_t hourin; //to hold entry time, when car was parked
    time_t hourout; //to hold time when car is being deparked
    float el_time; //to hold the difference of hourin and hourout 
    float charges; //to hold amount for parking
};
vehicle_details veh[12];  //Array to hold parking id
string pass1 = "admin"; //password of the admin
float mnc = 3, mxc = 6, mnb = 2, mxb = 4; //intial prices, globally defined

int main()
{
B:
    system("cls");
    int USADMIN;

    //Initial selection for User/Admin
    cout << "============================\n WELCOME TO CAR PARKING \n============================\n";
    cout << "1.Admin\n2.User\n3.Exit\nYour Selection...:" << endl;
    cin >> USADMIN;
    if (USADMIN == 1)
    {
    C:
        system("cls");
        string pass;

        cout << "Enter password" << endl;
        cin >> pass;                               //Login form for admin
        if (pass == pass1) //checks if pass is correct then proceed
        {

        D:
            system("cls"); //clears screen
            //Admin screen
            cout << "============================\n WELCOME TO CAR PARKING \n============================\n";
            int aprs;
            //menu
            cout << "1.if you want to check log files\n";
            cout << "2.if you want to change rates\n";
            cout << "3.if you want to see Abouts \n";
            cout << "4.Password Change\n5.Goto User End\n6.Exit\nYour Selection...:\n";
            cin >> aprs;
            if (aprs == 1) //Selection for admin
            {
                system("cls");
                int que;
                cout << "1.View Log\n2.Clear Log\n3.Return\nYour Selection...:" << endl;
                cin >> que;
                if (que == 1) //Open log file contains details that's been parked
                {
                    file();
                    system("pause");
                    goto D;
                }
                else if (que == 2) //Deletes all the details
                {
                    r_file();
                    system("pause");
                    system("cls");
                    goto D;
                }
                else if (que == 3) //Jumps back to starting of admin screen
                {
                    goto D;
                }
            }
            else if (aprs == 2) //Enables admin to update the rates
            {
                system("cls");
                cout << "Enter New Minimum Rate For Car" << endl;
                cin >> mnc;
                cout << "Enter New Maximum Rate For Car" << endl;
                cin >> mxc;
                cout << "Enter New Minimum Rate For Bike" << endl;
                cin >> mnb;
                cout << "Enter New Maximum Rate For Bike" << endl;
                cin >> mxb;
                cout << "Rates Successfully Changed!!!" << endl;
                system("pause");
                system("cls");
                goto D;
            }
            else if (aprs == 3) // Short detail about this car parking system
            {
                system("cls");
                cout << "\t\t\t\t\t===========================\n\t\t\t\t\t|||||||||||ABOUT|||||||||||\n\t\t\t\t\t===========================\n" <<
                    "  This Car parking system is designed to facilitate user/admin." <<
                    "This car park system saves time, money, space and\n" << "      simplifies the " <<
                    "tedious task of parking. Provides, optimum solutions and smart parking system for you.\n" <<
                    "       Lastly,this parking system satisfies your parking request at any place.Thank you for having us!\n\n" <<
                    " Developed by:Ahsan Arshad, Arham Naeem & Aliyan Rehman\n\n";
                system("pause");
                system("cls");
                goto D;
            }
            else if (aprs == 4) //Enables admin to change password
            {

                cout << password(); //calls function
                system("pause");
                goto B;
            }
            else if (aprs == 5) //Jumps to user screen
            {
                goto A;
            }
            else if (aprs == 6) //Exits the program
            {
                exit(0);
            }
            else //Warning message that the number pressed is not valid
            {
                cout << "Invalid Selection!!!" << endl;
                system("pause");
                goto C;
            }
        }
        //Warning message that the password is not valid

        else {
            cout << "wrong password" << endl;

            goto B; //jumps back to the beginning of the program
        }
    }
    //Admin view ends here
    else if (USADMIN == 2) //Displays user's screen
    {
    A: //user's view
        int uprs;
        system("cls");
        //Selection for user
        cout << "============================\n WELCOME TO CAR PARKING \n============================\n";
        cout << "1.if you want to Park\n2.if you want to Depark\n3.Goto Admin-end\n4.About\n5.Exit\nYour Selection...:\n"; //menu
        cin >> uprs;

        if (uprs == 1) //Enables user to park his vehicle
        {
            //Program for parking is proceeding 

            int menu;
            int vehicle;
            int vehicle2;
            int x;
            time_t now = time(0);  //Displays current time
            tm* time1 = localtime(&now);
            cout << "Today's time:" << (time1->tm_hour) << ":" << (time1->tm_min) << ":" << (time1->tm_sec) << endl;
            for (x = 1; x <= 13; x++)
            {
                if (x > 12) //Bound to max limit of 12 vehicles parking slots
                {
                    //Displays message is no slot is free
                    cout << "No Space Avaliable" << endl;
                    system("pause");
                }
                else if (veh[x].prkingid == x) //Checks whether parking id is already given
                {
                    continue;
                }
                else
                {
                    time_t now = time(0);
                    tm* time1 = localtime(&now); //Displays current time
                    veh[x].prkingid = x;
                    cout << "Enter Car Registration (AAA-0000)" << endl;
                    cin >> veh[x].reg_num; //Takes input, registration number of the car
                E:
                    //Selection for user
                    cout << "Enter Vehicle Type\n1.Car\n2.Bike\n\nYour Selection...:" << endl;
                    cin >> vehicle;
                    if (vehicle == 1)//if 1 is entered vehicle is car
                    {
                        veh[x].veh_type = "car";
                    }
                    else if (vehicle == 2)//If you enter 2 the vehicle will be bike
                    {
                        veh[x].veh_type = "bike";
                    }
                    //if wrong number is pressed
                    else {
                        cout << "Invalid Selection Re check !! " << endl; goto E; //jumps back to selection
                    }
                    //entry time being stored in a variable
                    veh[x].in_h = (time1->tm_hour); veh[x].in_m = (time1->tm_min); veh[x].in_s = (time1->tm_sec);
                    cout << "Entry Time...:" << veh[x].in_h << ":" << veh[x].in_m << ":" << veh[x].in_s << endl;
                    cout << "YOUR PARKING ID IS " << x << "" << endl; //Displays parking ID
                    veh[x].hourin = in();
                    system("pause"); //Pauses the program
                }

                goto A; // Jumps back to beginning of user's screen
            }
        }
        else if (uprs == 2) //if 2 is pressed
        {
            //Program for deparking is proceeding 
            int prking;
            char quest;
            string type;
            float tot_time;
            cout << "Enter Parking Id....:" << endl; //enter the correct parking id to get your car deparked
            cin >> prking;
            if (prking == veh[prking].prkingid)//if parking id is correct or exist
            {
                //Confirmatory question
                cout << "Do you really want to depark?(y/n)" << endl;
                cin >> quest;
                if (quest == 'y') //If want to depark
                {
                    time_t now1 = time(0); //calculates time
                    tm* time2 = localtime(&now1);
                    ofstream fs("D://logs.txt", ios::out | ios::app); //Writes information onto the file

                    cout << "Parking Id...:" << veh[prking].prkingid << endl; //displays the parking id which program has generated while vehicle was being parked
                    cout << "Registration Number...:" << veh[prking].reg_num << endl; //displays the reg no
                    cout << "Vehicle Type...:" << veh[prking].veh_type << endl; //displays the vehicle type car/bike
                    //displays the time when car was parked
                    cout << "Entry Time...:" << veh[prking].in_h << ":" << veh[prking].in_m << ":" << veh[prking].in_s << endl;
                    veh[prking].hourout = out();
                    //displays the current time when car is being deparked
                    cout << "Exit Time...:" << (time2->tm_hour) << ":" << (time2->tm_min) << ":" << (time2->tm_sec) << endl;
                    //difftime calculates the difference of time when car is being deparked
                    //and when car was parked in seconds to calculate the amount
                    veh[prking].el_time = difftime(veh[prking].hourout, veh[prking].hourin) / 60; //"/60" converts the time to minute as function returns time in seconds
                    cout << "Total Time(In Minutes)" << veh[prking].el_time << endl; //displays the time after differentitation 
                    type = veh[prking].veh_type;
                    tot_time = veh[prking].el_time;
                    veh[prking].charges = fee(type, tot_time);
                    cout << "Total Charges Rs." << roundf(veh[prking].charges) << endl; //displays total charge
                    //Data of the vehicle is being entered in file
                    fs << endl;
                    fs << "Parking Id...:" << veh[prking].prkingid << endl;
                    fs << "Registration Number...:" << veh[prking].reg_num << endl;
                    fs << "Vehicle Type...:" << veh[prking].veh_type << endl;
                    fs << "Entry Time...:" << veh[prking].in_h << ":" << veh[prking].in_m << ":" << veh[prking].in_s << endl;
                    fs << "Exit Time...:" << (time2->tm_hour) << ":" << (time2->tm_min) << ":" << (time2->tm_sec) << endl;
                    fs << "Total Time(In Minutes)" << veh[prking].el_time << endl;
                    fs << "Total Charges Rs." << roundf(veh[prking].charges) << endl; //rounds off the price and returns 
                    fs << endl;
                    fs.close(); //closes the file
                    veh[prking].prkingid = 0;
                    veh[prking].reg_num = "";
                    veh[prking].veh_type = "";
                    veh[prking].hourin = 0;
                    veh[prking].hourout = 0;
                    veh[prking].el_time = 0;
                    veh[prking].charges = 0;
                    system("pause");
                    goto A;
                }
                else if (quest == 'n') //if no need to depark, then jumps back to A
                {
                    goto A;
                }
            }
            else
            {
                cout << "Invalid Id!!!" << endl; //If wrong id is entered display a warning message
                system("pause");
                goto A;
            }
        }
        else if (uprs == 3) //if 3 is pressed jump to admin screen
        {
            system("cls");
            goto C;
        }
        else if (uprs == 4) //displays short detail about this program
        {
            system("cls");
            cout << "\t\t\t\t\t===========================\n\t\t\t\t\t|||||||||||ABOUT|||||||||||\n\t\t\t\t\t===========================\n" <<
                "  This Car parking system is designed to facilitate user/admin." <<
                "This car park system saves time, money, space and\n" << "      simplifies the " <<
                "tedious task of parking. Provides, optimum solutions and smart parking system for you.\n" <<
                "       Lastly,this parking system satisfies your parking request at any place.Thank you for having us!\n\n" <<
                " Developed by:Ahsan Arshad, Arham Naeem & Aliyan Rehman\n\n";
            system("pause");
            system("cls");
            goto A;
        }
        else if (uprs == 5) //exits the program
        {
            exit(0);
        }
        else //if wrong number is pressed, warning message
        {
            cout << "Invalid Selection!!!" << endl;
            system("pause");
            goto A;
        }

    }
    //User view ends 
    //Choice for user/admin
    else if (USADMIN == 3)
    {
        exit(0);  //exits the program
    }
    else //warning message 
    {
        cout << "Invalid Id!!!" << endl;
        system("pause");
        system("cls");
        goto B; //jumps to beginning of the program
    }
}
//FUNCATIONS BEING USED
float fee(string type, float tot_time) //calulates the amount(total fee)
{
    float charges, minc, maxc, minb, maxb;
    minc = mnc; // minimum price for car
    maxc = mxc; // maximum price for car
    minb = mnb; // minimum price for bike
    maxb = mxb; // maximum price for bike

    if (type == "car")
    {


        if (tot_time < 180) //price,if car is parked for less than 3 hours
        {
            charges = (tot_time * minc); //multiplies difference of time with minc
            return charges;
        }
        else if (tot_time > 180) //if car is parked for more than 3 hours, doubles the price
        {
            charges = (tot_time * maxc);  //multiplies difference of time with maxc
            return charges;
        }
    }
    else if (type == "bike")

    {

        if (tot_time < 180) //price if bike is parked for less than 3 hours
        {
            charges = (tot_time * minb);  //multiplies difference of time with minb
            return charges;
        }
        else if (tot_time > 180)//if bike is parked for more than 3 hours, doubles the price
        {
            charges = (tot_time * maxb); //multiplies difference of time with maxb
            return charges;
            return charges;
        }

    }
}
int out() //displays time of when car is getting deparked
{
    time_t hourout;
    return time(&hourout);
}
int in() //displays time of when car got parked
{
    time_t hourin;
    return time(&hourin);
}
void file() //checks if file exist or not
{
    fstream files;
    files.open("D://logs.txt"); //opens file in D drive
    files.close();
    if (files.fail())
    {
        cout << "Log file doesn't exists" << endl;
    }
    else
    {
        system("notepad.exe D://logs.txt");
    }

}

void r_file()//Removes/deletes the file and all the data in it
{
    fstream files;
    files.open("D://logs.txt");
    files.close();
    if (files.fail())
    {
        cout << "Log file doesn't exists" << endl;
    }
    else
    {
        remove("D://logs.txt");
        cout << "Log Cleared!!" << endl;
    }

}

string password() //changes password
{
    cout << "New Password..>:" << endl;
    cin >> pass1;
    return "Password Changed"; //password changes

}
//END OF THE PROGRAM