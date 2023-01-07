#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include <map>

using namespace std;


const string FILE_NAME_1 = "wednesdayCast.csv"; // numele primului fișier CSV
const string FILE_NAME_2 = "figurants.csv"; // numele celui de-al doilea fișier CSV
const string FILE_NAME_3 = "castRoleMonsterDiet.csv"; // numele fisierului in care afisez numele, rolul, dieta si monstrul cast-ului
const string OUTPUT_FILE_NAME = "wednesdayCastComplete.csv"; // numele fișierului de ieșire
const string PRICE_FILE_NAME_RO = "pricesRO.csv"; //numele fisierului care contine preturile in romana
const string PRICE_FILE_NAME_EN = "pricesEN.csv"; //numele fisierului care contine preturile in engleza

const int BUS_CAPACITY = 50; // capacitatea autobuzului

const int NUM_FIGURANTS = 132; // numărul de figuranți
const string NAMES[] = {"Ion Acatrinei", "Maria Tanasescu", "Gheorghe Dumitru", "Ana Roscovanu", "Mihai Ilie", "Elena Bulibasa", "Ioan Viziru", "Dana Budeanu", "Alexandru Micunealta",
                        "Andreea Gigina", "Aleena Allison", "Carol Nicholson", "Malik Dominguez", "Janice Gibbs", "Wojciech Haas", "Luna Montes", "Ronan Waters", "Rabia Garrison",
                        "Aidan O'Ryan", "Asma Holt", "Bethany King", "Rhys Vaughn", "Amirah Pierce", "Shreya Reilly", "Carla Whitney", "Lucille Gomez", "Rosalie Shah", "Clementine Whitehead",
                        "Meghan Salas", "Lori Nguyen", "Hasan Beck", "Elspeth Munoz", "Asia White", "Monty Gill", "Cai Medina", "Otis Price", "Dillan Ware", "Harmony Anderson", "Billy Sims",
                        "Catrin Mora", "Wilson Wiggins", "Tariq Blanchard", "Krish Hutchinson", "Diego Mcconnell", "Cormac Wall", "Georgia Petersen", "Tommy Owen", "Niall Sherman",
                        "Vivian Paul","Keeley Gilbert", "Dillon Mclean", "Eleri Pitts", "Audrey Shepard", "Andrea Shields", "Arnold Pollard", "Jeremy Mckinney", "Matilda Bell",
                        "Kimberly Hill", "Brendon Warren", "Mohamed Harvey", "Maisha Schroeder", "Ava-Rose Connolly", "Malaika Randolph", "Cassie Lawson", "Donald Quinn", "Amin Cooper",
                        "Amie Lawrence", "Sana Donaldson", "Faisal Pratt", "Tia Dickerson", "Bertie Mcpherson", "Flynn Booth", "Aayan Prince", "Emilia Chapman", "Alessia Dorsey",
                        "Christian Griffin", "Kaylee O'Quinn", "Willow Beasley", "Cecil Weiss", "Fern Sandova"}; // vectorul de nume aleatorii
const int NUM_NAMES = sizeof(NAMES) / sizeof(string); // numărul de nume în vector


class Person {
public:
    string name; // numele persoanei
    string role; // funcția persoanei (actor sau figurant)
    string monster; // tipul de monstru al persoanei
    string diet; // dieta fiecarei persoane
};

class MonsterManager: public Person {
private:
    string name;
    string role;
    string monster;
    string diet;

public:
        // asignez fiecărei persoane din listă un monstru aleator, dacă este actor sau figurant
    static void assignMonsters(vector<Person>& persons)
    {
        // generator de numere aleatoare
        mt19937 rng;
        rng.seed(random_device()());
        uniform_int_distribution<int> dist(0, 4);

        // asignez fiecărei persoane un monstru aleator, dacă este actor sau figurant
        for (Person& person : persons) {
            if (person.role == "actor" || person.role == "figurant" || person.role == "stunt")
                {
                // aleg un monstru aleator
                int index = dist(rng);
                person.monster = (index == 0) ? "Om/Human" : (index == 1) ? "Varcolac/Werewolf" : (index == 2) ? "Clarvazator/Clairvoyant" : (index == 3) ? "Sirena/Mermaid" : "Vampir/Vampire";
                }
        }
    }

};

