// #include "Date.h"
// #include "Client.h"
// #include "Room.h"
// #include "Event.h"
// #include "DataOfRooms.h"
#include "Date.cpp"
#include "Client.cpp"
#include "Room.cpp"
#include "Event.cpp"
#include "DataOfRooms.cpp"
#include <ctime>
#include <iostream>
#include <cassert>
#include <fstream>
//#include <algorithm>
//g++ main.cpp Date.cpp Client.cpp Room.cpp Event.cpp DataOfRooms.cpp
//datite da sa subota i  nedelq
Event &generate(Event &event, std::string nameOfEvent, Date dateOfEvent)
{
    event.Remove();
    event.setName(nameOfEvent);
    event.setDate(dateOfEvent);
    event.setId(rand() % 100);
    event.setRows(7);
    event.setCols(7);
    return event;
}
bool dateComp(Date i, Date j) { return (i < j); }
Event &readTORoom(Client &c,
                  /*std::vector<std::vector<std::vector<Client>>> &v2*/
                  Event &event)
{
    bool f = true;
    // std::cout << "Enter the event name: ";
    // std::string name;
    // std::getline(std::cin, name);
    // std::cout << "\n Enter the day, month and year of a event: ";
    // unsigned int d, m, y;
    // std::cin >> d >> m >> y;
    // Date date(d, m, y);
    // for (size_t i = 0; i < studio.getSize(); i++)
    // {
    //     if (studio[i].getName() == name && studio[i].getDate() == date)
    //     {
    std::cout << "\n";
    std::cin.ignore(1, '\n');
    do
    {

        std::vector<std::vector<Client>> temp;
        c.read();
        //c.print();`
        temp = event.getplaces();
        if (temp[c.getRow() - 1][c.getCol() - 1].getRow() == c.getRow() && temp[c.getRow() - 1][c.getCol() - 1].getCol() == c.getCol())
        {
            std::cout << "THIS PLACE IS BUSY! WRITE NEW SEAT:\n\n";
            f = false;
        }
        else
        {
            f = true;
            temp[c.getRow() - 1][c.getCol() - 1] = c;
            event.setMatrix(temp);
        }
    } while (!f);
    // event.setCols(c.getCol());
    return event;
    //         std::vector<std::vector<Client>> p;
    //         p = v;
    //         studio[i].setMatrix()
    //     }
    // }

    //v2[0][0][0].
}
//
bool helpCommander()

