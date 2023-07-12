#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "taxi.hpp"
#include "user.hpp"
#include "booking.hpp"

class TaxiBookingSystem
{
public:
    void register_taxi();
    void register_user();
    void book_taxi();
    void run();
private:
    void save_receipt_to_file(const std::string& filename, const Booking& booking);
private:
    std::vector<Taxi> m_taxis;
    std::vector<User> m_users;
};