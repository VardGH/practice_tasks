#include "booking.hpp"

Booking::Booking(const User& user, const TravelPackage& travel_package, const std::string& booking_details)
    : m_user(user)
    , m_travel_package(travel_package)
    , m_booking_details(booking_details)
{
}

User Booking::get_user() const
{
    return m_user;
}

TravelPackage Booking::get_travel_package() const
{
    return m_travel_package;
}

std::string Booking::get_booking_details() const
{
    return m_booking_details;
}

void Booking::set_user(const User& user)
{
    m_user = user;
} 

void Booking::set_booking_details(const std::string& booking_details)
{
    m_booking_details = booking_details;
}

void Booking::set_travel_package(const TravelPackage& travel_package)
{
    m_travel_package = travel_package;
}