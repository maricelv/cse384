#include "books.h"

BookCollection::BookCollection(): startId_(1000)
{}


// HW # 5: excercise: write a memmber function to Find a book in the collection based on its Id
// finish the function below
Book BookCollection::FindBook(int id)
{
  // declare an object in the books class
   Book b;
  // set the book id to -1 to mark 
   b.BookId(-1);
  // iterate through the books and check if the book id is equal to the id input
   for(int i =0; i < books.size(); i++) {
	   if (books[i].BookId() == id ) {
		   std::cout << "The book is found " << std::endl;
	   return books[i];
	   }
   }
   std::cout << "The book is not found  " << std::endl;
    /*  note returns copy of b */
}

//HW # 5: excercise: write a memmber function to Delete a book based on its Id
bool BookCollection::DeleteBook(int id)
{
  /* implement the method here */
  // iterate through the books and check if the id matches the input id
  for (int i =0; i < books.size(); i++) {
	  if (books[i].BookId() == id) {
		  // erase the book by giving the first position, then the last position
		  books.erase(books.begin() + i, books.begin() + (i+1));
          return true;
	  }
  }
  std::cout << "Book not available" << std::endl;
  return false;
}

void BookCollection::AddToCollection(const Book& book)
{
   books.push_back(book);
}

int BookCollection::CollectionLength() 
{
   return books.size();
}

std::ostream& operator << (std::ostream& outs, const Book& book)
{
   outs << "BookId   : " << book.BookId() << std::endl;
   outs << "Author   : " << book.author() << std::endl;
   outs << "Title    : " << book.title()  << std::endl;
   outs << "copyright: " << book.copyright() << std::endl;
   outs << "rating   : " << book.rating() << std::endl;
   if(book.available())
     outs << "Available" << std::endl;
   else
     outs << "Not Available" << std::endl;

   return outs;
}


void BookCollection::ListCollection()
{
   for(int i = 0; i < books.size(); ++i)
   {
     std::cout << books[i] << std::endl;
   }
}


void BookCollection::ReadCollectionItems(std::istream& ins)
{
   try
   {
      Book b;
    
      if(&ins == &std::cin) std::cout << "Enter Author Full Name: ";
      getline(ins, b.author_);

      if(&ins == &std::cin) std::cout << "Enter Book Title      : ";
      getline(ins, b.title_);
  
      std::string temp;
      if(&ins == &std::cin) std::cout << "Enter Copyright (year): ";
      getline(ins, temp);
      b.copyright_ = std::stoi(temp);
   
      if(&ins == &std::cin) std::cout << "Enter Rating (1-10)   : ";
      getline(ins, temp);
      b.rating_ = std::stoi(temp);

      if(&ins == &std::cin) std::cout << "Is Book available?    : ";
      getline(ins, temp);
      if(std::tolower(*temp.c_str()) == 'y')
        b.avail_ = true;
      else
        b.avail_ = false;

       //generate the bookID and add to the collection
       b.BookId(startId_ + books.size());
       AddToCollection(b);
    }
    catch(...)
    {
      //swallow all exceptions for now
    }
}


#ifdef _TEST_BOOK_COLLECTION

int main()
{
   //test code for the package should go here: the test stub
   return 0;
}

#endif 




