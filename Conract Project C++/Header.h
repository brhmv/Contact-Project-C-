#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct Contact
{
    string name;
    string surname;
    string pnumber;

};


struct ContactCrud {

    void creatFile()// for creating file but it ovveride the existing file if the file exist
    {
        ofstream MyWriteFile("user.txt");
        MyWriteFile.close();
    }
    void add(string name, string surname, string phonenumber) //adds datas to existing file
    {

        string filename("user.txt");
        ofstream file_out;

        file_out.open(filename, std::ios_base::app);
        file_out << name + " " + surname + " " + phonenumber + '%' << endl;
    }

    void read() //reads all datas from file
    {

        string myText;
        ifstream MyReadFile("user.txt");
        Contact user;
        int index = 0;
        int count = 0;
        while (getline(MyReadFile, myText)) {

            for (char x : myText) {
                if (x == ' ') {

                    count++;

                }
                if (x == '%') {
                    index++;
                    cout << "Id:";
                    cout << index;
                    cout << " ";
                    cout << user.name;
                    cout << user.surname;
                    cout << user.pnumber << endl;

                    user.name = "";
                    user.surname = "";
                    user.pnumber = "";
                    count = 0;

                }


                if (count == 0) {
                    if (x == '%') {

                        continue;
                    }
                    user.name += x;
                }

                else if (count == 1) {
                    user.surname += x;
                }
                else if (count == 2) {

                    user.pnumber += x;

                }

            }

        }
        MyReadFile.close();


    }

    void read(string search)  // reads all spesific datas based on name,surname,phonenumber, from file
    {

        string myText;
        ifstream MyReadFile("user.txt");
        Contact user;
        int count = 0;
        int delet_line = 0;
        while (getline(MyReadFile, myText)) {

            for (char x : myText) {
                if (x == ' ') {

                    count++;

                }
                if (x == '%') {
                    delet_line++;
                    string arry[] = { user.name,user.surname,user.pnumber };
                    for (string z : arry) {
                        if (z == search) {
                           
                                cout << "Id:";
                                cout << delet_line;
                                cout << " ";
                            
                            cout << user.name;
                            cout << user.surname;
                            cout << user.pnumber << endl;
                        };

                    }

                    user.name = "";
                    user.surname = "";
                    user.pnumber = "";
                    count = 0;

                }


                if (count == 0) {
                    if (x == '%') {

                        continue;
                    }
                    user.name += x;
                }

                else if (count == 1) {
                    user.surname += x;
                }
                else if (count == 2) {

                    user.pnumber += x;



                }

            }

        }
        MyReadFile.close();


    }


    Contact readId(int Id) {

        string myText;
        ifstream MyReadFile("user.txt");
        Contact user;
        string z;
        int indexId = 0;
        int count = 0;
        while (getline(MyReadFile, myText)) {

            for (char x : myText) {
                if (x == ' ') {

                    count++;

                }
                if (x == '%') {
                    indexId++;
                    if (indexId == Id) {

                        Contact userId;
                        userId.name = user.name;
                        userId.surname = user.surname;
                        userId.pnumber = user.pnumber;

                        return userId;
                    }


                    user.name = "";
                    user.surname = "";
                    user.pnumber = "";
                    count = 0;

                }


                if (count == 0) {
                    if (x == '%') {

                        continue;
                    }
                    user.name += x;
                }

                else if (count == 1) {
                    user.surname += x;
                }
                else if (count == 2) {

                    user.pnumber += x;

                }
            }
        }
        MyReadFile.close();
    }

    /////////////////////////////Delete spesific

// Delete n-th line from given file
    void delete_line(int delet_Id)
    {
        // open file in read mode or in mode
        ifstream is("user.txt");

        // open file in write mode or out mode
        ofstream ofs;
        ofs.open("temp.txt", ofstream::out);

        // loop getting single characters
        char c;
        int line_no = 1;
        while (is.get(c))
        {
            // if a newline character
            if (c == '\n')
                line_no++;

            // file content not to be deleted
            if (line_no != delet_Id)
                ofs << c;
        }

        // closing output file
        ofs.close();

        // closing input file
        is.close();

        // remove the original file
        remove("user.txt");

        // rename the file
        if (rename("temp.txt", "user.txt") != 0)
            perror("Error renaming file");
    }


    bool is_file_exist(const char* fileName)
    {
        ifstream infile(fileName);
        return infile.good();
    }



    void edit(int edit_Id) {
      
        Contact holder;
        
       
        holder = readId(edit_Id);
        delete_line(edit_Id);

         
            while (true) {
                cout << "1--->Edit Name" << endl;
                cout << "2--->Edit Surname" << endl;
                cout << "3--->Edit Phone Number" << endl;
                cout << "4--->Finish Editing" << endl;

                int progress;
                cin >> progress;
                if (progress == 1) {

                    cin >> holder.name;
                }
                else if (progress == 2) {
                    cin >> holder.surname;
                }

                else if (progress == 3) {
                    cin >> holder.pnumber;
                }
                else if (progress == 4) {
                    break;
                }
            }
            add(holder.name, holder.surname, holder.pnumber);
        }
};







