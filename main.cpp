#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FileReader {

public:
    unsigned int shipCount = 0;
    unsigned int shipCount1 = 0;
    unsigned int shipCount2 = 0;
    unsigned int nameLength = 0;
    string shipName;     //store
    unsigned int classLength = 0;
    string className;   //store
    short shipLength = 0;   //store
    unsigned int shieldCapacity = 0;  //store
    float warpSpeed = 0;  //store
    unsigned int weaponCount = 0;
    unsigned int weaponLength = 0;
    string weaponName;  //store
    unsigned int weaponPowerRating = 0;  //store
    float powerConsumption = 0;  //store
    unsigned int maxVal1 = 0;
    unsigned int maxVal2 = 0;
    unsigned int maxShip1 = 0;
    unsigned int maxShip2 = 0;
    unsigned int minShip1 = 0;
    unsigned int minShip2 = 0;

    vector<string>shipName1;
    vector<string>className1;
    vector<short>shipLength1;
    vector<unsigned int>shieldCapacity1;
    vector<float>warpSpeed1;
    vector<string>weaponName1;
    vector<unsigned int>weaponPowerRating1;
    vector<float>powerConsumption1;
    vector<unsigned int>weaponCount1;
    vector<unsigned int>totPowerRating1;

    vector<string>shipName2;
    vector<string>className2;
    vector<short>shipLength2;
    vector<unsigned int>shieldCapacity2;
    vector<float>warpSpeed2;
    vector<string>weaponName2;
    vector<unsigned int>weaponPowerRating2;
    vector<float>powerConsumption2;
    vector<unsigned int>weaponCount2;
    vector<unsigned int>totPowerRating2;

    void loadFile1();
    void loadFile2();
    void printShips1();
    void printShips2();
    void mostPowerfulWeapon1();
    void mostPowerfulWeapon2();
    void mostPowerfulWeapon3();
    void strongestShip1();
    void strongestShip2();
    void strongestShip3();
    void weakestShip1();
    void weakestShip2();
    void weakestShip3();
    void printUnarmed1();
    void printUnarmed2();
};


void FileReader::loadFile1(){

    ifstream file1("friendlyships.shp", ios_base::binary);

    if(!file1.is_open()) {
        cout << "Error: File not opened" << endl;
    }

    file1.read((char *) &shipCount, 4);
    this->shipCount1 = shipCount;


    for(unsigned int i = 0; i < shipCount; i++) {

        file1.read((char *) &nameLength, 4);
        char *shipName = new char[nameLength];
        file1.read(shipName, nameLength * sizeof(shipName[0]));
        file1.read((char *) &classLength, 4);
        char *className = new char[classLength];
        file1.read(className, classLength * sizeof(className[0]));
        file1.read((char *) &shipLength, 2);
        file1.read((char *) &shieldCapacity, 4);
        file1.read((char *) &warpSpeed, 4);
        file1.read((char *) &weaponCount, 4);

        shipName1.push_back(shipName);
        className1.push_back(className);
        shipLength1.push_back(shipLength);
        shieldCapacity1.push_back(shieldCapacity);
        warpSpeed1.push_back(warpSpeed);
        weaponCount1.push_back(weaponCount);

        int totPowerRating = 0;
        for(unsigned int j = 0; j < weaponCount; j++) {
            file1.read((char *) &weaponLength, 4);
            char *weaponName = new char[weaponLength];
            file1.read(weaponName, weaponLength * sizeof(weaponName[0]));
            file1.read((char *) &weaponPowerRating, 4);
            file1.read((char *) &powerConsumption, 4);

            weaponName1.push_back(weaponName);
            weaponPowerRating1.push_back(weaponPowerRating);
            powerConsumption1.push_back(powerConsumption);
            totPowerRating = totPowerRating + weaponPowerRating;
        }

        totPowerRating1.push_back(totPowerRating);
    }

    //cout << totPowerRating1.size() << endl;

    file1.close();
}

