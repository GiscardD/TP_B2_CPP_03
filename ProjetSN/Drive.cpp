#include <iostream>
#include <windows.h>
#include <filesystem>
#include <fstream>
#include <string>
#include "Drive.h"
#include<vector>
using namespace std;
namespace fs = std::filesystem;
Drive::Drive()
{

}

Drive::detect(){

}

Drive::~Drive()
{
    wait();
}

string allDrives;

char Drive::getUsb(){
    char usb = '0';
    char sizeLocalDrive[MAX_PATH];
    DWORD dResult = GetLogicalDriveStrings(MAX_PATH, sizeLocalDrive);
    string currentUsb = "";
    for(int i = 0; i < dResult; i++){
        if(sizeLocalDrive[i] > 64 && sizeLocalDrive[i] < 90){
            currentUsb.append(1, sizeLocalDrive[i]);
            if(allDrives.find(sizeLocalDrive[i]) > 100){
                usb = sizeLocalDrive[i];
            }
        }
    }
    allDrives = currentUsb;

    return usb;
}//Cette fonction utilise la fonction GetLogicalDriveStrings pour obtenir une chaîne de caractères contenant tous les lecteurs logiques disponibles sur l'ordinateur.
// En utilisant une boucle "for", cette fonction parcourt chaque caractère de la chaîne de

void Drive::wait(){
    char usbLetter = getUsb();

    while(true){
        usbLetter = getUsb();
        if(usbLetter != '0'){
            printf("%c\n ", usbLetter);
            sync(usbLetter);
            Sleep(1000);
//            "Drive". Cette fonction utilise la fonction membre "getUsb" pour obtenir la lettre de lecteur USB connecté.
        }
    }
}

void Drive::sync(char usb){// Sync permet de recupeerer le nom de la cle
    string filename(1, usb);

    filename += ":\\keyce_drive";
    cout << filename;
    cout<<filename<<endl;
if(filesystem::is_directory(filename)){
        for(const auto & dir_entry : fs::recursive_directory_iterator(filename)){
//            cout << entry.path() << endl;
            kCopy(dir_entry.path().string(), dir_entry.path().filename().string());
        }
    }
}

void Drive::kCopy(string file, string name){
    cout << file;
    ofstream ofile ("C:\\Users\\MARAFA\\Desktop\\keyce_drive\\"+ name, std::ios_base::binary);//on se dirige ves l'emplacement
    ifstream sfile (file, std::ios_base::binary);// permet la recuperation du fichier avec son nom et le convertit en binaire
    char buffer[1025];// en 64 bit
    while(sfile.read(buffer, sizeof(buffer))){//w
        ofile.write(buffer, sfile.gcount());
    }
//    ofile.write(buffer, sfile.gcount());

    ofile.close();
    sfile.close();
}
