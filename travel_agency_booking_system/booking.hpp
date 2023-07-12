#pragma once

#include "user.hpp"
#include "travel_package.hpp"

#include <string>

class Booking
{
public:
    Booking(const User& user, const TravelPackage& travel_package, const std::string& booking_details);
public:
    User get_user() const;
    TravelPackage get_travel_package() const;
    std::string get_booking_details() const;

    void set_user(const User& user);
    void set_travel_package(const TravelPackage& travel_package);
    void set_booking_details(const std::string& booking_details);

private:
    User m_user;
    TravelPackage m_travel_package;
    std::string m_booking_details;
};