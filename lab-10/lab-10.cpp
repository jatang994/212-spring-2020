#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <sstream>

// TODO: Clean up code if time

/* String-handling Helper Functions */
void remove_punctuation(std::string *s) {
	int i = 0;
	while (i < s->length()) {
		if (((*s)[i] >= 'A' && (*s)[i] <= 'Z') || ((*s)[i] >= 'a' && (*s)[i] <= 'z') || ((*s)[i] >= '0' && (*s)[i] <= '9')) {
			i++;
		} else {
			s->erase(i, 1);
		}
	}
}
void to_lower(std::string *s) {
	for (int i = 0; i < s->length(); i++) {
		if ((*s)[i] >= 'A' && (*s)[i] <= 'Z') {
			(*s)[i] += 'a' - 'A';
		}
	}
}

void spell_check_hash_table(const std::string& filename, const std::unordered_set<std::string>& dict) {
	std::cout << "Processing " << filename << " with a hash table ... ";
	/*
	 * IMPLEMENT 5.2.2 FOR HASH TABLES HERE
	 */
	std::cout << "ok!" << std::endl;
}


void find_letter_frequencies(const std::string& filename) {
    /*
     * IMPLEMENT 5.2.3 HERE
     */
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// main function
//---------------------------------------------------------------------------
int main() {
	std::string token;
	std::ifstream dict_file("american-english");

	// create a set backed by a hashtable
	std::unordered_set<std::string> dict_ht;


	// this loop reads all lines from the dictionary
	unsigned int count = 0;
    while(std::getline(dict_file, token)) {
		// at every iteration `token` contains one word from the american-english file
		/*
		 * IMPLEMENT 6.2.1 HERE
		 */
		count += 1;
    }
    std::cout << count << " words read from the american-english dictionary" << std::endl;

	// performs spell checking using a hashtable
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	spell_check_hash_table("alice.txt", dict_ht);
	spell_check_hash_table("pride.txt", dict_ht);
	spell_check_hash_table("war.txt", dict_ht);
	std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
	std::cout << "Time for Hash Tables = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;

	
	find_letter_frequencies("alice.txt");
	find_letter_frequencies("pride.txt");
	find_letter_frequencies("war.txt");
}