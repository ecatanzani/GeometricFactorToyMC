#include "config.h"

simu_config::simu_config(const std::string wd) {
    std::string config_file_name{"/simu.conf"};
    get_config_info(parse_config_file(wd, config_file_name));
}

std::string simu_config::parse_config_file(const std::string wd, const std::string config_file) {
	std::string configPath{wd + "/" + config_file};
	std::ifstream input_file(configPath.c_str());
	if (!input_file.is_open()) {
		std::cerr << "\nInput config file not found [" << configPath << "]\n\n";
		exit(100);
	}
	std::string input_string((std::istreambuf_iterator<char>(input_file)), (std::istreambuf_iterator<char>()));
	input_file.close();
	return input_string;
}

void simu_config::get_config_info(const std::string parsed_config) {
	std::string tmp_str;
	std::istringstream input_stream(parsed_config);
	std::string::size_type sz;

	while (input_stream >> tmp_str) {
		if (!strcmp(tmp_str.c_str(), "SphereRadius")) {
			input_stream >> tmp_str;
			sphere_radius = stod(tmp_str, &sz);
		}
        if (!strcmp(tmp_str.c_str(), "TelescopeSize")) {
			input_stream >> tmp_str;
			telescope_lateral = stod(tmp_str, &sz);
		}
        if (!strcmp(tmp_str.c_str(), "TelescopeDistance")) {
			input_stream >> tmp_str;
			telescope_vertical = stod(tmp_str, &sz);
		}
    }
}


void simu_config::PrintConfigPars() {
	std::cout << "\n\n*** Env Config ***\n";
	std::cout << "\nSelected geometry: [Full Sphere]";
	std::cout << "\nDetector geometry: [square]";
	std::cout << "\nLateral detector dimension: [" << telescope_lateral << "] (m)";
	std::cout << "\nVertical detector displacement: [" << telescope_vertical << "] (m)";
	std::cout << "\n\n******************\n";
}

const double simu_config::GetSphereRadius() {
	return sphere_radius;
}

const double simu_config::GetTelescopeLateralSize() {
	return telescope_lateral;
}

const double simu_config::GetTelescopeVerticalDisplacement() {
	return telescope_vertical;
}