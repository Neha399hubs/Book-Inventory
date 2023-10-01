#include<iostream>
#include<string>

using namespace std;

class Book {
	public:
		int id;
		string title;
		int count;
		
		Book(int bookId, const string& bookTitle, int bookCount)
		{
			id = bookId;
			title = bookTitle;
			count = bookCount;
		}
};

class Inventory {
	public:
		Book* books[100];
		int bookCount;
		
		Inventory() 
		{ 
		  bookCount = 0;
		}
		
		void addBook()
		{ if (bookCount < 100) 
		    { int bookId, bookCount;
			  string bookTitle;
		    
		      cout<<"Enter book Id: ";
		      cin>> bookId;
		      cout<<"Enter bookTitle: ";
		      cin.ignore();
		      getline(cin, bookTitle);
		      cout<<"Enter bookCount: ";
		      cin>>bookCount;
		      
			  books[bookCount++] = new Book(bookId, bookTitle, bookCount);
		      cout<<"Book added to inventory." << endl;
		    } 
		   else 
			{ 
		      cout<<"Inventory is full. Sorry, cannot add more books." << endl;
		    }
		}
		 
		void sellBook() 
		{ int bookId;
		  cout<<"Enter bookId to sell: ";
		  cin>> bookId;
		  
		  for(int i = 0; i < bookCount; i++) {
		 	if (books[i]->id == bookId)
		 	{ 
		 	   if (books[i]->count > 0 ) {
		 	   	    books[i]->count--;
		 	   	    cout<<"Book sold.Remaining Count: "<< books[i]->count << endl;
				}
				
			   else {
			   	    cout<<"Book is out of stock."<< endl;
			   }
			   	
			   return;
			}
	    }   
		 
		cout<< "Book not found in inventory."<<endl;
		  
		}
		
		void displayInventory() { 
		  cout<<"Inventory:" << endl;
		  for(int i = 0; i < bookCount; i++)
		  {
		  	cout<< "ID: " << books[i]->id << " | TITLE: " << books[i]->title << " | COUNT: " << books[i]->count << endl;
		  }
		}
		
		
};

int main()  {

 Inventory invent;
 /*Book book1(1, "abc", 10);
 Book book2(2, "wbc", 20);
 
 invent.addBook(&book1);
 invent.addBook(&book2);
 
 invent.displayInventory();*/
 
 
 char choice;
 do{
 	cout<<"OPTIONS:" <<endl;
 	cout<<"1. Add a book" <<endl;
 	cout<<"2. Sell a book" <<endl;
 	cout<<"3. Display Inventory" <<endl;
 	cout<<"4. Exit" <<endl;
 	cout<<"ENTER YOUR CHOICE: ";
 	cin>> choice;
 	
 	switch(choice) {
 		case '1':
 			invent.addBook();
 			break;
 		
 		case '2':
 			invent.sellBook();
 			break;
 			
 		case '3':
 			invent.displayInventory();
 			break;
 			
 		case '4':
 			cout<<"Exiting the Program."<<endl;
 			break;
 			
 		default:
 			cout<<"Invalid choice.Please try again."<<endl;
	 }
 	
 } while(choice!= 4);
  
 
  return 0;
  
}
  



