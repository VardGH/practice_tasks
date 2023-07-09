#pragma once

#include <string>

class Doctor
{
public:
    Doctor(const std::string& name, const std::string& specialization, const int experience, const std::string& contact_info);
    ~Doctor() = default;

public:
    std::string get_name() const;
    std::string get_specialization() const;
    int get_experience() const;
    std::string get_contact_info() const;

    void set_name(const std::string& name);
    void set_specialization(const std::string& specialization);
    void set_experience(const int experience);
    void set_contact_info(const std::string& contact_info);
    
private:
    std::string m_name;
    std::string m_specialization;
    int m_experience;
    std::string m_contact_info;
};