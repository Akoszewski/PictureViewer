# sudo apt install -y postgresql postgresql-contrib postgresql-client

sudo -u postgres psql -c "ALTER USER postgres PASSWORD 'haslo123';"
sudo -u postgres psql -c 'create database app_database;'
sudo -u postgres psql -d app_database -f ./database.sql
