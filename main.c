#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//car properties
double CIF;//cost insurance freight
int SC;//sitting capacity
double GW;//tonnes
double EC;//cc
double AOC;//Derived from the year of manufacturer

//declaring tax rates
double ID;
double VAT;
double WHT;
double IL = 150000;//Infrastructure levy
double SD = 35000;//Stamp Duty
double FF = 20000;//Form Fees
double ED = 200000;//Excise Duty

//calculating and assigning the registration fee
double R;
double Registration[] = {300000 , 700000};
int Plate_System;
void registration_tax(){//calculating the registration tax basing on the plate system

    R = Registration[ Plate_System - 1 ];

}

int age;

//Taxes imposed on transportation and border crossing
double road_tolls;
double border_fees;

int bond_days;//number of days spent in the bond
double bond_tax;

double additional_seat_cost;
double weight_cost;
double Engine_capacity_cost;

void CIF_request()
{
    //asking user to input CIF as this was not declared in tasks for code to accomplish.
    printf( "\nWhat is the Cost Insurance Freight(CIF) of the vehicle?\n" );
    scanf( "%Lf" , &CIF );
}

void Transport_type_Request_plus_tax_imposed()
{
    //selection of mode of transportation and assigning of tax involved
    int mode;
    printf("\nPlease select a mode of transportation for this vehicle.\n1.Carrier Bed Vehicle\n2.Vehichle itself driven into the country.\n");
    scanf( "%d" , &mode );

    switch(mode){
case 1:
    road_tolls = 0.5 * CIF;
    border_fees = 0.015 *CIF;
case 2:
    road_tolls = 0;
    border_fees = 0.015 *CIF;
    }
}

void Bond_days_request_plus_tax_imposed()
{
    //using days spent in bond to calculate bond tax
    printf( "\nHow many days has this car spent in the bond?\n" );
    scanf( "%d" , &bond_days );
    bond_tax = bond_days * 15000;
}

void output_tax_info()
{

     printf( "\nThis car is subjected to\nImport Duty Tax--------- %Lf\nValue Added Tax--------- %Lf\nWitholding Tax---------- %Lf\nInfrastructure Levy----- %Lf\t\t\t( PLEASE NOTE THAT THIS VALUE VARIES WITH AGE OF CAR )\nStamp Duty Tax---------- %Lf\nForm Fees--------------- %Lf\nExcise Duty Tax--------- %Lf\nRegistration Tax-------- %Lf\nRoad toll fee----------- %Lf\nBorder fees------------- %Lf\nSitting capacity fee---- %Lf\nWeight tax-------------- %Lf\nEngine capacity cost---- %Lf \n\n" , ID,VAT,WHT,IL,SD,FF,ED,R,road_tolls,border_fees,additional_seat_cost,weight_cost,Engine_capacity_cost );

}

void ambulance_info()
{
    ID = 0;
    VAT = 0;
    WHT = 0;
    SD = 35000;//Stamp Duty
    FF = 20000;//Form Fees
    ED = 200000;//Excise Duty

    Plate_System = 2;

    printf( "\nWhat is the age of this ambulance?\t\t\tPLEASE INPUT A NUMBER OF YEARS\n" );
    scanf( "%d" , &age );
    if ( age > 10 ){
        IL = 0.15 * CIF;
    }else{
        IL = IL;
    }

    registration_tax();

    output_tax_info();

    //remember to add the zero additional taxes.
}

void estate_info()
{
//standard taxes
    ID =(CIF * 0.25);  //import duty
    VAT = 0.18 * CIF;  //Value Added Tax
    WHT = 0.06 * CIF;  //Withholding tax
    IL = 150000;       //Infrastructure levy

//mandatory taxes
    SD = 35000;        //Stamp Duty
    FF = 20000;        //Form Fees
    ED = 200000;       //Excise Duty

    printf( "\nWhat is the Plate system of this estate vehichle?\n1.Analog Plate System (APS)\n2.Digital Plate System(DPS)\n" );
    scanf( "%d" , &Plate_System );
    printf( "\nWhat is the sitting capacity of the vehicle\t\t\tPLEASE INPUT A NUMBER OF SEATS\n" );
    scanf( "%d" , &SC );
    printf( "\nWhat is the gross weight of the vehicle?\n" );
    scanf( "%Lf" , &GW );
    printf( "\nWhat is the engine capacity of the vehicle\t\t\tPLEASE INPUT A NUMBER OF CCs\n" );
    scanf( "%d" , &EC );
    printf( "\nWhat is the age of the vehicle?\n" );
    scanf( "%d" , &age );

//additional taxes for estate vehichles
    if ( SC > 5 ){//extra seats
        double extra_seats = (double) SC - 5;
        additional_seat_cost = extra_seats * 250000;
    }

    if ( GW < 1500 ){//different weight classes
        weight_cost = 0.02 * CIF;
    }else if ( 1500 < GW < 2000 ){
        weight_cost = 0.05 * CIF;
    }else if ( GW > 2000 ){
        weight_cost = 0.1 * CIF;
    }

    if ( EC < 1800 ){//different engine capacities
        Engine_capacity_cost = 0.025 * CIF;
    }else{
        Engine_capacity_cost = 0.05 * CIF;
    }

    if( age > 10 ){
        IL = IL + 0.15 * CIF;
    }else if( 10 > age > 5 ){
        IL = IL + 0.05 * CIF;
    }else {
        IL = IL + 0.01 * CIF;
    }

    R = Registration[Plate_System-1];

    output_tax_info();
}

