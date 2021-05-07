/*
    Given a string , find smallest window containing all characters of string;
*/

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

string find_window(string str){

int anss = -1 , l = 0, s = 0,d = 0 , cd = 0;
        
        unordered_map < char , int > mp1;
        
        for(int i = 0 ; i < str.size(); ++i){
            if(mp1.find(str[i]) == mp1.end()){
                ++d;
                
            }
            ++mp1[str[i]];
        }
        
        mp1.clear();
        
        for(int i = 0 ; i < str.size(); ++i){
            
            ++mp1[str[i]];
            if(mp1[str[i]] == 1){
                ++cd;
            }
            
            if(cd == d){
                while(mp1[str[s]] != 1){
                    --mp1[str[s]];
                    ++s;
                }
                
                if(anss == -1){
                    anss = s;
                    l = i - s + 1;
                }
                else{
                    
                    int clen = i - s + 1 ;
                    if(clen < l){
                        l = clen;
                        anss = s;
                    }
                    
                }
                
            }
            
        }
        
        string ans = "";
        for(int i = 0 ; i < l ; ++i){
            ans = ans + str[anss];
            anss++;
        }
        return ans;

}

int main(){

    string s;
    cout<<"Enter string: ";
    cin>>s;

    string ans = find_window(s);

    cout<<"Smallest window containing all characters is: "<<ans;


    return 0;
}