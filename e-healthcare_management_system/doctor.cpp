#include "doctor.hpp"


Doctor::Doctor(const std::string& name, const std::string& specialization, const int experience, const std::string& contact_info)
    : m_name(name)
    , m_specialization(specialization)
    , m_experience(experience)
    , m_contact_info(contact_info)
{
}

std::string Doctor::get_name() const
{
    return m_name;
}

std::string Doctor::get_specialization() const
{
    return m_specialization;
}

int Doctor::get_experience() const
{
    return m_experience;
}


std::string Doctor::get_contact_info() const
{
    return m_contact_info;
}

void Doctor::set_name(const std::string& name)
{
    m_name = name;
}

void Doctor::set_specialization(const std::string& specialization)
{
    m_specialization = specialization;
}

void Doctor::set_experience(const int experience)
{
    m_experience = experience;
}

void Doctor::set_contact_info(const std::string& contact_info)
{
    m_contact_info = contact_info;
}