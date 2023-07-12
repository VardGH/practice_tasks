#include "taxi_booking_system.hpp"

void TaxiBookingSystem::register_taxi()
{
    std::string taxi_number;
    std::string driver_name;
    std::string taxi_class;

    std::cout << "Enter taxi number: ";
    std::cin >> taxi_number;
    std::cout << "Enter driver name: ";
    std::cin >> driver_name;
    std::cout << "Enter taxi class (start/comfort/business): ";
    std::cin >> taxi_class;
    m_taxis.push_back(Taxi(taxi_number, driver_name, taxi_class));
    std::cout << "Taxi registered successfully." << std::endl;
}

void TaxiBookingSystem::register_user()
{
    std::string name;
    std::string contact_info;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter contact information: ";
    std::cin >> contact_info;
    m_users.push_back(User(name, contact_info));
    std::cout << "User registered successfully." << std::endl;    
}

void TaxiBookingSystem::save_receipt_to_file(const std::string& filename, const Booking& booking) 
{
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Receipt" << std::endl;
        file << "-------" << std::endl;
        file << "User: " << booking.get_user().get_name() << std::endl;
        file << "Contact: " << booking.get_user().get_contact_info() << std::endl;
        file << "Taxi: " << booking.get_taxi().get_taxi_number() << std::endl;
        file << "Driver: " << booking.get_taxi().get_driver_name() << std::endl;
        file << "Distance: " << booking.get_distance() << " km" << std::endl;
        file << "Class: " << booking.get_taxi().get_taxi_class() << std::endl;
        file << "Fare: $" << booking.get_fare() << std::endl;
        file.close();
        std::cout << "Receipt saved to " << filename << std::endl;
    } else {
        std::cout << "Failed to save receipt to file." << std::endl;
    }
}

void TaxiBookingSystem::book_taxi() 
{
    int user_index;

    std::cout << "Enter your user index (0-" << m_users.size() - 1 << "): ";
    std::cin >> user_index;

    if (user_index < 0 || user_index >= m_users.size()) {
        std::cout << "Invalid user index." << std::endl;
        return;
    }

    std::string taxiNumber;
    std::cout << "Enter taxi number: ";
    std::cin >> taxiNumber;

    Taxi* booked_taxi = nullptr;
    for (auto& taxi : m_taxis) {
        if (taxi.get_taxi_number() == taxiNumber && taxi.get_status() == "available") {
            booked_taxi = &taxi;
            break;
        }
    }

    if (booked_taxi == nullptr) {
        std::cout << "No available taxi with the specified number." << std::endl;
        return;
    }

    double distance;
    std::cout << "Enter distance: ";
    std::cin >> distance;
    
    Booking booking(m_users[user_index], *booked_taxi, distance);
    booked_taxi->set_status("booked");
    booking.print_receipt();
    std::string filename = m_users[user_index].get_name() + ".txt";
    save_receipt_to_file(filename, booking);
}

void TaxiBookingSystem::run() {
    int choice;
    do {
        std::cout << std::endl;
        std::cout << "======Taxi Booking System===" << std::endl;
        std::cout << "1. Register a new taxi" << std::endl;
        std::cout << "2. Register a new user" << std::endl;
        std::cout << "3. Book a taxi" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                register_taxi();
                break;
            case 2:
                register_user();
                break;
            case 3:
                book_taxi();
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 4);
}