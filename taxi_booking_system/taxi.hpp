#pragma once

#include <string>

class Taxi
{
public:
    Taxi(const std::string& taxi_number, const std::string& name, const std::string& taxi_class);
    ~Taxi() = default;

public:
    std::string get_driver_name() const;
    std::string get_taxi_number() const;
    std::string get_status() const;
    std::string get_taxi_class() const;

    void set_driver_name(const std::string& name);
    void set_taxi_number(const std::string& taxi_number);
    void set_status(const std::string& status);
    void set_taxi_class(const std::string& taxi_class);

private:
    std::string m_taxi_number;
    std::string m_name;
    std::string m_status;
    std::string m_taxi_class;
};