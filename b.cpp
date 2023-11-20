#include <iostream>
#include <string>
#include <cctype>
#include <type_traits>
using namespace std;



class Node {
public:
    string name;
    int quantity;
    float price;
    Node* next;
    Node* previous;
};


class linkedList{
    private:
    Node* head;
    public:
    linkedList() : head(nullptr) {}

    void insertValue(string n, int q, int p){
        Node* tmpNode = new Node;
        tmpNode->name = n;
        tmpNode->quantity = q;
        tmpNode->price = p;
        tmpNode->next = nullptr;
        tmpNode->previous = nullptr;
    
        if(head == nullptr){
            head = tmpNode;
        } else{
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = tmpNode;
            tmpNode->previous = temp;
        }}

    void deleteNode(int val) {
        Node* currentNode = head;
        int currentPosition = 0;

        while (currentNode != nullptr && currentPosition < val) {
            currentNode = currentNode->next;
            currentPosition++;
        }

        if (currentNode == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        if (currentNode->previous != nullptr) {
            currentNode->previous->next = currentNode->next;
        }

        if (currentNode->next != nullptr) {
            currentNode->next->previous = currentNode->previous;
        }

        if (currentNode == head) {
            head = currentNode->next;
        }

        delete currentNode;
    }
    void replaceValue(int position, string n, int what) {
        Node* currentNode = head;
        int currentPosition = 0;

        while (currentNode != nullptr && currentPosition < position) {
            currentNode = currentNode->next;
            currentPosition++;
        }
        if (currentNode == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        if (what == 1) {
            currentNode->name = n;
        } else if (what == 2) {
            currentNode->quantity = stoi(n);
        } else if (what == 3) {
            currentNode->price = stof(n);
        }
        
    }

    void addQuantity(int position, int add) {
        Node* currentNode = head;
        int currentPosition = 0;

        while (currentNode != nullptr && currentPosition < position) {
            currentNode = currentNode->next;
            currentPosition++;
        }
        if (currentNode == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }
        currentNode->quantity += add;
    }

    void print(float val) {
        Node* go = head;
        for (float i = 0; i < val; i++){go = go->next;}
        cout << "Name: " << go->name << " Quantity: " << go->quantity << " Price: Rp. " << go->price <<endl;
        }
    
    void printAllName() {
        Node* go = head;
        cout << "No\tName" << endl;
        while (go != nullptr) {
            int i = 1;
            cout << i <<".\t" << go->name <<endl;
            go = go->next;
            i++;
        }
        cout << endl;
    } 

    void printAllNameQuantity() {
        Node* go = head;
        cout << "No \t Name \t Quantity" << endl;
        while (go != nullptr) {
            int i = 1;
            cout << i <<".\t" << go->name << "\t" << go->quantity << endl;
            go = go->next;
            i++;
        }
        cout << endl;
    } 


    void printAll() {
        Node* go = head;
        cout << "No\tName\tStock\tPrice" << endl;
        while (go != nullptr) {
            int i = 1;
            cout << i <<".\t" << go->name << "\t" << go->quantity << "\t" << go->price <<endl;
            go = go->next;
            i++;
        }
        cout << endl;
    } 

    int checkSize() {
        Node* go = head;
        int i=0;
        while (go != nullptr) {
            i++;
            go = go->next;
        }
        return i;
    } 

    int getQuantity(int input) {
        Node* go = head;
        int i=0;
        while (i !=input) {
            go = go->next;
            i++;
        }
        return go->quantity;
    }
};

class functions {
    private:
    linkedList catalog;
    

    public:
    int checkEmpty(){
        if (catalog.checkSize() == 0) {
            cout <<"The catalog is empty!"<<endl;
            return 0;
        } else {
            return 1;
        }
    }

    void insertItem(){
        int tempQuantity;
        string tempName;
        float tempPrice;

        cout << "Insert the item name: ";
        cin >> tempName;
        cout << "Insert the item quantity: ";
        cin >> tempQuantity;
        cout << "Insert the item price: ";
        cin >> tempPrice;

        catalog.insertValue(tempName, tempQuantity, tempPrice);
    } 

    void deleteItem(){
        if (checkEmpty() == 0) {return;}
        int input;
        
        catalog.printAllName();
        cout << "Which item do you want to delete?" << endl;
        cin >> input;

        if (input>catalog.checkSize() || input <1) {
            cout << "Your input is not valid!";
            deleteItem();
        } else {
            catalog.deleteNode(input-1);
            cout << "Item has been successfully deleted"<< endl;
        }
    }

    void printCatalog(){
        if (checkEmpty() == 0) {return;}
        catalog.printAll();
    }

    void addStock(){
        if (checkEmpty() == 0) {return;}

        int index, quantity;
        
        catalog.printAllNameQuantity();

        cout << "Which item do you want to add the stock?" << endl;
        cin >> index;

        if (index>catalog.checkSize() || index <1) {
            cout << "Your input is not valid!";
            addStock();
        } else {
            if (index>catalog.checkSize() || index <1) {
                cout << "Your input is not valid!";
            } else {
                cout << "How much would be restocked?" << endl;
                cin >> quantity;
                catalog.addQuantity(index-1,quantity);
                cout << "Item has been successfully restocked"<< endl;
            }
        }
        
    }

    void replaceData() {
        if (checkEmpty() == 0) {return;}

        int index, type = 0;
        string data;
        catalog.printAll();

        cout << endl << "Which index do you want to change?"<<endl;
        cin >> index;

        cout << "What do you want to change?"<<endl;        
        cout << "1. Name"<<endl;  
        cout << "2. Quantity"<<endl;  
        cout << "3. Price"<<endl;  
        cin >> type;

        cout << "Data: ";

        cin >> data;
        catalog.replaceValue(index-1,data,type);
        cout << "Data has been replaced!"<<endl;
    }
};

int main() {
    functions fun;
    string input;
    cout << "Welcome to your item management system!" << endl << endl;

    

    while (input[0] != 48) {
        cout << "What would you like to do?" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Show catalog" << endl;
        cout << "2. Insert new item" << endl;
        cout << "3. Delete an item" << endl;
        cout << "4. Add stock" << endl;
        cout << "5. Replace data" << endl;
        
        cin >> input;
        cout << endl;
        
        if ((!isdigit(input[0])) || input[0]>54) {
        cout << "Your input is not valid!";
        } if (input[0] == 49) {
            fun.printCatalog();
        } if (input[0] == 50) {
            fun.insertItem();
        } if (input[0] == 51) {
            fun.deleteItem();
        } if (input[0] == 52) {
            fun.addStock();
        } if (input[0] == 53) {
            fun.replaceData();
        }

        cout <<endl;
    }



}   