void FileReader::loadFile2(){

    ifstream file2("enemyships.shp", ios_base::binary);

    if(!file2.is_open()) {
        cout << "Error: File not opened" << endl;
    }

    file2.read((char *) &shipCount, 4);
    this->shipCount2 = shipCount;

    for(unsigned int i = 0; i < shipCount; i++) {
        file2.read((char *) &nameLength, 4);
        char *shipName = new char[nameLength];
        file2.read(shipName, nameLength * sizeof(shipName[0]));
        file2.read((char *) &classLength, 4);
        char *className = new char[classLength];
        file2.read(className, classLength * sizeof(className[0]));
        file2.read((char *) &shipLength, 2);
        file2.read((char *) &shieldCapacity, 4);
        file2.read((char *) &warpSpeed, 4);
        file2.read((char *) &weaponCount, 4);

        shipName2.push_back(shipName);
        className2.push_back(className);
        shipLength2.push_back(shipLength);
        shieldCapacity2.push_back(shieldCapacity);
        warpSpeed2.push_back(warpSpeed);
        weaponCount2.push_back(weaponCount);

        int totPowerRating = 0;
        for(unsigned int j = 0; j < weaponCount; j++) {
            file2.read((char *) &weaponLength, 4);
            char *weaponName = new char[weaponLength];
            file2.read(weaponName, weaponLength * sizeof(weaponName[0]));
            file2.read((char *) &weaponPowerRating, 4);
            file2.read((char *) &powerConsumption, 4);

            weaponName2.push_back(weaponName);
            weaponPowerRating2.push_back(weaponPowerRating);
            powerConsumption2.push_back(powerConsumption);
            totPowerRating = totPowerRating + weaponPowerRating;
        }

        totPowerRating2.push_back(totPowerRating);
    }

    //cout << totPowerRating2.size() << endl;
    file2.close();
}

void FileReader:: printShips1() {

    int location = 0;

    for(unsigned int i = 0; i < shipCount1; i++){

        cout << "Name: " << shipName1.at(i) << endl;
        cout << "Class: " << className1.at(i) << endl;
        cout << "Length: " << shipLength1.at(i) << endl;
        cout << "Shield capacity: " << shieldCapacity1.at(i) << endl;
        cout << "Maximum Warp: " << warpSpeed1.at(i) << endl;
        cout << "Armaments: " << endl;

        if(weaponCount1.at(i) == 0){

            cout << "Unarmed" << endl;
        }

        for(unsigned int j = 0; j < weaponCount1.at(i); j++){

            cout << weaponName1.at(j + location) << ", ";
            cout << weaponPowerRating1.at(j + location) << ", ";
            cout << powerConsumption1.at(j + location) << endl;

        }

        location = location + weaponCount1.at(i);
        if(weaponCount1.at(i) != 0){

            cout << "Total firepower: " << totPowerRating1.at(i);
            cout << endl;
        }

        cout << endl;
    }

}

void FileReader:: printShips2() {

    int location = 0;

    for(unsigned int i = 0; i < shipCount2; i++){

        cout << "Name: " << shipName2.at(i) << endl;
        cout << "Class: " << className2.at(i) << endl;
        cout << "Length: " << shipLength2.at(i) << endl;
        cout << "Shield capacity: " << shieldCapacity2.at(i) << endl;
        cout << "Maximum Warp: " << warpSpeed2.at(i) << endl;
        cout << "Armaments: " << endl;

        if(weaponCount2.at(i) == 0){

            cout << "Unarmed" << endl;
        }

        for(unsigned int j = 0; j < weaponCount2.at(i); j++){

            cout << weaponName2.at(j + location) << ", ";
            cout << weaponPowerRating2.at(j + location) << ", ";
            cout << powerConsumption2.at(j + location) << endl;

        }

        location = location + weaponCount2.at(i);

        if(weaponCount2.at(i) != 0){

            cout << "Total firepower: " << totPowerRating2.at(i);
            cout << endl;
        }

        cout << endl;
    }

}

void FileReader:: mostPowerfulWeapon1() {

    unsigned int maxVal = 0;
    unsigned int maxIndex = 0;

    for(unsigned int i = 0; i < weaponPowerRating1.size(); i++){

        if(weaponPowerRating1.at(i) > maxVal){

            maxVal = weaponPowerRating1.at(i);
            maxIndex = i;
        }
    }

    //cout << weaponPowerRating1.size() << endl;
    //cout << maxIndex << endl;
    //cout << maxVal << endl;

    unsigned int totIndex = 0;
    unsigned int location = 0;

    for(unsigned int i = 0; i < shipCount1; i++){

        totIndex = totIndex + weaponCount1.at(i);

        if(maxIndex <= totIndex){

            cout << "Name: " << shipName1.at(i) << endl;
            cout << "Class: " << className1.at(i) << endl;
            cout << "Length: " << shipLength1.at(i) << endl;
            cout << "Shield capacity: " << shieldCapacity1.at(i) << endl;
            cout << "Maximum Warp: " << warpSpeed1.at(i) << endl;
            cout << "Armaments: " << endl;

            if(weaponCount1.at(i) == 0){

                cout << "Unarmed" << endl;

            }

            for(unsigned int j = 0; j < weaponCount1.at(i); j++){

                cout << weaponName1.at(j + location) << ", ";
                cout << weaponPowerRating1.at(j + location) << ", ";
                cout << powerConsumption1.at(j + location) << endl;

            }

            location = location + weaponCount1.at(i);
            cout << "Total firepower: " << totPowerRating1.at(i);

            cout << endl;
            cout << endl;

            break;
        }
    }
}

