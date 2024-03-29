#pragma once

#include "transport_catalogue.h"

namespace transport {

void ProcessRequests(std::istream& in, TransportCatalogue& catalogue, std::ostream& out);

void PrintRoute(std::string& line, TransportCatalogue& catalogue, std::ostream& out);
void PrintStop(std::string& line, TransportCatalogue& catalogue, std::ostream& out);

}