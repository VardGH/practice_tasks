#pragma once

#include <string>

class User
{
public:
    User(const std::string& name, const std::string& contact_info);
    ~User() = default;

public:
    std::string get_name() const;
    std::string get_contact_info() const;

    void set_name(const std::string& name);
    void set_contact_info(const std::string& contact_info);

private:
    std::string m_name;
    std::string m_contact_info;
};