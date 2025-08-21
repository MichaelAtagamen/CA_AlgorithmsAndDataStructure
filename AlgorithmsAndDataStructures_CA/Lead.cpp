#include "Lead.h"

Lead::Lead() : name(""), phone("") {}

Lead::Lead(const std::string& name, const std::string& phone)
    : name(name), phone(phone) {
}

std::string Lead::getName() const { return name; }
std::string Lead::getPhone() const { return phone; }

bool Lead::operator==(const Lead& other) const {
    return phone == other.phone;
}

bool Lead::operator!=(const Lead& other) const {
    return !(*this == other);
}

bool Lead::operator<(const Lead& other) const {
    return phone < other.phone;
}

bool Lead::operator>(const Lead& other) const {
    return phone > other.phone;
}

bool Lead::operator<=(const Lead& other) const {
    return phone <= other.phone;
}

bool Lead::operator>=(const Lead& other) const {
    return phone >= other.phone;
}

std::string Lead::toCSV() const {
    return name + "," + phone;
}
