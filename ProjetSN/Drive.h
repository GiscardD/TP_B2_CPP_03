#include <windows.h>
#include <string>
#ifndef DRIVE_H
#define DRIVE_H

using namespace std;
class Drive
{
public:
    Drive();
    detect();
    void sync(char usb);
    void kCopy(string file, string name);
    virtual ~Drive();

protected:

private:
    void wait();
    char getUsb();
};
//La classe contient plusieurs fonctions membres publiques, qui peuvent être appelées à partir d'objets de cette classe ou de ses classes dérivées :
#endif // DRIVE_H
