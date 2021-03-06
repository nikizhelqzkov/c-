#ifndef INSTITUTION_INCLUDED
#define INSTITUTION_INCLUDED
#include "Payer.h"
#include "Person.h"
#include <iostream>
#include <vector>
class Institution
{
private:
    std::string name;
    int id = 0;

public:
    Institution() = default;
    Institution(std::string);
    virtual ~Institution();
    virtual bool has_member(Person, std::function<bool(int,int)>) const = 0;
    virtual const Payer *payer(const Payer *) = 0;
    virtual bool valid() const = 0;
    virtual Institution *clone() const = 0;
    virtual const Payer *getPayer() const = 0;
    virtual std::string type() const = 0;
    void setId(int);
    virtual int getId() const;
    virtual int count() const = 0;
   // virtual std::vector<Person> getData() const = 0;
    //virtual int countPersons() = 0;
};

#endif