void FileReader:: mostPowerfulWeapon2() {

    unsigned int maxVal = 0;
    unsigned int maxIndex = 0;

    for(unsigned int i = 0; i < weaponPowerRating2.size(); i++){

        if(weaponPowerRating2.at(i) > maxVal){

            maxVal = weaponPowerRating2.at(i);
            maxIndex = i;
        }
    }

    //cout << weaponPowerRating1.size() << endl;
    //cout << maxIndex << endl;
    //cout << maxVal << endl;

    unsigned int totIndex = 0;
    unsigned int location = 0;

    for(unsigned int i = 0; i < shipCount2; i++){

        totIndex = totIndex + weaponCount2.at(i);

        if(maxIndex <= totIndex){

            cout << "Name: " << shipName2.at(i) << endl;
            cout << "Class: " << className2.at(i) << endl;
            cout << "Length: " << shipLength2.at(i) << endl;
            cout << "Shield capacity: " << shieldCapacity2.at(i) << endl;
            cout << "Maximum Warp: " << warpSpeed2.at(i) << endl;
            cout << "Armaments: " << endl;

            if(weaponCount2.at(i) == 0){

                cout << "Unarmed" << endl;

            }

            for(unsigned int j = 0; j < weaponCount2.at(i); j++){

                cout << weaponName2.at(j + location) << ", ";
                cout << weaponPowerRating2.at(j + location) << ", ";
                cout << powerConsumption2.at(j + location) << endl;

            }

            location = location + weaponCount2.at(i);
            cout << "Total firepower: " << totPowerRating2.at(i);

            cout << endl;
            cout << endl;

            break;
        }
    }
}

void FileReader:: mostPowerfulWeapon3() {

    unsigned int maxVal1 = 0;

    for(unsigned int i = 0; i < weaponPowerRating1.size(); i++){

        if(weaponPowerRating1.at(i) > maxVal1){

            this->maxVal1 = weaponPowerRating1.at(i);
        }
    }

    unsigned int maxVal2 = 0;

    for(unsigned int i = 0; i < weaponPowerRating2.size(); i++){

        if(weaponPowerRating2.at(i) > maxVal2){

            this->maxVal2 = weaponPowerRating2.at(i);
        }
    }

}

void FileReader:: strongestShip1() {

    unsigned int maxShip = 0;
    unsigned int maxShipIndex = 0;

    for(unsigned int i = 0; i < totPowerRating1.size(); i++){

        if(totPowerRating1.at(i) > maxShip){

            maxShip = totPowerRating1.at(i);
            maxShipIndex = i;
        }

    }

    unsigned int location = 0;

    for(unsigned int i = 0; i < totPowerRating1.size(); i++){

        if(i == maxShipIndex){

            cout << "Name: " << shipName1.at(i) << endl;
            cout << "Class: " << className1.at(i) << endl;
            cout << "Length: " << shipLength1.at(i) << endl;
            cout << "Shield capacity: " << shieldCapacity1.at(i) << endl;
            cout << "Maximum Warp: " << warpSpeed1.at(i) << endl;
            cout << "Armaments: " << endl;

            if(weaponCount1.at(i) == 0){

                cout << "Unarmed" << endl;
                break;
            }

            for(unsigned int j = 0; j < weaponCount1.at(i); j++){

                cout << weaponName1.at(j + location) << ", ";
                cout << weaponPowerRating1.at(j + location) << ", ";
                cout << powerConsumption1.at(j + location) << endl;

            }

            cout << "Total firepower: " << totPowerRating1.at(i);

            cout << endl;
            cout << endl;

            break;
        }

        location = location + weaponCount1.at(i);
    }
}