class MealManager: public Person {
public:
    // asignez fiecărei persoane din listă un tip de masă aleator
    static void assignMeals(vector<Person>& persons)
    {
        // generator de numere aleatoare
        mt19937 rng;
        rng.seed(random_device()());
        uniform_int_distribution<int> dist(0, 2);

        // asignez fiecărei persoane un tip de masă aleator
        for (Person& person : persons) {
            int index = dist(rng);
            person.diet = (index == 0) ? "Orice" : (index == 1) ? "Vegetariana" : "Flexitariana";
        }
    }
};

class MenuCreator {

public:
    // constructorul clasei MenuCreator
    MenuCreator()
    {
            create_menu();
    }

    // metoda create_menu
    void create_menu()
    {

        ofstream menuRO("menuRO.csv");
        ofstream menuEN("menuEN.csv");

        if (!menuRO)
        throw "File does not exist!";

         if (!menuEN)
        throw "File does not exist!";

        menuRO<<"Pentru cei care mananca orice: "<<','<<"Pentru cei care sunt vegetarieni: "<<','<<"Pentru cei care sunt flexitarieni: "<<"\n" ;
        menuEN<<"For those who eat anything: "<<','<<"For vegetarians: "<<','<<"For flexitarians: "<<"\n" ;

        string menuROOrc[9] = {"Ciorba de vacuta","Ceafa de porc cu cartofi prajiti","Lava-cake",
                            "Ciorba de burta","Pulpe de pui la cuptor cu orez", "Cornulete in doua culori",
                            "Ciorba de pui", "Paste carbonara", "Eclere cu vanilie"};
        string menuROVeg[9] = {"Supa crema de legume", "Orez cu baby legume", "Placina cu mere ",
                            "Supa crema de linte", "Paste cu pesto", "Biscuiti grecesti cu sos de suc de portocale",
                            "Supa indiana usor picanta", "Salata calda cu tofu si ciuperci", "Prajitura cu banane si nuca de cocos"};
        string menuROFlex[9] ={"Ciorba de peste", "Somon la cuptor cu legume", "Papanasi cu dulceata de cirese amare",
                            "Supa de cod mediteranean", "Paste cu ton si sos mexican dulce-acrisor", "Placinta cu visine",
                            "Supa crema de legume", "Pizza vegetariana", "Cheesecake cu zmeura"};

        string menuENOrc[9] = {"Beef soup","Pork neck with french fries","Lava-cake",
                            "Tripe soup","Chicken legs in the oven with rice","Two-color mini croissants",
                            "Chicken soup","Pasta carbonara","Eclairs with vanilla"};
        string menuENVeg[9] = {"Vegetable cream soup","Rice with baby vegetables","Apple pie",
                            "Lentil cream soup","Pesto pasta","Greek biscuits with orange sauce",
                            "Indian soup slightly spicy","Warm salad with tofu and mushrooms","Banana and coconut cake"};
        string menuENFlex[9] = {"Fish soup","Salmon in the oven with vegetables","Cheese dumplings with bitter cherry jam",
                            "Mediterranean cod soup","Pasta with tuna and mexican sweet-sour sauce","Cherry pie",
                            "Vegetable cream soup","Vegetarian pizza","Raspberry cheesecake"};

        menuRO<<"Ziua 1"<<','<<"Ziua 1"<<','<<"Ziua 1"<<"\n";
        menuEN<<"Day 1"<<','<<"Day 1"<<','<<"Day 1"<<"\n";

        for(int i = 0; i < 9; i++)
           {

                if(i == 3)
               {
                   menuRO<<"Ziua 2"<<','<<"Ziua 2"<<','<<"Ziua 2"<<"\n";
                   menuEN<<"Day 2"<<','<<"Day 2"<<','<<"Day 2"<<"\n";
               }
                if(i == 6)
                {
                   menuRO<<"Ziua 3"<<','<<"Ziua 3"<<','<<"Ziua 3"<<"\n";
                   menuEN<<"Day 3"<<','<<"Day 3"<<','<<"Day 3"<<"\n";
                }

                menuRO<<menuROOrc[i]<<','<<menuROVeg[i]<<','<<menuROFlex[i]<<"\n";
                menuEN<<menuENOrc[i]<<','<<menuENVeg[i]<<','<<menuENFlex[i]<<"\n";

           }

       menuRO.close();
       menuEN.close();


    }
};

