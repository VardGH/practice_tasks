#pragma once

#include "doctor.hpp"
#include "patient.hpp"
#include "medical_history.hpp"
#include "report_generator.hpp"
#include <string>
#include <vector>

class ManagementSystem
{
public:
    void register_doctor(const std::string& name, const std::string& specialization, 
                            const int experience, const std::string& contact_info);

    void register_patient(const std::string& name, const std::string& birth_data, 
                            const std::string& gender, const std::string& contact_info);

    void add_med_history_entry(const int patient_index, const std::string& diagnosis, 
                            const std::string& treatment, const std::string& medication);

    void generate_report(const int patient_ndex);

private:
    bool is_valid_patient_index(const int patient_index) const;
private:
    std::vector<Doctor> m_doctors;
    std::vector<Patient> m_patients;
    ReportGenerator m_report_generator;
};