void sedan_info()
{
//standard taxes
    ID = 0.25 * CIF;
    VAT = 0.18 * CIF;
    WHT = 0.06 * CIF;
    IL = 150000;

//mandatory taxes
    SD = 35000;
    FF = 20000;
    ED = 200000;

    Plate_System = 2;
    registration_tax();
    printf( "\nWhat is the gross weight of the vehicle?\n" );
    scanf( "%d" , &GW );
    printf( "\nWhat is the engine capacity of the vehicle\t\t\tPLEASE INPUT A NUMBER OF CCs\n" );
    scanf( "%d" , &SC );
    printf( "\nWhat is the age of this ambulance?\t\t\tPLEASE INPUT A NUMBER OF YEARS\n" );
    scanf( "%d" , &age );

    //additional taxes

    if ( GW < 1500 ){//different weight classes
        weight_cost = 0.02 * CIF;
    }else if ( 1500 < GW < 2000 ){
        weight_cost = 0.1 * CIF;
    }else if ( GW > 2000 ){
        weight_cost = 0.15 * CIF;
    }

    if ( EC < 1500 ){//different engine capacities
        Engine_capacity_cost = 0.025 * CIF;
    }else if ( 1500 < EC < 2000 ){
        Engine_capacity_cost = 0.05 * CIF;
    }else{
        Engine_capacity_cost = 0.1 * CIF;
    }

    if ( age > 15 ){
        printf( "!!!WARNING!!!\nYou are not allowed to bring this vehicle into this country.\n\n" );
        return 0;
    }else if( 15 > age > 10 ){
        IL = IL + 0.1 * CIF;
    }else if( 10 > age > 5 ){
        IL = IL + 0.05 * CIF;
    }else {
        IL = IL + 1.5 * CIF;
    }

    output_tax_info();
}

void SUV_info()
{
//standard taxes
    ID = 0.25 * CIF;
    VAT = 0.18 * CIF;
    WHT = 0.06 * CIF;
    IL = 150000;

//mandatory taxes
    SD = 35000;
    FF = 20000;
    ED = 200000;

    Plate_System = 1;
    registration_tax();

    printf( "\nWhat is the sitting capacity of the vehicle\t\t\tPLEASE INPUT A NUMBER OF SEATS\n" );
    scanf( "%d" , &SC );
    printf( "\nWhat is the gross weight of the vehicle?\n" );
    scanf( "%Lf" , &GW );
    printf( "\nWhat is the age of the vehicle?\n" );
    scanf( "%d" , &age );

    //setting additional taxes
    if ( SC > 5 ){//extra seats
        int extra_seats = SC - 5;
        additional_seat_cost = (double)extra_seats * 350000;
    }

    if ( GW > 5000 ){
        weight_cost = 0.15 * CIF;
    }else {
        weight_cost = 0 * CIF;
    }

    if ( age > 15 ){
        printf( "!!!WARNING!!!\nYou are not allowed to bring this vehicle into this country.\n\n" );
        return 0;
    }else if( age > 10 ){
        IL = IL + 0.25 * CIF;
    }else if( 10 > age > 5 ){
        IL = IL + 0.15 * CIF;
    }else {
        IL = IL + 0.01 * CIF;
    }

    output_tax_info();
}

