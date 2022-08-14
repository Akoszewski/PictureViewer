Graficzny interfejs użytkownika bazy danych obrazów medycznych

Oprogramowanie z graficznym interfejsem użytkownika, które umożliwia podgląd danych i obrazów zapisanych
w bazie. Wyszukiwanie pacjentów, badań lub obrazów według metadanych. Podgląd obrazów będących
wynikiem zapytania. Projekt realizowany z wykorzystaniem biblioteki Qt.


Instalacja:
Przed pierwszym uruchomieniem aplikacji należy uruchomić skrypt `./setup-db.sh`
oraz zainstalować connector qt do bazy danych. Na systemie MacOS będzie to komenda: 
`brew install qt-postgresql`

a na linux Ubuntu/Debian:
`apt install libqt5sql5-psql`

Uwaga: Na systemie MacOS jeśli polecenie psql nie będzie odnalezione należy zacząć od
komendy `export PATH="/Applications/Postgres.app/Contents/Versions/9.5/bin:$PATH"`
ale należy poprawić ścieżkę która jest zależna m.in. od wersji postgresql.
