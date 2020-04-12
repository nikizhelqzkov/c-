#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
    char *name;
    int years;//max 90
    char* email;//max 100 symbols
    int id;
    //spisuk ot challanges koito da sa w nov klas s nasledqvane
public:
   // Person();
    Person(const char*,int,const char*,int);//func for validation on email ,years
    Person(const Person&);
    ~Person();
    Person& operator=(const Person&);
    void setPerson(const char*,int,const char*, int);
    void setYears(int);
    void setEmail(const char *);
    void setName(const char* );
    void setId(int);
    char*getName()const;
    char*getEmail()const;
    int getId()const;
    int getYears()const;
    void profile_info(const char*)const;//da raboti v masiva ot personi kato normalna funkciq

  
};
#include "Person.hpp"


#endif