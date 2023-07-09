#include "patient.hpp"

Patient::Patient(const std::string& name, const std::string& birth_data, const std::string& gender, const std::string& contact_info)
    : m_name(name)
    , m_birth_data(birth_data)
    , m_gender(gender)
    , m_contact_info(contact_info)
    , m_med_history("No Diagnosis", "No Treatment", "No Medication")
{
}

std::string Patient::get_name() const
{
    return m_name;
}

std::string Patient::get_birth_data() const
{
    return m_birth_data;
}

std::string Patient::get_gender() const
{
    return m_gender;
}

MedicalHistory Patient::get_med_history() const
{
    return m_med_history;
}

std::string Patient::get_contact_info() const
{
    return m_contact_info;
}

void Patient::set_name(const std::string& name)
{
    m_name = name;
}

void Patient::set_birth_data(const std::string& birth_data)
{
    m_birth_data = birth_data;
}

void Patient::set_contact_info(const std::string& contact_info)
{
    m_contact_info = contact_info;
}

void Patient::set_gender(const std::string& gender)
{
    m_gender = gender;
}

void Patient::set_med_history(const MedicalHistory& med_history) 
{
    m_med_history = med_history;
}