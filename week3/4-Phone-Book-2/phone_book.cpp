#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>

using namespace std;


class Contact {
public:

    Contact(int number = -1, string name = ""){
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

    Node* root;

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
                else if(contact.name > current->value.name ){
                    from_left = false;
                    parent = current;
                    current = current->right;
                }
                else{
                    current->value.number = contact.number;
                    return;
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

        int phone_number = -1;
        Node* current = root;
        bool found = false;
        bool more_people = true;

        if(root == NULL){
            more_people = false;
        }

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
                phone_number = current->value.number;
            }
        }
        if(found){
            cout << phone_number << endl;
        } else {
            cout << "NOT FOUND!" << endl;
        }
    }



    //list all records in an alphabetical order
    void list() {
        in_order_print(root);
    }



    //remove a record for a given name
    Node* remove(Node* start, string name){
        root = recursive_remove(start, name);
    }



private:


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



    Node* recursive_remove(Node* rt, string name){
        if(rt == NULL){
            // go to end of function and return rt
            //cout << "NULL" << endl;
        }
        else if(name < rt->value.name){
            rt->left = recursive_remove(rt->left, name);
        }
        else if(name > rt->value.name){
            rt->right = recursive_remove(rt->right, name);
        }
        // found
        else{
            // if leaf node
            if(rt->left == NULL && rt->right == NULL){
                delete rt;
                rt = NULL;
            }
            // if 1 child
            else if(rt->left == NULL){
                Node* tmp = rt;
                rt = rt->right;
                delete tmp;
            }
            else if(rt->right == NULL){
                Node* tmp = rt;
                rt = rt->left;
                delete tmp;
            }
            // has 2 child
            else{
                // find min in right subtree
                Node* current = rt->right;
                while(current->left != NULL){
                    current = current->left;
                }
                // rt->value = min element->value
                rt->value.name = current->value.name;
                rt->value.number = current->value.number;
                // remove min element
                rt->right = recursive_remove(rt->right, current->value.name);
            }
        }
        return rt;
    }
};


int main(){


    int n, number;
    string command, name;
    PhoneBook pb;

    cin >> n;
    while(n--){
        cin >> command;
        if (command == "insert"){
            cin >> number >> name;
            pb.insert(Contact(number, name));
        }
        else if(command == "lookup"){
            cin >> name;
            pb.lookup(name);
        }
        else if(command == "list"){
            pb.list();
        }
        else if(command == "remove"){
            cin >> name;
            pb.remove(pb.root, name);
        }
    }


/*

    pb.insert(Contact(140, "A"));
    //pb.remove(pb.root, "Ivan");
    pb.insert(Contact(1337, "Aba"));
    pb.insert(Contact(360, "USA"));
    pb.insert(Contact(720, "Jon"));
    pb.insert(Contact(420, "Plazma"));
    pb.insert(Contact(3141592, "Bush"));
    pb.insert(Contact(165, "Deci"));
    pb.insert(Contact(911, "Beta"));
    pb.insert(Contact(112, "Baba"));
    pb.insert(Contact(42, "Exa"));

    PhoneBook pb;
    pb.insert(Contact(140, "50"));
    pb.remove(pb.root, "A");
    pb.insert(Contact(360, "30"));
    pb.insert(Contact(720, "80"));
    pb.insert(Contact(420, "70"));
    pb.insert(Contact(3141592, "90"));
    pb.insert(Contact(1337, "60"));
    pb.insert(Contact(165, "75"));
    pb.insert(Contact(911, "85"));
    pb.insert(Contact(112, "95"));
    pb.insert(Contact(42, "65"));
    pb.insert(Contact(42, "67"));
    pb.list();

    pb.remove(pb.root, "50");
    pb.remove(pb.root, "Exa");
    pb.lookup("4");
    pb.lookup("2");
    pb.lookup("8");
    pb.lookup("1");
    pb.lookup("3");
    pb.lookup("5");
    pb.lookup("9");
    cout << endl;

    cout << "NEW PRINT" << endl;
    pb.list();
*/

    return 0;
}






























