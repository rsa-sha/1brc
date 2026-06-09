#include <algorithm>
#include <charconv>
#include <fcntl.h>
#include <filesystem>
#include <iostream>
#include <limits>
#include <string>
#include <sys/mman.h>
#include <unordered_map>
#include <vector>

const std::string DEFAULT_FILE = "measurements.txt";

inline int parse_number(const char *st, const char *end) {
	bool neg = (st[0]=='-' );
	if (neg)++st;
	int v = 0;
	while (st < end) {
		if (st[0] != '.')
			v = v * 10 + (st[0]-'0');
		st++;
	}
	return neg ? -v:v;

}

struct LocationData {
	int	min = std::numeric_limits<int>::max();
	int	max = std::numeric_limits<int>::lowest();
	int	tot = 0;
	int	count = 0;

	inline void update (int temp) {
		min = std::min(min, temp);
		max = std::max(max, temp);
		tot += temp;
		count++;
	}
};

class BRC {
public:
	BRC(std::string file_name) {
		_file = file_name;
	}

	int parse() {
		// Read file by batched lines
		int fd = open(_file.c_str(), O_RDONLY);
		if (fd == -1) {
			std::cerr << "Failed to open file\n";
			return -1;
		}
		auto size = std::filesystem::file_size(_file);
		char *file_data = static_cast<char *>(
				mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0)
				);
		if (!file_data) {
			std::cerr << "Failed to mmap file\n";
			return 1;
		}
		char *p = file_data;
		char *e = file_data + size;
		while (p < e) {
			// parse city
			while (*p == '\n')++p;
			char *st = p;
			while (p < e && *p != ';')++p;
			std::string_view city(st, p-st);
			++p;	// skip ';'
			// parse temp
			char *val = p;
			while (p < e && *p != '\n')++p;
			std::string_view temp_str(val, p - val);
			int temp = 0;
			/*
			auto [ptr, ec] = std::from_chars(temp_str.data(), temp_str.data() + temp_str.size(), temp);
			if (ec ==  std::errc()) {
			*/
			temp = parse_number(temp_str.data(), temp_str.data() + temp_str.size());
			auto it = _data.find(city);
			if (it == _data.end()) {
				auto [newItr, inserted] = _data.emplace(city, LocationData{temp, temp, temp, 1});
				it = newItr;
			}
			it->second.update(temp);
			//}
		}
		return 0;
	}

	// Dumping values
	void display_all() {
		for (auto &[city, location]: _data) {
			std::cout << "City: " << city << " | Min -> " << location.min/10.0 << " | Max -> " << location.max/10.0 << " | Avg -> " << (location.tot / 10.0f) / location.count <<"\n";
		}
	}

	void display_sorted() {
		std::vector<std::string> locations;
		locations.reserve(_data.size());
		for(const auto &[key, _]:_data)
			locations.emplace_back(key);
		std::sort(locations.begin(), locations.end());
		for (auto city: locations) {
			LocationData location = _data[city];
			std::cout << "City: " << city << " | Min -> " << location.min/10.0 << " | Max -> " << location.max/10.0 << " | Avg -> " << (location.tot / 10.0f) / location.count <<"\n";
		}
	}
private:
	std::string _file;

	std::unordered_map<std::string_view, LocationData> _data;
};


int main(int argc, char *argv[]) {
	int ret_code = 0;
	std::string name;
	if (argc >= 2)
		name = argv[1];
	if (argc > 2 || (argc==2 && name=="help")) {
		std::cout<< "USAGE: " << argv[0] << " <measurements_file>\n"; 
		return ret_code;
	}
	if (argc == 1)
		name = DEFAULT_FILE;
	// Verify file existence and build from file
	if (!std::filesystem::exists(name)) {
		std::cerr<<"File "<<name<<" does not exist. Please re-verify the file path\n";
		return 1;
	}
	// Processing the file content
	BRC processor(name);
	processor.parse();
	//processor.display_all();
	processor.display_sorted();
	return ret_code;
}
