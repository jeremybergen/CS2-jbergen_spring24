#include <iostream>

using namespace std;

class SomeClass {
    private:
    int _id;
    int _otherId;

    public:
    SomeClass* setId(int);
    int getId();

    SomeClass* setOtherId(int);
    int getOtherId();
};

int main(int argc, char* argv[])
{
    SomeClass sc1;

    cout << "DEBUG: &sc1: " << &sc1 << endl;
    cout << "DEBUG: &(*(sc1.setId(42))): " << &(*(sc1.setId(42))) << endl;
    cout << "DEBUG: &(*(*(sc1.setId(42))).setOtherId(15)): " << &(*(*(sc1.setId(42))).setOtherId(15)) << endl;
    (*(sc1.setId(42))).setOtherId(15);
    sc1.setId(42)->setOtherId(15);
    // pointer returned
    // sc1.setOtherId(15)
  //this->setOtherId(15);
    cout << sc1.getId() << " " << sc1.getOtherId() << endl;

    return 0;

//     SomeClass* sc1 = new SomeClass();

//     sc1->setId(42)->setOtherId(15);
//   //this->setOtherId(15);
//     cout << sc1->getId() << " " << sc1->getOtherId() << endl;

//     delete sc1;
//     return 0;
}

SomeClass* SomeClass::setOtherId(int otherId)
{
    this->_otherId = otherId;
    return this;
}
int SomeClass::getOtherId()
{
    return this->_otherId;
}

SomeClass* SomeClass::setId(int id)
{
    (*this)._id = id;
    return this;
}

int SomeClass::getId()
{
    return this->_id;
}