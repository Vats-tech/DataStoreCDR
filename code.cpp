#include <bits/stdc++.h>
#include<thread>
#include <fstream>
using namespace std;




/*------------- Creating a class --------------*/


class DataStore{
	public:

		std::map<string,string> Mymap; 				//		Data structure which will contain the key value pair

		void getData();						//		function to get Data from file into map

		void read();						//		Function to get read

		void create();						//		Function to write into file

		void Delete();						//		Function to delete from file

};









/*-------------------------------------- Get all data from file and store it in above decleared map -----------------------------------*/



void DataStore :: getData(){

	string myText;						// 		Creating a text string, which will be used to output the text file
	

	ifstream MyReadFile("freshwork.txt");			// 		Read from the text file
	
	while (getline (MyReadFile, myText)) {			//		Use a while loop together with the getline() function to read the file line by line
		  		
 		string key, value;				// 		key & value 
 			
    	std::stringstream ss(myText);				// 		Using stringstream to breaking the words or reading a stream of words
    	
    	if (ss >> key)						// 		Checking for key
    	{
      	if(ss >> value)						//		If key is present then look for Value
      	{      			
        	Mymap[key] = value; 				// 		Store both the key value pair in map
      	}
      	
  		}
  	}
  	
  	MyReadFile.close();					//  	Close the file
  	
 /* 	std::map<string,string> :: iterator it;
		//	Looping through all the available key-value pair
		for(it=Mymap.begin();it!=Mymap.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
		}
		cout<<endl;
*/

}








/*---------------------------------------------- Create Operation to add key-value pair in DataStoe -----------------------------------*/



void DataStore :: create(){
	
	getData();	//		Call the getData function to get recent data from file if new Data is added the it will update the above map 
	cout<<endl<<"Enter Key And Value To Add It in File"<<endl<<endl;
	string key,value;
	cin>>key;							//		Get input from user 
	cin>>value;
	
	if(value.size() > 16000){					//		Check if value is > 16kB or not 
	 
		cout<<endl<<"!==== Error - Please enter value of size < 16KB ====!"<<endl;
	}
	
	std::ifstream in("freshwork.txt", std::ios::binary | std::ios::ate);// 	 Open file in binary type to get size of file
	
	int fileSize = in.tellg();					//		Size of File
	
	in.close();							// 		Close the file
	
	if(fileSize >= 1073741274){					// 		Check if file size is > 1GB  
	
		cout<<endl<<"!==== ERROR - File Size Is Exceeding 1GB. Plz Delete Data From File ====!"<<endl;
		
		return;							// 		If file size greater than 1GB then show erro and then return
	}
	
	if(Mymap.find(key) == Mymap.end()){				//		Check if Key is already present in file if not then insert it in file
	
		std::ofstream MyFile;	
		MyFile.open("freshwork.txt",ios::app);			//		Open Existing File in append mode
		
		MyFile << key <<" " << value<<endl	;		//		Write into file
		
		MyFile.close();						//		Close the file
		cout<<endl<<"!====SUCCESS ==== key-value is added ====!"<<endl;
	}
	
	else{
		cout<<endl<<"!==== Error ::  Key - Value Pair already Exist ====!"<<endl;//	If key is already present in file then show error
	}
}








/*----------------------------------------------------- Read Operation to get value--------------------------------------------------- */




void DataStore :: read(){

	getData();						//		Get recent Data from file 
	
	if(Mymap.size() == 0){					//		If file is Empty  then Show proper error
		
		cout<<endl<<"!==== Error ::Your File is Empty Please Enter Data ====!"<<endl<<endl;
		
		return;
	}
	
	cout<<endl<<"Enter Key To Get Value"<<endl;
	string key;
	cin>>key;						//		Get key from user

	std::map<string,string> :: iterator it;			//		Initializing an iterator of above map to iterate through the value
	
	bool flag = false;
	
	for(it=Mymap.begin();it!=Mymap.end();it++){		//		Looping through all the available key-value pair
		
		if(it->first == key){				//		Check for match
		
			cout<<endl<<"Output ==== "<<it->second<<endl;	//		Print the value if key is found
			
			flag=true;
			
			break;			
		}
	}
	
	
	if(flag == false){ 					// 		If flag == false then key does not exist in file
	
		cout<<endl<<"Error :: This key value pair does not exist in file"<<endl;//		Show Valid Error
	}
		
}









