#pragma once

#include "user.hpp"
#include "travel_package.hpp"
#include "booking.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class TravelAgency
{
public:
    void register_user();
    void register_travel_package();
    void search_and_book();
    void generate_ticket(const Booking& booking);
    void generate_report();

    void run();
private:
    std::vector<TravelPackage> m_travel_packages;
    std::vector<User> m_users;
    std::vector<Booking> m_bookings;
};