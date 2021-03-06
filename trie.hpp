#ifndef __TRIE_HPP__
#define __TRIE_HPP__

#include "state.hpp"

using namespace std;

class Trie {
    private:
        State * const root = new State();
        State *current_state;
        // On the path from the root to the current_state,
        // longest_match contains the string that led
        // to the last final state. This is the longest matched word. 
        // string_since_last_match contains
        // the remaining string, i.e. the chars of the states from the last final state
        // to current_state
        wstring longest_match = L"", string_since_last_match = L"";
        vector<wstring> split_text;


        void feed_string(wstring s);
        void feed_char(wchar_t c);
        void no_child_for_char(wchar_t c);
        void cut_off_first_char_and_feed_rest_to_trie();
        void transition_to_child_state(State *child);
        // flush adds the words that are currently being processed by the trie to split_text.
        void flush();

    public:
        Trie();

        void add_word(wstring word);
        void add_words(vector<wstring> words);

        vector<wstring> split_string(wstring s);
#ifdef DEBUG
        wstring to_string();
#endif
};

#endif
