#include <iostream>
using namespace std;

//function prototypes
void displaymenu ();
void addbook ();
void displaybooks ();
int searchbook ();
void removebook ();


struct books
{
  string title;
  string author;
  int year;
};

books library[100];
int size = 0;

void
displaymenu ()
{
  cout << "---LIBRARY MANAGEMENT SYSTEM---\n";
  cout << "1.Add book\n";
  cout << "2.Display books\n";
  cout << "3.Search book\n";
  cout << "4.Remove book\n";
  cout << "5.Exit the program\n";
}

void
addbook ()
{
  books newbook;
  cout << "Enter the title of the book: ";
  cin >> newbook.title;
  cout << "Enter the name of the author: ";
  cin >> newbook.author;
  cout << "Enter the publication year: ";
  cin >> newbook.year;

  library[size] = newbook;
  size++;


}

void
displaybooks ()
{

  cout << " title\t author\t year\n";
  for (int i = 0; i < size; i++)
    {
      cout << library[i].title << "\t" << library[i].author << "\t" << library[i].year << "\n";

    }
}

int
searchbook ()
{
  string book;
  cout << " Enter the title of the book: ";
  cin >> book;
  for (int i = 0; i < size; i++)
    {
      if (book == library[i].title)
	{
	  return i;
	}
    }
  return -1;
}


int main ()
{
  int num;
  int index;

  do
    {

      displaymenu ();

      int choice;
      cin >> choice;

      switch (choice)
	{

	case 1:
	  addbook ();
	  break;

	case 2:
	  displaybooks ();
	  break;

	case 3:
	  index = searchbook ();
	  if (index == -1)
	    cout << "book does not exist";
	  else
	    cout << "book details: " << library[index].title << "\t" << library[index].author << "\t" << library[index].year << "\n";
	  break;

	case 4:
	  cout << "Exit. ";
	  break;
	  
	default:
	  cout << "Entered the wrong option. Try again.";


	}
      cout << "do you want to continue?\n";
      cout << "1.Yes\n";
      cout << "2.No\n";

      cin >> num;
    }
  while (num == 1);


  return 0;
}

