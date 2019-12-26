# Zadania na laboratorium

## Zadanie 1
Zaprojektuj i zaprogramuj wzorzec klasy Vector. Obiekty tej klasy będą przechowywały obiekty zadanego typu,
w sposób zbliżony do std::vector, choć z pewnymi różnicami. Biblioteczny typ std::vector rezerwuje miejsce na stercie na zapas,
na obiekty, które dopiero włożymy do kolekcji (np. przez push_back albo insert), poza tym, w momencie usuwania obiektów
z kolekcji (np. przez pop_back) nie zmniejsza wewnętrznych danych, tylko traktuje miejsce po usuniętych jako rezerwę.
Nasza klasa Vector powinna się zachowywać inaczej: rozmiar wewnętrznej tablicy powinien dokładnie odpowiadać ilości danych
w każdej chwili (z uwzględnieniem szczególnego stanu pustego). Do zarządzania czasem życia wewnętrznej tablicy należy użyć
atrybutu typu std::unique_ptr. Wyposaż klasę w następujące operacje:
- konstruktor domyślny, tworzący pustą kolekcję
- konstruktor z liczby całkowitej n ze znakiem tworzący kolekcję n obiektów skonstruowanych domyślnie
- zestaw konstruktor kopiujący/operator przypisania realizujące głębokie kopie
- zestaw konstruktor przenoszący/operator przypisania z rvalue realizujące przenoszenie (a może dostarczone przez kompilator wystarczą?)
- destruktor (a może dostarczony przez kompilator wystarczy?)
- metodę size zwracającą rozmiar w postaci liczby całkowitej ze znakiem
- metodę empty zwracającą prawdę wtedy i tylko wtedy gdy kolekcja jest pusta
- zestaw metoda swap oraz wolnostojący wzorzec funkcji swap
- zestaw operatorów [] zapewniających dostęp do elementu kolekcji, stałej lub nie
- zestaw operacji push_back, powiększających wewnętrzną kolekcję i umożliwiających skopiowanie bądź przeniesienie
  zadanego obiektu pod nowopowstały indeks
- zestaw operacji back, zapewniających dostęp do ostatniego elementu kolekcji, stałej lub nie
- operację pop_back, skracającą kolekcję o element o ostatnim indeksie (i nie robiącą niczego innego,
  w szczególności nie zwracającą żadnej wartości)
- zestaw operacji push_front, powiększających wewnętrzną kolekcję i umożliwiających skopiowanie bądź przeniesienie
  zadanego obiektu pod nowopowstały indeks 0 (elementy dotychczas istniejące w kolekcji otrzymują numery o jeden większe)
- zestaw operacji front, zapewniających dostęp do pierwszego elementu kolekcji, stałej lub nie
- operację pop_front, skracającą kolekcję o element o zerowym indeksie i przesuwającą elementy o pozostałych indeksach
  na o jeden mniejsze (i nie robiącą niczego innego, w szczególności nie zwracającą żadnej wartości).

Testy do przejścia (można oczywiście rozbudować, jeżeli potrzeba):
<pre>
  auto test_Vector(void) -> void
    {
    Vector<int> v1;
    Vector<int> v2(5);
    Vector<int> v3(std::move(v2));
    v3[0]=5;
    assert(v3[0]==5);
    const Vector<int>& crv3 = v3;
    assert(crv3[0]==5);
    v1 = std::move(v3);

    assert(v1[0]==5);
    v1.swap(v3);
    assert(v3[0]==5);
    swap(v1,v3);
    assert(v1[0]==5);

    v3 = v1;
    assert(v3[0]==5);
    assert(v1[0]==5);

    Vector<int> v4(v3);
    v4.push_back(17);
    assert(v4.size()==6);
    assert(v4[5]==17);
    int i=5;
    int k=7;
    v4.push_back(i+k);
    assert(v4.size()==7);
    assert(v4.back()==12);
    v4.back()=13;
    const Vector<int>& crv4=v4;
    assert(crv4.back()==13);
    v4.pop_back();
    assert(v4.size()==6);
    assert(v4[5]==17);
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    assert(v4.size()==0);

    v4.push_front(i+k);
    v4.push_front(5);
    assert(v4[0]==5);
    v4.front()=13;
    assert(crv4[1]==12);
    assert(crv4.front()==13);
    v4.pop_back();
    assert(crv4.front()==13);
    v4.pop_front();
    assert(crv4.empty());
    }
</pre>