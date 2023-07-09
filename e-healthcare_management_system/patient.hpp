#pragma once

#include <string>
#include <vector>
#include "medical_history.hpp"

class Patient
{
public:
    Patient(const std::string& name, const std::string& birth_data, const std::string& gender, const std::string& contact_info);

public:
    std::string get_name() const;
    std::string get_birth_data() const;
    std::string get_gender() const;
    std::string get_contact_info() const;
    MedicalHistory get_med_history() const;

    void set_name(const std::string& name); 
    void set_birth_data(const std::string& birth_data);
    void set_gender(const std::string& gender);
    void set_contact_info(const std::string& contact_info);
    void set_med_history(const MedicalHistory& med_history);

private:
    std::string m_name;
    std::string m_birth_data;
    std::string m_gender;
    std::string m_contact_info;
    MedicalHistory m_med_history;
};