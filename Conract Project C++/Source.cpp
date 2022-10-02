#include "Header.h"
#include "ContactCrud.h"
using namespace std;

int main() {
    
    ContactCrud crud;
    if (!crud.is_file_exist("user.txt") ) {
        crud.creatFile();
        crud.add("contact", "of", "Allahverdi");
    }
    
    menu();
    
   
  

    










}









//ifstream fin("user.txt");
    //string myText;
    ////fin.open("user.txt");
    //while (getline(fin, myText)) {
    //    // Output the text from the file
    //    cout << myText;
    //}