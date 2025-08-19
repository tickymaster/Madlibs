#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>

int story_main();
int story_loader(std::string& story);
void file_loader(const size_t file_ID, std::string& contents);
std::string strip_punctuation(const std::string& word);

int main(){
        return story_main();    
}

int story_main(){
        std::string story;
        
        int code = story_loader(story);

        if (code==EXIT_FAILURE)
        {
                return EXIT_FAILURE;
        }
        
        // key words 
        std::string noun = "<noun>";
        std::string verb = "<verb>";
        std::string adjective = "<adjective>";
        std::string adverb = "<adverb>";
        std::string plural_noun = "<plural_noun>";
        std::string number = "<number>";
        std::string body_part = "<body_part>";
        std::string color = "<color>";
        std::string place = "<place>";
        std::string emotion = "<emotion>";

        // New string that will be constructed
        std::string reconstruction = "";

        // Dissasemble a string 
        std::istringstream iss(story);

        std::string word;

        while (iss >> word)
        {
                std::string punct = "";
                if (!word.empty() && std::ispunct(word.back()))
                {
                        punct = word.back();
                        word.pop_back();
                }
                
                // std::cout << "Unstripped word: " << word << std::endl;

                word = strip_punctuation(word);

                // std::cout << "Stripped word: " << "StartWord:" << word << ":EndWord" << std::endl;

                if (word == noun)
                {
                        std::cout << "Enter a noun: ";
                        std::cin >> word;
                } else if (word == verb)
                {
                        std::cout << "Enter a verb: ";
                        std::cin >> word;
                }
                else if (word == adjective)
                {
                        std::cout << "Enter an adjective: ";
                        std::cin >> word;
                }
                else if (word == adverb)
                {
                        std::cout << "Enter an adverb: ";
                        std::cin >> word;
                }
                else if (word == plural_noun)
                {
                        std::cout << "Enter a plural noun: ";
                        std::cin >> word;
                }
                else if (word == number)
                {
                        std::cout << "Enter a number: ";
                        std::cin >> word;
                }
                else if (word == body_part)
                {
                        std::cout << "Enter a body part: ";
                        std::cin >> word;
                }
                else if (word == color)
                {
                        std::cout << "Enter a color: ";
                        std::cin >> word;
                }
                else if (word == place)
                {
                        std::cout << "Enter a place: ";
                        std::cin >> word;
                }
                else if (word == emotion)
                {
                        std::cout << "Enter an emotion: ";
                        std::cin >> word;
                }
                        
                reconstruction += word + " ";
        }
        
        std::cout << reconstruction;
        return EXIT_SUCCESS;
}

int story_loader(std::string& story){
        std::cout << "Welcome to the story selection screen! Which story would you like to select (1-5): ";
        size_t story_ID;
        std::cin >> story_ID;

        if (story_ID < 1 || story_ID > 5)
        {
                std::cerr << "ERROR: Invalid Index" << std::endl;
                return EXIT_FAILURE;
        }
        

        file_loader(story_ID, story);

        return EXIT_SUCCESS;
}

void file_loader(const size_t file_ID, std::string& contents){
        std::string prefix = "../stories/";
        std::string suffix = ".txt";
        std::string file_name = prefix + std::to_string(file_ID) + suffix;

        std::ifstream file(file_name);

        std::string text;

        std::string full_text = "";

        while (getline(file, text))
        {
                full_text += text + '\n';
        }
        
        file.close();

        contents = full_text;
}

std::string strip_punctuation(const std::string& word) {
        std::string possible_token = "<";

        bool track = false;

        for (size_t i = 0; i < word.size(); i++)
        {
                if (word[i] == '<')
                {
                        track = true;
                }
                else if (word[i] == '>')
                {
                        track = false;
                } else 
                {
                        if (track)
                        {
                                possible_token += word[i];
                        }
                }
        }
        
        possible_token += ">";

        return (possible_token == "<>") ? word : possible_token;
}