# Zadania na laboratorium

## Zadanie 1
Zaprogramuj wszystkie usługi, których brakuje normalnym typom wyliczeniowym, dla typu wyliczeniowego ```Month```, który będzie reprezentował miesiące (z odpowiadającym wartościami liczbowymi dla miesięcy liczonymi jak należy od 1 do 12):
operator wyjścia na strumień, który wypisze daną wielkość typu ```Month``` w postaci stosownego napisu, np. January itp.
operator wejścia ze strumienia, który w razie rozpoznania na wejściu słowa reprezentującego dany miesiąc (takiego samego, jakie wypisuje dla tego miesiąca operator wyjścia) zapisze odpowiadającą wartość na prawostronny argument typu Month&, a w każdym innym razie upewni się, że strumień jest w stanie zepsutym
funkcje ```ForEachMonth``` oraz ```ForEachMonthReverse```, których argumentem będzie funktor jednoargumentowy wywoływalny z wartościami typu Month, i które wywołają ten funktor dla miesięcy odpowiednio od stycznia do grudnia i od grudnia do stycznia. Uwaga: chcielibyśmy, żeby te funkcje były wywoływalne co najmniej z wyrażeniami lambda, a typ tych wyrażeń nie jest określony przez standard, co oznacza, że nie można napisać tak po prostu takich funkcji, trzeba napisać wzorce funkcji, dla których typ funktora jest parametrem.
Spróbuj zastanowić się jak rozwiązać to zadanie tak, aby zminimalizować nieunikniony bałagan.
Testy do przejścia:
<pre>
void testMonth(void)
  {
  std::ostringstream out;
  ForEachMonthReverse([&](Month m)
    {
    out << m << "\n";
    });
  std::istringstream in(out.str());
  std::vector<Month> v;
  std::copy(std::istream_iterator<Month>(in),std::istream_iterator<Month>(),std::back_inserter(v));
  assert(v.size()==12);
  int i=12;
  ForEachMonth([&v,&i](Month m)
    {
    assert(m == v[--i]);
    });
  }
</pre>