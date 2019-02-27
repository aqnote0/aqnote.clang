#include <iostream>
#include <string>

using namespace std;

class B
{
  private:
    string name;
    
  public:
    B(string name) : name(name) {}
    string get();
};

class B1 : public B
{

};