void Trailer_info()
{
//standard taxes
    ID = 0.25 * CIF;
    VAT = 0.18 * CIF;
    WHT = 0.06 * CIF;
    IL = 150000;

//mandatory taxes
    SD = 35000;
    FF = 20000;
    ED = 200000;

    printf( "\nWhat is the Plate system of this estate vehichle?\n1.Analog Plate System (APS)\n2.Digital Plate System(DPS)\n" );
    scanf( "%d" , &Plate_System );
    registration_tax();
    printf( "\nWhat is the gross weight of the vehicle?\n" );
    scanf( "%Lf" , &GW );
    printf( "\nWhat is the engine capacity of the vehicle\t\t\tPLEASE INPUT A NUMBER OF CCs\n" );
    scanf( "%d" , &EC );
    printf( "\nWhat is the age of the vehicle?\n" );
    scanf( "%d" , &age );

    if ( GW < 15000 ){
        weight_cost = 0.05 * CIF;
    }else if ( 15000 < GW < 20000) {
        weight_cost = 0.15 * CIF;
    }else {
        weight_cost = 0.25 * CIF;
    }

    if ( EC < 1500 ){//different engine capacities
        Engine_capacity_cost = 0.025 * CIF;
    }else if ( 1500 < EC < 2000 ){
        Engine_capacity_cost = 0.05 * CIF;
    }else{
        Engine_capacity_cost = 0.1 * CIF;
    }

    if ( age > 15 ){
        printf( "!!!WARNING!!!\nYou are not allowed to bring this vehicle into this country.\n\n" );
        return 0;
    }else if( 15 > age > 10 ){
        IL = IL + 0.1 * CIF;
    }else if( 10 > age > 5 ){
        IL = IL + 0.05 * CIF;
    }else {
        IL = IL + 1.5 * CIF;
    }

    output_tax_info();
}

void Taxes_per_type()
{
//making a choice of car
    printf("\nWhat Vehicle are you interested in?\n1.Ambulance\n2.Estate\n3.Sedan\n4.Sports Utility Vehicle (SUV)\n5.Trailer\n");

    int car_choice;

    scanf( "%i" , &car_choice );

    switch (car_choice){

case 1 ://ambulance taxes
    CIF_request();
    Transport_type_Request_plus_tax_imposed();
    Bond_days_request_plus_tax_imposed();
    ambulance_info();
    break;

case 2 :
    CIF_request();
    Transport_type_Request_plus_tax_imposed();
    Bond_days_request_plus_tax_imposed();
    estate_info();
    break;

case 3 :
    CIF_request();
    Transport_type_Request_plus_tax_imposed();
    Bond_days_request_plus_tax_imposed();
    sedan_info();
    break;

case 4 :
    CIF_request();
    Transport_type_Request_plus_tax_imposed();
    Bond_days_request_plus_tax_imposed();
    SUV_info();
    break;

case 5 :
    CIF_request();
    Transport_type_Request_plus_tax_imposed();
    Bond_days_request_plus_tax_imposed();
    Trailer_info();
    break;

default:
    printf("\n!!!!WARNING!!!!!That is not a valid choice, please select a valid option from the list, Lets try that again.\n\n");
    Taxes_per_type();
    }
//basing on choice of car, selecting functions to run to generate and output taxes

    }

void end_of_Payable_Tax(){

    printf("\n\nWould you like to :\n1.Look at the tax info for another car.\n2.Go to the start menu.\n3.Exit the program.\n");
    int repeat_option;
    scanf( "%d" , &repeat_option );
    switch(repeat_option){
case 1:
    Payable_tax();
    break;
case 2:
    main();
    break;
case 3:
    return 0;
    break;
default:
    printf("That is not a valid option, please select a valid one, Lets try that again:\n");
    break;

    }
}

