# Zadania na laboratorium

## Zadanie 1
Napisz aplikację okienkową ```Kalkulator``` wykorzystując wxWidgets. Kalkulator powinien być najprostszy, czterodziałaniowy, i pozwalać na podawanie liczb z częścią ułamkową w zapisie dziesiętnym. Kalkulator może być mało sprytny: niektóre lepsze modele fizycznych kalkulatorów potrafią prawidłowo obliczyć 2+3\*4 jako 14, inne od razu wykonują działanie, więc odpowiedzą 20. W tym zadaniu można wybrać najprostszy sposób działania. Aplikacja musi reagować na naciśnięcia guzików kalkulatora myszą, nie musi reagować na próby wprowadzania liczb i działań z klawiatury. Wyświetlacz kalkulatora może być zaimplementowany przez ```wxTextCtrl```, który poznaliśmy na wykładzie, ale obiekty tej klasy robią więcej niż nam jest potrzeba: potrafią pozwolić użytkownikowi na edycję tekstu wewnątrz obiektu, a tymczasem wyświetlacz kalkulatora jest pasywny i wyświetla tylko to, co wynika z naciskania guzików i z obliczeń. Można w związku z tym poszukać w dokumentacji albo innej klasy widgetu, która będzie robić tylko to, co trzeba, albo sposobu na wyłączenie możliwości edytowania w ```wxTextCtrl```. Poeksperymentuj z rozmieszczeniem obiektów w ramce.