#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <stdio.h>

std::string arrowCheck(int charact, bool &cont2) {
    if(charact == 224) {
        cont2 = true;
        return("none");
    }

    switch (charact) {
    case 72:
        if(cont2) {cont2 = false; return "up";}
        break;

    case 75:
        if(cont2) {cont2 = false; return "left";}
        break;

    case 80:
        if(cont2) {cont2 = false; return "down";}
        break;

    case 77:
        if(cont2) {cont2 = false; return "right";}
        break;
    
    default:
        if(cont2) {cont2 = false; return "none";}
        break;
    }
    return("go");
}

int main(int argc, char *argv[]) {
    
    std::cout << "******* Notepad-- ***** Press ESC to quit and down arrow to reload. *******\n\n";
    std::string filePath = argv[1] != nullptr? argv[1] : "filename.txt";
    std::string str = "";
    std::ifstream fileRead(filePath);
    str = "";
    char buffer;
    while (fileRead) {
        buffer = fileRead.get();
        str += buffer;
    }
    fileRead.close();
    std::cout << "File read. ";
    system("CLS");
    std::cout << "******* Notepad-- ***** Press ESC to quit and down arrow to reload. *******\n\n";
    std::cout << str;
    bool continue2 = false;
    bool running = true;
    while(running) {
        int charact = getch();
        std::string typeTrue = arrowCheck(charact, continue2);
       if (typeTrue == "none") {
            continue;
        }
        if(typeTrue == "up") {
            std::cout << "\nEnter a path to write to. Current path: " + filePath + " (include filename and extension at end of path): ";
            std::getline(std::cin >> std::ws, filePath);
            std::cout << "Done. Filepath is: " << filePath;
            getch();
            system("CLS");
            std::cout << "******* Notepad-- ***** Press ESC to quit and down arrow to reload. *******\n\n";
            std::cout << str;
            continue;
        }
        if (typeTrue == "down") {            
            system("CLS");
            std::cout << "******* Notepad-- ***** Press ESC to quit and down arrow to reload. *******\n\n";
            std::cout << str;
            
            continue;
        }
        if(typeTrue == "left") {
             std::cout << "\nRead from file (will overwrite current work)? Y/N: ";
            char answer2;
            std::cin >> answer2;
            if(answer2 == 'Y' || answer2 == 'y') {
                std::ifstream fileRead(filePath);
                str = "";
                char buffer;
                while (fileRead) {
                    buffer = fileRead.get();
                    str += buffer;
                }
                fileRead.close();
                std::cout << "File read. ";
                system("CLS");
                std::cout << "******* Notepad-- ***** Press ESC to quit and down arrow to reload. *******\n\n";
                std::cout << str;
                continue;
        } else {
            std::cout << "\nNot reading file.";
            getch();
            system("CLS");
            std::cout << "******* Notepad-- ***** Press ESC to quit and down arrow to reload. *******\n\n";
            std::cout << str;
        }
        }
        if(typeTrue == "right") {
            std::cout << "\nSave? Y/N: ";
            char answer;
            std::cin >> answer;
            if(answer == 'Y' || answer == 'y') {
                std::ofstream file(filePath);
                file << str;
                file.close();
                std::cout << "File saved. ";
                getch();
                system("CLS");
                std::cout << "******* Notepad-- ***** Press ESC to quit and down arrow to reload. *******\n\n";
                std::cout << str;
            } else {
                std::cout << "\nNot saving file.";
                getch();
                system("CLS");
                std::cout << "******* Notepad-- ***** Press ESC to quit and down arrow to reload. *******\n\n";
                std::cout << str;
            }
            continue;
        }

        

        if(charact == 27) {
            break;
        }

        switch(charact) {
            case 13:
                std::cout << std::endl;
                str += "\n";
                //str += "|";
                break;

            case 8: 
                if(str == "") {
                    system("CLS");
                    std::cout << "******* Notepad-- ***** Press ESC to quit and down arrow to reload. *******\n\n";
                    std::cout << str;
                    break;
                }
                std::cout << "\b \b";

                    if(str.at(str.length()-1) == '\n') {
                        system("CLS");
                        std::cout << "******* Notepad-- ***** Press ESC to quit and down arrow to reload. *******\n\n";
                        str.erase(str.length()-1);
                        std::cout << str;
                    } else {
                        str.erase(str.length()-1);
                    }
                break;

            default:
                std::cout << (char)charact;
                str += (char)charact;
                break;
        }
    }
}