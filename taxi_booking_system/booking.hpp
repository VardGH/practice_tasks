#pragma once

#include "taxi.hpp"
#include "user.hpp"
#include <iostream>

class Booking
{
public:
    Booking(const User& user, const Taxi& taxi, const double distance);

public:
    User get_user() const;
    Taxi get_taxi() const;
    double get_distance() const;
    double get_fare() const;

    void set_user(const User& user);
    void set_taxi(const Taxi& taxi);
    void set_distance(const double distance);
    void set_fare(const double fare);

    void calculate_fare();
    void print_receipt() const;

private:
    User m_user;
    Taxi m_taxi;
    double m_distance;
    double m_fare;
};