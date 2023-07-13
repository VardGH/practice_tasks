#include <iostream>
#include "member.hpp"
#include "fitness_club.hpp"

int main()
{
    FitnessClub club;

    club.register_member("John Doe", "john.doe@example.com", STANDARD);
    club.register_member("Jane Smith", "jane.smith@example.com", PREMIUM);

    Member& john = club.get_member("John Doe");
    club.enter_area(john, "Fitness Area");
    club.enter_area(john, "Massage");
    club.enter_area(john, "Pool");
    club.enter_area(john, "Fitness Area");

    Member& jane = club.get_member("Jane Smith");
    club.enter_area(jane, "Fitness Area");
    club.enter_area(jane, "Massage");
    club.enter_area(jane, "Massage");
    club.enter_area(jane, "Pool");
    club.enter_area(jane, "Pool");
    club.enter_area(jane, "Pool");

    club.generate_monthly_statistics(john);
    club.generate_monthly_statistics(jane);

    club.upgrade_membership(john);
    club.enter_area(john, "Pool");
    club.enter_area(john, "Fitness Area");
    club.enter_area(john, "Massage");
    club.enter_area(john, "Pool");
    club.enter_area(john, "Pool");
    club.enter_area(john, "Fitness Area");

    club.downgrade_membership(jane);
    club.enter_area(jane, "Fitness Area");
    club.enter_area(jane, "Massage");
    club.enter_area(jane, "Fitness Area");
    club.enter_area(jane, "Pool");

    club.generate_monthly_statistics(john);
    club.generate_monthly_statistics(jane);

}