#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <map>
#include <algorithm>

using namespace std;

void Questions();
vector<string> initializeFruits();
vector<string> removeFruit(string fruit);

int main()
{
  /*
  for(int i = 0; i < fruitList.size(); i++)
  {
      cout << fruitList[i] << endl;
  }
  */

  char input = 'n';
  while (input != 'y')
    {
      cout << "--- 20 Questions ---" << endl;
      cout << "Think of a fruit..." << endl;
      cout << "Type 'y' for yes, 'n' for no" << endl << endl;
      cout << "Are you ready? " << endl;
      cin >> input;
      cout << endl;
    }

  Questions();
}

vector<string> initializeFruits()
{
    ifstream istream("fruitlist.txt");
    vector<std::string> fruits;
    string line;
    
    while (getline(istream, line)) 
    {
        fruits.push_back(line);
    }
    for (string& fruit : fruits) {
        transform(fruit.begin(), fruit.end(), fruit.begin(), ::tolower);
    }
    
    return fruits;
}

void Questions()
{
    string finalFruit;
    char input;
    vector<string> possibleAnswers;
    vector<string>fruitList = initializeFruits();
    string state = "q";
    int qNum = 1; //count the questions

    cout << "Q" << qNum << ": Is your fruit the color red?" << endl;
    cin >> input;
    qNum++;

    if (input == 'y' && state == "q")
    {
      possibleAnswers.push_back ("apple");
      possibleAnswers.push_back ("cherry");
      possibleAnswers.push_back ("strawberry");
      possibleAnswers.push_back ("raspberry");
      possibleAnswers.push_back ("cranberry");
      possibleAnswers.push_back ("pomegranate");
      state = "red";
    }
    else if(input == 'n' && state == "q")
    {
        cout << "Q" << qNum << ": Is your fruit the color orange?" << endl;
        cin >> input;
        qNum++;
        
        if(input == 'y')
        {
            possibleAnswers.push_back ("orange");
            possibleAnswers.push_back ("apricot");
            possibleAnswers.push_back ("mango");
            possibleAnswers.push_back ("peach");
            possibleAnswers.push_back ("nectarine");
            possibleAnswers.push_back ("kumquat");
            possibleAnswers.push_back ("tangerine");
            possibleAnswers.push_back ("cantaloupe");
            possibleAnswers.push_back ("grapefruit");
            possibleAnswers.push_back ("pumpkin");
            state = "orange";
        }
        else
        {
            cout << "Q" << qNum << ": Is your fruit the color yellow?" << endl;
            cin >> input;
            qNum++;
            
            if(input == 'y')
            {
                possibleAnswers.push_back ("banana");
                possibleAnswers.push_back ("lemon");
                possibleAnswers.push_back ("squash");
                possibleAnswers.push_back ("mango");
                possibleAnswers.push_back ("pineapple");
                possibleAnswers.push_back ("durian");
                state = "yellow";
            }
            else
            {
                cout << "Q" << qNum << ": Is your fruit the color green?" << endl;
                cin >> input;
                qNum++;
                if(input == 'y')
                {
                    possibleAnswers.push_back ("apple");
                    possibleAnswers.push_back ("grape");
                    possibleAnswers.push_back ("pear");
                    possibleAnswers.push_back ("lime");
                    possibleAnswers.push_back ("avocado");
                    possibleAnswers.push_back ("watermelon");
                    possibleAnswers.push_back ("kiwi");
                    state = "green";
                }
                else
                {
                    cout << "Q" << qNum << ": Is your fruit the color blue?" << endl;
                    cin >> input;
                    qNum++;
                    
                    if(input == 'y')
                    {
                        possibleAnswers.push_back ("blueberry");
                        possibleAnswers.push_back ("grape");
                        possibleAnswers.push_back ("fig");
                        possibleAnswers.push_back ("plum");
                        possibleAnswers.push_back ("blackberry");
                        possibleAnswers.push_back ("eggplant");
                        state = "blue"; //color not green, yellow, orange, or red
                    }
                    else
                    {
                        cout << "Q" << qNum << ": Is your fruit the color brown?" << endl;
                        cin >> input;
                        qNum++;
                        
                        if(input == 'y')
                        {
                            cout << "Q" << qNum << ": Is your fruit a kiwi?" << endl;
                            cin >> input;
                            qNum++;
                            if(input == 'y')
                            {
                                state = "correct";
                            }
                            else
                            {
                                state = "incorrect";
                            }
                        }
                        else
                        {
                            state = "incorrect";
                        }
                    }
                }
            }
        }
        
    }
    
    if (state == "red")
    {
        cout << "Q" << qNum << ": Does your fruit end with ""erry""?" << endl;
        cin >> input;
        qNum++;
        
        if(input == 'y')
        {
            possibleAnswers.push_back ("cherry");
            possibleAnswers.push_back ("strawberry");
            possibleAnswers.push_back ("raspberry");
            possibleAnswers.push_back ("cranberry");
            state = "erry";
        }
        else
        {
            possibleAnswers.push_back ("apple");
            possibleAnswers.push_back ("pomegranate");
            state = "notErry";
        }
    }
    
    if (state == "orange")
    {
        cout << "Q" << qNum << ": Do you peel your fruit to eat it?" << endl;
        cin >> input;
        qNum++;
        
        if(input == 'y')
        {
            possibleAnswers.push_back ("grapefruit");
            possibleAnswers.push_back ("orange");
            possibleAnswers.push_back ("tangerine");
            state = "peel";
        }
        else
        {
            possibleAnswers.push_back ("apricot");
            possibleAnswers.push_back ("mango");
            possibleAnswers.push_back ("peach");
            possibleAnswers.push_back ("nectarine");
            possibleAnswers.push_back ("kumquat");
            possibleAnswers.push_back ("cantaloupe");
            possibleAnswers.push_back ("papaya");
            state = "notPeel";
        }
    }
    if (state == "yellow")
    {
        cout << "Q" << qNum << ": Do you peel your fruit to eat it?" << endl;
        cin >> input;
        qNum++;
        
        if(input == 'y')
        {
            possibleAnswers.push_back ("banana");
            //state = "banana";
            
            cout << "Q" << qNum << ": Is your fruit a banana?" << endl;
            cin >> input;
            qNum++;
            
            if(input == 'y')
            {
                state = "correct";
            }
            else
            {
                state = "incorrect";
            }
            
        }
        else
        {
            possibleAnswers.push_back ("lemon");
            possibleAnswers.push_back ("squash");
            possibleAnswers.push_back ("mango");
            possibleAnswers.push_back ("pineapple");
            possibleAnswers.push_back ("durian");
            state = "notBanana";
        }
    }
    if (state == "green")
    {
        cout << "Q" << qNum << ": Is your fruit about the size of an apple or bigger?" << endl;
        cin >> input;
        qNum++;
        
        if(input == 'y')
        {
            possibleAnswers.push_back ("apple");
            possibleAnswers.push_back ("watermelon");
            possibleAnswers.push_back ("pear");
            possibleAnswers.push_back ("avocado");
            state = "greenBig";
        }
        else
        {
            possibleAnswers.push_back ("grape");
            possibleAnswers.push_back ("lime");
            possibleAnswers.push_back ("kiwi");
            state = "greenSmall";
        }
    }
    if (state == "blue")
    {
        cout << "Q" << qNum << ": Can you eat your entire fruit in one bite?" << endl;
        cin >> input;
        qNum++;
        if(input == 'y')
        {
            possibleAnswers.push_back ("blueberry");
            possibleAnswers.push_back ("grape");
            possibleAnswers.push_back ("blackberry");
            state = "oneBite";
        }
        else
        {
            possibleAnswers.push_back ("fig");
            possibleAnswers.push_back ("plum");
            possibleAnswers.push_back ("eggplant");
            state = "notOneBite";
        }
    }
    if(state == "erry")
    {
        input = 'n';
        vector<string> erryFruits;
        erryFruits.push_back ("cherry");
        erryFruits.push_back ("strawberry");
        erryFruits.push_back ("raspberry");
        erryFruits.push_back ("cranberry");
        while(input != 'y')
        {
            state = "correct";
            cout << "Q" << qNum << ": Is your fruit a " << erryFruits.back() << "?" << endl;
            qNum++;
            cin >> input;
            erryFruits.pop_back();
            if(erryFruits.size() == 0)
            {
                state = "incorrect";
                break;
            }
        }
    }
    if(state == "notErry")
    {
        cout << "Q" << qNum << ": Does one of your fruit a day keep the doctor away?" << endl;
        qNum++;
        cin >> input;
        if(input == 'y')
        {
            cout << "Q" << qNum << ": Is your fruit an apple?" << endl;
            qNum++;
            cin >> input;
            if(input == 'y')
            {
                state = "correct";
            }
            else
            {
                state = "incorrect";
            }
        }
        else
        {
            cout << "Q" << qNum << ": Is your fruit a pomegranate?" << endl;
            qNum++;
            cin >> input;
            if(input == 'y')
            {
                state = "correct";
            }
            else
            {
                state = "incorrect";
            }
        }
    }
    if(state == "peel")
    {
        bool fruitFound = false;
        while(!fruitFound)
        {
            cout << "Q" << qNum << ": Is your fruit named after it's color?" << endl;
            qNum++;
            cin >> input;
            if(input == 'y')
            {
                cout << "Q" << qNum << ": Is your fruit an orange?" << endl;
                qNum++;
                cin >> input;
                if(input == 'y')
                {
                    state = "correct";
                    fruitFound = true;
                    break;
                }
                else
                {
                    state = "incorrect";
                    fruitFound = true;
                    break;
                }
            }
                
            cout << "Q" << qNum << ": Is your fruit the size of a softball?" << endl;
            qNum++;
            cin >> input;
            if(input == 'y')
            {
                cout << "Q" << qNum << ": Is your fruit a grapefruit?" << endl;
                qNum++;
                cin >> input;
                if(input == 'y')
                {
                    state = "correct";
                    fruitFound = true;
                    break;
                }
                else
                {
                    state = "incorrect";
                    fruitFound = true;
                    break;
                }
            }
            
            cout << "Q" << qNum << ": Does your fruit look like a mini orange?" << endl;
            qNum++;
            cin >> input;
            if(input == 'y')
            {
                cout << "Q" << qNum << ": Is your fruit a tangerine?" << endl;
                qNum++;
                cin >> input;
                if(input == 'y')
                {
                    state = "correct";
                    fruitFound = true;
                    break;
                }
                else
                {
                    state = "incorrect";
                    fruitFound = true;
                    break;
                }
            }
        }
    }
    if(state == "notPeel")
    {
        cout << "Q" << qNum << ": Is your fruit the size of a baseball or bigger?" << endl;
        qNum++;
        cin >> input;
        
        if(input == 'y')
        {
            possibleAnswers.push_back ("mango");
            possibleAnswers.push_back ("cantaloupe");
            possibleAnswers.push_back ("papaya");
            state = "orangeBig";
        }
        else
        {
            possibleAnswers.push_back ("apricot");
            possibleAnswers.push_back ("peach");
            possibleAnswers.push_back ("nectarine");
            possibleAnswers.push_back ("kumquat");
            state = "orangeSmall";
        }
    }
    if(state == "orangeBig")
    {
        cout << "Q" << qNum << ": Does your fruit have many seeds when cut open?" << endl;
        qNum++;
        cin >> input;
        
        if(input == 'y')
        {
            cout << "Q" << qNum << ": Are the seeds black?" << endl;
            qNum++;
            cin >> input;
            
            if(input == 'y')
            {
                cout << "Q" << qNum << ": Is your fruit a papaya?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
            else
            {
                cout << "Q" << qNum << ": Is your fruit a cantaloupe?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
        }
        else
        {
            cout << "Q" << qNum << ": Is your fruit a mango?" << endl;
            qNum++;
            cin >> input;
                
            if(input == 'y')
            {
                state = "correct";
            }
            else
            {
                state = "incorrect";
            }
        }
    }
    if(state == "orangeSmall")
    {
        cout << "Q" << qNum << ": Is your fruit bitesize?" << endl;
        qNum++;
        cin >> input;
                
        if(input == 'y')
        {
            cout << "Q" << qNum << ": Is your fruit a kumquat?" << endl;
            qNum++;
            cin >> input;
            
            if(input == 'y')
            {
                state = "correct";
            }
            else
            {
                state = "incorrect";
            }
        }
        else
        {
            cout << "Q" << qNum << ": Does your fruit have the letter 'i' in the name?" << endl;
            qNum++;
            cin >> input;
            
            if(input == 'y')
            {
                cout << "Q" << qNum << ": Is your fruit a nectarine?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    cout << "Q" << qNum << ": Is your fruit a apricot?" << endl;
                    qNum++;
                    cin >> input;
                    
                    if(input == 'y')
                    {
                        state = "correct";
                    }
                    else
                    {
                        state = "incorrect";
                    }
                }
            }
            else
            {
                cout << "Q" << qNum << ": Is your fruit a peach?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
        }
    }
    if(state == "notBanana")
    {
        /*
        possibleAnswers.push_back ("lemon"); -
        possibleAnswers.push_back ("squash");-
        possibleAnswers.push_back ("mango"); -
        possibleAnswers.push_back ("pineapple");
        possibleAnswers.push_back ("durian"); -
        */
        cout << "Q" << qNum << ": Does your fruit have an 'o' in the name?" << endl;
        qNum++;
        cin >> input;
        
        if(input == 'y')
        {
            cout << "Q" << qNum << ": Is your fruit sour?" << endl;
            qNum++;
            cin >> input;
            if(input == 'y')
            {
                cout << "Q" << qNum << ": Is your fruit a lemon?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
            else
            {
                cout << "Q" << qNum << ": Is your fruit a mango?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
        }
        else
        {
            cout << "Q" << qNum << ": Is your fruit known for smelling bad?" << endl;
            qNum++;
            cin >> input;
            
            if(input == 'y')
            {
                cout << "Q" << qNum << ": Is your fruit a durian?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
            else
            {
                cout << "Q" << qNum << ": Does Spongebob live in your fruit?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    cout << "Q" << qNum << ": Is your fruit a pineapple?" << endl;
                    qNum++;
                    cin >> input;
                    
                    if(input == 'y')
                    {
                        state = "correct";
                    }
                    else
                    {
                        state = "incorrect";
                    }
                }
                else
                {
                    cout << "Q" << qNum << ": Is your fruit a squash?" << endl;
                    qNum++;
                    cin >> input;
                    
                    if(input == 'y')
                    {
                        state = "correct";
                    }
                    else
                    {
                        state = "incorrect";
                    }
                }
            }
        }
        
    }
    if(state == "greenBig")
    {
        /*
        possibleAnswers.push_back ("apple");
        possibleAnswers.push_back ("watermelon");
        possibleAnswers.push_back ("pear");
        possibleAnswers.push_back ("avocado");
        */
        
        cout << "Q" << qNum << ": Is there a major tech company named after your fruit?" << endl;
        qNum++;
        cin >> input;
        
        if(input == 'y')
        {
            cout << "Q" << qNum << ": Is your fruit an apple?" << endl;
            qNum++;
            cin >> input;
                    
            if(input == 'y')
            {
                state = "correct";
            }
            else
            {
                state = "incorrect";
            }
        }
        else
        {
            cout << "Q" << qNum << ": Is your fruit red on the inside?" << endl;
            qNum++;
            cin >> input;
            
            if(input == 'y')
            {
                cout << "Q" << qNum << ": Is your fruit a watermelon?" << endl;
                qNum++;
                cin >> input;
                        
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
            else
            {
                cout << "Q" << qNum << ": Does your fruit have a big seed?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    cout << "Q" << qNum << ": Is your fruit an avacado?" << endl;
                    qNum++;
                    cin >> input;
                            
                    if(input == 'y')
                    {
                        state = "correct";
                    }
                    else
                    {
                        state = "incorrect";
                    }
                }
                else
                {
                    cout << "Q" << qNum << ": Is your fruit a pear?" << endl;
                    qNum++;
                    cin >> input;
                            
                    if(input == 'y')
                    {
                        state = "correct";
                    }
                    else
                    {
                        state = "incorrect";
                    }
                }
            }
        }
        
    }
    if(state == "greenSmall")
    {
        /*
        possibleAnswers.push_back ("grape");
        possibleAnswers.push_back ("lime");
        possibleAnswers.push_back ("kiwi");
        */
        cout << "Q" << qNum << ": Is your fruit bitesize?" << endl;
        qNum++;
        cin >> input;
        
        if(input == 'y')
        {
            cout << "Q" << qNum << ": Is your fruit a grape?" << endl;
            qNum++;
            cin >> input;
                            
            if(input == 'y')
            {
                state = "correct";
            }
            else
            {
                state = "incorrect";
            }
        }
        else
        {
            cout << "Q" << qNum << ": Is your fruit brown on the outside?" << endl;
            qNum++;
            cin >> input;
            
            if(input == 'y')
            {
                cout << "Q" << qNum << ": Is your fruit a kiwi?" << endl;
                qNum++;
                cin >> input;
                                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
            else
            {
                cout << "Q" << qNum << ": Is your fruit a lime?" << endl;
                qNum++;
                cin >> input;
                                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
        }
    }
    if(state == "oneBite")
    {
        /*
        possibleAnswers.push_back ("blueberry");
        possibleAnswers.push_back ("grape");
        possibleAnswers.push_back ("blackberry");
        */
        
        cout << "Q" << qNum << ": Is your fruit a berry?" << endl;
        qNum++;
        cin >> input;
        
        if(input == 'y')
        {
            cout << "Q" << qNum << ": Is your fruit a blueberry" << endl;
            qNum++;
            cin >> input;
            
            if(input == 'y')
            {
                state = "correct";
            }
            else
            {
                cout << "Q" << qNum << ": Is your fruit a blackberry?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
        }
        else
        {
            cout << "Q" << qNum << ": Is your fruit a grape?" << endl;
            qNum++;
            cin >> input;
            
            if(input == 'y')
            {
                state = "correct";
            }
            else
            {
                state = "incorrect";
            }
        }
    }
    if(state == "notOneBite")
    {
        /*
        possibleAnswers.push_back ("fig");
        possibleAnswers.push_back ("plum");
        possibleAnswers.push_back ("eggplant");
        */
        
        cout << "Q" << qNum << ": Is your fruit larger than a softball?" << endl;
        qNum++;
        cin >> input;
            
        if(input == 'y')
        {
            cout << "Q" << qNum << ": Is your fruit an eggplant?" << endl;
            qNum++;
            cin >> input;
            
            if(input == 'y')
            {
                state = "correct";
            }
            else
            {
                state = "incorrect";
            }
        }
        else
        {
            cout << "Q" << qNum << ": Does your fruit have a large seed?" << endl;
            qNum++;
            cin >> input;
            
            if(input == 'y')
            {
                cout << "Q" << qNum << ": Is your fruit a plum?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
            else
            {
                cout << "Q" << qNum << ": Is your fruit a fig?" << endl;
                qNum++;
                cin >> input;
                
                if(input == 'y')
                {
                    state = "correct";
                }
                else
                {
                    state = "incorrect";
                }
            }
        }
    }
    if(state == "correct")
    {
        cout << "YES! I guessed your fruit in " << qNum - 1 << " guesses!" << endl;
    }
    if(state == "incorrect")
    {
        cout << "I could not guess your fruit..." << endl;
        cout << "What was your fruit?: ";
        cin >> finalFruit;
        
        if(finalFruit[0] <= 90)
        {
            finalFruit[0] = finalFruit[0] + 32; //lowercase the fruit for searching
        }
        
        for(int i = 0; i < fruitList.size(); i++)
        {
            if(finalFruit == fruitList[i])
            {
                state = "fruitFound";
            }
        }
        
        if(finalFruit[0] >= 97)
        {
            finalFruit[0] = finalFruit[0] - 32; //capitalize the fruit for printing
        }
        
        if(state == "fruitFound")
        {
            cout << finalFruit << " is a valid fruit, you win." << endl;
        }
        else
        {
            cout << finalFruit << " is NOT a valid fruit, I win." << endl;
        }
    }
}
