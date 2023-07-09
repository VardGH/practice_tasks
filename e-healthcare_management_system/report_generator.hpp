#pragma once

#include "patient.hpp"
#include <iostream>
#include <fstream>
#include "medical_history.hpp"

class ReportGenerator
{
public:
    void generate_report(const Patient& patient);
};