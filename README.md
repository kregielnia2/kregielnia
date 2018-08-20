# kregielnia [![Build Status](https://travis-ci.com/kregielnia2/kregielnia.svg?branch=master)](https://travis-ci.com/kregielnia2/kregielnia)
!https://travis-ci.com/kregielnia2/kregielnia.svg?branch=master!:https://travis-ci.com/kregielnia2/kregielnia

Obsługa kręgielni 🎳
Wymagania:

 - liczenie punktów cząstkowych (dla niepełnych ramek): 3-|X|4/|5
 - liczenie punktów całościowych (szczegóły w załączniku)
 - walidacja inputu z niepełnymi ramkami dla kilku graczy w poniższym formacie:

    Name1:X|4-|3
    Name2:34|X|0-
    :X|22|33

 - input z wielu plików w jednym katalogu, każdy plik z kilkoma graczami reprezentuje inny tor (zalecane użycie boost filesystem library lub https://en.cppreference.com/w/cpp/experimental/fs z C++17, uwaga na problemy z CI)
 - wyświetlanie wyników na ekranie z podziałem na tory (ze statusem gry) i graczy oraz zapis do jednego pliku:

    ### Lane 1: game in progress ###
    Name1 30
    Name2 44
    34
    ### Lane 2: no game ###
    ### Lane 3: game finished ###
    Michael 100
    Radek 288