void FileReader:: strongestShip2() {

    unsigned int maxShip = 0;
    unsigned int maxShipIndex = 0;

    for(unsigned int i = 0; i < totPowerRating2.size(); i++){

        if(totPowerRating2.at(i) > maxShip){

            maxShip = totPowerRating2.at(i);
            maxShipIndex = i;
        }

    }

    unsigned int location = 0;

    for(unsigned int i = 0; i < totPowerRating2.size(); i++){

        if(i == maxShipIndex){

            cout << "Name: " << shipName2.at(i) << endl;
            cout << "Class: " << className2.at(i) << endl;
            cout << "Length: " << shipLength2.at(i) << endl;
            cout << "Shield capacity: " << shieldCapacity2.at(i) << endl;
            cout << "Maximum Warp: " << warpSpeed2.at(i) << endl;
            cout << "Armaments: " << endl;

            if(weaponCount2.at(i) == 0){

                cout << "Unarmed" << endl;
                break;
            }

            for(unsigned int j = 0; j < weaponCount2.at(i); j++){

                cout << weaponName2.at(j + location) << ", ";
                cout << weaponPowerRating2.at(j + location) << ", ";
                cout << powerConsumption2.at(j + location) << endl;

            }

            cout << "Total firepower: " << totPowerRating2.at(i);

            cout << endl;
            cout << endl;

            break;
        }

        location = location + weaponCount2.at(i);
    }

}

void FileReader:: strongestShip3() {

    unsigned int maxShip1 = 0;

    for(unsigned int i = 0; i < totPowerRating1.size(); i++){

        if(totPowerRating1.at(i) > maxShip1){

            this->maxShip1 = totPowerRating1.at(i);
        }

    }

    unsigned int maxShip2 = 0;

    for(unsigned int i = 0; i < totPowerRating2.size(); i++){

        if(totPowerRating2.at(i) > maxShip2){

            this->maxShip2 = totPowerRating2.at(i);
        }

    }

}

void FileReader:: weakestShip1() {

    unsigned int minShip = 10000;
    unsigned int minShipIndex = 0;

    for(unsigned int i = 0; i < totPowerRating1.size(); i++){

        if(totPowerRating1.at(i) != 0){

            if(totPowerRating1.at(i) < minShip){

                minShip = totPowerRating1.at(i);
                minShipIndex = i;
            }
        }
    }

    unsigned int location = 0;

    for(unsigned int i = 0; i < totPowerRating1.size(); i++){

        if(i == minShipIndex){

            cout << "Name: " << shipName1.at(i) << endl;
            cout << "Class: " << className1.at(i) << endl;
            cout << "Length: " << shipLength1.at(i) << endl;
            cout << "Shield capacity: " << shieldCapacity1.at(i) << endl;
            cout << "Maximum Warp: " << warpSpeed1.at(i) << endl;
            cout << "Armaments: " << endl;

            if(weaponCount1.at(i) == 0){

                cout << "Unarmed" << endl;
                break;
            }

            for(unsigned int j = 0; j < weaponCount1.at(i); j++){

                cout << weaponName1.at(j + location) << ", ";
                cout << weaponPowerRating1.at(j + location) << ", ";
                cout << powerConsumption1.at(j + location) << endl;

            }

            cout << "Total firepower: " << totPowerRating1.at(i);

            cout << endl;
            cout << endl;

            break;
        }

        location = location + weaponCount1.at(i);
    }
}

void FileReader:: weakestShip2() {

    unsigned int minShip = 10000;
    unsigned int minShipIndex = 0;

    for(unsigned int i = 0; i < totPowerRating2.size(); i++){

        if(totPowerRating2.at(i) != 0){

            if(totPowerRating2.at(i) < minShip){

                minShip = totPowerRating2.at(i);
                minShipIndex = i;
            }
        }
    }

    unsigned int location = 0;

    for(unsigned int i = 0; i < totPowerRating2.size(); i++){

        if(i == minShipIndex){

            cout << "Name: " << shipName2.at(i) << endl;
            cout << "Class: " << className2.at(i) << endl;
            cout << "Length: " << shipLength2.at(i) << endl;
            cout << "Shield capacity: " << shieldCapacity2.at(i) << endl;
            cout << "Maximum Warp: " << warpSpeed2.at(i) << endl;
            cout << "Armaments: " << endl;

            if(weaponCount2.at(i) == 0){

                cout << "Unarmed" << endl;
                break;
            }

            for(unsigned int j = 0; j < weaponCount2.at(i); j++){

                cout << weaponName2.at(j + location) << ", ";
                cout << weaponPowerRating2.at(j + location) << ", ";
                cout << powerConsumption2.at(j + location) << endl;

            }

            cout << "Total firepower: " << totPowerRating2.at(i);

            cout << endl;
            cout << endl;

            break;
        }

        location = location + weaponCount2.at(i);
    }
}

void FileReader:: weakestShip3() {

    unsigned int minShip1 = 10000;

    for(unsigned int i = 0; i < totPowerRating1.size(); i++){

        if(totPowerRating1.at(i) != 0){

            if(totPowerRating1.at(i) < minShip1){

                this->minShip1 = totPowerRating1.at(i);
            }
        }
    }

    unsigned int minShip2 = 10000;

    for(unsigned int i = 0; i < totPowerRating2.size(); i++){

        if(totPowerRating2.at(i) != 0){

            if(totPowerRating2.at(i) < minShip2){

                this->minShip2 = totPowerRating2.at(i);
            }
        }
    }

}

