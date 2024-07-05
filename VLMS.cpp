#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
long long trans_id=1;
unordered_map<string,vector<string>> Admin_Data={{"Abc",{"123@abc","abc@gmail.com"}},{"Def",{"123@def","def@gmail.com"}},{"Xyz",{"123@xyz","xyz@gmail.com"}}};
unordered_map<string,vector<string>> Customer_Data={{"c1",{"123@c1","c1@gmail.com"}},{"c2",{"123@c2","c2@gmail.com"}}};
unordered_map<string,vector<string>> Vendor_Data={{"v1",{"123@v1","v1@gmail.com"}},{"v2",{"123@v2","v2@gmail.com"}},{"v3",{"123@v3","v3@gmail.com"}}};
unordered_map<string,vector<string>> Video_Data={{"vi1",{"comedy","2010","brahmi","2000","v1"}},{"vi2",{"horror","1986","abcd","4000","v2"}}};
unordered_map<long long,vector<string>> Transaction_Data={{1024,{"vi1","c1","2000"}},{1025,{"vi2","c2","4000"}}};
class Admin{
    //Inside Admin class;
    public:
    void AuthenticateAdmin(){
	    cout<<"Enter your UserName: ";
	    string username;
	    cout<<endl;
	    cin>>username;
	    cout<<"Please enter your Password: ";
	    string password;
	    cin>>password;
	    //Taking user name and password from user;
    	if(Admin_Data.find(username)==Admin_Data.end()||Admin_Data[username][0]!=password){
    	    //checking the validity of the user name and the password
    		cout<<"User not found"<<endl;
    		return ;
    	}
    	AdminDuties();
        //calling AdminDuties() funciton;
    }
    private:
    void AdminDuties(){
    	bool isexit=0;
    	while(true){
    		cout<<"Enter the operation you want to perform: "<<endl;
    		cout<<"1. Add Video"<<endl<<"2. Update Video"<<endl<<"3. Delete Video"<<endl<<"4. Generate Report"<<endl<<"5. Exit"<<endl;
    		int operation;
    		cin>>operation;
    		//To perform admin duties based on choice
    		switch(operation){
    			case 1 	: 	Add_Video(); 
    						break;
    			case 2 	: 	Update_Video();
    						break;
    			case 3 	: 	Delete_Video();
    						break;
    			case 4  :   Generate_Report();
    			            break;
    			case 5  :   isexit=1;
    						break;
    			default :	cout<<"Invalid Choice of Operation!"<<endl;
    						
    		}
    		if(isexit)
    			break;
    	}
    }
    void Generate_Report(){
        cout<<"title \t genre \t year \t artist \t price \t vendor  "<<endl;
        for(auto [k,v]:Video_Data){
            cout<<k<<"\t";
            for(auto i:v){
                cout<<i<<"\t";
            }
            cout<<endl;
        }
    }
    void Add_Video(){
    	cout<<"Enter Video name: ";
    	//Taking video data from the user;
    	string viname,genre,year,artist,price,vendor;
    	cin>>viname;
    	cout<<endl;
    	cout<<"Enter Video genre: ";
    	cin>>genre;
    	cout<<endl;
    	cout<<"Enter year: ";
    	cin>>year;
    	cout<<endl;
    	cout<<"Enter artist: ";
    	cin>>artist;
    	cout<<endl;
    	cout<<"Enter price: ";
    	cin>>price;
    	cout<<endl;
    	cout<<"Enter Vendor name: ";
    	cin>>vendor;
    	cout<<endl;
    	if(Video_Data.find(viname)!=Video_Data.end()){
    		cout<<"Video already exists"<<endl;
    		//Checking the video existence;
    		return ;
    	}
    	//Adding the video
    	Video_Data[viname]={genre,year,artist,price,vendor};
    	cout<<"Video added Successfully"<<endl;
    	
    }
    void Update_Video(){
    	string vname;
    	cout<<"Enter the Video name: ";
    	cin>>vname;
    	//Checking the video existence;
    	if(Video_Data.find(vname)==Video_Data.end()){
    		cout<<"Video not found"<<endl;
    		return ;    	}
    	int choice;
    	cout<<"1. Update Price"<<"2. Update Vendor Name"<<endl;
    	cin>>choice;
    	if(choice==1){
    		string price;
    		cout<<"Enter new price: ";
    		//Updating the price
    		cin>>price;
    		Video_Data[vname][3]=price;
    	}
    	else{
    		string vename;
    			//Updating the vendor name
    		cout<<"Enter new Vendor Name: ";
    		cin>>vename;
    		Video_Data[vname][4]=vename;
    	}
    	
    }
    void Delete_Video(){
    	cout<<"Enter Video name: ";
    	string vname;
    	cin>>vname;
    	//Checking the video existence;
    	if(Video_Data.find(vname)==Video_Data.end())
    	{
    		cout<<"Video not found"<<endl;
    		return;
    	}
    	//Deleting video
    	Video_Data.erase(vname);
    	cout<<"Video deleted successfully"<<endl;
    }
};
class Vendor{
    //vendor class
    public:
    void AuthenticateVendor(){
        //Authenticating the vendor
    	cout<<"Enter your UserName: ";
    	string username;
    	cout<<endl;
    	cin>>username;
    	cout<<"Please enter your Password: ";
    	string password;
    	cin>>password;
    	//checking the validity of username and password;
    	if(Vendor_Data.find(username)==Vendor_Data.end()||Vendor_Data[username][0]!=password){
    		cout<<"User not found"<<endl;
    		return ;
    	}
    	VendorDuties(username);
    	//calling vendor duties;
    }
    private:
    void VendorDuties(string username){
    	bool isexit=0;
    	while(true){
    		cout<<"Enter the operation you want to perform: "<<endl;
    		cout<<"1. Add Video"<<endl<<"2. Exit"<<endl;
    		int operation;
    		cin>>operation;
    		//performing vendor duties based on given choice
    		switch(operation){
    			case 1 	: 	Add_Video();
    						break;
    			case 2 	: 	isexit=1;
    						break;
    			default :   cout<<"Invalid Choice of Operation!"<<endl;
    		}
    		if(isexit)
    			break;
    	}	
    	
    }
    void Add_Video(){
    	cout<<"Enter Video name: ";
    	string viname,genre,year,artist,price,vendor;
    	cin>>viname;
    	cout<<endl;
    	cout<<"Enter Video genre: ";
    	cin>>genre;
    	cout<<endl;
    	cout<<"Enter year: ";
    	cin>>year;
    	cout<<endl;
    	cout<<"Enter artist: ";
    	cin>>artist;
    	cout<<endl;
    	cout<<"Enter price: ";
    	cin>>price;
    	cout<<endl;
    	cout<<"Enter Vendor name: ";
    	cin>>vendor;
    	cout<<endl;
    	if(Video_Data.find(viname)!=Video_Data.end()){
    		cout<<"Video already exists"<<endl;
    		return ;
    	}
    	//Adding the video
    	Video_Data[viname]={genre,year,artist,price,vendor};
    	cout<<"Video added Successfully"<<endl;
    	
    }
    
};
class Customer{
    public:
    //Customer class
    void AuthenticateCustomer(){
    	cout<<"Enter your UserName: ";
    	string username;
    	cout<<endl;
    	cin>>username;
    	cout<<"Please enter your Password: ";
    	string password;
    	cin>>password;
    	if(Customer_Data.find(username)==Customer_Data.end()||Customer_Data[username][0]!=password){
    		cout<<"User not found, Please check your details."<<endl;
    		return ;
    	}
    	CustomerDuties(username); //calling customer duties;
    }
    private:
    void CustomerDuties(string username){
    	bool isexit=0;
    	while(true){
    		cout<<"Enter the operation you want to perform: "<<endl;
    		cout<<"1. Search a Video"<<endl<<"2. Visit all Videos"<<endl<<"3. Purchase a Video"<<endl<<"4. Get Invoice"<<endl<<"5. Exit"<<endl;
    		int operation;
    		cin>>operation;
    		//performing vendor duties based on given choice
    		switch(operation){	
    			case 1 	: 	Search_a_Video();
    						break;
    			case 2 	: 	Visit_All_Videos();
    						break;
    			case 3 	: 	Purchase_Video(username);
    						break;
    			case 4 	: 	Get_Invoice();
    						break;
    			case 5  :   isexit=1;
    						break;
    			default :	cout<<"Invalid Choice of Operation!"<<endl;
    						
    		}
    		//exiting the duties if choice 5 is pressed
    		if(isexit)
    			break;
    	}
    }
    void Search_a_Video()
    {
    	cout<<"Enter the video name to be searched:"<<endl;
    	string vname;
    	cin>>vname;
    	//searching a video
    	if(Video_Data.find(vname)==Video_Data.end())
    	{
    	    //Handling edge case;
    		cout<<"Video not found"<<endl;
    		return;
    	}
    	else
    	cout<<"Video found";
    }
    void Visit_All_Videos()
    {
        //printing the video data
    	for(auto [k,v]: Video_Data)
    	{
    		cout<<k<<": ";
    		for(auto i:v)
    		{
    			cout<<i<<" ";
    		}
    		cout<<endl;
    	}
    }
    void Purchase_Video(string un)
    {
    	cout<<"Enter the video name to be purchased:";
    	string vname;
    	cin>>vname;
    	//purchasing a video 
    	Transaction_Data.insert({trans_id,{vname,un,Video_Data[vname][3]}});
    	//printing transaction id and updating transaction table
    	cout<<trans_id++<<endl;
    }
    void Get_Invoice()
    {
    	cout<<"Enter transaction id:";
    	//printing the invoice
    	cin>>trans_id;
    	for(auto i:Transaction_Data[trans_id])
    	{
    		cout<<i<<endl;
    	}
    }
    
};


int  main()
{
	cout<<"Welcome to Video Library Services!"<<endl;
	bool isexit=false;
	while(true&&!isexit){
		cout<<"Please select your role"<<endl;
		cout<<"1. Administrator."<<endl<<"2. Vendor."<<endl<<"3. Customer."<<endl<<"4. Exit"<<endl;
		int role;
		cin>>role;
		//Identifying the user role;
		switch(role){
			case 1 	: 	Admin a;
			            a.AuthenticateAdmin(); //creating objects for respective class roles and performing authentication
						break;
			case 2 	: 	Vendor v;
			            v.AuthenticateVendor();
						break;
			case 3 	: 	Customer c;
			            c.AuthenticateCustomer();
						break;
			case 4  :   isexit=true;
				    break; 
		    default :	cout<<"Invalid Role . Please try again!"<<endl; //Handling invalid roles;
						
		}
	}
	
}
