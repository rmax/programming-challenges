#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

typedef unsigned int uint;


template<typename T>
void vprint(const vector<T>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}


class City {
public:
  City(string const& s) {
    name = s;
  };

  virtual ~City() {};

  string getName() {
    return name;
  };

  void addIncoming(City* city, string transport) {
    incoming.push_back(make_pair(city, transport));
  };

  vector< pair<City*, string> > getIncoming() {
    return incoming;
  };

  void addOutgoing(City* city, string transport) {
    outgoing.push_back(make_pair(city, transport));
  };

  vector< pair<City*, string> > getOutgoing() {
    return outgoing;
  };

private:
  string name;
  vector< pair<City*, string> > incoming;
  vector< pair<City*, string> > outgoing;
};


typedef map<string, City*> citymap_t;
typedef vector< pair<City*, string> > routes_t;


void printCity(City* c) {
  routes_t out;
  routes_t in;
  routes_t::iterator it;

  cout << "[City:" << c->getName() << "]" << endl;

  out = c->getOutgoing();
  in = c->getIncoming();

  cout  << "\tincoming: ";
  for (it = in.begin(); it != in.end(); it++) {
    cout << it->first->getName() << "(" << it->second << ") ";
  }
  cout << endl;

  cout  << "\toutgoing: ";
  for (it = out.begin(); it != out.end(); it++) {
    cout << it->first->getName() << "(" << it->second << ") ";
  }
  cout << endl;
}


vector<string> commonTransports(City* source, City* target) {
  routes_t out = source->getOutgoing();
  routes_t in = target->getIncoming();
  routes_t::iterator i;
  routes_t::iterator j;
  set<string> transports;

  for (i = out.begin(); i != out.end(); i++) {
    for (j = in.begin(); j != in.end(); j++) {
#ifdef DEBUG
      cout << "comparing " << i->second << " " << j->second << endl;
#endif
      if (i->second == j->second) {
        transports.insert(i->second);
      }
    }
  }

  return vector<string>(transports.begin(), transports.end());
}


vector<string> allowedTransports(City* from, City* to, vector<string> candidates) {
  stack< pair<City*, string> > st;
  pair<City*, string> node;
  routes_t out;
  routes_t::iterator it;
  set<string> visited;
  set<string> result;

  City* current;
  string current_t;
  set<string> candidates_set(candidates.begin(), candidates.end());

#ifdef DEBUG
  cout << "allowedTransport(" << from->getName() << ","
       << to->getName() << "," << t << ")" << endl;
#endif

  out = from->getOutgoing();
  for (it = out.begin(); it != out.end(); it++) {
    if (candidates_set.find(it->second) != candidates_set.end()) {
      st.push(make_pair(it->first, it->second));
      visited.insert(from->getName() + "|" + it->first->getName() + "|" + it->second);
    }
  }

#ifdef DEBUG
  cout << "stack start: " << from->getName() << endl;
#endif

  while(!st.empty()) {
    node = st.top();
    st.pop();

    current = node.first;
    current_t = node.second;

    if (result.find(current_t) != result.end()) {
      continue;
    }

#ifdef DEBUG
    cout << "current node: " << current->getName() << endl;
#endif
    if (current->getName() == to->getName()) {
      result.insert(current_t);
      continue;
    }

    out = current->getOutgoing();
#ifdef DEBUG
    cout << "outgoing nodes: " << out.size() << endl;
#endif
    for (it = out.begin(); it != out.end(); it++) {
      if (it->second != current_t) {
#ifdef DEBUG
        cout << "skipping: " << it->first->getName()
             << "(" << it->second << ")" << endl;
#endif
        continue;
      }

      if (visited.find(current->getName()
            + "|" + it->first->getName()
            + "|" + it->second) == visited.end()) {
#ifdef DEBUG
        cout << "enqueing: " << it->first->getName()
             << "(" << it->second << ")" << endl;
#endif
        st.push(make_pair(it->first, it->second));
        visited.insert(current->getName()
                      + "|" + it->first->getName()
                      + "|" + it->second);
      } else {
#ifdef DEBUG
        cout << "visited: " << it->first->getName() << endl;
#endif
      }
    }
  }

  return vector<string>(result.begin(), result.end());
}


int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif

  uint p, c, v, i, j;
  string source, dest, transport;
  City* cfrom;
  City* cto;
  citymap_t cities;
  citymap_t::iterator it;

  i = 0;
  while (cin >> p >> c >> v) {
    if (p == 0 || c == 0 || v == 0) break;
    i++;
    cities.clear();

    cout << "Caso " << i << ":" << endl;
#ifdef DEBUG
    cout << p << " " << c << " " << v << endl;
#endif
    while (c--) {
      cin >> source >> dest;

      it = cities.find(source);
      if (it != cities.end()) {
        cfrom = it->second;
      } else {
        cfrom = new City(source);
#ifdef DEBUG
        cout << "created source city " << cfrom->getName() << endl;
#endif
        cities[source] = cfrom;
      }

      it = cities.find(dest);
      if (it != cities.end()) {
        cto = it->second;
      } else {
        cto = new City(dest);
#ifdef DEBUG
        cout << "created dest city " << cto->getName() << endl;
#endif
        cities[dest] = cto;
      }
#ifdef DEBUG
      cout << cfrom->getName() << "->" << cto->getName() << endl;
#endif

      while (cin.get() != '\n') {
        cin.unget();
        cin >> transport;
        cfrom->addOutgoing(cto, transport);
        cto->addIncoming(cfrom, transport);
      }
    }
    while (v--) {
      cin >> source >> dest;

      City* s = cities.find(source)->second;
      City* t = cities.find(dest)->second;
#ifdef DEBUG
      cout << "-- source --" << endl;
      printCity(s);
      cout << "-- target --" << endl;
      printCity(t);
#endif

      vector<string> candidates = commonTransports(s, t);

      if (candidates.size() == 0) {
        cout << "Imposible" << endl;
      } else {
#ifdef DEBUG
        cout << "Common transports: "; vprint(candidates); cout << endl;
#endif
        vector<string> result = allowedTransports(s, t, candidates);
        size_t len = result.size();
        if (len == 0) {
          cout << "Imposible" << endl;
        } else {
          cout << "De " << source << " a " << dest << " puedes ir en: ";
          for (j = 0; j < len; j++) {
            cout << result[j];
            if (j < len-1) {
              cout << " ";
            } else {
              cout << endl;
            }
          }
        }
      }
    }
  }

  return 0;
}