/*------------------------------------------------------------- Delete Operation -------------------------------------------------------*/




void DataStore :: Delete(){
	cout<<endl<<"Enter Key To Delete It From File"<<endl<<endl;
	string key;
	cin>>key;								//		Get the key from user to delete it from file
	
	getData();								//		Get recent Updated data inside above decleared map
	
	
	if(Mymap.size() !=0 && Mymap.find(key) != Mymap.end()){			//		Check if file is not empty and key exist in the file
	
		Mymap.erase(key);						//		If exist then delete it from file
		cout<<endl<<"!====SUCCESS ==== key-value is deleted ====!"<<endl;
	}
	
	else{									//		If file size is zero Or key does not exist 
	
		cout<<endl<<"Error:: Key does not exist in file"<<endl;		//		Show valid Error
		return;
	}
	
	
	/*  After Deleting the key from temprory storage (map) Update the current Data in File*/
	
	std::ofstream MyFile;
	MyFile.open("freshwork.txt",ios::trunc);		// 		Open file in tranculated mode
	
	std::map<string,string> :: iterator it;	
	
	for(it= Mymap.begin();it!=Mymap.end();it++){
		
		MyFile<<it->first<<" "<<it->second<<endl;	//		Write the Current updated data inside file	
	}
	MyFile.close();									//		Close the file
	
}





/* ----------------------------------------OPERATIONS --- Choose what you want to perform -------------------------------------------*/



void Operations(){
	
	DataStore Object;						//		Make an Object of Class Dat6aStore	
	bool bExit = false;
    
	do								// 		Repeate the options until user exit himself 
	{
		cout<<endl<<"Choose From The Given Options-"<<endl;;
		cout<<"1 :: Create " << endl;				//		Chhose 1 for Creating or adding new data in file
		cout<<"2 :: Read " << endl;				//		Choose 2 for reading the value 
		cout<<"3 :: Delete "<< endl;				//		Choose 3 to delete the key&valye from file
		cout<<"4 :: Exit " << endl;				//		Chhose 4 to exit
		
		cout<<endl;
		
		int choice;
		cin>>choice;						//		Get the choice from user
	     switch(choice)
	     {
	          case 1:
	        		Object.create();			//		Calling create fun.
	          break;
	          
	          case 2:
	               Object.read();					//		Calling read fun.
	          break;
	          
	          case 3:
	               Object.Delete();					//		Callling Delete fn.
	          break;
	          
	          case 4:
	               bExit = true;					// 		Set flag -> true to exit
	          break;
	          
	          default:
	               cout << "Wrong Choice ! Please Choose again.";	//		If by mistake you entered the wrong value
	          break;
	     }
	     
	} while (!bExit);
}







/*-----------------------------------------------  MULTITHREADING----- THREAD 1   ---------------------------------------------------- */


void inside_thread_one(){						//		Function Pointer 1

	cout<<endl<<"This is -----		 Thread 1		---------"<<endl; // 		Show the User Current Thread
		
	Operations();							//		Call the operations fun. to perform diff. fun.
}





/*---------------------------------------------  MULTITHREADING----- THREAD 2   ----------------------------------------------------- */


void inside_thread_two(){						//		Function Pointer 2

	cout<<endl<<"This is ----- 		Thread 2		---------"<<endl;//		Show Current thread
	
	Operations();							//		Call the operations fun. to perform diff. fun.
}








/* ---------------------------------------- 						-----------------------------------							---------------------------------------*/


int main() {
	
	Operations();						//		Main Thread

	/*------Ask User if user want to use multithreading or not-----*/

	cout<<endl<<"If You Want To Use Multiple Thread Then Enter 1 Else Enter Any Value"<<endl;
	
	int yesOrno;
	
	cin>>yesOrno;
	
	
	
	if(yesOrno == 1){					//		If user want to perform multithreading 
	
		std::thread th1(inside_thread_one);		//		Launching thread using function pointer									
												
		th1.join();					// 		Wait for thread th1 to finish 
		
		std::thread th2(inside_thread_two);		//		Launching thread using function pointer	
		
		th2.join();					// 		Wait for thread th2 to finish 
	}

}

