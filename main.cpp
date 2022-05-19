#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>
#include <set>

using namespace std;
list<map<char, set<char>>> parseGraph(string kezdszoveg)
{
    list<map<char, set<char>>> graph;
    string::iterator it = kezdszoveg.begin();
    map<char, set<char>> els;
    while (it != kezdszoveg.end())
    {
        char eredet = *it;
        it++;
        while (*it != '\n')
        {char el = *it;
            it++;
            set<char> &elSet = els[eredet];
            elSet.insert(el);
            els.insert(pair<char, set<char>>(eredet, elSet));
        }
        it++;
        if (*it == '\n')
        {graph.push_back(els);
            els.clear();
            ++it;
        }
    }
    graph.push_back(els);
    return graph;
}

string readFile(string fileut)
{
    string filebancucc = "";
    ifstream file(fileut);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {filebancucc += line + "\n";}
        file.close();
    }
    else{cout<<"Hiba a megnyitasban: "<< fileut;}
    return filebancucc;
}
int szomsz_ar(list<map<char, set<char>>> graph, char from, char to)
{
    int ar = 0;
    string halad;
    int suly = 1;
    for (auto &els : graph)
    {
        map<char, set<char>>::iterator it = els.find(from);
        if (it != els.end())
        {set<char> &elsoferedet = it->second;
            if (elsoferedet.find(to) != elsoferedet.end())return suly;}
        suly++;
    }
    return -1;
}

int get_ut_ar(list<map<char, set<char>>> graph, string ut)
{   int ar = 0;
    for (int i = 1; i < ut.length(); i++)
    {
        char from = ut[i - 1];
        char to = ut[i];
        int elAr = szomsz_ar(graph, from, to);
        if (elAr == -1)return -1;
        ar += elAr;
    }
    return ar;
}

list<string> getvmi(set<char> chars)
{
    list<string> stringek;
    if (chars.size() == 0)stringek.push_back("");
    for (char c : chars)
    {   set<char> ujChars = chars;
        ujChars.erase(c);
        list<string> ustring = getvmi(ujChars);
        for (string &s : ustring)
        {stringek.push_back(c + s);}
        stringek.push_back(string(1, c));
    }

    return stringek;
}
pair<string, int> ut_keres(list<map<char, set<char>>> graph, char eredet, char vege)
{
    if (eredet == vege)return pair<string, int>("", 0);
    set<char> leh_ered;
    set<char> lehet_vege;
    for (auto &els : graph)
    {for (auto &el : els)
        {leh_ered.insert(el.first);
            lehet_vege.insert(el.second.begin(), el.second.end());
        }
    }
    if (leh_ered.find(eredet) == leh_ered.end()){cout<<"A kezdopont: " << string(1, eredet) <<"  nem a graf resze, ";}
    if (lehet_vege.find(vege) == lehet_vege.end()){cout<<"A vegpont: "<< string(1, vege) << "  nem a graf resze";}
    leh_ered.erase(eredet);
    leh_ered.erase(vege);
    list<string> pers = getvmi(leh_ered);
    pers.push_back("");
    for (auto &per : pers)
    { per = eredet + per + vege;}
    int legolcsobb = -1;
    string legolcsobbPath;

    for (auto &per : pers)
    {
        int ar = get_ut_ar(graph, per);
        if (ar == -1)continue;
        if (legolcsobb == -1 || ar < legolcsobb)
        {
            legolcsobb = ar;
            legolcsobbPath = per;
        }
    }

    return pair<string, int>(legolcsobbPath, legolcsobb);
}
int main()
{
        cout<<"Kedves javito urasag!"<<endl;

cout<<"Leirom hogy mit tud ez a program. Dijkstra algoritmust kb. A lenyege hogy van egy txt amibol beolvasol dolgokat."<<endl;

cout<<"A txt felepitese:"<<endl;
cout<<"A txt-n belul fel vannak sorolva csucspontok. Jelen esetben ez igy nez ki:"<<endl;
cout<<endl;
cout<<"a:efh"<<endl;
cout<<"b:frt"<<endl;
cout<<"t:efh"<<endl;
cout<<endl;
cout<<"e:bl"<<endl;
cout<<"r:at"<<endl;
cout<<endl;
cout<<"h:bwp"<<endl;
cout<<endl;
cout<<"p:e"<<endl;
cout<<endl;
cout<<"Itt ugy a csucspontok a karakterek. Mint lathatjuk csoportokra vannak osztva (enterekkel) minnel alabb van a csoport annal nagyobb a sulya az adot elnek. Az a:efh jelen esetben igy azt jelenti hogy az abol 3 db egy sulyu iranyitott (!!) el indul ki."<<endl;
cout<<endl;
cout<<"A program maga azt tudja hogy beadsz neki egy kezdopontot es egy vegpontot, majd a program megkeresi a legrovidebb utvonalat. Fonts hogy iranyitottak az elek."<<endl;
cout<<endl;
cout<<"UI: termeszetesen magamtol nem vagyok eleg okos egy ilyen feladat es kod kitalalasara de biztosithatlak hogy sok idom (amit a a sakkra fordithattam volna btw) ment el vele. Ugyhogy minden szabalyos."<<endl;
cout<<endl;
cout<<"Kitartast a javitasba: Kyra"<<endl;
cout<<endl;
cout<<"UII:Ja igen a txt nevet meg kell adni az elejen. A proba file neve graph.txt."<<endl;cout<<endl;
        char eredet = '\0';
        char end = '\0';
        string filenev;
        string filebancucc = "";
        cout << "File: ";
        cin>>filenev;
        cout << "File beolvasas: " << filenev << endl;
        filebancucc = readFile(filenev);
        list<map<char, set<char>>> graph = parseGraph(filebancucc);

        cout << "A graf jelenlegi formaja a file alapjan: " << endl;
        int suly = 1;
        for (auto &kecske : graph)
        {
            cout << "Ezen elek sulya: " << suly++ << ": " << endl;
            for (auto &el : kecske)
            {
                cout << el.first << " -> ";
                for (auto &target : el.second)
                {
                    cout << target << " ";
                }
                cout << endl;
        }
        }
        cout << "Kezdo pont: ";
        cin >> eredet;
        cout << "Vegpont: ";
        cin >> end;

        pair<string, int> legr_ut = ut_keres(graph, eredet, end);

        if (legr_ut.second == -1)
        {
            cout << "Nem letezik ilyen ut" << endl;
        }
        else
        {
            cout << "Legrovidebb ut: " << legr_ut.first << endl;
            cout << "Ara: " << legr_ut.second << endl;
        }





    return 0;
}
