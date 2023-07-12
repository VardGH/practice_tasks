#pragma once

#include <string>

class TravelPackage
{
public:
    TravelPackage(const std::string& destination, const double price, const int available_slots);

public:
    std::string get_destination() const;
    double get_price() const;
    int get_available_slots() const;
    int get_booked_slots() const;

    void set_destination(const std::string& destination);
    void get_price(const double price);
    void get_available_slots(const int available_slots);
    void booked_slots(const int booked_slots);

    void book_slots(const int slots);
    
private:
    std::string m_destination;
    double m_price;
    int m_available_slots;
    int m_booked_slots;
};