float totalCostMachiaj(const vector<Person>& persons)
{
    float total_price_machiaj = 0;
    float cost_vampir = 50.6;
    float cost_varcolac = 122.1;
    float cost_sirena = 75.9;
    float cost_clarvazator = 34.54;
    float cost_om = 12.1;
    float total_vampir = 0;
    float total_varcolac = 0;
    float total_sirena = 0;
    float total_clarvazator = 0;
    float total_om = 0;
    int monstru_vampir = 0;
    int monstru_varcolac = 0;
    int monstru_sirena = 0;
    int monstru_clarvazator = 0;
    int monstru_om = 0;


    for (const Person& person : persons) {
        if(person.monster == "Vampir")
        {
            monstru_vampir++;
        }
        else
            if(person.monster =="Varcolac")
        {
            monstru_varcolac++;
        }
        else
            if(person.monster == "Sirena")
        {
            monstru_sirena++;
        }
        else
            if(person.monster == "Clarvazator")
        {
            monstru_clarvazator++;
        }
        else
            if(person.monster == "Om")
        {
            monstru_om++;
        }
    }

    total_vampir = monstru_vampir*cost_vampir;
    total_varcolac = monstru_varcolac*cost_varcolac;
    total_sirena = monstru_sirena*cost_sirena;
    total_clarvazator = monstru_clarvazator*cost_clarvazator;
    total_om = monstru_om*cost_om;
    total_price_machiaj = total_vampir + total_varcolac + total_sirena + total_clarvazator + total_om;

    /*
    //verificarea corectitudinii calculelor
    cout<<"Numarul de vampiri este "<<monstru_vampir<< "."<<endl;
    cout<<"Pret vampiri "<<total_vampir<<endl;
    cout<<"Numarul de varcolaci este "<<monstru_varcolac<< "."<<endl;
    cout<<"Pret varcolaci "<<total_varcolac<<endl;
    cout<<"Numarul de sirene este "<<monstru_sirena<< "."<<endl;
    cout<<"Pret sirena "<<total_sirena<<endl;
    cout<<"Numarul de clarvazatori este "<<monstru_clarvazator<< "."<<endl;
    cout<<"Pret clarvazator "<<total_clarvazator<<endl;
    cout<<"Numarul de oameni este "<<monstru_om<< "."<<endl;
    cout<<"Pret om "<<total_om<<endl;
    */

    return total_price_machiaj;
}

float totalCostDieta(const vector<Person>& persons)
{
    float total_price_dieta = 0;
    int dieta_orice = 0;
    int dieta_flexitariana = 0;
    int dieta_vegetariana = 0;
    float cost_orice = 8.8;
    float cost_vegetariana = 7.26;
    float cost_flexitariana = 10.12;
    float total_orice = 0;
    float total_vegetariana = 0;
    float total_flexitariana = 0;

    for (const Person& person : persons)
    {
        if(person.diet == "Orice")
            {
              dieta_orice++;
            }
        else
            if(person.diet == "Flexitariana")
            {
            dieta_flexitariana++;
            }
        else
            if(person.diet == "Vegetariana")
            {
            dieta_vegetariana++;
            }
    }
    total_orice = dieta_orice*cost_orice;
    total_vegetariana = dieta_vegetariana*cost_vegetariana;
    total_flexitariana = dieta_flexitariana*cost_flexitariana;
    total_price_dieta = total_orice + dieta_flexitariana + dieta_vegetariana;

    /*
    //verificarea corectitudinii calculelor
    cout<<"Numarul de persoane care mananca orice este "<<dieta_orice<< "."<<endl;
    cout<<"Pret meniu orice "<<total_orice<<endl;
    cout<<"Numarul de persoane vegetariene este "<<dieta_vegetariana<< "."<<endl;
    cout<<"Pret meniu vegetarian "<<total_vegetariana<<endl;
    cout<<"Numarul de persoane flexitariene este "<<dieta_flexitariana<< "."<<endl;
    cout<<"Pret meniu flexitarian "<<total_flexitariana<<endl;
    */

    return total_price_dieta;
}

