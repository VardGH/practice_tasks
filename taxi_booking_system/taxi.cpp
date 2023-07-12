#include "taxi.hpp"

Taxi::Taxi(const std::string& taxi_number, const std::string& name, const std::string& taxi_class)
    : m_taxi_number(taxi_number)
    , m_name(name)
    , m_status("available")
    , m_taxi_class(taxi_class)
{
}

std::string Taxi::get_driver_name() const
{
    return m_name;
}


std::string Taxi::get_taxi_class() const
{
    return m_taxi_class;
}

std::string Taxi::get_status() const
{
    return m_status;
}

std::string Taxi::get_taxi_number() const
{
    return m_taxi_number;
}

void Taxi::set_taxi_number(const std::string& taxi_number)
{
    m_taxi_number = taxi_number;
}

void Taxi::set_driver_name(const std::string& name)
{
    m_name = name;
}

void Taxi::set_status(const std::string& status)
{
    m_status = status;
}

void Taxi::set_taxi_class(const std::string& taxi_class)
{
    m_taxi_class = taxi_class;
}