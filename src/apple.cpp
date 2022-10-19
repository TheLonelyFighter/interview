#include<iostream>
#include<vector>
#include<array>
#include<sstream>


#define MAX_ELEMS 26
class Words {
    public:
        std::string word;
        char status; // 0 = never used, 1 = tombstone, 2 = occupied

    Words(std::string word_arg = "none", char status_arg = 0) {
        word = word_arg;
        status = status_arg;
    }
};

void delete_word(std::array<Words, MAX_ELEMS> &words, std::string key) {
    for (auto& i : words) {
        if (i.word == key) {
            i.status = 1;
            std::cout << "Word deleted" << std::endl;
            return;
        }
    }
    std::cout << "Word not found" << std::endl;
}

int search_word(std::array<Words, MAX_ELEMS> &words, std::string key) {
    int index = (int) (key.back() - 'a');
    if (words[index].word == key && words[index].status == 2) {
            std::cout << "Found " << key << std::endl;
            return index;
        }
        
    for (int i = index; i < 26; i++) {
        if (words[i].word == key && words[i].status == 2) {
            std::cout << "Found " << key << std::endl;
            return index;
        }
    }

    std::cout << "Not found " << key << std::endl;    
    return -1;
}

int insert_word(std::array<Words, MAX_ELEMS> &words, std::string key) {
   int search_index = search_word(words, key); 
    if (search_index != -1) {
        std::cout << "Word already exists" << std::endl;
        return search_index;
    }
    int index = (int) (key.back() - 'a');

    if (words[index].status == 0 || words[index].status == 1) {
        words[index].word = key;
        words[index].status = 2;
        return index;
    } else {
        int i = 0;
        while (words[index].status == 2 && i <= MAX_ELEMS + 1) {
            index = (index + i) % MAX_ELEMS;
            i++;
        }
        if (i > MAX_ELEMS) {
            std::cout << "Table is full" << std::endl;
            return -1;
        }
        else {
            words[index].word = key;
            words[index].status = 2;
            return index;
        }
        return -1;
    }

}

void read_input(std::array<Words, MAX_ELEMS> &words)
{
    std::vector<std::string> words_in_line;
    words_in_line.reserve(MAX_ELEMS);
    std::string line; 

    //read line
    getline(std::cin, line);
    std::stringstream ss(line);

     // Split the line into words
    while(ss.good()) {
        std::string token;
        ss >> token;
        std::string word = token.substr(1); // remove the first character
        
        if (token[0] == 'A') {
            insert_word(words, word);
        } else if (token[0] == 'D') {
            delete_word(words, word);
        }
          else {
            std::cout << "Invalid action" << std::endl;
        } 
    }
}

int main() {

    std::array<Words,MAX_ELEMS> wordmap;
    std::string example_key = "apple";

    // initialize the wordmap
    for (int i = 0; i < MAX_ELEMS; i++) {
        Words word = Words();
        wordmap[i] = word;
    }

    read_input(wordmap);

    // output all entries with "occupied" status
    std::cout << "Output all entries with occupied status" << std::endl;
    for (auto& i : wordmap) {
        if (i.status == 2) {
            std::cout << i.word << " ";
        }
    }

    return 0;
}