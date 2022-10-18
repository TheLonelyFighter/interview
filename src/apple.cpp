#include<iostream>
#include<map>

class Words {
    public:
        std::string word;
        char status; // 0 = never used, 1 = tombstone, 2 = occupied

    Words(std::string word_arg = "none", char status_arg = 0) {
        word = word_arg;
        status = status_arg;
    }
};

void insert_word(std::map<char, Words> &words, std::string key) {
   for (auto i : words) {
         if (i.second.word == key)
              return;         // if key exists do nothing
   }
    
   
    char letter = key.back();
    if (words[letter].status == 0 || words[letter].status == 1) {
        words[letter] = Words(key, 2);
    }
    else {
        for (char i = letter + 1; i <= 'z'; i++) {
            if (words[i].status == 0 || words[i].status == 1) {
                words[i] = Words(key, 2);
                return;
            }
        }
    }
    
}

void delete_word(std::map<char, Words> &words, std::string key) {
    for (auto i : words) {
        if (i.second.word == key) {
            i.second.status = 1;
            return;
        }
    }
}

void search_word(std::map<char, Words> &words, std::string key) {
    char letter = key.back();
    if (words[letter].status == 2 && words[letter].word == key) {
        std::cout << "Word found" << std::endl;
        return;
    }
    else if (words[letter].status == 0) {
        std::cout << "Key does not exist" << std::endl;
        return;
    }
    else {
        for (char i = letter + 1; i <= 'z'; i++) {
            if (words[i].status == 2 && words[i].word == key) {
                std::cout << "Word found" << std::endl;
                return;
                }
            }
        }
    std::cout << "key does noe exist" << std::endl;
    return;
}


int main() {

    std::map<char, Words> wordmap;
    int max_elements = 26;
    std::string example_key = "apple";
    std::cout << example_key.back();

    for (int i = 0; i < max_elements; i++) {
        char letter = 'a' + i;
        Words word = Words("initial", 0);
        wordmap.insert(std::pair<char, Words>(letter, word));
    }
    
    // initialize the wordmap
    for (auto& i : wordmap) {
        std::cout << i.first << " " << i.second.word << " " <<  int (i.second.status) << std::endl;
    }

    // add a word to the wordmap


    return 0;
}