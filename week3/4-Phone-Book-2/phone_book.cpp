#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;


class Contact {
public:

    Contact(int number, string name){
        this->name = name;
        this->number = number;
    }
    string name;
    int number;
};


class PhoneBook {
private:
    class Node {
    public:
        Node(Contact value, Node* left = NULL, Node* right = NULL)
            :value(value), left(left), right(right){
        }
        Contact value;
        Node* left;
        Node* right;
    };
public:



    //constructor
    PhoneBook(): root(NULL){
    }
    //destructor
    ~PhoneBook(){
        delete_tree(root);
    }

    //inserts a new contact
    void insert(Contact contact){

        if(root == NULL){
            root = new Node(contact);
        }
        else{
            Node* parent = NULL;
            Node* current = root;
            bool from_left;
            while(current != NULL){
                if(contact.name < current->value.name){
                    from_left = true;
                    parent = current;
                    current = current->left;
                }
                else{
                    from_left = false;
                    parent = current;
                    current = current->right;
                }
            }
            if(from_left){
                parent->left = new Node(contact);
            }
            else{
                parent->right = new Node(contact);
            }
        }
    }

    //lookup a name and print its phone number
    void lookup(string name){
        if(root->value.name == name){
            cout << root->value.number;
        }
        else{
            Node* current = root;
            bool found = false;
            bool more_people = true;

            while(!found && more_people){

                if(name < current->value.name){
                    if(current->left != NULL){
                        current = current->left;
                    }else{
                        more_people = false;
                    }
                }
                else if(name > current->value.name){
                    if(current->right != NULL){
                        current = current->right;
                    }else{
                        more_people = false;
                    }
                }else{
                    found = true;
                }
            }

            if(found){
                cout << current->value.number << endl;
            }else{
                cout << "NOT FOUND!" << endl;
            }

        }
    }

    //list all records in an alphabetical order
    void list() {
        in_order_print(root);
    }

    //remove a record for a given name
    void remove(string name){

    }





private:
   Node* root;

    void delete_tree(Node* current){
        if(current != NULL){
            delete_tree(current->left);
            delete_tree(current->right);
            delete current;
        }
    }

    void in_order_print(Node* current){

        if(current != NULL){
            in_order_print(current->left);
            cout << current->value.name << " " << current->value.number << endl;
            in_order_print(current->right);
        }
    }



};


int main(){


    PhoneBook pb;
    pb.insert(Contact(140, "Ivan"));
    pb.insert(Contact(1337, "Aba"));
    pb.insert(Contact(360, "USA"));
    pb.insert(Contact(720, "Jon"));
    pb.insert(Contact(420, "Plazma"));
    pb.insert(Contact(3141592, "Bush"));
    pb.insert(Contact(165, "Deci"));
    pb.insert(Contact(911, "Beta"));
    pb.insert(Contact(112, "Baba"));
    pb.insert(Contact(42, "Exa"));
    /*
    */
    pb.list();

    pb.lookup("Plazma");
    pb.lookup("Aba");
    pb.lookup("USA");
    pb.lookup("NONE");
    pb.lookup("Baba");
    pb.lookup("Exa");
    pb.lookup("ivan");

    cout << endl;



    return 0;
}






























