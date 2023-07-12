#include "travel_package.hpp"

TravelPackage::TravelPackage(const std::string& destination, const double price, const int available_slots)
    : m_destination(destination)
    , m_price(price)
    , m_available_slots(available_slots)
    , m_booked_slots(0)
{
}

std::string TravelPackage::get_destination() const
{
    return m_destination;
}

double TravelPackage::get_price() const
{
    return m_price;
}

int TravelPackage::get_available_slots() const
{
    return m_available_slots;
}

int TravelPackage::get_booked_slots() const
{

    return m_booked_slots;
}

void TravelPackage::set_destination(const std::string& destination)
{
    m_destination = destination;
}

void TravelPackage::get_price(const double price)
{
    m_price = price;
}

void TravelPackage::get_available_slots(const int available_slots)
{
    m_available_slots = available_slots;
}

void TravelPackage::booked_slots(const int booked_slots)
{
    m_booked_slots = booked_slots;
}

void TravelPackage::book_slots(const int slots) 
{
    m_booked_slots += slots;
    m_available_slots -= slots;
}