void FileReader:: printUnarmed1() {

    unsigned int location = 0;

    for(unsigned int i = 0; i < shipCount1; i++){

        if(weaponCount1.at(i) == 0){

            cout << "Name: " << shipName1.at(i) << endl;
            cout << "Class: " << className1.at(i) << endl;
            cout << "Length: " << shipLength1.at(i) << endl;
            cout << "Shield capacity: " << shieldCapacity1.at(i) << endl;
            cout << "Maximum Warp: " << warpSpeed1.at(i) << endl;
            cout << "Armaments: " << endl;

            if(weaponCount1.at(i) == 0){

                cout << "Unarmed" << endl;
            }

            for(unsigned int j = 0; j < weaponCount1.at(i); j++){

                cout << weaponName1.at(j + location) << ", ";
                cout << weaponPowerRating1.at(j + location) << ", ";
                cout << powerConsumption1.at(j + location) << endl;

            }

            location = location + weaponCount1.at(i);

            cout << endl;
        }

    }

}

void FileReader:: printUnarmed2() {

    unsigned int location = 0;

    for(unsigned int i = 0; i < shipCount2; i++){

        if(weaponCount2.at(i) == 0){

            cout << "Name: " << shipName2.at(i) << endl;
            cout << "Class: " << className2.at(i) << endl;
            cout << "Length: " << shipLength2.at(i) << endl;
            cout << "Shield capacity: " << shieldCapacity2.at(i) << endl;
            cout << "Maximum Warp: " << warpSpeed2.at(i) << endl;
            cout << "Armaments: " << endl;

            if(weaponCount2.at(i) == 0){

                cout << "Unarmed" << endl;
            }

            for(unsigned int j = 0; j < weaponCount2.at(i); j++){

                cout << weaponName2.at(j + location) << ", ";
                cout << weaponPowerRating2.at(j + location) << ", ";
                cout << powerConsumption2.at(j + location) << endl;

            }

            location = location + weaponCount2.at(i);

            cout << endl;
        }

    }

}

int main(){

    FileReader readerObject;

    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;
    int option;
    cin >> option;

    if(option == 1){

        readerObject.loadFile1();
    }

    if(option == 2){

        readerObject.loadFile2();
    }

    if(option == 3){

        readerObject.loadFile1();
        readerObject.loadFile2();
    }

    cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl;
    int choice;

    cin >> choice;

    if(choice == 1){

        if(option == 1){

            readerObject.printShips1();
        }

        if(option == 2){

            readerObject.printShips2();
        }

        if(option == 3){

            readerObject.printShips1();
            readerObject.printShips2();
        }

    }

    if(choice == 2){

        if(option == 1){

            readerObject.mostPowerfulWeapon1();
        }

        if(option == 2){

            readerObject.mostPowerfulWeapon2();
        }

        if(option == 3){

            readerObject.mostPowerfulWeapon3();

            if(readerObject.maxVal1 > readerObject.maxVal2){

                readerObject.mostPowerfulWeapon1();
            }

            if(readerObject.maxVal2 > readerObject.maxVal1){

                readerObject.mostPowerfulWeapon2();
            }
        }

    }

    if(choice == 3){

        if(option == 1){

            readerObject.strongestShip1();
        }

        if(option == 2){

            readerObject.strongestShip2();
        }

        if(option == 3){

            readerObject.strongestShip3();

            if(readerObject.maxShip1 > readerObject.maxShip2){

                readerObject.strongestShip1();
            }

            if(readerObject.maxShip2 > readerObject.maxShip1){


                readerObject.strongestShip2();
            }

        }

    }

    if(choice == 4){

        if(option == 1){

            readerObject.weakestShip1();
        }

        if(option == 2){

            readerObject.weakestShip2();
        }

        if(option == 3){

            readerObject.weakestShip3();

            if(readerObject.minShip1 < readerObject.minShip2){

                readerObject.weakestShip1();
            }

            if(readerObject.minShip2 < readerObject.minShip1){

                readerObject.weakestShip2();
            }

        }

    }

    if(choice == 5){

        if(option == 1){

            readerObject.printUnarmed1();
        }

        if(option == 2){

            readerObject.printUnarmed2();
        }

        if(option == 3){

            readerObject.printUnarmed1();
            readerObject.printUnarmed2();
        }



    }

    return 0;
}