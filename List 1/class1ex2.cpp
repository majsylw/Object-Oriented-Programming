/*Napisz wzorzec algorytmu Tokenizer, którego argumentami bêdzie podzakres kolekcji liter
(kolekcja liter to mo¿e byæ obiekt typu std::string, ale te¿ std::vector<char> itp.)
oraz iterator docelowy, do jakiejœ kolekcji napisów typu std::string. Algorytm ten powinien
podzieliæ tekst z podzakresu kolekcji liter na wyrazy i umieœciæ je w kolekcji docelowej.
Za definicjê wyrazu przyjmujemy nieprzerwany ci¹g liter lub cyfr. Uwaga: ten algorytm bêdzie
mia³ dwa parametry we wzorcu, jeden na typ obu iteratorów opisuj¹cych zakres, drugi na typ
iteratora docelowego. Nie próbuj od razu pisaæ wzorca algorytmu, zamiast tego wybierz konkretne
typy wejœciowe i wyjœciowe, na przyk³ad takie jak na pocz¹tku poni¿szej funkcji testuj¹cej,
a dopiero potem spróbuj przerobiæ tê konkretn¹ funkcjê na wzorzec. Spróbuj tak napisaæ swoj¹
funkcjê, korzystaj¹c z algorytmów i us³ug biblioteki standardowej, ¿eby u¿yæ najwy¿ej jednej pêtli (tylko jednej).
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <cassert>
#include <cctype>



/*
void Tokenizer(std::string::iterator poczatek,
               std::string::iterator koniec,
               std::back_insert_iterator<std::list<std::string>> cel)
{
    std::string::iterator srodek = poczatek;
    while( srodek <= koniec )
    {
        if( isalnum( *srodek ) ) {
            ++srodek;
        } else {
            std::string sub(poczatek, srodek);
            if( !sub.empty() )
                cel = sub;
            poczatek = ++srodek;
        }
    }
}

void Tokenizer(std::vector<char>::iterator poczatek,
               std::vector<char>::iterator koniec,
               std::insert_iterator<std::set<std::string>> cel)
{
    std::vector<char>::iterator srodek = poczatek;
    while( srodek <= koniec )
    {
        if( isalnum( *srodek ) ) {
            ++srodek;
        } else {
            std::string sub(poczatek, srodek);
            if( !sub.empty() )
                cel = sub;
            poczatek = ++srodek;
        }
    }
}
*/

template <class InputIterator, class InsertIterator>
void Tokenizer(InputIterator poczatek,
               InputIterator koniec,
               InsertIterator cel)
{
    InputIterator srodek = poczatek;
    while( srodek <= koniec )
    {
        if( isalnum( *srodek ) ) {
            ++srodek;
        } else {
            std::string sub(poczatek, srodek);
            if( !sub.empty() )
                cel = sub;
            poczatek = ++srodek;
        }
    }
}

void test_Tokenizer(void)
{
std::string tekst=
R"#(People are frustrated by PC kinks and the erratic behavior they
produce. Such unexpected variations in performance have long
been smoothed out in refrigerators, televisions, mobile phones,
and automobiles. As for PCs, telling users that their own
surfing or program installation choices are to blame
understandably makes them no less frustrated, even if they
realize that a more reliable system would inevitably be less
functional—a trade-off seemingly not required by refrigerator
improvements. Worse, the increasing reliance on the PC and
Internet that suggests momentum in their use means that more
is at risk when something goes wrong. Skype users who have
abandoned their old-fashioned telephone lines may regret their
decision if an emergency arises and they need to dial an
emergency number like 911, only to find that they cannot get
through, let alone be located automatically. When one’s
finances, contacts, and appointments are managed using a PC,
it is no longer merely frustrating if the computer comes down
with a virus. It is enough to search for alternative architectures.)#";

// Zittrain, The Future of the Internet, http://yupnet.org/zittrain/archives/14

std::list<std::string> words;
Tokenizer(std::begin(tekst),std::end(tekst),std::back_inserter(words));
std::list<std::string> wdone{"People","are","frustrated","by","PC","kinks",
"and","the","erratic","behavior","they","produce","Such","unexpected",
"variations","in","performance","have","long","been","smoothed","out",
"in","refrigerators","televisions","mobile","phones","and","automobiles",
"As","for","PCs","telling","users","that","their","own","surfing","or",
"program","installation","choices","are","to","blame","understandably",
"makes","them","no","less","frustrated","even","if","they","realize",
"that","a","more","reliable","system","would","inevitably","be","less",
"functional","a","trade","off","seemingly","not","required","by",
"refrigerator","improvements","Worse","the","increasing","reliance","on",
"the","PC","and","Internet","that","suggests","momentum","in","their",
"use","means","that","more","is","at","risk","when","something","goes",
"wrong","Skype","users","who","have","abandoned","their","old",
"fashioned","telephone","lines","may","regret","their","decision","if",
"an","emergency","arises","and","they","need","to","dial","an",
"emergency","number","like","911","only","to","find","that","they",
"cannot","get","through","let","alone","be","located","automatically",
"When","one","s","finances","contacts","and","appointments","are",
"managed","using","a","PC","it","is","no","longer","merely",
"frustrating","if","the","computer","comes","down","with","a","virus",
"It","is","enough","to","search","for","alternative","architectures"};


assert(words==wdone);

std::vector<char> tekst_jako_vector(std::begin(tekst),std::end(tekst));

std::set<std::string> words_list;
Tokenizer(std::begin(tekst_jako_vector),
          std::end(tekst_jako_vector),
          std::inserter(words_list,std::end(words_list)));
std::list<std::string> wldone{"911","As","Internet","It","PC","PCs","People","Skype","Such",
"When","Worse","a","abandoned","alone","alternative","an","and","appointments",
"architectures","are","arises","at","automatically","automobiles","be","been","behavior",
"blame","by","cannot","choices","comes","computer","contacts","decision","dial","down",
"emergency","enough","erratic","even","fashioned","finances","find","for","frustrated",
"frustrating","functional","get","goes","have","if","improvements","in","increasing",
"inevitably","installation","is","it","kinks","less","let","like","lines","located","long",
"longer","makes","managed","may","means","merely","mobile","momentum","more","need","no",
"not","number","off","old","on","one","only","or","out","own","performance","phones",
"produce","program","realize","refrigerator","refrigerators","regret","reliable",
"reliance","required","risk","s","search","seemingly","smoothed","something","suggests",
"surfing","system","telephone","televisions","telling","that","the","their","them","they",
"through","to","trade","understandably","unexpected","use","users","using","variations",
"virus","when","who","with","would","wrong"};
assert(wldone.size()==words_list.size());
assert(std::equal(std::begin(words_list),std::end(words_list),std::begin(wldone)));

std::cerr << "Program pomyslnie przeszedl testy.";
}

int main(void)
{
    test_Tokenizer();

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();

    return 0;
}