float totalCostDrink(const vector<Person>& persons)
{
    int total_water_pers = 0;
    float total_coffee_pers = 0;
    float total_juice_pers = 0;
    float juice_pers = 0.8;
    int water_pers = 1;
    float coffee_pers = 0.5;
    float water_price_L = 0.66;
    float coffee_price_L = 3.3;
    float juice_price_L = 0.704;
    float total_water_price = 0;
    float total_coffee_price = 0;
    float total_juice_price = 0;
    float total_price_drink = 0;
    int numPersons = 0;


    ifstream wednesdayCastCompleteDrink(OUTPUT_FILE_NAME);

    if (!wednesdayCastCompleteDrink)
        throw "File does not exist!";

    // citesc fiecare linie din fișier
    string line;
    while (getline(wednesdayCastCompleteDrink, line))
        {
        // creez un stream pentru a citi câmpurile din linie
        istringstream lineStream(line);

        // citesc numele și funcția persoanei
        string name, role;
        getline(lineStream, name, ',');
        getline(lineStream, role, ',');

        // adaug 1 la numărul total de persoane
        numPersons++;
    }

    wednesdayCastCompleteDrink.close();

    total_water_pers = water_pers * numPersons;
    total_coffee_pers =  coffee_pers * numPersons;
    total_juice_pers = juice_pers * numPersons;

    total_water_price = total_water_pers * water_price_L;
    total_juice_price = total_juice_pers * juice_price_L;
    total_coffee_price = total_coffee_pers * coffee_price_L;

    total_price_drink = total_water_price + total_juice_price + total_coffee_price;

    /*
    //verificarea corectitudinii calculelor
    cout<<"Cantitate de apa/persoana este de "<< total_water_pers << " de litri."<<endl;
    cout<<"Cantitate de cafea/persoana este de "<< total_coffee_pers << " de litri."<<endl;
    cout<<"Cantitate de suc/persoana este de "<< total_juice_pers << " de litri."<<endl;

    cout<<"Pret apa/persoana este "<< total_water_price << " lei."<<endl;
    cout<<"Pret cafea/persoana este "<< total_coffee_price << " lei."<<endl;
    cout<<"Pret suc/persoana este "<< total_juice_price << " lei."<<endl;
    */

    return total_price_drink;
}

class Acommodation: public Person {
private:
    string name;
    string role;

public:

    int rooms()
        {
        ifstream fileAcommodation(OUTPUT_FILE_NAME);

        if (!fileAcommodation)
            throw "File does not exist!";

    int total_three_person_room = 0;
    int total_two_person_room = 0;
    int numFigurant = 0;
    int numInitialCast = 0;
    float price_three_person_room_night = 92.4;
    float price_two_person_room_night = 77;
    float total_price_three_person_room = 0;
    float total_price_two_person_room = 0;
    float total_price_acommodation = 0;


        while (getline(fileAcommodation, name, ','))
        {
            getline(fileAcommodation, role, '\n');

            if (role == "figurant")
                numFigurant++;
            else numInitialCast++;
        }

        total_two_person_room = numInitialCast/2;
        if (numInitialCast%2 != 0)
            total_two_person_room++;

        total_three_person_room = numFigurant/3;
        if (numFigurant%3 != 0)
            total_three_person_room++;


        total_price_two_person_room = price_two_person_room_night * total_two_person_room;
        total_price_three_person_room = price_three_person_room_night * total_three_person_room;
        total_price_acommodation = total_price_three_person_room + total_price_two_person_room;

        /*
        //verificarea corectitudinii calculelor
        cout<<"Cate camere 2 persoane "<<total_two_person_room<<endl;
        cout<<"Cate camere 3 persoane "<<total_three_person_room<<endl;

        cout<<"Pret total camere 2 persoane "<<total_price_two_person_room<<endl;
        cout<<"Pret total camere 3 persoane "<<total_price_three_person_room<<endl;
        */

        fileAcommodation.close();

    return total_price_acommodation;

    }

};

