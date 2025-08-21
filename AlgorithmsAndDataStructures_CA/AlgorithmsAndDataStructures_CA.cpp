
#include <iostream>
#include "OrderedArray.h"
#include "MySet.h"
#include "Lead.h"        // NEW include for Lead
#include <fstream>
#include <sstream>

// ======= Helper: trim spaces =======
std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

// ================== CSV FUNCTIONS ==================
// Read leads from a CSV into a set
void readLeadsFromCSV(const std::string& filename, MySet<Lead>& leads) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return;
    }

    std::string line;

    // Optional: skip header if CSV has one
    // std::getline(file, line);

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string name, phone, email;

        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, email, ','); // ignore email for now

        name = trim(name);
        phone = trim(phone);

        if (!name.empty() && !phone.empty()) {
            leads.insert(Lead(name, phone));
        }
    }

    file.close();
}

// Write a set of leads to a CSV
void writeLeadsToCSV(const std::string& filename, const MySet<Lead>& leads) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << "\n";
        return;
    }

    for (int i = 0; i < leads.length(); ++i) {
        file << leads.getElement(i).toCSV() << "\n";
    }

    file.close();
}

// ================== TESTS ==================
void testSetOperations() {
    MySet<int> setA;
    MySet<int> setB;

    setA.insert(1);
    setA.insert(2);
    setA.insert(3);

    setB.insert(3);
    setB.insert(4);
    setB.insert(5);

    std::cout << "\nSet A: ";
    for (int i = 0; i < setA.length(); ++i)
        std::cout << setA.getElement(i) << " ";

    std::cout << "\nSet B: ";
    for (int i = 0; i < setB.length(); ++i)
        std::cout << setB.getElement(i) << " ";

    MySet<int> unionSet = setA | setB;
    std::cout << "\nUnion (A | B): ";
    for (int i = 0; i < unionSet.length(); ++i)
        std::cout << unionSet.getElement(i) << " ";

    MySet<int> intersectionSet = setA & setB;
    std::cout << "\nIntersection (A & B): ";
    for (int i = 0; i < intersectionSet.length(); ++i)
        std::cout << intersectionSet.getElement(i) << " ";
}



void testCSVLeads() {
    MySet<Lead> rep1Leads, rep2Leads;

    readLeadsFromCSV("rep1.csv", rep1Leads);
    readLeadsFromCSV("rep2.csv", rep2Leads);

    MySet<Lead> allUnique = rep1Leads | rep2Leads;
    MySet<Lead> common = rep1Leads & rep2Leads;

    writeLeadsToCSV("unique_leads.csv", allUnique);
    writeLeadsToCSV("common_leads.csv", common);

    std::cout << "\nLead processing complete.\n";
    std::cout << "Unique leads: " << allUnique.length() << "\n";
    std::cout << "Common leads: " << common.length() << "\n";
}

// ================== MAIN ==================
int main() {
    std::cout << "=== OrderedArray Test ===\n";
    OrderedArray<int> arr;
    arr.push(4);
    arr.push(1);
    arr.push(3);
    arr.push(2);

    for (int i = 0; i < arr.length(); ++i)
        std::cout << arr.getElement(i) << " ";
    std::cout << "\n";

    std::cout << "\n=== MySet Test ===\n";
    testSetOperations();

    std::cout << "\n=== Lead Deduplication Test ===\n";
    testCSVLeads();

    return 0;
}
