#ifndef DATA_ROOM_H
#define DATA_ROOM_H
#include "Room.cpp"
class RoomArr
{
private:
    std::vector<Room> data;
    size_t size;

public:
    RoomArr();
    RoomArr(const std::vector<Room> &, size_t);
    RoomArr(const RoomArr &);
    ~RoomArr();
    void printArr() const;
    Room &operator[](int i);
    Room operator[](int) const;
    bool addEvent(const Room&);
   bool removeEvent(const Room&);
};

#endif