int main()
{
   // numărul total de persoane
    int numPersons = 0;

    // deschid fișierul pentru scriere
    ofstream file(FILE_NAME_2);

    if (!file)
        throw "File does not exist!";

    // initializez generatorul de numere aleatoare
    srand(time(nullptr));

    // generez și scriu numele aleatorii pentru figuranți
    for (int i = 0; i < NUM_FIGURANTS; i++)
        {
            int nameIndex = rand() % NUM_NAMES;
            string name = NAMES[nameIndex];
        file << name << ",figurant" << endl;
    }

    // închid fișierul
    file.close();

    ifstream wednesdayCast(FILE_NAME_1);
    ifstream figuranti(FILE_NAME_2);

        if (!wednesdayCast)
        throw "File does not exist!";

        if (!figuranti)
        throw "File does not exist!";

    ofstream wednesdayCastComplete(OUTPUT_FILE_NAME);

        if (!wednesdayCastComplete)
        throw "File does not exist!";

    // copiez linie cu linie din primul fișier în fișierul de ieșire
    string line;
    while (getline(wednesdayCast, line))
        {
        wednesdayCastComplete << line << endl;
        }

    // copiez linie cu linie din cel de-al doilea fișier în fișierul de ieșire
    while (getline(figuranti, line))
        {
        wednesdayCastComplete << line << endl;
        }

    // închide fișierele
    wednesdayCast.close();
    figuranti.close();
    wednesdayCastComplete.close();

    ifstream wednesdayCastCompleteBus(OUTPUT_FILE_NAME);

    if (!wednesdayCastCompleteBus)
        throw "File does not exist!";

    // citesc fiecare linie din fișier
    while (getline(wednesdayCastCompleteBus, line))
        {
        // creez un stream pentru a citi câmpurile din linie
        istringstream lineStream(line);

        // citesc numele și funcția persoanei
        string name, role, monster, diet;
        getline(lineStream, name, ',');
        getline(lineStream, role, ',');
        getline(lineStream, monster, ',');
        getline(lineStream, diet, '\n');

        // adaug 1 la numărul total de persoane
        numPersons++;
    }

    int numBuses = (numPersons + BUS_CAPACITY - 1) / BUS_CAPACITY;
    int priceOneBus = 5680;
    int numDrumuri = 2;
    int priceBuses = numBuses*priceOneBus*numDrumuri;


    wednesdayCastCompleteBus.close();

    ifstream wednesdayCastCompleteVector(OUTPUT_FILE_NAME);

    if (!wednesdayCastCompleteVector)
        throw "File does not exist!";

    // citesc liniile din fișier într-un vector de string-uri
    vector<string> lines;
    string linie;

    while (getline(wednesdayCastCompleteVector, linie))
        {
        lines.push_back(linie);
        }

    vector<Person> persons;

    // parcurg liniile și citesc fiecare linie într-un obiect de tip Person
    for (string linie : lines)
        {
        stringstream ss(linie);
        Person pers;
        getline(ss, pers.name, ',');
        getline(ss, pers.role, ',');
        getline(ss, pers.monster, ',');
        getline(ss, pers.diet, '\n');
        persons.push_back(pers);
        }

 wednesdayCastCompleteVector.close();

       // asignez fiecărei persoane un tip de masă aleator
    MealManager::assignMeals(persons);
    MonsterManager::assignMonsters(persons);
    MonsterManager monstru;

    ofstream castRoleMonsterDiet(FILE_NAME_3);
    // scru fiecare persoană în fișierul CSV
    for (Person& pers : persons)
        {
        castRoleMonsterDiet<< pers.name << "," << pers.role << "," << pers.monster << "," << pers.diet<<endl;
        }

    castRoleMonsterDiet.close();



    MenuCreator meniu;
    Acommodation cazare;

    int cost_per_day = 2200;
    int ten_days = 10;

    int cost_ten_days = cost_per_day * ten_days;
    float cost_discount = cost_ten_days * 0.02;

    int total_price_location_ten_days =  cost_ten_days - cost_discount;
    int total_price_location_30_days = total_price_location_ten_days * 3;
    int total_price_location_45_days = total_price_location_ten_days * 4 + cost_per_day * 5;
    int total_price_location_60_days = total_price_location_ten_days * 6;
    int total_price_location_100_days = total_price_location_ten_days * 10;


    //afisez toate preturile atat in romana, cat si in engleza

    ofstream preturi_totale_ro(PRICE_FILE_NAME_RO);
    ofstream preturi_totale_en(PRICE_FILE_NAME_EN);

   if(!preturi_totale_ro)
        throw "File does not exist!";

    if(!preturi_totale_en)
        throw "File does not exist!";


    preturi_totale_ro << "Numarul autobuzelor este de " << numBuses << "." <<"\n";
    preturi_totale_ro << "Costul autobuzelor este de " << priceBuses << " $." <<"\n";
    preturi_totale_ro << "Pret pe o zi:" <<"\n";
    preturi_totale_ro << "Cost total pentru cazare: " << cazare.rooms() << " $." <<"\n";
    preturi_totale_ro << "Cost total pentru machiaj: " << totalCostMachiaj(persons) << " $." <<"\n";
    preturi_totale_ro << "Cost total pentru mancare: " << totalCostDieta(persons) << " $." <<"\n";
    preturi_totale_ro << "Cost total pentru bautura: " << totalCostDrink(persons) << " $." <<"\n";
    preturi_totale_ro << "Cost total pentru locatie: " << cost_per_day << " $." <<"\n";
    preturi_totale_ro << "Pret pe 30 zile:" <<"\n";
    preturi_totale_ro << "Cost total pentru cazare: " << cazare.rooms() *30<< " $." <<"\n";
    preturi_totale_ro << "Cost total pentru machiaj: " << totalCostMachiaj(persons) *30<< " $." <<"\n";
    preturi_totale_ro << "Cost total pentru mancare: " << totalCostDieta(persons) *30<< " $." <<"\n";
    preturi_totale_ro << "Cost total pentru bautura: " << totalCostDrink(persons) *30<< " $." <<"\n";
    preturi_totale_ro << "Cost total locatie:  " << total_price_location_30_days << " $." <<"\n";
    preturi_totale_ro << "Pret pe 45 zile:" <<"\n";
    preturi_totale_ro << fixed << "Cost total pentru cazare: " << cazare.rooms() *45<< " $." <<"\n";
    preturi_totale_ro << "Cost total pentru machiaj: " << totalCostMachiaj(persons) * 45<< " $." <<"\n";
    preturi_totale_ro << "Cost total pentru mancare: " << totalCostDieta(persons) *45<< " $." <<"\n";
    preturi_totale_ro << "Cost total pentru bautura: " << totalCostDrink(persons) *45<< " $." <<"\n";
    preturi_totale_ro << "Cost total locatie: " << total_price_location_45_days<< " $."<<"\n";
    preturi_totale_ro << "Pret pe 60 zile" <<"\n";
    preturi_totale_ro << fixed << "Cost total pentru cazare: " << cazare.rooms() *60<< " $." <<"\n";
    preturi_totale_ro << "Cost total pentru machiaj: " << totalCostMachiaj(persons) *60<< " $." <<"\n";
    preturi_totale_ro << "Cost total pentru mancare: " << totalCostDieta(persons) *60<< " $." <<"\n";
    preturi_totale_ro << "Cost total pentru bautura pentru 60 de zile: " << totalCostDrink(persons) *60<< " $." <<"\n";
    preturi_totale_ro << "Cost total locatie: " << total_price_location_60_days << " $." <<"\n";
    preturi_totale_ro << "Pret pe 100 zile:" <<"\n";
    preturi_totale_ro << fixed << "Cost total pentru cazare: " << cazare.rooms() *100<< " $." <<"\n";
    preturi_totale_ro << fixed << "Cost total pentru machiaj: " << totalCostMachiaj(persons) *100 << " $." <<"\n";
    preturi_totale_ro << "Cost total pentru mancare: " << totalCostDieta(persons) *100<< " $." <<"\n";
    preturi_totale_ro << "Cost total pentru bautura: " << totalCostDrink(persons) *100<< " $." <<"\n";
    preturi_totale_ro << "Cost total locatie: " << total_price_location_100_days << " $." <<"\n";

    preturi_totale_en << "The number of buses is " << numBuses << "." <<"\n";
    preturi_totale_en << "The total cost of buses is " << priceBuses << " $." <<"\n";
    preturi_totale_en << "Price per day:" <<"\n";
    preturi_totale_en << "Total accommodation cost: " << cazare.rooms() << " $." <<"\n";
    preturi_totale_en << "Total makeup cost: " << totalCostMachiaj(persons) << " $." <<"\n";
    preturi_totale_en << "Total food cost: " << totalCostDieta(persons) << " $." <<"\n";
    preturi_totale_en << "Total drink cost: " << totalCostDrink(persons) << " $." <<"\n";
    preturi_totale_ro << "Total location cost: " << cost_per_day << " $." <<"\n";
    preturi_totale_en << "Price for 30 days:" <<"\n";
    preturi_totale_en << "Total accommodation cost: " << cazare.rooms() *30<< " $." <<"\n";
    preturi_totale_en << "Total makeup cost: " << totalCostMachiaj(persons) *30<< " $." <<"\n";
    preturi_totale_en << "Total food cost: " << totalCostDieta(persons) *30<< " $." <<"\n";
    preturi_totale_en << "Total drink cost: " << totalCostDrink(persons) *30<< " $." <<"\n";
    preturi_totale_en << "Total location cost:  " << total_price_location_30_days << " $." <<"\n";
    preturi_totale_en << "Price for 45 days" <<"\n";
    preturi_totale_en << fixed << "Total accommodation cost: " << cazare.rooms() *45<< " $." <<"\n";
    preturi_totale_en << "Total makeup cost: " << totalCostMachiaj(persons) * 45<< " $." <<"\n";
    preturi_totale_en << "Total food cost: " << totalCostDieta(persons) *45<< " $." <<"\n";
    preturi_totale_en << "Total drink cost: " << totalCostDrink(persons) *45<< " $." <<"\n";
    preturi_totale_en << "Total location cost: " << total_price_location_45_days<< " $."<<"\n";
    preturi_totale_en << "Price for 60 days:" <<"\n";
    preturi_totale_en << fixed << "Total accommodation cost: " << cazare.rooms() *60<< " $." <<"\n";
    preturi_totale_en << "Total makeup cost: " << totalCostMachiaj(persons) *60<< " $." <<"\n";
    preturi_totale_en << "Total food cost: " << totalCostDieta(persons) *60<< " $." <<"\n";
    preturi_totale_en << "Total drink cost: " << totalCostDrink(persons) *60<< " $." <<"\n";
    preturi_totale_en << "Total location cost: " << total_price_location_60_days << " $." <<"\n";
    preturi_totale_en << "Price for 100 days:" <<"\n";
    preturi_totale_en << fixed << "Total accommodation cost: " << cazare.rooms() *100<< " $." <<"\n";
    preturi_totale_en << fixed << "Total makeup cost: " << totalCostMachiaj(persons) *100 << " $." <<"\n";
    preturi_totale_en << "Total food cost: " << totalCostDieta(persons) *100<< " $." <<"\n";
    preturi_totale_en << "Total drink cost: " << totalCostDrink(persons) *100<< " $." <<"\n";
    preturi_totale_en << "Total location cost: " << total_price_location_100_days << " $." <<"\n";


    preturi_totale_ro.close();
    preturi_totale_en.close();


    //interfata consola

    cout<<"For English press 1."<<endl;
    cout<<"Pentru limba romana apasa 2."<<endl;

    int apasa;
    cin>>apasa;

    if(apasa == 1)
    {
        cout<<"The program runs successfully! The information is in the files!"<<endl;
    }
    if(apasa == 2)
    {
       cout<<"Programul ruleaza cu succes! Informatiile se afla in fisiere!"<<endl;
    }

    return 0;
}

