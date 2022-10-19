#include<iostream>
#include<vector>
#include<array>


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
    char letter = key.back();
    int index = (int) (letter - 'a');
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
    std::string line; 

    //read line
    std::getline(std::cin, line);

    std::vector<std::string> words_in_line;
    words_in_line.reserve(MAX_ELEMS);

    // Split the line into words
    std::string word = "";
    for (auto x : line)
    {
        if (x == ' ')
        {
            words_in_line.emplace_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    words_in_line.emplace_back(word);

    // Process the words
    for(auto& i : words_in_line) {   

        char action = i[0];
        std::string word = i.substr(1, i.size() - 1);
        //if action valid then insert or delete word
         std::cout << "Action: " << action << " Word: " << word << std::endl;

        if (action == 'A') {
            insert_word(words, word);
        } else if (action == 'D') {
            delete_word(words, word);
        }
          else {
            std::cout << "Invalid action" << std::endl;
        }                      
    }  
}


int main() {

    
    const std::size_t max_elements = 26; //our array can contain maximum 26 elements
    std::array<Words,MAX_ELEMS> wordmap;
    std::string example_key = "apple";

    for (int i = 0; i < max_elements; i++) {
        char letter = 'a' + i;
        Words word = Words("initial", 0);
        wordmap[i] = word;
    }
    
    // initialize the wordmap
    for (auto& i : wordmap) {
        std::cout << i.word << " " <<  int (i.status) << std::endl;
    }
    
    read_input(wordmap);

    // output all entries with "occupied" status
    std::cout << "Output all entries with occupied status" << std::endl;
    for (auto& i : wordmap) {
        if (i.status == 2) {
            std::cout << i.word << " " <<  int (i.status) << std::endl;
        }
    }

    return 0;
}