{
    bool help = true;
    bool helpFlag = true;
    std::cout << "\n\nWELCOME TO THE HELPING CENTER\n";
    std::cout << "\nThese are the starting commands that you can use:\n\n";
    std::cout << "1)open --> opens file\n2)save --> saves the opened file on his directory\n";
    std::cout << "3)save_as --> saves the opened file on new directory\n4)close -->close opened file\n";
    std::cout << "5)help --> give some information about your valid commands\n\n";
    do
    {
        std::cout << "Write that number if you are: \n";
        std::cout << "1)Moderator\n2)Client\n";
        int helpN;
        std::cin >> helpN;
        if (helpN == 1)
        {
            std::cout << "\nWelcome Mod!\nThese are your using commands:\n";
            //all mod commands like new event etc
            std::cout << "1)addevent --> adding new event on EventBox \n2)freeseats --> report of freeseats on an event\n";
            std::cout << "3)bookings --> report of reserved tickets on an event\n";
            std::cout << "4)report --> report of bought tickets from one date to other date\n\n";
            //za 4 shte sortirame masiva po data na eventa i shte shte vidim ot koq data da broim biletite
            //std::sort (myvector.begin(), myvector.end(), dateComp);
            std::cout << "PRESS THE b for back!\n";
            char back;
            bool flagHelp = true;
            do
            {
                std::cin >> back;
                if (back == 'b')
                {
                    help = false;
                }
                else
                {
                    flagHelp = false;
                }
            } while (!flagHelp);
        }
        else if (helpN == 2)
        {
            std::cout << "\nWelcome Client!\nThese are your using commands:\n";
            //all mod commands like new event etc
            std::cout << "\n1)book --> reserve a ticket with name and date of the event, your seat, your name and some note\n";
            std::cout << "2)buy --> reserve a ticket with name and date of the event, your seat, your name and some note\n";
            std::cout << "3)unbook --> cancel the reservation\n";
            std::cout << "4)check --> checking your ticket whether is valid and returning information of the ticket\n\n";

            std::cout << "PRESS THE b for back!\n";
            char back;
            bool flagHelp = true;
            do
            {
                std::cin >> back;
                if (back == 'b')
                {
                    help = false;
                }
                else
                {
                    flagHelp = false;
                }
            } while (!flagHelp);
        }
        else
        {
            helpFlag = false;
            std::cout << "Wrong number!\n\n";
        }
    } while (!helpFlag);
    return help;
}
bool closeCommander()
{
    bool close = true;
    std::cout << "\n\nYOU CLOSED THE FILE!!!!\n";
    std::cout << "NOW WE WILL RETURN BACK TO THE START MENU!!!\n\n\n";
    close = false;
    return close;
}
RoomArr &read(RoomArr &studio, Client &c)
{

    std::cout << "Enter the event name: ";
    std::string name;

    std::getline(std::cin, name);

    std::cout << "\nEnter the day, month and year of a event: ";
    unsigned int day, m, y;
    std::cin >> day >> m >> y;
    Date date(day, m, y);
    bool isItHave = false;
    // std::cin.ignore(1, '\n');
    for (size_t i = 0; i < studio.getSize(); i++)
    {

        //std::cout << studio[i].getName() << "\n";
        if (studio[i].getName() == name && studio[i].getDate() == date)
        {
            isItHave = true;
            c.setDate(date);
            // e.setDate(date);
            // studio[i].print();
            // std::cout << "============================\n";
            // studio[i] = readTORoom(e, studio[i]);
            studio[i] = readTORoom(c, studio[i]);
        }
    }
    if (!isItHave)
    {
        std::cout << "The event on that date is missing!\n";
    }
    return studio;
}

