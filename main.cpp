/*
Shahrukh Showkath sxs200232
*/
#include <stdio.h>
#include "Node.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "BinTree.h"
using namespace std;


/* Prompts user for two files names. Reads first file and performs the commands attributed
    to the file, including inserting, deleting, searching, editing, and sorting nodes for
    a binary search tree. */
int main()
{
    string file2;
    cin >> file2;
    string fileName;
    cin >> fileName;
    //fileName = ("test.txt");
    string line;
    BinTree<Game> BST;
    string n;
    int s;
    string i;
    int p;
    string revenue;
    float rev;
    string key;
    bool check;
    Game g;
    ifstream dataFile;
    dataFile.open(file2);
    if (dataFile.is_open())
    {
        while (getline(dataFile, line) && line.compare("\n") != 0)
        {
            p = (int) line.find(", ");
            n = line.substr(0, p);
            line = line.substr(p + 2, line.length() - 1);
            
            p = (int) line.find(", ");
            s = stoi(line.substr(0, p));
            line = line.substr(p + 2, line.length() - 1);
            
            p = (int) line.find(", ");
            i = (line.substr(0, p));
            line = line.substr(p + 2, line.length() - 1);
            
            p = stoi(line);
            
            g.setName(n);
            g.setInitials(i);
            g.setPlays(p);
            g.setScore(s);
            
            BST.Insert(g, BST.getRoot());
        }
    }
    
    ifstream infoFile;
    infoFile.open(fileName);
    
    /* Iterates through command file and performs the relevant commands */
    if (infoFile.is_open())
    {
        while (getline(infoFile, line) && line.compare("\n") != 0)
        {
            if (line != "\n")
                {
                stringstream ss (line);
                string word;
                int command;
                ss >> command;
                switch(command)
                {
                    // Inserts node into binary search tree
                    case 1:
                        
                        line = line.substr(3, line.length() - 1);
                        n = line.substr(0, line.find("\""));
                        line = line.substr((line.find("\""))+2, line.length() - 1);
                        ss.str(std::string());
                        ss.str(line);
                        
                        ss >> s;
                        ss >> i;
                        ss >> p;
                        ss >> revenue;
                        revenue = revenue.substr(1, revenue.length() - 2);
                        rev = stof(revenue);
                        g.setName(n);
                        g.setInitials(i);
                        g.setPlays(p);
                        g.setScore(s);
                        
                        BST.Insert(g, BST.getRoot());
                        rev =(float) (p / 4.0);
                        std::cout << "RECORD ADDED" << std::endl;
                        std::cout << "Name: " << n << std::endl;
                        std::cout << "High Score: " << s << std::endl;
                        std::cout << "Initials: " << i << std::endl;
                        std::cout << "Plays: " << p << std::endl;
                        std::cout << "Revenue: $";
                        std::cout << std::fixed << std::setprecision(2) << rev << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        break;
                    
                    // Searches for a node    
                    case 2:
                        
                        key = line.substr(2, line.length() - 1);
                        check = false;
                        if (!BST.Search(BST.root, key, check))
                        {
                            cout << key << " NOT FOUND" << endl;
                        }
                        cout << endl;
                        cout << endl;
                        break;
                    
                    // Edits a node 
                    case 3:
                    
                        line = line.substr(3, line.length() - 1);
                        n = line.substr(0, line.find("\""));
                        line = line.substr((line.find("\""))+2, line.length() - 1);
                        ss.str(std::string());
                        ss.str(line);
                        ss >> s;
                        ss >> i;
                        BST.Edit(n, s, i);
                        cout << endl;
                        cout << endl;
                        break;
                    
                    // Deletes a node
                    case 4:
                        
                        key = line.substr(2, line.length() - 1);
                        
                        n = (BST.retNode(BST.getRoot(), key))->getData().getName();
                        s = (BST.retNode(BST.getRoot(), key))->getData().getScore();
                        i = (BST.retNode(BST.getRoot(), key))->getData().getInitials();
                        p = (BST.retNode(BST.getRoot(), key))->getData().getPlays();
                        BST.Delete(BST.retNode(BST.getRoot(), key));
                        rev = (float) (p / 4.0);
                        cout << "RECORD DELETED" << endl;
                        cout << "Name: " << n << endl;
                        cout << "High Score: " << to_string(s) << endl;
                        cout << "Initials: " << i << endl;
                        cout << "Plays: " << to_string(p) << endl;
                        cout << "Revenue: $";
                        cout << fixed << setprecision(2) << rev << endl;
                        cout << endl;
                        cout << endl;
                        break;
                    
                    //Prints out the BST in ascending or descending order by name 
                    case 5:
                        key = line.substr(2, line.length() - 1);
                        if (key == "asc")
                        {
                            cout << "RECORDS SORTED ASCENDING" << endl;
                            BST.printInorder(BST.getRoot());
                            cout << endl;
                        }
                        else if (key == "des")
                        {
                            cout << "RECORDS SORTED DESCENDING" << endl;
                            BST.printReverseOrder(BST.getRoot());
                            cout << endl;
                        }
                        cout << endl;
                        break;
                }
            }
        }
    }
    // Outputs database to a new file
    string file3;
    file3 = "cidercade.dat";
    ofstream fileStream;
    fileStream.open(file3);
    if (fileStream.is_open())
    {
        BST.printFile(BST.getRoot(), fileStream); 
    }
    fileStream.close();
    
    return 0;
}   
