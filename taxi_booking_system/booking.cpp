#include "booking.hpp"

Booking::Booking(const User& user, const Taxi& taxi, const double distance)
    : m_user(user)
    , m_taxi(taxi)
    , m_distance(distance)
{
    calculate_fare();
}


void Booking::calculate_fare()
{
    std::string taxi_class = m_taxi.get_taxi_class();

    double fare_multiplier = 1.0;

    if (taxi_class == "comfort") {
        fare_multiplier = 1.8;
    } else if(taxi_class == "business") {
        fare_multiplier = 3.0;
    }

    m_fare = m_distance * fare_multiplier;
}

void Booking::print_receipt() const 
{
    std::cout << "Receipt" << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << "User: " << m_user.get_name() << std::endl;
    std::cout << "Contact: " << m_user.get_contact_info() << std::endl;
    std::cout << "Taxi: " << m_taxi.get_taxi_number() << std::endl;
    std::cout << "Driver: " << m_taxi.get_driver_name() << std::endl;
    std::cout << "Distance: " << m_distance << " km" << std::endl;
    std::cout << "Class: " << m_taxi.get_taxi_class() << std::endl;
    std::cout << "Fare: $" << m_fare << std::endl;
}

User Booking::get_user() const
{
    return m_user;
}

Taxi Booking::get_taxi() const
{
    return m_taxi;
}

double Booking::get_distance() const
{
    return m_distance;
}

double Booking::get_fare() const
{
    return m_fare;
}

void Booking::set_user(const User& user)
{
    m_user = user;
}

void Booking::set_taxi(const Taxi& taxi)
{
    m_taxi = taxi;
}

void Booking::set_distance(const double distance)
{
    m_distance = distance;
}

void Booking::set_fare(const double fare)
{
    m_fare = fare;
}