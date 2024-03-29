#include "stat_reader.h"

#include <iomanip>

namespace transport {

void ProcessRequests(std::istream& in, TransportCatalogue& catalogue, std::ostream& out) {
    size_t requests_count;
    in >> requests_count;
    for (size_t i = 0; i < requests_count; ++i) {
        std::string keyword, line;
        in >> keyword;
        std::getline(in, line);
        if (keyword == "Bus") {
            PrintRoute(line, catalogue, out);
        }
        if (keyword == "Stop") {
            PrintStop(line, catalogue, out);
        }
    }
}

void PrintRoute(std::string& line, TransportCatalogue& catalogue, std::ostream& out) {
    std::string bus_number = line.substr(1, line.npos);
    if (catalogue.FindRoute(bus_number)) {
        auto bus_stat = catalogue.GetBusStat(bus_number);
        out << "Bus " << bus_number << ": " << bus_stat->stops_count << " stops on route, " 
            << bus_stat->unique_stops_count << " unique stops, " << std::setprecision(6) 
            << bus_stat->route_length << " route length, " 
            << bus_stat->curvature << " curvature\n";
    }
    else {
out << "Bus " << bus_number << ": not found\n";
    }
}

void PrintStop(std::string& line, TransportCatalogue& catalogue, std::ostream& out) {
    std::string stop_name = line.substr(1, line.npos);
    if (catalogue.FindStop(stop_name)) {
        out << "Stop " << stop_name << ": ";
        auto buses = catalogue.GetBusesByStop(stop_name);
        if (!buses.empty()) {
            std::cout << "buses ";
            for (const auto& bus : buses) {
                out << bus << " ";
            }
            out << "\n";
        }
        else {
            out << "no buses\n";
        }
    }
    else {
        out << "Stop " << stop_name << ": not found\n";
    }
}

}