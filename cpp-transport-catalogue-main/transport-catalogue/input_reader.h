#pragma once

#include "transport_catalogue.h"

#include <iostream>

namespace transport {

struct RouteInfo {
    std::string bus_number;
    std::vector<const Stop*> stops;
    bool is_circle;
};

void FillCatalogue(std::istream& in, TransportCatalogue& catalogue);

std::pair<std::string, geo::Coordinates> FillStop(std::string& line);
void FillStopDistances(std::string& line, TransportCatalogue& catalogue);
RouteInfo FillRoute(std::string& line, TransportCatalogue& catalogue);

}
  