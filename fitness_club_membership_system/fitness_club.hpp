#pragma once

#include "member.hpp"

#include <string>
#include <vector>
#include <fstream>

class FitnessClub
{
public:
    FitnessClub() = default;
    ~FitnessClub() = default;
public:
    void register_member(const std::string& name, const std::string& contact_info, const MembershipLevel membership_level);
    void enter_area(Member& member, const std::string& area_name);
    void generate_monthly_statistics(const Member& member);
    void generate_monthly_bill(const Member& member);
    Member& get_member(const std::string& name);
    void downgrade_membership(Member& member);
    void upgrade_membership(Member& member);
     
private:
    double calculate_monthly_fee(const Member& member); 
private:
    std::vector<Member> m_members;

};