void Payable_tax()//a function to output all the individual taxes payable by the importer
{
    printf("\nFor what vehicle would you like to see information?\n1.Ambulance\n2.Estate\n3.Sedan\n4.Sports Utility Vehicle (SUV)\n5.Trailer\n");
    int car_info_choice;
    scanf( "%d" , &car_info_choice );

    switch(car_info_choice){

case 1:
    printf("\nThis car is subjected to ---\nImport Duty tax-----------------------------0\nValue Added Tax-----------------------------0\nWithholding Tax ----------------------------0\nInfrastructure Levy--AGE > 10Years----------15%% of CIF\n                   --AGE < 10Years----------150000\nStampDuty-----------------------------------35000\nFF------------------------------------------20000\nExcise Duty---------------------------------200000\nRegistration--------------------------------700000\nTransport cost-------Carrier Bed Vehicle----Border fees(1.5%% of CIF) plus Road Tolls(0.5%% of CIF)\n                   --Driven Into Country----Border fees only(1.5%% of CIF)");
    end_of_Payable_Tax();
    break;
case 2:
    printf("\nThis car is subjected to ---\nImport Duty tax-----------------------------25%% of CIF\nValue Added Tax-----------------------------18%% of CIF\nWithholding Tax ----------------------------6%% of CIF\nInfrastructure Levy-------------------------150000 + additional age tax --between 1 & 5 years----5%% of CIF\n\t\t\t\t\t\t\t\t\t--between 5 & 10 years---5%% of CIF\n\t\t\t\t\t\t\t\t\t--above 10 years---------15%% of CIF\nStampDuty-----------------------------------35000\nFF------------------------------------------20000\nExcise Duty---------------------------------200000\nRegistration------APS-----------------------300000\n                --DPS-----------------------700000\nSitting capacity > 5------------------------250000 per extra seat\nVehicle weight----below 1500 tons-----------2%% of CIF value\n                --between 1500 & 2000 tons -5%% of CIF value\n                --above 2000 tons ----------10%% of CIF value\nEngine Capacity---below 1800 CC-------------2.5%% of CIF\n                --above 1800CC--------------5%% of CIF\n\n");
    end_of_Payable_Tax();
    break;
case 3:
    printf("\nThis car is subjected to ---\nImport Duty tax-----------------------------25%% of CIF\nValue Added Tax-----------------------------18%% of CIF\nWithholding Tax ----------------------------6%% of CIF\nInfrastructure Levy-------------------------150000 + additional age tax --below 5 years----------1%% of CIF\n\t\t\t\t\t\t\t\t\t--between 5 & 10 years---5%% of CIF\n\t\t\t\t\t\t\t\t\t--between 10 & 15 years--10%% of CIF\n\t\t\t\t\t\t\t\t\t--above 15 years---------!CANNOT BE IMPORTED!\nStampDuty-----------------------------------35000\nFF------------------------------------------20000\nExcise Duty---------------------------------200000\nRegistration--------------------------------700000\nVehicle weight----below 1500 tons-----------2%% of CIF value\n                --between 1500 & 2000 tons--10%% of CIF value\n                --above 2000 tons ----------15%% of CIF value\nEngine Capacity---below 1500 CC-------------2.5%% of CIF\n                --between 1500 & 2000 CC ---5%% of CIF\n                --above 2000CC--------------10%% of CIF\n\n");
    end_of_Payable_Tax();
    break;
case 4:
    printf("\nThis car is subjected to ---\nImport Duty tax-----------------------------25%% of CIF\nValue Added Tax-----------------------------18%% of CIF\nWithholding Tax ----------------------------6%% of CIF\nInfrastructure Levy-------------------------150000 + additional age tax --between 1 & 5 years----1%% of CIF\n\t\t\t\t\t\t\t\t\t--between 5 & 10 years--15%% of CIF\n\t\t\t\t\t\t\t\t\t--above 10 years---------25%% of CIF\nStampDuty-----------------------------------35000\nFF------------------------------------------20000\nExcise Duty---------------------------------200000\nRegistration--------------------------------300000\nSitting capacity > 5------------------------350000 per extra seat\nVehicle weight----below 5000 tons-----------EXEMPTED FROM CHARGE.\n                --above 5000 tons ----------15%% of CIF value\n");
    end_of_Payable_Tax();
    break;
case 5:
    printf("\nThis car is subjected to ---\nImport Duty tax-----------------------------25%% of CIF\nValue Added Tax-----------------------------18%% of CIF\nWithholding Tax ----------------------------6%% of CIF\n\nInfrastructure Levy-------------------------150000 + additional age tax --below 5 years----------1.5%% of CIF\n\t\t\t\t\t\t\t\t\t--between 5 & 10 years---5%% of CIF\n\t\t\t\t\t\t\t\t\t--between 10 & 15 years--10%% of CIF\n\t\t\t\t\t\t\t\t\t--above 15 years---------!CANNOT BE IMPORTED!\nStampDuty--------------------------------------35000\nFF---------------------------------------------20000\nExcise Duty------------------------------------200000\nRegistration------APS--------------------------300000\n                --DPS--------------------------700000\nVehicle weight----below 15000 tons-------------5%% of CIF value\n                --between 15000 & 20000 tons --15%% of CIF value\n                --above 20000 tons ------------25%% of CIF value\nEngine Capacity---below 15000 CC---------------2.5%% of CIF\n                --between 15000 & 20000 CC ----5%% of CIF\n                --above 20000CC----------------10%% of CIF\n\n");
    end_of_Payable_Tax();
    break;
default:
    printf("\nThat is not a valid choice, Please enter a valid choice, Lets try that again:\n\n");
    Payable_tax();
    break;
    }
}

void main()//navigating through the categories of tasks our application is capable of carrying out.
{
    int category;
    printf("\nPlease select a category to view:\n1.Taxes Per Type\n2.Attached information and corresponding Individual taxes payable for each vehicle.\n");
    scanf ( "%d" , &category );

    switch(category){
case 1 :
    Taxes_per_type();
    break;
case 2 :
    Payable_tax();
    break;
default:
    printf( "\n!!!!WARNING!!!!!That is not a valid choice, please select a valid option from the list, Lets try that again.\n\n" );
    main();
    break;
    }
}
