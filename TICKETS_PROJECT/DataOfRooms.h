#ifndef DATA_ROOM_H
#define DATA_ROOM_H
#include "Event.h"
#include <vector>
class RoomArr
{
private:
    std::vector<Event> data;
    size_t size;

public:
    RoomArr();
    RoomArr(const std::vector<Event> &, size_t);
    RoomArr(const RoomArr &);
    ~RoomArr();
    void printArr(std::ostream&) const;
    void printArr() const;
    Event &operator[](int i);
    Event operator[](int) const;
    RoomArr &addEvent(const Event &);
    bool removeEvent(const Event &);
    int getSize() const;
    std::vector<Event> getData() const;
    void freeseats(std::string, Date);
    void bookings(std::string, Date);
    void checkTicket(long unsigned int serialNumber);
    RoomArr& unbook(std::string name, Date date, int row, int col);
};

#endif