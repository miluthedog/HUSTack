#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Node {
    int cof;  // Coefficient
    int exp;   // Exponent
    Node* next; // Pointer to the next term
};

// HashMap to store polynomial heads
unordered_map<int, Node*> header;

// Function to create a new polynomial
void create(int id) {
    if (header.find(id) == header.end()) {
        header[id] = nullptr; // Initialize with null
    }
}

// Function to add a term to a polynomial
void addterm(int id, int coef, int exp) { 
    if (header.find(id) == header.end()) {
        create(id); // Create polynomial if it doesn't exist
    }

    Node* new_node = new Node();
    new_node->cof = coef;
    new_node->exp = exp;
    new_node->next = nullptr;

    // Insert the new term in sorted order based on exponent
    Node* current = header[id];
    Node* prev = nullptr;

    while (current != nullptr && current->exp > exp) {
        prev = current;
        current = current->next;
    }

    // If the exponent already exists, just add the coefficient
    if (current != nullptr && current->exp == exp) {
        current->cof += coef; // Add coefficients
        delete new_node; // Delete the new node since it's not needed
    } else {
        // Insert the new node in the linked list
        if (prev == nullptr) {
            // Inserting at the head
            new_node->next = header[id];
            header[id] = new_node;
        } else {
            // Inserting in between or at the end
            new_node->next = current;
            prev->next = new_node;
        }
    }
}

// Function to evaluate the polynomial at a given variable value
void evaluatepoly(int id, int variable) {
    if (header.find(id) == header.end()) {
        cout << "0" << endl; // Print 0 if polynomial does not exist
        return;
    }

    Node* current = header[id];
    int result = 0;

    while (current != nullptr) {
        result += current->cof * pow(variable, current->exp); // Evaluate each term
        current = current->next;
    }

    cout << result << endl; // Print the result
}

// Function to add two polynomials and store the result in a new polynomial
void addpoly(int id1, int id2, int rid) {
    if (header.find(id1) == header.end() || header.find(id2) == header.end()) {
        return; // If one of the polynomials does not exist, do nothing
    }

    Node* poly1 = header[id1];
    Node* poly2 = header[id2];
    Node* result_head = nullptr; // Head of the new polynomial
    Node* current = nullptr; // Pointer to traverse the new polynomial

    while (poly1 != nullptr || poly2 != nullptr) {
        Node* new_node = new Node();
        
        if (poly1 == nullptr) {
            new_node->cof = poly2->cof;
            new_node->exp = poly2->exp;
            poly2 = poly2->next;
        } else if (poly2 == nullptr) {
            new_node->cof = poly1->cof;
            new_node->exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly1->exp == poly2->exp) {
            new_node->cof = poly1->cof + poly2->cof;
            new_node->exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            new_node->cof = poly1->cof;
            new_node->exp = poly1->exp;
            poly1 = poly1->next;
        } else {
            new_node->cof = poly2->cof;
            new_node->exp = poly2->exp;
            poly2 = poly2->next;
        }

        new_node->next = nullptr;

        // Add new node to the result polynomial
        if (result_head == nullptr) {
            result_head = new_node; // First node
            current = new_node;
        } else {
            current->next = new_node; // Append to the result
            current = current->next;
        }
    }

    header[rid] = result_head; // Store the result polynomial
}

// Function to print a polynomial
void printpoly(int id) {
    if (header.find(id) == header.end()) {
        return; // If polynomial doesn't exist, do nothing
    }

    Node* current = header[id];
    while (current != nullptr) {
        cout << current->cof << " " << current->exp; // Print coefficient and exponent
        if (current->next != nullptr) {
            cout << " "; // Space between terms
        }
        current = current->next;
    }
    cout << endl; // End line after printing polynomial
}

// Function to destroy a polynomial
void destroy(int id) {
    if (header.find(id) == header.end()) return;

    Node* current = header[id];
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current; // Free memory
        current = next_node;
    }
    header.erase(id); // Remove from hashmap
}

int main() {
    string input;
    while (true) {
        cin >> input;
        if (input == "*") {
            break; // Exit on '*'
        } else if (input == "Create") {
            int poly_id;
            cin >> poly_id;
            create(poly_id);
        } else if (input == "AddTerm") {
            int poly_id, coef, exp;
            cin >> poly_id >> coef >> exp;
            addterm(poly_id, coef, exp);
        } else if (input == "EvaluatePoly") {
            int poly_id, variable_value;
            cin >> poly_id >> variable_value;
            evaluatepoly(poly_id, variable_value);
        } else if (input == "AddPoly") {
            int poly_id1, poly_id2, result_poly_id;
            cin >> poly_id1 >> poly_id2 >> result_poly_id;
            addpoly(poly_id1, poly_id2, result_poly_id);
        } else if (input == "PrintPoly") {
            int poly_id;
            cin >> poly_id;
            printpoly(poly_id);
        } else if (input == "Destroy") {
            int poly_id;
            cin >> poly_id;
            destroy(poly_id);
        }
    }
    return 0;
}