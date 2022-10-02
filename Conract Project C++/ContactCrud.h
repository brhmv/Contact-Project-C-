#pragma once
ContactCrud crud;



enum Keys
{
    Up = 72,
    Down = 80,
    Enter = 13,
    Backspace = 8
};
enum Color {
    Green = 2,
    Red = 4,
    White = 15
};
void changeColor(int i) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, i);
}
void printMenu(char* arr, int index) {
    system("cls");
    string array[7] = { "All Contacts ", "Add contact ", "Search based on name,surname,phonenumber ","Search Id ","Delete ","Edit", "Exit" };
    int j = 0;
    for (int i = 0; i < 7; i++)
    {
        if (i == index)
        {
            changeColor(Red);
            cout << array[i] << arr[j] << endl;
            changeColor(White);
        }
        else
        {
            cout << array[i] << arr[j] << endl;
        }
        j++;
    }

}
int changeArr(char* arr, int index, int size) {
    for (int i = 0; i < size; i++)
    {
        if (i == index) {
            arr[i] = '<';
        }
        else arr[i] = ' ';
    }
    return index;
}


int loop = 1;
void menu() {
    while (loop)
    {
        if (loop == 1) {
            char ch;
            ch = _getch();
            cout << int(ch) << endl;
            int i = 0;
            char* arr = new char[3];
            int choice;
            while (true)
            {
                int temp = changeArr(arr, i, 6);
                printMenu(arr, temp);
                ch = _getch();
                if (int(ch) == -32) {
                    ch = _getch();
                    switch (int(ch))
                    {
                    case Up: i = i == 0 ? 6 : i - 1; break;
                    case Down: i = i == 6 ? 0 : i + 1; break;
                    }
                }

                else if (int(ch) == Enter) {
                    choice = i;
                    break;
                }
            }

            Contact add_user;
            Contact search_user;
            string search;
            int delete_Id;
            int search_Id;
            int edit_Id;
            switch (choice)
            {
            case 0:
                system("cls");
                crud.read();
                break;
            case 1:
                system("cls");
                cout << "Insert Name: ";
                cin >> add_user.name;
                cout << endl;
                cout << "Insert Surname: ";
                cin >> add_user.surname;
                cout << endl;
            label:
                cout << "Insert Phone number: ";
                cin >> add_user.pnumber;

                if (add_user.pnumber.length() > 15)
                {
                    cout << "Number is too long" << endl;
                    goto label;
                }
                for (int O = 0; O < add_user.pnumber.length(); O++)
                {
                    if (!(int(add_user.pnumber[O]) <= 57 && int(add_user.pnumber[O]) >= 48)) {
                        cout << "You sould insert number !" << endl;
                        goto label;
                    }
                }

                crud.add(add_user.name, add_user.surname, add_user.pnumber);
                break;
            case 2:
                system("cls");
                cout << "Insert one of name,surname,phone number: ";
                cin >> search;
                crud.read(search);
                break;
            case 3:
                system("cls");
                cout << "Insert ID: ";
                cin >> search_Id;
                search_user = crud.readId(search_Id);
                cout << search_user.name << " " << search_user.surname << " " << search_user.pnumber;
                break;
            case 4:
                system("cls");
                cout << "Insert ID: ";
                cin >> delete_Id;
                if (delete_Id == 1) {
                    cout << "first Line cant be deleted";
                }
                else {
                    crud.delete_line(delete_Id);
                }
                break;
            case 5:
                system("cls");
                cout << "Insert ID: ";
                cin >> edit_Id;
                if (edit_Id == 1) {
                    cout << "first line cant be edited";
                }
                else {
                    crud.edit(edit_Id);
                }
                break;
            case 6:
                system("cls");
                loop = 0;
                break;
            default:

                break;
            }
        }

    }


      
}






