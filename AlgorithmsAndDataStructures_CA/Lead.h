#pragma once
#ifndef LEAD_H
#define LEAD_H

#include <string>

class Lead {
public:
    Lead(); // default
    Lead(const std::string& name, const std::string& phone);

    std::string getName() const;
    std::string getPhone() const;

    // Comparison for equality (based on phone)
    bool operator==(const Lead& other) const;
    bool operator!=(const Lead& other) const;
    bool operator<(const Lead& other) const;
    bool operator>(const Lead& other) const;
    bool operator<=(const Lead& other) const;
    bool operator>=(const Lead& other) const;

    std::string toCSV() const;

private:
    std::string name;
    std::string phone;
};

#endif