RoomArr &unbook(RoomArr &studio)
{
    std::string nameCLose;
    std::cout << "Name of event: ";
    std::getline(std::cin, nameCLose);
    std::cout << "\n Enter the day, month and year of a event: ";
    unsigned int Day, month, year;
    std::cin >> Day >> month >> year;
    Date dateClose(Day, month, year);
    std::cout << "Enter your row and seat of a row: ";
    int row, col;
    std::cin >> row >> col;
    studio = studio.unbook(nameCLose, dateClose, row, col);
    std::cout << "\n";
    return studio;
}
void checkTicket(RoomArr &studio)
{
    long unsigned int tN;
    std::cout << "Your ticket number: ";
    std::cout << "\n";
    std::cin >> tN;
    studio.checkTicket(tN);
    std::cout << "\n\n";
}
int main()
{

    std::cout << "Live Date: ";
    srand(time(0));
    Date z1;
    z1.getLiveData();
    z1.print();
    std::cout << std::endl;
    std::string a;
    bool open = false;
    bool help = false;
    bool save = false;
    bool save_as = false;
    bool close = false;
    bool exit = false;
    std::cout << "WELCOME TO THE TICKET CENTER!" << std::endl;
    RoomArr st;
    bool canOpen = true;
    std::string fileName;
    bool closeC = true;
    bool isOpen = false;
    do
    {
        open = false;
        help = false;
        save = false;
        save_as = false;
        close = false;
        exit = false;
        std::cout << "Write one of the commands: " << std::endl
                  << "1)open" << std::endl
                  << "2)help" << std::endl
                  << "3)save" << std::endl
                  << "4)save_as" << std::endl
                  << "5)close" << std::endl
                  << "6)exit" << std::endl;

        std::cin >> a;

        if (a == "open" || a == "Open" || a == "OPEN" || a == "1")
        {

            if (canOpen == false)
            {
                std::cout << "\n\n YOU CAN NOT OPEN AGAIN THE FILE! YOU CAN SAVE IT OR CLOSE IT!!!\n\n\n";
            }
            else if (canOpen == true)
            {
                closeC = true;
                int num;
                std::cout << "WRITE NAME OF THE FILE FOR READING: ";

                std::cin >> fileName;
                //for returning back
                // std::cin >> num;
                // if (num == 1)
                // {
                //     open = false;
                // }
                // std::vector<std::vector<Client>> v(7, std::vector<Client>(7));
                int size;
                std::ifstream in(fileName);
                if (!in.is_open())
                {
                    std::cout << "That file is missing\n\n\n";

                    in.close();
                }
                else
                {
                    isOpen = true;
                    open = true;
                    canOpen = false;
                    in >> size;

                    for (size_t i = 0; i < size; i++)
                    {

                        std::string NameOfEvent;
                        in >> NameOfEvent;

                        int dayOfEvent, monthOfEvent, yearOfEvent, id, rows, cols;
                        in >> yearOfEvent >> monthOfEvent >> dayOfEvent;
                        in >> id >> rows >> cols;
                        Date dateOfEvent;
                        dateOfEvent.setDay(dayOfEvent);
                        dateOfEvent.setMonth(monthOfEvent);
                        dateOfEvent.setYear(yearOfEvent);
                        Event s;
                        s.setName(NameOfEvent);
                        s.setDate(dateOfEvent);
                        s.setId(id);
                        s.setRows(rows);
                        s.setCols(cols);
                        // std::cout << s.getName() << " " << s.getDate() << " " << s.getId() << " " << s.getRows() << " " << s.getCols() << "\n";
                        std::vector<std::vector<Client>> temp(rows, std::vector<Client>(cols));
                        for (size_t j = 0; j < rows; j++)
                        {
                            for (size_t k = 0; k < cols; k++)
                            {
                                Client cl; //vlqzul sum iventa, prochel sum dannite bez problem i vlizam da cheta dannite ot printnatiq vekor
                                cl.read(in);
                                //cl.print();
                                //std::cout << "\n";
                                temp[j][k] = cl;
                            }
                        }
                        s.setMatrix(temp);
                        st.addEvent(s);
                        st[i].Print();
                    }
                    in.close();
                    std::cout << "YOUR FILE IS OPEN!\n";

                    //-----pochvat funkciite
                    std::cout << "NOW YOU CAN USE SEVERAL MODS! --> IT HAS DIFFERENT MODS FOR MODERATOR AND CLIENT\n\n";
                    std::cout << "Do you want help for methods? y or n: ";
                    char h;
                    std::cin >> h;
                    if (h == 'y')
                    {
                        bool he;
                        he = helpCommander();
                    }

                    char modOrCLient;
                    bool mOC = false;
                    do
                    {
                        std::cout << "You are moderator or client? --> write m for moderator and c for client and b for back:\n";
                        std::cin >> modOrCLient;
                        if (modOrCLient == 'm')
                        {
                            mOC = true;
                            bool m = false;
                            do
                            {
                                std::cout << "\nWelcome Mod!\nThese are your using commands:\n";
                                //all mod commands like new event etc
                                std::string mV;
                                std::cout << "1)addevent --> adding new event on EventBox \n2)freeseats --> report of freeseats on an event\n";
                                std::cout << "3)bookings --> report of reserved tickets on an event\n";
                                std::cout << "4)report --> report of bought tickets from one date to other date\n";
                                std::cout << "5)back\n";
                                std::cout << "WRITE THE NAME OF COMMAND OR THE NUMBER: \n";
                                std::cin >> mV;
                                if (mV == "1" || mV == "addevent" || mV == "Addevent" || mV == "ADDEVENT" || mV == "AddEvent")
                                {
                                    m = true;
                                    mOC = false;

                                    std::cout << "\n";
                                    std::cin.ignore(1, '\n');
                                    std::cout << "\n";

                                    std::vector<std::vector<Client>> v(7, std::vector<Client>(7));
                                    for (int i = 0; i < v.size(); i++)
                                    {
                                        for (int j = 0; j < v[i].size(); j++)
                                        {
                                            v[i][j].setName("FREE");
                                        }
                                    }
                                    std::cout << "Write the name of event: ";
                                    std::string nameOfEvent;
                                    std::getline(std::cin, nameOfEvent);
                                    std::cout << "\n";
                                    std::cout << "Enter the date: ";
                                    int dayOfEvent2, monthOfEvent2, yearOfEvent2;
                                    std::cin >> dayOfEvent2 >> monthOfEvent2 >> yearOfEvent2;
                                    Date dateOfEvent2;
                                    dateOfEvent2.setDay(dayOfEvent2);
                                    dateOfEvent2.setMonth(monthOfEvent2);
                                    dateOfEvent2.setYear(yearOfEvent2);

                                    Event event;
                                    event = generate(event, nameOfEvent, dateOfEvent2);
                                    event.setMatrix(v);

                                    st = st.addEvent(event);
                                    // st[2].Print();
                                    std::cout << st.getSize() << "\n";
                                    for (int i = 0; i < v.size(); i++)
                                    {
                                        for (int j = 0; j < v[i].size(); j++)
                                        {
                                            v[i][j].setName("FREE");
                                            v[i][j].remove();
                                        }
                                    }
                                }
                                else if (mV == "2" || mV == "freeseats" || mV == "Freeseats" || mV == "FREESEATS" || mV == "FreeSeats")
                                {
                                    std::cin.ignore(1, '\n');
                                    std::cout << "Enter the name of event for freeseats: ";
                                    std::string freeSeats;
                                    std::getline(std::cin, freeSeats);
                                    std::cout << "\n";
                                    int dF, mF, yF;
                                    std::cout << "Enter the date of an event: ";
                                    std::cin >> dF >> mF >> yF;
                                    Date DF(dF, mF, yF);
                                    std::cin.ignore(1, '\n');
                                    st.freeseats(freeSeats, DF); //neka da e s vuvezhdane imeto i ako go nqma da kazhe nema
                                    std::cout << "\n";
                                }
                                else if (mV == "3" || mV == "bookings" || mV == "Bookings" || mV == "BOOKINGS")
                                {
                                    std::cin.ignore(1, '\n');
                                    std::cout << "Enter the name of event for bookings: ";
                                    std::string bookings;
                                    std::getline(std::cin, bookings);
                                    std::cout << "\n";
                                    int dB, mB, yB;
                                    std::cout << "Enter the date of an event: ";
                                    std::cin >> dB >> mB >> yB;
                                    Date DB(dB, mB, yB);
                                    std::cin.ignore(1, '\n');
                                    st.bookings(bookings, DB);
                                }
                                else if (mV == "4" || mV == "report" || mV == "Report" || mV == "REPORT")
                                {
                                    std::cin.ignore(1, '\n');
                                    std::cout << "Enter the name of event for report: ";
                                    std::string report;
                                    std::getline(std::cin, report);
                                    std::cout << "\n";
                                    int dR, mR, yR;
                                    std::cout << "Enter the date of an event: ";
                                    std::cin >> dR >> mR >> yR;
                                    Date DR(dR, mR, yR);
                                    std::cin.ignore(1, '\n');
                                    st.report(report, DR);
                                }
                                else if (mV == "5" || mV == "back" || mV == "Back" || mV == "BACK")
                                {
                                    m = true;
                                    mOC = false;
                                }
                                else
                                {
                                    std::cout << "\nUNVALID COMMAND!!! WRITE AGAIN!!!\n";
                                    m = false;
                                }

                            } while (!m);
                        }
                        else if (modOrCLient == 'c')
                        {
                            mOC = true;
                            bool cl = false;
                            do
                            {
                                std::cout << "\nWelcome Client!\nThese are your using commands:\n";
                                std::string cV;

                                std::cout << "\n1)ticket --> reserve or buy a ticket with name and date of the event, your seat, your name and some note\n";
                                std::cout << "2)unbook --> cancel the reservation\n";
                                std::cout << "3)check --> checking your ticket whether is valid and returning information of the ticket\n\n";
                                std::cout << "4)back\n";
                                std::cout << "WRITE THE NAME OF COMMAND OR THE NUMBER: \n";
                                std::cin >> cV;
                                if (cV == "1" || cV == "ticket" || cV == "Ticket" || cV == "TICKET")
                                {
                                    cl = true;
                                    mOC = false;

                                    std::cout << "\n";
                                    std::cin.ignore(1, '\n');
                                    std::cout << "\n";
                                    std::vector<std::vector<Client>> v(7, std::vector<Client>(7));
                                    for (int i = 0; i < v.size(); i++)
                                    {
                                        for (int j = 0; j < v[i].size(); j++)
                                        {
                                            v[i][j].setName("FREE");
                                        }
                                    }

                                    // std::vector<std::vector<Client>> v(7, std::vector<Client>(7));
                                    // for (int i = 0; i < v.size(); i++)
                                    // {
                                    //     for (int j = 0; j < v[i].size(); j++)
                                    //     {
                                    //         v[i][j].setName("FREE");
                                    //     }
                                    // }
                                    // std::cout << "Write the name of event: ";
                                    // std::string nameOfEvent;
                                    // std::getline(std::cin, nameOfEvent);
                                    // std::cout << "\n";
                                    // std::cout << "Enter the date: ";
                                    // int dayOfEvent2, monthOfEvent2, yearOfEvent2;
                                    // std::cin >> dayOfEvent2 >> monthOfEvent2 >> yearOfEvent2;
                                    // Date dateOfEvent2;
                                    // dateOfEvent2.setDay(dayOfEvent2);
                                    // dateOfEvent2.setMonth(monthOfEvent2);
                                    // dateOfEvent2.setYear(yearOfEvent2);

                                    // Event event;
                                    // event = generate(event, nameOfEvent, dateOfEvent2);
                                    // event.setMatrix(v);

                                    // st = st.addEvent(event);
                                    // // st[2].Print();
                                    // std::cout << st.getSize() << "\n";
                                    // for (int i = 0; i < v.size(); i++)
                                    // {
                                    //     for (int j = 0; j < v[i].size(); j++)
                                    //     {
                                    //         v[i][j].setName("FREE");
                                    //         v[i][j].remove();
                                    //     }
                                    // }

                                    Client c;

                                    st = read(st, c);

                                    // event.setName(nameOfEvent);
                                    // event.setDate(dateOfEvent);
                                    // event.setId(rand() % 100);
                                    // // event.setMatrix(v);
                                    // event.setRows(7);
                                    // event.setCols(7);
                                    // event = generate(event, nameOfEvent, dateOfEvent);
                                    // event.setMatrix(v);

                                    // st.addEvent(event);
                                }
                                else if (cV == "2" || cV == "unbook" || cV == "Unbook" || cV == "UNBOOK")
                                {
                                    std::cin.ignore(1, '\n');
                                    st = unbook(st);
                                }
                                else if (cV == "3" || cV == "check" || cV == "Check" || cV == "CHECK")
                                {
                                    std::cin.ignore(1, '\n');
                                   checkTicket(st);
                                }
                                else if (cV == "4" || cV == "back" || cV == "Back" || cV == "BACK")
                                {
                                    cl = true;
                                    mOC = false;
                                }
                                else
                                {
                                    std::cout << "\nUNVALID COMMAND!!! WRITE AGAIN!!!\n";
                                    cl = false;
                                }

                            } while (!cl);
                        }
                        else if (modOrCLient == 'b')
                        {
                            std::cout << "ARE YOU SURE THAT YOU WANT TO LEAVE\n";
                            std::cout << "(IF PRESS y you will have chance to save your new updates but if you not save and press again open you will lost your saves)\n";
                            std::cout << "y/n: ";
                            char YN;
                            std::cin >> YN;
                            if (YN == 'y' || YN == 'Y')
                            {
                                mOC = true;
                            }
                        }
                        else if (modOrCLient != 'c' && modOrCLient != 'm')
                        {
                            std::cout << "Write again your decision: \n";
                        }
                    } while (!mOC);

                    open = false;
                }
            }
        }
        else if (a == "help" || a == "Help" || a == "HELP" || a == "2")
        {
            help = helpCommander();
        }
        else if (a == "save" || a == "Save" || a == "SAVE" || a == "3")
        {
            if (closeC == false || isOpen == false)
            {
                std::cout << "\n\nYOU CAN NOT SAVE THE EMPTY FILE!!!!\n\n";
            }
            else
            {
                save = true;
                std::cout << "YOUR FILE IS SAVED ON " << fileName << " !!! \n\n";
                // std::cout << "\n";
                // std::cin.ignore(1, '\n');
                // std::cout << "\n";

                // std::vector<std::vector<Client>> v(7, std::vector<Client>(7));
                // for (int i = 0; i < v.size(); i++)
                // {
                //     for (int j = 0; j < v[i].size(); j++)
                //     {
                //         v[i][j].setName("FREE");
                //     }
                // }
                // std::cout << "Write the name of event: ";
                // std::string nameOfEvent;
                // std::getline(std::cin, nameOfEvent);
                // std::cout << "\n";
                // std::cout << "Enter the date: ";
                // int dayOfEvent2, monthOfEvent2, yearOfEvent2;
                // std::cin >> dayOfEvent2 >> monthOfEvent2 >> yearOfEvent2;
                // Date dateOfEvent2;
                // dateOfEvent2.setDay(dayOfEvent2);
                // dateOfEvent2.setMonth(monthOfEvent2);
                // dateOfEvent2.setYear(yearOfEvent2);

                // Event event;
                // event = generate(event, nameOfEvent, dateOfEvent2);
                // event.setMatrix(v);

                // st = st.addEvent(event);
                // st[2].Print();
                // std::cout << st.getSize() << "\n";
                // for (int i = 0; i < v.size(); i++)
                // {
                //     for (int j = 0; j < v[i].size(); j++)
                //     {
                //         v[i][j].setName("FREE");
                //         v[i][j].remove();
                //     }
                // }

                // std::cout << "WRITE NAME OF THE FILE FOR SAVING: ";
                // std::string fileName;
                // std::cin >> fileName;

                std::ofstream out(fileName);
                st.printArr(out);
                out.close();
                canOpen = true;
                save = false;
            }
        }
        else if (a == "save_as" || a == "Save_as" || a == "SAVE_AS" || a == "Save_As" || a == "4")
        {
            if (closeC == false || isOpen == false)
            {
                std::cout << "\n\nYOU CAN NOT SAVE THE EMPTY FILE!!!!\n\n";
            }
            else
            {
                save_as = false;
                std::cout << "WRITE NAME OF THE FILE FOR SAVING: ";
                std::string fileName2;
                std::cin >> fileName2;
                std::ofstream out(fileName2);
                st.printArr(out);
                out.close();
                std::cout << "YOUR FILE IS SAVED ON " << fileName2 << " !!! \n\n";
                fileName = fileName2;

                canOpen = true;
            }
        }
        else if (a == "close" || a == "Close" || a == "CLOSE" || a == "5")
        {
            if (isOpen == false)
            {
                std::cout << "\n\nYOU CAN NOT CLOSE THE EMPTY FILE!!!!\n\n";
            }
            else
            {
                close = closeCommander();
                closeC = false;
                canOpen = true;
                isOpen = false;
                RoomArr t;
                st = t;
            }
        }
        else if (a == "exit" || a == "Exit" || a == "EXIT" || a == "6")
        {
            exit = true;
            std::cout << "GOOD BYE !!!\n";
            return 0;
        }
        else
        {
            std::cout << "WRITE AGAIN CORRECT COMMAND\n\n\n";
        }
    } while (!open && !help && !save && !save_as && !close && !exit);

    // Date d1(20, 6, 2020), d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
    // Client c, d, e;

    //c.read();d.read();
    // e.read();
    // std::vector<std::vector<std::vector<Client>>> p2(7, std::vector<std::vector<Client>>(7));
    // std::vector<std::vector<Client>> v(7, std::vector<Client>(7));

    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         v[i][j].setName("FREE");
    //     }
    // }

    // std::cout << "\n";
    // std::cin.ignore(1, '\n');
    // std::cout << "\n";

    // std::cout << "Write the name of event: ";
    // std::string nameOfEvent;
    // std::getline(std::cin, nameOfEvent);
    // std::cout << "\n";
    // std::cout << "Enter the date: ";
    // int dayOfEvent2, monthOfEvent2, yearOfEvent2;
    // std::cin >> dayOfEvent2 >> monthOfEvent2 >> yearOfEvent2;
    // Date dateOfEvent2;
    // dateOfEvent2.setDay(dayOfEvent2);
    // dateOfEvent2.setMonth(monthOfEvent2);
    // dateOfEvent2.setYear(yearOfEvent2);

    // Event event;

    //---------------
    //(dateOfEvent, nameOfEvent, rand() % 100, v, 7, 7);
    // event.Remove();
    // event.setName(nameOfEvent);
    // event.setDate(dateOfEvent2);
    // event.setId(rand() % 100);
    // event.setRows(7);
    // event.setCols(7);

    // event = generate(event, nameOfEvent, dateOfEvent2);
    // event.setMatrix(v);

    // //kolos.print();

    // st = st.addEvent(event);
    // st[2].Print();
    // std::cout<<st.getSize()<<"\n";
    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         v[i][j].setName("FREE");
    //         v[i][j].remove();
    //     }
    //  }

    //st[1].Print();
    // std::cout << "\n";
    // std::cin.ignore(1, '\n');
    // std::cout << "Write the name of event: ";
    // std::getline(std::cin, nameOfEvent);
    // std::cout << "\n";
    // std::cout << "Enter the date: ";
    // std::cin >> dayOfEvent >> monthOfEvent >> yearOfEvent;

    // dateOfEvent.setDay(dayOfEvent);
    // dateOfEvent.setMonth(monthOfEvent);
    // dateOfEvent.setYear(yearOfEvent);

    // event.Remove();
    // event.setName(nameOfEvent);
    // event.setDate(dateOfEvent);
    // event.setId(rand() % 100);
    // // event.setMatrix(v);
    // event.setRows(7);
    // event.setCols(7);
    // event = generate(event, nameOfEvent, dateOfEvent);
    // event.setMatrix(v);

    // st.addEvent(event);

    // studio[0].Print();
    // std::cout << "==========================\n";
    //studio[1].Print();
    // std::cout << "\n";
    // std::cin.ignore(1, '\n');
    // std::cout << "\n";
    // std::cin.ignore(1, '\n');
    // st = read(st, c);
    // st = read(st, e);

    //st = unbook(st);

    //st[0].print();
    // std::cout << "========================\n\n";
    // st[1].print();

    // std::cin.ignore(1, '\n');
    // std::cout << "Enter the name of event for freeseats: ";
    // std::string freeSeats;
    // std::getline(std::cin, freeSeats);
    // std::cout << "\n";
    // int dF, mF, yF;
    // std::cout << "Enter the date of an event: ";
    // std::cin >> dF >> mF >> yF;
    // Date DF(dF, mF, yF);
    // std::cin.ignore(1, '\n');
    // st.freeseats(freeSeats, DF); //neka da e s vuvezhdane imeto i ako go nqma da kazhe nema
    // std::cout << "\n";

    // std::cout << "Enter the name of event for bookings: ";
    // std::string bookings;
    // std::getline(std::cin, bookings);
    // std::cout << "\n";
    // int dB, mB, yB;
    // std::cout << "Enter the date of an event: ";
    // std::cin >> dB >> mB >> yB;
    // Date DB(dB, mB, yB);
    // std::cin.ignore(1, '\n');
    // st.bookings(bookings, DB); //neka da e s vuvezhdane imeto i ako go nqma da kazhe nema

    // checkTicket(st);

    system("pause");

    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         v[i][j].setName("FREE PLACE");
    //     }
    // }

    // v[e.getRow() - 1][e.getCol() - 1] = e;

    // std::cout<<v[2].size();

    // Room club(rand() % 100, v, 7, 7);
    // Room club2(rand() % 100, v2, 7, 7);
    // Room club3(rand() % 100, v3, 7, 7);
    // Room club4(rand() % 100, v4, 7, 7);
    // Room club5(rand() % 100, v5, 7, 7);
    // Room club6(rand() % 100, v6, 7, 7);
    // Room club7(rand() % 100, v7, 7, 7);
    // Room club8(rand() % 100, v8, 7, 7);
    // Room club9(rand() % 100, v9, 7, 7);

    //club.print();

    // readTORoom(c, v);
    // Room club(club.getId(), v, 7, 7);

    //  Date date(25,06,2000);
    //  date.print();
    // size_t id = 3;
    //int **a = new int *[3];

    // int row = 3;
    // int col = 2;
    // int counter = 1;
    // for (int i = 0; i < row; ++i)
    // {
    //     a[i] = new int[col];
    // }
    // for (int i = 0; i < row; ++i)
    // {
    //     for (int j = 0; j < col; ++j)
    //     {
    //         std::cin>>a[i][j];
    //     }
    // }

    // Room A(3, a, row, col);

    // A.print();

    // for (size_t i = 0; i < row; i++)
    // {
    //     delete[] a[i];
    // }
    // delete[] a;

    return 0;
}